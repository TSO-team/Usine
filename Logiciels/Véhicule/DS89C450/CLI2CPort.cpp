//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLI2CPort.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/05/03
// Description :             Fonctions pour utiliser le protocole I2C.
// Herite de :               CLI2CBase
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLI2CPort.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLI2CPort :: CLI2CPort(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Initialise l'adresse interne par defaut a 8 bits.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CPort :: CLI2CPort(void) {type = ADR8BIT;}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur : 
//                CLI2CPort :: CLI2CPort(transfert_IO_t newType)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Initialise l'adresse interne a newType.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CPort :: CLI2CPort(transfert_IO_t newType) {type = newType;}

//////////////////////////////////////////////////////////////////////////////
// Destructeur :  CLI2CPort :: ~CLI2CPort(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Envoit un stop pour terminer la connexion.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CPort :: ~CLI2CPort(void) {I2CStop();}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    CLI2CPort :: I2CAdresserChip(UC ucAdrChip)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Appelle le circuit integre correspondant a ucAdrChip pour 
//               initier une communication I2C.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CPort :: I2CAdresserChip(UC ucAdrChip) {
  I2CStart();
  I2COctetEcrire(ucAdrChip & 0xFE);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    CLI2CPort :: I2CAdresserInterne(USI usiAdrDepart)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Selectionne l'adresse interne correspondante dans un circuit 
//               integre prealablement selectionne.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CPort :: I2CAdresserInterne(USI usiAdrDepart) {
  switch (type) {
    case PASADR: break;
    case ADR8BIT:
      I2COctetEcrire((UC)usiAdrDepart);
      break;
    case ADR16BIT:
      I2COctetEcrire((UC)(usiAdrDepart >> 8));
      I2COctetEcrire((UC)usiAdrDepart);
  }
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    CLI2CPort :: I2CFinEcriture(UC ucAdrChip)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : S'assure que tout le monde a compris que l'ecriture est 
//               terminee.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CPort :: I2CFinEcriture(UC ucAdrChip) {
  UC j = 20;
  I2CStop();
  do {I2CStart();} while (I2COctetEcrire(ucAdrChip & 0xFE) && j--);
}

UC CLI2CPort :: I2CLireDonneeSeulement(UC ucAdrChip) {
  UC ucDonnee;
  I2CStart();
  I2COctetEcrire(ucAdrChip | 0x01); // Ecris pour lire.	
  ucDonnee = I2COctetLire(NACK);
  I2CStop();
  return(ucDonnee);
}

void CLI2CPort :: I2CEcrireDonnee(UC ucAdrChip, USI usiAdrDepart, UC ucDonnee) {
  I2CAdresserChip(ucAdrChip);
  I2CAdresserInterne(usiAdrDepart);
  I2COctetEcrire(ucDonnee);
  I2CFinEcriture(ucAdrChip);
}

UC CLI2CPort :: I2CLireDonnee(UC ucAdrChip, USI usiAdrDepart) {
  I2CAdresserChip(ucAdrChip);
  I2CAdresserInterne(usiAdrDepart);
  return I2CLireDonneeSeulement(ucAdrChip);
}

void CLI2CPort :: I2CEcrireDonnee(UC ucAdrChip, USI usiAdrDepart, UC ucDonnee, transfert_IO_t newType) {
  transfert_IO_t oldType = type;
  type = newType;
  I2CEcrireDonnee(ucAdrChip, usiAdrDepart, ucDonnee);
  type = oldType;
}

UC CLI2CPort :: I2CLireDonnee(UC ucAdrChip, USI usiAdrDepart, transfert_IO_t newType) {
  UC ucDonnee;
  transfert_IO_t oldType = type;
  type = newType;
  ucDonnee = I2CLireDonnee(ucAdrChip, usiAdrDepart);
  type = oldType;
  return ucDonnee;
}

void CLI2CPort :: I2CEcrireDonnee(UC ucAdrChip, UC ucDonnee) {
  transfert_IO_t oldType = type;
  type = PASADR;
  I2CEcrireDonnee(ucAdrChip, 0, ucDonnee);
  type = oldType;
}

UC CLI2CPort :: I2CLireDonnee(UC ucAdrChip) {
  UC ucDonnee;
  transfert_IO_t oldType = type;
  type = PASADR;
  ucDonnee = I2CLireDonnee(ucAdrChip, 0);
  type = oldType;
  return ucDonnee;
}

void CLI2CPort :: I2CEcrireDonnees(UC ucAdrChip, USI usiAdrDepart, UC *ucpDonnees, UC ucLength) {
  I2CAdresserChip(ucAdrChip);
  I2CAdresserInterne(usiAdrDepart);
  for (UC i = 0; i < ucLength; i++) I2COctetEcrire(ucpDonnees[i]);
  I2CFinEcriture(ucAdrChip);
}

void CLI2CPort :: I2CLireDonnees(UC ucAdrChip, USI usiAdrDepart, UC *ucpDonnees, UC ucLength) {
  UC i = 0;
  I2CAdresserChip(ucAdrChip);
  I2CAdresserInterne(usiAdrDepart);

  I2CStart();
  I2COctetEcrire(ucAdrChip | 0x01); // Ecris pour lire.

  if (ucLength > 1) while (++i < ucLength) ucpDonnees[i - 1] = I2COctetLire(ACK);
  ucpDonnees[i] = I2COctetLire(NACK);
  I2CStop();
}

void CLI2CPort :: I2CEcrireDonnees(UC ucAdrChip, UC *ucpDonnees, UC ucLength) {
  transfert_IO_t oldType = type;
  type = PASADR;
  I2CEcrireDonnees(ucAdrChip, 0, ucpDonnees, ucLength);
  type = oldType;
}

void CLI2CPort :: I2CLireDonnees(UC ucAdrChip, UC *ucpDonnees, UC ucLength) {
  transfert_IO_t oldType = type;
  type = PASADR;
  I2CLireDonnees(ucAdrChip, 0, ucpDonnees, ucLength);
  type = oldType;
}

void CLI2CPort :: I2CEcrireDonnees(UC ucAdrChip, USI usiAdrDepart, UC *ucpDonnees, UC ucLength, transfert_IO_t newType) {
  transfert_IO_t oldType = type;
  type = newType;
  I2CEcrireDonnees(ucAdrChip, usiAdrDepart, ucpDonnees, ucLength);
  type = oldType;
}

void CLI2CPort :: I2CLireDonnees(UC ucAdrChip, USI usiAdrDepart, UC *ucpDonnees, UC ucLength, transfert_IO_t newType) {
  transfert_IO_t oldType = type;
  type = newType;
  I2CLireDonnees(ucAdrChip, usiAdrDepart, ucpDonnees, ucLength);
  type = oldType;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


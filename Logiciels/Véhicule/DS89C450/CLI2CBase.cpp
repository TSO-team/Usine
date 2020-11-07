//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLI2CBase.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/05/03
// Description :             Fonctions pour implementer le protocole I2C.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLI2CBase.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLI2CBase :: CLI2CBase(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Initialise le delai entre l'ecriture et la lecture a 15 ms.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CBase :: CLI2CBase(void) {ulTimeout = DELAIS_15_MS;}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur :
//                CLI2CBase :: CLI2CBase(UL ulNewTimeout)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Initialise le delai entre l'ecriture et la lecture a 
//                ulNewTimeout.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CBase :: CLI2CBase(UL ulNewTimeout) {ulTimeout = ulNewTimeout;}

//////////////////////////////////////////////////////////////////////////////
// Destructeur :  CLI2CBase :: ~CLI2CBase(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLI2CBase :: ~CLI2CBase(void) {}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLI2CBase :: I2CEcrireBit(UC ucValeur)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Ecrit un bit en I2C.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: I2CBitEcrire(UC ucValeur) {
  SDA = !!ucValeur;
  I2CDelay(2);
  SCL = 1;
  I2CDelay(2);
  SCL = 0;
  I2CDelay(2);
}

//////////////////////////////////////////////////////////////////////////////
// Controleur :  void CLI2CBase :: I2CStart(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Initie une communication I2C.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: I2CStart(void) {
  SDA = SCL = 1;
  I2CDelay(2);
  SDA = 0;
  I2CDelay(2);
  SCL = 0;
  I2CDelay(2);
}

//////////////////////////////////////////////////////////////////////////////
// Controleur :  void CLI2CBase :: I2CStop(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Termine une communication I2C.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: I2CStop(void) {
  SDA = SCL = 0;
  I2CDelay(2);
  SCL = 1;
  I2CDelay(2);
  SDA = 1;
  I2CDelay(2);
}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   void CLI2CBase :: I2CBitLire(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Lit un bit en I2C.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLI2CBase :: I2CBitLire(void) {
  UC ucDonnee;
  SDA = 1;
  I2CDelay(2);
  SCL = 1;
  I2CDelay(2);
  ucDonnee = SDA;
  I2CDelay(2);
  SCL = 0;
  I2CDelay(2);
  return(ucDonnee);
}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLI2CBase :: I2COctetEcrire(UC ucValeur)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Ecrit un byte en I2C.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
UC CLI2CBase :: I2COctetEcrire(UC ucValeur) {
  for (UC i = 0; i < 8; i++, ucValeur <<= 1) I2CBitEcrire(ucValeur >> 7);
  return(I2CBitLire());
}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   void CLI2CBase :: I2COctetLire(UC ucAckNoAck)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Lit un byte en I2C et transmet une valeur indiquant si on 
//               veut continuer de lire le prochain byte (ucAckNoAck).
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLI2CBase :: I2COctetLire(UC ucAckNoAck) {
  UC ucVal = 0x00, i;
  for (i = 0; i < 8; i++) {
    ucVal = (ucVal << 1) + I2CBitLire();
  }
  I2CBitEcrire(ucAckNoAck);
  return(ucVal);
}

//////////////////////////////////////////////////////////////////////////////
// Delai :       void CLI2CBase :: I2CDelay(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Utilise le delai par defaut.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: I2CDelay(void) {for (UL i = ulTimeout; i > 0; i--);}

//////////////////////////////////////////////////////////////////////////////
// Delai :       void CLI2CBase :: I2CDelay(UL ulTimeout)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Utilise le delai indique par ulTimeout.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLI2CBase :: I2CDelay(UL ulTimeout) {
  while (ulTimeout) ulTimeout--;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




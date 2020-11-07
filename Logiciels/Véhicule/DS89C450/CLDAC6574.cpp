//////////////////////////////////////////////////////////////////////////////
// Fichier :     CLDAC6574.cpp
// Concepteur :  Samuel Duclos
// Date :        2017/04/18
// Description : Interface du DAC6574.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLDAC6574.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLDAC6574 :: CLDAC6574(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLDAC6574 :: CLDAC6574(void) {}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur : 
//               CLDAC6574 :: CLDAC6574(port channel)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Selectionne un channel du convertisseur digital -> analogue
//               et initialise la largeur de l'adresse interne a 8 bits (I2C).
// Constructeur initialisateur appele: 
//               CLI2CPort(ADR8BIT)
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLDAC6574 :: CLDAC6574(port channel) : CLI2CPort(ADR8BIT) {
  configuration = channel;
}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLDAC6574 :: ~CLDAC6574(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : NEANT.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLDAC6574 :: ~CLDAC6574(void) {}

//////////////////////////////////////////////////////////////////////////////
// Modificateur de configuration : 
//                void CLDAC6574 :: vSet(USI usiData)                  
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Selectionne le port du convertisseur digital -> analogue.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
//void CLDAC6574 :: vSetChannel(port channel) {configuration = channel;}
//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLDAC6574 :: vSet(USI usiData)                  
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Sortie (ecriture) sur le convertisseur digital -> analogue.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLDAC6574 :: vSet(USI usiData) {
  unMot unData;
  unData.Mot = (usiData & 0x03FF) << 6;
  SWAP(unData.Tableau, 0, 1);
  I2CEcrireDonnees(0x98, configuration, unData.Tableau, 2);
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



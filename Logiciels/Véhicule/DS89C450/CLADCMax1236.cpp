//////////////////////////////////////////////////////////////////////////////
// Fichier :     CLADCMax1236.cpp
// Concepteur :  Samuel Duclos
// Date :        2017/04/18
// Description : Interface du MAX1236.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLADCMax1236.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLADCMax1236 :: CLADCMax1236(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Initialise la largeur de l'adresse interne a 16 bits (I2C).
// Constructeur initialisateur appele:
//                CLI2CPort(ADR16BIT)
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLADCMax1236 :: CLADCMax1236(void) : CLI2CPort(ADR16BIT) {}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLADCMax1236 :: ~CLADCMax1236(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : NEANT.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLADCMax1236 :: ~CLADCMax1236(void) {}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   USI CLADCMax1236 :: usiGet(USI usiChannel)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Lit une conversion analogue -> digitale de 10 bits.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
USI CLADCMax1236 :: usiGet(USI usiChannel) {
  unMot unConv;
  I2CLireDonnees(0x68, usiChannel, unConv.Tableau, 2);
  SWAP(unConv.Tableau, 0, 1);
  return unConv.Mot & 0x0FFF;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



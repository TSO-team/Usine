//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLPile.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Controle de la pile.
// Herite de :               CLADCMax1236
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLPile.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLPile :: CLPile(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLPile :: CLPile(void) {}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLPile :: ~CLPile(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : NEANT.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLPile :: ~CLPile(void) {}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   CLPile :: ucCharge(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Accede au pourcentage de charge de la batterie en lisant la 
//               valeur recue du convertisseur analogue -> digital.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
UC CLPile :: ucCharge(void) {
  return ((float)usiGet(CHANNEL3) * 100.0) / PILE_MAXIMUM;
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




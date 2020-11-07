//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLCaptDist.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Controle des capteurs de distance.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLCaptDist.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLCaptDist :: CLCaptDist(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : NEANT.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLCaptDist :: CLCaptDist(void) {usiChannel = CHANNEL0;}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur : CLCaptDist :: CLCaptDist(USI usiNewChannel)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Selectionne un channel du convertisseur analogue -> digital.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLCaptDist :: CLCaptDist(USI usiNewChannel) {usiChannel = usiNewChannel;}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLCaptDist :: ~CLCaptDist(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : NEANT.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLCaptDist :: ~CLCaptDist(void) {}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :   USI CLCaptDist :: usiGet(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Retourne 0 si aucun objet detecte sinon, retourne la valeur 
//               brute convertie (analogue -> digitale).
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
USI CLCaptDist :: usiGet(void) {
  USI usiADC = CLADCMax1236 :: usiGet(usiChannel);
  if ((usiADC < 0x0700) && (usiADC > 0x0300)) return usiADC;
  else return 0;
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



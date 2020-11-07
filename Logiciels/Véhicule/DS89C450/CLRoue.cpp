//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLRoue.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Controle d'une roue.
// Herite de :               CLDAC6574
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLRoue.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLRoue :: CLRoue(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLRoue :: CLRoue(void) {}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur : 
//                CLRoue :: CLRoue(port channel)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Selectionne le channel choisi.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLRoue :: CLRoue(port channel) {clDAC6574.configuration = channel;}

//////////////////////////////////////////////////////////////////////////////
// Destructeur :  CLRoue :: ~CLRoue(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLRoue :: ~CLRoue(void) {}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLRoue :: vSet(USI usiVitesse)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Envoit le mot brut au convertisseur digital -> analogue 
//                qui controle les roues.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLRoue :: vSet(USI usiVitesse) {clDAC6574.vSet(usiVitesse);}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLRoue :: vSetVitesseDifferentielleHaute(UC ucVitesse)                   
// Concepteur :   William Bordeleau
// Date :         3 mai 2017
// Description :  Calcule et envoit le mot necessaire pour tourner autour 
//                d'une vitesse moyenne donnee en sens avant
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLRoue :: vSetVitesseDifferentielleHaute(UC ucVitesse) {
  vSet((ARRET + ARRET * (USI)ucVitesse / 100) - 1);
}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLRoue :: vSetVitesseDifferentielle(
//                                 UC ucVitesseMoyenne,SC cDeltaVitesse)                   
// Concepteur :   Samuel Duclos
// Date :         11 mai 2017
// Description :  Calcule et envoit le mot necessaire pour tourner autour 
//                d'une vitesse moyenne donnee.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLRoue :: vSetVitesseDifferentielle(UC ucVitesseMoyenne, signed char cDeltaVitesse) {
  signed char cVitesse;
  cVitesse = ucVitesseMoyenne + cDeltaVitesse;
  if (cVitesse > 0) vSet(( ARRET + (ARRET * cVitesse)) / 100 - 1);
  else vSet((ARRET + (ARRET * cVitesse)) / 100);
}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLRoue :: vSetVitesseDifferentielleBasse(UC ucVitesse)                   
// Concepteur :   William Bordeleau
// Date :         3 mai 2017
// Description :  Calcule et envoit le mot necessaire pour tourner autour 
//                d'une vitesse moyenne donnee en sens arriere
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLRoue :: vSetVitesseDifferentielleBasse(UC ucVitesse) {
  vSet(ARRET - ARRET * (USI)ucVitesse / 100);
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



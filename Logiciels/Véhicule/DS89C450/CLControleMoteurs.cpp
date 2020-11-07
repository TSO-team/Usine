//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLControleMoteurs.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/05/03
// Composee de :             clRoueHighLeft(PORT0), clRoueHighRight(PORT1),
//                           clRoueLowLeft(PORT2), clRoueLowRight(PORT3)
// Description :             Controleur de quatre moteurs pour chaque roue.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLControleMoteurs.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLControleMoteurs :: CLControleMoteurs(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : NEANT.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLControleMoteurs :: CLControleMoteurs(void) {}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur:
//     CLControleMoteurs :: CLControleMoteurs(UC ucVitesseMoyenne)
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Initialise les moteurs pour chaque roue.
// Compose de : clRoueHighLeft(PORT0), clRoueHighRight(PORT1),
//              clRoueLowLeft(PORT2), clRoueLowRight(PORT3)
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLControleMoteurs :: CLControleMoteurs(UC ucVitesseMoyenne) :
                               clRoueHighLeft(PORT0),
                               clRoueHighRight(PORT1),
                               clRoueLowLeft(PORT2),
                               clRoueLowRight(PORT3)
{ucVitesse = ucVitesseMoyenne;}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLControleMoteurs :: ~CLControleMoteurs(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : NEANT.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLControleMoteurs :: ~CLControleMoteurs(void) {}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLControleMoteurs :: vChangeVitesse(UC ucVitesseMoyenne)
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Change la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vChangeVitesse(UC ucVitesseMoyenne) {
  ucVitesse = ucVitesseMoyenne;
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vMarcheAvant(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Avance a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vMarcheAvant(void) {
  clRoueHighLeft.vSetVitesseDifferentielleHaute(ucVitesse);
  clRoueHighRight.vSetVitesseDifferentielleHaute(ucVitesse);
  clRoueLowLeft.vSetVitesseDifferentielleHaute(ucVitesse);
  clRoueLowRight.vSetVitesseDifferentielleHaute(ucVitesse);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vMarcheArriere(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Recule a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vMarcheArriere(void) {
  clRoueHighLeft.vSetVitesseDifferentielleBasse(ucVitesse);
  clRoueHighRight.vSetVitesseDifferentielleBasse(ucVitesse);
  clRoueLowLeft.vSetVitesseDifferentielleBasse(ucVitesse);
  clRoueLowRight.vSetVitesseDifferentielleBasse(ucVitesse);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vTourneDroite(UC ucVitesseMoyenne)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Tourne a droite a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vTourneDroite(UC ucVitesseMoyenne) {
  clRoueHighLeft.vSetVitesseDifferentielleHaute(ucVitesseMoyenne);
  clRoueHighRight.vSetVitesseDifferentielleBasse(ucVitesseMoyenne);
  clRoueLowLeft.vSetVitesseDifferentielleHaute(ucVitesseMoyenne);
  clRoueLowRight.vSetVitesseDifferentielleBasse(ucVitesseMoyenne);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vTourneDroite(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Tourne a droite a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vTourneDroite(void) {vTourneDroite(ucVitesse);}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vTourneGauche(UC ucVitesseMoyenne)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Tourne a gauche a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vTourneGauche(UC ucVitesseMoyenne) {
  clRoueHighLeft.vSetVitesseDifferentielleBasse(ucVitesseMoyenne);
  clRoueHighRight.vSetVitesseDifferentielleHaute(ucVitesseMoyenne);
  clRoueLowLeft.vSetVitesseDifferentielleBasse(ucVitesseMoyenne);
  clRoueLowRight.vSetVitesseDifferentielleHaute(ucVitesseMoyenne);
}
//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vTourne(UC ucVitesseMoyenne, 
//                                              SC cAngle)                   
// Concepteur : Samuel Duclos
// Date : 12 mai 2017
// Description : Marche avant avec deplacement horizontal en grades (x, y).
//               Vitesse en pourcentage, angle de -100 a 100.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vTourne(UC ucVitesseMoyenne, signed char cDeltaVitesse) {
  clRoueHighLeft.vSetVitesseDifferentielle(ucVitesseMoyenne, cDeltaVitesse);
  clRoueHighRight.vSetVitesseDifferentielle(ucVitesseMoyenne, -cDeltaVitesse);
  clRoueLowLeft.vSetVitesseDifferentielle(ucVitesseMoyenne, cDeltaVitesse);
  clRoueLowRight.vSetVitesseDifferentielle(ucVitesseMoyenne, -cDeltaVitesse);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vTourneGauche(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Tourne a gauche a la vitesse moyenne donnee.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vTourneGauche(void) {vTourneGauche(ucVitesse);}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vControleBrut(USI usiHighLeft, 
//                                                    USI usiHighRight, 
//                                                    USI usiLowLeft,
//                                                    USI usiLowRight)                
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Controle brut des moteurs.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vControleBrut(USI usiHighLeft, USI usiHighRight, 
                                        USI usiLowLeft, USI usiLowRight) {
  clRoueHighLeft.vSet(usiHighLeft);
  clRoueHighRight.vSet(usiHighRight);
  clRoueLowLeft.vSet(usiLowLeft);
  clRoueLowRight.vSet(usiLowRight);
}

//////////////////////////////////////////////////////////////////////////////
// Fonction : void CLControleMoteurs :: vArretMoteurs(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Arret complet des moteurs.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLControleMoteurs :: vArretMoteurs(void) {
  vControleBrut(ARRET, ARRET, ARRET, ARRET);
}
  

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




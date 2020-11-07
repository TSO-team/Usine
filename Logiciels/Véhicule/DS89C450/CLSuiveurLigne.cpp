//////////////////////////////////////////////////////////////////////////////
// Fichier :     CLSuiveurLigne.cpp
// Concepteur :  Samuel Duclos
// Date :        2017/02/05
// Description : Controleur PID.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLSuiveurLigne.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLSuiveurLigne :: CLSuiveurLigne(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLSuiveurLigne :: CLSuiveurLigne(void) {}

//////////////////////////////////////////////////////////////////////////////
// Constructeur initialisateur:
//               CLSuiveurLigne :: CLSuiveurLigne(UC ucVitesseMoyenne)
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Herite de :   CLControleMoteurs
// Description : Initialise les membres prives de CLSuiveurLigne.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLSuiveurLigne :: CLSuiveurLigne(UC ucVitesseMoyenne) :
                               CLControleMoteurs(ucVitesseMoyenne) {
  ucVitesse = ucVitesseMoyenne;
  fLastError = fIntegral = 0;
}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLSuiveurLigne :: ~CLSuiveurLigne(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : NEANT.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLSuiveurLigne :: ~CLSuiveurLigne(void) {}

//////////////////////////////////////////////////////////////////////////////
// Initialisateur : void CLSuiveurLigne :: vPID(void)                   
// Concepteur :     Samuel Duclos
// Date :           3 mai 2017
// Description :    L'erreur est le resultat desire, 0, moins la moyenne des 
//                  capteurs actifs sur l'axe des X.
//                  Moteurs = Proportion(sensors) + Integrale() + Derivee().
// Version :        v0.1
// Compilateur :    IAR
//////////////////////////////////////////////////////////////////////////////
void CLSuiveurLigne :: vPID(void) {
  fError = GOAL - cAverageAngle();
  fIntegral += fError * TIME_LAPSE; // Integrale de l'erreur dans le temps.
  // Derivee de l'erreur dans le temps.
  fDerivative = (fError  - fLastError) / TIME_LAPSE;
  // Angle applique = P + I + D.
  vAppliqueMoteurs(P * fError + I * fIntegral + D * fDerivative);
  fLastError = fError; // Update l'erreur dans la prochaine boucle.
  for (USI i = TIME_LAPSE; i; i--); // Delai (base de temps).
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    float CLSuiveurLigne :: fAverageDistance(void)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Fait la moyenne des sensors allumes.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
signed char CLSuiveurLigne :: cAverageAngle(void) {
  static signed char cMemoire = 0;
  switch (~(clIOPCF8574.ucGet()) & 0x1F) {
    //Avance
  case 0x1B: cMemoire = 0;                      break; // 1 1 0 1 1  
    
    // Tourne vers la gauche
  case 0x13: cMemoire = ANGLE_MIN / 8;          break; // 1 0 0 1 1  
  case 0x17: cMemoire = ANGLE_MIN / 4;          break; // 1 0 1 1 1
  case 0x07: cMemoire = ANGLE_MIN / 2;          break; // 0 0 1 1 1
  case 0x0F: cMemoire = (ANGLE_MIN * 3) / 4;    break; // 0 1 1 1 1
  case 0x02: cMemoire = ANGLE_MIN;              break; // 0 0 0 1 1
    // Tourne vers la droite
  case 0x19: cMemoire = ANGLE_MAX / 8;          break; // 1 1 0 0 1
  case 0x1D: cMemoire = ANGLE_MAX / 4;          break; // 1 1 1 0 1
  case 0x1C: cMemoire = ANGLE_MAX / 2;          break; // 1 1 1 0 0
  case 0x1E: cMemoire = (ANGLE_MAX * 3) / 4;    break; // 1 1 1 1 0
  case 0x18: cMemoire = ANGLE_MAX;              break; // 1 1 0 0 0
  }
  
  return cMemoire;
}

//////////////////////////////////////////////////////////////////////////////
// Fonction :    void CLSuiveurLigne :: vAppliqueMoteurs(float fAngle)                   
// Concepteur :  Samuel Duclos
// Date :        3 mai 2017
// Description : Transforme les angles (-100 a 100 grades) en commandes moteur.
// Version :     v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
void CLSuiveurLigne :: vAppliqueMoteurs(float fAngle) {
  if (fAngle < ANGLE_MIN) fAngle = ANGLE_MIN;
  if (fAngle > ANGLE_MAX) fAngle = ANGLE_MAX;
  vTourne(VITESSE_MOYENNE, (signed char)fAngle);
//  if (fAngle > 0.9) vTourneGauche((UC)fAngle);
//  else if (fAngle < -0.9) vTourneDroite((UC)-fAngle);
//  else vMarcheAvant();
}


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



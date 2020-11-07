//////////////////////////////////////////////////////////////////////////////
// Fichier :                 MainVehicule.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Programme principal du vehicule.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLVehicule.h"

///////////////////////////////////////////////////////////////////////////////
// AVERTISSEMENT: Pour changer les parametres et pour activer le mode test, 
//                modifier le fichier Test.h!
///////////////////////////////////////////////////////////////////////////////

void main(void) {
  class CLVehicule clVehicule(MODE, VITESSE_MOYENNE);
  while (1) clVehicule.vControle();
}

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




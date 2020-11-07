///////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLVehicule.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Classe de controle du vehicule.
// Composee de :             CLCom2, CLSuiveurLigne, CLCaptDist, CLPile
// Version :                 v0.1
// Compilateur :             IAR
///////////////////////////////////////////////////////////////////////////////
#ifndef CLVEHICULE_H
  #define CLVEHICULE_H
  #include "CLCom2.h"
  #include "CLSuiveurLigne.h"
  #include "CLCaptDist.h"
  #include "CLPile.h"
  #include "CLEcran.h"
  #ifdef TEST_MODE_ENABLED
    
  #endif

  // Fonctionnalites du vehicule (modes programmes).
  typedef enum {AUTOMATIQUE, CLAVIER, INCLINOMETRE, EVITEMENT} mode;

  class CLVehicule : private CLControleMoteurs {
    public: CLVehicule(void), CLVehicule(mode, UC), ~CLVehicule(void);
      void vControle(void);

    private:
      class CLCom2 clCom2;
      class CLSuiveurLigne clSuiveurLigne;
      class CLCaptDist clCaptDistGauche, clCaptDistDroite;
      class CLPile clPile;
      class CLEcran clEcran;
      
      #ifdef TEST_MODE_ENABLED
        void vTestCapteurDistance(void), vTest(void);
      #endif

      void vInclinometre(void), vGestionPile(void), vAnalyseTrame(void);
      void vCapteursEvitement(void), vAsciiToInt(void), vClavier(void);
      UC ucChecksum5(void);
      UC ucChecksum12(void);
      UC *ucpIndTamp, ucVitesse;
      USI usiConvert, usiTabRoue[4];
      mode choix;
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLSuiveurLigne.h
// Concepteur :              Samuel Duclos
// Date :                    2017/02/05
// Herite de :               CLControleMoteurs
// Description :             Controleur PID.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLSUIVEURLIGNE_H
  #define CLSUIVEURLIGNE_H
  #include "CLIOPCF8574.h"
  #include "CLControleMoteurs.h"

  #define TIME_LAPSE 2 // Trop peu sensible pour ajouter de delai.
  #define GOAL 0    // Le but c'est que les sensors soient banlances au milieu.

  class CLSuiveurLigne : private CLControleMoteurs {
    public: CLSuiveurLigne(void), CLSuiveurLigne(UC);
      ~CLSuiveurLigne(void);
      void vAppliqueMoteurs(float), vPID(void);
    private: UC ucVitesse;
      class CLIOPCF8574 clIOPCF8574;
      float fLastError, fIntegral, fError, fDerivative;
      signed char cAverageAngle(void);
  };
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



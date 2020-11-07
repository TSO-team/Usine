//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLRoue.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Classe de controle d'une roue.
// Herite de :               CLDAC6574
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLROUE_H
  #define CLROUE_H
  #include "CLDAC6574.h"

  #define ARRET 0x0200

  class CLRoue {
    public: CLRoue(void), CLRoue(port), ~CLRoue(void);
      void vArretMoteur(void), vSetVitesseDifferentielleHaute(UC);
      void vSetVitesseDifferentielleBasse(UC), vSet(USI);
      void vSetVitesseDifferentielle(UC, SC);
      class CLDAC6574 clDAC6574; 
  private:
      port configuration;
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



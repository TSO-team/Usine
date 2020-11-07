//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLCaptDist.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Classe de controle de capteurs de distance.
// Herite de :               CLADC1236
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLCAPTDIST_H
  #define CLCAPTDIST_H
  #include "CLADCMax1236.h"

  class CLCaptDist : private CLADCMax1236 {
    public: CLCaptDist(void), CLCaptDist(USI), ~CLCaptDist(void);
      USI usiGet(void);
    private: USI usiChannel;
  };
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



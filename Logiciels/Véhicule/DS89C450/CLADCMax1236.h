//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLADCMax1236.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Interface le MAX1236.
// Succede :                 CLI2CPort
// Precede :                 CLCaptDist, CLPile.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLADCMAX1236_H
  #define CLADCMAX1236_H
  #include "CLI2CPort.h"

  // Selection du channel analogue -> digital a convertir.
  typedef enum {
    CHANNEL0 = 0xDB63, CHANNEL1 = 0xDB65, CHANNEL2 = 0xDB67, CHANNEL3 = 0xDB69
  } channel;

  class CLADCMax1236 : private CLI2CPort {
    public: CLADCMax1236(void), ~CLADCMax1236(void);
    protected: USI usiGet(USI);
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



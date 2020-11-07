//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLDAC6574.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Interface le DAC6574.
// Succede :                 CLI2CPort
// Precede :                 CLRoue
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLDAC6574_H
  #define CLDAC6574_H
  #include "CLI2CPort.h"

  typedef enum {
    PORT0 = 0x0010, PORT1 = 0x0012, PORT2 = 0x0014, PORT3 = 0x0016
  } port;

  class CLDAC6574 : private CLI2CPort {
    public: CLDAC6574(void), CLDAC6574(port), ~CLDAC6574(void);
      //void vSetChannel(port);
      void vSet(USI);
    //private: 
      port configuration;
  };
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



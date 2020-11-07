//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLIOPCF8574.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Interface le PCF8574.
// Succede :                 CLI2CPort
// Precede :                 CLSuiveurLigne
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLIOPCF8574_H
  #define CLIOPCF8574_H
  #include "CLI2CPort.h"

  class CLIOPCF8574 : private CLI2CPort {
    public: CLIOPCF8574(void), ~CLIOPCF8574(void);
    //protected:
      void vSet(UC);
      UC ucGet(void);
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



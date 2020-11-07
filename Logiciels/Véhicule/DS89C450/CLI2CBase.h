//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Classe pour implementer le protocole I2C.
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLI2CBASE_H
  #define CLI2CBASE_H
  #include "_DeclarationGenerale.h"

  #define DELAIS_15_MS 10000 // Delais pour 15ms.

  class CLI2CBase {
    public: CLI2CBase(void), CLI2CBase(UL), ~CLI2CBase(void);
    protected: void I2CStart(void), I2CStop(void);
      UC I2COctetEcrire(UC), I2COctetLire(UC);
    private: void I2CBitEcrire(UC), I2CDelay(void), I2CDelay(UL);
      UC I2CBitLire(void);
      UL ulTimeout;
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


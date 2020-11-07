//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Classe de gestion de l'ecran LCD utilise par le 
//                           DS89C450.
// Herite de :               CLInOutBase
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLECRAN_H
  #define CLECRAN_H
  #include <stdio.h>
  #include <string.h>
  #include "CLInOutBase.h"

  #define DELAIS_15_MS 10000 // Delais pour 15ms.
  #define ADRESSE_ECRAN 0xF800
  #define ADRESSE_FLAG ADRESSE_ECRAN + 1
  #define ADRESSE_WRITE ADRESSE_ECRAN + 2
  #define ADRESSE_READ ADRESSE_ECRAN + 3

  class CLEcran : private CLInOutBase {
    public: CLEcran(void), CLEcran(USI), ~CLEcran(void);
      void vLcdClr(void), vLcdAffCar(UC), vLcdAffCarHex(UC);
      void vLcdAffChaine(UC *), vLcdAffEcran(UC *), vLcdInit(void);
      void vLcdPoscurC0L1(UC, UC);
    private: void vLcdBusy(void);
      USI usiAdresseEcran, usiAdresseFlag, usiAdresseWrite, usiAdresseRead;
  };
#endif

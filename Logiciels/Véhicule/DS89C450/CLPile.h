//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLPile.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Classe de controle de la pile.
// Herite de :               CLADC1236
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef CLPILE_H
  #define CLPILE_H
  #include "CLADCMax1236.h"

  #define PILE_MAXIMUM 0x0FFF

  class CLPile : private CLADCMax1236 {
    public: CLPile(void), ~CLPile(void);
    //protected:
      UC ucCharge(void);
  };
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



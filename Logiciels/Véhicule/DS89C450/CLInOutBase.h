#ifndef CLINOUTBASE_H
  #define CLINOUTBASE_H
  #include "_DeclarationGenerale.h"

  typedef enum {SAMELSB, SAMEMSB, SUITELSB, SUITEMSB} transfert_t;

  class CLInOutBase {
    public: CLInOutBase(void), ~CLInOutBase(void);
    protected:
      void vOut(USI, UC), vOut(USI, USI, transfert_t);
      UC ucIn(USI);
      USI usiIn(USI, transfert_t);
    private:
      UC ucInportb(USI);
      void vOutportb(USI, UC);
  };
#endif

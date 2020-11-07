//////////////////////////////////////////////////////////////////////////////
// Fichier :                 I2CPort.h
// Concepteur :              Samuel Duclos
// Description :             
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "_DeclarationGenerale.h"
#include "CLI2CBase.h"
#ifndef CLI2CPORT_H
  #define CLI2CPORT_H
  #define ACK 0
  #define NACK 1

  typedef enum {PASADR, ADR8BIT, ADR16BIT} transfert_IO_t;

  class CLI2CPort : protected CLI2CBase {
    public: CLI2CPort(void), CLI2CPort(transfert_IO_t), ~CLI2CPort(void);
    protected:
      void I2CEcrireDonnee(UC, USI, UC), I2CEcrireDonnee(UC, UC);
      UC I2CLireDonnee(UC, USI), I2CLireDonnee(UC), I2CLireDonneeSeulement(UC);
      void I2CEcrireDonnee(UC, USI, UC, transfert_IO_t);
      UC I2CLireDonnee(UC, USI, transfert_IO_t);
      void I2CEcrireDonnees(UC, USI, UC *, UC);
      void I2CLireDonnees(UC, USI, UC *, UC);
      void I2CEcrireDonnees(UC, UC *, UC), I2CLireDonnees(UC, UC *, UC);
      void I2CEcrireDonnees(UC, USI, UC *, UC, transfert_IO_t);
      void I2CLireDonnees(UC, USI, UC *, UC, transfert_IO_t);
    private:
      void I2CAdresserChip(UC), I2CAdresserInterne(USI), I2CFinEcriture(UC);
      transfert_IO_t type;
  };
#endif

// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


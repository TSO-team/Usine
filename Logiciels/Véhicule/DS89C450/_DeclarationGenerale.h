///////////////////////////////////////////////////////////////////////////////
// Fichier :     _DeclarationGenerale.h
// Concepteur :  Samuel Duclos
// Description : Definitions generales pour un projet.
// Date :        2017/03/08
// Version :     v0.1
// Compilateur : IAR
///////////////////////////////////////////////////////////////////////////////
#ifndef DECLARATIONGENERALE_H
  #define DECLARATIONGENERALE_H
  //#include "_DS89C450Modifie.h"
  #include "ConversionKeilToIAR.h"
  #include "Test.h"

///////////////////////////////////////////////////////////////////////////////
//                           DEFINITIONS DE TYPES
///////////////////////////////////////////////////////////////////////////////
  #define UC unsigned char
  #define SC signed char
  #define USI unsigned short int
  #define UL unsigned long

  typedef union {struct {UC LSB, MSB;} Octet; USI Mot; UC Tableau[2];} unMot;

///////////////////////////////////////////////////////////////////////////////
//                                  MACROS
///////////////////////////////////////////////////////////////////////////////
  #define SWAP(tab, i, j) \
    do { \
      tab[i] ^= tab[j]; \
      tab[j] ^= tab[i]; \
      tab[i] ^= tab[j]; \
    } while (0);
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




//////////////////////////////////////////////////////////////////////////////
// Fichier :                 Test.h
// Concepteur :              Samuel Duclos
// Date :                    2017/04/18
// Description :             Fichier permettant de specifier des tests.
// Herite de :               CLADC1236
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#ifndef TEST_H
  #define TEST_H
//  #define TEST_MODE_ENABLED   // Commenter pour desactiver le mode test!

  #define MODE AUTOMATIQUE    // Pour changer de mode en mode test.
  //#define MODE CLAVIER
  //#define MODE INCLINOMETRE
  //#define MODE EVITEMENT

  #define VITESSE_MOYENNE 70
  #define ANGLE_MAX (100 - VITESSE_MOYENNE)
  #define ANGLE_MIN (-ANGLE_MAX)
  #define P 1.0
  #define I 0.0
  #define D 2.0

  #ifndef TEST_MODE_ENABLED
    #undef MODE
    #define MODE CLAVIER
  #endif
#endif


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@



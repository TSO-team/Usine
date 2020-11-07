//////////////////////////////////////////////////////////////////////////////
// Fichier :      CLInOutBase.cpp
// Concepteur :   Samuel Duclos
// Date :         2016/11/03
// Description :  Fonctions pour utiliser les I/Os sur le DS89C450.
//  Fonction qui permet de lire un dispositif d'entree     ucInportb ().
//  Fonction qui permet d'ecrire un dispositif de sortie   vOutportb ().
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLInOutBase.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLInOutBase :: CLInOutBase(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLInOutBase :: CLInOutBase(void) {}

//////////////////////////////////////////////////////////////////////////////
// Destructeur :  CLInOutBase :: ~CLInOutBase(void)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  NEANT.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
CLInOutBase :: ~CLInOutBase(void) {}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :    UC CLInOutBase :: ucIn(USI usiAdresse)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Entree (lecture) d'un byte.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
UC CLInOutBase :: ucIn(USI usiAdresse) {return ucInportb(usiAdresse);}

//////////////////////////////////////////////////////////////////////////////
// Accesseur :    UC CLInOutBase :: usiIn(USI usiAdresse, 
//                                        transfert_t typeTransfert)                   
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Entree (lecture) polymorphe d'un mot.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
USI CLInOutBase :: usiIn(USI usiAdresse, transfert_t typeTransfert) {
  unMot unWord;
  switch (typeTransfert) {
    case SAMELSB:
      unWord.Octet.LSB = ucIn(usiAdresse);
      unWord.Octet.MSB = ucIn(usiAdresse);
      break;
    case SAMEMSB:
      unWord.Octet.MSB = ucIn(usiAdresse);
      unWord.Octet.LSB = ucIn(usiAdresse);
      break;
    case SUITELSB:
      unWord.Octet.LSB = ucIn(usiAdresse);
      unWord.Octet.MSB = ucIn(usiAdresse + 1);
      break;
    case SUITEMSB:
      unWord.Octet.MSB = ucIn(usiAdresse);
      unWord.Octet.LSB = ucIn(usiAdresse + 1);
      break;
  }
  return unWord.Mot;
}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLInOutBase :: vOut(USI usiAdresse, UC ucDonnee)
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Sortie (ecriture) d'un byte.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLInOutBase :: vOut(USI usiAdresse, UC ucDonnee) {
  vOutportb(usiAdresse, ucDonnee);
}

//////////////////////////////////////////////////////////////////////////////
// Modificateur : void CLInOutBase :: vOut(USI usiAdresse, USI usiDonnee, 
//                                         transfert_t typeTransfert)
// Concepteur :   Samuel Duclos
// Date :         3 mai 2017
// Description :  Sortie (ecriture) polymorphe d'un mot.
// Version :      v0.1
// Compilateur :  IAR
//////////////////////////////////////////////////////////////////////////////
void CLInOutBase :: vOut(USI usiAdresse, USI usiDonnee, 
                         transfert_t typeTransfert) {
  unMot unWord;
  unWord.Mot = usiDonnee;

  switch (typeTransfert) {
    case SAMELSB:
      vOut(usiAdresse, unWord.Octet.LSB);
      vOut(usiAdresse, unWord.Octet.MSB);
      break;
    case SAMEMSB:
      vOut(usiAdresse, unWord.Octet.MSB);
      vOut(usiAdresse, unWord.Octet.LSB);
      break;
    case SUITELSB:
      vOut(usiAdresse, unWord.Octet.LSB);
      vOut(usiAdresse, unWord.Octet.MSB + 1);
      break;
    case SUITEMSB:
      vOut(usiAdresse, unWord.Octet.MSB);
      vOut(usiAdresse, unWord.Octet.LSB + 1);
      break;
  }
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Ecrit en memoire xdata.
// Prototype :               void vOutportb(USI usiAdresse, UC ucDonnee);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLInOutBase :: vOutportb(USI usiAdresse, UC ucDonnee) {
  UC xdata *ucpAdresse = (UC xdata *)usiAdresse;
  *ucpAdresse = ucDonnee;
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Lit en memoire xdata.
// Prototype :               UC ucInportb(USI usiAdresse);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
UC CLInOutBase :: ucInportb(USI usiAdresse) {
  return(*((UC xdata *)usiAdresse));
}


//////////////////////////////////////////////////////////////////////////////
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


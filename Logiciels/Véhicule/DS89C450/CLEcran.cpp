//////////////////////////////////////////////////////////////////////////////
// Fichier :                 CLEcran.cpp
// Concepteur :              Samuel Duclos
// Date :                    2017/05/03
// Description :             Fonctions pour utiliser l'ecran LCD utilise par 
//                           le DS89C450.
// Herite de :               CLInOutBase
// Version :                 v0.1
// Compilateur :             IAR
//////////////////////////////////////////////////////////////////////////////
#include "CLEcran.h"

//////////////////////////////////////////////////////////////////////////////
// Constructeur : CLEcran :: CLEcran(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Initialise l'adresse des registres de l'ecran a partir de 
//               0xF800 jusqu'a 0xF803.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLEcran :: CLEcran(void) {vLcdInit();}

//////////////////////////////////////////////////////////////////////////////
// Destructeur : CLEcran :: ~CLEcran(void)                   
// Concepteur : Samuel Duclos
// Date : 3 mai 2017
// Description : Efface l'ecran LCD.
// Version : v0.1
// Compilateur : IAR
//////////////////////////////////////////////////////////////////////////////
CLEcran :: ~CLEcran(void) {vLcdClr();}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Affiche un caractere sur l'ecran LCD.
// Prototype :               void vLcdAffCar(UC ucCarac);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdAffCar(UC ucCarac) {
  vLcdBusy();
  vOut(usiAdresseWrite, ucCarac);
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Affiche un byte en hexadecimal sur l'ecran LCD.
// Prototype :               void vLcdAffCarHex(UC ucCarac);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdAffCarHex(UC ucCarac) {
  UC ucpString[5];
  vLcdBusy();
  sprintf((char *)ucpString, "%x", ucCarac);
  vLcdAffChaine(ucpString);
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Affiche une chaine de caracteres sur l'ecran LCD.
// Prototype :               void vLcdAffChaine(UC const *ucpString);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdAffChaine(UC *ucpMessage) {

  UC i, n = strlen((const char *)ucpMessage);

  for (i = 0; i < n; i++) {vLcdAffCar(ucpMessage[i]);}
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Affiche un tableau sur l'ecran LCD.
// Prototype :               void vLcdAffEcran(UC *ucpEcran);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdAffEcran(UC *ucpEcran) {
  vLcdPoscurC0L1(0, 1);
  vLcdAffChaine(&ucpEcran[0]);
  vLcdPoscurC0L1(0, 2);
  vLcdAffChaine(&ucpEcran[21]);
  vLcdPoscurC0L1(0, 3);
  vLcdAffChaine(&ucpEcran[42]);
  vLcdPoscurC0L1(0, 4);
  vLcdAffChaine(&ucpEcran[63]);
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Efface l'ecran LCD.
// Prototype :               void vLcdClr(void);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdClr(void) {
  vLcdBusy();
  vOut(usiAdresseEcran, 0x01);
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Initialise l'ecran, clear et remet le curseur a 0.
// Prototype :               void vLcdInit(void);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdInit(void) {
  USI j;
  UC i, ucTab[5] = {0x38, 0x0C, 0x01, 0x02, 0x06};
  vLcdClr();
  for (i = 0; i < 3; i++) {
    for (j = DELAIS_15_MS; j; j--);
    vOut(usiAdresseEcran, 0x38);
  }
  for (i = 0; i < 5; i++) {
    vLcdBusy();
    vOut(usiAdresseEcran, ucTab[i]);
  }
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Place le curseur a l'adresse donnee.
// Prototype :               void vLcdPoscurC0L1(UC ucCol, UC ucLigne);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdPoscurC0L1(UC ucCol, UC ucLigne) {
  UC ucpTab[4] = {0x00, 0x40, 0x14, 0x54};
  vLcdBusy();
  vOut(usiAdresseEcran, ucpTab[ucLigne - 1] + ucCol + 0x80);
}

//////////////////////////////////////////////////////////////////////////////
// Concepteur :              Samuel Duclos
// Description :             Attends que le flag de disponibilite soit la.
// Prototype :               void vLcdBusy(void);
// Version :                 v0.1
// Compilateur :             Keil 9.53  (uVision 5)
//////////////////////////////////////////////////////////////////////////////
void CLEcran :: vLcdBusy(void) {while(ucIn(usiAdresseFlag) & 0x80);}


// ****************************************************************************
// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


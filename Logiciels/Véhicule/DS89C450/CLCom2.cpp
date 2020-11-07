//******************************** CLCom2.cpp ********************************
// Application realisee avec IAR pour 8051.
// Description: Fonctions RS-232 incluant l'initialisation du baud rate.
//              Gere un tampon de 7 bit en ASCII recu avec le port serie.
// AUTEUR: WILLIAM BORDELEAU
// DATE DE CREATION: 2016-10-12  VERSION 1.0
// DATE MODIFICATION: 2017-04-20 - Samuel Duclos
//****************************************************************************
#include "CLCom2.h"

//****** variables globales  
UC CLCom2 :: ucIndTamp = 0;       // Indice du tampon.
UC *CLCom2 :: ucpDebutTamp;       // Indice de debut du tampon.
UC *CLCom2 :: ucpFinTamp;         // Indice de fin du tampon.
UC CLCom2 :: ucLongTamp = 14;      // Longueur du tampon.
UC CLCom2 :: ucLongTrame = 14;     // Longueur de la trame .
UC CLCom2 :: ucNbrCaraRecu = 0;   // Compteur de caractere recus.
UC CLCom2 :: ucTrameRecu = 0;     // Indication si trame recue.
UC *CLCom2 :: ucpTampon;


//**************************  CLCom2 ***********************************
// DESCRIPTION:  Constructeur de base de CLCom2
// INCLUDE:      #include "CLCom2.h"         
// PROTOTYPE:   CLCom2(void);
// PARAMETRE D'ENTREE:   AUNCUN           
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE: class CLCom2 clCom2;  
// PROCEDURE APPELEE:  vInitBaudRate(USI);                   
// DATE DE CREATION: 2017-05-01
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
CLCom2 :: CLCom2(void) 
{
  vInitBaudRate(19200);
  ES1 = EA = 1;
  ucLongTrame = 14;
  ucLongTamp = 14;
  ucpTampon = new UC [ucLongTamp]; 
  ucNbrCaraRecu = ucTrameRecu = 0;   
  ucpDebutTamp = ucpTampon;
  ucpFinTamp = ucpTampon + 13;
}

//**************************  CLCom2 ***********************************
// DESCRIPTION:  Constructeur de CLCom2
// INCLUDE:      #include "CLCom2.h"         
// PROTOTYPE:   CLCom2(UC ucLongueBuf, UC ucLongueTrame, USI usiBaud);
// PARAMETRE D'ENTREE:   ucLongueBuf
//                       ucLongueTrame
//                       usiBaud  
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE: class CLCom2 clCom2(5,5,52700);  
// PROCEDURE APPELEE:  vInitBaudRate(USI);                   
// DATE DE CREATION: 2017-05-01
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
CLCom2 :: CLCom2(UC ucLongueBuf, UC ucLongueTrame, USI usiBaud) 
{
  vInitBaudRate(usiBaud);
  ucLongTrame = ucLongueTrame;
  ucLongTamp = ucLongueBuf;
  ucpTampon = new UC [ucLongTamp]; 
  ucNbrCaraRecu = ucTrameRecu = 0;   
  ucpDebutTamp = ucpTampon;
  ucpFinTamp = ucpTampon + ucLongTamp; 
}
//**************************  ~CLCom2 ***********************************
// DESCRIPTION:  Destructeur de CLCom2
// INCLUDE:      #include "CLCom2.h"         
// PROTOTYPE:   ~CLCom2(void);
// PARAMETRE D'ENTREE:   AUCUN
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE: NON APELLABLE 
// PROCEDURE APPELEE:  AUCUN;                   
// DATE DE CREATION: 2017-05-01
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
CLCom2 :: ~CLCom2(void) {delete ucpTampon;}


UC CLCom2 :: ucInitLongTrame(UC ucLong) 
{
  if (ucLong <= ucLongTamp) 
  { 
    ucLongTrame = ucLong;
    return 1;
  } else return 0; 
}

//************************** vInitBaudRate ***********************************
// DESCRIPTION:  initialisation du Baudrate
// INCLUDE:      #include "CLCom2.h"         
// PROTOTYPE:   void vInitBaudRate(UI usiBaud);
// PARAMETRE D'ENTREE:   usiBaud           Baudrate desire
// PARAMETRE DE SORTIE:  AUCUN        
// EXEMPLE: USI usiBaud = 57600;
//          vInitBaudRate(usiBaud);  
// PROCEDURE APPELEE:  AUCUNE                    
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
// DATE DE MODIFICATION: 2017-04-20 - William Bordeleau
//****************************************************************************
void CLCom2 :: vInitBaudRate(USI usiBaud) 
{
  SCON1 = 0x50;        // Selectionne UART mode 1, 8-bit avec reception
  TMOD |= 0x20;        // timer 1, mode 2, 8-bit auto reload
  PCON |= 0x80;        // Le bit Smod = 1 pour vitesse *2 du port serie
  WDCON = 0x80;
  switch (usiBaud) 
  {   // choix du baud Rate
  case 9600 :
    TH1 = 0xFA;
    break;
  case 19200 :
    TH1 = 0xFD;
    break;
  case 28800 :
    TH1 = 0xFE;
    break;
  case 57600 :
    TH1 = 0xFF;
    break;
  }

  TR1 = 1;           // Active timer 1 pour fonctionner le port serie
  TI_1 = 0; 
  RI_1 = 0;   // TI et RI a 0 remise a zero du flag
}

//************************* vTransCaractere **********************************
// DESCRIPTION:  transfert d'un caractere sur le port serie
// INCLUDE:     #include "CLCom2.h"          
// PROTOTYPE:   void vTransCaractere(UC ucCar);
// PARAMETRE D'ENTREE:    ucCar      caractere a envoyer
// PARAMETRE DE SORTIE:   AUCUN
// EXEMPLE: vTransCaractere('A'); 
// PROCEDURE APPELEE:  AUCUNE                   
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
void CLCom2 :: vTransCaractere(UC ucCar) 
{
  SBUF1 = ucCar; 
  while (!TI_1);    // Attend que TI_0 soit pret
  TI_1 = 0;         // Rentre le caractere dans le buffer
}

//************************* vTransString **********************************
// DESCRIPTION:  transfert d'une string sur le port serie
// INCLUDE:     #include "CLCom2.h"          
// PROTOTYPE:   void vTransString(UC ucChaine);
// PARAMETRE D'ENTREE:    ucChaine      String a envoyer
// PARAMETRE DE SORTIE:   AUCUN
// EXEMPLE: vTransString(ucChaine); 
// PROCEDURE APPELEE:  AUCUNE                   
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
void CLCom2 :: vTransString(UC *ucChaine) 
{
  while (*ucChaine) 
  {
    vTransCaractere(*ucChaine);
    ucChaine++;
  }
}

//************************* ucLireNbCaractRecu *******************************
// DESCRIPTION:  Retourne le nombre de caractere recu
// INCLUDE:      #include "CLCom2.h"
// PROTOTYPE:   UC ucLireNbCaractRecu(void);
// PARAMETRE D'ENTREE:  AUCUN
// PARAMETRE DE SORTIE: ucNbrCaraRecu      nombre de caractere recu
// EXEMPLE: ucNbrCaraRecu = ucLireNbCaractRecu();   
// PROCEDURE APPELEE:  AUCUNE                     
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
UC CLCom2 :: ucLireNbCaractRecu(void) 
{
  return ucNbrCaraRecu;
}

//************************* ucLireEtatTrame **********************************
// DESCRIPTION:  retourne si la trame est complete
// INCLUDE:     #include "CLCom2.h"            
// PROTOTYPE:   UC ucLireEtatTrame(void);
// PARAMETRE D'ENTREE:  AUCUN
// PARAMETRE DE SORTIE: ucTrameRecu       si la trame est recu
// EXEMPLE: ucTrameRecu =  ucLireEtatTrame(); 
// PROCEDURE APPELEE:  AUCUNE
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
UC CLCom2 :: ucLireEtatTrame(void) 
{
  return ucTrameRecu;

}

//**************************** ucpLireTrame **********************************
// DESCRIPTION:  renvoi un pointeur au debut de la trame si elle est complete
// INCLUDE:     #include "CLCom2.h"      
// PROTOTYPE:   UC *ucpLireTrame(void);
// PARAMETRE D'ENTREE:  AUCUNE
// PARAMETRE DE SORTIE: ucpPointeur         pointeur de debut de trame
// EXEMPLE:  ucpIndTamp = ucpLireTrame();  
// PROCEDURE APPELEE: ucLireEtatTrame()                     
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
UC *CLCom2 :: ucpLireTrame(void) 
{
  if(ucLireEtatTrame()) 
  {          //si la trame est complete
    ucTrameRecu = 0;               //remet a 0 l'indice de completion du tampon
    return ucpDebutTamp;           //renvoi le pointeur
  } 
}

//*************************** vInteruptSerial ********************************
// DESCRIPTION:  fonction d'interruption qui recoit les caractere et les
//               place dans un tampon
// INCLUDE:     #include "CLCom2.h"          
// PROTOTYPE:  void vInteruptSerial(void);
// PARAMETRE D'ENTREE:  AUCUN
// PARAMETRE DE SORTIE: AUCUN
// EXEMPLE: AUCUN  
// PROCEDURE APPELEE: AUCUN                    
// DATE DE CREATION: 2016-10-12
// AUTEUR: WILLIAM BORDELEAU
//****************************************************************************
#pragma vector = 0x3B
__interrupt void CLCom2 :: vInterruptSerial(void) 
{
  EA = 0;                               //desactive les autre interrupt
  if (RI_1) 
  {                        // si on recoit
    if (ucNbrCaraRecu == 0) ucpTampon = ucpDebutTamp; //si la trame est complete
    *ucpTampon = SBUF1;        //envoi le caractere dans le tampon 
    ucpTampon++;
    if(ucNbrCaraRecu < (ucLongTrame - 1 )) 
    {
      ucNbrCaraRecu++;
      ucTrameRecu = 0;   
    }
    //si on est pas a la fin
    else 
    {
      ucNbrCaraRecu = 0;                //remet le compteur a 0
      ucTrameRecu = 1;                  //indique que la trame est complete
    }

    RI_1 = 0;                           //reintialise RI_0
    EA = 1;                             //reactive les autres interrupt
  }
}

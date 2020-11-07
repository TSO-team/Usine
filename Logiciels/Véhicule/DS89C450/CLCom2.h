//************************** CLCom2.h ****************************************
// Application realisee avec Keil 5
// Description: protype des fonction et des includes pour CLCom2.h
// AUTEUR: WILLIAM BORDELEAU
// DATE DE CREATION: 2016-10-12  VERSION 1.0
// DATE MODIFICATION: 2017-04-20 - Samuel Duclos
//****************************************************************************
// Fichier contenant des declarations generales     _DeclarationGenerale.h  
// Fonct permet d'initialiser le baud rate          vInitBaudRate(UI).
// Fonct permet de tansferer un caractere           vTransCaractere(UC).  
// Fonct qui retourne le nombre de caractere recu   ucLireNbCaractRecu( ).
// Fonct indiquant si trame complete recu           ucLireEtatTrame( ).
// Fonct qui permet de lire une trame recu          *ucpLireTrame( ).
// Fonct permettant de recevoir les caracteres      vInteruptSerial( ).
//****************************************************************************
#ifndef CLCOM2_H
  #define CLCOM2_H
  #include "_DeclarationGenerale.h"
  #define LONGTAMPON 14
  #define LONGTRAME  14

  class CLCom2 {
    public:
      CLCom2(void);
      CLCom2(UC, UC, USI);
      ~CLCom2(void);
      void vTransCaractere(UC);
      void vTransString(UC *);
      UC *ucpLireTrame(void); 
      UC ucLireNbCaractRecu(void);
      UC ucLireEtatTrame(void);
      UC ucInitLongTrame(UC);
    protected:
    private:
      void vInitBaudRate(USI);
      __interrupt static void vInterruptSerial(void);
      UC ucValideTrame(void);
      static UC ucIndTamp;         //indice du tampon
      static UC *ucpDebutTamp;     //indice de debut du tampon
      static UC *ucpFinTamp;       //indice de fin du tampon
      static UC ucLongTamp;        //longueur du tampon
      static UC ucLongTrame;       //longueur de la trame 
      static UC ucNbrCaraRecu;     //compteur de caractere recu
      static UC ucTrameRecu;       //indication si trame recu
      static UC *ucpTampon;
  };
#endif


//<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3<3



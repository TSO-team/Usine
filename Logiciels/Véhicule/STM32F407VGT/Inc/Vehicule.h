//******************************************************************************
//   Nom du fichier : IO_BUS.h
//   Auteur : Alain Champagne                  
//      Date de cr�ation : 21-12-2015 
//        Fichier de d�claration et de d�finition des fonctions de controle des 
//        �l�ments d'entr�es sorties.
//  
//******************************************************************************
#ifndef VEHICULEH
  #define VEHICULEH



//Predeclaration des fonctions
void vChecksum(unsigned char *ucpTab);
int iConVit(float fData);
int iConX(float fData);
void vIntToASCII(int *ipTab1,unsigned char*ucpTab2);

#endif

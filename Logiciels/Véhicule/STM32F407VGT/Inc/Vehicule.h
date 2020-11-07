//******************************************************************************
//   Nom du fichier : IO_BUS.h
//   Auteur : Alain Champagne                  
//      Date de création : 21-12-2015 
//        Fichier de déclaration et de définition des fonctions de controle des 
//        éléments d'entrées sorties.
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

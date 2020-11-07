//******************************************************************************
//   Nom du fichier : 1307.h
//   Auteur : Alain Champagne                  
//      Date de création : 03-01-2016 
//        Fichier de déclaration et de définition pour les fonctions de  
//        traitement du circuit d'horloge DS1307.
//  
//******************************************************************************

#ifndef X1307_H
  #define X1307_H

//Definitions de parametres. 

#define ECRIREI2C1307 0xD0
#define LIREI2C1307 0xD1            


 
//Predeclaration des fonctions. 
void v1307WriteByte (uint8_t ucData, uint8_t ucAdresse);
uint8_t uc1307ReadByte (uint8_t ucAdresse);
void v1307WritePage(char ucTableau[], uint8_t ucAdresse);
void v1307ReadPage(char ucTableau[], uint8_t ucAdresse);

#endif 
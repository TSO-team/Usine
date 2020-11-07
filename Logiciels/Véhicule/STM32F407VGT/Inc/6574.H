//******************************************************************************
//   Nom du fichier : 6574.h
//   Auteur : Alain Champagne                  
//      Date de création : 04-01-2016	
//        Fichier de déclaration et de définition pour les fonctions de  
//        traitement du convertisseur DAC6574 I2C.
//  
//******************************************************************************

#ifndef X6574_H
  #define X6574_H

//Definitions de parametres. 

#define ECRIREI2C6574 0x98
#define LIREI2C6574 0x99            

//0x10 chanel 0, 0x12, chanel 1, 0x14 chanel 2 et 0x16 chanel 3.
#define CONFIGURE06574 0x10 
#define CONFIGURE16574 0x12 
#define CONFIGURE26574 0x14 
#define CONFIGURE36574 0x16     


//Predeclaration des fonctions. 
void v6574WriteInt(uint8_t ucChanel, uint16_t uiData);

#endif 
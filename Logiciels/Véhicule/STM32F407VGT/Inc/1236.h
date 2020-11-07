//******************************************************************************
//   Nom du fichier : 1236.h
//   Auteur : Alain Champagne                  
//      Date de création : 19-03-2006 
//      Modifiée pour le KIT ARM : 30-12-2015
//        Fichier de déclaration et de définition pour les fonctions de  
//        traitement du I2C.
//  
//******************************************************************************

#ifndef X1236_H
  #define X1236_H

//Definitions de parametres. 

#define ECRIREI2C1236 0x68
#define LIREI2C1236 0x69            //0x69 pour lire un MAX1236EUA

//0x61 chanel 0, 0x63, chanel 1, 0x65 chanel 2 et 0x67 chanel 3.
#define CONFIGURE01236 0x61 
#define CONFIGURE11236 0x63 
#define CONFIGURE21236 0x65 
#define CONFIGURE31236 0x67     

#define SETUP01236 0xD2   
 
//Predeclaration des fonctions. 
uint16_t i1236ReadChanel(uint8_t ucChanel);

#endif 
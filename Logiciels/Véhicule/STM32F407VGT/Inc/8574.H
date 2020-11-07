//******************************************************************************
//   Nom du fichier : 8574.h
//   Auteur : Alain Champagne                  
//      Date de création : 03-01-2016 
//        Fichier de déclaration et de définition pour les fonctions de 
//        traitement du circuit IO PCF8574 I2C.
//  
//******************************************************************************

#ifndef X8574_H
  #define X8574_H

//Definitions de parametres. 

#define ECRIREI2C8574 0x40
#define LIREI2C8574 0x41        


//Prédéclaration des fonctions. 
void v8574WriteByte(uint8_t ucData);
uint8_t uc8574ReadByte(void);

#endif 
//******************************************************************************
//   Nom du fichier : 2432.h
//   Auteur : Alain Champagne                  
//      Date de création : 03-01-2016 
//        Fichier de déclaration et de définition pour les fonctions de 
//        traitement du circuit de mémoire I2C 24C32.
//  
//******************************************************************************

#ifndef X2432_H
  #define X2432_H



//Definitions de parametres. 


#define ECRIREI2C24C32 0xA0            
#define LIREI2C24C32 0xA1

//Predeclaration des fonctions. 
void v2432WriteByte(uint8_t ucData, uint16_t uiAdresse);
uint8_t uc2432ReadByte(uint16_t uiAdresse);
void v2432Write(char ucTableau[], uint16_t uiAdresse, uint8_t ucSize);
void v2432Read(char ucTableau[], uint16_t uiAdresse, uint8_t ucSize);


#endif 
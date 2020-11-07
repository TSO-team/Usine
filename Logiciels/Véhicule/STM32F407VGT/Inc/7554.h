//******************************************************************************
//   Nom du fichier : 7554.h
//   Auteur : Alain Champagne                  
//      Date de création : 21-01-2016 
//        Fichier de déclaration et de définition pour les fonctions de  
//        traitement du SPI avec le convertisseur DAC7554.
//  
//******************************************************************************

#ifndef X7554_H
  #define X7554_H

//#include "stm32f4xx_hal_gpio.h"

//Définition de parametres. 
//Le CS employé pour ce device, est la ligne PE6 de la carte système.
//Sur la drive SPI, le CS-DAC est à la patte 10 du connecteur JP4-2 et 
//à la patte 8 du connecteur JP4-1.

//Définition du DEVICE OpCode
#define SPI7554CHANEL0 0x8000
#define SPI7554CHANEL1 0x9000
#define SPI7554CHANEL2 0xA000
#define SPI7554CHANEL3 0xB000

#define CS_SPI7554_H HAL_GPIO_WritePin(GPIOE, SPI_CS_4_Pin, GPIO_PIN_SET)
#define CS_SPI7554_L HAL_GPIO_WritePin(GPIOE, SPI_CS_4_Pin, GPIO_PIN_RESET)


//Predeclaration des fonctions. 
void v7554Write(uint8_t ucChanel, uint16_t uiValue);


#endif 
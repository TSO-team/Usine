//******************************************************************************
//   Nom du fichier : 2544.h
//   Auteur : Alain Champagne                  
//      Date de création : 20-01-2016 
//        Fichier de déclaration et de définition pour les fonctions de  
//        traitement du SPI avec le convertisseur ADC TLV2544ID.
//  
//******************************************************************************

#ifndef X2544_H
  #define X2544_H

//#include "stm32f4xx_hal_gpio.h"

//Definitions de parametres. 
//Le CS employé pour ce device, est la ligne PE4 de la carte système.
//Sur la drive SPI, le CS-ADC est à la patte 8 du connecteur JP4-2 et 
//à la patte 7 du connecteur JP4-1.

#define ECRIRECFRSPI2544 0xA804                  //Configuration simple.

#define CHANEL0 0x00                             
#define CHANEL1 0x20
#define CHANEL2 0x40
#define CHANEL3 0X60

#define LIRECFR 0x90
#define ECRIRECFR 0xA0

    
#define CS_SPI2544_H HAL_GPIO_WritePin(GPIOE, SPI_CS_2_Pin, GPIO_PIN_SET)
#define CS_SPI2544_L HAL_GPIO_WritePin(GPIOE, SPI_CS_2_Pin, GPIO_PIN_RESET)


//Predeclaration des fonctions. 
uint16_t ui2544Read (uint8_t ucChanel);
void v2544Write (uint16_t uiConfiguration);

#endif 
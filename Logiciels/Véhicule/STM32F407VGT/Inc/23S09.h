//******************************************************************************
//   Nom du fichier : 23S09.h
//   Auteur : Alain Champagne                  
//      Date de cr�ation : 20-01-2016 
//        Fichier de d�claration et de d�finition pour les fonctions de  
//        traitement du SPI avec le circuit IO MCP23S09.
//  
//******************************************************************************

#ifndef X23S09_H
  #define X23S09_H

//D�finition de parametres. 
//Le CS employ� pour ce device, est la ligne PE5 de la carte syst�me.
//Sur la drive SPI, le CS-I/O est � la patte 6 du connecteur JP4-2 et 
//� la patte 6 du connecteur JP4-1.

//D�finition du DEVICE OpCode
#define SPI23S09ECRIRE 0x40
#define SPI23S09LIRE 0x41

//D�finition des registres internes.
#define SPIIODIRA 0x00
#define SPIIPOLA 0x01
#define SPIGPINTENA 0x02
#define SPIDEFVALA 0x03
#define SPIINTCONA 0x04
#define SPIIOCON 0x05
#define SPIGPPUA 0x06
#define SPIINTFA 0x07
#define SPIINTCAPA 0x08
#define SPIGPIOA 0x09                            //Pour relire le port GPIOA
#define SPIOLATA 0x0A                            //Pour �crire, on doit �crire 
                                                 //sur le OLATA.

#define CS_SPI23S09_H HAL_GPIO_WritePin(GPIOE, SPI_CS_3_Pin, GPIO_PIN_SET)
#define CS_SPI23S09_L HAL_GPIO_WritePin(GPIOE, SPI_CS_3_Pin, GPIO_PIN_RESET)


//Predeclaration des fonctions. 
void v23S09Read (char ucBufferIn[], uint8_t ucAddRegister);
void v23S09Write (uint8_t ucAddRegister, uint8_t ucValue);

#endif 
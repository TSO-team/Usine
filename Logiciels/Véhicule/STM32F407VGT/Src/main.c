/**
  ******************************************************************************
  * File Name          : main.c
  * Description        : Main program body
  ******************************************************************************
  *
  * Copyright (c) 2017 STMicroelectronics International N.V. 
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without 
  * modification, are permitted, provided that the following conditions are met:
  *
  * 1. Redistribution of source code must retain the above copyright notice, 
  *    this list of conditions and the following disclaimer.
  * 2. Redistributions in binary form must reproduce the above copyright notice,
  *    this list of conditions and the following disclaimer in the documentation
  *    and/or other materials provided with the distribution.
  * 3. Neither the name of STMicroelectronics nor the names of other 
  *    contributors to this software may be used to endorse or promote products 
  *    derived from this software without specific written permission.
  * 4. This software, including modifications and/or derivative works of this 
  *    software, must execute solely and exclusively on microcontroller or
  *    microprocessor devices manufactured by or for STMicroelectronics.
  * 5. Redistribution and use of this software other than as permitted under 
  *    this license is void and will automatically terminate your rights under 
  *    this license. 
  *
  * THIS SOFTWARE IS PROVIDED BY STMICROELECTRONICS AND CONTRIBUTORS "AS IS" 
  * AND ANY EXPRESS, IMPLIED OR STATUTORY WARRANTIES, INCLUDING, BUT NOT 
  * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR A 
  * PARTICULAR PURPOSE AND NON-INFRINGEMENT OF THIRD PARTY INTELLECTUAL PROPERTY
  * RIGHTS ARE DISCLAIMED TO THE FULLEST EXTENT PERMITTED BY LAW. IN NO EVENT 
  * SHALL STMICROELECTRONICS OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
  * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, 
  * OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF 
  * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
  * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
  * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  *
  ******************************************************************************
  */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_hal.h"
#include "usb_device.h"


/* USER CODE BEGIN Includes */
#include "LIS3DSH.h"
#include "IO_BUS.h"
#include "GLcd.h"
#include "ST.h"
#include "Vehicule.h"
/* USER CODE END Includes */

/* Private variables ---------------------------------------------------------*/
ADC_HandleTypeDef hadc1;
ADC_HandleTypeDef hadc2;
ADC_HandleTypeDef hadc3;

CAN_HandleTypeDef hcan1;

I2C_HandleTypeDef hi2c1;

SPI_HandleTypeDef hspi1;

UART_HandleTypeDef huart2;

/* USER CODE BEGIN PV */
/* Private variables ---------------------------------------------------------*/

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
void Error_Handler(void);
static void MX_GPIO_Init(void);
static void MX_ADC1_Init(void);
static void MX_ADC2_Init(void);
static void MX_ADC3_Init(void);
static void MX_CAN1_Init(void);
static void MX_I2C1_Init(void);
static void MX_SPI1_Init(void);
static void MX_USART2_UART_Init(void);

/* USER CODE BEGIN PFP */
/* Private function prototypes -----------------------------------------------*/

/* USER CODE END PFP */

/* USER CODE BEGIN 0 */
 uint8_t ucKey = 0x20;
/* USER CODE END 0 */

int main(void)
{

  /* USER CODE BEGIN 1 */
  
   
  uint8_t ucCode[16] = {'1','2','3','A',
                        '4','5','6','B',
                        '7','8','9','C',
                        '*','0','#','D'};
  
  uint8_t ucTrans[20] = {'0','0','0',0,0,' ',' ',' ',' ',' ',
                         ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}; 
                        // Trame Clavier
 int iRoue[4];
  
 unsigned char ucTrameRoue[20] = {0,0,0,0,0,0,0,0,0,0,
                                  0,0,0,0,0,0,0,0,0,0};
  // 12 (4*3) pour les roues
  // 2 pour checksum

 unsigned char ucTrameDebug[20] = {'A','V','G','A','V','D', 'A','R','G',
                                   'A','R','D'};   
 
  unsigned char ucTableauFloat[20] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',
  ' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};  
  
  uint8_t ucCtrlTele = 0;  // Controle inclinometre ou clavier. Clavier = 0
                           // Inclinometre = 1.
                           // Suiveur = 2
                           // Capteur = 3.
                           // Mode clavier au demarrage.
  
  unsigned char *ucpTrans;
  int *ipRoue;
  unsigned char *ucpTrameRoue;
  float fXData;
  float fYData;
  
/* int iTest;
  unsigned char iTest1;
  unsigned char iTest2;
    unsigned char iTest3;
    unsigned char iTest4;
  unsigned char ucPCF;*/
   
  /* USER CODE END 1 */

  /* MCU Configuration----------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* Configure the system clock */
  SystemClock_Config();

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ADC1_Init();
  MX_ADC2_Init();
  MX_ADC3_Init();
  MX_CAN1_Init();
  MX_I2C1_Init();
  MX_SPI1_Init();
  MX_USART2_UART_Init();
  MX_USB_DEVICE_Init();

  /* USER CODE BEGIN 2 */
  vLIS3DSHEcrire(LIS3DSH_Reg_Ctrl_4, 0x63);
  vLIS3DSHEcrire(LIS3DSH_Reg_Ctrl_5, 0xD8); 
  vInitGLcd();
  vClearGLcd(0x00);
  ucpTrans = &ucTrans[0];
  ipRoue = &iRoue[0];
  ucpTrameRoue = &ucTrameRoue[0];

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
      
    //clavier I2C
    if(ucKey != 0x20)                                 // Touche rentrer?
    {    
      switch (ucCode[ucKey])
      {
      case '1':                                       // Rien
        vPutCharGLcd('1',1,1,5);
        ucTrans[0] = '0';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);
        vPutStringGLcd(ucTrans, 0, 5);    
        break;
        
      case '2':                                        // Avant
        vPutCharGLcd('2',1,1,5);        
        ucTrans[0] = 'F';   
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);     
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case '3':                                       // Rien     
        vPutCharGLcd('3',1,1,5);        
        ucTrans[0] = '0';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);     
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case 'A':                                       // Suiveur
        vPutCharGLcd('A',1,1,5);
        ucTrans[0] = 'A';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);        
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100);
        ucCtrlTele = 2;
        break;
        
      case '4':                                       // Gauche
        vPutCharGLcd('4',1,1,5);
        ucTrans[0] = 'G';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);      
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case '5':                                       // Stop
        vPutCharGLcd('5',1,1,5);        
        ucTrans[0] = 'S';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);          
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case '6':                                       // Droite
        vPutCharGLcd('6',1,1,5);     
        ucTrans[0] = 'D';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);         
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case 'B':                                       // Clavier
        vPutCharGLcd('B',1,1,5);         
        ucTrans[0] = 'M';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);         
        vPutStringGLcd(ucTrans, 0, 5);   
        ucCtrlTele = 0;
        break;
        
      case '7':                                       // Rien
        vPutCharGLcd('7',1,1,5);        
        ucTrans[0] = '0';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);        
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case '8':                                       // Arriere
        vPutCharGLcd('8',1,1,5);       
        ucTrans[0] = 'R';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);
        vPutStringGLcd(ucTrans, 0, 5);
        break;
        
      case '9':                                       // Inclinometre
        vPutCharGLcd('9',1,1,5);      
        ucTrans[0] = 'I';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);       
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100);
        ucCtrlTele = 1;
        break;
        
      case 'C':                                       // Capteur
        vPutCharGLcd('C',1,1,5);      
        ucTrans[0] = 'E';
        ucTrans[1] = '0';
        ucTrans[2] = '0';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);         
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100);
        ucCtrlTele = 2;
        break;
        
      case '*':                                       // Vitesse 1
        vPutCharGLcd('*',1,1,5);
        ucTrans[0] = 'V';
        ucTrans[1] = '1';
        ucTrans[2] = '9';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);     
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100); 
        break;
        
      case '0':                                       // Vitesse 2
        vPutCharGLcd('0',1,1,5);       
        ucTrans[0] = 'V';
        ucTrans[1] = '3';
        ucTrans[2] = '2';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);  
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100); 
        break;
        
      case '#':                                       // Vitesse 3
        vPutCharGLcd('#',1,1,5);      
        ucTrans[0] = 'V';
        ucTrans[1] = '4';
        ucTrans[2] = 'B';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);     
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100); 
        break;
        
      case 'D':                                       // Vitesse 4
        vPutCharGLcd('D',1,1,5);        
        ucTrans[0] = 'V';
        ucTrans[1] = '6';
        ucTrans[2] = '4';
        ucTrans[3] = 0;                               // Checksum                                
        ucTrans[4] = 0;                               // Checksum
        vChecksum(ucpTrans);     
        vPutStringGLcd(ucTrans, 0, 5);
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100);
        break;
      }
      
     if(ucCtrlTele == 0)
      {
        HAL_UART_Transmit(&huart2, ucpTrans, 14, 100);    
      }
      
      ucKey = 0x20;
      ucpTrans = &ucTrans[0];
    }    //fin if uckey
    
    if(ucCtrlTele == 1) // Inclinometre
    {
      fXData = fLIS3DSHLireSortieX(LIS3DSH_Sense_8g); // Lecture axe des x
      sprintf(ucTableauFloat, "%+2.2f",fXData);
      vPutStringGLcd(ucTableauFloat,2,5);  
      vPutCharGLcd('X',2,5,5); 
      
      fYData = fLIS3DSHLireSortieY(LIS3DSH_Sense_8g); // lecture axe des y
      sprintf(ucTableauFloat, "%+2.2f",fYData);
      vPutStringGLcd(ucTableauFloat,3,5);
      vPutCharGLcd('Y',3,5,5); 
        
      if((fXData <= 0.25) && (fXData >= -0.25))       // Threshold min
      {
        fXData = 0;
      }
      
      if((fYData <= 0.25) && (fYData >= -0.25))       // Threshold min
      {
        fYData = 0;
      }
      
      
      if(fXData > 0.75)   // Threshold max
      {
        fXData = 0.75;
      }
      
      if(fXData < -0.75)  // Threshold max
      {
        fXData = -0.75;
      }
      
      if(fYData > 0.75)   // Threshold max
      {
        fYData = 0.75;
      }
      
      if(fYData < -0.75)  // Threshold max
      {
        fYData = -0.75;
      }
      
      fYData = fYData * (-1);
          
      if((fXData == 0) || (fYData == 0))       // Lineaire  
      {
        if((fXData == 0) && (fYData > 0.25))   // Avant
        {
          iRoue[0] = iConVit(fYData);          // AVG
          iRoue[1] = iConVit(fYData);          // AVD
          iRoue[2] = iConVit(fYData);          // ARG
          iRoue[3] = iConVit(fYData);          // ARD
        }
        
        if((fXData == 0) && (fYData < -0.25))  // Arrière
        {
          iRoue[0] = iConVit(fYData);          // AVG
          iRoue[1] = iConVit(fYData);          // AVD
          iRoue[2] = iConVit(fYData);          // ARG
          iRoue[3] = iConVit(fYData);          // ARD
        }
        
        if((fXData > 0.25) && (fYData == 0))   // Droite
        {
          iRoue[0] = iConVit(fXData);          // AVG
          iRoue[1] = iConVit(-fXData);         // AVD
          iRoue[2] = iConVit(fXData);          // ARG
          iRoue[3] = iConVit(-fXData);         // ARD 
        }
        
        if((fXData < -0.25) && (fYData == 0))  // Gauche
        {
          iRoue[0] = iConVit(fXData);          // AVG
          iRoue[1] = iConVit(-fXData);         // AVD
          iRoue[2] = iConVit(fXData);          // ARG
          iRoue[3] = iConVit(-fXData);         // ARD
        }
        
        if((fXData == 0) && (fYData == 0))     // Stop
        {
          iRoue[0] = 0x200;                    // AVG
          iRoue[1] = 0x200;                    // AVD
          iRoue[2] = 0x200;                    // ARG
          iRoue[3] = 0x200;                    // ARD
        }
        
      }
      else                                     // Diagonale
      {
        if((fXData < 0) && (fYData > 0))       // Gauche Avant
        {
          iRoue[0] = iConVit(fYData) - iConX(fXData); // AVG
          iRoue[1] = iConVit(fYData);                 // AVD
          iRoue[2] = iConVit(fYData) - iConX(fXData); // ARG
          iRoue[3] = iConVit(fYData);                 // ARD
        }
        if((fXData > 0) && (fYData > 0))   // Droit Avant
        { 
          iRoue[0] = iConVit(fYData);                 // AVG
          iRoue[1] = iConVit(fYData) - iConX(fXData); // AVD
          iRoue[2] = iConVit(fYData);                 // ARG
          iRoue[3] = iConVit(fYData) - iConX(fXData); // ARD
        }
        if((fXData < 0) && (fYData < 0))   // Gauche Arriere
        {
          iRoue[0] = iConVit(fYData);                 // AVG
          iRoue[1] = iConVit(fYData) + iConX(fXData); // AVD
          iRoue[2] = iConVit(fYData);                 // ARG
          iRoue[3] = iConVit(fYData) + iConX(fXData); // ARD
        }
        if((fXData > 0) && (fYData < 0))   // Droit Arriere
        {
          iRoue[0] = iConVit(fYData) + iConX(fXData); // AVG
          iRoue[1] = iConVit(fYData);                 // AVD
          iRoue[2] = iConVit(fYData) + iConX(fXData); // ARG
          iRoue[3] = iConVit(fYData);                 // ARD
        }
        
      }
      
      vIntToASCII(ipRoue,ucpTrameRoue);
      ucTrameRoue[12] = 0;                // Checksum
      ucTrameRoue[13] = 0;                // CheckSum
      vChecksum(ucpTrameRoue);
      HAL_UART_Transmit(&huart2, ucpTrameRoue, 14, 100);
      vPutStringGLcd(ucTrameRoue,4,5);
      vPutStringGLcd(ucTrameDebug,5,5);
     } //fin if inclinometre
    
    //Test MAX1236
   /* 
    iTest = i1236ReadChanel();
    iTest1 = ((iTest & 0xF000) >> 12) + 0x30;
    iTest2 = ((iTest & 0x0F00) >> 8) + 0x30;
    iTest3 = ((iTest & 0x00F0) >> 4)+ 0x30;
    iTest4 = (iTest & 0x000F)+ 0x30;
    vPutCharGLcd(iTest1,1,0,5);
    vPutCharGLcd(iTest2,1,1,5);
    vPutCharGLcd(iTest3,1,2,5);
    vPutCharGLcd(iTest4,1,3,5);
    
    //Test Dac
  //  v6574WriteInt('0', 0xFfff);
    
    //Test PCF
    //ucPCF = (uc8574ReadByte() + 0x30);
   ///vPutCharGLcd(ucPCF,1,0,5);
   // v8574WriteByte(0x35);
    */
    
  /* USER CODE END WHILE */

  /* USER CODE BEGIN 3 */

  }
  /* USER CODE END 3 */

}

/** System Clock Configuration
*/
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;

    /**Configure the main internal regulator output voltage 
    */
  __HAL_RCC_PWR_CLK_ENABLE();

  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE1);

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 8;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV2;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

    /**Initializes the CPU, AHB and APB busses clocks 
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV4;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_5) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure the Systick interrupt time 
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick 
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/* ADC1 init function */
static void MX_ADC1_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc1.Instance = ADC1;
  hadc1.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc1.Init.Resolution = ADC_RESOLUTION_12B;
  hadc1.Init.ScanConvMode = DISABLE;
  hadc1.Init.ContinuousConvMode = DISABLE;
  hadc1.Init.DiscontinuousConvMode = DISABLE;
  hadc1.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc1.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  hadc1.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc1.Init.NbrOfConversion = 1;
  hadc1.Init.DMAContinuousRequests = DISABLE;
  hadc1.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc1) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_TEMPSENSOR;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc1, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

/* ADC2 init function */
static void MX_ADC2_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc2.Instance = ADC2;
  hadc2.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc2.Init.Resolution = ADC_RESOLUTION_12B;
  hadc2.Init.ScanConvMode = DISABLE;
  hadc2.Init.ContinuousConvMode = DISABLE;
  hadc2.Init.DiscontinuousConvMode = DISABLE;
  hadc2.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc2.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  hadc2.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc2.Init.NbrOfConversion = 1;
  hadc2.Init.DMAContinuousRequests = DISABLE;
  hadc2.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc2) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_11;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc2, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

/* ADC3 init function */
static void MX_ADC3_Init(void)
{

  ADC_ChannelConfTypeDef sConfig;

    /**Configure the global features of the ADC (Clock, Resolution, Data Alignment and number of conversion) 
    */
  hadc3.Instance = ADC3;
  hadc3.Init.ClockPrescaler = ADC_CLOCK_SYNC_PCLK_DIV4;
  hadc3.Init.Resolution = ADC_RESOLUTION_12B;
  hadc3.Init.ScanConvMode = DISABLE;
  hadc3.Init.ContinuousConvMode = DISABLE;
  hadc3.Init.DiscontinuousConvMode = DISABLE;
  hadc3.Init.ExternalTrigConvEdge = ADC_EXTERNALTRIGCONVEDGE_RISING;
  hadc3.Init.ExternalTrigConv = ADC_EXTERNALTRIGCONV_T1_CC1;
  hadc3.Init.DataAlign = ADC_DATAALIGN_RIGHT;
  hadc3.Init.NbrOfConversion = 1;
  hadc3.Init.DMAContinuousRequests = DISABLE;
  hadc3.Init.EOCSelection = ADC_EOC_SINGLE_CONV;
  if (HAL_ADC_Init(&hadc3) != HAL_OK)
  {
    Error_Handler();
  }

    /**Configure for the selected ADC regular channel its corresponding rank in the sequencer and its sample time. 
    */
  sConfig.Channel = ADC_CHANNEL_12;
  sConfig.Rank = 1;
  sConfig.SamplingTime = ADC_SAMPLETIME_3CYCLES;
  if (HAL_ADC_ConfigChannel(&hadc3, &sConfig) != HAL_OK)
  {
    Error_Handler();
  }

}

/* CAN1 init function */
static void MX_CAN1_Init(void)
{

  hcan1.Instance = CAN1;
  hcan1.Init.Prescaler = 16;
  hcan1.Init.Mode = CAN_MODE_NORMAL;
  hcan1.Init.SJW = CAN_SJW_1TQ;
  hcan1.Init.BS1 = CAN_BS1_1TQ;
  hcan1.Init.BS2 = CAN_BS2_1TQ;
  hcan1.Init.TTCM = DISABLE;
  hcan1.Init.ABOM = DISABLE;
  hcan1.Init.AWUM = DISABLE;
  hcan1.Init.NART = DISABLE;
  hcan1.Init.RFLM = DISABLE;
  hcan1.Init.TXFP = DISABLE;
  if (HAL_CAN_Init(&hcan1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* I2C1 init function */
static void MX_I2C1_Init(void)
{

  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* SPI1 init function */
static void MX_SPI1_Init(void)
{

  hspi1.Instance = SPI1;
  hspi1.Init.Mode = SPI_MODE_MASTER;
  hspi1.Init.Direction = SPI_DIRECTION_2LINES;
  hspi1.Init.DataSize = SPI_DATASIZE_8BIT;
  hspi1.Init.CLKPolarity = SPI_POLARITY_LOW;
  hspi1.Init.CLKPhase = SPI_PHASE_1EDGE;
  hspi1.Init.NSS = SPI_NSS_SOFT;
  hspi1.Init.BaudRatePrescaler = SPI_BAUDRATEPRESCALER_256;
  hspi1.Init.FirstBit = SPI_FIRSTBIT_MSB;
  hspi1.Init.TIMode = SPI_TIMODE_DISABLE;
  hspi1.Init.CRCCalculation = SPI_CRCCALCULATION_DISABLE;
  hspi1.Init.CRCPolynomial = 10;
  if (HAL_SPI_Init(&hspi1) != HAL_OK)
  {
    Error_Handler();
  }

}

/* USART2 init function */
static void MX_USART2_UART_Init(void)
{

  huart2.Instance = USART2;
  huart2.Init.BaudRate = 19200;
  huart2.Init.WordLength = UART_WORDLENGTH_8B;
  huart2.Init.StopBits = UART_STOPBITS_1;
  huart2.Init.Parity = UART_PARITY_NONE;
  huart2.Init.Mode = UART_MODE_TX_RX;
  huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
  huart2.Init.OverSampling = UART_OVERSAMPLING_16;
  if (HAL_UART_Init(&huart2) != HAL_OK)
  {
    Error_Handler();
  }

}

/** Configure pins as 
        * Analog 
        * Input 
        * Output
        * EVENT_OUT
        * EXTI
     PC3   ------> I2S2_SD
     PA4   ------> I2S3_WS
     PB10   ------> I2S2_CK
     PC7   ------> I2S3_MCK
     PC10   ------> I2S3_CK
     PC12   ------> I2S3_SD
*/
static void MX_GPIO_Init(void)
{

  GPIO_InitTypeDef GPIO_InitStruct;

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOE_CLK_ENABLE();
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();
  __HAL_RCC_GPIOD_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOE, SPI_CS_0_Pin|CS_I2C_SPI_Pin|SPI_CS_2_Pin|SPI_CS_3_Pin 
                          |SPI_CS_4_Pin|PX5_Pin|INT2309_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, OTG_FS_PowerSwitchOn_Pin|PX7_Pin|PX6_Pin|PX4_Pin 
                          |PX3_Pin|PX2_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, RD_Pin|A4_Pin|CS0_Pin|CS1_Pin 
                          |CS2_Pin|CS3_Pin|CONVERT_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOD, A0_Pin|A1_Pin|A2_Pin|A3_Pin 
                          |LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, PX1_Pin|PX0_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : SPI_CS_0_Pin CS_I2C_SPI_Pin SPI_CS_2_Pin SPI_CS_3_Pin 
                           SPI_CS_4_Pin PX5_Pin INT2309_Pin */
  GPIO_InitStruct.Pin = SPI_CS_0_Pin|CS_I2C_SPI_Pin|SPI_CS_2_Pin|SPI_CS_3_Pin 
                          |SPI_CS_4_Pin|PX5_Pin|INT2309_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pins : EOC2544_Pin PY0_Pin */
  GPIO_InitStruct.Pin = EOC2544_Pin|PY0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : OTG_FS_PowerSwitchOn_Pin PX7_Pin PX6_Pin PX4_Pin 
                           PX3_Pin PX2_Pin */
  GPIO_InitStruct.Pin = OTG_FS_PowerSwitchOn_Pin|PX7_Pin|PX6_Pin|PX4_Pin 
                          |PX3_Pin|PX2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pin : PDM_OUT_Pin */
  GPIO_InitStruct.Pin = PDM_OUT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(PDM_OUT_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : PY7_Pin */
  GPIO_InitStruct.Pin = PY7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(PY7_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : I2S3_WS_Pin */
  GPIO_InitStruct.Pin = I2S3_WS_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(I2S3_WS_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : RD_Pin A4_Pin CS0_Pin CS1_Pin 
                           CS2_Pin CS3_Pin CONVERT_Pin */
  GPIO_InitStruct.Pin = RD_Pin|A4_Pin|CS0_Pin|CS1_Pin 
                          |CS2_Pin|CS3_Pin|CONVERT_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : BOOT1_Pin PY5_Pin PY6_Pin INT8574_Pin */
  GPIO_InitStruct.Pin = BOOT1_Pin|PY5_Pin|PY6_Pin|INT8574_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pins : D0_Pin D1_Pin D2_Pin D3_Pin 
                           D4_Pin D5_Pin D6_Pin D7_Pin */
  GPIO_InitStruct.Pin = D0_Pin|D1_Pin|D2_Pin|D3_Pin 
                          |D4_Pin|D5_Pin|D6_Pin|D7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOE, &GPIO_InitStruct);

  /*Configure GPIO pin : CLK_IN_Pin */
  GPIO_InitStruct.Pin = CLK_IN_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF5_SPI2;
  HAL_GPIO_Init(CLK_IN_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : A0_Pin A1_Pin A2_Pin A3_Pin 
                           LD4_Pin LD3_Pin LD5_Pin LD6_Pin 
                           Audio_RST_Pin */
  GPIO_InitStruct.Pin = A0_Pin|A1_Pin|A2_Pin|A3_Pin 
                          |LD4_Pin|LD3_Pin|LD5_Pin|LD6_Pin 
                          |Audio_RST_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pins : I2S3_MCK_Pin I2S3_SCK_Pin I2S3_SD_Pin */
  GPIO_InitStruct.Pin = I2S3_MCK_Pin|I2S3_SCK_Pin|I2S3_SD_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF6_SPI3;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PX1_Pin PX0_Pin */
  GPIO_InitStruct.Pin = PX1_Pin|PX0_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : PY1_Pin PY2_Pin OTG_FS_OverCurrent_Pin PY3_Pin 
                           PY4_Pin */
  GPIO_InitStruct.Pin = PY1_Pin|PY2_Pin|OTG_FS_OverCurrent_Pin|PY3_Pin 
                          |PY4_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_INPUT;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOD, &GPIO_InitStruct);

  /*Configure GPIO pin : INT_KEY_Pin */
  GPIO_InitStruct.Pin = INT_KEY_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(INT_KEY_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pin : MEMS_INT2_Pin */
  GPIO_InitStruct.Pin = MEMS_INT2_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_EVT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(MEMS_INT2_GPIO_Port, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

}

/* USER CODE BEGIN 4 */



/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @param  None
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler */
  /* User can add his own implementation to report the HAL error return state */
  while(1) 
  {
  }
  /* USER CODE END Error_Handler */ 
}

#ifdef USE_FULL_ASSERT

/**
   * @brief Reports the name of the source file and the source line number
   * where the assert_param error has occurred.
   * @param file: pointer to the source file name
   * @param line: assert_param error line source number
   * @retval None
   */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
    ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */

}

#endif

/**
  * @}
  */ 

/**
  * @}
*/ 

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/

#ifndef __LIS3DSH_H
#define __LIS3DSH_H


#define INCLINAISON 1
#define LIS3DSH_Write_Mask 0x00
#define LIS3DSH_Read_Mask 0x80
#define LIS3DSH_Sense_2g 0.06
#define LIS3DSH_Sense_4g 0.12
#define LIS3DSH_Sense_6g 0.18
#define LIS3DSH_Sense_8g 0.24
#define LIS3DSH_Sense_16g 0.73

#define CS_LIS3DH_H HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_SET)
#define CS_LIS3DH_L HAL_GPIO_WritePin(GPIOE, GPIO_PIN_3, GPIO_PIN_RESET)

//brief Read only information register 1.
#define LIS3DSH_Reg_Info_1 0x0D

//brief Read only information register 2.
#define LIS3DSH_Reg_Info_2 0x0E

//brief Tell you what it is.
#define LIS3DSH_Reg_WHO_AM_I 0x0F

//brief Interrupt and soft reset control register.
#define LIS3DSH_Reg_Ctrl_3 0x23

//brief Power and output configuration register.
#define LIS3DSH_Reg_Ctrl_4 0x20

//brief Scale range and other setting.
#define LIS3DSH_Reg_Ctrl_5 0x24

//brief FIFO and other setting.
#define LIS3DSH_Reg_Ctrl_6 0x25

//brief Status report register.
#define LIS3DSH_Reg_Status 0x27

//brief Temperature output register.
#define LIS3DSH_Reg_Temp_Out 0x0C

//brief X-axis offset register.
#define LIS3DSH_Reg_X_Offset 0x10

//brief Y-axis offset register.
#define LIS3DSH_Reg_Y_Offset 0x11

//brief Z-axis offset register.
#define LIS3DSH_Reg_Z_Offset 0x12

//brief Constant shift signed value X-axis register.
#define LIS3DSH_Reg_X_Constant_Shift 0x13

//brief Constant shift signed value Y-axis register.
#define LIS3DSH_Reg_Y_Constant_Shift 0x14

//brief Constant shift signed value Z-axis register.
#define LIS3DSH_Reg_Z_Constant_Shift 0x15

//brief Long counter for interrupt state machine programming.
#define LIS3DSH_Reg_Long_Counter_L 0x16
#define LIS3DSH_Reg_Long_Counter_H 0x17

//brief Interrupt state register.
#define LIS3DSH_Reg_Interrupt_State 0x18

//brief Vector coefficient register.
#define LIS3DSH_Reg_Vector_Coefficient_1 0x1B
#define LIS3DSH_Reg_Vector_Coefficient_2 0x1C
#define LIS3DSH_Reg_Vector_Coefficient_3 0x1D
#define LIS3DSH_Reg_Vector_Coefficient_4 0x1E

//brief Threshold value e register.
#define LIS3DSH_Reg_Threshold_Value 0x1F

//brief X-axis out register.
#define LIS3DSH_Reg_X_Out_L 0x28
#define LIS3DSH_Reg_X_Out_H 0x29

//brief Y-axis out register.
#define LIS3DSH_Reg_Y_Out_L 0x2A
#define LIS3DSH_Reg_Y_Out_H 0x2B

//brief Z-axis out register
#define LIS3DSH_Reg_Z_Out_L 0x2C
#define LIS3DSH_Reg_Z_Out_H 0x2D

//brief FIFO control register
#define LIS3DSH_Reg_FIFO_Ctrl 0x2E

//brief FIFO source control
#define LIS3DSH_Reg_FIFO_Src_Ctrl 0x2F

//brief Interrupt pin configuration.
#define LIS3DSH_Reg_Ctrl_1 0x21

//brief State machine 1
#define LIS3DSH_Reg_State_Machine_1_Base 0x40

//brief Timer 4 for interrupt pin 1.
#define LIS3DSH_Reg_Timer4_Pin1 0x50

//brief TImer 3 for interrupt pin 1.
#define LIS3DSH_Reg_Timer3_Pin1 0x51

//brief Timer 2 for interrupt pin 1.
#define LIS3DSH_Reg_Timer2_Pin1_L 0x52
#define LIS3DSH_Reg_Timer2_Pin1_H 0x53

//brief Timer 1 for interrupt pin 1.
#define LIS3DSH_Reg_Timer1_Pin1_L 0x54
#define LIS3DSH_Reg_Timer1_Pin1_H 0x55

//brief Thresholed 2 for interrupt pin 1.
#define LIS3DSH_Reg_Threshold_2_Pin1 0x56

//brief Thresholed 1 for interrupt pin 1.
#define LIS3DSH_Reg_Threshold_1_Pin1 0x57

//brief Axis and sign mask for motion detection for pin 1.
#define LIS3DSH_Reg_Mask_B_1 0x59
#define LIS3DSH_Reg_Mask_A_1 0x5A

//brief Setting of threshold, peak detection and flags
#define LIS3DSH_Reg_Setting_Motoin_1 0x5B

//brief Unsigned output of timer for pin 1.
#define LIS3DSH_Reg_Long_Counter_Out_Pin_1_L 0x5D
#define LIS3DSH_Reg_Long_Counter_Out_Pin_1_H 0x5E

//brief Program and reset pointer for pin 1 motion detection operation
#define LIS3DSH_Reg_Program_Reset_Pin_1 0x5C

//brief Output flags on axis for interrupt pin 1 management
#define LIS3DSH_Reg_Interrupt_Manage_Pin_1 0x5F

//brief Peak detection value register for pin 1 operation
#define LIS3DSH_Reg_Peak_Detect_Pin_1 0x19

//brief State program 2 interrupt MNG - pin 2 control register.
#define LIS3DSH_Reg_Ctrl_2 0x22

//brief State Machine 2 code register
#define LIS3DSH_Reg_State_Machine_2_Base 0x60

//brief Timer 4 for interrupt pin 2.
#define LIS3DSH_Reg_Timer4_Pin2 0x70

//brief TImer 3 for interrupt pin 2.
#define LIS3DSH_Reg_Timer3_Pin2 0x71

//brief Timer 2 for interrupt pin 2.
#define LIS3DSH_Reg_Timer2_Pin2_L 0x72
#define LIS3DSH_Reg_Timer2_Pin2_H 0x73

//brief Timer 1 for interrupt pin 2.
#define LIS3DSH_Reg_Timer1_Pin2_L 0x74
#define LIS3DSH_Reg_Timer1_Pin2_H 0x75

//brief Threshold signed value for pin 2 operation.
#define LIS3DSH_Reg_Threshold_2_Pin2 0x76

//brief Threshold signed value for pin 2 operation.
#define LIS3DSH_Reg_Threshold_1_Pin2 0x77

//brief Axis and sign mask (swap) for pin 2 motion detection operation
#define LIS3DSH_Reg_Mask_A_2 0x7A

//brief Axis and sign mask (swap) for SM2 motion detection operation
#define LIS3DSH_Reg_Mask_B_2 0x79

//brief Setting of threshold, peak detection and flags for pin 2 motion 
//detection operation.
#define LIS3DSH_Reg_Setting_Motoin_2 0x7B

//brief Program and reset pointer for pin 2 motion detection operation.
#define LIS3DSH_Reg_Program_Reset_Pin_2 0x7C

//brief 16-bit general timer (unsigned output value)
#define LIS3DSH_Reg_Long_Counter_Out_Pin_2_H 0x7E
#define LIS3DSH_Reg_Long_Counter_Out_Pin_2_L 0x7D

//brief Output flags on axis for interrupt SM2 management.
#define LIS3DSH_Reg_Interrupt_Manage_Pin_2 0x7F

//brief Peak detection value register for SM2 operation.
#define LIS3DSH_Reg_Peak_Detect_Pin_2 0x1A

//brief Decimation counter value register for SM2 operation.
#define LIS3DSH_Reg_Decimation_Counter_Pin2 0x78

//addtogroup Function Paramater
 #define LIS3DSH_Output_Power_Down 0x00
 #define LIS3DSH_Output_Rate_3Hz 0x10
 #define LIS3DSH_Output_Rate_6Hz 0x20
 #define LIS3DSH_Output_Rate_12Hz 0x30
 #define LIS3DSH_Output_Rate_25Hz 0x40
 #define LIS3DSH_Output_Rate_50Hz 0x50
 #define LIS3DSH_Output_Rate_100Hz 0x60
 #define LIS3DSH_Output_Rate_400Hz 0x70
 #define LIS3DSH_Output_Rate_800Hz 0x80
 #define LIS3DSH_Output_Rate_1600Hz 0xA0
 #define LIS3DSH_Output_Contius 0x00
 #define LIS3DSH_Output_Single 0x08
 #define LIS3DSH_Output_Z_Enable 0x04
 #define LIS3DSH_Output_Y_Enable 0x02
 #define LIS3DSH_Output_X_Enable 0x01
 #define LIS3DSH_Output_Reset 0x00
 #define LIS3DSH_Output_Feature_Filter_Bandwidth_800Hz 0x00
 #define LIS3DSH_Output_Feature_Filter_Bandwidth_400Hz 0x40
 #define LIS3DSH_Output_Feature_Filter_Bandwidth_200Hz 0x80
 #define LIS3DSH_Output_Feature_Filter_Bandwidth_50Hz 0xC0
 #define LIS3DSH_Output_Feature_Range_2g 0x00
 #define LIS3DSH_Output_Feature_Range_4g 0x08
 #define LIS3DSH_Output_Feature_Range_6g 0x10
 #define LIS3DSH_Output_Feature_Range_8g 0x18
 #define LIS3DSH_Output_Feature_Range_16g 0x20
 #define LIS3DSH_Output_Feature_Self_Test_Normal 0x00
 #define LIS3DSH_Output_Feature_Self_Test_Positive 0x02
 #define LIS3DSH_Output_Feature_Self_Test_Nagetive 0x04
 #define LIS3DSH_Output_Feature_Self_Test_Disable 0x06
 #define LIS3DSH_Output_Feature_SPI_4_Wire 0x00
 #define LIS3DSH_Output_Feature_SPI_3_Wire 0x01
 #define LIS3DSH_Output_Feature_Reset 0x00
  

 uint8_t ucLIS3DSHLire(uint8_t LIS3DSH_Reg); 
 void vLIS3DSHEcrire(uint8_t LIS3DSH_Reg, uint8_t ucData); 
 float fLIS3DSHLireSortieX(float LIS3DSH_Sense);
 float fLIS3DSHLireSortieY(float LIS3DSH_Sense);
 float fLIS3DSHLireSortieZ(float LIS3DSH_Sense);
 uint8_t ucLIS302DLLire(uint8_t LIS3DSH_Reg); 
 void vLIS302DLEcrire(uint8_t LIS3DSH_Reg, uint8_t ucData); 
 float fLIS302DLLireSortieX(float LIS3DSH_Sense);
 float fLIS302DLLireSortieY(float LIS3DSH_Sense);
 float fLIS302DLLireSortieZ(float LIS3DSH_Sense);

#endif

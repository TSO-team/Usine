#include "ioDS89C450.h"

#ifndef CONVERSION_KEIL_TO_IAR_H
  #define CONVERSION_KEIL_TO_IAR_H

  #define data __data
  #define xdata __xdata
  #define code __code

  #define P1_0 P1_bit.P10_T2
  #define P1_1 P1_bit.P11_T2EX
  #define P1_2 P1_bit.P12_RXD1
  #define P1_3 P1_bit.P13_TXD1
  #define P1_4 P1_bit.P14_INT2
  #define P1_5 P1_bit.P15_INT3
  #define P1_6 P1_bit.P16_INT4
  #define P1_7 P1_bit.P17_INT5

  #define P3_0 P3_bit.P30_RXD0
  #define P3_1 P3_bit.P31_TXD0
  #define P3_2 P3_bit.P32_INT0
  #define P3_3 P3_bit.P33_INT1
  #define P3_4 P3_bit.P34_T0
  #define P3_5 P3_bit.P35_T1
  #define P3_6 P3_bit.P36_WR
  #define P3_7 P3_bit.P37_RD

  #define SDA P3_4
  #define SCL P3_5

  #define TI_0 SCON0_bit.TI_0
  #define RI_0 SCON0_bit.RI_0
  #define TI_1 SCON1_bit.TI_1
  #define RI_1 SCON1_bit.RI_1
  #define TR1 TCON_bit.TR1
  #define EA IE_bit.EA
  #define ES0 IE_bit.ES0
  #define ES1 IE_bit.ES1
#endif





// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@







///////////////////////////////////////////////////////////////////////////////
//                               ioDS89C450.h
// Special header for the Maxim (Dallas Semiconductor) DS89C450 Microcontroller
///////////////////////////////////////////////////////////////////////////////
#ifndef IODS89C450_H
  #define IODS89C450_H
  #define __DS89C450__
  #ifdef __IAR_SYSTEMS_ICC__
    #pragma language=extended

///////////////////////////////////////////////////////////////////////////////
// All SFRs
///////////////////////////////////////////////////////////////////////////////
__sfr __no_init volatile union {
  unsigned char EIP1;
  struct {
    unsigned char MPX2 : 1, MPX3 : 1, MPX4 : 1, MPX5 : 1, MPWDI : 1, : 4;
  } EIP1_bit;
} @ 0xF1;

__sfr __no_init volatile unsigned char ACC @ 0xE0;
__sfr __no_init volatile unsigned char TL2 @ 0xCC;

__sfr __no_init volatile union {
  unsigned char T2MOD;
  struct {unsigned char DCEN : 1, T2OE : 1, : 6;} T2MOD_bit;
} @ 0xC9;

__sfr __no_init volatile union {
  unsigned char IP0;
  struct {
    unsigned char LPX0 : 1, LPT0 : 1, LPX1 : 1, LPT1 : 1, LPS0 : 1, LPT2 : 1;
    unsigned char LPS1 : 1, : 1;
  } IP0_bit;
} @ 0xB8;

__sfr __no_init volatile unsigned char SADDR1 @ 0xAA;

__sfr __no_init volatile union {
  unsigned char ACON;
  struct {unsigned char : 5, PAGES0 : 1, PAGES1 : 1, PAGEE : 1;} ACON_bit;
} @ 0x9D;

__sfr __no_init volatile unsigned char SBUF0 @ 0x99;
__sfr __no_init volatile unsigned char TH0 @ 0x8C;

__sfr __no_init volatile union {
  unsigned char TCON;
  struct {
    unsigned char IT0 : 1, IE0 : 1, IT1 : 1, IE1 : 1, TR0 : 1, TF0 : 1;
    unsigned char TR1 : 1, TF1 : 1;
  } TCON_bit;
} @ 0x88;

__sfr __no_init volatile union {
  unsigned char PSW;
  struct {
    unsigned char P : 1, F1 : 1, OV : 1, RS0 : 1, RS1 : 1, F0 : 1, AC : 1;
    unsigned char CY : 1;
  } PSW_bit;
} @ 0xD0;

__sfr __no_init volatile unsigned char TH2 @ 0xCD;
__sfr __no_init volatile unsigned char SADEN0 @ 0xB9;

__sfr __no_init volatile union {
  unsigned char IE;
  struct {
    unsigned char EX0 : 1, ET0 : 1, EX1 : 1, ET1 : 1, ES0 : 1;
    unsigned char ET2 : 1, ES1 : 1, EA : 1;
  } IE_bit;
} @ 0xA8;

__sfr __no_init volatile union {
  unsigned char P1;
  struct {
    unsigned char P10_T2 : 1, P11_T2EX : 1, P12_RXD1 : 1, P13_TXD1 : 1;
    unsigned char P14_INT2 : 1, P15_INT3 : 1, P16_INT4 : 1, P17_INT5 : 1;
  } P1_bit;
} @ 0x90;

__sfr __no_init volatile unsigned char TH1 @ 0x8D;

__sfr __no_init volatile union {
  unsigned char TMOD;
  struct {
    unsigned char M00 : 1, M10 : 1, C_T0 : 1, GATE0 : 1, M01 : 1;
    unsigned char M11 : 1, C_T1 : 1, GATE1 : 1;
  } TMOD_bit;
} @ 0x89;

__sfr __no_init volatile union {
  unsigned char SCON1;
  struct {
    unsigned char RI_1 : 1, TI_1 : 1, RB8_1 : 1, TB8_1 : 1, REN_1 : 1;
    unsigned char SM2_1 : 1, SM1_1 : 1, SM0_FE_1 : 1;
  } SCON1_bit;
} @ 0xC0;

__sfr __no_init volatile unsigned char SADDR0 @ 0xA9;

__sfr __no_init volatile union {
  unsigned char EXIF;
  struct {
    unsigned char BGS : 1, RGSL : 1, RGMD : 1, CKRY : 1, IE2 : 1;
    unsigned char IE3 : 1, IE4 : 1, IE5 : 1;
  } EXIF_bit;
} @ 0x91;

__sfr __no_init volatile union {
  unsigned char CKCON;
  struct {
    unsigned char MD0 : 1, MD1 : 1, MD2 : 1, T0M : 1, T1M : 1;
    unsigned char T2M : 1, WD0 : 1, WD1 : 1;
  } CKCON_bit;
} @ 0x8E;

__sfr __no_init volatile union {
  unsigned char P0;
  struct {
    unsigned char P00 : 1, P01 : 1, P02 : 1, P03 : 1, P04 : 1, P05 : 1;
    unsigned char P06 : 1, P07 : 1;
  } P0_bit;
} @ 0x80;

__sfr __no_init volatile unsigned char SBUF1 @ 0xC1;

__sfr __no_init volatile union {
  unsigned char P3;
  struct {
    unsigned char P30_RXD0 : 1, P31_TXD0 : 1, P32_INT0 : 1, P33_INT1 : 1;
    unsigned char P34_T0 : 1, P35_T1 : 1, P36_WR : 1, P37_RD : 1;
  } P3_bit;
} @ 0xB0;

__sfr __no_init volatile unsigned char SP @ 0x81;

__sfr __no_init volatile union {
  unsigned char ROMSIZE;
  struct {
    unsigned char RMS0 : 1, RMS1 : 1, RMS2 : 1, PRAME : 1, : 4;
  } ROMSIZE_bit;
} @ 0xC2;

__sfr __no_init volatile union {
  unsigned char IP1;
  struct {
    unsigned char MPX0 : 1, MPT0 : 1, MPX1 : 1, MPT1 : 1, MPS0 : 1, MPT2 : 1;
    unsigned char MPS1 : 1, : 1;
  } IP1_bit;
} @ 0xB1;

__sfr __no_init volatile union {
  unsigned char P2;
  struct {
    unsigned char P20 : 1, P21 : 1, P22 : 1, P23 : 1, P24 : 1, P25 : 1;
    unsigned char P26 : 1, P27 : 1;
  } P2_bit;
} @ 0xA0;

__sfr __no_init volatile unsigned char DPL @ 0x82;
__sfr __no_init volatile unsigned char DPH @ 0x83;

__sfr __no_init volatile union {
  unsigned char FCNTL;
  struct {
    unsigned char FC0 : 1, FC1 : 1, FC2 : 1, FC3 : 1, : 2, FERR : 1, FBUSY : 1;
  } FCNTL_bit;
} @ 0xD5;

__sfr __no_init volatile union {
  unsigned char PMR;
  struct {
    unsigned char DME0 : 1, DME1 : 1, ALEON : 1, _4X__2X : 1, CTM : 1;
    unsigned char SWB : 1, CD0 : 1, CD1 : 1;
  } PMR_bit;
} @ 0xC4;

__sfr __no_init volatile unsigned char DPL1 @ 0x84;

__sfr __no_init volatile union {
  unsigned char EIP0;
  struct {
    unsigned char LPX2 : 1, LPX3 : 1, LPX4 : 1, LPX5 : 1, LPWDI : 1, : 3;
  } EIP0_bit;
} @ 0xF8;

__sfr __no_init volatile unsigned char FDATA @ 0xD6;

__sfr __no_init volatile union {
  unsigned char STATUS;
  struct {
    unsigned char SPRA0 : 1, SPTA0 : 1, SPRA1 : 1, SPTA1 : 1, : 1;
    unsigned char PIS0 : 1, PIS1 : 1, PIS2 : 1;
  } STATUS_bit;
} @ 0xC5;

__sfr __no_init volatile union {
  unsigned char CKMOD;
  struct {unsigned char : 3, T0MH : 1, T1MH : 1, T2MH : 1, : 2;} CKMOD_bit;
} @ 0x96;

__sfr __no_init volatile unsigned char DPH1 @ 0x85;

__sfr __no_init volatile union {
  unsigned char EIE;
  struct {
    unsigned char EX2 : 1, EX3 : 1, EX4 : 1, EX5 : 1, EWDI : 1, : 3;
  } EIE_bit;
} @ 0xE8;

__sfr __no_init volatile unsigned char RCAP2L @ 0xCA;

__sfr __no_init volatile union {
  unsigned char DPS;
  struct {
    unsigned char SEL : 1, : 3, AID : 1, TSL : 1, ID0 : 1, ID1 : 1;
  } DPS_bit;
} @ 0x86;

__sfr __no_init volatile union {
  unsigned char WDCON;
  struct {
    unsigned char RWT : 1, EWT : 1, WTRF : 1, WDIF : 1, PFI : 1;
    unsigned char EPFI : 1, POR : 1, SMOD_1 : 1;
  } WDCON_bit;
} @ 0xD8;

__sfr __no_init volatile unsigned char RCAP2H @ 0xCB;
__sfr __no_init volatile unsigned char TA @ 0xC7;
__sfr __no_init volatile unsigned char SADEN1 @ 0xBA;

__sfr __no_init volatile union {
  unsigned char SCON0;
  struct {
    unsigned char RI_0 : 1, TI_0 : 1, RB8_0 : 1, TB8_0 : 1, REN_0 : 1;
    unsigned char SM2_0 : 1, SM1_0 : 1, SM0_FE_0 : 1;
  } SCON0_bit;
} @ 0x98;

__sfr __no_init volatile unsigned char TL0 @ 0x8A;

__sfr __no_init volatile union {
  unsigned char PCON;
  struct {
    unsigned char IDLE : 1, STOP : 1, GF0 : 1, GF1 : 1, OFDE : 1;
    unsigned char OFDF : 1, SMOD0 : 1, SMOD_0 : 1;
  } PCON_bit;
} @ 0x87;

__sfr __no_init volatile unsigned char B @ 0xF0;

__sfr __no_init volatile union {
  unsigned char T2CON;
  struct {
    unsigned char CP_RL2 : 1, C_T2 : 1, TR2 : 1, EXEN2 : 1, TCLK : 1;
    unsigned char RCLK : 1, EXF2 : 1, TF2 : 1;
  } T2CON_bit;
} @ 0xC8;

__sfr __no_init volatile unsigned char TL1 @ 0x8B;

///////////////////////////////////////////////////////////////////////////////
// Interrupt Vectors
///////////////////////////////////////////////////////////////////////////////
#define IE0_int 0x03  // External Interrupt 0
#define TF0_int 0x0B  // Timer 0 Overflow
#define IE1_int 0x13  // External Interrupt 1
#define TF1_int 0x1B  // Timer 1 Overflow
#define RI_0_int 0x23 // Serial Port 0
#define TI_0_int 0x23 // Serial Port 0
#define TF2_int 0x2B  // Timer 2 Overflow
#define EXF2_int 0x2B // Timer 2 Overflow
#define PFI_int 0x33  // Power Fail
#define RI_1_int 0x3B // Serial Port 1
#define TI_1_int 0x3B // Serial Port 1
#define IE2_int 0x43  // External Interrupt 2
#define IE3_int 0x4B  // External Interrupt 3
#define IE4_int 0x53  // External Interrupt 4
#define IE5_int 0x5B  // External Interrupt 5
#define WDIF_int 0x63 // Watchdog

#pragma language=default
#endif  /* __IAR_SYSTEMS_ICC__  */

///////////////////////////////////////////////////////////////////////////////
// Assembler definitions
// The following SFRs are built in in the a8051.exe and can not be
// defined explicitly in this file:
//  ACC,B,PSW,SP,DPL,DPH
// The PSW-bits are built-in in the a8051.exe
//  OV,AC,F0,RS0,RS1,P
///////////////////////////////////////////////////////////////////////////////

#ifdef __IAR_SYSTEMS_ASM__
///////////////////////////////////////////////////////////////////////////////
// All SFRs
///////////////////////////////////////////////////////////////////////////////
P0 DEFINE 0x80
P0_P00 DEFINE 0x80.0
P0_P01 DEFINE 0x80.1
P0_P02 DEFINE 0x80.2
P0_P03 DEFINE 0x80.3
P0_P04 DEFINE 0x80.4
P0_P05 DEFINE 0x80.5
P0_P06 DEFINE 0x80.6
P0_P07 DEFINE 0x80.7
DPL1 DEFINE 0x84
DPH1 DEFINE 0x85
DPS DEFINE 0x86
PCON DEFINE 0x87
TCON DEFINE 0x88
TCON_IT0 DEFINE 0x88.0
TCON_IE0 DEFINE 0x88.1
TCON_IT1 DEFINE 0x88.2
TCON_IE1 DEFINE 0x88.3
TCON_TR0 DEFINE 0x88.4
TCON_TF0 DEFINE 0x88.5
TCON_TR1 DEFINE 0x88.6
TCON_TF1 DEFINE 0x88.7
TMOD DEFINE 0x89
TL0 DEFINE 0x8A
TL1 DEFINE 0x8B
TH0 DEFINE 0x8C
TH1 DEFINE 0x8D
CKCON DEFINE 0x8E
P1 DEFINE 0x90
P1_P10_T2 DEFINE 0x90.0
P1_P11_T2EX DEFINE 0x90.1
P1_P12_RXD1 DEFINE 0x90.2
P1_P13_TXD1 DEFINE 0x90.3
P1_P14_INT2 DEFINE 0x90.4
P1_P15_INT3 DEFINE 0x90.5
P1_P16_INT4 DEFINE 0x90.6
P1_P17_INT5 DEFINE 0x90.7
EXIF DEFINE 0x91
CKMOD DEFINE 0x96
SCON0 DEFINE 0x98
SCON0_RI_0 DEFINE 0x98.0
SCON0_TI_0 DEFINE 0x98.1
SCON0_RB8_0 DEFINE 0x98.2
SCON0_TB8_0 DEFINE 0x98.3
SCON0_REN_0 DEFINE 0x98.4
SCON0_SM2_0 DEFINE 0x98.5
SCON0_SM1_0 DEFINE 0x98.6
SCON0_SM0_FE_0 DEFINE 0x98.7
SBUF0 DEFINE 0x99
ACON DEFINE 0x9D
P2 DEFINE 0xA0
P2_P20 DEFINE 0xA0.0
P2_P21 DEFINE 0xA0.1
P2_P22 DEFINE 0xA0.2
P2_P23 DEFINE 0xA0.3
P2_P24 DEFINE 0xA0.4
P2_P25 DEFINE 0xA0.5
P2_P26 DEFINE 0xA0.6
P2_P27 DEFINE 0xA0.7
IE DEFINE 0xA8
IE_EX0 DEFINE 0xA8.0
IE_ET0 DEFINE 0xA8.1
IE_EX1 DEFINE 0xA8.2
IE_ET1 DEFINE 0xA8.3
IE_ES0 DEFINE 0xA8.4
IE_ET2 DEFINE 0xA8.5
IE_ES1 DEFINE 0xA8.6
IE_EA DEFINE 0xA8.7
SADDR0 DEFINE 0xA9
SADDR1 DEFINE 0xAA
P3 DEFINE 0xB0
P3_P30_RXD0 DEFINE 0xB0.0
P3_P31_TXD0 DEFINE 0xB0.1
P3_P32_INT0 DEFINE 0xB0.2
P3_P33_INT1 DEFINE 0xB0.3
P3_P34_T0 DEFINE 0xB0.4
P3_P35_T1 DEFINE 0xB0.5
P3_P36_WR DEFINE 0xB0.6
P3_P37_RD DEFINE 0xB0.7
IP1 DEFINE 0xB1
IP0 DEFINE 0xB8
IP0_LPX0 DEFINE 0xB8.0
IP0_LPT0 DEFINE 0xB8.1
IP0_LPX1 DEFINE 0xB8.2
IP0_LPT1 DEFINE 0xB8.3
IP0_LPS0 DEFINE 0xB8.4
IP0_LPT2 DEFINE 0xB8.5
IP0_LPS1 DEFINE 0xB8.6
SADEN0 DEFINE 0xB9
SADEN1 DEFINE 0xBA
SCON1 DEFINE 0xC0
SCON1_RI_1 DEFINE 0xC0.0
SCON1_TI_1 DEFINE 0xC0.1
SCON1_RB8_1 DEFINE 0xC0.2
SCON1_TB8_1 DEFINE 0xC0.3
SCON1_REN_1 DEFINE 0xC0.4
SCON1_SM2_1 DEFINE 0xC0.5
SCON1_SM1_1 DEFINE 0xC0.6
SCON1_SM0_FE_1 DEFINE 0xC0.7
SBUF1 DEFINE 0xC1
ROMSIZE DEFINE 0xC2
PMR DEFINE 0xC4
STATUS DEFINE 0xC5
TA DEFINE 0xC7
T2CON DEFINE 0xC8
T2CON_CP_RL2 DEFINE 0xC8.0
T2CON_C_T2 DEFINE 0xC8.1
T2CON_TR2 DEFINE 0xC8.2
T2CON_EXEN2 DEFINE 0xC8.3
T2CON_TCLK DEFINE 0xC8.4
T2CON_RCLK DEFINE 0xC8.5
T2CON_EXF2 DEFINE 0xC8.6
T2CON_TF2 DEFINE 0xC8.7
T2MOD DEFINE 0xC9
RCAP2L DEFINE 0xCA
RCAP2H DEFINE 0xCB
TL2 DEFINE 0xCC
TH2 DEFINE 0xCD
FCNTL DEFINE 0xD5
FDATA DEFINE 0xD6
WDCON DEFINE 0xD8
WDCON_RWT DEFINE 0xD8.0
WDCON_EWT DEFINE 0xD8.1
WDCON_WTRF DEFINE 0xD8.2
WDCON_WDIF DEFINE 0xD8.3
WDCON_PFI DEFINE 0xD8.4
WDCON_EPFI DEFINE 0xD8.5
WDCON_POR DEFINE 0xD8.6
WDCON_SMOD_1 DEFINE 0xD8.7
EIE DEFINE 0xE8
EIE_EX2 DEFINE 0xE8.0
EIE_EX3 DEFINE 0xE8.1
EIE_EX4 DEFINE 0xE8.2
EIE_EX5 DEFINE 0xE8.3
EIE_EWDI DEFINE 0xE8.4
EIP1 DEFINE 0xF1
EIP0 DEFINE 0xF8
EIP0_LPX2 DEFINE 0xF8.0
EIP0_LPX3 DEFINE 0xF8.1
EIP0_LPX4 DEFINE 0xF8.2
EIP0_LPX5 DEFINE 0xF8.3
EIP0_LPWDI DEFINE 0xF8.4

  #endif /* __IAR_SYSTEMS_ASM__*/
#endif /* IODS89C450_H */


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@




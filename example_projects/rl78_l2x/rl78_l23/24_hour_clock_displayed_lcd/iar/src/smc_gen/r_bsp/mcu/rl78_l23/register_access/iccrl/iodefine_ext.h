/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : iodefine_ext.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 05.12.2024 1.90     First Release
***********************************************************************************************************************/

#ifndef __IOR7F100L_EXT_H__
#define __IOR7F100L_EXT_H__

#if !defined(__IASMRL78__) && !defined(__ICCRL78__)
  #error "iodefine_ext.h file for use with RL78 Assembler or Compiler only"
#endif

#if !defined(__S2__)
#define __S2__ __RL78_1__
#endif
#if !defined(__S3__)
#define __S3__ __RL78_2__
#endif
#if !defined(__S1__)
#define __S1__ __RL78_0__
#endif

#if defined(__IASMRL78__)
  #if __CORE__ != __S3__
    #error "iodefine_ext.h file for use with IASMRL78 option --core S3 only"
  #endif
#endif
#if defined(__ICCRL78__)
  #if __CORE__ != __S3__
    #error "iodefine_ext.h file for use with ICCRL78 option --core S3 only"
  #endif
#endif

#ifdef __IAR_SYSTEMS_ICC__

#ifndef _SYSTEM_BUILD
#pragma system_include
#endif

#pragma language=save
#pragma language=extended

/*----------------------------------------------
 * SFR bits (default names)
 *--------------------------------------------*/

#ifndef __RL78_BIT_STRUCTURE__
  #define __RL78_BIT_STRUCTURE__
  typedef struct
  {
    unsigned char no0:1;
    unsigned char no1:1;
    unsigned char no2:1;
    unsigned char no3:1;
    unsigned char no4:1;
    unsigned char no5:1;
    unsigned char no6:1;
    unsigned char no7:1;
  } __BITS8;
#endif

#ifndef __RL78_BIT_STRUCTURE2__
  #define __RL78_BIT_STRUCTURE2__
  typedef struct
  {
    unsigned short no0:1;
    unsigned short no1:1;
    unsigned short no2:1;
    unsigned short no3:1;
    unsigned short no4:1;
    unsigned short no5:1;
    unsigned short no6:1;
    unsigned short no7:1;
    unsigned short no8:1;
    unsigned short no9:1;
    unsigned short no10:1;
    unsigned short no11:1;
    unsigned short no12:1;
    unsigned short no13:1;
    unsigned short no14:1;
    unsigned short no15:1;
  } __BITS16;
#endif

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

__near __no_init volatile union
{
  unsigned char ADM2;
  __BITS8       ADM2_bit;
  struct
  {
    unsigned char  ADTYP0:1;
    unsigned char  ADTYP1:1;
    unsigned char  AWC:1;
    unsigned char  ADRCK:1;
    unsigned char  :4;
  };
} @ 0xF0010;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADUL;
  __BITS8       ADUL_bit;
} @ 0xF0011;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADLL;
  __BITS8       ADLL_bit;
} @ 0xF0012;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTES;
  __BITS8       ADTES_bit;
} @ 0xF0013;

__near __no_bit_access __no_init volatile union
{
  const unsigned short ADCR0;
  const __BITS16       ADCR0_bit;
  struct
  {
    unsigned char :8;
    union
    {
      const unsigned char ADCR0H;
      const __BITS8       ADCR0H_bit;
    };
  };
} @ 0xF0020;

__near __no_init volatile union
{
  unsigned char PU0;
  __BITS8       PU0_bit;
} @ 0xF0030;

__near __no_init volatile union
{
  unsigned char PU1;
  __BITS8       PU1_bit;
} @ 0xF0031;

__near __no_init volatile union
{
  unsigned char PU2;
  __BITS8       PU2_bit;
} @ 0xF0032;

__near __no_init volatile union
{
  unsigned char PU3;
  __BITS8       PU3_bit;
} @ 0xF0033;

__near __no_init volatile union
{
  unsigned char PU4;
  __BITS8       PU4_bit;
} @ 0xF0034;

__near __no_init volatile union
{
  unsigned char PU5;
  __BITS8       PU5_bit;
} @ 0xF0035;

__near __no_init volatile union
{
  unsigned char PU6;
  __BITS8       PU6_bit;
} @ 0xF0036;

__near __no_init volatile union
{
  unsigned char PU7;
  __BITS8       PU7_bit;
} @ 0xF0037;

__near __no_init volatile union
{
  unsigned char PU8;
  __BITS8       PU8_bit;
} @ 0xF0038;

__near __no_init volatile union
{
  unsigned char PU9;
  __BITS8       PU9_bit;
} @ 0xF0039;

__near __no_init volatile union
{
  unsigned char PU12;
  __BITS8       PU12_bit;
} @ 0xF003C;

__near __no_init volatile union
{
  unsigned char PU14;
  __BITS8       PU14_bit;
} @ 0xF003E;

__near __no_init volatile union
{
  unsigned char PIM0;
  __BITS8       PIM0_bit;
} @ 0xF0040;

__near __no_init volatile union
{
  unsigned char PIM1;
  __BITS8       PIM1_bit;
} @ 0xF0041;

__near __no_init volatile union
{
  unsigned char PIM2;
  __BITS8       PIM2_bit;
} @ 0xF0042;

__near __no_init volatile union
{
  unsigned char PIM3;
  __BITS8       PIM3_bit;
} @ 0xF0043;

__near __no_init volatile union
{
  unsigned char PIM4;
  __BITS8       PIM4_bit;
} @ 0xF0044;

__near __no_init volatile union
{
  unsigned char PIM5;
  __BITS8       PIM5_bit;
} @ 0xF0045;

__near __no_init volatile union
{
  unsigned char PIM6;
  __BITS8       PIM6_bit;
} @ 0xF0046;

__near __no_init volatile union
{
  unsigned char PIM7;
  __BITS8       PIM7_bit;
} @ 0xF0047;

__near __no_init volatile union
{
  unsigned char PIM8;
  __BITS8       PIM8_bit;
} @ 0xF0048;

__near __no_init volatile union
{
  unsigned char PIM9;
  __BITS8       PIM9_bit;
} @ 0xF0049;

__near __no_init volatile union
{
  unsigned char PIM12;
  __BITS8       PIM12_bit;
} @ 0xF004C;

__near __no_init volatile union
{
  unsigned char PIM14;
  __BITS8       PIM14_bit;
} @ 0xF004E;

__near __no_init volatile union
{
  unsigned char POM0;
  __BITS8       POM0_bit;
} @ 0xF0050;

__near __no_init volatile union
{
  unsigned char POM1;
  __BITS8       POM1_bit;
} @ 0xF0051;

__near __no_init volatile union
{
  unsigned char POM2;
  __BITS8       POM2_bit;
} @ 0xF0052;

__near __no_init volatile union
{
  unsigned char POM3;
  __BITS8       POM3_bit;
} @ 0xF0053;

__near __no_init volatile union
{
  unsigned char POM4;
  __BITS8       POM4_bit;
} @ 0xF0054;

__near __no_init volatile union
{
  unsigned char POM5;
  __BITS8       POM5_bit;
} @ 0xF0055;

__near __no_init volatile union
{
  unsigned char POM6;
  __BITS8       POM6_bit;
} @ 0xF0056;

__near __no_init volatile union
{
  unsigned char POM7;
  __BITS8       POM7_bit;
} @ 0xF0057;

__near __no_init volatile union
{
  unsigned char POM8;
  __BITS8       POM8_bit;
} @ 0xF0058;

__near __no_init volatile union
{
  unsigned char POM9;
  __BITS8       POM9_bit;
} @ 0xF0059;

__near __no_init volatile union
{
  unsigned char POM12;
  __BITS8       POM12_bit;
} @ 0xF005C;

__near __no_init volatile union
{
  unsigned char POM13;
  __BITS8       POM13_bit;
} @ 0xF005D;

__near __no_init volatile union
{
  unsigned char POM14;
  __BITS8       POM14_bit;
} @ 0xF005E;

__near __no_init volatile union
{
  unsigned char PMCA1;
  __BITS8       PMCA1_bit;
} @ 0xF0061;

__near __no_init volatile union
{
  unsigned char PMCA2;
  __BITS8       PMCA2_bit;
} @ 0xF0062;

__near __no_init volatile union
{
  unsigned char PMCA4;
  __BITS8       PMCA4_bit;
} @ 0xF0064;

__near __no_init volatile union
{
  unsigned char NFEN0;
  __BITS8       NFEN0_bit;
} @ 0xF0070;

__near __no_init volatile union
{
  unsigned char NFEN1;
  __BITS8       NFEN1_bit;
} @ 0xF0071;

__near __no_init volatile union
{
  unsigned char ISC;
  __BITS8       ISC_bit;
} @ 0xF0073;

__near __no_bit_access __no_init volatile union
{
  unsigned char TIS0;
  __BITS8       TIS0_bit;
} @ 0xF0074;

__near __no_bit_access __no_init volatile union
{
  unsigned char TIS1;
  __BITS8       TIS1_bit;
} @ 0xF0075;

__near __no_bit_access __no_init volatile union
{
  unsigned char IAWCTL;
  __BITS8       IAWCTL_bit;
} @ 0xF0078;

__near __no_init volatile union
{
  unsigned char ULBS;
  __BITS8       ULBS_bit;
  struct
  {
    unsigned char  ULBS0:1;
    unsigned char  ULBS1:1;
    unsigned char  ULBS2:1;
    unsigned char  ULBS3:1;
    unsigned char  ULBS4:1;
    unsigned char  ULBS5:1;
    unsigned char  ULBS6:1;
    unsigned char  ULBS7:1;
  };
} @ 0xF0079;

__near __no_init volatile union
{
  unsigned char TOS;
  __BITS8       TOS_bit;
  struct
  {
    unsigned char  TOS0:1;
    unsigned char  :7;
  };
} @ 0xF007A;

__near __no_init volatile union
{
  unsigned char PMS;
  __BITS8       PMS_bit;
} @ 0xF007B;

__near __no_init volatile union
{
  unsigned char DFLCTL;
  __BITS8       DFLCTL_bit;
  struct
  {
    unsigned char  DFLEN:1;
    unsigned char  :7;
  };
} @ 0xF0090;

__near __no_bit_access __no_init volatile union
{
  unsigned char MODRV;
  __BITS8       MODRV_bit;
} @ 0xF009E;

__near __no_bit_access __no_init volatile union
{
  unsigned char HIOTRM;
  __BITS8       HIOTRM_bit;
} @ 0xF00A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char HOCODIV;
  __BITS8       HOCODIV_bit;
} @ 0xF00A8;

__near __no_init volatile union
{
  unsigned char FLMODE;
  __BITS8       FLMODE_bit;
  struct
  {
    unsigned char  :1;
    unsigned char  BANKPGEN:1;
    unsigned char  :4;
    unsigned char  MODE0:1;
    unsigned char  MODE1:1;
  };
} @ 0xF00AA;

__near __no_init volatile union
{
  unsigned char FLMWRP;
  __BITS8       FLMWRP_bit;
  struct
  {
    unsigned char  FLMWEN:1;
    unsigned char  :7;
  };
} @ 0xF00AB;

__near __no_bit_access __no_init volatile union
{
  const unsigned short FLSEC;
  const __BITS16       FLSEC_bit;
} @ 0xF00B0;

__near __no_bit_access __no_init volatile union
{
  const unsigned short FLFSWS;
  const __BITS16       FLFSWS_bit;
} @ 0xF00B2;

__near __no_bit_access __no_init volatile union
{
  const unsigned short FLFSWE;
  const __BITS16       FLFSWE_bit;
} @ 0xF00B4;

__near __no_bit_access __no_init volatile union
{
  unsigned char FSSET;
  __BITS8       FSSET_bit;
} @ 0xF00B6;

__near __no_init volatile union
{
  unsigned char FSSE;
  __BITS8       FSSE_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  ESQST:1;
  };
} @ 0xF00B7;

__near __no_bit_access __no_init volatile union
{
  unsigned char PFCMD;
  __BITS8       PFCMD_bit;
} @ 0xF00C0;

__near __no_init volatile union
{
  const unsigned char PFS;
  const __BITS8       PFS_bit;
} @ 0xF00C1;

__near __no_init volatile union
{
  unsigned char PER0;
  __BITS8       PER0_bit;
  struct
  {
    unsigned char  TAU0EN:1;
    unsigned char  :1;
    unsigned char  SAU0EN:1;
    unsigned char  SAU1EN:1;
    unsigned char  IICA0EN:1;
    unsigned char  ADCEN:1;
    unsigned char  IICA1EN:1;
    unsigned char  RTCWEN:1;
  };
} @ 0xF00F0;

__near __no_init volatile union
{
  unsigned char PRR0;
  __BITS8       PRR0_bit;
  struct
  {
    unsigned char  TAU0RES:1;
    unsigned char  :1;
    unsigned char  SAU0RES:1;
    unsigned char  SAU1RES:1;
    unsigned char  IICA0RES:1;
    unsigned char  ADCRES:1;
    unsigned char  IICA1RES:1;
    unsigned char  :1;
  };
} @ 0xF00F1;

__near __no_bit_access __no_init volatile union
{
  unsigned char MOCODIV;
  __BITS8       MOCODIV_bit;
} @ 0xF00F2;

__near __no_init volatile union
{
  unsigned char OSMC;
  __BITS8       OSMC_bit;
  struct
  {
    unsigned char  HIPREC:1;
    unsigned char  :3;
    unsigned char  WUTMMCK0:1;
    unsigned char  :2;
    unsigned char  RTCLPC:1;
  };
} @ 0xF00F3;

__near __no_init volatile union
{
  unsigned char RPECTL;
  __BITS8       RPECTL_bit;
  struct
  {
    unsigned char  RPEF:1;
    unsigned char  :6;
    unsigned char  RPERDIS:1;
  };
} @ 0xF00F5;

__near __no_init volatile union
{
  unsigned char PORSR;
  __BITS8       PORSR_bit;
  struct
  {
    unsigned char  PORF:1;
    unsigned char  :7;
  };
} @ 0xF00F9;

__near __no_init volatile union
{
  unsigned char PER1;
  __BITS8       PER1_bit;
  struct
  {
    unsigned char  CTSUEN:1;
    unsigned char  :1;
    unsigned char  UTA0EN:1;
    unsigned char  DTCEN:1;
    unsigned char  TML32EN:1;
    unsigned char  CMPEN:1;
    unsigned char  SMSEN:1;
    unsigned char  DACEN:1;
  };
} @ 0xF00FA;

__near __no_init volatile union
{
  unsigned char PRR1;
  __BITS8       PRR1_bit;
  struct
  {
    unsigned char  CTSURES:1;
    unsigned char  :3;
    unsigned char  TML32RES:1;
    unsigned char  CMPRES:1;
    unsigned char  SMSRES:1;
    unsigned char  DACRES:1;
  };
} @ 0xF00FB;

__near __no_init volatile union
{
  unsigned char PER2;
  __BITS8       PER2_bit;
  struct
  {
    unsigned char  TRJ0EN:1;
    unsigned char  TRJ1EN:1;
    unsigned char  UTA1EN:1;
    unsigned char  UTA2EN:1;
    unsigned char  UTA3EN:1;
    unsigned char  TKBEN:1;
    unsigned char  OSDCEN:1;
    unsigned char  EXSDEN:1;
  };
} @ 0xF00FC;

__near __no_init volatile union
{
  unsigned char PRR2;
  __BITS8       PRR2_bit;
  struct
  {
    unsigned char  TRJ0RES:1;
    unsigned char  TRJ1RES:1;
    unsigned char  :3;
    unsigned char  TKBRES:1;
    unsigned char  OSDCRES:1;
    unsigned char  EXSDRES:1;
  };
} @ 0xF00FD;

__near __no_bit_access __no_init volatile union
{
  const unsigned char BCDADJ;
  const __BITS8       BCDADJ_bit;
} @ 0xF00FE;

__near __no_bit_access __no_init volatile union
{
  unsigned char VECTCTRL;
  __BITS8       VECTCTRL_bit;
} @ 0xF00FF;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR00;
  const __BITS16       SSR00_bit;
  struct
  {
    union
    {
      const unsigned char SSR00L;
      const __BITS8       SSR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0100;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR01;
  const __BITS16       SSR01_bit;
  struct
  {
    union
    {
      const unsigned char SSR01L;
      const __BITS8       SSR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0102;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR02;
  const __BITS16       SSR02_bit;
  struct
  {
    union
    {
      const unsigned char SSR02L;
      const __BITS8       SSR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0104;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR03;
  const __BITS16       SSR03_bit;
  struct
  {
    union
    {
      const unsigned char SSR03L;
      const __BITS8       SSR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0106;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR00;
  __BITS16       SIR00_bit;
  struct
  {
    union
    {
      unsigned char SIR00L;
      __BITS8       SIR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0108;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR01;
  __BITS16       SIR01_bit;
  struct
  {
    union
    {
      unsigned char SIR01L;
      __BITS8       SIR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR02;
  __BITS16       SIR02_bit;
  struct
  {
    union
    {
      unsigned char SIR02L;
      __BITS8       SIR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR03;
  __BITS16       SIR03_bit;
  struct
  {
    union
    {
      unsigned char SIR03L;
      __BITS8       SIR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF010E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR00;
  __BITS16       SMR00_bit;
} @ 0xF0110;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR01;
  __BITS16       SMR01_bit;
} @ 0xF0112;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR02;
  __BITS16       SMR02_bit;
} @ 0xF0114;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR03;
  __BITS16       SMR03_bit;
} @ 0xF0116;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR00;
  __BITS16       SCR00_bit;
} @ 0xF0118;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR01;
  __BITS16       SCR01_bit;
} @ 0xF011A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR02;
  __BITS16       SCR02_bit;
} @ 0xF011C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR03;
  __BITS16       SCR03_bit;
} @ 0xF011E;

__near __no_init volatile union
{
  const unsigned short SE0;
  const __BITS16       SE0_bit;
  struct
  {
    union
    {
      const unsigned char SE0L;
      const __BITS8       SE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0120;

__near __no_init volatile union
{
  unsigned short SS0;
  __BITS16       SS0_bit;
  struct
  {
    union
    {
      unsigned char SS0L;
      __BITS8       SS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0122;

__near __no_init volatile union
{
  unsigned short ST0;
  __BITS16       ST0_bit;
  struct
  {
    union
    {
      unsigned char ST0L;
      __BITS8       ST0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0124;

__near __no_bit_access __no_init volatile union
{
  unsigned short SPS0;
  __BITS16       SPS0_bit;
  struct
  {
    union
    {
      unsigned char SPS0L;
      __BITS8       SPS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0126;

__near __no_bit_access __no_init volatile union
{
  unsigned short SO0;
  __BITS16       SO0_bit;
} @ 0xF0128;

__near __no_init volatile union
{
  unsigned short SOE0;
  __BITS16       SOE0_bit;
  struct
  {
    union
    {
      unsigned char SOE0L;
      __BITS8       SOE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF012A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SOL0;
  __BITS16       SOL0_bit;
  struct
  {
    union
    {
      unsigned char SOL0L;
      __BITS8       SOL0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0134;

__near __no_bit_access __no_init volatile union
{
  unsigned short SSC0;
  __BITS16       SSC0_bit;
  struct
  {
    union
    {
      unsigned char SSC0L;
      __BITS8       SSC0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0138;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR10;
  const __BITS16       SSR10_bit;
  struct
  {
    union
    {
      const unsigned char SSR10L;
      const __BITS8       SSR10L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0140;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR11;
  const __BITS16       SSR11_bit;
  struct
  {
    union
    {
      const unsigned char SSR11L;
      const __BITS8       SSR11L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0142;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR12;
  const __BITS16       SSR12_bit;
  struct
  {
    union
    {
      const unsigned char SSR12L;
      const __BITS8       SSR12L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0144;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SSR13;
  const __BITS16       SSR13_bit;
  struct
  {
    union
    {
      const unsigned char SSR13L;
      const __BITS8       SSR13L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0146;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR10;
  __BITS16       SIR10_bit;
  struct
  {
    union
    {
      unsigned char SIR10L;
      __BITS8       SIR10L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0148;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR11;
  __BITS16       SIR11_bit;
  struct
  {
    union
    {
      unsigned char SIR11L;
      __BITS8       SIR11L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR12;
  __BITS16       SIR12_bit;
  struct
  {
    union
    {
      unsigned char SIR12L;
      __BITS8       SIR12L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SIR13;
  __BITS16       SIR13_bit;
  struct
  {
    union
    {
      unsigned char SIR13L;
      __BITS8       SIR13L_bit;
    };
    unsigned char :8;
  };
} @ 0xF014E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR10;
  __BITS16       SMR10_bit;
} @ 0xF0150;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR11;
  __BITS16       SMR11_bit;
} @ 0xF0152;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR12;
  __BITS16       SMR12_bit;
} @ 0xF0154;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMR13;
  __BITS16       SMR13_bit;
} @ 0xF0156;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR10;
  __BITS16       SCR10_bit;
} @ 0xF0158;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR11;
  __BITS16       SCR11_bit;
} @ 0xF015A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR12;
  __BITS16       SCR12_bit;
} @ 0xF015C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR13;
  __BITS16       SCR13_bit;
} @ 0xF015E;

__near __no_init volatile union
{
  const unsigned short SE1;
  const __BITS16       SE1_bit;
  struct
  {
    union
    {
      const unsigned char SE1L;
      const __BITS8       SE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0160;

__near __no_init volatile union
{
  unsigned short SS1;
  __BITS16       SS1_bit;
  struct
  {
    union
    {
      unsigned char SS1L;
      __BITS8       SS1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0162;

__near __no_init volatile union
{
  unsigned short ST1;
  __BITS16       ST1_bit;
  struct
  {
    union
    {
      unsigned char ST1L;
      __BITS8       ST1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0164;

__near __no_bit_access __no_init volatile union
{
  unsigned short SPS1;
  __BITS16       SPS1_bit;
  struct
  {
    union
    {
      unsigned char SPS1L;
      __BITS8       SPS1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0166;

__near __no_bit_access __no_init volatile union
{
  unsigned short SO1;
  __BITS16       SO1_bit;
} @ 0xF0168;

__near __no_init volatile union
{
  unsigned short SOE1;
  __BITS16       SOE1_bit;
  struct
  {
    union
    {
      unsigned char SOE1L;
      __BITS8       SOE1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF016A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SOL1;
  __BITS16       SOL1_bit;
  struct
  {
    union
    {
      unsigned char SOL1L;
      __BITS8       SOL1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0174;

__near __no_bit_access __no_init volatile union
{
  unsigned short SSC1;
  __BITS16       SSC1_bit;
  struct
  {
    union
    {
      unsigned char SSC1L;
      __BITS8       SSC1L_bit;
    };
    unsigned char :8;
  };
} @ 0xF0178;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR00;
  const __BITS16       TCR00_bit;
} @ 0xF0180;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR01;
  const __BITS16       TCR01_bit;
} @ 0xF0182;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR02;
  const __BITS16       TCR02_bit;
} @ 0xF0184;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR03;
  const __BITS16       TCR03_bit;
} @ 0xF0186;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR04;
  const __BITS16       TCR04_bit;
} @ 0xF0188;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR05;
  const __BITS16       TCR05_bit;
} @ 0xF018A;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR06;
  const __BITS16       TCR06_bit;
} @ 0xF018C;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TCR07;
  const __BITS16       TCR07_bit;
} @ 0xF018E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR00;
  __BITS16       TMR00_bit;
} @ 0xF0190;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR01;
  __BITS16       TMR01_bit;
} @ 0xF0192;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR02;
  __BITS16       TMR02_bit;
} @ 0xF0194;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR03;
  __BITS16       TMR03_bit;
} @ 0xF0196;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR04;
  __BITS16       TMR04_bit;
} @ 0xF0198;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR05;
  __BITS16       TMR05_bit;
} @ 0xF019A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR06;
  __BITS16       TMR06_bit;
} @ 0xF019C;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMR07;
  __BITS16       TMR07_bit;
} @ 0xF019E;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR00;
  const __BITS16       TSR00_bit;
  struct
  {
    union
    {
      const unsigned char TSR00L;
      const __BITS8       TSR00L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A0;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR01;
  const __BITS16       TSR01_bit;
  struct
  {
    union
    {
      const unsigned char TSR01L;
      const __BITS8       TSR01L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A2;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR02;
  const __BITS16       TSR02_bit;
  struct
  {
    union
    {
      const unsigned char TSR02L;
      const __BITS8       TSR02L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A4;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR03;
  const __BITS16       TSR03_bit;
  struct
  {
    union
    {
      const unsigned char TSR03L;
      const __BITS8       TSR03L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A6;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR04;
  const __BITS16       TSR04_bit;
  struct
  {
    union
    {
      const unsigned char TSR04L;
      const __BITS8       TSR04L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01A8;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR05;
  const __BITS16       TSR05_bit;
  struct
  {
    union
    {
      const unsigned char TSR05L;
      const __BITS8       TSR05L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AA;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR06;
  const __BITS16       TSR06_bit;
  struct
  {
    union
    {
      const unsigned char TSR06L;
      const __BITS8       TSR06L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AC;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TSR07;
  const __BITS16       TSR07_bit;
  struct
  {
    union
    {
      const unsigned char TSR07L;
      const __BITS8       TSR07L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01AE;

__near __no_init volatile union
{
  const unsigned short TE0;
  const __BITS16       TE0_bit;
  struct
  {
    union
    {
      const unsigned char TE0L;
      const __BITS8       TE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B0;

__near __no_init volatile union
{
  unsigned short TS0;
  __BITS16       TS0_bit;
  struct
  {
    union
    {
      unsigned char TS0L;
      __BITS8       TS0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B2;

__near __no_init volatile union
{
  unsigned short TT0;
  __BITS16       TT0_bit;
  struct
  {
    union
    {
      unsigned char TT0L;
      __BITS8       TT0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TPS0;
  __BITS16       TPS0_bit;
} @ 0xF01B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TO0;
  __BITS16       TO0_bit;
  struct
  {
    union
    {
      unsigned char TO0L;
      __BITS8       TO0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01B8;

__near __no_init volatile union
{
  unsigned short TOE0;
  __BITS16       TOE0_bit;
  struct
  {
    union
    {
      unsigned char TOE0L;
      __BITS8       TOE0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOL0;
  __BITS16       TOL0_bit;
  struct
  {
    union
    {
      unsigned char TOL0L;
      __BITS8       TOL0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TOM0;
  __BITS16       TOM0_bit;
  struct
  {
    union
    {
      unsigned char TOM0L;
      __BITS8       TOM0L_bit;
    };
    unsigned char :8;
  };
} @ 0xF01BE;

__near __no_bit_access __no_init volatile union
{
  unsigned char MIOTRM;
  __BITS8       MIOTRM_bit;
} @ 0xF0212;

__near __no_bit_access __no_init volatile union
{
  unsigned char LIOTRM;
  __BITS8       LIOTRM_bit;
} @ 0xF0213;

__near __no_bit_access __no_init volatile union
{
  unsigned char MOSCDIV;
  __BITS8       MOSCDIV_bit;
} @ 0xF0214;

__near __no_init volatile union
{
  unsigned char WKUPMD;
  __BITS8       WKUPMD_bit;
  struct
  {
    unsigned char  FWKUP:1;
    unsigned char  :7;
  };
} @ 0xF0215;

__near __no_init volatile union
{
  unsigned char PSMCR;
  __BITS8       PSMCR_bit;
  struct
  {
    unsigned char  RAMSDS:1;
    unsigned char  RAMSDMD:1;
    unsigned char  :6;
  };
} @ 0xF0216;

__near __no_bit_access __no_init volatile union
{
  unsigned char SOMRG;
  __BITS8       SOMRG_bit;
} @ 0xF0217;

__near __no_init volatile union
{
  unsigned char LVDFCLR;
  __BITS8       LVDFCLR_bit;
  struct
  {
    unsigned char  :2;
    unsigned char  DLVD0FCLR:1;
    unsigned char  DLVD1FCLR:1;
    unsigned char  :4;
  };
} @ 0xF0218;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEC;
  __BITS8       SEC_bit;
} @ 0xF0220;

__near __no_bit_access __no_init volatile union
{
  unsigned char MIN;
  __BITS8       MIN_bit;
} @ 0xF0221;

__near __no_bit_access __no_init volatile union
{
  unsigned char HOUR;
  __BITS8       HOUR_bit;
} @ 0xF0222;

__near __no_bit_access __no_init volatile union
{
  unsigned char WEEK;
  __BITS8       WEEK_bit;
} @ 0xF0223;

__near __no_bit_access __no_init volatile union
{
  unsigned char DAY;
  __BITS8       DAY_bit;
} @ 0xF0224;

__near __no_bit_access __no_init volatile union
{
  unsigned char MONTH;
  __BITS8       MONTH_bit;
} @ 0xF0225;

__near __no_bit_access __no_init volatile union
{
  unsigned char YEAR;
  __BITS8       YEAR_bit;
} @ 0xF0226;

__near __no_bit_access __no_init volatile union
{
  unsigned char SUBCUD;
  __BITS8       SUBCUD_bit;
} @ 0xF0227;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWM;
  __BITS8       ALARMWM_bit;
} @ 0xF0228;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWH;
  __BITS8       ALARMWH_bit;
} @ 0xF0229;

__near __no_bit_access __no_init volatile union
{
  unsigned char ALARMWW;
  __BITS8       ALARMWW_bit;
} @ 0xF022A;

__near __no_init volatile union
{
  unsigned char RTCC0;
  __BITS8       RTCC0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  RTC128EN:1;
    unsigned char  RCLOE1:1;
    unsigned char  :1;
    unsigned char  RTCE:1;
  };
} @ 0xF022B;

__near __no_init volatile union
{
  unsigned char RTCC1;
  __BITS8       RTCC1_bit;
  struct
  {
    unsigned char  RWAIT:1;
    unsigned char  RWST:1;
    unsigned char  :1;
    unsigned char  RIFG:1;
    unsigned char  WAFG:1;
    unsigned char  :1;
    unsigned char  WALIE:1;
    unsigned char  WALE:1;
  };
} @ 0xF022C;

__near __no_init volatile union
{
  unsigned char IICCTL00;
  __BITS8       IICCTL00_bit;
  struct
  {
    unsigned char  SPT0:1;
    unsigned char  STT0:1;
    unsigned char  ACKE0:1;
    unsigned char  WTIM0:1;
    unsigned char  SPIE0:1;
    unsigned char  WREL0:1;
    unsigned char  LREL0:1;
    unsigned char  IICE0:1;
  };
} @ 0xF0230;

__near __no_init volatile union
{
  unsigned char IICCTL01;
  __BITS8       IICCTL01_bit;
  struct
  {
    unsigned char  PRS0:1;
    unsigned char  :1;
    unsigned char  DFC0:1;
    unsigned char  SMC0:1;
    unsigned char  DAD0:1;
    unsigned char  CLD0:1;
    unsigned char  SVADIS0:1;
    unsigned char  WUP0:1;
  };
} @ 0xF0231;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWL0;
  __BITS8       IICWL0_bit;
} @ 0xF0232;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWH0;
  __BITS8       IICWH0_bit;
} @ 0xF0233;

__near __no_bit_access __no_init volatile union
{
  unsigned char SVA0;
  __BITS8       SVA0_bit;
} @ 0xF0234;

__near __no_init volatile union
{
  unsigned char IICCTL10;
  __BITS8       IICCTL10_bit;
  struct
  {
    unsigned char  SPT1:1;
    unsigned char  STT1:1;
    unsigned char  ACKE1:1;
    unsigned char  WTIM1:1;
    unsigned char  SPIE1:1;
    unsigned char  WREL1:1;
    unsigned char  LREL1:1;
    unsigned char  IICE1:1;
  };
} @ 0xF0238;

__near __no_init volatile union
{
  unsigned char IICCTL11;
  __BITS8       IICCTL11_bit;
  struct
  {
    unsigned char  PRS1:1;
    unsigned char  :1;
    unsigned char  DFC1:1;
    unsigned char  SMC1:1;
    unsigned char  DAD1:1;
    unsigned char  CLD1:1;
    unsigned char  SVADIS1:1;
    unsigned char  WUP1:1;
  };
} @ 0xF0239;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWL1;
  __BITS8       IICWL1_bit;
} @ 0xF023A;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICWH1;
  __BITS8       IICWH1_bit;
} @ 0xF023B;

__near __no_bit_access __no_init volatile union
{
  unsigned char SVA1;
  __BITS8       SVA1_bit;
} @ 0xF023C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRJCR0;
  __BITS8       TRJCR0_bit;
} @ 0xF0240;

__near __no_init volatile union
{
  unsigned char TRJIOC0;
  __BITS8       TRJIOC0_bit;
} @ 0xF0241;

__near __no_init volatile union
{
  unsigned char TRJMR0;
  __BITS8       TRJMR0_bit;
} @ 0xF0242;

__near __no_init volatile union
{
  unsigned char TRJISR0;
  __BITS8       TRJISR0_bit;
} @ 0xF0243;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRJCR1;
  __BITS8       TRJCR1_bit;
} @ 0xF0244;

__near __no_init volatile union
{
  unsigned char TRJIOC1;
  __BITS8       TRJIOC1_bit;
} @ 0xF0245;

__near __no_init volatile union
{
  unsigned char TRJMR1;
  __BITS8       TRJMR1_bit;
} @ 0xF0246;

__near __no_init volatile union
{
  unsigned char TRJISR1;
  __BITS8       TRJISR1_bit;
} @ 0xF0247;

__near __no_init volatile union
{
  unsigned char EXSDM1;
  __BITS8       EXSDM1_bit;
  struct
  {
    unsigned char  EXSDLPC:1;
    unsigned char  :7;
  };
} @ 0xF025A;

__near __no_init volatile union
{
  unsigned char EXSDM0;
  __BITS8       EXSDM0_bit;
  struct
  {
    unsigned char  EXSDOE00:1;
    unsigned char  EXSDOE01:1;
    unsigned char  :3;
    unsigned char  PRTY0:1;
    unsigned char  EXSDD00:1;
    unsigned char  EXSDD01:1;
  };
} @ 0xF025B;

__near __no_init volatile union
{
  unsigned char PMCT0;
  __BITS8       PMCT0_bit;
} @ 0xF0260;

__near __no_init volatile union
{
  unsigned char PMCT3;
  __BITS8       PMCT3_bit;
} @ 0xF0263;

__near __no_init volatile union
{
  unsigned char PMCT5;
  __BITS8       PMCT5_bit;
} @ 0xF0265;

__near __no_init volatile union
{
  unsigned char PMCT7;
  __BITS8       PMCT7_bit;
} @ 0xF0267;

__near __no_init volatile union
{
  unsigned char PMCT9;
  __BITS8       PMCT9_bit;
} @ 0xF0269;

__near __no_init volatile union
{
  unsigned char PMCT12;
  __BITS8       PMCT12_bit;
} @ 0xF026C;

__near __no_init volatile union
{
  unsigned char PMCE0;
  __BITS8       PMCE0_bit;
} @ 0xF0280;

__near __no_init volatile union
{
  unsigned char PMCE1;
  __BITS8       PMCE1_bit;
} @ 0xF0281;

__near __no_init volatile union
{
  unsigned char PMCE6;
  __BITS8       PMCE6_bit;
} @ 0xF0286;

__near __no_init volatile union
{
  unsigned char PMCE7;
  __BITS8       PMCE7_bit;
} @ 0xF0287;

__near __no_init volatile union
{
  unsigned char PFSEG0;
  __BITS8       PFSEG0_bit;
} @ 0xF0290;

__near __no_init volatile union
{
  unsigned char PFSEG1;
  __BITS8       PFSEG1_bit;
} @ 0xF0291;

__near __no_init volatile union
{
  unsigned char PFSEG2;
  __BITS8       PFSEG2_bit;
} @ 0xF0292;

__near __no_init volatile union
{
  unsigned char PFSEG3;
  __BITS8       PFSEG3_bit;
} @ 0xF0293;

__near __no_init volatile union
{
  unsigned char PFSEG4;
  __BITS8       PFSEG4_bit;
} @ 0xF0294;

__near __no_init volatile union
{
  unsigned char PFSEG5;
  __BITS8       PFSEG5_bit;
} @ 0xF0295;

__near __no_init volatile union
{
  unsigned char PFSEG6;
  __BITS8       PFSEG6_bit;
} @ 0xF0296;

__near __no_init volatile union
{
  unsigned char PFSEG7;
  __BITS8       PFSEG7_bit;
} @ 0xF0297;

__near __no_init volatile union
{
  unsigned char ISCLCD;
  __BITS8       ISCLCD_bit;
} @ 0xF0298;

__near __no_bit_access __no_init volatile union
{
  unsigned char LCDM2;
  __BITS8       LCDM2_bit;
} @ 0xF0299;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADM1EX;
  __BITS8       ADM1EX_bit;
} @ 0xF029E;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS0;
  __BITS8       CCS0_bit;
} @ 0xF02A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS4;
  __BITS8       CCS4_bit;
} @ 0xF02A4;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS5;
  __BITS8       CCS5_bit;
} @ 0xF02A5;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS6;
  __BITS8       CCS6_bit;
} @ 0xF02A6;

__near __no_bit_access __no_init volatile union
{
  unsigned char CCS7;
  __BITS8       CCS7_bit;
} @ 0xF02A7;

__near __no_init volatile union
{
  unsigned char CCDE;
  __BITS8       CCDE_bit;
} @ 0xF02A8;

__near __no_init volatile union
{
  unsigned char PTDC;
  __BITS8       PTDC_bit;
} @ 0xF02A9;

__near __no_init volatile union
{
  unsigned char PFOE0;
  __BITS8       PFOE0_bit;
} @ 0xF02AA;

__near __no_init volatile union
{
  unsigned char PFOE1;
  __BITS8       PFOE1_bit;
} @ 0xF02AB;

__near __no_init volatile union
{
  unsigned char PDIDIS0;
  __BITS8       PDIDIS0_bit;
} @ 0xF02B0;

__near __no_init volatile union
{
  unsigned char PDIDIS1;
  __BITS8       PDIDIS1_bit;
} @ 0xF02B1;

__near __no_init volatile union
{
  unsigned char PDIDIS2;
  __BITS8       PDIDIS2_bit;
} @ 0xF02B2;

__near __no_init volatile union
{
  unsigned char PDIDIS3;
  __BITS8       PDIDIS3_bit;
} @ 0xF02B3;

__near __no_init volatile union
{
  unsigned char PDIDIS4;
  __BITS8       PDIDIS4_bit;
} @ 0xF02B4;

__near __no_init volatile union
{
  unsigned char PDIDIS5;
  __BITS8       PDIDIS5_bit;
} @ 0xF02B5;

__near __no_init volatile union
{
  unsigned char PDIDIS6;
  __BITS8       PDIDIS6_bit;
} @ 0xF02B6;

__near __no_init volatile union
{
  unsigned char PDIDIS7;
  __BITS8       PDIDIS7_bit;
} @ 0xF02B7;

__near __no_init volatile union
{
  unsigned char PDIDIS8;
  __BITS8       PDIDIS8_bit;
} @ 0xF02B8;

__near __no_init volatile union
{
  unsigned char PDIDIS9;
  __BITS8       PDIDIS9_bit;
} @ 0xF02B9;

__near __no_init volatile union
{
  unsigned char PDIDIS12;
  __BITS8       PDIDIS12_bit;
} @ 0xF02BC;

__near __no_init volatile union
{
  unsigned char PDIDIS13;
  __BITS8       PDIDIS13_bit;
} @ 0xF02BD;

__near __no_init volatile union
{
  unsigned char PDIDIS14;
  __BITS8       PDIDIS14_bit;
} @ 0xF02BE;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLPMC;
  __BITS8       FLPMC_bit;
} @ 0xF02C0;

__near __no_init volatile union
{
  unsigned char FLARS;
  __BITS8       FLARS_bit;
} @ 0xF02C1;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLAPL;
  __BITS16       FLAPL_bit;
} @ 0xF02C2;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLAPH;
  __BITS8       FLAPH_bit;
} @ 0xF02C4;

__near __no_init volatile union
{
  unsigned char FSSQ;
  __BITS8       FSSQ_bit;
  struct
  {
    unsigned char  :6;
    unsigned char  FSSTP:1;
    unsigned char  SQST:1;
  };
} @ 0xF02C5;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSEDL;
  __BITS16       FLSEDL_bit;
} @ 0xF02C6;

__near __no_bit_access __no_init volatile union
{
  unsigned char FLSEDH;
  __BITS8       FLSEDH_bit;
} @ 0xF02C8;

__near __no_init volatile union
{
  unsigned char FLRST;
  __BITS8       FLRST_bit;
} @ 0xF02C9;

__near __no_init volatile union
{
  const unsigned char FSASTL;
  const __BITS8       FSASTL_bit;
} @ 0xF02CA;

__near __no_init volatile union
{
  const unsigned char FSASTH;
  const __BITS8       FSASTH_bit;
} @ 0xF02CB;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLWL;
  __BITS16       FLWL_bit;
} @ 0xF02CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLWH;
  __BITS16       FLWH_bit;
} @ 0xF02CE;

__near __no_bit_access __no_init volatile union
{
  unsigned short OSDC;
  __BITS16       OSDC_bit;
} @ 0xF02D0;

__near __no_init volatile union
{
  unsigned char CLKDCTL;
  __BITS8       CLKDCTL_bit;
  struct
  {
    unsigned char  CLKDEN0:1;
    unsigned char  CLKDEN1:1;
    unsigned char  CLKDEN2:1;
    unsigned char  CLKDEN3:1;
    unsigned char  :4;
  };
} @ 0xF02D4;

__near __no_bit_access __no_init volatile union
{
  unsigned char DTCBAR;
  __BITS8       DTCBAR_bit;
} @ 0xF02E0;

__near __no_init volatile union
{
  unsigned char DTCEN0;
  __BITS8       DTCEN0_bit;
} @ 0xF02E8;

__near __no_init volatile union
{
  unsigned char DTCEN1;
  __BITS8       DTCEN1_bit;
} @ 0xF02E9;

__near __no_init volatile union
{
  unsigned char DTCEN2;
  __BITS8       DTCEN2_bit;
} @ 0xF02EA;

__near __no_init volatile union
{
  unsigned char DTCEN3;
  __BITS8       DTCEN3_bit;
} @ 0xF02EB;

__near __no_init volatile union
{
  unsigned char DTCEN4;
  __BITS8       DTCEN4_bit;
} @ 0xF02EC;

__near __no_init volatile union
{
  unsigned char DTCEN5;
  __BITS8       DTCEN5_bit;
} @ 0xF02ED;

__near __no_init volatile union
{
  unsigned char DTCEN6;
  __BITS8       DTCEN6_bit;
} @ 0xF02EE;

__near __no_init volatile union
{
  unsigned char CRC0CTL;
  __BITS8       CRC0CTL_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  CRC0EN:1;
  };
} @ 0xF02F0;

__near __no_bit_access __no_init volatile union
{
  unsigned short PGCRCL;
  __BITS16       PGCRCL_bit;
} @ 0xF02F2;

__near __no_bit_access __no_init volatile union
{
  unsigned short CRCD;
  __BITS16       CRCD_bit;
} @ 0xF02FA;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA0;
  __BITS8       TXBA0_bit;
} @ 0xF0300;

__near __no_bit_access __no_init volatile union
{
  const unsigned char RXBA0;
  const __BITS8       RXBA0_bit;
} @ 0xF0301;

__near __no_init volatile union
{
  unsigned char ASIMA00;
  __BITS8       ASIMA00_bit;
  struct
  {
    unsigned char  ISRMA0:1;
    unsigned char  ISSMA0:1;
    unsigned char  :3;
    unsigned char  RXEA0:1;
    unsigned char  TXEA0:1;
    unsigned char  UARTAEN0:1;
  };
} @ 0xF0302;

__near __no_init volatile union
{
  unsigned char ASIMA01;
  __BITS8       ASIMA01_bit;
} @ 0xF0303;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA0;
  __BITS8       BRGCA0_bit;
} @ 0xF0304;

__near __no_bit_access __no_init volatile union
{
  const unsigned char ASISA0;
  const __BITS8       ASISA0_bit;
} @ 0xF0305;

__near __no_init volatile union
{
  unsigned char ASCTA0;
  __BITS8       ASCTA0_bit;
  struct
  {
    unsigned char  OVECTA0:1;
    unsigned char  FECTA0:1;
    unsigned char  PECTA0:1;
    unsigned char  :5;
  };
} @ 0xF0306;

__near __no_init volatile union
{
  unsigned char UTA0CK;
  __BITS8       UTA0CK_bit;
} @ 0xF0310;

__near __no_init volatile union
{
  unsigned char TMC5MG;
  __BITS8       TMC5MG_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  TCE5MG:1;
  };
} @ 0xF0320;

__near __no_init volatile union
{
  unsigned char TCL5MG;
  __BITS8       TCL5MG_bit;
  struct
  {
    unsigned char  TCL5MG0:1;
    unsigned char  :7;
  };
} @ 0xF0321;

__near __no_bit_access __no_init volatile union
{
  unsigned char CR5MGL;
  __BITS8       CR5MGL_bit;
} @ 0xF0322;

__near __no_bit_access __no_init volatile union
{
  unsigned char CR5MGH;
  __BITS8       CR5MGH_bit;
} @ 0xF0323;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS0;
  __BITS8       DACS0_bit;
} @ 0xF0330;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS1;
  __BITS8       DACS1_bit;
} @ 0xF0331;

__near __no_init volatile union
{
  unsigned char DAM0;
  __BITS8       DAM0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  DACE0:1;
    unsigned char  DACE1:1;
    unsigned char  :2;
  };
} @ 0xF0332;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS2;
  __BITS8       DACS2_bit;
} @ 0xF0338;

__near __no_init volatile union
{
  unsigned char DAM1;
  __BITS8       DAM1_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  DACE2:1;
    unsigned char  :3;
  };
} @ 0xF033A;

__near __no_init volatile union
{
  unsigned char COMPMDR;
  __BITS8       COMPMDR_bit;
  struct
  {
    unsigned char  C0ENB:1;
    unsigned char  :3;
    unsigned char  C1ENB:1;
    unsigned char  :3;
  };
} @ 0xF0340;

__near __no_init volatile union
{
  unsigned char COMPFIR;
  __BITS8       COMPFIR_bit;
} @ 0xF0341;

__near __no_init volatile union
{
  unsigned char COMPOCR;
  __BITS8       COMPOCR_bit;
  struct
  {
    unsigned char  C0IE:1;
    unsigned char  C0OE:1;
    unsigned char  :2;
    unsigned char  C1IE:1;
    unsigned char  C1OE:1;
    unsigned char  :2;
  };
} @ 0xF0342;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TM3L;
  const __BITS8       TM3L_bit;
} @ 0xF0350;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TM3H;
  const __BITS8       TM3H_bit;
} @ 0xF0351;

__near __no_init volatile union
{
  unsigned char TMC3;
  __BITS8       TMC3_bit;
  struct
  {
    unsigned char  COVF3:1;
    unsigned char  :6;
    unsigned char  TM3ST:1;
  };
} @ 0xF0352;

__near __no_bit_access __no_init volatile union
{
  unsigned short ITLCMP00;
  __BITS16       ITLCMP00_bit;
  struct
  {
    union
    {
      unsigned char ITLCMP000;
      __BITS8       ITLCMP000_bit;
    };
    union
    {
      unsigned char ITLCMP001;
      __BITS8       ITLCMP001_bit;
    };
  };
} @ 0xF0360;

__near __no_bit_access __no_init volatile union
{
  unsigned short ITLCMP01;
  __BITS16       ITLCMP01_bit;
  struct
  {
    union
    {
      unsigned char ITLCMP012;
      __BITS8       ITLCMP012_bit;
    };
    union
    {
      unsigned char ITLCMP013;
      __BITS8       ITLCMP013_bit;
    };
  };
} @ 0xF0362;

__near __no_bit_access __no_init volatile union
{
  const unsigned short ITLCAP00;
  const __BITS16       ITLCAP00_bit;
} @ 0xF0364;

__near __no_init volatile union
{
  unsigned char ITLCTL0;
  __BITS8       ITLCTL0_bit;
  struct
  {
    unsigned char  ITLEN00:1;
    unsigned char  ITLEN01:1;
    unsigned char  ITLEN02:1;
    unsigned char  ITLEN03:1;
    unsigned char  :4;
  };
} @ 0xF0366;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLCSEL0;
  __BITS8       ITLCSEL0_bit;
} @ 0xF0367;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLFDIV00;
  __BITS8       ITLFDIV00_bit;
} @ 0xF0368;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLFDIV01;
  __BITS8       ITLFDIV01_bit;
} @ 0xF0369;

__near __no_init volatile union
{
  unsigned char ITLCC0;
  __BITS8       ITLCC0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  CAPR0:1;
    unsigned char  :1;
    unsigned char  CAPF0CR:1;
    unsigned char  :1;
  };
} @ 0xF036A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLS0;
  __BITS8       ITLS0_bit;
} @ 0xF036B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ITLMKF0;
  __BITS8       ITLMKF0_bit;
} @ 0xF036C;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL0;
  __BITS8       INTPCTL0_bit;
} @ 0xF0370;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL1;
  __BITS8       INTPCTL1_bit;
} @ 0xF0371;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL2;
  __BITS8       INTPCTL2_bit;
} @ 0xF0372;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL3;
  __BITS8       INTPCTL3_bit;
} @ 0xF0373;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL4;
  __BITS8       INTPCTL4_bit;
} @ 0xF0374;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL5;
  __BITS8       INTPCTL5_bit;
} @ 0xF0375;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL6;
  __BITS8       INTPCTL6_bit;
} @ 0xF0376;

__near __no_bit_access __no_init volatile union
{
  unsigned char INTPCTL7;
  __BITS8       INTPCTL7_bit;
} @ 0xF0377;

__near __no_bit_access __no_init volatile union
{
  unsigned char TPS2;
  __BITS8       TPS2_bit;
} @ 0xF037F;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI0;
  __BITS16       SMSI0_bit;
} @ 0xF0380;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI1;
  __BITS16       SMSI1_bit;
} @ 0xF0382;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI2;
  __BITS16       SMSI2_bit;
} @ 0xF0384;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI3;
  __BITS16       SMSI3_bit;
} @ 0xF0386;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI4;
  __BITS16       SMSI4_bit;
} @ 0xF0388;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI5;
  __BITS16       SMSI5_bit;
} @ 0xF038A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI6;
  __BITS16       SMSI6_bit;
} @ 0xF038C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI7;
  __BITS16       SMSI7_bit;
} @ 0xF038E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI8;
  __BITS16       SMSI8_bit;
} @ 0xF0390;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI9;
  __BITS16       SMSI9_bit;
} @ 0xF0392;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI10;
  __BITS16       SMSI10_bit;
} @ 0xF0394;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI11;
  __BITS16       SMSI11_bit;
} @ 0xF0396;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI12;
  __BITS16       SMSI12_bit;
} @ 0xF0398;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI13;
  __BITS16       SMSI13_bit;
} @ 0xF039A;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI14;
  __BITS16       SMSI14_bit;
} @ 0xF039C;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI15;
  __BITS16       SMSI15_bit;
} @ 0xF039E;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI16;
  __BITS16       SMSI16_bit;
} @ 0xF03A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI17;
  __BITS16       SMSI17_bit;
} @ 0xF03A2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI18;
  __BITS16       SMSI18_bit;
} @ 0xF03A4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI19;
  __BITS16       SMSI19_bit;
} @ 0xF03A6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI20;
  __BITS16       SMSI20_bit;
} @ 0xF03A8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI21;
  __BITS16       SMSI21_bit;
} @ 0xF03AA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI22;
  __BITS16       SMSI22_bit;
} @ 0xF03AC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI23;
  __BITS16       SMSI23_bit;
} @ 0xF03AE;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI24;
  __BITS16       SMSI24_bit;
} @ 0xF03B0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI25;
  __BITS16       SMSI25_bit;
} @ 0xF03B2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI26;
  __BITS16       SMSI26_bit;
} @ 0xF03B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI27;
  __BITS16       SMSI27_bit;
} @ 0xF03B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI28;
  __BITS16       SMSI28_bit;
} @ 0xF03B8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI29;
  __BITS16       SMSI29_bit;
} @ 0xF03BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI30;
  __BITS16       SMSI30_bit;
} @ 0xF03BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSI31;
  __BITS16       SMSI31_bit;
} @ 0xF03BE;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SMSG0;
  const __BITS16       SMSG0_bit;
} @ 0xF03C0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG1;
  __BITS16       SMSG1_bit;
} @ 0xF03C2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG2;
  __BITS16       SMSG2_bit;
} @ 0xF03C4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG3;
  __BITS16       SMSG3_bit;
} @ 0xF03C6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG4;
  __BITS16       SMSG4_bit;
} @ 0xF03C8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG5;
  __BITS16       SMSG5_bit;
} @ 0xF03CA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG6;
  __BITS16       SMSG6_bit;
} @ 0xF03CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG7;
  __BITS16       SMSG7_bit;
} @ 0xF03CE;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG8;
  __BITS16       SMSG8_bit;
} @ 0xF03D0;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG9;
  __BITS16       SMSG9_bit;
} @ 0xF03D2;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG10;
  __BITS16       SMSG10_bit;
} @ 0xF03D4;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG11;
  __BITS16       SMSG11_bit;
} @ 0xF03D6;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG12;
  __BITS16       SMSG12_bit;
} @ 0xF03D8;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG13;
  __BITS16       SMSG13_bit;
} @ 0xF03DA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SMSG14;
  __BITS16       SMSG14_bit;
} @ 0xF03DC;

__near __no_bit_access __no_init volatile union
{
  const unsigned short SMSG15;
  const __BITS16       SMSG15_bit;
} @ 0xF03DE;

__near __no_init volatile union
{
  unsigned char SMSC;
  __BITS8       SMSC_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  LONGWAIT:1;
    unsigned char  SMSTRGWAIT:1;
    unsigned char  SMSSTOP:1;
    unsigned char  SMSSTART:1;
  };
} @ 0xF03E0;

__near __no_init volatile union
{
  const unsigned char SMSS;
  const __BITS8       SMSS_bit;
  struct
  {
          unsigned char  :7;
    const unsigned char  SMSSTAT:1;
  };
} @ 0xF03E1;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG0;
  __BITS8       SEG0_bit;
} @ 0xF0400;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG1;
  __BITS8       SEG1_bit;
} @ 0xF0401;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG2;
  __BITS8       SEG2_bit;
} @ 0xF0402;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG3;
  __BITS8       SEG3_bit;
} @ 0xF0403;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG4;
  __BITS8       SEG4_bit;
} @ 0xF0404;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG5;
  __BITS8       SEG5_bit;
} @ 0xF0405;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG6;
  __BITS8       SEG6_bit;
} @ 0xF0406;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG7;
  __BITS8       SEG7_bit;
} @ 0xF0407;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG8;
  __BITS8       SEG8_bit;
} @ 0xF0408;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG9;
  __BITS8       SEG9_bit;
} @ 0xF0409;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG10;
  __BITS8       SEG10_bit;
} @ 0xF040A;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG11;
  __BITS8       SEG11_bit;
} @ 0xF040B;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG12;
  __BITS8       SEG12_bit;
} @ 0xF040C;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG13;
  __BITS8       SEG13_bit;
} @ 0xF040D;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG14;
  __BITS8       SEG14_bit;
} @ 0xF040E;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG15;
  __BITS8       SEG15_bit;
} @ 0xF040F;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG16;
  __BITS8       SEG16_bit;
} @ 0xF0410;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG17;
  __BITS8       SEG17_bit;
} @ 0xF0411;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG18;
  __BITS8       SEG18_bit;
} @ 0xF0412;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG19;
  __BITS8       SEG19_bit;
} @ 0xF0413;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG20;
  __BITS8       SEG20_bit;
} @ 0xF0414;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG21;
  __BITS8       SEG21_bit;
} @ 0xF0415;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG22;
  __BITS8       SEG22_bit;
} @ 0xF0416;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG23;
  __BITS8       SEG23_bit;
} @ 0xF0417;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG24;
  __BITS8       SEG24_bit;
} @ 0xF0418;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG25;
  __BITS8       SEG25_bit;
} @ 0xF0419;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG26;
  __BITS8       SEG26_bit;
} @ 0xF041A;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG27;
  __BITS8       SEG27_bit;
} @ 0xF041B;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG28;
  __BITS8       SEG28_bit;
} @ 0xF041C;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG29;
  __BITS8       SEG29_bit;
} @ 0xF041D;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG30;
  __BITS8       SEG30_bit;
} @ 0xF041E;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG31;
  __BITS8       SEG31_bit;
} @ 0xF041F;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG32;
  __BITS8       SEG32_bit;
} @ 0xF0420;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG33;
  __BITS8       SEG33_bit;
} @ 0xF0421;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG34;
  __BITS8       SEG34_bit;
} @ 0xF0422;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG35;
  __BITS8       SEG35_bit;
} @ 0xF0423;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG36;
  __BITS8       SEG36_bit;
} @ 0xF0424;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG37;
  __BITS8       SEG37_bit;
} @ 0xF0425;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG38;
  __BITS8       SEG38_bit;
} @ 0xF0426;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG39;
  __BITS8       SEG39_bit;
} @ 0xF0427;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG40;
  __BITS8       SEG40_bit;
} @ 0xF0428;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG41;
  __BITS8       SEG41_bit;
} @ 0xF0429;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG42;
  __BITS8       SEG42_bit;
} @ 0xF042A;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG43;
  __BITS8       SEG43_bit;
} @ 0xF042B;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG44;
  __BITS8       SEG44_bit;
} @ 0xF042C;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG45;
  __BITS8       SEG45_bit;
} @ 0xF042D;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG46;
  __BITS8       SEG46_bit;
} @ 0xF042E;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG47;
  __BITS8       SEG47_bit;
} @ 0xF042F;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG48;
  __BITS8       SEG48_bit;
} @ 0xF0430;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG49;
  __BITS8       SEG49_bit;
} @ 0xF0431;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG50;
  __BITS8       SEG50_bit;
} @ 0xF0432;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG51;
  __BITS8       SEG51_bit;
} @ 0xF0433;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG52;
  __BITS8       SEG52_bit;
} @ 0xF0434;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG53;
  __BITS8       SEG53_bit;
} @ 0xF0435;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG54;
  __BITS8       SEG54_bit;
} @ 0xF0436;

__near __no_bit_access __no_init volatile union
{
  unsigned char SEG55;
  __BITS8       SEG55_bit;
} @ 0xF0437;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP0;
  __BITS16       TRTCMP0_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP00;
      __BITS8       TRTCMP00_bit;
    };
    union
    {
      unsigned char TRTCMP01;
      __BITS8       TRTCMP01_bit;
    };
  };
} @ 0xF0440;

__near __no_init volatile union
{
  unsigned char TRTCR0;
  __BITS8       TRTCR0_bit;
  struct
  {
    unsigned char  TSTART00:1;
    unsigned char  :1;
    unsigned char  TSTART01:1;
    unsigned char  :5;
  };
} @ 0xF0442;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD0;
  __BITS8       TRTMD0_bit;
} @ 0xF0443;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP1;
  __BITS16       TRTCMP1_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP10;
      __BITS8       TRTCMP10_bit;
    };
    union
    {
      unsigned char TRTCMP11;
      __BITS8       TRTCMP11_bit;
    };
  };
} @ 0xF0448;

__near __no_init volatile union
{
  unsigned char TRTCR1;
  __BITS8       TRTCR1_bit;
  struct
  {
    unsigned char  TSTART10:1;
    unsigned char  :1;
    unsigned char  TSTART11:1;
    unsigned char  :5;
  };
} @ 0xF044A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD1;
  __BITS8       TRTMD1_bit;
} @ 0xF044B;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP2;
  __BITS16       TRTCMP2_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP20;
      __BITS8       TRTCMP20_bit;
    };
    union
    {
      unsigned char TRTCMP21;
      __BITS8       TRTCMP21_bit;
    };
  };
} @ 0xF0450;

__near __no_init volatile union
{
  unsigned char TRTCR2;
  __BITS8       TRTCR2_bit;
  struct
  {
    unsigned char  TSTART20:1;
    unsigned char  :1;
    unsigned char  TSTART21:1;
    unsigned char  :5;
  };
} @ 0xF0452;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD2;
  __BITS8       TRTMD2_bit;
} @ 0xF0453;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP3;
  __BITS16       TRTCMP3_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP30;
      __BITS8       TRTCMP30_bit;
    };
    union
    {
      unsigned char TRTCMP31;
      __BITS8       TRTCMP31_bit;
    };
  };
} @ 0xF0458;

__near __no_init volatile union
{
  unsigned char TRTCR3;
  __BITS8       TRTCR3_bit;
  struct
  {
    unsigned char  TSTART30:1;
    unsigned char  :1;
    unsigned char  TSTART31:1;
    unsigned char  :5;
  };
} @ 0xF045A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD3;
  __BITS8       TRTMD3_bit;
} @ 0xF045B;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP4;
  __BITS16       TRTCMP4_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP40;
      __BITS8       TRTCMP40_bit;
    };
    union
    {
      unsigned char TRTCMP41;
      __BITS8       TRTCMP41_bit;
    };
  };
} @ 0xF0460;

__near __no_init volatile union
{
  unsigned char TRTCR4;
  __BITS8       TRTCR4_bit;
  struct
  {
    unsigned char  TSTART40:1;
    unsigned char  :1;
    unsigned char  TSTART41:1;
    unsigned char  :5;
  };
} @ 0xF0462;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD4;
  __BITS8       TRTMD4_bit;
} @ 0xF0463;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP5;
  __BITS16       TRTCMP5_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP50;
      __BITS8       TRTCMP50_bit;
    };
    union
    {
      unsigned char TRTCMP51;
      __BITS8       TRTCMP51_bit;
    };
  };
} @ 0xF0468;

__near __no_init volatile union
{
  unsigned char TRTCR5;
  __BITS8       TRTCR5_bit;
  struct
  {
    unsigned char  TSTART50:1;
    unsigned char  :1;
    unsigned char  TSTART51:1;
    unsigned char  :5;
  };
} @ 0xF046A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD5;
  __BITS8       TRTMD5_bit;
} @ 0xF046B;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP6;
  __BITS16       TRTCMP6_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP60;
      __BITS8       TRTCMP60_bit;
    };
    union
    {
      unsigned char TRTCMP61;
      __BITS8       TRTCMP61_bit;
    };
  };
} @ 0xF0470;

__near __no_init volatile union
{
  unsigned char TRTCR6;
  __BITS8       TRTCR6_bit;
  struct
  {
    unsigned char  TSTART60:1;
    unsigned char  :1;
    unsigned char  TSTART61:1;
    unsigned char  :5;
  };
} @ 0xF0472;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD6;
  __BITS8       TRTMD6_bit;
} @ 0xF0473;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRTCMP7;
  __BITS16       TRTCMP7_bit;
  struct
  {
    union
    {
      unsigned char TRTCMP70;
      __BITS8       TRTCMP70_bit;
    };
    union
    {
      unsigned char TRTCMP71;
      __BITS8       TRTCMP71_bit;
    };
  };
} @ 0xF0478;

__near __no_init volatile union
{
  unsigned char TRTCR7;
  __BITS8       TRTCR7_bit;
  struct
  {
    unsigned char  TSTART70:1;
    unsigned char  :1;
    unsigned char  TSTART71:1;
    unsigned char  :5;
  };
} @ 0xF047A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRTMD7;
  __BITS8       TRTMD7_bit;
} @ 0xF047B;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSIVC0;
  __BITS16       FLSIVC0_bit;
} @ 0xF0480;

__near __no_bit_access __no_init volatile union
{
  unsigned short FLSIVC1;
  __BITS16       FLSIVC1_bit;
} @ 0xF0482;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH0;
  __BITS16       GFLASH0_bit;
} @ 0xF0488;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH1;
  __BITS16       GFLASH1_bit;
} @ 0xF048A;

__near __no_bit_access __no_init volatile union
{
  unsigned short GFLASH2;
  __BITS16       GFLASH2_bit;
} @ 0xF048C;

__near __no_bit_access __no_init volatile union
{
  unsigned short GIAWCTL;
  __BITS16       GIAWCTL_bit;
} @ 0xF048E;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCTL0;
  __BITS8       TKBTCTL0_bit;
} @ 0xF0490;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCMP0;
  __BITS8       TKBTCMP0_bit;
} @ 0xF0491;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCTL1;
  __BITS8       TKBTCTL1_bit;
} @ 0xF0492;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCMP1;
  __BITS8       TKBTCMP1_bit;
} @ 0xF0493;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCTL2;
  __BITS8       TKBTCTL2_bit;
} @ 0xF0494;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBTCMP2;
  __BITS8       TKBTCMP2_bit;
} @ 0xF0495;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR20;
  __BITS16       TKBCR20_bit;
} @ 0xF04A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR21;
  __BITS16       TKBCR21_bit;
} @ 0xF04A2;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR22;
  __BITS16       TKBCR22_bit;
} @ 0xF04A4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR23;
  __BITS16       TKBCR23_bit;
} @ 0xF04A6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBTGCR2;
  __BITS16       TKBTGCR2_bit;
} @ 0xF04A8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR20;
  __BITS16       TKBSIR20_bit;
} @ 0xF04AA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR21;
  __BITS16       TKBSIR21_bit;
} @ 0xF04AC;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR20;
  __BITS8       TKBDNR20_bit;
} @ 0xF04AE;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR20;
  __BITS8       TKBSSR20_bit;
} @ 0xF04AF;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR21;
  __BITS8       TKBDNR21_bit;
} @ 0xF04B0;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR21;
  __BITS8       TKBSSR21_bit;
} @ 0xF04B1;

__near __no_init volatile union
{
  unsigned char TKBTRG2;
  __BITS8       TKBTRG2_bit;
  struct
  {
    unsigned char  TKBRDT2:1;
    unsigned char  :7;
  };
} @ 0xF04B2;

__near __no_init volatile union
{
  const unsigned char TKBFLG2;
  const __BITS8       TKBFLG2_bit;
  struct
  {
    const unsigned char  TKBRSF2:1;
    const unsigned char  TKBMFF2:1;
    const unsigned char  TKBIEF2:1;
    const unsigned char  TKBIRF2:1;
    const unsigned char  TKBSEF20:1;
    const unsigned char  TKBSEF21:1;
    const unsigned char  TKBSSF20:1;
    const unsigned char  TKBSSF21:1;
  };
} @ 0xF04B3;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD20;
  __BITS16       TKBCRLD20_bit;
} @ 0xF04B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD21;
  __BITS16       TKBCRLD21_bit;
} @ 0xF04B6;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBCNT2;
  const __BITS16       TKBCNT2_bit;
} @ 0xF04C0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL20;
  __BITS16       TKBCTL20_bit;
} @ 0xF04C2;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBMFR2;
  __BITS16       TKBMFR2_bit;
} @ 0xF04C4;

__near __no_init volatile union
{
  unsigned char TKBIOC20;
  __BITS8       TKBIOC20_bit;
  struct
  {
    unsigned char  TKBTOD20:1;
    unsigned char  TKBTOD21:1;
    unsigned char  TKBTOL20:1;
    unsigned char  TKBTOL21:1;
    unsigned char  :4;
  };
} @ 0xF04C6;

__near __no_init volatile union
{
  unsigned char TKBCLR2;
  __BITS8       TKBCLR2_bit;
  struct
  {
    unsigned char  :1;
    unsigned char  TKBCLMF2:1;
    unsigned char  TKBCLIE2:1;
    unsigned char  TKBCLIR2:1;
    unsigned char  TKBCLSE20:1;
    unsigned char  TKBCLSE21:1;
    unsigned char  :2;
  };
} @ 0xF04C7;

__near __no_init volatile union
{
  unsigned char TKBIOC21;
  __BITS8       TKBIOC21_bit;
  struct
  {
    unsigned char  TKBTOE20:1;
    unsigned char  TKBTOE21:1;
    unsigned char  :6;
  };
} @ 0xF04C8;

__near __no_init volatile union
{
  unsigned char TKBCTL21;
  __BITS8       TKBCTL21_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  TKBCE2:1;
  };
} @ 0xF04C9;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL22;
  __BITS16       TKBCTL22_bit;
} @ 0xF04CA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL20;
  __BITS16       TKBPACTL20_bit;
} @ 0xF04D0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL21;
  __BITS16       TKBPACTL21_bit;
} @ 0xF04D2;

__near __no_init volatile union
{
  unsigned char TKBPAHFS2;
  __BITS8       TKBPAHFS2_bit;
  struct
  {
    unsigned char  TKBPAHTS20:1;
    unsigned char  TKBPAHTS21:1;
    unsigned char  :6;
  };
} @ 0xF04D4;

__near __no_init volatile union
{
  unsigned char TKBPAHFT2;
  __BITS8       TKBPAHFT2_bit;
  struct
  {
    unsigned char  TKBPAHTT20:1;
    unsigned char  TKBPAHTT21:1;
    unsigned char  :6;
  };
} @ 0xF04D5;

__near __no_init volatile union
{
  const unsigned char TKBPAFLG2;
  const __BITS8       TKBPAFLG2_bit;
  struct
  {
    const unsigned char  TKBPAHIF20:1;
    const unsigned char  TKBPAFIF20:1;
    const unsigned char  TKBPAHIF21:1;
    const unsigned char  TKBPAFIF21:1;
    const unsigned char  TKBPAHSF20:1;
    const unsigned char  TKBPAFSF20:1;
    const unsigned char  TKBPAHSF21:1;
    const unsigned char  TKBPAFSF21:1;
  };
} @ 0xF04D6;

__near __no_init volatile union
{
  unsigned char TKBPACTL22;
  __BITS8       TKBPACTL22_bit;
  struct
  {
    unsigned char  TKBPACE20:1;
    unsigned char  TKBPACE21:1;
    unsigned char  :6;
  };
} @ 0xF04D7;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS20;
  __BITS16       TKBPAHZS20_bit;
} @ 0xF04D8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS21;
  __BITS16       TKBPAHZS21_bit;
} @ 0xF04DA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS20;
  __BITS16       TKBPAFXS20_bit;
} @ 0xF04DC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS21;
  __BITS16       TKBPAFXS21_bit;
} @ 0xF04DE;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR0;
  __BITS8       PIOR0_bit;
} @ 0xF04E0;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR1;
  __BITS8       PIOR1_bit;
} @ 0xF04E1;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR2;
  __BITS8       PIOR2_bit;
} @ 0xF04E2;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR3;
  __BITS8       PIOR3_bit;
} @ 0xF04E3;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR4;
  __BITS8       PIOR4_bit;
} @ 0xF04E4;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR5;
  __BITS8       PIOR5_bit;
} @ 0xF04E5;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR6;
  __BITS8       PIOR6_bit;
} @ 0xF04E6;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR7;
  __BITS8       PIOR7_bit;
} @ 0xF04E7;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR8;
  __BITS8       PIOR8_bit;
} @ 0xF04E8;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR9;
  __BITS8       PIOR9_bit;
} @ 0xF04E9;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR10;
  __BITS8       PIOR10_bit;
} @ 0xF04EA;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR11;
  __BITS8       PIOR11_bit;
} @ 0xF04EB;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR12;
  __BITS8       PIOR12_bit;
} @ 0xF04EC;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR13;
  __BITS8       PIOR13_bit;
} @ 0xF04ED;

__near __no_init volatile union
{
  unsigned short CTSUCRAL;
  __BITS16       CTSUCRAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCR0;
      __BITS8       CTSUCR0_bit;
    };
    union
    {
      unsigned char CTSUCR1;
      __BITS8       CTSUCR1_bit;
    };
  };
} @ 0xF0500;

__near __no_init volatile union
{
  unsigned short CTSUCRAH;
  __BITS16       CTSUCRAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCR2;
      __BITS8       CTSUCR2_bit;
    };
    union
    {
      unsigned char CTSUCR3;
      __BITS8       CTSUCR3_bit;
    };
  };
} @ 0xF0502;

__near __no_init volatile union
{
  unsigned short CTSUCRBL;
  __BITS16       CTSUCRBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUSDPRS;
      __BITS8       CTSUSDPRS_bit;
    };
    union
    {
      unsigned char CTSUSST;
      __BITS8       CTSUSST_bit;
    };
  };
} @ 0xF0504;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUCRBH;
  __BITS16       CTSUCRBH_bit;
  struct
  {
    unsigned char :8;
    union
    {
      unsigned char CTSUDCLKC;
      __BITS8       CTSUDCLKC_bit;
    };
  };
} @ 0xF0506;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUMCHL;
  __BITS16       CTSUMCHL_bit;
  struct
  {
    union
    {
      unsigned char CTSUMCH0;
      __BITS8       CTSUMCH0_bit;
    };
    union
    {
      unsigned char CTSUMCH1;
      __BITS8       CTSUMCH1_bit;
    };
  };
} @ 0xF0508;

__near __no_init volatile union
{
  unsigned short CTSUMCHH;
  __BITS16       CTSUMCHH_bit;
  struct
  {
    union
    {
      unsigned char CTSUMFAF;
      __BITS8       CTSUMFAF_bit;
    };
    unsigned char :8;
  };
} @ 0xF050A;

__near __no_init volatile union
{
  unsigned short CTSUCHACAL;
  __BITS16       CTSUCHACAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC0;
      __BITS8       CTSUCHAC0_bit;
    };
    union
    {
      unsigned char CTSUCHAC1;
      __BITS8       CTSUCHAC1_bit;
    };
  };
} @ 0xF050C;

__near __no_init volatile union
{
  unsigned short CTSUCHACAH;
  __BITS16       CTSUCHACAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC2;
      __BITS8       CTSUCHAC2_bit;
    };
    union
    {
      unsigned char CTSUCHAC3;
      __BITS8       CTSUCHAC3_bit;
    };
  };
} @ 0xF050E;

__near __no_init volatile union
{
  unsigned short CTSUCHACBL;
  __BITS16       CTSUCHACBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHAC4;
      __BITS8       CTSUCHAC4_bit;
    };
    union
    {
      const unsigned char CTSUCHAC5;
      const __BITS8       CTSUCHAC5_bit;
    };
  };
} @ 0xF0510;

__near __no_init volatile union
{
  unsigned short CTSUCHTRCAL;
  __BITS16       CTSUCHTRCAL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC0;
      __BITS8       CTSUCHTRC0_bit;
    };
    union
    {
      unsigned char CTSUCHTRC1;
      __BITS8       CTSUCHTRC1_bit;
    };
  };
} @ 0xF0514;

__near __no_init volatile union
{
  unsigned short CTSUCHTRCAH;
  __BITS16       CTSUCHTRCAH_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC2;
      __BITS8       CTSUCHTRC2_bit;
    };
    union
    {
      unsigned char CTSUCHTRC3;
      __BITS8       CTSUCHTRC3_bit;
    };
  };
} @ 0xF0516;

__near __no_init volatile union
{
  unsigned short CTSUCHTRCBL;
  __BITS16       CTSUCHTRCBL_bit;
  struct
  {
    union
    {
      unsigned char CTSUCHTRC4;
      __BITS8       CTSUCHTRC4_bit;
    };
    union
    {
      const unsigned char CTSUCHTRC5;
      const __BITS8       CTSUCHTRC5_bit;
    };
  };
} @ 0xF0518;

__near __no_init volatile union
{
  unsigned short CTSUSRL;
  __BITS16       CTSUSRL_bit;
  struct
  {
    union
    {
      unsigned char CTSUST1;
      __BITS8       CTSUST1_bit;
    };
    union
    {
      unsigned char CTSUST;
      __BITS8       CTSUST_bit;
    };
  };
} @ 0xF051C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSO0;
  __BITS16       CTSUSO0_bit;
} @ 0xF0520;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSO1;
  __BITS16       CTSUSO1_bit;
} @ 0xF0522;

__near __no_bit_access __no_init volatile union
{
  const unsigned short CTSUSC;
  const __BITS16       CTSUSC_bit;
} @ 0xF0524;

__near __no_bit_access __no_init volatile union
{
  const unsigned short CTSUUC;
  const __BITS16       CTSUUC_bit;
} @ 0xF0526;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUDBGR0;
  __BITS16       CTSUDBGR0_bit;
} @ 0xF0528;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUDBGR1;
  __BITS16       CTSUDBGR1_bit;
} @ 0xF052A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK0;
  __BITS16       CTSUSUCLK0_bit;
} @ 0xF052C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK1;
  __BITS16       CTSUSUCLK1_bit;
} @ 0xF052E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK2;
  __BITS16       CTSUSUCLK2_bit;
} @ 0xF0530;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUSUCLK3;
  __BITS16       CTSUSUCLK3_bit;
} @ 0xF0532;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TRNGSDR;
  const __BITS8       TRNGSDR_bit;
} @ 0xF0540;

__near __no_init volatile union
{
  unsigned char TRNGSCR0;
  __BITS8       TRNGSCR0_bit;
  struct
  {
    unsigned char  :2;
    unsigned char  TRNGST:1;
    unsigned char  TRNGEN:1;
    unsigned char  :3;
    unsigned char  TRNGRDY:1;
  };
} @ 0xF0542;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT0;
  const __BITS16       TRT0_bit;
  struct
  {
    union
    {
      const unsigned char TRT00;
      const __BITS8       TRT00_bit;
    };
    union
    {
      const unsigned char TRT01;
      const __BITS8       TRT01_bit;
    };
  };
} @ 0xF0550;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT1;
  const __BITS16       TRT1_bit;
  struct
  {
    union
    {
      const unsigned char TRT10;
      const __BITS8       TRT10_bit;
    };
    union
    {
      const unsigned char TRT11;
      const __BITS8       TRT11_bit;
    };
  };
} @ 0xF0558;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT2;
  const __BITS16       TRT2_bit;
  struct
  {
    union
    {
      const unsigned char TRT20;
      const __BITS8       TRT20_bit;
    };
    union
    {
      const unsigned char TRT21;
      const __BITS8       TRT21_bit;
    };
  };
} @ 0xF0560;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT3;
  const __BITS16       TRT3_bit;
  struct
  {
    union
    {
      const unsigned char TRT30;
      const __BITS8       TRT30_bit;
    };
    union
    {
      const unsigned char TRT31;
      const __BITS8       TRT31_bit;
    };
  };
} @ 0xF0568;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT4;
  const __BITS16       TRT4_bit;
  struct
  {
    union
    {
      const unsigned char TRT40;
      const __BITS8       TRT40_bit;
    };
    union
    {
      const unsigned char TRT41;
      const __BITS8       TRT41_bit;
    };
  };
} @ 0xF0570;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT5;
  const __BITS16       TRT5_bit;
  struct
  {
    union
    {
      const unsigned char TRT50;
      const __BITS8       TRT50_bit;
    };
    union
    {
      const unsigned char TRT51;
      const __BITS8       TRT51_bit;
    };
  };
} @ 0xF0578;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT6;
  const __BITS16       TRT6_bit;
  struct
  {
    union
    {
      const unsigned char TRT60;
      const __BITS8       TRT60_bit;
    };
    union
    {
      const unsigned char TRT61;
      const __BITS8       TRT61_bit;
    };
  };
} @ 0xF0580;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRT7;
  const __BITS16       TRT7_bit;
  struct
  {
    union
    {
      const unsigned char TRT70;
      const __BITS8       TRT70_bit;
    };
    union
    {
      const unsigned char TRT71;
      const __BITS8       TRT71_bit;
    };
  };
} @ 0xF0588;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRJ0;
  __BITS16       TRJ0_bit;
} @ 0xF0598;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRJ1;
  __BITS16       TRJ1_bit;
} @ 0xF059A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM0;
  __BITS16       CTSUTRIM0_bit;
  struct
  {
    union
    {
      unsigned char RTRIM;
      __BITS8       RTRIM_bit;
    };
    union
    {
      unsigned char DACTRIM;
      __BITS8       DACTRIM_bit;
    };
  };
} @ 0xF0600;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM1;
  __BITS16       CTSUTRIM1_bit;
  struct
  {
    union
    {
      unsigned char SUADJD;
      __BITS8       SUADJD_bit;
    };
    union
    {
      unsigned char TRESULT4;
      __BITS8       TRESULT4_bit;
    };
  };
} @ 0xF0602;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM2;
  __BITS16       CTSUTRIM2_bit;
  struct
  {
    union
    {
      unsigned char TRESULT0;
      __BITS8       TRESULT0_bit;
    };
    union
    {
      unsigned char TRESULT1;
      __BITS8       TRESULT1_bit;
    };
  };
} @ 0xF0604;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTSUTRIM3;
  __BITS16       CTSUTRIM3_bit;
  struct
  {
    union
    {
      unsigned char TRESULT2;
      __BITS8       TRESULT2_bit;
    };
    union
    {
      unsigned char TRESULT3;
      __BITS8       TRESULT3_bit;
    };
  };
} @ 0xF0606;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA1;
  __BITS8       TXBA1_bit;
} @ 0xF0610;

__near __no_bit_access __no_init volatile union
{
  const unsigned char RXBA1;
  const __BITS8       RXBA1_bit;
} @ 0xF0611;

__near __no_init volatile union
{
  unsigned char ASIMA10;
  __BITS8       ASIMA10_bit;
  struct
  {
    unsigned char  ISRMA1:1;
    unsigned char  ISSMA1:1;
    unsigned char  :3;
    unsigned char  RXEA1:1;
    unsigned char  TXEA1:1;
    unsigned char  UARTAEN1:1;
  };
} @ 0xF0612;

__near __no_init volatile union
{
  unsigned char ASIMA11;
  __BITS8       ASIMA11_bit;
} @ 0xF0613;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA1;
  __BITS8       BRGCA1_bit;
} @ 0xF0614;

__near __no_bit_access __no_init volatile union
{
  const unsigned char ASISA1;
  const __BITS8       ASISA1_bit;
} @ 0xF0615;

__near __no_init volatile union
{
  unsigned char ASCTA1;
  __BITS8       ASCTA1_bit;
  struct
  {
    unsigned char  OVECTA1:1;
    unsigned char  FECTA1:1;
    unsigned char  PECTA1:1;
    unsigned char  :5;
  };
} @ 0xF0616;

__near __no_init volatile union
{
  unsigned char UTA1CK;
  __BITS8       UTA1CK_bit;
} @ 0xF0620;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA2;
  __BITS8       TXBA2_bit;
} @ 0xF0630;

__near __no_bit_access __no_init volatile union
{
  const unsigned char RXBA2;
  const __BITS8       RXBA2_bit;
} @ 0xF0631;

__near __no_init volatile union
{
  unsigned char ASIMA20;
  __BITS8       ASIMA20_bit;
  struct
  {
    unsigned char  ISRMA2:1;
    unsigned char  ISSMA2:1;
    unsigned char  :3;
    unsigned char  RXEA2:1;
    unsigned char  TXEA2:1;
    unsigned char  UARTAEN2:1;
  };
} @ 0xF0632;

__near __no_init volatile union
{
  unsigned char ASIMA21;
  __BITS8       ASIMA21_bit;
} @ 0xF0633;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA2;
  __BITS8       BRGCA2_bit;
} @ 0xF0634;

__near __no_bit_access __no_init volatile union
{
  unsigned char ASISA2;
  __BITS8       ASISA2_bit;
} @ 0xF0635;

__near __no_init volatile union
{
  unsigned char ASCTA2;
  __BITS8       ASCTA2_bit;
  struct
  {
    unsigned char  OVECTA2:1;
    unsigned char  FECTA2:1;
    unsigned char  PECTA2:1;
    unsigned char  :5;
  };
} @ 0xF0636;

__near __no_init volatile union
{
  unsigned char UTA2CK;
  __BITS8       UTA2CK_bit;
} @ 0xF0640;

__near __no_bit_access __no_init volatile union
{
  unsigned char TXBA3;
  __BITS8       TXBA3_bit;
} @ 0xF0650;

__near __no_bit_access __no_init volatile union
{
  const unsigned char RXBA3;
  const __BITS8       RXBA3_bit;
} @ 0xF0651;

__near __no_init volatile union
{
  unsigned char ASIMA30;
  __BITS8       ASIMA30_bit;
  struct
  {
    unsigned char  ISRMA3:1;
    unsigned char  ISSMA3:1;
    unsigned char  :3;
    unsigned char  RXEA3:1;
    unsigned char  TXEA3:1;
    unsigned char  UARTAEN3:1;
  };
} @ 0xF0652;

__near __no_init volatile union
{
  unsigned char ASIMA31;
  __BITS8       ASIMA31_bit;
} @ 0xF0653;

__near __no_bit_access __no_init volatile union
{
  unsigned char BRGCA3;
  __BITS8       BRGCA3_bit;
} @ 0xF0654;

__near __no_bit_access __no_init volatile union
{
  unsigned char ASISA3;
  __BITS8       ASISA3_bit;
} @ 0xF0655;

__near __no_init volatile union
{
  unsigned char ASCTA3;
  __BITS8       ASCTA3_bit;
  struct
  {
    unsigned char  OVECTA3:1;
    unsigned char  FECTA3:1;
    unsigned char  PECTA3:1;
    unsigned char  :5;
  };
} @ 0xF0656;

__near __no_init volatile union
{
  unsigned char UTA3CK;
  __BITS8       UTA3CK_bit;
} @ 0xF0660;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL0;
  __BITS8       ELISEL0_bit;
} @ 0xF0680;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL1;
  __BITS8       ELISEL1_bit;
} @ 0xF0681;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL2;
  __BITS8       ELISEL2_bit;
} @ 0xF0682;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL3;
  __BITS8       ELISEL3_bit;
} @ 0xF0683;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL4;
  __BITS8       ELISEL4_bit;
} @ 0xF0684;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL5;
  __BITS8       ELISEL5_bit;
} @ 0xF0685;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL6;
  __BITS8       ELISEL6_bit;
} @ 0xF0686;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL7;
  __BITS8       ELISEL7_bit;
} @ 0xF0687;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL8;
  __BITS8       ELISEL8_bit;
} @ 0xF0688;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL9;
  __BITS8       ELISEL9_bit;
} @ 0xF0689;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL10;
  __BITS8       ELISEL10_bit;
} @ 0xF068A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELISEL11;
  __BITS8       ELISEL11_bit;
} @ 0xF068B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL0;
  __BITS8       ELL1SEL0_bit;
} @ 0xF0690;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL1;
  __BITS8       ELL1SEL1_bit;
} @ 0xF0691;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL2;
  __BITS8       ELL1SEL2_bit;
} @ 0xF0692;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL3;
  __BITS8       ELL1SEL3_bit;
} @ 0xF0693;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL4;
  __BITS8       ELL1SEL4_bit;
} @ 0xF0694;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL5;
  __BITS8       ELL1SEL5_bit;
} @ 0xF0695;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1SEL6;
  __BITS8       ELL1SEL6_bit;
} @ 0xF0696;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1CTL;
  __BITS8       ELL1CTL_bit;
} @ 0xF0697;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK0;
  __BITS8       ELL1LNK0_bit;
} @ 0xF0698;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK1;
  __BITS8       ELL1LNK1_bit;
} @ 0xF0699;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK2;
  __BITS8       ELL1LNK2_bit;
} @ 0xF069A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK3;
  __BITS8       ELL1LNK3_bit;
} @ 0xF069B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK4;
  __BITS8       ELL1LNK4_bit;
} @ 0xF069C;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK5;
  __BITS8       ELL1LNK5_bit;
} @ 0xF069D;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL1LNK6;
  __BITS8       ELL1LNK6_bit;
} @ 0xF069E;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL0;
  __BITS8       ELL2SEL0_bit;
} @ 0xF06A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL1;
  __BITS8       ELL2SEL1_bit;
} @ 0xF06A1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL2;
  __BITS8       ELL2SEL2_bit;
} @ 0xF06A2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL3;
  __BITS8       ELL2SEL3_bit;
} @ 0xF06A3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL4;
  __BITS8       ELL2SEL4_bit;
} @ 0xF06A4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL5;
  __BITS8       ELL2SEL5_bit;
} @ 0xF06A5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2SEL6;
  __BITS8       ELL2SEL6_bit;
} @ 0xF06A6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2CTL;
  __BITS8       ELL2CTL_bit;
} @ 0xF06A7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK0;
  __BITS8       ELL2LNK0_bit;
} @ 0xF06A8;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK1;
  __BITS8       ELL2LNK1_bit;
} @ 0xF06A9;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK2;
  __BITS8       ELL2LNK2_bit;
} @ 0xF06AA;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK3;
  __BITS8       ELL2LNK3_bit;
} @ 0xF06AB;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK4;
  __BITS8       ELL2LNK4_bit;
} @ 0xF06AC;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK5;
  __BITS8       ELL2LNK5_bit;
} @ 0xF06AD;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL2LNK6;
  __BITS8       ELL2LNK6_bit;
} @ 0xF06AE;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL0;
  __BITS8       ELL3SEL0_bit;
} @ 0xF06B0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL1;
  __BITS8       ELL3SEL1_bit;
} @ 0xF06B1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL2;
  __BITS8       ELL3SEL2_bit;
} @ 0xF06B2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL3;
  __BITS8       ELL3SEL3_bit;
} @ 0xF06B3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL4;
  __BITS8       ELL3SEL4_bit;
} @ 0xF06B4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL5;
  __BITS8       ELL3SEL5_bit;
} @ 0xF06B5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3SEL6;
  __BITS8       ELL3SEL6_bit;
} @ 0xF06B6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3CTL;
  __BITS8       ELL3CTL_bit;
} @ 0xF06B7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK0;
  __BITS8       ELL3LNK0_bit;
} @ 0xF06B8;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK1;
  __BITS8       ELL3LNK1_bit;
} @ 0xF06B9;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK2;
  __BITS8       ELL3LNK2_bit;
} @ 0xF06BA;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK3;
  __BITS8       ELL3LNK3_bit;
} @ 0xF06BB;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK4;
  __BITS8       ELL3LNK4_bit;
} @ 0xF06BC;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK5;
  __BITS8       ELL3LNK5_bit;
} @ 0xF06BD;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELL3LNK6;
  __BITS8       ELL3LNK6_bit;
} @ 0xF06BE;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL0;
  __BITS8       ELOSEL0_bit;
} @ 0xF06C0;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL1;
  __BITS8       ELOSEL1_bit;
} @ 0xF06C1;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL2;
  __BITS8       ELOSEL2_bit;
} @ 0xF06C2;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL3;
  __BITS8       ELOSEL3_bit;
} @ 0xF06C3;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL4;
  __BITS8       ELOSEL4_bit;
} @ 0xF06C4;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL5;
  __BITS8       ELOSEL5_bit;
} @ 0xF06C5;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL6;
  __BITS8       ELOSEL6_bit;
} @ 0xF06C6;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOSEL7;
  __BITS8       ELOSEL7_bit;
} @ 0xF06C7;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELOENCTL;
  __BITS8       ELOENCTL_bit;
} @ 0xF06C8;

__near __no_bit_access __no_init volatile union
{
  const unsigned char ELOMONI;
  const __BITS8       ELOMONI_bit;
} @ 0xF06C9;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR00;
  __BITS16       TKBCR00_bit;
} @ 0xF0740;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR01;
  __BITS16       TKBCR01_bit;
} @ 0xF0742;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR02;
  __BITS16       TKBCR02_bit;
} @ 0xF0744;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR03;
  __BITS16       TKBCR03_bit;
} @ 0xF0746;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBTGCR0;
  __BITS16       TKBTGCR0_bit;
} @ 0xF0748;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR00;
  __BITS16       TKBSIR00_bit;
} @ 0xF074A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR01;
  __BITS16       TKBSIR01_bit;
} @ 0xF074C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR00;
  __BITS8       TKBDNR00_bit;
} @ 0xF074E;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR00;
  __BITS8       TKBSSR00_bit;
} @ 0xF074F;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR01;
  __BITS8       TKBDNR01_bit;
} @ 0xF0750;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR01;
  __BITS8       TKBSSR01_bit;
} @ 0xF0751;

__near __no_init volatile union
{
  unsigned char TKBTRG0;
  __BITS8       TKBTRG0_bit;
  struct
  {
    unsigned char  TKBRDT0:1;
    unsigned char  :7;
  };
} @ 0xF0752;

__near __no_init volatile union
{
  const unsigned char TKBFLG0;
  const __BITS8       TKBFLG0_bit;
  struct
  {
    const unsigned char  TKBRSF0:1;
    const unsigned char  TKBMFF0:1;
    const unsigned char  TKBIEF0:1;
    const unsigned char  TKBIRF0:1;
    const unsigned char  TKBSEF00:1;
    const unsigned char  TKBSEF01:1;
    const unsigned char  TKBSSF00:1;
    const unsigned char  TKBSSF01:1;
  };
} @ 0xF0753;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD00;
  __BITS16       TKBCRLD00_bit;
} @ 0xF0754;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD01;
  __BITS16       TKBCRLD01_bit;
} @ 0xF0756;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBCNT0;
  const __BITS16       TKBCNT0_bit;
} @ 0xF0760;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL00;
  __BITS16       TKBCTL00_bit;
} @ 0xF0762;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBMFR0;
  __BITS16       TKBMFR0_bit;
} @ 0xF0764;

__near __no_init volatile union
{
  unsigned char TKBIOC00;
  __BITS8       TKBIOC00_bit;
  struct
  {
    unsigned char  TKBTOD00:1;
    unsigned char  TKBTOD01:1;
    unsigned char  TKBTOL00:1;
    unsigned char  TKBTOL01:1;
    unsigned char  :4;
  };
} @ 0xF0766;

__near __no_init volatile union
{
  unsigned char TKBCLR0;
  __BITS8       TKBCLR0_bit;
  struct
  {
    unsigned char  :1;
    unsigned char  TKBCLMF0:1;
    unsigned char  TKBCLIE0:1;
    unsigned char  TKBCLIR0:1;
    unsigned char  TKBCLSE00:1;
    unsigned char  TKBCLSE01:1;
    unsigned char  :2;
  };
} @ 0xF0767;

__near __no_init volatile union
{
  unsigned char TKBIOC01;
  __BITS8       TKBIOC01_bit;
  struct
  {
    unsigned char  TKBTOE00:1;
    unsigned char  TKBTOE01:1;
    unsigned char  :6;
  };
} @ 0xF0768;

__near __no_init volatile union
{
  unsigned char TKBCTL01;
  __BITS8       TKBCTL01_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  TKBCE0:1;
  };
} @ 0xF0769;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL02;
  __BITS16       TKBCTL02_bit;
} @ 0xF076A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL00;
  __BITS16       TKBPACTL00_bit;
} @ 0xF0770;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL01;
  __BITS16       TKBPACTL01_bit;
} @ 0xF0772;

__near __no_init volatile union
{
  unsigned char TKBPAHFS0;
  __BITS8       TKBPAHFS0_bit;
  struct
  {
    unsigned char  TKBPAHTS00:1;
    unsigned char  TKBPAHTS01:1;
    unsigned char  :6;
  };
} @ 0xF0774;

__near __no_init volatile union
{
  unsigned char TKBPAHFT0;
  __BITS8       TKBPAHFT0_bit;
  struct
  {
    unsigned char  TKBPAHTT00:1;
    unsigned char  TKBPAHTT01:1;
    unsigned char  :6;
  };
} @ 0xF0775;

__near __no_init volatile union
{
  const unsigned char TKBPAFLG0;
  const __BITS8       TKBPAFLG0_bit;
  struct
  {
    const unsigned char  TKBPAHIF00:1;
    const unsigned char  TKBPAFIF00:1;
    const unsigned char  TKBPAHIF01:1;
    const unsigned char  TKBPAFIF01:1;
    const unsigned char  TKBPAHSF00:1;
    const unsigned char  TKBPAFSF00:1;
    const unsigned char  TKBPAHSF01:1;
    const unsigned char  TKBPAFSF01:1;
  };
} @ 0xF0776;

__near __no_init volatile union
{
  unsigned char TKBPACTL02;
  __BITS8       TKBPACTL02_bit;
  struct
  {
    unsigned char  TKBPACE00:1;
    unsigned char  TKBPACE01:1;
    unsigned char  :6;
  };
} @ 0xF0777;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS00;
  __BITS16       TKBPAHZS00_bit;
} @ 0xF0778;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS01;
  __BITS16       TKBPAHZS01_bit;
} @ 0xF077A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS00;
  __BITS16       TKBPAFXS00_bit;
} @ 0xF077C;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS01;
  __BITS16       TKBPAFXS01_bit;
} @ 0xF077E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR10;
  __BITS16       TKBCR10_bit;
} @ 0xF0780;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR11;
  __BITS16       TKBCR11_bit;
} @ 0xF0782;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR12;
  __BITS16       TKBCR12_bit;
} @ 0xF0784;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR13;
  __BITS16       TKBCR13_bit;
} @ 0xF0786;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBTGCR1;
  __BITS16       TKBTGCR1_bit;
} @ 0xF0788;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR10;
  __BITS16       TKBSIR10_bit;
} @ 0xF078A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR11;
  __BITS16       TKBSIR11_bit;
} @ 0xF078C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR10;
  __BITS8       TKBDNR10_bit;
} @ 0xF078E;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR10;
  __BITS8       TKBSSR10_bit;
} @ 0xF078F;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR11;
  __BITS8       TKBDNR11_bit;
} @ 0xF0790;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR11;
  __BITS8       TKBSSR11_bit;
} @ 0xF0791;

__near __no_init volatile union
{
  unsigned char TKBTRG1;
  __BITS8       TKBTRG1_bit;
  struct
  {
    unsigned char  TKBRDT1:1;
    unsigned char  :7;
  };
} @ 0xF0792;

__near __no_init volatile union
{
  const unsigned char TKBFLG1;
  const __BITS8       TKBFLG1_bit;
  struct
  {
    const unsigned char  TKBRSF1:1;
    const unsigned char  TKBMFF1:1;
    const unsigned char  TKBIEF1:1;
    const unsigned char  TKBIRF1:1;
    const unsigned char  TKBSEF10:1;
    const unsigned char  TKBSEF11:1;
    const unsigned char  TKBSSF10:1;
    const unsigned char  TKBSSF11:1;
  };
} @ 0xF0793;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD10;
  __BITS16       TKBCRLD10_bit;
} @ 0xF0794;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD11;
  __BITS16       TKBCRLD11_bit;
} @ 0xF0796;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBCNT1;
  const __BITS16       TKBCNT1_bit;
} @ 0xF07A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL10;
  __BITS16       TKBCTL10_bit;
} @ 0xF07A2;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBMFR1;
  __BITS16       TKBMFR1_bit;
} @ 0xF07A4;

__near __no_init volatile union
{
  unsigned char TKBIOC10;
  __BITS8       TKBIOC10_bit;
  struct
  {
    unsigned char  TKBTOD10:1;
    unsigned char  TKBTOD11:1;
    unsigned char  TKBTOL10:1;
    unsigned char  TKBTOL11:1;
    unsigned char  :4;
  };
} @ 0xF07A6;

__near __no_init volatile union
{
  unsigned char TKBCLR1;
  __BITS8       TKBCLR1_bit;
  struct
  {
    unsigned char  :1;
    unsigned char  TKBCLMF1:1;
    unsigned char  TKBCLIE1:1;
    unsigned char  TKBCLIR1:1;
    unsigned char  TKBCLSE10:1;
    unsigned char  TKBCLSE11:1;
    unsigned char  :2;
  };
} @ 0xF07A7;

__near __no_init volatile union
{
  unsigned char TKBIOC11;
  __BITS8       TKBIOC11_bit;
  struct
  {
    unsigned char  TKBTOE10:1;
    unsigned char  TKBTOE11:1;
    unsigned char  :6;
  };
} @ 0xF07A8;

__near __no_init volatile union
{
  unsigned char TKBCTL11;
  __BITS8       TKBCTL11_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  TKBCE1:1;
  };
} @ 0xF07A9;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL12;
  __BITS16       TKBCTL12_bit;
} @ 0xF07AA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL10;
  __BITS16       TKBPACTL10_bit;
} @ 0xF07B0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL11;
  __BITS16       TKBPACTL11_bit;
} @ 0xF07B2;

__near __no_init volatile union
{
  unsigned char TKBPAHFS1;
  __BITS8       TKBPAHFS1_bit;
  struct
  {
    unsigned char  TKBPAHTS10:1;
    unsigned char  TKBPAHTS11:1;
    unsigned char  :6;
  };
} @ 0xF07B4;

__near __no_init volatile union
{
  unsigned char TKBPAHFT1;
  __BITS8       TKBPAHFT1_bit;
  struct
  {
    unsigned char  TKBPAHTT10:1;
    unsigned char  TKBPAHTT11:1;
    unsigned char  :6;
  };
} @ 0xF07B5;

__near __no_init volatile union
{
  const unsigned char TKBPAFLG1;
  const __BITS8       TKBPAFLG1_bit;
  struct
  {
    const unsigned char  TKBPAHIF10:1;
    const unsigned char  TKBPAFIF10:1;
    const unsigned char  TKBPAHIF11:1;
    const unsigned char  TKBPAFIF11:1;
    const unsigned char  TKBPAHSF10:1;
    const unsigned char  TKBPAFSF10:1;
    const unsigned char  TKBPAHSF11:1;
    const unsigned char  TKBPAFSF11:1;
  };
} @ 0xF07B6;

__near __no_init volatile union
{
  unsigned char TKBPACTL12;
  __BITS8       TKBPACTL12_bit;
  struct
  {
    unsigned char  TKBPACE10:1;
    unsigned char  TKBPACE11:1;
    unsigned char  :6;
  };
} @ 0xF07B7;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS10;
  __BITS16       TKBPAHZS10_bit;
} @ 0xF07B8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAHZS11;
  __BITS16       TKBPAHZS11_bit;
} @ 0xF07BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS10;
  __BITS16       TKBPAFXS10_bit;
} @ 0xF07BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPAFXS11;
  __BITS16       TKBPAFXS11_bit;
} @ 0xF07BE;


#pragma language=restore

#endif /* __IAR_SYSTEMS_ICC__ */

#ifdef __IAR_SYSTEMS_ASM__

/*----------------------------------------------
 *       Extended SFR declarations
 *--------------------------------------------*/

ADM2       DEFINE  0xF0010
ADUL       DEFINE  0xF0011
ADLL       DEFINE  0xF0012
ADTES      DEFINE  0xF0013
ADCR0      DEFINE  0xF0020
ADCR0H     DEFINE  0xF0021
PU0        DEFINE  0xF0030
PU1        DEFINE  0xF0031
PU2        DEFINE  0xF0032
PU3        DEFINE  0xF0033
PU4        DEFINE  0xF0034
PU5        DEFINE  0xF0035
PU6        DEFINE  0xF0036
PU7        DEFINE  0xF0037
PU8        DEFINE  0xF0038
PU9        DEFINE  0xF0039
PU12       DEFINE  0xF003C
PU14       DEFINE  0xF003E
PIM0       DEFINE  0xF0040
PIM1       DEFINE  0xF0041
PIM2       DEFINE  0xF0042
PIM3       DEFINE  0xF0043
PIM4       DEFINE  0xF0044
PIM5       DEFINE  0xF0045
PIM6       DEFINE  0xF0046
PIM7       DEFINE  0xF0047
PIM8       DEFINE  0xF0048
PIM9       DEFINE  0xF0049
PIM12      DEFINE  0xF004C
PIM14      DEFINE  0xF004E
POM0       DEFINE  0xF0050
POM1       DEFINE  0xF0051
POM2       DEFINE  0xF0052
POM3       DEFINE  0xF0053
POM4       DEFINE  0xF0054
POM5       DEFINE  0xF0055
POM6       DEFINE  0xF0056
POM7       DEFINE  0xF0057
POM8       DEFINE  0xF0058
POM9       DEFINE  0xF0059
POM12      DEFINE  0xF005C
POM13      DEFINE  0xF005D
POM14      DEFINE  0xF005E
PMCA1      DEFINE  0xF0061
PMCA2      DEFINE  0xF0062
PMCA4      DEFINE  0xF0064
NFEN0      DEFINE  0xF0070
NFEN1      DEFINE  0xF0071
ISC        DEFINE  0xF0073
TIS0       DEFINE  0xF0074
TIS1       DEFINE  0xF0075
IAWCTL     DEFINE  0xF0078
ULBS       DEFINE  0xF0079
TOS        DEFINE  0xF007A
PMS        DEFINE  0xF007B
DFLCTL     DEFINE  0xF0090
MODRV      DEFINE  0xF009E
HIOTRM     DEFINE  0xF00A0
HOCODIV    DEFINE  0xF00A8
FLMODE     DEFINE  0xF00AA
FLMWRP     DEFINE  0xF00AB
FLSEC      DEFINE  0xF00B0
FLFSWS     DEFINE  0xF00B2
FLFSWE     DEFINE  0xF00B4
FSSET      DEFINE  0xF00B6
FSSE       DEFINE  0xF00B7
PFCMD      DEFINE  0xF00C0
PFS        DEFINE  0xF00C1
PER0       DEFINE  0xF00F0
PRR0       DEFINE  0xF00F1
MOCODIV    DEFINE  0xF00F2
OSMC       DEFINE  0xF00F3
RPECTL     DEFINE  0xF00F5
PORSR      DEFINE  0xF00F9
PER1       DEFINE  0xF00FA
PRR1       DEFINE  0xF00FB
PER2       DEFINE  0xF00FC
PRR2       DEFINE  0xF00FD
BCDADJ     DEFINE  0xF00FE
VECTCTRL   DEFINE  0xF00FF
SSR00      DEFINE  0xF0100
SSR00L     DEFINE  0xF0100
SSR01      DEFINE  0xF0102
SSR01L     DEFINE  0xF0102
SSR02      DEFINE  0xF0104
SSR02L     DEFINE  0xF0104
SSR03      DEFINE  0xF0106
SSR03L     DEFINE  0xF0106
SIR00      DEFINE  0xF0108
SIR00L     DEFINE  0xF0108
SIR01      DEFINE  0xF010A
SIR01L     DEFINE  0xF010A
SIR02      DEFINE  0xF010C
SIR02L     DEFINE  0xF010C
SIR03      DEFINE  0xF010E
SIR03L     DEFINE  0xF010E
SMR00      DEFINE  0xF0110
SMR01      DEFINE  0xF0112
SMR02      DEFINE  0xF0114
SMR03      DEFINE  0xF0116
SCR00      DEFINE  0xF0118
SCR01      DEFINE  0xF011A
SCR02      DEFINE  0xF011C
SCR03      DEFINE  0xF011E
SE0        DEFINE  0xF0120
SE0L       DEFINE  0xF0120
SS0        DEFINE  0xF0122
SS0L       DEFINE  0xF0122
ST0        DEFINE  0xF0124
ST0L       DEFINE  0xF0124
SPS0       DEFINE  0xF0126
SPS0L      DEFINE  0xF0126
SO0        DEFINE  0xF0128
SOE0       DEFINE  0xF012A
SOE0L      DEFINE  0xF012A
SOL0       DEFINE  0xF0134
SOL0L      DEFINE  0xF0134
SSC0       DEFINE  0xF0138
SSC0L      DEFINE  0xF0138
SSR10      DEFINE  0xF0140
SSR10L     DEFINE  0xF0140
SSR11      DEFINE  0xF0142
SSR11L     DEFINE  0xF0142
SSR12      DEFINE  0xF0144
SSR12L     DEFINE  0xF0144
SSR13      DEFINE  0xF0146
SSR13L     DEFINE  0xF0146
SIR10      DEFINE  0xF0148
SIR10L     DEFINE  0xF0148
SIR11      DEFINE  0xF014A
SIR11L     DEFINE  0xF014A
SIR12      DEFINE  0xF014C
SIR12L     DEFINE  0xF014C
SIR13      DEFINE  0xF014E
SIR13L     DEFINE  0xF014E
SMR10      DEFINE  0xF0150
SMR11      DEFINE  0xF0152
SMR12      DEFINE  0xF0154
SMR13      DEFINE  0xF0156
SCR10      DEFINE  0xF0158
SCR11      DEFINE  0xF015A
SCR12      DEFINE  0xF015C
SCR13      DEFINE  0xF015E
SE1        DEFINE  0xF0160
SE1L       DEFINE  0xF0160
SS1        DEFINE  0xF0162
SS1L       DEFINE  0xF0162
ST1        DEFINE  0xF0164
ST1L       DEFINE  0xF0164
SPS1       DEFINE  0xF0166
SPS1L      DEFINE  0xF0166
SO1        DEFINE  0xF0168
SOE1       DEFINE  0xF016A
SOE1L      DEFINE  0xF016A
SOL1       DEFINE  0xF0174
SOL1L      DEFINE  0xF0174
SSC1       DEFINE  0xF0178
SSC1L      DEFINE  0xF0178
TCR00      DEFINE  0xF0180
TCR01      DEFINE  0xF0182
TCR02      DEFINE  0xF0184
TCR03      DEFINE  0xF0186
TCR04      DEFINE  0xF0188
TCR05      DEFINE  0xF018A
TCR06      DEFINE  0xF018C
TCR07      DEFINE  0xF018E
TMR00      DEFINE  0xF0190
TMR01      DEFINE  0xF0192
TMR02      DEFINE  0xF0194
TMR03      DEFINE  0xF0196
TMR04      DEFINE  0xF0198
TMR05      DEFINE  0xF019A
TMR06      DEFINE  0xF019C
TMR07      DEFINE  0xF019E
TSR00      DEFINE  0xF01A0
TSR00L     DEFINE  0xF01A0
TSR01      DEFINE  0xF01A2
TSR01L     DEFINE  0xF01A2
TSR02      DEFINE  0xF01A4
TSR02L     DEFINE  0xF01A4
TSR03      DEFINE  0xF01A6
TSR03L     DEFINE  0xF01A6
TSR04      DEFINE  0xF01A8
TSR04L     DEFINE  0xF01A8
TSR05      DEFINE  0xF01AA
TSR05L     DEFINE  0xF01AA
TSR06      DEFINE  0xF01AC
TSR06L     DEFINE  0xF01AC
TSR07      DEFINE  0xF01AE
TSR07L     DEFINE  0xF01AE
TE0        DEFINE  0xF01B0
TE0L       DEFINE  0xF01B0
TS0        DEFINE  0xF01B2
TS0L       DEFINE  0xF01B2
TT0        DEFINE  0xF01B4
TT0L       DEFINE  0xF01B4
TPS0       DEFINE  0xF01B6
TO0        DEFINE  0xF01B8
TO0L       DEFINE  0xF01B8
TOE0       DEFINE  0xF01BA
TOE0L      DEFINE  0xF01BA
TOL0       DEFINE  0xF01BC
TOL0L      DEFINE  0xF01BC
TOM0       DEFINE  0xF01BE
TOM0L      DEFINE  0xF01BE
MIOTRM     DEFINE  0xF0212
LIOTRM     DEFINE  0xF0213
MOSCDIV    DEFINE  0xF0214
WKUPMD     DEFINE  0xF0215
PSMCR      DEFINE  0xF0216
SOMRG      DEFINE  0xF0217
LVDFCLR    DEFINE  0xF0218
SEC        DEFINE  0xF0220
MIN        DEFINE  0xF0221
HOUR       DEFINE  0xF0222
WEEK       DEFINE  0xF0223
DAY        DEFINE  0xF0224
MONTH      DEFINE  0xF0225
YEAR       DEFINE  0xF0226
SUBCUD     DEFINE  0xF0227
ALARMWM    DEFINE  0xF0228
ALARMWH    DEFINE  0xF0229
ALARMWW    DEFINE  0xF022A
RTCC0      DEFINE  0xF022B
RTCC1      DEFINE  0xF022C
IICCTL00   DEFINE  0xF0230
IICCTL01   DEFINE  0xF0231
IICWL0     DEFINE  0xF0232
IICWH0     DEFINE  0xF0233
SVA0       DEFINE  0xF0234
IICCTL10   DEFINE  0xF0238
IICCTL11   DEFINE  0xF0239
IICWL1     DEFINE  0xF023A
IICWH1     DEFINE  0xF023B
SVA1       DEFINE  0xF023C
TRJCR0     DEFINE  0xF0240
TRJIOC0    DEFINE  0xF0241
TRJMR0     DEFINE  0xF0242
TRJISR0    DEFINE  0xF0243
TRJCR1     DEFINE  0xF0244
TRJIOC1    DEFINE  0xF0245
TRJMR1     DEFINE  0xF0246
TRJISR1    DEFINE  0xF0247
EXSDM1     DEFINE  0xF025A
EXSDM0     DEFINE  0xF025B
PMCT0      DEFINE  0xF0260
PMCT3      DEFINE  0xF0263
PMCT5      DEFINE  0xF0265
PMCT7      DEFINE  0xF0267
PMCT9      DEFINE  0xF0269
PMCT12     DEFINE  0xF026C
PMCE0      DEFINE  0xF0280
PMCE1      DEFINE  0xF0281
PMCE6      DEFINE  0xF0286
PMCE7      DEFINE  0xF0287
PFSEG0     DEFINE  0xF0290
PFSEG1     DEFINE  0xF0291
PFSEG2     DEFINE  0xF0292
PFSEG3     DEFINE  0xF0293
PFSEG4     DEFINE  0xF0294
PFSEG5     DEFINE  0xF0295
PFSEG6     DEFINE  0xF0296
PFSEG7     DEFINE  0xF0297
ISCLCD     DEFINE  0xF0298
LCDM2      DEFINE  0xF0299
ADM1EX     DEFINE  0xF029E
CCS0       DEFINE  0xF02A0
CCS4       DEFINE  0xF02A4
CCS5       DEFINE  0xF02A5
CCS6       DEFINE  0xF02A6
CCS7       DEFINE  0xF02A7
CCDE       DEFINE  0xF02A8
PTDC       DEFINE  0xF02A9
PFOE0      DEFINE  0xF02AA
PFOE1      DEFINE  0xF02AB
PDIDIS0    DEFINE  0xF02B0
PDIDIS1    DEFINE  0xF02B1
PDIDIS2    DEFINE  0xF02B2
PDIDIS3    DEFINE  0xF02B3
PDIDIS4    DEFINE  0xF02B4
PDIDIS5    DEFINE  0xF02B5
PDIDIS6    DEFINE  0xF02B6
PDIDIS7    DEFINE  0xF02B7
PDIDIS8    DEFINE  0xF02B8
PDIDIS9    DEFINE  0xF02B9
PDIDIS12   DEFINE  0xF02BC
PDIDIS13   DEFINE  0xF02BD
PDIDIS14   DEFINE  0xF02BE
FLPMC      DEFINE  0xF02C0
FLARS      DEFINE  0xF02C1
FLAPL      DEFINE  0xF02C2
FLAPH      DEFINE  0xF02C4
FSSQ       DEFINE  0xF02C5
FLSEDL     DEFINE  0xF02C6
FLSEDH     DEFINE  0xF02C8
FLRST      DEFINE  0xF02C9
FSASTL     DEFINE  0xF02CA
FSASTH     DEFINE  0xF02CB
FLWL       DEFINE  0xF02CC
FLWH       DEFINE  0xF02CE
OSDC       DEFINE  0xF02D0
CLKDCTL    DEFINE  0xF02D4
DTCBAR     DEFINE  0xF02E0
DTCEN0     DEFINE  0xF02E8
DTCEN1     DEFINE  0xF02E9
DTCEN2     DEFINE  0xF02EA
DTCEN3     DEFINE  0xF02EB
DTCEN4     DEFINE  0xF02EC
DTCEN5     DEFINE  0xF02ED
DTCEN6     DEFINE  0xF02EE
CRC0CTL    DEFINE  0xF02F0
PGCRCL     DEFINE  0xF02F2
CRCD       DEFINE  0xF02FA
TXBA0      DEFINE  0xF0300
RXBA0      DEFINE  0xF0301
ASIMA00    DEFINE  0xF0302
ASIMA01    DEFINE  0xF0303
BRGCA0     DEFINE  0xF0304
ASISA0     DEFINE  0xF0305
ASCTA0     DEFINE  0xF0306
UTA0CK     DEFINE  0xF0310
TMC5MG     DEFINE  0xF0320
TCL5MG     DEFINE  0xF0321
CR5MGL     DEFINE  0xF0322
CR5MGH     DEFINE  0xF0323
DACS0      DEFINE  0xF0330
DACS1      DEFINE  0xF0331
DAM0       DEFINE  0xF0332
DACS2      DEFINE  0xF0338
DAM1       DEFINE  0xF033A
COMPMDR    DEFINE  0xF0340
COMPFIR    DEFINE  0xF0341
COMPOCR    DEFINE  0xF0342
TM3L       DEFINE  0xF0350
TM3H       DEFINE  0xF0351
TMC3       DEFINE  0xF0352
ITLCMP00   DEFINE  0xF0360
ITLCMP000  DEFINE  0xF0360
ITLCMP001  DEFINE  0xF0361
ITLCMP01   DEFINE  0xF0362
ITLCMP012  DEFINE  0xF0362
ITLCMP013  DEFINE  0xF0363
ITLCAP00   DEFINE  0xF0364
ITLCTL0    DEFINE  0xF0366
ITLCSEL0   DEFINE  0xF0367
ITLFDIV00  DEFINE  0xF0368
ITLFDIV01  DEFINE  0xF0369
ITLCC0     DEFINE  0xF036A
ITLS0      DEFINE  0xF036B
ITLMKF0    DEFINE  0xF036C
INTPCTL0   DEFINE  0xF0370
INTPCTL1   DEFINE  0xF0371
INTPCTL2   DEFINE  0xF0372
INTPCTL3   DEFINE  0xF0373
INTPCTL4   DEFINE  0xF0374
INTPCTL5   DEFINE  0xF0375
INTPCTL6   DEFINE  0xF0376
INTPCTL7   DEFINE  0xF0377
TPS2       DEFINE  0xF037F
SMSI0      DEFINE  0xF0380
SMSI1      DEFINE  0xF0382
SMSI2      DEFINE  0xF0384
SMSI3      DEFINE  0xF0386
SMSI4      DEFINE  0xF0388
SMSI5      DEFINE  0xF038A
SMSI6      DEFINE  0xF038C
SMSI7      DEFINE  0xF038E
SMSI8      DEFINE  0xF0390
SMSI9      DEFINE  0xF0392
SMSI10     DEFINE  0xF0394
SMSI11     DEFINE  0xF0396
SMSI12     DEFINE  0xF0398
SMSI13     DEFINE  0xF039A
SMSI14     DEFINE  0xF039C
SMSI15     DEFINE  0xF039E
SMSI16     DEFINE  0xF03A0
SMSI17     DEFINE  0xF03A2
SMSI18     DEFINE  0xF03A4
SMSI19     DEFINE  0xF03A6
SMSI20     DEFINE  0xF03A8
SMSI21     DEFINE  0xF03AA
SMSI22     DEFINE  0xF03AC
SMSI23     DEFINE  0xF03AE
SMSI24     DEFINE  0xF03B0
SMSI25     DEFINE  0xF03B2
SMSI26     DEFINE  0xF03B4
SMSI27     DEFINE  0xF03B6
SMSI28     DEFINE  0xF03B8
SMSI29     DEFINE  0xF03BA
SMSI30     DEFINE  0xF03BC
SMSI31     DEFINE  0xF03BE
SMSG0      DEFINE  0xF03C0
SMSG1      DEFINE  0xF03C2
SMSG2      DEFINE  0xF03C4
SMSG3      DEFINE  0xF03C6
SMSG4      DEFINE  0xF03C8
SMSG5      DEFINE  0xF03CA
SMSG6      DEFINE  0xF03CC
SMSG7      DEFINE  0xF03CE
SMSG8      DEFINE  0xF03D0
SMSG9      DEFINE  0xF03D2
SMSG10     DEFINE  0xF03D4
SMSG11     DEFINE  0xF03D6
SMSG12     DEFINE  0xF03D8
SMSG13     DEFINE  0xF03DA
SMSG14     DEFINE  0xF03DC
SMSG15     DEFINE  0xF03DE
SMSC       DEFINE  0xF03E0
SMSS       DEFINE  0xF03E1
SEG0       DEFINE  0xF0400
SEG1       DEFINE  0xF0401
SEG2       DEFINE  0xF0402
SEG3       DEFINE  0xF0403
SEG4       DEFINE  0xF0404
SEG5       DEFINE  0xF0405
SEG6       DEFINE  0xF0406
SEG7       DEFINE  0xF0407
SEG8       DEFINE  0xF0408
SEG9       DEFINE  0xF0409
SEG10      DEFINE  0xF040A
SEG11      DEFINE  0xF040B
SEG12      DEFINE  0xF040C
SEG13      DEFINE  0xF040D
SEG14      DEFINE  0xF040E
SEG15      DEFINE  0xF040F
SEG16      DEFINE  0xF0410
SEG17      DEFINE  0xF0411
SEG18      DEFINE  0xF0412
SEG19      DEFINE  0xF0413
SEG20      DEFINE  0xF0414
SEG21      DEFINE  0xF0415
SEG22      DEFINE  0xF0416
SEG23      DEFINE  0xF0417
SEG24      DEFINE  0xF0418
SEG25      DEFINE  0xF0419
SEG26      DEFINE  0xF041A
SEG27      DEFINE  0xF041B
SEG28      DEFINE  0xF041C
SEG29      DEFINE  0xF041D
SEG30      DEFINE  0xF041E
SEG31      DEFINE  0xF041F
SEG32      DEFINE  0xF0420
SEG33      DEFINE  0xF0421
SEG34      DEFINE  0xF0422
SEG35      DEFINE  0xF0423
SEG36      DEFINE  0xF0424
SEG37      DEFINE  0xF0425
SEG38      DEFINE  0xF0426
SEG39      DEFINE  0xF0427
SEG40      DEFINE  0xF0428
SEG41      DEFINE  0xF0429
SEG42      DEFINE  0xF042A
SEG43      DEFINE  0xF042B
SEG44      DEFINE  0xF042C
SEG45      DEFINE  0xF042D
SEG46      DEFINE  0xF042E
SEG47      DEFINE  0xF042F
SEG48      DEFINE  0xF0430
SEG49      DEFINE  0xF0431
SEG50      DEFINE  0xF0432
SEG51      DEFINE  0xF0433
SEG52      DEFINE  0xF0434
SEG53      DEFINE  0xF0435
SEG54      DEFINE  0xF0436
SEG55      DEFINE  0xF0437
TRTCMP0    DEFINE  0xF0440
TRTCMP00   DEFINE  0xF0440
TRTCMP01   DEFINE  0xF0441
TRTCR0     DEFINE  0xF0442
TRTMD0     DEFINE  0xF0443
TRTCMP1    DEFINE  0xF0448
TRTCMP10   DEFINE  0xF0448
TRTCMP11   DEFINE  0xF0449
TRTCR1     DEFINE  0xF044A
TRTMD1     DEFINE  0xF044B
TRTCMP2    DEFINE  0xF0450
TRTCMP20   DEFINE  0xF0450
TRTCMP21   DEFINE  0xF0451
TRTCR2     DEFINE  0xF0452
TRTMD2     DEFINE  0xF0453
TRTCMP3    DEFINE  0xF0458
TRTCMP30   DEFINE  0xF0458
TRTCMP31   DEFINE  0xF0459
TRTCR3     DEFINE  0xF045A
TRTMD3     DEFINE  0xF045B
TRTCMP4    DEFINE  0xF0460
TRTCMP40   DEFINE  0xF0460
TRTCMP41   DEFINE  0xF0461
TRTCR4     DEFINE  0xF0462
TRTMD4     DEFINE  0xF0463
TRTCMP5    DEFINE  0xF0468
TRTCMP50   DEFINE  0xF0468
TRTCMP51   DEFINE  0xF0469
TRTCR5     DEFINE  0xF046A
TRTMD5     DEFINE  0xF046B
TRTCMP6    DEFINE  0xF0470
TRTCMP60   DEFINE  0xF0470
TRTCMP61   DEFINE  0xF0471
TRTCR6     DEFINE  0xF0472
TRTMD6     DEFINE  0xF0473
TRTCMP7    DEFINE  0xF0478
TRTCMP70   DEFINE  0xF0478
TRTCMP71   DEFINE  0xF0479
TRTCR7     DEFINE  0xF047A
TRTMD7     DEFINE  0xF047B
FLSIVC0    DEFINE  0xF0480
FLSIVC1    DEFINE  0xF0482
GFLASH0    DEFINE  0xF0488
GFLASH1    DEFINE  0xF048A
GFLASH2    DEFINE  0xF048C
GIAWCTL    DEFINE  0xF048E
TKBTCTL0   DEFINE  0xF0490
TKBTCMP0   DEFINE  0xF0491
TKBTCTL1   DEFINE  0xF0492
TKBTCMP1   DEFINE  0xF0493
TKBTCTL2   DEFINE  0xF0494
TKBTCMP2   DEFINE  0xF0495
TKBCR20    DEFINE  0xF04A0
TKBCR21    DEFINE  0xF04A2
TKBCR22    DEFINE  0xF04A4
TKBCR23    DEFINE  0xF04A6
TKBTGCR2   DEFINE  0xF04A8
TKBSIR20   DEFINE  0xF04AA
TKBSIR21   DEFINE  0xF04AC
TKBDNR20   DEFINE  0xF04AE
TKBSSR20   DEFINE  0xF04AF
TKBDNR21   DEFINE  0xF04B0
TKBSSR21   DEFINE  0xF04B1
TKBTRG2    DEFINE  0xF04B2
TKBFLG2    DEFINE  0xF04B3
TKBCRLD20  DEFINE  0xF04B4
TKBCRLD21  DEFINE  0xF04B6
TKBCNT2    DEFINE  0xF04C0
TKBCTL20   DEFINE  0xF04C2
TKBMFR2    DEFINE  0xF04C4
TKBIOC20   DEFINE  0xF04C6
TKBCLR2    DEFINE  0xF04C7
TKBIOC21   DEFINE  0xF04C8
TKBCTL21   DEFINE  0xF04C9
TKBCTL22   DEFINE  0xF04CA
TKBPACTL20 DEFINE  0xF04D0
TKBPACTL21 DEFINE  0xF04D2
TKBPAHFS2  DEFINE  0xF04D4
TKBPAHFT2  DEFINE  0xF04D5
TKBPAFLG2  DEFINE  0xF04D6
TKBPACTL22 DEFINE  0xF04D7
TKBPAHZS20 DEFINE  0xF04D8
TKBPAHZS21 DEFINE  0xF04DA
TKBPAFXS20 DEFINE  0xF04DC
TKBPAFXS21 DEFINE  0xF04DE
PIOR0      DEFINE  0xF04E0
PIOR1      DEFINE  0xF04E1
PIOR2      DEFINE  0xF04E2
PIOR3      DEFINE  0xF04E3
PIOR4      DEFINE  0xF04E4
PIOR5      DEFINE  0xF04E5
PIOR6      DEFINE  0xF04E6
PIOR7      DEFINE  0xF04E7
PIOR8      DEFINE  0xF04E8
PIOR9      DEFINE  0xF04E9
PIOR10     DEFINE  0xF04EA
PIOR11     DEFINE  0xF04EB
PIOR12     DEFINE  0xF04EC
PIOR13     DEFINE  0xF04ED
CTSUCRAL   DEFINE  0xF0500
CTSUCR0    DEFINE  0xF0500
CTSUCR1    DEFINE  0xF0501
CTSUCRAH   DEFINE  0xF0502
CTSUCR2    DEFINE  0xF0502
CTSUCR3    DEFINE  0xF0503
CTSUCRBL   DEFINE  0xF0504
CTSUSDPRS  DEFINE  0xF0504
CTSUSST    DEFINE  0xF0505
CTSUCRBH   DEFINE  0xF0506
CTSUDCLKC  DEFINE  0xF0507
CTSUMCHL   DEFINE  0xF0508
CTSUMCH0   DEFINE  0xF0508
CTSUMCH1   DEFINE  0xF0509
CTSUMCHH   DEFINE  0xF050A
CTSUMFAF   DEFINE  0xF050A
CTSUCHACAL DEFINE  0xF050C
CTSUCHAC0  DEFINE  0xF050C
CTSUCHAC1  DEFINE  0xF050D
CTSUCHACAH DEFINE  0xF050E
CTSUCHAC2  DEFINE  0xF050E
CTSUCHAC3  DEFINE  0xF050F
CTSUCHACBL DEFINE  0xF0510
CTSUCHAC4  DEFINE  0xF0510
CTSUCHAC5  DEFINE  0xF0511
CTSUCHTRCAL DEFINE  0xF0514
CTSUCHTRC0 DEFINE  0xF0514
CTSUCHTRC1 DEFINE  0xF0515
CTSUCHTRCAH DEFINE  0xF0516
CTSUCHTRC2 DEFINE  0xF0516
CTSUCHTRC3 DEFINE  0xF0517
CTSUCHTRCBL DEFINE  0xF0518
CTSUCHTRC4 DEFINE  0xF0518
CTSUCHTRC5 DEFINE  0xF0519
CTSUSRL    DEFINE  0xF051C
CTSUST1    DEFINE  0xF051C
CTSUST     DEFINE  0xF051D
CTSUSO0    DEFINE  0xF0520
CTSUSO1    DEFINE  0xF0522
CTSUSC     DEFINE  0xF0524
CTSUUC     DEFINE  0xF0526
CTSUDBGR0  DEFINE  0xF0528
CTSUDBGR1  DEFINE  0xF052A
CTSUSUCLK0 DEFINE  0xF052C
CTSUSUCLK1 DEFINE  0xF052E
CTSUSUCLK2 DEFINE  0xF0530
CTSUSUCLK3 DEFINE  0xF0532
TRNGSDR    DEFINE  0xF0540
TRNGSCR0   DEFINE  0xF0542
TRT0       DEFINE  0xF0550
TRT00      DEFINE  0xF0550
TRT01      DEFINE  0xF0551
TRT1       DEFINE  0xF0558
TRT10      DEFINE  0xF0558
TRT11      DEFINE  0xF0559
TRT2       DEFINE  0xF0560
TRT20      DEFINE  0xF0560
TRT21      DEFINE  0xF0561
TRT3       DEFINE  0xF0568
TRT30      DEFINE  0xF0568
TRT31      DEFINE  0xF0569
TRT4       DEFINE  0xF0570
TRT40      DEFINE  0xF0570
TRT41      DEFINE  0xF0571
TRT5       DEFINE  0xF0578
TRT50      DEFINE  0xF0578
TRT51      DEFINE  0xF0579
TRT6       DEFINE  0xF0580
TRT60      DEFINE  0xF0580
TRT61      DEFINE  0xF0581
TRT7       DEFINE  0xF0588
TRT70      DEFINE  0xF0588
TRT71      DEFINE  0xF0589
TRJ0       DEFINE  0xF0598
TRJ1       DEFINE  0xF059A
CTSUTRIM0  DEFINE  0xF0600
RTRIM      DEFINE  0xF0600
DACTRIM    DEFINE  0xF0601
CTSUTRIM1  DEFINE  0xF0602
SUADJD     DEFINE  0xF0602
TRESULT4   DEFINE  0xF0603
CTSUTRIM2  DEFINE  0xF0604
TRESULT0   DEFINE  0xF0604
TRESULT1   DEFINE  0xF0605
CTSUTRIM3  DEFINE  0xF0606
TRESULT2   DEFINE  0xF0606
TRESULT3   DEFINE  0xF0607
TXBA1      DEFINE  0xF0610
RXBA1      DEFINE  0xF0611
ASIMA10    DEFINE  0xF0612
ASIMA11    DEFINE  0xF0613
BRGCA1     DEFINE  0xF0614
ASISA1     DEFINE  0xF0615
ASCTA1     DEFINE  0xF0616
UTA1CK     DEFINE  0xF0620
TXBA2      DEFINE  0xF0630
RXBA2      DEFINE  0xF0631
ASIMA20    DEFINE  0xF0632
ASIMA21    DEFINE  0xF0633
BRGCA2     DEFINE  0xF0634
ASISA2     DEFINE  0xF0635
ASCTA2     DEFINE  0xF0636
UTA2CK     DEFINE  0xF0640
TXBA3      DEFINE  0xF0650
RXBA3      DEFINE  0xF0651
ASIMA30    DEFINE  0xF0652
ASIMA31    DEFINE  0xF0653
BRGCA3     DEFINE  0xF0654
ASISA3     DEFINE  0xF0655
ASCTA3     DEFINE  0xF0656
UTA3CK     DEFINE  0xF0660
ELISEL0    DEFINE  0xF0680
ELISEL1    DEFINE  0xF0681
ELISEL2    DEFINE  0xF0682
ELISEL3    DEFINE  0xF0683
ELISEL4    DEFINE  0xF0684
ELISEL5    DEFINE  0xF0685
ELISEL6    DEFINE  0xF0686
ELISEL7    DEFINE  0xF0687
ELISEL8    DEFINE  0xF0688
ELISEL9    DEFINE  0xF0689
ELISEL10   DEFINE  0xF068A
ELISEL11   DEFINE  0xF068B
ELL1SEL0   DEFINE  0xF0690
ELL1SEL1   DEFINE  0xF0691
ELL1SEL2   DEFINE  0xF0692
ELL1SEL3   DEFINE  0xF0693
ELL1SEL4   DEFINE  0xF0694
ELL1SEL5   DEFINE  0xF0695
ELL1SEL6   DEFINE  0xF0696
ELL1CTL    DEFINE  0xF0697
ELL1LNK0   DEFINE  0xF0698
ELL1LNK1   DEFINE  0xF0699
ELL1LNK2   DEFINE  0xF069A
ELL1LNK3   DEFINE  0xF069B
ELL1LNK4   DEFINE  0xF069C
ELL1LNK5   DEFINE  0xF069D
ELL1LNK6   DEFINE  0xF069E
ELL2SEL0   DEFINE  0xF06A0
ELL2SEL1   DEFINE  0xF06A1
ELL2SEL2   DEFINE  0xF06A2
ELL2SEL3   DEFINE  0xF06A3
ELL2SEL4   DEFINE  0xF06A4
ELL2SEL5   DEFINE  0xF06A5
ELL2SEL6   DEFINE  0xF06A6
ELL2CTL    DEFINE  0xF06A7
ELL2LNK0   DEFINE  0xF06A8
ELL2LNK1   DEFINE  0xF06A9
ELL2LNK2   DEFINE  0xF06AA
ELL2LNK3   DEFINE  0xF06AB
ELL2LNK4   DEFINE  0xF06AC
ELL2LNK5   DEFINE  0xF06AD
ELL2LNK6   DEFINE  0xF06AE
ELL3SEL0   DEFINE  0xF06B0
ELL3SEL1   DEFINE  0xF06B1
ELL3SEL2   DEFINE  0xF06B2
ELL3SEL3   DEFINE  0xF06B3
ELL3SEL4   DEFINE  0xF06B4
ELL3SEL5   DEFINE  0xF06B5
ELL3SEL6   DEFINE  0xF06B6
ELL3CTL    DEFINE  0xF06B7
ELL3LNK0   DEFINE  0xF06B8
ELL3LNK1   DEFINE  0xF06B9
ELL3LNK2   DEFINE  0xF06BA
ELL3LNK3   DEFINE  0xF06BB
ELL3LNK4   DEFINE  0xF06BC
ELL3LNK5   DEFINE  0xF06BD
ELL3LNK6   DEFINE  0xF06BE
ELOSEL0    DEFINE  0xF06C0
ELOSEL1    DEFINE  0xF06C1
ELOSEL2    DEFINE  0xF06C2
ELOSEL3    DEFINE  0xF06C3
ELOSEL4    DEFINE  0xF06C4
ELOSEL5    DEFINE  0xF06C5
ELOSEL6    DEFINE  0xF06C6
ELOSEL7    DEFINE  0xF06C7
ELOENCTL   DEFINE  0xF06C8
ELOMONI    DEFINE  0xF06C9
TKBCR00    DEFINE  0xF0740
TKBCR01    DEFINE  0xF0742
TKBCR02    DEFINE  0xF0744
TKBCR03    DEFINE  0xF0746
TKBTGCR0   DEFINE  0xF0748
TKBSIR00   DEFINE  0xF074A
TKBSIR01   DEFINE  0xF074C
TKBDNR00   DEFINE  0xF074E
TKBSSR00   DEFINE  0xF074F
TKBDNR01   DEFINE  0xF0750
TKBSSR01   DEFINE  0xF0751
TKBTRG0    DEFINE  0xF0752
TKBFLG0    DEFINE  0xF0753
TKBCRLD00  DEFINE  0xF0754
TKBCRLD01  DEFINE  0xF0756
TKBCNT0    DEFINE  0xF0760
TKBCTL00   DEFINE  0xF0762
TKBMFR0    DEFINE  0xF0764
TKBIOC00   DEFINE  0xF0766
TKBCLR0    DEFINE  0xF0767
TKBIOC01   DEFINE  0xF0768
TKBCTL01   DEFINE  0xF0769
TKBCTL02   DEFINE  0xF076A
TKBPACTL00 DEFINE  0xF0770
TKBPACTL01 DEFINE  0xF0772
TKBPAHFS0  DEFINE  0xF0774
TKBPAHFT0  DEFINE  0xF0775
TKBPAFLG0  DEFINE  0xF0776
TKBPACTL02 DEFINE  0xF0777
TKBPAHZS00 DEFINE  0xF0778
TKBPAHZS01 DEFINE  0xF077A
TKBPAFXS00 DEFINE  0xF077C
TKBPAFXS01 DEFINE  0xF077E
TKBCR10    DEFINE  0xF0780
TKBCR11    DEFINE  0xF0782
TKBCR12    DEFINE  0xF0784
TKBCR13    DEFINE  0xF0786
TKBTGCR1   DEFINE  0xF0788
TKBSIR10   DEFINE  0xF078A
TKBSIR11   DEFINE  0xF078C
TKBDNR10   DEFINE  0xF078E
TKBSSR10   DEFINE  0xF078F
TKBDNR11   DEFINE  0xF0790
TKBSSR11   DEFINE  0xF0791
TKBTRG1    DEFINE  0xF0792
TKBFLG1    DEFINE  0xF0793
TKBCRLD10  DEFINE  0xF0794
TKBCRLD11  DEFINE  0xF0796
TKBCNT1    DEFINE  0xF07A0
TKBCTL10   DEFINE  0xF07A2
TKBMFR1    DEFINE  0xF07A4
TKBIOC10   DEFINE  0xF07A6
TKBCLR1    DEFINE  0xF07A7
TKBIOC11   DEFINE  0xF07A8
TKBCTL11   DEFINE  0xF07A9
TKBCTL12   DEFINE  0xF07AA
TKBPACTL10 DEFINE  0xF07B0
TKBPACTL11 DEFINE  0xF07B2
TKBPAHFS1  DEFINE  0xF07B4
TKBPAHFT1  DEFINE  0xF07B5
TKBPAFLG1  DEFINE  0xF07B6
TKBPACTL12 DEFINE  0xF07B7
TKBPAHZS10 DEFINE  0xF07B8
TKBPAHZS11 DEFINE  0xF07BA
TKBPAFXS10 DEFINE  0xF07BC
TKBPAFXS11 DEFINE  0xF07BE

#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* __IOR7F100L_EXT_H__ */

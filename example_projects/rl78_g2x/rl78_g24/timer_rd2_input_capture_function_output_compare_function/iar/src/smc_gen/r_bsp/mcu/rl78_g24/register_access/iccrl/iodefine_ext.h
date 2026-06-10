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
* Copyright (C) 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : iodefine_ext.h
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 29.07.2022 1.60     First Release

***********************************************************************************************************************/
/*-------------------------------------------------------------------------
 *      Declarations of extended SFR registers for RL78 microcontroller R7F101GLG.
 *
 *      This file can be used by both the RL78,
 *      Assembler, ARL78, and the C/C++ compiler, ICCRL78.
 *
 *      This header file is generated from the device file:
 *          DR7F101GLG.DVF
 *          Copyright(C) 2021 Renesas
 *          Format version V3.20, File version E1.00a
 *-------------------------------------------------------------------------*/

#ifndef __IOR7F101GLG_EXT_H__
#define __IOR7F101GLG_EXT_H__

#if !defined(__IASMRL78__) && !defined(__ICCRL78__)
  #error "IOR7F101GLG_EXT.H file for use with RL78 Assembler or Compiler only"
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
    #error "IOR7F101GLG_EXT.H file for use with IASMRL78 option --core S3 only"
  #endif
#endif
#if defined(__ICCRL78__)
  #if __CORE__ != __S3__
    #error "IOR7F101GLG_EXT.H file for use with ICCRL78 option --core S3 only"
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

__near __no_init volatile union
{
  unsigned char ADM3;
  __BITS8       ADM3_bit;
  struct
  {
    unsigned char  ADVMOD:1;
    unsigned char  :6;
    unsigned char  ADTRSWT:1;
  };
} @ 0xF0014;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADS0;
  __BITS8       ADS0_bit;
} @ 0xF0015;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADS1;
  __BITS8       ADS1_bit;
} @ 0xF0016;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADS2;
  __BITS8       ADS2_bit;
} @ 0xF0017;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADS3;
  __BITS8       ADS3_bit;
} @ 0xF0018;

__near __no_init volatile union
{
  unsigned char ADSCTL;
  __BITS8       ADSCTL_bit;
  struct
  {
    unsigned char  ADPRIOR0:1;
    unsigned char  ADPRIOR1:1;
    unsigned char  ADPRIOR2:1;
    unsigned char  ADPRIOR3:1;
    unsigned char  ADSEN0:1;
    unsigned char  ADSEN1:1;
    unsigned char  ADSEN2:1;
    unsigned char  ADSEN3:1;
  };
} @ 0xF0019;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTR0;
  __BITS8       ADTR0_bit;
} @ 0xF001A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTR1;
  __BITS8       ADTR1_bit;
} @ 0xF001B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTR2;
  __BITS8       ADTR2_bit;
} @ 0xF001C;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADTR3;
  __BITS8       ADTR3_bit;
} @ 0xF001D;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADPS;
  __BITS8       ADPS_bit;
} @ 0xF001E;

__near __no_bit_access __no_init volatile union
{
  unsigned char ADSPMOD;
  __BITS8       ADSPMOD_bit;
} @ 0xF001F;

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

__near __no_bit_access __no_init volatile union
{
  const unsigned short ADCR1;
  const __BITS16       ADCR1_bit;
  struct
  {
    unsigned char :8;
    union
    {
      const unsigned char ADCR1H;
      const __BITS8       ADCR1H_bit;
    };
  };
} @ 0xF0022;

__near __no_bit_access __no_init volatile union
{
  const unsigned short ADCR2;
  const __BITS16       ADCR2_bit;
  struct
  {
    unsigned char :8;
    union
    {
      const unsigned char ADCR2H;
      const __BITS8       ADCR2H_bit;
    };
  };
} @ 0xF0024;

__near __no_bit_access __no_init volatile union
{
  const unsigned short ADCR3;
  const __BITS16       ADCR3_bit;
  struct
  {
    unsigned char :8;
    union
    {
      const unsigned char ADCR3H;
      const __BITS8       ADCR3H_bit;
    };
  };
} @ 0xF0026;

__near __no_init volatile union
{
  unsigned char ADINTCTL;
  __BITS8       ADINTCTL_bit;
  struct
  {
    unsigned char  ADINTCTL0F:1;
    unsigned char  ADINTCTL0S:1;
    unsigned char  ADINTCTL1F:1;
    unsigned char  ADINTCTL1S:1;
    unsigned char  ADINTCTL2F:1;
    unsigned char  ADINTCTL2S:1;
    unsigned char  ADINTCTL3F:1;
    unsigned char  ADINTCTL3S:1;
  };
} @ 0xF0028;

__near __no_init volatile union
{
  unsigned char ADINTST;
  __BITS8       ADINTST_bit;
  struct
  {
    unsigned char  ADINTST0F:1;
    unsigned char  ADINTST0S:1;
    unsigned char  ADINTST1F:1;
    unsigned char  ADINTST1S:1;
    unsigned char  ADINTST2F:1;
    unsigned char  ADINTST2S:1;
    unsigned char  ADINTST3F:1;
    unsigned char  ADINTST3S:1;
  };
} @ 0xF0029;

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
  unsigned char PIM3;
  __BITS8       PIM3_bit;
} @ 0xF0043;

__near __no_init volatile union
{
  unsigned char PIM5;
  __BITS8       PIM5_bit;
} @ 0xF0045;

__near __no_init volatile union
{
  unsigned char PIM7;
  __BITS8       PIM7_bit;
} @ 0xF0047;

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
  unsigned char POM3;
  __BITS8       POM3_bit;
} @ 0xF0053;

__near __no_init volatile union
{
  unsigned char POM5;
  __BITS8       POM5_bit;
} @ 0xF0055;

__near __no_init volatile union
{
  unsigned char POM7;
  __BITS8       POM7_bit;
} @ 0xF0057;

__near __no_init volatile union
{
  unsigned char PMCA0;
  __BITS8       PMCA0_bit;
} @ 0xF0060;

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
  unsigned char PMCA12;
  __BITS8       PMCA12_bit;
} @ 0xF006C;

__near __no_init volatile union
{
  unsigned char PMCA14;
  __BITS8       PMCA14_bit;
} @ 0xF006E;

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
  unsigned char TIOS0;
  __BITS8       TIOS0_bit;
} @ 0xF0074;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR0;
  __BITS8       PIOR0_bit;
} @ 0xF0077;

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
    unsigned char  :5;
  };
} @ 0xF0079;

__near __no_bit_access __no_init volatile union
{
  unsigned char IICM;
  __BITS8       IICM_bit;
} @ 0xF007A;

__near __no_init volatile union
{
  unsigned char PMS;
  __BITS8       PMS_bit;
} @ 0xF007B;

__near __no_init volatile union
{
  unsigned char PFBER;
  __BITS8       PFBER_bit;
  struct
  {
    unsigned char  PFBE:1;
    unsigned char  :7;
  };
} @ 0xF007C;

__near __no_init volatile union
{
  unsigned char GDIDIS;
  __BITS8       GDIDIS_bit;
} @ 0xF007D;

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

__near __no_init volatile union
{
  unsigned char PCKC;
  __BITS8       PCKC_bit;
  struct
  {
    unsigned char  :1;
    unsigned char  PLLCK:1;
    unsigned char  :6;
  };
} @ 0xF0098;

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
    unsigned char  :6;
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
  unsigned char PFCMD /* write only */ ;
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
    unsigned char  :1;
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
    unsigned char  :2;
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
    unsigned char  DALIEN:1;
    unsigned char  :2;
    unsigned char  DTCEN:1;
    unsigned char  TML32EN:1;
    unsigned char  PGACMPEN:1;
    unsigned char  :1;
    unsigned char  DACEN:1;
  };
} @ 0xF00FA;

__near __no_init volatile union
{
  unsigned char PRR1;
  __BITS8       PRR1_bit;
  struct
  {
    unsigned char  DALIRES:1;
    unsigned char  :3;
    unsigned char  TML32RES:1;
    unsigned char  PGACMPRES:1;
    unsigned char  :1;
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
    unsigned char  TRXEN:1;
    unsigned char  PWMOPEN:1;
    unsigned char  TRD0EN:1;
    unsigned char  TRGEN:1;
    unsigned char  TKBEN:1;
    unsigned char  MEMEN:1;
    unsigned char  FAAEN:1;
  };
} @ 0xF00FC;

__near __no_init volatile union
{
  unsigned char PRR2;
  __BITS8       PRR2_bit;
  struct
  {
    unsigned char  TRJ0RES:1;
    unsigned char  TRXRES:1;
    unsigned char  PWMOPRES:1;
    unsigned char  TRD0RES:1;
    unsigned char  TRGRES:1;
    unsigned char  TKBRES:1;
    unsigned char  MEMRES:1;
    unsigned char  FAARES:1;
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
  unsigned short SCR10;
  __BITS16       SCR10_bit;
} @ 0xF0158;

__near __no_bit_access __no_init volatile union
{
  unsigned short SCR11;
  __BITS16       SCR11_bit;
} @ 0xF015A;

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

__near __no_init volatile union
{
  unsigned char HSCLKSEL;
  __BITS8       HSCLKSEL_bit;
  struct
  {
    unsigned char  FIHSEL:1;
    unsigned char  FIHST:1;
    unsigned char  :6;
  };
} @ 0xF0219;

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

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDPOE;
  __BITS8       TRDPOE_bit;
} @ 0xF02AC;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR1;
  __BITS8       PIOR1_bit;
} @ 0xF02AD;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR2;
  __BITS8       PIOR2_bit;
} @ 0xF02AE;

__near __no_bit_access __no_init volatile union
{
  unsigned char PIOR3;
  __BITS8       PIOR3_bit;
} @ 0xF02AF;

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
  unsigned char PDIDIS3;
  __BITS8       PDIDIS3_bit;
} @ 0xF02B3;

__near __no_init volatile union
{
  unsigned char PDIDIS5;
  __BITS8       PDIDIS5_bit;
} @ 0xF02B5;

__near __no_init volatile union
{
  unsigned char PDIDIS7;
  __BITS8       PDIDIS7_bit;
} @ 0xF02B7;

__near __no_init volatile union
{
  unsigned char PDIDIS13;
  __BITS8       PDIDIS13_bit;
} @ 0xF02BD;

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
  unsigned char DTCBAR;
  __BITS8       DTCBAR_bit;
} @ 0xF02E0;

__near __no_init volatile union
{
  unsigned char DSCCTL;
  __BITS8       DSCCTL_bit;
  struct
  {
    unsigned char  DSCON:1;
    unsigned char  :5;
    unsigned char  PLLDIV0:1;
    unsigned char  :1;
  };
} @ 0xF02E5;

__near __no_init volatile union
{
  unsigned char MCKC;
  __BITS8       MCKC_bit;
  struct
  {
    unsigned char  CKSELR:1;
    unsigned char  RDIV0:1;
    unsigned char  RDIV1:1;
    unsigned char  :4;
    unsigned char  CLSTR:1;
  };
} @ 0xF02E6;

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
  unsigned char ELSELR00;
  __BITS8       ELSELR00_bit;
} @ 0xF0300;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR01;
  __BITS8       ELSELR01_bit;
} @ 0xF0301;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR02;
  __BITS8       ELSELR02_bit;
} @ 0xF0302;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR03;
  __BITS8       ELSELR03_bit;
} @ 0xF0303;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR04;
  __BITS8       ELSELR04_bit;
} @ 0xF0304;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR05;
  __BITS8       ELSELR05_bit;
} @ 0xF0305;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR06;
  __BITS8       ELSELR06_bit;
} @ 0xF0306;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR07;
  __BITS8       ELSELR07_bit;
} @ 0xF0307;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR08;
  __BITS8       ELSELR08_bit;
} @ 0xF0308;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR09;
  __BITS8       ELSELR09_bit;
} @ 0xF0309;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR10;
  __BITS8       ELSELR10_bit;
} @ 0xF030A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR11;
  __BITS8       ELSELR11_bit;
} @ 0xF030B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR12;
  __BITS8       ELSELR12_bit;
} @ 0xF030C;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR13;
  __BITS8       ELSELR13_bit;
} @ 0xF030D;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR14;
  __BITS8       ELSELR14_bit;
} @ 0xF030E;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR15;
  __BITS8       ELSELR15_bit;
} @ 0xF030F;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR16;
  __BITS8       ELSELR16_bit;
} @ 0xF0310;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR17;
  __BITS8       ELSELR17_bit;
} @ 0xF0311;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR18;
  __BITS8       ELSELR18_bit;
} @ 0xF0312;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR19;
  __BITS8       ELSELR19_bit;
} @ 0xF0313;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR20;
  __BITS8       ELSELR20_bit;
} @ 0xF0314;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR21;
  __BITS8       ELSELR21_bit;
} @ 0xF0315;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR22;
  __BITS8       ELSELR22_bit;
} @ 0xF0316;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR23;
  __BITS8       ELSELR23_bit;
} @ 0xF0317;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR24;
  __BITS8       ELSELR24_bit;
} @ 0xF0318;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR25;
  __BITS8       ELSELR25_bit;
} @ 0xF0319;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR26;
  __BITS8       ELSELR26_bit;
} @ 0xF031A;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR27;
  __BITS8       ELSELR27_bit;
} @ 0xF031B;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR28;
  __BITS8       ELSELR28_bit;
} @ 0xF031C;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR29;
  __BITS8       ELSELR29_bit;
} @ 0xF031D;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR30;
  __BITS8       ELSELR30_bit;
} @ 0xF031E;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR31;
  __BITS8       ELSELR31_bit;
} @ 0xF031F;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR32;
  __BITS8       ELSELR32_bit;
} @ 0xF0320;

__near __no_bit_access __no_init volatile union
{
  unsigned char ELSELR33;
  __BITS8       ELSELR33_bit;
} @ 0xF0321;

__near __no_init volatile union
{
  unsigned char DAM0;
  __BITS8       DAM0_bit;
  struct
  {
    unsigned char  :4;
    unsigned char  DACE0:1;
    unsigned char  DACE1:1;
    unsigned char  DACE2:1;
    unsigned char  :1;
  };
} @ 0xF0330;

__near __no_init volatile union
{
  unsigned char DAM1;
  __BITS8       DAM1_bit;
  struct
  {
    unsigned char  DAPOE0:1;
    unsigned char  DAPOE1:1;
    unsigned char  DAPOE2:1;
    unsigned char  :5;
  };
} @ 0xF0331;

__near __no_bit_access __no_init volatile union
{
  unsigned char DAM2;
  __BITS8       DAM2_bit;
} @ 0xF0332;

__near __no_bit_access __no_init volatile union
{
  unsigned char DACS2;
  __BITS8       DACS2_bit;
} @ 0xF0333;

__near __no_bit_access __no_init volatile union
{
  unsigned short DACS0;
  __BITS16       DACS0_bit;
} @ 0xF0334;

__near __no_bit_access __no_init volatile union
{
  unsigned short DACS1;
  __BITS16       DACS1_bit;
  struct
  {
    union
    {
      unsigned char DACS1L;
      __BITS8       DACS1L_bit;
    };
  };
} @ 0xF0336;

__near __no_init volatile union
{
  unsigned char COMPMDR0;
  __BITS8       COMPMDR0_bit;
  struct
  {
    unsigned char  C0ENB:1;
    unsigned char  C0POE:1;
    unsigned char  :1;
    unsigned char  C0MON:1;
    unsigned char  C1ENB:1;
    unsigned char  C1POE:1;
    unsigned char  :1;
    unsigned char  C1MON:1;
  };
} @ 0xF0340;

__near __no_bit_access __no_init volatile union
{
  unsigned char COMPFIR0;
  __BITS8       COMPFIR0_bit;
} @ 0xF0341;

__near __no_init volatile union
{
  unsigned char COMPOCR0;
  __BITS8       COMPOCR0_bit;
  struct
  {
    unsigned char  C0IE:1;
    unsigned char  C0OE:1;
    unsigned char  C0OP:1;
    unsigned char  C0OTWMD:1;
    unsigned char  C1IE:1;
    unsigned char  C1OE:1;
    unsigned char  C1OP:1;
    unsigned char  C1OTWMD:1;
  };
} @ 0xF0342;

__near __no_init volatile union
{
  unsigned char COMPMDR1;
  __BITS8       COMPMDR1_bit;
  struct
  {
    unsigned char  C2ENB:1;
    unsigned char  C2POE:1;
    unsigned char  :1;
    unsigned char  C2MON:1;
    unsigned char  C3ENB:1;
    unsigned char  C3POE:1;
    unsigned char  :1;
    unsigned char  C3MON:1;
  };
} @ 0xF0344;

__near __no_bit_access __no_init volatile union
{
  unsigned char COMPFIR1;
  __BITS8       COMPFIR1_bit;
} @ 0xF0345;

__near __no_init volatile union
{
  unsigned char COMPOCR1;
  __BITS8       COMPOCR1_bit;
  struct
  {
    unsigned char  C2IE:1;
    unsigned char  C2OE:1;
    unsigned char  C2OP:1;
    unsigned char  C2OTWMD:1;
    unsigned char  C3IE:1;
    unsigned char  C3OE:1;
    unsigned char  C3OP:1;
    unsigned char  :1;
  };
} @ 0xF0346;

__near __no_init volatile union
{
  unsigned char PGACTL;
  __BITS8       PGACTL_bit;
  struct
  {
    unsigned char  :6;
    unsigned char  PGAPOE:1;
    unsigned char  PGAEN:1;
  };
} @ 0xF0347;

__near __no_init volatile union
{
  unsigned char PGAINS;
  __BITS8       PGAINS_bit;
} @ 0xF0348;

__near __no_bit_access __no_init volatile union
{
  unsigned char CMP0SEL;
  __BITS8       CMP0SEL_bit;
} @ 0xF034A;

__near __no_bit_access __no_init volatile union
{
  unsigned char CMP1SEL;
  __BITS8       CMP1SEL_bit;
} @ 0xF034B;

__near __no_bit_access __no_init volatile union
{
  unsigned char CMP2SEL;
  __BITS8       CMP2SEL_bit;
} @ 0xF034C;

__near __no_bit_access __no_init volatile union
{
  unsigned char CMP3SEL;
  __BITS8       CMP3SEL_bit;
} @ 0xF034D;

__near __no_bit_access __no_init volatile union
{
  unsigned char COMPOCR2;
  __BITS8       COMPOCR2_bit;
} @ 0xF034E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRX;
  __BITS16       TRX_bit;
} @ 0xF0350;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRXBUF;
  const __BITS16       TRXBUF_bit;
} @ 0xF0352;

__near __no_init volatile union
{
  unsigned char TRXCR1;
  __BITS8       TRXCR1_bit;
} @ 0xF0354;

__near __no_init volatile union
{
  unsigned char TRXCR2;
  __BITS8       TRXCR2_bit;
} @ 0xF0355;

__near __no_init volatile union
{
  unsigned char TRXSR;
  __BITS8       TRXSR_bit;
  struct
  {
    unsigned char  TRXOVF:1;
    unsigned char  TRXSB:1;
    unsigned char  :6;
  };
} @ 0xF0356;

__near __no_bit_access __no_init volatile union
{
  unsigned char OPCTL0;
  __BITS8       OPCTL0_bit;
} @ 0xF0358;

__near __no_bit_access __no_init volatile union
{
  unsigned char OPDF0;
  __BITS8       OPDF0_bit;
} @ 0xF0359;

__near __no_bit_access __no_init volatile union
{
  unsigned char OPDF1;
  __BITS8       OPDF1_bit;
} @ 0xF035A;

__near __no_bit_access __no_init volatile union
{
  unsigned char OPEDGE;
  __BITS8       OPEDGE_bit;
} @ 0xF035B;

__near __no_bit_access __no_init volatile union
{
  const unsigned char OPSR;
  const __BITS8       OPSR_bit;
} @ 0xF035C;

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
  unsigned char TPS2;
  __BITS8       TPS2_bit;
} @ 0xF0373;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDELC;
  __BITS8       TRDELC_bit;
} @ 0xF0390;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDBCR;
  __BITS8       TRDBCR_bit;
} @ 0xF0391;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TRDBOF;
  const __BITS8       TRDBOF_bit;
} @ 0xF0392;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDSTR;
  __BITS8       TRDSTR_bit;
} @ 0xF0393;

__near __no_init volatile union
{
  unsigned char TRDMR;
  __BITS8       TRDMR_bit;
  struct
  {
    unsigned char  TRDSYNC:1;
    unsigned char  :3;
    unsigned char  TRDBFC0:1;
    unsigned char  TRDBFD0:1;
    unsigned char  TRDBFC1:1;
    unsigned char  TRDBFD1:1;
  };
} @ 0xF0394;

__near __no_init volatile union
{
  unsigned char TRDPMR;
  __BITS8       TRDPMR_bit;
  struct
  {
    unsigned char  TRDPWMB0:1;
    unsigned char  TRDPWMC0:1;
    unsigned char  TRDPWMD0:1;
    unsigned char  :1;
    unsigned char  TRDPWMB1:1;
    unsigned char  TRDPWMC1:1;
    unsigned char  TRDPWMD1:1;
    unsigned char  TRDPWMA1:1;
  };
} @ 0xF0395;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDFCR;
  __BITS8       TRDFCR_bit;
} @ 0xF0396;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDOER1;
  __BITS8       TRDOER1_bit;
} @ 0xF0397;

__near __no_init volatile union
{
  unsigned char TRDOER2;
  __BITS8       TRDOER2_bit;
  struct
  {
    unsigned char  TRDSHUTS:1;
    unsigned char  :6;
    unsigned char  TRDPTO:1;
  };
} @ 0xF0398;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDOCR;
  __BITS8       TRDOCR_bit;
} @ 0xF0399;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDDF0;
  __BITS8       TRDDF0_bit;
} @ 0xF039A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDDF1;
  __BITS8       TRDDF1_bit;
} @ 0xF039B;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDCR0;
  __BITS8       TRDCR0_bit;
} @ 0xF03A0;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIORA0;
  __BITS8       TRDIORA0_bit;
} @ 0xF03A1;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIORC0;
  __BITS8       TRDIORC0_bit;
} @ 0xF03A2;

__near __no_init volatile union
{
  unsigned char TRDSR0;
  __BITS8       TRDSR0_bit;
} @ 0xF03A3;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIER0;
  __BITS8       TRDIER0_bit;
} @ 0xF03A4;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDPOCR0;
  __BITS8       TRDPOCR0_bit;
} @ 0xF03A5;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRD0;
  __BITS16       TRD0_bit;
} @ 0xF03A6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDGRA0;
  __BITS16       TRDGRA0_bit;
} @ 0xF03A8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDGRB0;
  __BITS16       TRDGRB0_bit;
} @ 0xF03AA;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDCR1;
  __BITS8       TRDCR1_bit;
} @ 0xF03B0;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIORA1;
  __BITS8       TRDIORA1_bit;
} @ 0xF03B1;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIORC1;
  __BITS8       TRDIORC1_bit;
} @ 0xF03B2;

__near __no_init volatile union
{
  unsigned char TRDSR1;
  __BITS8       TRDSR1_bit;
} @ 0xF03B3;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDIER1;
  __BITS8       TRDIER1_bit;
} @ 0xF03B4;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDPOCR1;
  __BITS8       TRDPOCR1_bit;
} @ 0xF03B5;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRD1;
  __BITS16       TRD1_bit;
} @ 0xF03B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDGRA1;
  __BITS16       TRDGRA1_bit;
} @ 0xF03B8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDGRB1;
  __BITS16       TRDGRB1_bit;
} @ 0xF03BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDCMPB0;
  __BITS16       TRDCMPB0_bit;
} @ 0xF03C0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDCMPA1;
  __BITS16       TRDCMPA1_bit;
} @ 0xF03C4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDCMPB1;
  __BITS16       TRDCMPB1_bit;
} @ 0xF03C8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDADTC0;
  __BITS16       TRDADTC0_bit;
  unsigned short TRDCMPE1;
  __BITS16       TRDCMPE1_bit;
} @ 0xF03CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRDADTC1;
  __BITS16       TRDADTC1_bit;
} @ 0xF03D0;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRDRSF;
  const __BITS16       TRDRSF_bit;
} @ 0xF03D6;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TRDRSF0;
  const __BITS8       TRDRSF0_bit;
} @ 0xF03D6;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TRDRSF1;
  const __BITS8       TRDRSF1_bit;
} @ 0xF03D7;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDADCR;
  __BITS8       TRDADCR_bit;
} @ 0xF03D8;

__near __no_init volatile union
{
  unsigned char TRGMR0;
  __BITS8       TRGMR0_bit;
  struct
  {
    unsigned char  TRGPWM:1;
    unsigned char  TRGMDF:1;
    unsigned char  TRGDFA:1;
    unsigned char  TRGDFB:1;
    unsigned char  TRGDFCK0:1;
    unsigned char  TRGDFCK1:1;
    unsigned char  TRGELCICE:1;
    unsigned char  TRGSTART:1;
  };
} @ 0xF03E0;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRGCNTC;
  __BITS8       TRGCNTC_bit;
} @ 0xF03E1;

__near __no_init volatile union
{
  unsigned char TRGCR;
  __BITS8       TRGCR_bit;
  struct
  {
    unsigned char  TRGTCK0:1;
    unsigned char  TRGTCK1:1;
    unsigned char  TRGTCK2:1;
    unsigned char  TRGCKEG0:1;
    unsigned char  TRGCKEG1:1;
    unsigned char  TRGCCLR0:1;
    unsigned char  TRGCCLR1:1;
    unsigned char  :1;
  };
} @ 0xF03E2;

__near __no_init volatile union
{
  unsigned char TRGIER0;
  __BITS8       TRGIER0_bit;
  struct
  {
    unsigned char  TRGIMIEA:1;
    unsigned char  TRGIMIEB:1;
    unsigned char  TRGUDIE:1;
    unsigned char  TRGOVIE:1;
    unsigned char  :2;
    unsigned char  TRGIMIEC:1;
    unsigned char  TRGIMIED:1;
  };
} @ 0xF03E3;

__near __no_init volatile union
{
  unsigned char TRGSR0;
  __BITS8       TRGSR0_bit;
  struct
  {
    unsigned char  TRGIMFA:1;
    unsigned char  TRGIMFB:1;
    unsigned char  TRGUDF:1;
    unsigned char  TRGOVF:1;
    unsigned char  TRGDIRF:1;
    unsigned char  :1;
    unsigned char  TRGIMFC:1;
    unsigned char  TRGIMFD:1;
  };
} @ 0xF03E4;

__near __no_init volatile union
{
  unsigned char TRGIOR;
  __BITS8       TRGIOR_bit;
  struct
  {
    unsigned char  TRGIOA0:1;
    unsigned char  TRGIOA1:1;
    unsigned char  TRGIOA2:1;
    unsigned char  TRGBUFA:1;
    unsigned char  TRGIOB0:1;
    unsigned char  TRGIOB1:1;
    unsigned char  TRGIOB2:1;
    unsigned char  TRGBUFB:1;
  };
} @ 0xF03E5;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRG;
  __BITS16       TRG_bit;
} @ 0xF03E6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRGGRA;
  __BITS16       TRGGRA_bit;
} @ 0xF03E8;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRGGRB;
  __BITS16       TRGGRB_bit;
} @ 0xF03EA;

__near __no_init volatile union
{
  unsigned char TRGMR1;
  __BITS8       TRGMR1_bit;
  struct
  {
    unsigned char  TRGPWM2:1;
    unsigned char  TRGDFCLR:1;
    unsigned char  TRGTCEG0:1;
    unsigned char  TRGTCEG1:1;
    unsigned char  :2;
    unsigned char  TRGPENA:1;
    unsigned char  TRGPENB:1;
  };
} @ 0xF03F0;

__near __no_init volatile union
{
  unsigned char TRGOER;
  __BITS8       TRGOER_bit;
  struct
  {
    unsigned char  TRGSHUTS:1;
    unsigned char  :6;
    unsigned char  TRGPTO:1;
  };
} @ 0xF03F1;

__near __no_init volatile union
{
  unsigned char TRGOCR;
  __BITS8       TRGOCR_bit;
  struct
  {
    unsigned char  TRGTOA:1;
    unsigned char  TRGTOB:1;
    unsigned char  :6;
  };
} @ 0xF03F2;

__near __no_init volatile union
{
  unsigned char TRGIER1;
  __BITS8       TRGIER1_bit;
  struct
  {
    unsigned char  TRGZCIE:1;
    unsigned char  TRGPCIE:1;
    unsigned char  :6;
  };
} @ 0xF03F3;

__near __no_init volatile union
{
  unsigned char TRGSR1;
  __BITS8       TRGSR1_bit;
  struct
  {
    unsigned char  TRGZCLF:1;
    unsigned char  TRGPCLF:1;
    unsigned char  :6;
  };
} @ 0xF03F4;

__near __no_init volatile union
{
  unsigned char TRGSTR;
  __BITS8       TRGSTR_bit;
  struct
  {
    unsigned char  TRGTSTART:1;
    unsigned char  TRGCSEL:1;
    unsigned char  :6;
  };
} @ 0xF03F5;

__near __no_init volatile union
{
  unsigned char TRGCTL0;
  __BITS8       TRGCTL0_bit;
  struct
  {
    unsigned char  TRGIDZ0:1;
    unsigned char  TRGIDZ1:1;
    unsigned char  :2;
    unsigned char  TRGACL:1;
    unsigned char  TRGBCL:1;
    unsigned char  TRGZCL:1;
    unsigned char  TRGSCE:1;
  };
} @ 0xF03F6;

__near __no_init volatile union
{
  unsigned char TRGCTL1;
  __BITS8       TRGCTL1_bit;
  struct
  {
    unsigned char  TRGECM0:1;
    unsigned char  TRGECM1:1;
    unsigned char  :1;
    unsigned char  TRGLDE:1;
    unsigned char  :3;
    unsigned char  TRGPMCE:1;
  };
} @ 0xF03F7;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRGPMC;
  __BITS16       TRGPMC_bit;
} @ 0xF03F8;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRGCAP0;
  const __BITS16       TRGCAP0_bit;
} @ 0xF03FA;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TRGCAP1;
  const __BITS16       TRGCAP1_bit;
} @ 0xF03FC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR20;
  __BITS16       TKBCR20_bit;
} @ 0xF0400;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR21;
  __BITS16       TKBCR21_bit;
} @ 0xF0402;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR22;
  __BITS16       TKBCR22_bit;
} @ 0xF0404;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCR23;
  __BITS16       TKBCR23_bit;
} @ 0xF0406;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBTGCR2;
  __BITS16       TKBTGCR2_bit;
} @ 0xF0408;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR20;
  __BITS16       TKBSIR20_bit;
} @ 0xF040A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBSIR21;
  __BITS16       TKBSIR21_bit;
} @ 0xF040C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR20;
  __BITS8       TKBDNR20_bit;
} @ 0xF040E;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR20;
  __BITS8       TKBSSR20_bit;
} @ 0xF040F;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBDNR21;
  __BITS8       TKBDNR21_bit;
} @ 0xF0410;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBSSR21;
  __BITS8       TKBSSR21_bit;
} @ 0xF0411;

__near __no_init volatile union
{
  unsigned char TKBTRG2 /* write only */ ;
  __BITS8       TKBTRG2_bit;
  struct
  {
    unsigned char  TKBRDT2:1;
    unsigned char  :7;
  };
} @ 0xF0412;

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
} @ 0xF0413;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD20;
  __BITS16       TKBCRLD20_bit;
} @ 0xF0414;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCRLD21;
  __BITS16       TKBCRLD21_bit;
} @ 0xF0416;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB20;
  __BITS8       TKBLEB20_bit;
} @ 0xF0418;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB21;
  __BITS8       TKBLEB21_bit;
} @ 0xF0419;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBCNT2;
  const __BITS16       TKBCNT2_bit;
} @ 0xF0420;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL20;
  __BITS16       TKBCTL20_bit;
} @ 0xF0422;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBMFR2;
  __BITS16       TKBMFR2_bit;
} @ 0xF0424;

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
} @ 0xF0426;

__near __no_init volatile union
{
  unsigned char TKBCLR2 /* write only */ ;
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
} @ 0xF0427;

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
} @ 0xF0428;

__near __no_init volatile union
{
  unsigned char TKBCTL21;
  __BITS8       TKBCTL21_bit;
  struct
  {
    unsigned char  :7;
    unsigned char  TKBCE2:1;
  };
} @ 0xF0429;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBCTL22;
  __BITS16       TKBCTL22_bit;
} @ 0xF042A;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB22;
  __BITS8       TKBLEB22_bit;
} @ 0xF042C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB23;
  __BITS8       TKBLEB23_bit;
} @ 0xF042D;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL20;
  __BITS16       TKBPACTL20_bit;
} @ 0xF0430;

__near __no_bit_access __no_init volatile union
{
  unsigned short TKBPACTL21;
  __BITS16       TKBPACTL21_bit;
} @ 0xF0432;

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
} @ 0xF0434;

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
} @ 0xF0435;

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
} @ 0xF0436;

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
} @ 0xF0437;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBPACTL23;
  __BITS8       TKBPACTL23_bit;
} @ 0xF0438;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBPACTL24;
  __BITS8       TKBPACTL24_bit;
} @ 0xF0439;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS20;
  const __BITS16       TKBPAPLS20_bit;
} @ 0xF043A;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS21;
  const __BITS16       TKBPAPLS21_bit;
} @ 0xF043C;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS20L;
  const __BITS8       TKBPAPLS20L_bit;
} @ 0xF043E;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS21L;
  const __BITS8       TKBPAPLS21L_bit;
} @ 0xF043F;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW0L;
  __BITS16       CWDW0L_bit;
} @ 0xF0440;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW0H;
  __BITS16       CWDW0H_bit;
} @ 0xF0442;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW1L;
  __BITS16       CWDW1L_bit;
} @ 0xF0444;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW1H;
  __BITS16       CWDW1H_bit;
} @ 0xF0446;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW2L;
  __BITS16       CWDW2L_bit;
} @ 0xF0448;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW2H;
  __BITS16       CWDW2H_bit;
} @ 0xF044A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW3L;
  __BITS16       CWDW3L_bit;
} @ 0xF044C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW3H;
  __BITS16       CWDW3H_bit;
} @ 0xF044E;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW4L;
  __BITS16       CWDW4L_bit;
} @ 0xF0450;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW4H;
  __BITS16       CWDW4H_bit;
} @ 0xF0452;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW5L;
  __BITS16       CWDW5L_bit;
} @ 0xF0454;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW5H;
  __BITS16       CWDW5H_bit;
} @ 0xF0456;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW6L;
  __BITS16       CWDW6L_bit;
} @ 0xF0458;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW6H;
  __BITS16       CWDW6H_bit;
} @ 0xF045A;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW7L;
  __BITS16       CWDW7L_bit;
} @ 0xF045C;

__near __no_bit_access __no_init volatile union
{
  unsigned short CWDW7H;
  __BITS16       CWDW7H_bit;
} @ 0xF045E;

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
  unsigned char TRDTCTL;
  __BITS8       TRDTCTL_bit;
} @ 0xF0498;

__near __no_bit_access __no_init volatile union
{
  unsigned char TRDTCMP;
  __BITS8       TRDTCMP_bit;
} @ 0xF0499;

__near __no_bit_access __no_init volatile union
{
  unsigned short WIND;
  __BITS16       WIND_bit;
} @ 0xF04A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short ADBSEL;
  __BITS16       ADBSEL_bit;
} @ 0xF04B0;

__near __no_init volatile union
{
  unsigned char RPECTL2;
  __BITS8       RPECTL2_bit;
  struct
  {
    unsigned char  FAARPEF:1;
    unsigned char  :6;
    unsigned char  FAARPEREN:1;
  };
} @ 0xF04B2;

__near __no_bit_access __no_init volatile union
{
  unsigned char FAADUC;
  __BITS8       FAADUC_bit;
} @ 0xF04B3;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADCL;
  __BITS16       FAADCL_bit;
} @ 0xF04B4;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADCH;
  __BITS16       FAADCH_bit;
} @ 0xF04B6;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADAL;
  __BITS16       FAADAL_bit;
} @ 0xF04B8;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADAH;
  __BITS16       FAADAH_bit;
} @ 0xF04BA;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADBL;
  __BITS16       FAADBL_bit;
} @ 0xF04BC;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAADBH;
  __BITS16       FAADBH_bit;
} @ 0xF04BE;

__near __no_bit_access __no_init volatile union
{
  unsigned short BTVTHR1;
  __BITS16       BTVTHR1_bit;
} @ 0xF04C0;

__near __no_bit_access __no_init volatile union
{
  unsigned short BTVTHR2;
  __BITS16       BTVTHR2_bit;
} @ 0xF04C2;

__near __no_bit_access __no_init volatile union
{
  unsigned short BTVTHR3;
  __BITS16       BTVTHR3_bit;
} @ 0xF04C4;

__near __no_bit_access __no_init volatile union
{
  unsigned short BTVTHR4;
  __BITS16       BTVTHR4_bit;
} @ 0xF04C6;

__near __no_bit_access __no_init volatile union
{
  unsigned short COLTHR1;
  __BITS16       COLTHR1_bit;
} @ 0xF04C8;

__near __no_bit_access __no_init volatile union
{
  unsigned short COLTHR2;
  __BITS16       COLTHR2_bit;
} @ 0xF04CA;

__near __no_bit_access __no_init volatile union
{
  unsigned short COLTHR3;
  __BITS16       COLTHR3_bit;
} @ 0xF04CC;

__near __no_bit_access __no_init volatile union
{
  unsigned short COLTHR4;
  __BITS16       COLTHR4_bit;
} @ 0xF04CE;

__near __no_bit_access __no_init volatile union
{
  unsigned short COLTHR5;
  __BITS16       COLTHR5_bit;
} @ 0xF04D0;

__near __no_bit_access __no_init volatile union
{
  unsigned short CNFR1;
  __BITS16       CNFR1_bit;
} @ 0xF04D2;

__near __no_bit_access __no_init volatile union
{
  unsigned short CNFR2;
  __BITS16       CNFR2_bit;
} @ 0xF04D4;

__near __no_bit_access __no_init volatile union
{
  unsigned short TXWR1;
  __BITS16       TXWR1_bit;
} @ 0xF04D6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TDR1H;
  __BITS16       TDR1H_bit;
} @ 0xF04DE;

__near __no_bit_access __no_init volatile union
{
  unsigned short TDR1L;
  __BITS16       TDR1L_bit;
} @ 0xF04E0;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRSTR1 /* write only */ ;
  __BITS16       TRSTR1_bit;
} @ 0xF04E2;

__near __no_bit_access __no_init volatile union
{
  unsigned short CTR1;
  __BITS16       CTR1_bit;
} @ 0xF04E6;

__near __no_bit_access __no_init volatile union
{
  unsigned short TXDCTR1;
  __BITS16       TXDCTR1_bit;
} @ 0xF04E8;

__near __no_bit_access __no_init volatile union
{
  const unsigned short RDR1H;
  const __BITS16       RDR1H_bit;
} @ 0xF04EE;

__near __no_bit_access __no_init volatile union
{
  const unsigned short RDR1L;
  const __BITS16       RDR1L_bit;
} @ 0xF04F0;

__near __no_bit_access __no_init volatile union
{
  const unsigned short STR1;
  const __BITS16       STR1_bit;
} @ 0xF04F2;

__near __no_bit_access __no_init volatile union
{
  const unsigned short STR2;
  const __BITS16       STR2_bit;
} @ 0xF04F4;

__near __no_bit_access __no_init volatile union
{
  const unsigned short COLR1;
  const __BITS16       COLR1_bit;
} @ 0xF04F6;

__near __no_bit_access __no_init volatile union
{
  unsigned short FECR1 /* write only */ ;
  __BITS16       FECR1_bit;
} @ 0xF04FA;

__near __no_bit_access __no_init volatile union
{
  unsigned short SWRR1 /* write only */ ;
  __BITS16       SWRR1_bit;
} @ 0xF04FC;

__near __no_bit_access __no_init volatile union
{
  unsigned short TRJ0;
  __BITS16       TRJ0_bit;
} @ 0xF0500;

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
  unsigned short A0L;
  __BITS16       A0L_bit;
} @ 0xF0600;

__near __no_bit_access __no_init volatile union
{
  unsigned short A0H;
  __BITS16       A0H_bit;
} @ 0xF0602;

__near __no_bit_access __no_init volatile union
{
  unsigned short M0L;
  __BITS16       M0L_bit;
  unsigned short TMCMP0L;
  __BITS16       TMCMP0L_bit;
} @ 0xF0604;

__near __no_bit_access __no_init volatile union
{
  unsigned short M0H;
  __BITS16       M0H_bit;
  unsigned short TMCMP0H;
  __BITS16       TMCMP0H_bit;
} @ 0xF0606;

__near __no_bit_access __no_init volatile union
{
  unsigned short M1L;
  __BITS16       M1L_bit;
  unsigned short TMCMP1L;
  __BITS16       TMCMP1L_bit;
} @ 0xF0608;

__near __no_bit_access __no_init volatile union
{
  unsigned short M1H;
  __BITS16       M1H_bit;
  unsigned short TMCMP1H;
  __BITS16       TMCMP1H_bit;
} @ 0xF060A;

__near __no_bit_access __no_init volatile union
{
  unsigned short L0L;
  __BITS16       L0L_bit;
  unsigned short TMCMP2L;
  __BITS16       TMCMP2L_bit;
} @ 0xF060C;

__near __no_bit_access __no_init volatile union
{
  unsigned short L0H;
  __BITS16       L0H_bit;
  unsigned short TMCMP2H;
  __BITS16       TMCMP2H_bit;
} @ 0xF060E;

__near __no_bit_access __no_init volatile union
{
  unsigned short L1L;
  __BITS16       L1L_bit;
  unsigned short TMCMP3L;
  __BITS16       TMCMP3L_bit;
} @ 0xF0610;

__near __no_bit_access __no_init volatile union
{
  unsigned short L1H;
  __BITS16       L1H_bit;
  unsigned short TMCMP3H;
  __BITS16       TMCMP3H_bit;
} @ 0xF0612;

__near __no_bit_access __no_init volatile union
{
  unsigned short R0L;
  __BITS16       R0L_bit;
  unsigned short TMCMP4L;
  __BITS16       TMCMP4L_bit;
} @ 0xF0614;

__near __no_bit_access __no_init volatile union
{
  unsigned short R0H;
  __BITS16       R0H_bit;
  unsigned short TMCMP4H;
  __BITS16       TMCMP4H_bit;
} @ 0xF0616;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMCMP5L;
  __BITS16       TMCMP5L_bit;
} @ 0xF0618;

__near __no_bit_access __no_init volatile union
{
  unsigned short DP0;
  __BITS16       DP0_bit;
  unsigned short TMCMP5H;
  __BITS16       TMCMP5H_bit;
} @ 0xF061A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK0L;
  __BITS16       TMMSK0L_bit;
} @ 0xF061C;

__near __no_bit_access __no_init volatile union
{
  unsigned short DP1;
  __BITS16       DP1_bit;
  unsigned short TMMSK0H;
  __BITS16       TMMSK0H_bit;
} @ 0xF061E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK1L;
  __BITS16       TMMSK1L_bit;
} @ 0xF0620;

__near __no_bit_access __no_init volatile union
{
  unsigned short DRP0;
  __BITS16       DRP0_bit;
  unsigned short TMMSK1H;
  __BITS16       TMMSK1H_bit;
} @ 0xF0622;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK2L;
  __BITS16       TMMSK2L_bit;
} @ 0xF0624;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK2H;
  __BITS16       TMMSK2H_bit;
} @ 0xF0626;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK3L;
  __BITS16       TMMSK3L_bit;
} @ 0xF0628;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAACNT;
  __BITS16       FAACNT_bit;
  unsigned short TMMSK3H;
  __BITS16       TMMSK3H_bit;
} @ 0xF062A;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK4L;
  __BITS16       TMMSK4L_bit;
} @ 0xF062C;

__near __no_bit_access __no_init volatile union
{
  unsigned short PG0;
  __BITS16       PG0_bit;
  unsigned short TMMSK4H;
  __BITS16       TMMSK4H_bit;
} @ 0xF062E;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK5L;
  __BITS16       TMMSK5L_bit;
} @ 0xF0630;

__near __no_bit_access __no_init volatile union
{
  unsigned short TMMSK5H;
  __BITS16       TMMSK5H_bit;
} @ 0xF0632;

__near __no_bit_access __no_init volatile union
{
  unsigned short FCNTL;
  __BITS16       FCNTL_bit;
} @ 0xF0634;

__near __no_bit_access __no_init volatile union
{
  unsigned short FAAFLG;
  __BITS16       FAAFLG_bit;
  unsigned short FCNTH;
  __BITS16       FCNTH_bit;
} @ 0xF0636;

__near __no_bit_access __no_init volatile union
{
  unsigned short FCCNT;
  __BITS16       FCCNT_bit;
} @ 0xF0638;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV0L;
  __BITS16       IV0L_bit;
} @ 0xF0648;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV0H;
  __BITS16       IV0H_bit;
} @ 0xF064A;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV1L;
  __BITS16       IV1L_bit;
} @ 0xF064C;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV1H;
  __BITS16       IV1H_bit;
} @ 0xF064E;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV2L;
  __BITS16       IV2L_bit;
} @ 0xF0650;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV2H;
  __BITS16       IV2H_bit;
} @ 0xF0652;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV3L;
  __BITS16       IV3L_bit;
} @ 0xF0654;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV3H;
  __BITS16       IV3H_bit;
} @ 0xF0656;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV4L;
  __BITS16       IV4L_bit;
} @ 0xF0658;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV4H;
  __BITS16       IV4H_bit;
} @ 0xF065A;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV5L;
  __BITS16       IV5L_bit;
} @ 0xF065C;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV5H;
  __BITS16       IV5H_bit;
} @ 0xF065E;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV6L;
  __BITS16       IV6L_bit;
} @ 0xF0660;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV6H;
  __BITS16       IV6H_bit;
} @ 0xF0662;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV7L;
  __BITS16       IV7L_bit;
} @ 0xF0664;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV7H;
  __BITS16       IV7H_bit;
} @ 0xF0666;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV8L;
  __BITS16       IV8L_bit;
} @ 0xF0668;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV8H;
  __BITS16       IV8H_bit;
} @ 0xF066A;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV9L;
  __BITS16       IV9L_bit;
} @ 0xF066C;

__near __no_bit_access __no_init volatile union
{
  unsigned short DSYSC;
  __BITS16       DSYSC_bit;
  unsigned short IV9H;
  __BITS16       IV9H_bit;
} @ 0xF066E;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV10L;
  __BITS16       IV10L_bit;
} @ 0xF0670;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV10H;
  __BITS16       IV10H_bit;
} @ 0xF0672;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV11L;
  __BITS16       IV11L_bit;
} @ 0xF0674;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV11H;
  __BITS16       IV11H_bit;
} @ 0xF0676;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV12L;
  __BITS16       IV12L_bit;
} @ 0xF0678;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV12H;
  __BITS16       IV12H_bit;
} @ 0xF067A;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV13L;
  __BITS16       IV13L_bit;
} @ 0xF067C;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV13H;
  __BITS16       IV13H_bit;
} @ 0xF067E;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV14L;
  __BITS16       IV14L_bit;
} @ 0xF0680;

__near __no_bit_access __no_init volatile union
{
  unsigned short SP0;
  __BITS16       SP0_bit;
  unsigned short IV14H;
  __BITS16       IV14H_bit;
} @ 0xF0682;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV15L;
  __BITS16       IV15L_bit;
} @ 0xF0684;

__near __no_bit_access __no_init volatile union
{
  unsigned short IV15H;
  __BITS16       IV15H_bit;
} @ 0xF0686;

__near __no_bit_access __no_init volatile union
{
  unsigned short IEVSC0L;
  __BITS16       IEVSC0L_bit;
} @ 0xF06A0;

__near __no_bit_access __no_init volatile union
{
  unsigned short IEVSC0H;
  __BITS16       IEVSC0H_bit;
} @ 0xF06A2;

__near __no_bit_access __no_init volatile union
{
  unsigned short IEVSC1;
  __BITS16       IEVSC1_bit;
} @ 0xF06A4;

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
  unsigned char TKBTRG0 /* write only */ ;
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
  unsigned char TKBLEB00;
  __BITS8       TKBLEB00_bit;
} @ 0xF0758;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB01;
  __BITS8       TKBLEB01_bit;
} @ 0xF0759;

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
  unsigned char TKBCLR0 /* write only */ ;
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
  unsigned char TKBLEB02;
  __BITS8       TKBLEB02_bit;
} @ 0xF076C;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB03;
  __BITS8       TKBLEB03_bit;
} @ 0xF076D;

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
  unsigned char TKBPACTL03;
  __BITS8       TKBPACTL03_bit;
} @ 0xF0778;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBPACTL04;
  __BITS8       TKBPACTL04_bit;
} @ 0xF0779;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS00;
  const __BITS16       TKBPAPLS00_bit;
} @ 0xF077A;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS01;
  const __BITS16       TKBPAPLS01_bit;
} @ 0xF077C;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS00L;
  const __BITS8       TKBPAPLS00L_bit;
} @ 0xF077E;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS01L;
  const __BITS8       TKBPAPLS01L_bit;
} @ 0xF077F;

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
  unsigned char TKBTRG1 /* write only */ ;
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
  unsigned char TKBLEB10;
  __BITS8       TKBLEB10_bit;
} @ 0xF0798;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB11;
  __BITS8       TKBLEB11_bit;
} @ 0xF0799;

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
  unsigned char TKBCLR1 /* write only */ ;
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
  unsigned char TKBLEB12;
  __BITS8       TKBLEB12_bit;
} @ 0xF07AC;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBLEB13;
  __BITS8       TKBLEB13_bit;
} @ 0xF07AD;

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
  unsigned char TKBPACTL13;
  __BITS8       TKBPACTL13_bit;
} @ 0xF07B8;

__near __no_bit_access __no_init volatile union
{
  unsigned char TKBPACTL14;
  __BITS8       TKBPACTL14_bit;
} @ 0xF07B9;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS10;
  const __BITS16       TKBPAPLS10_bit;
} @ 0xF07BA;

__near __no_bit_access __no_init volatile union
{
  const unsigned short TKBPAPLS11;
  const __BITS16       TKBPAPLS11_bit;
} @ 0xF07BC;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS10L;
  const __BITS8       TKBPAPLS10L_bit;
} @ 0xF07BE;

__near __no_bit_access __no_init volatile union
{
  const unsigned char TKBPAPLS11L;
  const __BITS8       TKBPAPLS11L_bit;
} @ 0xF07BF;


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
ADM3       DEFINE  0xF0014
ADS0       DEFINE  0xF0015
ADS1       DEFINE  0xF0016
ADS2       DEFINE  0xF0017
ADS3       DEFINE  0xF0018
ADSCTL     DEFINE  0xF0019
ADTR0      DEFINE  0xF001A
ADTR1      DEFINE  0xF001B
ADTR2      DEFINE  0xF001C
ADTR3      DEFINE  0xF001D
ADPS       DEFINE  0xF001E
ADSPMOD    DEFINE  0xF001F
ADCR0      DEFINE  0xF0020
ADCR0H     DEFINE  0xF0021
ADCR1      DEFINE  0xF0022
ADCR1H     DEFINE  0xF0023
ADCR2      DEFINE  0xF0024
ADCR2H     DEFINE  0xF0025
ADCR3      DEFINE  0xF0026
ADCR3H     DEFINE  0xF0027
ADINTCTL   DEFINE  0xF0028
ADINTST    DEFINE  0xF0029
PU0        DEFINE  0xF0030
PU1        DEFINE  0xF0031
PU3        DEFINE  0xF0033
PU4        DEFINE  0xF0034
PU5        DEFINE  0xF0035
PU6        DEFINE  0xF0036
PU7        DEFINE  0xF0037
PU12       DEFINE  0xF003C
PU14       DEFINE  0xF003E
PIM0       DEFINE  0xF0040
PIM1       DEFINE  0xF0041
PIM3       DEFINE  0xF0043
PIM5       DEFINE  0xF0045
PIM7       DEFINE  0xF0047
POM0       DEFINE  0xF0050
POM1       DEFINE  0xF0051
POM3       DEFINE  0xF0053
POM5       DEFINE  0xF0055
POM7       DEFINE  0xF0057
PMCA0      DEFINE  0xF0060
PMCA1      DEFINE  0xF0061
PMCA2      DEFINE  0xF0062
PMCA12     DEFINE  0xF006C
PMCA14     DEFINE  0xF006E
NFEN0      DEFINE  0xF0070
NFEN1      DEFINE  0xF0071
ISC        DEFINE  0xF0073
TIOS0      DEFINE  0xF0074
PIOR0      DEFINE  0xF0077
IAWCTL     DEFINE  0xF0078
ULBS       DEFINE  0xF0079
IICM       DEFINE  0xF007A
PMS        DEFINE  0xF007B
PFBER      DEFINE  0xF007C
GDIDIS     DEFINE  0xF007D
DFLCTL     DEFINE  0xF0090
PCKC       DEFINE  0xF0098
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
SIR10      DEFINE  0xF0148
SIR10L     DEFINE  0xF0148
SIR11      DEFINE  0xF014A
SIR11L     DEFINE  0xF014A
SMR10      DEFINE  0xF0150
SMR11      DEFINE  0xF0152
SCR10      DEFINE  0xF0158
SCR11      DEFINE  0xF015A
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
TCR00      DEFINE  0xF0180
TCR01      DEFINE  0xF0182
TCR02      DEFINE  0xF0184
TCR03      DEFINE  0xF0186
TMR00      DEFINE  0xF0190
TMR01      DEFINE  0xF0192
TMR02      DEFINE  0xF0194
TMR03      DEFINE  0xF0196
TSR00      DEFINE  0xF01A0
TSR00L     DEFINE  0xF01A0
TSR01      DEFINE  0xF01A2
TSR01L     DEFINE  0xF01A2
TSR02      DEFINE  0xF01A4
TSR02L     DEFINE  0xF01A4
TSR03      DEFINE  0xF01A6
TSR03L     DEFINE  0xF01A6
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
LVDFCLR    DEFINE  0xF0218
HSCLKSEL   DEFINE  0xF0219
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
TRJCR0     DEFINE  0xF0240
TRJIOC0    DEFINE  0xF0241
TRJMR0     DEFINE  0xF0242
TRJISR0    DEFINE  0xF0243
CCS0       DEFINE  0xF02A0
CCS4       DEFINE  0xF02A4
CCS5       DEFINE  0xF02A5
CCS6       DEFINE  0xF02A6
CCS7       DEFINE  0xF02A7
CCDE       DEFINE  0xF02A8
TRDPOE     DEFINE  0xF02AC
PIOR1      DEFINE  0xF02AD
PIOR2      DEFINE  0xF02AE
PIOR3      DEFINE  0xF02AF
PDIDIS0    DEFINE  0xF02B0
PDIDIS1    DEFINE  0xF02B1
PDIDIS3    DEFINE  0xF02B3
PDIDIS5    DEFINE  0xF02B5
PDIDIS7    DEFINE  0xF02B7
PDIDIS13   DEFINE  0xF02BD
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
DTCBAR     DEFINE  0xF02E0
DSCCTL     DEFINE  0xF02E5
MCKC       DEFINE  0xF02E6
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
ELSELR00   DEFINE  0xF0300
ELSELR01   DEFINE  0xF0301
ELSELR02   DEFINE  0xF0302
ELSELR03   DEFINE  0xF0303
ELSELR04   DEFINE  0xF0304
ELSELR05   DEFINE  0xF0305
ELSELR06   DEFINE  0xF0306
ELSELR07   DEFINE  0xF0307
ELSELR08   DEFINE  0xF0308
ELSELR09   DEFINE  0xF0309
ELSELR10   DEFINE  0xF030A
ELSELR11   DEFINE  0xF030B
ELSELR12   DEFINE  0xF030C
ELSELR13   DEFINE  0xF030D
ELSELR14   DEFINE  0xF030E
ELSELR15   DEFINE  0xF030F
ELSELR16   DEFINE  0xF0310
ELSELR17   DEFINE  0xF0311
ELSELR18   DEFINE  0xF0312
ELSELR19   DEFINE  0xF0313
ELSELR20   DEFINE  0xF0314
ELSELR21   DEFINE  0xF0315
ELSELR22   DEFINE  0xF0316
ELSELR23   DEFINE  0xF0317
ELSELR24   DEFINE  0xF0318
ELSELR25   DEFINE  0xF0319
ELSELR26   DEFINE  0xF031A
ELSELR27   DEFINE  0xF031B
ELSELR28   DEFINE  0xF031C
ELSELR29   DEFINE  0xF031D
ELSELR30   DEFINE  0xF031E
ELSELR31   DEFINE  0xF031F
ELSELR32   DEFINE  0xF0320
ELSELR33   DEFINE  0xF0321
DAM0       DEFINE  0xF0330
DAM1       DEFINE  0xF0331
DAM2       DEFINE  0xF0332
DACS2      DEFINE  0xF0333
DACS0      DEFINE  0xF0334
DACS1      DEFINE  0xF0336
DACS1L     DEFINE  0xF0336
COMPMDR0   DEFINE  0xF0340
COMPFIR0   DEFINE  0xF0341
COMPOCR0   DEFINE  0xF0342
COMPMDR1   DEFINE  0xF0344
COMPFIR1   DEFINE  0xF0345
COMPOCR1   DEFINE  0xF0346
PGACTL     DEFINE  0xF0347
PGAINS     DEFINE  0xF0348
CMP0SEL    DEFINE  0xF034A
CMP1SEL    DEFINE  0xF034B
CMP2SEL    DEFINE  0xF034C
CMP3SEL    DEFINE  0xF034D
COMPOCR2   DEFINE  0xF034E
TRX        DEFINE  0xF0350
TRXBUF     DEFINE  0xF0352
TRXCR1     DEFINE  0xF0354
TRXCR2     DEFINE  0xF0355
TRXSR      DEFINE  0xF0356
OPCTL0     DEFINE  0xF0358
OPDF0      DEFINE  0xF0359
OPDF1      DEFINE  0xF035A
OPEDGE     DEFINE  0xF035B
OPSR       DEFINE  0xF035C
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
TPS2       DEFINE  0xF0373
TRDELC     DEFINE  0xF0390
TRDBCR     DEFINE  0xF0391
TRDBOF     DEFINE  0xF0392
TRDSTR     DEFINE  0xF0393
TRDMR      DEFINE  0xF0394
TRDPMR     DEFINE  0xF0395
TRDFCR     DEFINE  0xF0396
TRDOER1    DEFINE  0xF0397
TRDOER2    DEFINE  0xF0398
TRDOCR     DEFINE  0xF0399
TRDDF0     DEFINE  0xF039A
TRDDF1     DEFINE  0xF039B
TRDCR0     DEFINE  0xF03A0
TRDIORA0   DEFINE  0xF03A1
TRDIORC0   DEFINE  0xF03A2
TRDSR0     DEFINE  0xF03A3
TRDIER0    DEFINE  0xF03A4
TRDPOCR0   DEFINE  0xF03A5
TRD0       DEFINE  0xF03A6
TRDGRA0    DEFINE  0xF03A8
TRDGRB0    DEFINE  0xF03AA
TRDCR1     DEFINE  0xF03B0
TRDIORA1   DEFINE  0xF03B1
TRDIORC1   DEFINE  0xF03B2
TRDSR1     DEFINE  0xF03B3
TRDIER1    DEFINE  0xF03B4
TRDPOCR1   DEFINE  0xF03B5
TRD1       DEFINE  0xF03B6
TRDGRA1    DEFINE  0xF03B8
TRDGRB1    DEFINE  0xF03BA
TRDCMPB0   DEFINE  0xF03C0
TRDCMPA1   DEFINE  0xF03C4
TRDCMPB1   DEFINE  0xF03C8
TRDADTC0   DEFINE  0xF03CC
TRDCMPE1   DEFINE  0xF03CC
TRDADTC1   DEFINE  0xF03D0
TRDRSF     DEFINE  0xF03D6
TRDRSF0    DEFINE  0xF03D6
TRDRSF1    DEFINE  0xF03D7
TRDADCR    DEFINE  0xF03D8
TRGMR0     DEFINE  0xF03E0
TRGCNTC    DEFINE  0xF03E1
TRGCR      DEFINE  0xF03E2
TRGIER0    DEFINE  0xF03E3
TRGSR0     DEFINE  0xF03E4
TRGIOR     DEFINE  0xF03E5
TRG        DEFINE  0xF03E6
TRGGRA     DEFINE  0xF03E8
TRGGRB     DEFINE  0xF03EA
TRGMR1     DEFINE  0xF03F0
TRGOER     DEFINE  0xF03F1
TRGOCR     DEFINE  0xF03F2
TRGIER1    DEFINE  0xF03F3
TRGSR1     DEFINE  0xF03F4
TRGSTR     DEFINE  0xF03F5
TRGCTL0    DEFINE  0xF03F6
TRGCTL1    DEFINE  0xF03F7
TRGPMC     DEFINE  0xF03F8
TRGCAP0    DEFINE  0xF03FA
TRGCAP1    DEFINE  0xF03FC
TKBCR20    DEFINE  0xF0400
TKBCR21    DEFINE  0xF0402
TKBCR22    DEFINE  0xF0404
TKBCR23    DEFINE  0xF0406
TKBTGCR2   DEFINE  0xF0408
TKBSIR20   DEFINE  0xF040A
TKBSIR21   DEFINE  0xF040C
TKBDNR20   DEFINE  0xF040E
TKBSSR20   DEFINE  0xF040F
TKBDNR21   DEFINE  0xF0410
TKBSSR21   DEFINE  0xF0411
TKBTRG2    DEFINE  0xF0412
TKBFLG2    DEFINE  0xF0413
TKBCRLD20  DEFINE  0xF0414
TKBCRLD21  DEFINE  0xF0416
TKBLEB20   DEFINE  0xF0418
TKBLEB21   DEFINE  0xF0419
TKBCNT2    DEFINE  0xF0420
TKBCTL20   DEFINE  0xF0422
TKBMFR2    DEFINE  0xF0424
TKBIOC20   DEFINE  0xF0426
TKBCLR2    DEFINE  0xF0427
TKBIOC21   DEFINE  0xF0428
TKBCTL21   DEFINE  0xF0429
TKBCTL22   DEFINE  0xF042A
TKBLEB22   DEFINE  0xF042C
TKBLEB23   DEFINE  0xF042D
TKBPACTL20 DEFINE  0xF0430
TKBPACTL21 DEFINE  0xF0432
TKBPAHFS2  DEFINE  0xF0434
TKBPAHFT2  DEFINE  0xF0435
TKBPAFLG2  DEFINE  0xF0436
TKBPACTL22 DEFINE  0xF0437
TKBPACTL23 DEFINE  0xF0438
TKBPACTL24 DEFINE  0xF0439
TKBPAPLS20 DEFINE  0xF043A
TKBPAPLS21 DEFINE  0xF043C
TKBPAPLS20L DEFINE  0xF043E
TKBPAPLS21L DEFINE  0xF043F
CWDW0L     DEFINE  0xF0440
CWDW0H     DEFINE  0xF0442
CWDW1L     DEFINE  0xF0444
CWDW1H     DEFINE  0xF0446
CWDW2L     DEFINE  0xF0448
CWDW2H     DEFINE  0xF044A
CWDW3L     DEFINE  0xF044C
CWDW3H     DEFINE  0xF044E
CWDW4L     DEFINE  0xF0450
CWDW4H     DEFINE  0xF0452
CWDW5L     DEFINE  0xF0454
CWDW5H     DEFINE  0xF0456
CWDW6L     DEFINE  0xF0458
CWDW6H     DEFINE  0xF045A
CWDW7L     DEFINE  0xF045C
CWDW7H     DEFINE  0xF045E
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
TRDTCTL    DEFINE  0xF0498
TRDTCMP    DEFINE  0xF0499
WIND       DEFINE  0xF04A0
ADBSEL     DEFINE  0xF04B0
RPECTL2    DEFINE  0xF04B2
FAADUC     DEFINE  0xF04B3
FAADCL     DEFINE  0xF04B4
FAADCH     DEFINE  0xF04B6
FAADAL     DEFINE  0xF04B8
FAADAH     DEFINE  0xF04BA
FAADBL     DEFINE  0xF04BC
FAADBH     DEFINE  0xF04BE
BTVTHR1    DEFINE  0xF04C0
BTVTHR2    DEFINE  0xF04C2
BTVTHR3    DEFINE  0xF04C4
BTVTHR4    DEFINE  0xF04C6
COLTHR1    DEFINE  0xF04C8
COLTHR2    DEFINE  0xF04CA
COLTHR3    DEFINE  0xF04CC
COLTHR4    DEFINE  0xF04CE
COLTHR5    DEFINE  0xF04D0
CNFR1      DEFINE  0xF04D2
CNFR2      DEFINE  0xF04D4
TXWR1      DEFINE  0xF04D6
TDR1H      DEFINE  0xF04DE
TDR1L      DEFINE  0xF04E0
TRSTR1     DEFINE  0xF04E2
CTR1       DEFINE  0xF04E6
TXDCTR1    DEFINE  0xF04E8
RDR1H      DEFINE  0xF04EE
RDR1L      DEFINE  0xF04F0
STR1       DEFINE  0xF04F2
STR2       DEFINE  0xF04F4
COLR1      DEFINE  0xF04F6
FECR1      DEFINE  0xF04FA
SWRR1      DEFINE  0xF04FC
TRJ0       DEFINE  0xF0500
TRNGSDR    DEFINE  0xF0540
TRNGSCR0   DEFINE  0xF0542
A0L        DEFINE  0xF0600
A0H        DEFINE  0xF0602
M0L        DEFINE  0xF0604
TMCMP0L    DEFINE  0xF0604
M0H        DEFINE  0xF0606
TMCMP0H    DEFINE  0xF0606
M1L        DEFINE  0xF0608
TMCMP1L    DEFINE  0xF0608
M1H        DEFINE  0xF060A
TMCMP1H    DEFINE  0xF060A
L0L        DEFINE  0xF060C
TMCMP2L    DEFINE  0xF060C
L0H        DEFINE  0xF060E
TMCMP2H    DEFINE  0xF060E
L1L        DEFINE  0xF0610
TMCMP3L    DEFINE  0xF0610
L1H        DEFINE  0xF0612
TMCMP3H    DEFINE  0xF0612
R0L        DEFINE  0xF0614
TMCMP4L    DEFINE  0xF0614
R0H        DEFINE  0xF0616
TMCMP4H    DEFINE  0xF0616
TMCMP5L    DEFINE  0xF0618
DP0        DEFINE  0xF061A
TMCMP5H    DEFINE  0xF061A
TMMSK0L    DEFINE  0xF061C
DP1        DEFINE  0xF061E
TMMSK0H    DEFINE  0xF061E
TMMSK1L    DEFINE  0xF0620
DRP0       DEFINE  0xF0622
TMMSK1H    DEFINE  0xF0622
TMMSK2L    DEFINE  0xF0624
TMMSK2H    DEFINE  0xF0626
TMMSK3L    DEFINE  0xF0628
FAACNT     DEFINE  0xF062A
TMMSK3H    DEFINE  0xF062A
TMMSK4L    DEFINE  0xF062C
PG0        DEFINE  0xF062E
TMMSK4H    DEFINE  0xF062E
TMMSK5L    DEFINE  0xF0630
TMMSK5H    DEFINE  0xF0632
FCNTL      DEFINE  0xF0634
FAAFLG     DEFINE  0xF0636
FCNTH      DEFINE  0xF0636
FCCNT      DEFINE  0xF0638
IV0L       DEFINE  0xF0648
IV0H       DEFINE  0xF064A
IV1L       DEFINE  0xF064C
IV1H       DEFINE  0xF064E
IV2L       DEFINE  0xF0650
IV2H       DEFINE  0xF0652
IV3L       DEFINE  0xF0654
IV3H       DEFINE  0xF0656
IV4L       DEFINE  0xF0658
IV4H       DEFINE  0xF065A
IV5L       DEFINE  0xF065C
IV5H       DEFINE  0xF065E
IV6L       DEFINE  0xF0660
IV6H       DEFINE  0xF0662
IV7L       DEFINE  0xF0664
IV7H       DEFINE  0xF0666
IV8L       DEFINE  0xF0668
IV8H       DEFINE  0xF066A
IV9L       DEFINE  0xF066C
DSYSC      DEFINE  0xF066E
IV9H       DEFINE  0xF066E
IV10L      DEFINE  0xF0670
IV10H      DEFINE  0xF0672
IV11L      DEFINE  0xF0674
IV11H      DEFINE  0xF0676
IV12L      DEFINE  0xF0678
IV12H      DEFINE  0xF067A
IV13L      DEFINE  0xF067C
IV13H      DEFINE  0xF067E
IV14L      DEFINE  0xF0680
SP0        DEFINE  0xF0682
IV14H      DEFINE  0xF0682
IV15L      DEFINE  0xF0684
IV15H      DEFINE  0xF0686
IEVSC0L    DEFINE  0xF06A0
IEVSC0H    DEFINE  0xF06A2
IEVSC1     DEFINE  0xF06A4
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
TKBLEB00   DEFINE  0xF0758
TKBLEB01   DEFINE  0xF0759
TKBCNT0    DEFINE  0xF0760
TKBCTL00   DEFINE  0xF0762
TKBMFR0    DEFINE  0xF0764
TKBIOC00   DEFINE  0xF0766
TKBCLR0    DEFINE  0xF0767
TKBIOC01   DEFINE  0xF0768
TKBCTL01   DEFINE  0xF0769
TKBCTL02   DEFINE  0xF076A
TKBLEB02   DEFINE  0xF076C
TKBLEB03   DEFINE  0xF076D
TKBPACTL00 DEFINE  0xF0770
TKBPACTL01 DEFINE  0xF0772
TKBPAHFS0  DEFINE  0xF0774
TKBPAHFT0  DEFINE  0xF0775
TKBPAFLG0  DEFINE  0xF0776
TKBPACTL02 DEFINE  0xF0777
TKBPACTL03 DEFINE  0xF0778
TKBPACTL04 DEFINE  0xF0779
TKBPAPLS00 DEFINE  0xF077A
TKBPAPLS01 DEFINE  0xF077C
TKBPAPLS00L DEFINE  0xF077E
TKBPAPLS01L DEFINE  0xF077F
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
TKBLEB10   DEFINE  0xF0798
TKBLEB11   DEFINE  0xF0799
TKBCNT1    DEFINE  0xF07A0
TKBCTL10   DEFINE  0xF07A2
TKBMFR1    DEFINE  0xF07A4
TKBIOC10   DEFINE  0xF07A6
TKBCLR1    DEFINE  0xF07A7
TKBIOC11   DEFINE  0xF07A8
TKBCTL11   DEFINE  0xF07A9
TKBCTL12   DEFINE  0xF07AA
TKBLEB12   DEFINE  0xF07AC
TKBLEB13   DEFINE  0xF07AD
TKBPACTL10 DEFINE  0xF07B0
TKBPACTL11 DEFINE  0xF07B2
TKBPAHFS1  DEFINE  0xF07B4
TKBPAHFT1  DEFINE  0xF07B5
TKBPAFLG1  DEFINE  0xF07B6
TKBPACTL12 DEFINE  0xF07B7
TKBPACTL13 DEFINE  0xF07B8
TKBPACTL14 DEFINE  0xF07B9
TKBPAPLS10 DEFINE  0xF07BA
TKBPAPLS11 DEFINE  0xF07BC
TKBPAPLS10L DEFINE  0xF07BE
TKBPAPLS11L DEFINE  0xF07BF

#endif /* __IAR_SYSTEMS_ASM__ */

#endif /* __IOR7F101GLG_EXT_H__ */

/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability 
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021, 2022 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_kr.h
* Version          : 1.0.11
* Device(s)        : R7F100GLGxFA
* Description      : General header file for Key Interrupt peripheral.
***********************************************************************************************************************/

#ifndef KR_H
#define KR_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Key Return Control Register (KRCTL)
*/
/* Usage of key return flags (KRF0 to KRF7) (KRMD) */
#define _00_KR_KRCTL_RETURN_UNUSED          (0x00U)    /* does not use key return flags */
#define _80_KR_KRCTL_RETURN_USED            (0x80U)    /* uses key return flags */
/* Selection of detection edge (KR0 to KR7) (KREG) */
#define _00_KR_KRCTL_EDGE_FALLING           (0x00U)    /* falling edge */
#define _01_KR_KRCTL_EDGE_RISING            (0x01U)    /* rising edge */

/*
    Key Return Mode Register 0 (KRM0)
*/
/* Key interrupt mode control (KRM07) */
#define _00_KR7_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR7 signal */
#define _80_KR7_SIGNAL_DETECT_ON            (0x80U)    /* detect KR7 signal */
/* Key interrupt mode control (KRM06) */
#define _00_KR6_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR6 signal */
#define _40_KR6_SIGNAL_DETECT_ON            (0x40U)    /* detect KR6 signal */
/* Key interrupt mode control (KRM05) */
#define _00_KR5_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR5 signal */
#define _20_KR5_SIGNAL_DETECT_ON            (0x20U)    /* detect KR5 signal */
/* Key interrupt mode control (KRM04) */
#define _00_KR4_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR4 signal */
#define _10_KR4_SIGNAL_DETECT_ON            (0x10U)    /* detect KR4 signal */
/* Key interrupt mode control (KRM03) */
#define _00_KR3_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR3 signal */
#define _08_KR3_SIGNAL_DETECT_ON            (0x08U)    /* detect KR3 signal */
/* Key interrupt mode control (KRM02) */
#define _00_KR2_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR2 signal */
#define _04_KR2_SIGNAL_DETECT_ON            (0x04U)    /* detect KR2 signal */
/* Key interrupt mode control (KRM01) */
#define _00_KR1_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR1 signal */
#define _02_KR1_SIGNAL_DETECT_ON            (0x02U)    /* detect KR1 signal */
/* Key interrupt mode control (KRM00) */
#define _00_KR0_SIGNAL_DETECT_OFF           (0x00U)    /* does not detect KR0 signal */
#define _01_KR0_SIGNAL_DETECT_ON            (0x01U)    /* detect KR0 signal */

/*
    Key Return Flag Register (KRF)
*/
/* Key interrupt flag (KRF7) */
#define _00_KR7_DETECT_FLAG_OFF             (0x00U)    /* no KR7 signal has been detected */
#define _80_KR7_DETECT_FLAG_ON              (0x80U)    /* KR7 signal has been detected */
/* Key interrupt flag (KRF6) */
#define _00_KR6_DETECT_FLAG_OFF             (0x00U)    /* no KR6 signal has been detected */
#define _40_KR6_DETECT_FLAG_ON              (0x40U)    /* KR6 signal has been detected */
/* Key interrupt flag (KRF5) */
#define _00_KR5_DETECT_FLAG_OFF             (0x00U)    /* no KR5 signal has been detected */
#define _20_KR5_DETECT_FLAG_ON              (0x20U)    /* KR5 signal has been detected */
/* Key interrupt flag (KRF4) */
#define _00_KR4_DETECT_FLAG_OFF             (0x00U)    /* no KR4 signal has been detected */
#define _10_KR4_DETECT_FLAG_ON              (0x10U)    /* KR4 signal has been detected */
/* Key interrupt flag (KRF3) */
#define _00_KR3_DETECT_FLAG_OFF             (0x00U)    /* no KR3 signal has been detected */
#define _08_KR3_DETECT_FLAG_ON              (0x08U)    /* KR3 signal has been detected */
/* Key interrupt flag (KRF2) */
#define _00_KR2_DETECT_FLAG_OFF             (0x00U)    /* no KR2 signal has been detected */
#define _04_KR2_DETECT_FLAG_ON              (0x04U)    /* KR2 signal has been detected */
/* Key interrupt flag (KRF1) */
#define _00_KR1_DETECT_FLAG_OFF             (0x00U)    /* no KR1 signal has been detected */
#define _02_KR1_DETECT_FLAG_ON              (0x02U)    /* KR1 signal has been detected */
/* Key interrupt flag (KRF0) */
#define _00_KR0_DETECT_FLAG_OFF             (0x00U)    /* no KR0 signal has been detected */
#define _01_KR0_DETECT_FLAG_ON              (0x01U)    /* KR0 signal has been detected */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

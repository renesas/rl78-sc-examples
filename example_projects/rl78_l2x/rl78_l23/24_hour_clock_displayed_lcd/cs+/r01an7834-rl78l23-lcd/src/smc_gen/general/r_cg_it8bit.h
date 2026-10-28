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
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_it8bit.h
* Version          : 1.0.41
* Device(s)        : R7F100LPLxFA
* Description      : General header file for IT8BIT peripheral.
***********************************************************************************************************************/

#ifndef IT8BIT_H
#define IT8BIT_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    8-bit Interval Timer Control Register n (TRTCRn)
*/
/* Mode select(TCSMDn) */
#define _00_IT8BIT_8BIT_COUNT_MODE           (0x00U)    /* operates as 8-bit counter */
#define _80_IT8BIT_16BIT_COUNT_MODE          (0x80U)    /* operates as 16-bit counter */
/* 8-bit interval timer clock enable (TCLKENn) */
#define _00_IT8BIT_CLOCK_STOP                (0x00U)    /* clock operation stopped */
#define _10_IT8BIT_CLOCK_SUPPLY              (0x10U)    /* clock operation supplied */
/* 8-bit interval timer 1 count start (TSTARTn1) */
#define _00_IT8BIT_COUNT1_STOP               (0x00U)    /* counting stops */
#define _04_IT8BIT_COUNT1_START              (0x04U)    /* counting starts */
/* 8-bit interval timer 0 count start (TSTARTn0) */
#define _00_IT8BIT_COUNT0_STOP               (0x00U)    /* counting stops */
#define _01_IT8BIT_COUNT0_START              (0x01U)    /* counting starts */

/*
    8-bit interval timer division register n (TRTMDn)
*/
/* 8-bit interval timer 1 division select (TCKn1) */
#define _00_IT8BIT_CLOCK1_1                  (0x00U)    /* fSXP or fIL */
#define _10_IT8BIT_CLOCK1_2                  (0x10U)    /* fSXP/2 or fIL/2 */
#define _20_IT8BIT_CLOCK1_4                  (0x20U)    /* fSXP/4 or fIL/4 */
#define _30_IT8BIT_CLOCK1_8                  (0x30U)    /* fSXP/8 or fIL/8 */
#define _40_IT8BIT_CLOCK1_16                 (0x40U)    /* fSXP/16 or fIL/16 */
#define _50_IT8BIT_CLOCK1_32                 (0x50U)    /* fSXP/32 or fIL/32 */
#define _60_IT8BIT_CLOCK1_64                 (0x60U)    /* fSXP/64 or fIL/64 */
#define _70_IT8BIT_CLOCK1_128                (0x70U)    /* fSXP/128 or fIL/128 */
#define _70_IT8BIT_CLOCK1_CLEAR              (0x70U)    /* clear timer 1 frequency */
/* 8-bit interval timer 0 division select (TCKn0) */
#define _00_IT8BIT_CLOCK0_1                  (0x00U)    /* fSXP or fIL */
#define _01_IT8BIT_CLOCK0_2                  (0x01U)    /* fSXP/2 or fIL/2 */
#define _02_IT8BIT_CLOCK0_4                  (0x02U)    /* fSXP/4 or fIL/4 */
#define _03_IT8BIT_CLOCK0_8                  (0x03U)    /* fSXP/8 or fIL/8 */
#define _04_IT8BIT_CLOCK0_16                 (0x04U)    /* fSXP/16 or fIL/16 */
#define _05_IT8BIT_CLOCK0_32                 (0x05U)    /* fSXP/32 or fIL/32 */
#define _06_IT8BIT_CLOCK0_64                 (0x06U)    /* fSXP/64 or fIL/64 */
#define _07_IT8BIT_CLOCK0_128                (0x07U)    /* fSXP/128 or fIL/128 */
#define _07_IT8BIT_CLOCK0_CLEAR              (0x07U)    /* clear timer 0 frequency */

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

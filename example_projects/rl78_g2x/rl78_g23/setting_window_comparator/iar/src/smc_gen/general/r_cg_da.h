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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_cg_da.h
* Version      : 1.0.1
* Device(s)    : R7F100GLGxFA
* Description  : General header file for DAC peripheral.
* Creation Date: 2021-06-11
***********************************************************************************************************************/

#ifndef DAC_H
#define DAC_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 1 (PER1)
*/
/* Control of D/A converter input clock (DACEN) */
#define _00_DA_CLOCK_STOP               (0x00U)    /* stop supply of input clock */
#define _80_DA_CLOCK_SUPPLY             (0x80U)    /* supplies input clock */

/*
    Peripheral Reset Control Register 1 (PRR1)
*/
/* Control resetting of the D/A converter (DACRES) */
#define _00_DA_RESET_RELEASE            (0x00U)    /* release reset of DA converter */
#define _80_DA_RESET_RESET              (0x80U)    /* DA converter is in reset state */

/*
    D/A Conversion Mode Register (DAM)
*/
/* D/A conversion operation (DACE1) */
#define _00_DA1_CONVERSION_STOP         (0x00U)    /* stop conversion operation */
#define _20_DA1_CONVERSION_ENABLE       (0x20U)    /* enable conversion operation */
/* D/A conversion operation (DACE0) */
#define _00_DA0_CONVERSION_STOP         (0x00U)    /* stop conversion operation */
#define _10_DA0_CONVERSION_ENABLE       (0x10U)    /* enable conversion operation */
/* D/A converter operation mode (DAMD1) */
#define _00_DA1_CONVERSION_MODE_NORMAL  (0x00U)    /* normal mode */
#define _02_DA1_CONVERSION_MODE_RTO     (0x02U)    /* real-time output mode */
/* D/A converter operation mode (DAMD0) */
#define _00_DA0_CONVERSION_MODE_NORMAL  (0x00U)    /* normal mode */
#define _01_DA0_CONVERSION_MODE_RTO     (0x01U)    /* real-time output mode */

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

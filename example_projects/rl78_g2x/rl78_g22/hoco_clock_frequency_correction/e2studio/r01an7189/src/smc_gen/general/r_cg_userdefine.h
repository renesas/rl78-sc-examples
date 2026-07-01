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
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_userdefine.h
* Version          : 1.0.20
* Device(s)        : R7F102GGExFB
* Description      : User header file for code generation.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

#ifndef USER_DEF_H
#define USER_DEF_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/* Start user code for register. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Start user code for macro define. Do not edit comment generated here */

/* Ideal range (calibration is unnecessary) is
    from 32MHz +0.1% to 32MHz -0.1% -> from 31.968MHz to 32.032MHz */
/* Ideal of counter value during of 30.517578125us(32.768kHz) is 976.5625 */
/* -> When count 4 times, ideal of counter value is 3906.25 */
/* Maximum */
/* (30.517578125us / (1 / 32.032MHz)) * 4 = 3910.15625 -> come near 3910 */
#define     CCNT_XT1_MAX    (3910U)
/* Minimum */
/* (30.517578125us / (1 / 31.968MHz)) * 4 = 3902.34375 -> come near 3902 */
#define     CCNT_XT1_MIN    (3902U)

/* Ideal of counter value during of 1.953125ms is 62500 */
/* Maximum *//* 1.953125ms / (1 / 32.032MHz) = 62562.5 -> come near 62562 */
#define     CCNT_EXT_MAX    (62562U)
/* Minimum *//* 1.953125ms / (1 / 31.968MHz) = 62437.5 -> come near 62437 */
#define     CCNT_EXT_MIN    (62437U)

#define     HIOTRM_MAX      (0b00111111)    /* HIOTRM Maximum speed */
#define     HIOTRM_MIN      (0b00000000)    /* HIOTRM Minimum speed */

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
/* Start user code for type define. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

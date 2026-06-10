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
* File Name        : Config_TRD0_TRD1.h
* Component Version: 1.2.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0_TRD1.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_trd.h"

#ifndef CFG_Config_TRD0_TRD1_H
#define CFG_Config_TRD0_TRD1_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* TMRD register C0 (TRDGRC0) */
#define _149E_TRD_TRDGRC0_VALUE                    (0x149EU)
/* TMRD register A0 (TRDGRA0) */
#define _149E_TRD_TRDGRA0_VALUE                    (0x149EU)
/* TMRD register D0 (TRDGRD0) */
#define _095F_TRD_TRDGRD0_VALUE                    (0x095FU)
/* TMRD register B0 (TRDGRB0) */
#define _095F_TRD_TRDGRB0_VALUE                    (0x095FU)
/* TMRD register A1 (TRDGRA1) */
#define _095F_TRD_TRDGRA1_VALUE                    (0x095FU)
/* TMRD register B1 (TRDGRB1) */
#define _095F_TRD_TRDGRB1_VALUE                    (0x095FU)
/* TMRD register C1 (TRDGRC1) */
#define _095F_TRD_TRDGRC1_VALUE                    (0x095FU)
/* TMRD register D1 (TRDGRD1) */
#define _095F_TRD_TRDGRD1_VALUE                    (0x095FU)
/* TMRD counter register 0 (TRD0) */
#define _01E0_TRD_TRD0_VALUE                       (0x01E0U)
/* TMRD A/D trigger compare register 0 (TRDADTC0) */
#define _0000_TRD_TRDADTC0_VALUE                   (0x0000U)
/* TMRD A/D trigger buffer register 0 (TRDADTB0) */
#define _0000_TRD_TRDADTB0_VALUE                   (0x0000U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef struct {
    uint16_t trdgrd0;
    uint16_t trdcmpd0;
    uint16_t trdgrc1;
    uint16_t trdcmpc1;
    uint16_t trdgrd1;
    uint16_t trdcmpd1;
    uint16_t trdadtb0;
} st_extcompwm_buffer_registers_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Create (void);
void R_Config_TRD0_TRD1_Start (void);
void R_Config_TRD0_TRD1_Stop (void);
MD_STATUS R_Config_TRD0_TRD1_Set_TRD_ReloadTrigger (st_extcompwm_buffer_registers_t * buffer);
void R_Config_TRD0_TRD1_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
extern uint8_t g_sampling_flg;

/* End user code. Do not edit comment generated here */
#endif


/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_sau_common.h
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
* Description      : Common header file for SAU peripheral.
***********************************************************************************************************************/

#ifndef SAU_COMMON_H
#define SAU_COMMON_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_SAU0_Create (void);
void R_SAU1_Create (void);
void R_SAU0_Set_PowerOn (void);
void R_SAU0_Set_PowerOff (void);
void R_SAU1_Set_PowerOn (void);
void R_SAU1_Set_PowerOff (void);
void R_SAU0_Set_Reset (void);
void R_SAU0_Release_Reset (void);
void R_SAU1_Set_Reset (void);
void R_SAU1_Release_Reset (void);
void R_SAU0_Set_SnoozeOn (void);
void R_SAU0_Set_SnoozeOff (void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

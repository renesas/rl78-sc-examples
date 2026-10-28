/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : UARTA0.h
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for UARTA0.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_uarta.h"

#ifndef CFG_UARTA0_H
#define CFG_UARTA0_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _8B_UARTA_OUTPUT_BAUDRATE             (0x8BU)
#define UARTA0_WAIT_1_CLOCK_CYCLE             (1U)    /* wait for 1 cycle as default,
                                                         please change the waiting time value according to the system */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_UARTA0_Create (void);
void R_UARTA0_Start (void);
void R_UARTA0_Stop (void);
MD_STATUS R_UARTA0_Send (uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_UARTA0_Receive (uint8_t * const rx_buf, uint16_t rx_num);
void R_UARTA0_Loopback_Enable (void);
void R_UARTA0_Loopback_Disable (void);
void R_UARTA0_PollingEnd_UserCode (void);
void R_UARTA0_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

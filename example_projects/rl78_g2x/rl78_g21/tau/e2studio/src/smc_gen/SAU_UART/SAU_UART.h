/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_UART.h
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for SAU_UART.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_sau.h"

#ifndef CFG_SAU_UART_H
#define CFG_SAU_UART_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define _4400_SAU0_CH0_TRANSMIT_DIVISOR    (0x4400U)
#define _4400_SAU0_CH1_RECEIVE_DIVISOR     (0x4400U)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_SAU_UART_Create (void);
void R_SAU_UART_Start (void);
void R_SAU_UART_Stop (void);
MD_STATUS R_SAU_UART_Send (uint8_t * const tx_buf, uint16_t tx_num);
MD_STATUS R_SAU_UART_Receive (uint8_t * const rx_buf, uint16_t rx_num);
void R_SAU_UART_Loopback_Enable (void);
void R_SAU_UART_Loopback_Disable (void);
void R_SAU_UART_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

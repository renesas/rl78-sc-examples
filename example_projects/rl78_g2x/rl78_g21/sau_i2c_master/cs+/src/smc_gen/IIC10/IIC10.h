/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : IIC10.h
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for IIC10.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_sau.h"

#ifndef CFG_IIC10_H
#define CFG_IIC10_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

#define _9E00_IIC10_DIVISOR                (0x9E00U)
#define IIC10_WAITTIME                     (13U)    /* wait for 5us as default,
                                                       please change the waiting time value according to the system */
#define IIC10_WAITTIME_2                   (53U)    /* wait for 20us as default,
                                                       please change the waiting time value according to the system */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void R_IIC10_Create (void);
void R_IIC10_Stop (void);
void R_IIC10_StartCondition (void);
void R_IIC10_StopCondition (void);
void R_IIC10_Master_Send (uint8_t adr, uint8_t * const tx_buf, uint16_t tx_num);
void R_IIC10_Master_Receive (uint8_t adr, uint8_t * const rx_buf, uint16_t rx_num);
void R_IIC10_Create_UserInit (void);
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif


/*
* Copyright (c) 2021 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_rtos.h
* Description  : This module implements functions of rtos.
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 22.04.2021 1.00     First Release
*         : 04.07.2025 1.92     Changed the disclaimer.
*         : 19.12.2025 2.00     Added inclusion of header files for FreeRTOS.
**********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "r_bsp_config.h"

#if BSP_CFG_RTOS_USED == 0      /* Non-OS */
#elif BSP_CFG_RTOS_USED == 1    /* FreeRTOS */
#include "FreeRTOS.h"
#include "task.h"
#include "semphr.h"
#include "queue.h"
#include "croutine.h"
#include "timers.h"
#include "event_groups.h"
#elif BSP_CFG_RTOS_USED == 2    /* SEGGER embOS(This is not available.) */
#elif BSP_CFG_RTOS_USED == 3    /* Micrium MicroC/OS(This is not available.) */
#elif BSP_CFG_RTOS_USED == 4    /* Renesas RI78V4 */
#ifndef __CCRL__ 
#error "The RI78V4 supports CC-RL compiler only."
#endif
#include "kernel.h"
#include "kernel_id.h"
#else
#endif

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Multiple inclusion prevention macro */
#ifndef R_RTOS_H
#define R_RTOS_H

#endif  /* R_RTOS_H */


/*
* Copyright (c) 2021 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_bsp_init.c
* H/W Platform : GENERIC_RL78_G23
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 04.08.2021 1.12     Added prototype declaration to suppress LLVM compiler warning messages.
*         : 06.08.2025 1.92     Changed the disclaimer.
*                               Changed to set only valid bits of BSP_CFG_PIORx.
*         : 09.01.2026 2.00     Added PIOR setting process for 104G.
***********************************************************************************************************************/
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/

/*************************************************
 * External function Prototypes
 *************************************************/

#if BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED != 0
/* If user is requesting warm start callback functions then these are the prototypes. */
void BSP_CFG_USER_WARM_START_PRE_C_FUNCTION (void);
#endif

#if BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED != 0
/* If user is requesting warm start callback functions then these are the prototypes. */
void BSP_CFG_USER_WARM_START_POST_C_FUNCTION (void);
#endif

#if BSP_CFG_WDT_REFRESH_ENABLE == 2
/* If user is requesting Watchdog Timer callback functions then these are the prototypes. */
void BSP_CFG_USER_WDT_REFRESH_INIT_FUNCTION (void);
#endif

/* This prototype is used to suppress the warning message of LLVM compiler. */
void bsp_init_system (void);

/* This prototype is used to suppress the warning message of LLVM compiler. */
void bsp_init_hardware (void);

/*************************************************
 * Private global variables and functions
 *************************************************/

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: bsp_init_system
 * Description  : BSP initial setting(clock)
 * Arguments    : none
 * Return value : none
**************************************************/
void bsp_init_system(void)
{
    /* Pin setting */
#if BSP_CFG_MCU_PART_G23_GROUP == 0
    /* RL78/G23 group = 100G */
#if BSP_CFG_MCU_PART_PIN_NUM < 5
    /* 44,40,36,32,30-pin */
    PIOR = BSP_CFG_PIOR0 | (BSP_CFG_PIOR1 << 1U) | (BSP_CFG_PIOR2 << 2U);
#elif BSP_CFG_MCU_PART_PIN_NUM < 7
    /* 52,48-pin */
    PIOR = BSP_CFG_PIOR0 | (BSP_CFG_PIOR1 << 1U) | (BSP_CFG_PIOR2 << 2U) |
        (BSP_CFG_PIOR3 << 3U);
#elif BSP_CFG_MCU_PART_PIN_NUM < 9
    /* 80,64-pin */
    PIOR = BSP_CFG_PIOR0 | (BSP_CFG_PIOR1 << 1U) | (BSP_CFG_PIOR2 << 2U) |
        (BSP_CFG_PIOR3 << 3U) | (BSP_CFG_PIOR4 << 4U);
#else
    /* 128,100-pin */
    PIOR = BSP_CFG_PIOR0 | (BSP_CFG_PIOR1 << 1U) | (BSP_CFG_PIOR2 << 2U) |
        (BSP_CFG_PIOR3 << 3U) | (BSP_CFG_PIOR4 << 4U) | (BSP_CFG_PIOR5 << 5U);
#endif
#else
    /* RL78/G23 group = 104G */
    /* 48,44,32-pin */
    PIOR = BSP_CFG_PIOR0 | (BSP_CFG_PIOR1 << 1U) | (BSP_CFG_PIOR2 << 2U) |
        (BSP_CFG_PIOR3 << 3U) | (BSP_CFG_PIOR4 << 4U);
#endif

    /* If the window open period of watchdog timer is set to 50%, then call it. */
#if BSP_CFG_WDT_REFRESH_ENABLE == 2
    BSP_CFG_USER_WDT_REFRESH_INIT_FUNCTION();
#endif

    /* Clock initialization */
#if BSP_CFG_STARTUP_DISABLE == 0
    mcu_clock_setup();
#endif

    /* If the warm start Pre C runtime callback is enabled, then call it. */
#if BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED == 1
    BSP_CFG_USER_WARM_START_PRE_C_FUNCTION();
#endif
} /* End of function bsp_init_system() */

/*************************************************
 * Function name: bsp_init_hardware
 * Description  : BSP initial setting(Peripheral functions)
 * Arguments    : none
 * Return value : none
**************************************************/
void bsp_init_hardware(void)
{
    /* If the warm start Post C runtime callback is enabled, the call it. */
#if BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED == 1
    BSP_CFG_USER_WARM_START_POST_C_FUNCTION();
#endif

    /* Peripheral function initialization */
    hdwinit();
} /* End of function bsp_init_hardware() */


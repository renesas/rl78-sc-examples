/* Generated configuration header file - do not edit */
/*
* Copyright (c) 2021 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef TOUCH_CONFIG_HEADER_FILE
#define TOUCH_CONFIG_HEADER_FILE


/***********************************************************************************************************************
 Configuration Options
 ***********************************************************************************************************************/
/* SPECIFY WHETHER TO INCLUDE CODE FOR API PARAMETER CHECKING
 * Setting to BSP_CFG_PARAM_CHECKING_ENABLE utilizes the system default setting
 * Setting to 1 includes parameter checking; 0 compiles out parameter checking
 */
#define TOUCH_CFG_PARAM_CHECKING_ENABLE   (BSP_CFG_PARAM_CHECKING_ENABLE)

/* For QE monitor with emulator, set this to 0. For QE monitor with UART, set this to 1 */
#define TOUCH_CFG_UART_MONITOR_SUPPORT    (0)

/* For QE tuning with emulator, set this to 0. For QE tuning with UART, set this to 1 */
#define TOUCH_CFG_UART_TUNING_SUPPORT     (0)

/* For QE monitor with UART channel */
#define TOUCH_CFG_UART_NUMBER             (0)

/* The following configurations are set according to the touch interface configuration, 
 * so they are not set in Smart Configurator.
 * Set when using QE for Capacitive Touch. In that case, QE_TOUCH_CONFIGURATION is defined in the project,
 * the definition in rm_touch_config.h is invalid, and instead it is defined in qe_touch_define.h.
 */
#ifndef QE_TOUCH_CONFIGURATION
#define TOUCH_CFG_NUM_BUTTONS             (1)
#define TOUCH_CFG_NUM_SLIDERS             (0)
#define TOUCH_CFG_NUM_WHEELS              (0)
#endif

#define TOUCH_CFG_CHATTERING_SUPPRESSION_TYPE (0)

#endif /* TOUCH_CONFIG_HEADER_FILE */

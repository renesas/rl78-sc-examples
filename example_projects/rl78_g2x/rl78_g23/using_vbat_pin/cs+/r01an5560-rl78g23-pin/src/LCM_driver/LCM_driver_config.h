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
/**********************************************************************************************************************
 * @file         LCM_driver_config.h
 * @version      1.00
 * @description  A header of a user configuration for an LCM(ZETTLER DISPLAYS).
 *               Created on: 9 June 2020
 *               Author: rigel
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 09.06.2020 1.00     First Release
 *********************************************************************************************************************/

#ifndef LCM_DRIVER_CONFIG_H
#define LCM_DRIVER_CONFIG_H

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
/* Parameters for command execution wait time */
#define LCM_COMMAND_EXEC_WAIT                           (26600) /* Wait 5ms at 32MHz operation */
 
/* Parameters for function set */
#define LCM_CONFIG_FUNCTION_SET_PARAMS                  (_0x10_LCM_COMMAND_FUNCTION_SET_DL_HIGH | \
                                                         _0x08_LCM_COMMAND_FUNCTION_SET_N_HIGH | \
                                                         _0x00_LCM_COMMAND_FUNCTION_SET_F_LOW)
/* Parameters for entry mode set */
#define LCM_CONFIG_ENTRY_MODE_SET_PARAMS                (_0x02_LCM_COMMAND_ENTRY_MODE_SET_ID_HIGH | \
                                                         _0x00_LCM_COMMAND_ENTRY_MODE_SET_S_LOW)
/* Parameters for display ON/OFF */
#define LCM_CONFIG_DISPLAY_ONOFF_PARAMS                 (_0x04_LCM_COMMAND_DISPLAY_ONOFF_D_HIGH | \
                                                         _0x00_LCM_COMMAND_DISPLAY_ONOFF_C_LOW | \
                                                         _0x00_LCM_COMMAND_DISPLAY_ONOFF_B_LOW)

/* A max characters per line */
#define LCM_CONFIG_MAX_CHAR_PER_LINE                    (16)

/* A wait time before sending */
#define LCM_CONFIG_WAIT_COUNT                           (13U)    /* This value references Config_IIC00.h */

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
/* Expecting errors or warnings for uncommented typdefs, structs, enums */

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/

#endif

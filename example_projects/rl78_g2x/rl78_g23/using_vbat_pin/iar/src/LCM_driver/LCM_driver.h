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
 * @file         LCM_driver.h
 * @version      1.00
 * @description  A header of a device driver for an LCM(ZETTLER DISPLAYS).
 *               Created on: 9 June 2020
 *               Author: rigel
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 09.06.2020 1.00     First Release
 *********************************************************************************************************************/

#ifndef LCM_DRIVER_H
#define LCM_DRIVER_H

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "LCM_driver_config.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
/* An IIC address for LCM commands */
#define _0xA0_LCM_SLAVE_ADDR                                       (0xA0)
#define _0x01_LCM_SLAVE_ADDR_RW_HIGH                               (0x01) /* to read data */
#define _0x00_LCM_SLAVE_ADDR_RW_LOW                                (0x00) /* to write data */

/* A control byte for LCM commands */
#define _0x00_LCM_CONTROL_BYTE                                     (0x00U)
#define _0x80_LCM_CONTROL_BYTE_RS_HIGH                             (0x80U) /* to transfer data */
#define _0x00_LCM_CONTROL_BYTE_RS_LOW                              (0x00U) /* to transfer command */

/* An LCM command set for writing a state (RS=0, R/W=0) */
#define _0x00_LCM_COMMAND_CLEAR_DISPLAY                            (0x00U)

#define _0x02_LCM_COMMAND_RETURN_HOME                              (0x02U)

#define _0x04_LCM_COMMAND_ENTRY_MODE_SET                           (0x04U)
#define _0x02_LCM_COMMAND_ENTRY_MODE_SET_ID_HIGH                   (0x02U)     /* increment of DDRAM address */
#define _0x00_LCM_COMMAND_ENTRY_MODE_SET_ID_LOW                    (0x00U)     /* decrement of DDRAM address */
#define _0x01_LCM_COMMAND_ENTRY_MODE_SET_S_HIGH                    (0x01U)     /* shift of display ON */
#define _0x00_LCM_COMMAND_ENTRY_MODE_SET_S_LOW                     (0x00U)     /* shift of display OFF */

#define _0x08_LCM_COMMAND_DISPLAY_ONOFF                            (0x08U)
#define _0x04_LCM_COMMAND_DISPLAY_ONOFF_D_HIGH                     (0x04U)     /* display ON */
#define _0x00_LCM_COMMAND_DISPLAY_ONOFF_D_LOW                      (0x00U)     /* display OFF */
#define _0x02_LCM_COMMAND_DISPLAY_ONOFF_C_HIGH                     (0x02U)     /* cursor ON */
#define _0x00_LCM_COMMAND_DISPLAY_ONOFF_C_LOW                      (0x00U)     /* cursor OFF */
#define _0x01_LCM_COMMAND_DISPLAY_ONOFF_B_HIGH                     (0x01U)     /* cursor blink ON */
#define _0x00_LCM_COMMAND_DISPLAY_ONOFF_B_LOW                      (0x00U)     /* cursor blink OFF */

#define _0x10_LCM_COMMAND_CURSOR_OR_DISPLAY_SHIFT                  (0x10U)
#define _0x08_LCM_COMMAND_CURSOR_OR_DISPLAY_SHIFT_SC_HIGH          (0x08U)    /* auto-shift of display */
#define _0x00_LCM_COMMAND_CURSOR_OR_DISPLAY_SHIFT_SC_LOW           (0x00U)    /* auto-shift of cursor */
#define _0x04_LCM_COMMAND_CURSOR_OR_DISPLAY_SHIFT_RL_HIGH          (0x04U)    /* auto-shift to the right */
#define _0x00_LCM_COMMAND_CURSOR_OR_DISPLAY_SHIFT_RL_LOW           (0x00U)    /* auto-shift to the left */

#define _0x20_LCM_COMMAND_FUNCTION_SET                             (0x20U)
#define _0x10_LCM_COMMAND_FUNCTION_SET_DL_HIGH                     (0x10U)    /* use 8-bit bus */
#define _0x00_LCM_COMMAND_FUNCTION_SET_DL_LOW                      (0x00U)    /* use 4-bit bus */
#define _0x08_LCM_COMMAND_FUNCTION_SET_N_HIGH                      (0x08U)    /* use 2-line display */
#define _0x00_LCM_COMMAND_FUNCTION_SET_N_LOW                       (0x00U)    /* use 1-line display */
#define _0x04_LCM_COMMAND_FUNCTION_SET_F_HIGH                      (0x04U)    /* use 5x11-dots font */
#define _0x00_LCM_COMMAND_FUNCTION_SET_F_LOW                       (0x00U)    /* use 5x8 dots font */

#define _0x40_LCM_COMMAND_SET_CGRAM_ADDRESS                        (0x40U)
#define _0x3F_LCM_COMMAND_SET_CGRAM_ADDRESS_AC_MASK                (0x3FU)    /* CGRAM address */

#define _0x80_LCM_COMMAND_SET_DDRAM_ADDRESS                        (0x80U)
#define _0x7F_LCM_COMMAND_SET_DDRAM_ADDRESS_AC_MASK                (0x7FU)    /* DDRAM address */

/* An LCM format for reading a state (RS=0, R/W=1) */
#define _0x80_LCM_FORMAT_READ_BUSY_FLAG_AND_ADDRESS_BF_MASK        (0x80U)    /* busy flag bit */
#define _0x7F_LCM_FORMAT_READ_BUSY_FLAG_AND_ADDRESS_AC_MASK        (0x7FU)    /* address counter bits */

/* An LCM format for writing data (RS=1, R/W=0) */
#define _0xFF_LCM_FORMAT_WRITE_DATA_TO_RAM_D_MASK                  (0xFFU)    /* data bits */

/* An LCM format for reading data (RS=1, R/W=1) */
#define _0xFF_LCM_FORMAT_READ_DATA_FROM_RAM_D_MASK                  (0xFFU)   /* data bits */

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
/* Expecting errors or warnings for uncommented typdefs, structs, enums */

/* A display position for an LCM(2-lines) */
typedef enum {
    LCM_POSITION_TOP    = 0x00U,     /* The left at the top line */
    LCM_POSITION_BOTTOM = 0x40U,     /* The left at the bottom line */
} lcm_position_t;

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
void r_LCM_init(void);
void r_LCM_clear(void);
void r_LCM_send_string(uint8_t * const str, lcm_position_t pos);
void r_LCM_send_command(uint8_t command);
void r_LCM_send_data(uint8_t data);
void r_LCM_turn_sendend_on(void);
#endif

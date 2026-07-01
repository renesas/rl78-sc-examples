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
 * @file         LCM_driver.c
 * @version      1.00
 * @description  An implementation of a device driver for an LCM(ZETTLER DISPLAYS).
 *               Created on: 16 June 2020
 *               Author: rigel
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 22.08.2020 1.00     First Release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "LCM_driver.h"
#include "Config_IICA0.h"          /* Chage this line and function names if other IIC is used. */

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Typedef definitions
 *********************************************************************************************************************/
/* Expecting errors or warnings for uncommented typdefs, structs, enums */

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/
static uint8_t g_LCM_is_sendend = 0U;

static void r_LCM_wait_sendend(void);

/**********************************************************************************************************************
 * Function Name: r_LCM_init
 ******************************************************************************************************************//**
 * @brief Initialize an LCM.
 * @param none
 * @return none
 */
void r_LCM_init(void)
{
    r_LCM_send_command(_0x20_LCM_COMMAND_FUNCTION_SET | LCM_CONFIG_FUNCTION_SET_PARAMS);
    r_LCM_send_command(_0x08_LCM_COMMAND_DISPLAY_ONOFF | LCM_CONFIG_DISPLAY_ONOFF_PARAMS);
    r_LCM_send_command(_0x04_LCM_COMMAND_ENTRY_MODE_SET | LCM_CONFIG_ENTRY_MODE_SET_PARAMS);

   g_LCM_is_sendend = 0U;     /* Clear the flag */
}
/**********************************************************************************************************************
 End of function r_LCM_init
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_clear
 ******************************************************************************************************************//**
 * @brief Clear the LCM display.
 * @param none
 * @return none
 */
void r_LCM_clear(void)
{
    r_LCM_send_command(_0x00_LCM_COMMAND_CLEAR_DISPLAY);
}
/**********************************************************************************************************************
 End of function r_LCM_clear
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_string
 ******************************************************************************************************************//**
 * @brief Send a string to the LCM.
 *        If the string length is more than LCM_MAX_CHAR_PER_LINE, the rest is not sent.
 * @param[in] str  A pointer to a string to send.
 * @param[in] pos  A display position of the string.
 * @return none
 */
void r_LCM_send_string(uint8_t * const str, lcm_position_t pos)
{
    int i;
    uint8_t *p;

    r_LCM_send_command(_0x80_LCM_COMMAND_SET_DDRAM_ADDRESS | pos);

    for (i = 0, p = str; *p != '\0'; i++, p++)
    {
        if (i >= LCM_CONFIG_MAX_CHAR_PER_LINE)
        {
           /* The string length reached the maximum. */
            break;
        }
        r_LCM_send_data(*p);
    }
}
/**********************************************************************************************************************
 End of function r_LCM_send_string
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_command
 ******************************************************************************************************************//**
 * @brief Send a command to the LCM.
 * @param[in] command  A one byte command to send.
 * @return none
 */
void r_LCM_send_command(uint8_t command)
{
    uint8_t tx_buffer[2] = { _0x00_LCM_CONTROL_BYTE_RS_LOW, 0x00U, };   /* A sequence to transfer. */

    tx_buffer[1] = command;

    /* R_Config_IICA0_Master_Send() includes seinding a start condition. */
    /* R_Config_IICA0_Master_Send() uses a callback that includes sending a stop condition. */
    R_Config_IICA0_Master_Send((_0xA0_LCM_SLAVE_ADDR | _0x00_LCM_SLAVE_ADDR_RW_LOW), 
                               tx_buffer, sizeof(tx_buffer)/sizeof(uint8_t), LCM_CONFIG_WAIT_COUNT);
    
    r_LCM_wait_sendend();
}
/**********************************************************************************************************************
 End of function r_LCM_send_command
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_send_data
 ******************************************************************************************************************//**
 * @brief Send data to the LCM.
 * @param[in] data  A one byte data to send.
 * @return none
 */
void r_LCM_send_data(uint8_t data)
{
    uint8_t tx_buffer[2] = { _0x80_LCM_CONTROL_BYTE_RS_HIGH, 0x00U, };  /* A sequence to transfer. */

    tx_buffer[1] = data;

    /* R_Config_IICA0_Master_Send() includes seinding a start condition. */
    /* R_Config_IICA0_Master_Send() uses a callback that includes sending a stop condition. */
    R_Config_IICA0_Master_Send((_0xA0_LCM_SLAVE_ADDR | _0x00_LCM_SLAVE_ADDR_RW_LOW),
                               tx_buffer, sizeof(tx_buffer)/sizeof(uint8_t), LCM_CONFIG_WAIT_COUNT);
    
    r_LCM_wait_sendend();
}
/**********************************************************************************************************************
 End of function r_LCM_send_data
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_turn_sendend_on
 ******************************************************************************************************************//**
 * @brief Turn a send-end flag on.
 * @param none
 * @return none
 */
void r_LCM_turn_sendend_on(void)
{
    g_LCM_is_sendend = 1U;
}
/**********************************************************************************************************************
 End of function r_LCM_sendend_on
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_LCM_wait_sendend
 ******************************************************************************************************************//**
 * @brief Wait until a send-end flag is on.
 * @param none
 * @return none
 */
static void r_LCM_wait_sendend(void)
{
    int i;
    while (! g_LCM_is_sendend)
    {
        NOP();
    }
    
    g_LCM_is_sendend = 0U;     /* Clear the flag */

    for (i=0;LCM_COMMAND_EXEC_WAIT>i;++i)
    {
        NOP();
    }
}
/**********************************************************************************************************************
 End of function r_LCM_wait_sendend
 *********************************************************************************************************************/

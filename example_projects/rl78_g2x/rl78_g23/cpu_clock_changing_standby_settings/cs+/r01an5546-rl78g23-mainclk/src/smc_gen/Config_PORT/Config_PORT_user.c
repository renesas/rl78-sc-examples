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
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_PORT_user.c
* Component Version: 1.4.0
* Device(s)        : R7F100GLGxFA
* Description      : This file implements device driver for Config_PORT.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_PORT.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
void r_port_bitmask_to_port(uint8_t mask, volatile unsigned char __near * port, r_config_port_mask_t flag);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_PORT_Create_UserInit
* Description  : This function adds user code after initializing the port.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_PORT_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name:r_port_set_LED
 ******************************************************************************************************************//**
 * @brief Set an LED state.
 * @param [in] state   The LEDs state. A bit[n] indicates whether LEDn is ON/OFF. 
 * @return none
 */
void r_port_set_LED(uint8_t state)
{
    r_config_port_mask_t mask_type;
    /* check the bit0(LED0/P03) */
    mask_type = (state & 0x1) ? R_CONFIG_PORT_POSITIVE_MASK : R_CONFIG_PORT_NEGATIVE_MASK;
    r_port_bitmask_to_port(0x08, &P0, mask_type);

    /* check the bit1(LED1/P02) */
    state >>= 1;
    mask_type = (state & 0x1) ? R_CONFIG_PORT_POSITIVE_MASK : R_CONFIG_PORT_NEGATIVE_MASK;
    r_port_bitmask_to_port(0x04, &P0, mask_type);

    /* check the bit2(LED3/P43) */
    state >>= 1;
    mask_type = (state & 0x1) ? R_CONFIG_PORT_POSITIVE_MASK : R_CONFIG_PORT_NEGATIVE_MASK;
    r_port_bitmask_to_port(0x08, &P4, mask_type);

    /* check the bit3(LED4/P42) */
    state >>= 1;
    mask_type = (state & 0x1) ? R_CONFIG_PORT_POSITIVE_MASK : R_CONFIG_PORT_NEGATIVE_MASK;
    r_port_bitmask_to_port(0x04, &P4, mask_type);

    /* check the bit4(LED5/P77) */
    state >>= 1;
    mask_type = (state & 0x1) ? R_CONFIG_PORT_POSITIVE_MASK : R_CONFIG_PORT_NEGATIVE_MASK;
    r_port_bitmask_to_port(0x80, &P7, mask_type);
}
/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: r_Config_bitmask_to_port
 ******************************************************************************************************************//**
 * @brief Execute bit-mask to a port.
 * @param [in] mask    A bit-mask to a port.
 *        [in] port    An address of a port register. This port shall be enabled.
 *        [in] flag    A positive mask or a negative mask.
 * @return none
 */
void r_port_bitmask_to_port(uint8_t mask, volatile unsigned char __near * port, r_config_port_mask_t flag)
{
    switch (flag)
    {
        case R_CONFIG_PORT_POSITIVE_MASK:
            *port |= mask;
            break;
        case R_CONFIG_PORT_NEGATIVE_MASK:
            *port &= ~mask;
            break;
        default:
            /* It shall not reach here. */
            break;
    }
}
/* End user code. Do not edit comment generated here */

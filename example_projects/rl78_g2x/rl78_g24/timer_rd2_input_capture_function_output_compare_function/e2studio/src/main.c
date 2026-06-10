/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2023 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : main.c
 * Version      : 1.00
 * Description  : Starts timer RD2 counter 0 and uses both input capture and output compare functions.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 26.06.2023 1.00     First Release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "r_smc_entry.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Local Typedef definitions
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function Name: main
 * Description  : main processing
 * Arguments    : none
 * Return Value : none
 *********************************************************************************************************************/
void main(void)
{
    g_capture_flg = 0x00U;    /* Initialize pulse width calculation completion flag */
    EI();                     /* Enable interrupt */
    R_Config_TRD0_Start();    /* Start TRD2 */

    while (1)
    {
        /* Waiting for pulse width calculation completion flag */

        if ((0x06U == g_capture_flg) || (0x07U == g_capture_flg))
        {
            /* Compare the results of the current and previous calculations. */
            if (g_tmrd0_active_width_a > g_tmrd0_inactive_width_a)
            {
                P6_bit.no2 = 0;           /* Turn on LED */
            }
            else
            {
                P6_bit.no2 = 1;           /* Turn off LED */
            }

            g_capture_flg &= (~0x07U);    /* Clear pulse width calculation completion flag */
        }
    }
}
/**********************************************************************************************************************
 * End of function main
 *********************************************************************************************************************/

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
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_IT00_user.c
* Component Version: 1.7.0
* Device(s)        : R7F100LPLxFB
* Description      : This file implements device driver for Config_IT00.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IT00.h"
/* Start user code for include. Do not edit comment generated here */
#include "Config_IT01.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_IT00_interrupt(vect=INTIT00)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
uint16_t g_interrupt_cnt = 0;
extern uint8_t g_watch_status;
extern uint8_t g_time_setting_flag;
extern uint8_t g_mode_change_flag;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_IT00_Create_UserInit
* Description  : This function adds user code after initializing the IT0 channel 0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_IT00_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_IT00_interrupt
* Description  : This function is INTIT00 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_IT00_interrupt(void)
{
    /* Start user code for r_Config_IT00_interrupt. Do not edit comment generated here */
    if (0 == P13_bit.no7)
    {
        if (LONG_PRESS_THRESHOLD > g_interrupt_cnt)
        {
            g_interrupt_cnt++;				/* Count the duration the switch is being pressed. */
        }
    }
    else
    {
        if (1 >= g_interrupt_cnt)
        {
            ;								/* Processing is not performed if the switch press duration is 10 ms or less. */
        }
        else if (LONG_PRESS_THRESHOLD > g_interrupt_cnt)
        {
            g_time_setting_flag = FLAG_SET;	/* If the switch is pressed for less than 1 second, treat it as a short press. */
        }
        else								/* If the switch is pressed for 1 second or more, treat it as a long press. */
        {
            if (++g_watch_status >= 3)		/* Change the mode. */
            {
                g_watch_status = WATCH_DISPLAY;
            }
            g_mode_change_flag = FLAG_SET;
        }
        g_interrupt_cnt = 0;
        R_Config_IT00_Stop();
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

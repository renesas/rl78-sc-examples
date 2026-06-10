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
 * Copyright (C) 2020-2022 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : Main.c
* Version      : 1.0.0
* Device(s)    : R7F100GLG(LQFP)
* Description  : Main Program.
* Creation Date: 2023-07-12
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
#include "r_cg_rtc.h"
#include "r_cg_iica.h"
/* Start user code for include. Do not edit comment generated here */
#include "Config_PORT.h"
#include "Config_RTC.h"
#include "r_cg_userdefine.h"

#include "LCM_driver/LCM_driver.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    /* Start user code. Do not edit comment generated here */
    {
        if (0U == PORF)
        {
            /* Initialize RTC only at Power-On-Reset. */
            R_Config_RTC_Create();
            r_rtc_init_current_time();
            r_rtc_init_alarm_time();
            PORF = 1U;
            R_Config_RTC_Start();
        }
        else
        {
            /* Setting for INTRTC. */
            /* Supplies input clock */
            RTCWEN = 1U;
            /* Set INTRTC Low priority */
            RTCPR1 = 1U;
            RTCPR0 = 1U;
            /* Clear INTRTC interrupt flag */
            RTCIF = 0U;
            /* Enable INTRTC interrupt */
            RTCMK = 0U;
        }

        EI();                              /* Enable the interrupts. */

        r_LCM_init();

        /* Wait an interrupt. */
        while (1U)
        {
            if (r_rtc_is_constperiod_flag_on())
            {
                RTCMK = 1U;
                r_rtc_display_current_time();
                r_rtc_clear_constperiod_flag();
                RTCMK = 0U;
            }
            else
            {
                ;
            }
        }
    }
    /* End user code. Do not edit comment generated here */
}


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
 * Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Main.c
* Version      : 1.0.0
* Device(s)    : R7F100GLG(LQFP)
* Description  : Main Program.
* Creation Date: 2020-08-17
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_lvd.h"
#include "r_cg_rtc.h"
#include "r_cg_iica.h"
#include "Config_LVD0.h"
#include "Config_RTC.h"
#include "Config_IICA0.h"
#include "LCM_driver.h"
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
void BCD_to_str(uint8_t BCD, uint8_t *str);
static void r_main_user_init(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    st_rtc_counter_value_t rtc_now;
    MD_STATUS status;
    uint8_t rtc_str[2][17];
    int i;
     
    r_main_user_init();

    while (1U)
    {
        if (r_is_vdd_over())
	{
            HALT();
	}
        if (r_is_vdd_over())
	{
	    do
	    {
	        status = R_Config_RTC_Get_CounterValue(&rtc_now);
	    } while (MD_OK != status);
	    BCD_to_str(rtc_now.year, &(rtc_str[0][0]));
	    rtc_str[0][2] = '/';
	    BCD_to_str(rtc_now.month, &(rtc_str[0][3]));
	    rtc_str[0][5] = '/';
	    BCD_to_str(rtc_now.day, &(rtc_str[0][6]));
	    for (i=8;16>i;++i)
	    {
                rtc_str[0][i] = ' ';
	    }
	    rtc_str[0][16] = '\0';

	    for (i=0;8>i;++i)
	    {
                rtc_str[1][i] = ' ';
	    }
	    BCD_to_str(rtc_now.hour, &(rtc_str[1][8]));
	    rtc_str[1][10] = ':';
	    BCD_to_str(rtc_now.min, &(rtc_str[1][11]));
	    rtc_str[1][13] = ':';
	    BCD_to_str(rtc_now.sec, &(rtc_str[1][14]));
	    rtc_str[1][16] = '\0';
	    r_LCM_send_string(rtc_str[0], LCM_POSITION_TOP);
	    r_LCM_send_string(rtc_str[1], LCM_POSITION_BOTTOM);
        }
	else
	{
	    r_LCM_clear();
            STOP();
        }
	
	if (r_is_vdd_over() && r_is_vdd_down())
	{
	    r_LCM_init();
	}
    }
}

/***********************************************************************************************************************
* Function Name: r_main_user_init
* Description  : This function adds user codes before the main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_main_user_init(void)
{
    EI();                              /* Enable the interrupts. */
    r_LCM_init();
    DI();                              /* Disable the interrupts. */  
    R_Config_RTC_Start();
    r_RTC_wait();
    EI();                              /* Enable the interrupts. */
}

/***********************************************************************************************************************
* Function Name: BCD_to_str
* Description  : This function Convert BCD to string.
* Arguments    : BCD -
*                    source BCD data
*                str -
*                    destination buffer
* Return Value : None
***********************************************************************************************************************/
void BCD_to_str(uint8_t BCD, uint8_t *str)
{
    if (NULL != str)
    {
        *str = 0x30U + ((BCD>>4)&0x0FU);
        *(str+1) = 0x30U + (BCD&0x0FU);
    }
}


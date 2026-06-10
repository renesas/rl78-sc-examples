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
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_RTC_user.c
* Component Version: 1.4.0
* Device(s)        : R7F100GLGxFA
* Description      : This file implements device driver for Config_RTC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_RTC.h"
/* Start user code for include. Do not edit comment generated here */
#include "LCM_driver.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_RTC_interrupt(vect=INTRTC)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static void convert_BCD_to_2chars(uint8_t bcd, uint8_t * const str);
static void convert_week_to_3chars(uint8_t week, uint8_t * const str);

static uint8_t g_rtc_constperiod = R_INTERRUPT_OFF;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_RTC_Create_UserInit
* Description  : This function adds user code after initializing the real-time clock.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_RTC_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    g_rtc_constperiod = R_INTERRUPT_OFF;
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RTC_callback_alarm
* Description  : This function is alarm interrupt service handler.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_RTC_callback_alarm(void)
{
    /* Start user code for r_Config_RTC_callback_alarm. Do not edit comment generated here */
    P5 &= 0xFBU;              /* Display that the alarm is excited on P52. */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RTC_callback_constperiod
* Description  : This function is real-time clock constant-period interrupt service handler.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_Config_RTC_callback_constperiod(void)
{
    /* Start user code for r_Config_RTC_callback_constperiod. Do not edit comment generated here */
    P5 ^= 0x08;               /* Invert an LED output every constant-period on P53. */
    if (R_INTERRUPT_ON == g_rtc_constperiod)
    {
        g_rtc_constperiod = R_INTERRUPT_OFF;
    }
    else
    {
        g_rtc_constperiod = R_INTERRUPT_ON;
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_RTC_interrupt
* Description  : This function is INTRTC interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_RTC_interrupt(void)
{
    if (1U == WAFG)
    {
        /* clear WAFG */
        RTCC1 &= (uint8_t)~_10_RTC_ALARM_MATCH;
        r_Config_RTC_callback_alarm();
    }
    if (1U == RIFG)
    {
        /* clear RIFG */
        RTCC1 &= (uint8_t)~_08_RTC_INTC_GENERATE_FLAG;
        r_Config_RTC_callback_constperiod();
    }
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: r_init_current_time
 ******************************************************************************************************************//**
 * @brief Initialize the current time.
 * @param none
 * @return none
 */
void r_rtc_init_current_time(void)
{
    /* This function does not use R_Config_RTC_Set_CounterValue(),
       because it always returns MD_BUSY1 until RTC is running. */
    {
        /* Initialize an RTC. */
        SUBCUD = 0x00;                /* The clock error corrections are NOT used. */

        /************************************/
        /* Set the Current time             */
        /************************************/
        SEC   = R_RTC_INIT_SEC;
        MIN   = R_RTC_INIT_MIN;
        HOUR  = R_RTC_INIT_HOUR;
        WEEK  = R_RTC_INIT_WEEK;
        DAY   = R_RTC_INIT_DAY;
        MONTH = R_RTC_INIT_MONTH;
        YEAR  = R_RTC_INIT_YEAR;
    }
}
/**********************************************************************************************************************
 * Function Name: r_init_alarm_time
 ******************************************************************************************************************//**
 * @brief Initialize the alarm time.
 * @param none
 * @return none
 */
void r_rtc_init_alarm_time(void)
{
    {
        st_rtc_alarm_value_t alarm_val;       /* Alarm time(temporary area) */

        /************************************/
        /* Set the Alarm time               */
        /************************************/
        alarm_val.alarmwm = R_RTC_ALARM_MIN;    /* A value for a Minute count. */
        alarm_val.alarmwh = R_RTC_ALARM_HOUR;   /* A value for a  Hour count. */
        alarm_val.alarmww = R_RTC_ALARM_WEEK;
      /*                    0b01111111;       A value for a Week count. [every day] 
                              |||||||+------- WW0 (An alarm on every Sunday)
                              |||||||            0:OFF
                              |||||||            1:ON
                              ||||||+-------- WW1 (An alarm on every Monday)
                              ||||||             0:OFF
                              ||||||             1:ON
                              |||||+--------- WW2 (An alarm on every Tuesday)
                              |||||             0:OFF
                              |||||             1:ON
                              ||||+---------- WW3 (An alarm on every Wednesday)
                              ||||              0:OFF
                              ||||              1:ON
                              |||+----------- WW4 (An alarm on every Thursday)
                              |||               0:OFF
                              |||               1:ON
                              ||+------------ WW5 (An alarm on every Friday)
                              ||                0:OFF
                              ||                1:ON
                              |+------------- WW6 (An alarm on every Saturday)
                              |                 0:OFF
                              |                 1:ON
                              +-------------- Be sure to set 0.
        */
        /* Set the alarm values. */
        R_Config_RTC_Set_AlarmValue(alarm_val);
    }
}
/**********************************************************************************************************************
 * Function Name: r_rtc_is_constperiod_flag_on
 ******************************************************************************************************************//**
 * @brief Check if a flag of constperiod-interrupt is on.
 * @param none
 * @return none
 */
uint8_t r_rtc_is_constperiod_flag_on(void)
{
    return (R_INTERRUPT_ON == g_rtc_constperiod);
}
/**********************************************************************************************************************
 * Function Name: r_rtc_clear_constperiod_flag
 ******************************************************************************************************************//**
 * @brief clear a flag of constperiod-interrupt.
 * @param none
 * @return none
 */
void r_rtc_clear_constperiod_flag(void)
{
    g_rtc_constperiod = R_INTERRUPT_OFF;
}
/**********************************************************************************************************************
 * Function Name: display_current_time
 ******************************************************************************************************************//**
 * @brief Display the current time on an LCD.
 * @param none
 * @return none
 */
void r_rtc_display_current_time(void)
{
    uint8_t string_time[13+1];        /* A string area for the time to display. */
    st_rtc_counter_value_t read_val;  /* Counter values read from RTC registers */

    while(MD_OK != R_Config_RTC_Get_CounterValue(&read_val))
    {
        ;
    }

    /* Show "YY/MM/DD(DOW)" on the top of LCD. */
    convert_BCD_to_2chars(read_val.year, &string_time[0]);
    string_time[2] = '/';
    convert_BCD_to_2chars(read_val.month, &string_time[3]);
    string_time[5] = '/';
    convert_BCD_to_2chars(read_val.day, &string_time[6]);
    string_time[8] = '(';
    convert_week_to_3chars(read_val.week, &string_time[9]);
    string_time[12] = ')';
    string_time[13] = '\0';
    r_LCM_send_string(string_time, LCM_POSITION_TOP);

    /* Show "hh:mm:ss" on the bottom of LCD. */
    convert_BCD_to_2chars(read_val.hour, &string_time[0]);
    string_time[2] = ':';
    convert_BCD_to_2chars(read_val.min, &string_time[3]);
    string_time[5] = ':';
    convert_BCD_to_2chars(read_val.sec, &string_time[6]);
    string_time[8] = '\0';
    r_LCM_send_string(string_time, LCM_POSITION_BOTTOM);
}
/**********************************************************************************************************************
 * Function Name: convert_BCD_to_2chars
 ******************************************************************************************************************//**
 * @brief Convert BCD to 2 characters.
 * @param[in] bcd     Two digits in BCD to convert. It shall be from 0x00 to 0x99.
 * @param[out] str  Two characters converted from bcd. 
 *                  It shall not be NULL. The result will not contain '\0'.
 * @return none
 */
static void convert_BCD_to_2chars(uint8_t bcd, uint8_t * const str)
{
    if (NULL == str)
    {
        return;
    }
    else
    {
        ;
    }

    *(str+0) = '0' + ((bcd>>4)&0xFU);
    *(str+1) = '0' + (bcd & 0xFU);
}
/**********************************************************************************************************************
 * Function Name: convert_week_to_3chars
 ******************************************************************************************************************//**
 * @brief Convert a week-value to 3 characters.
 * @param[in] week  A value as a day-of-week to convert. It shall be from 0 to 6.
 * @param[out] str   Three characters converted from the week. 
 *                   It shall not be NULL. The result will not contain '\0'.
 * @return none
 */
static void convert_week_to_3chars(uint8_t week, uint8_t * const str)
{
    static const uint8_t day_of_week[7][3+1] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat", };

    if (NULL == str)
    {
        return;
    }
    else
    {
        ;
    }

    week %= 7;
    *(str+0) = day_of_week[week][0];
    *(str+1) = day_of_week[week][1];
    *(str+2) = day_of_week[week][2];
}
/* End user code. Do not edit comment generated here */

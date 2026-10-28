/**********************************************************************************************************************
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : clock.c
 * Version      : 1.0
 * Description  : Clock demo program for RL78/L23.
 *********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 24.10.2025 1.10     First Release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include <stdint.h>
#include <stdbool.h>
#include "clock.h"

#include "r_smc_entry.h"
#include "platform.h"

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
extern volatile uint8_t g_rtc_interrupt_flag;     /* rtc interrupt user flag */

extern const uint8_t g_show_segdata[40][4];       /* Characters displayed on the LCD */
extern const uint8_t g_digit_segdata[8][4];       /* Number of display digits on the LCD */

uint8_t g_touch_button_flag = 0;                  /* Flag for enabling touch function */

static uint8_t s_lcd_seconds            = 0;      /* Store the seconds value of the clock */
static uint8_t s_lcd_minutes            = 0;      /* Store the minutes value of the clock */
static uint8_t s_lcd_hours              = 0;      /* Store the hours value of the clock */

static uint8_t * sp_time_address[3]     = {&s_lcd_seconds, &s_lcd_minutes, &s_lcd_hours};

static uint8_t s_unit                   = 0;      /* 0:seconds, 1:minutes, 2:hours */
static uint8_t s_clock_mode             = 0;      /* 0:clock mode, 1:time-setting mode */
static uint8_t s_blink_flag             = 0;      /* Flag for blinking display */
static uint8_t s_set_time_limit_count   = 0;      /* Flag for time limit in time-setting mode */
static uint8_t s_clock_start_flag       = 0;      /* Flag for starting the clock display */

static uint8_t s_100ms_count            = 0;      /* Flag for counting every 100ms */
static uint8_t s_chattering_flag        = 0;      /* Flag for button chattering prevention */
static uint8_t s_prev_button1_flag      = 0;      /* Flag for previous state of button1 */
static uint8_t s_prev_button2_flag      = 0;      /* Flag for previous state of button2 */

static uint8_t s_continuous_touch_flag  = 0;      /* Flag for continuous button press detection */
static uint8_t s_continuous_touch_count = 0;      /* Flag for continuous touch counter */

static uint8_t s_userswitch_on_off_flag = 0;      /* Flag for determining the ON/OFF status of the user switch */

/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/
static void r_lcd_show (uint8_t value, uint8_t digit);
static void r_time_show (void);
static void r_change_time (void);
static void r_blink_set_time (void);
static void r_array_show (uint8_t * array, uint8_t num, uint8_t delay);
static void r_clear_show (void);
static void r_delay_100ms (uint8_t num);
static void r_time_unit_change (void);

/**********************************************************************************************************************
 * Function Name: r_clock_demo_start
 * Description  : Start the clock demo
 * Return Value : None
 *********************************************************************************************************************/
void r_clock_demo_start(void)
{
    uint8_t start_show[8] =
    { 28, 22, 7, 8, 39, 22, 2, 3 }; /* RL78/L23 */
    uint8_t demo_show[8] =
    { 13, 22, 21, 38, 14, 15, 23, 25 }; /* CLK DEMO */

    RTCLPC   = 1;
    WUTMMCK0 = 0;

    /* Enable the LCD */
    R_Config_LCD_Voltage_On();
    R_Config_LCD_Start();

    /* Enable the sub clock */
    r_change_to_sub();

    /* LCD display for "RL78/L23" and "CLK DEMO" */
    r_array_show(start_show, 8, 2);
    r_delay_100ms(20);

    r_clear_show();
    r_delay_100ms(3);

    r_array_show(demo_show, 8, 2);
    r_delay_100ms(5);

    r_clear_show();
    r_delay_100ms(5);

    r_array_show(demo_show, 8, 0);
    r_delay_100ms(5);

    r_clear_show();
    r_delay_100ms(5);

    r_array_show(demo_show, 8, 0);
    r_delay_100ms(20);

    r_clear_show();

    /* Enable the user switch */
    R_Config_INTC_INTP0_Start();

    /* Wait for the user switch press */
    while (0 == s_clock_start_flag)
    {
        r_userswitch_release();
    }

    /* Enable the main clock */
    r_change_to_main();

    /* Enable the RTC */
    R_Config_RTC_Start();

    /* Show the time on the LCD */
    r_time_show();
}
/**********************************************************************************************************************
 End of function r_clock_demo_start
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_userswitch_release
 * Description  : Process the event when the user switch is released
 * Return Value : None
 *********************************************************************************************************************/
void r_userswitch_release(void)
{
    if (((P13 & 0x80) == 0x80) && (1 == s_userswitch_on_off_flag))
    {
        s_userswitch_on_off_flag = 0;
        if (0 == s_clock_start_flag)
        {
            s_clock_start_flag = 1;
        }
    }
}
/**********************************************************************************************************************
 End of function r_userswitch_release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_change_to_sub
 * Description  : Sub-clock supply
 * Return Value : None
 *********************************************************************************************************************/
void r_change_to_sub(void)
{
    HIOSTOP = 1;
    TPS0    = 0;
    CSS     = 1;
}
/**********************************************************************************************************************
 End of function r_change_to_sub
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_change_to_main
 * Description  : Main-clock supply
 * Return Value : None
 *********************************************************************************************************************/
void r_change_to_main(void)
{
    HIOSTOP = 0;
    NOP();
    NOP();

    CSS  = 0;
    TPS0 = 10;

    while (1 == CLS)
    {
        ;
    }
}
/**********************************************************************************************************************
 End of function r_change_to_main
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_userswitch_callback
 * Description  : Callback for user switch
 * Return Value : None
 *********************************************************************************************************************/
void r_userswitch_callback(void)
{
    /* User switch chattering prevention */
    if (1 == s_chattering_flag)
    {
        return;
    }
    s_chattering_flag = 1;

    /* User switch detection */
    if ((P13 & 0x80) == 0x00)
    {
        s_userswitch_on_off_flag = 1;
        s_set_time_limit_count   = 0;
        if (1 == s_clock_start_flag)
        {
            r_time_unit_change();
        }
    }
    else if ((P13 & 0x80) == 0x80)
    {
        s_userswitch_on_off_flag = 0;
        if (0 == s_clock_start_flag)
        {
            s_clock_start_flag = 1;
        }
    }
    else
    {
        NOP();
    }
    R_Config_TAU0_4_Start();
}
/**********************************************************************************************************************
 End of function r_userswitch_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_rtc_callback
 * Description  : Callback for RTC
 * Return Value : None
 *********************************************************************************************************************/
void r_rtc_callback(void)
{
    /* Update the time */
    if (0 == s_clock_mode)
    {
        r_change_time();
        r_time_show();
    }
    else
    {
        /* Check the end time of the blinking */
        g_rtc_interrupt_flag = 0;
        s_set_time_limit_count++;
        if (TIME_SETTING_FINISH <= s_set_time_limit_count)
        {
            s_set_time_limit_count = 0;
            g_touch_button_flag    = 0;
            s_clock_mode           = 0;

            /* Set the RTC */
            RWAIT = 1;
            while (0 == RWST)
            {
                ;
            }
            SEC  = ((s_lcd_seconds / 10) << 4) + (s_lcd_seconds % 10);
            MIN  = ((s_lcd_minutes / 10) << 4) + (s_lcd_minutes % 10);
            HOUR = ((s_lcd_hours   / 10) << 4) + (s_lcd_hours   % 10);

            RWAIT = 0;
            while (1 == RWST)
            {
                ;
            }

            R_Config_TAU0_1_Stop();
            P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
            r_time_show();
        }
    }
}
/**********************************************************************************************************************
 End of function r_rtc_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_tau0_1_blink_callback
 * Description  : Callback for TAU0_1
 * Return Value : None
 *********************************************************************************************************************/
void r_tau0_1_blink_callback(void)
{
    /* Blinking of the unit for time setting */
    if (1 == s_blink_flag)
    {
        r_blink_set_time();
        s_blink_flag = 0;
    }
    else
    {
        r_time_show();
        s_blink_flag = 1;
    }
}
/**********************************************************************************************************************
 End of function r_tau0_1_blink_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_tau0_3_delay_callback
 * Description  : Callback for TAU0_3
 * Return Value : None
 *********************************************************************************************************************/
void r_tau0_3_delay_callback(void)
{
    s_100ms_count++;
}
/**********************************************************************************************************************
 End of function r_tau0_3_delay_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_tau0_4_chattering_callback
 * Description  : Callback for TAU0_4
 * Return Value : None
 *********************************************************************************************************************/
void r_tau0_4_chattering_callback(void)
{
    s_chattering_flag = 0;
    R_Config_TAU0_4_Stop();
}
/**********************************************************************************************************************
 End of function r_tau0_4_chattering_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_tau0_5_continuous_callback
 * Description  : Callback for TAU0_5
 * Return Value : None
 *********************************************************************************************************************/
void r_tau0_5_continuous_callback(void)
{
    if (COUNTINUOUS_START_NUM < s_continuous_touch_count)
    {
        s_continuous_touch_flag = 1;
    }
    else
    {
        s_continuous_touch_count++;
    }
}
/**********************************************************************************************************************
 End of function r_tau0_5_continuous_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_touch_plus_set_time
 * Description  : Callback for Touch Button 1
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_plus_set_time(void)
{
    /* Detect touch */
    s_set_time_limit_count = 0;

    if (0 == s_prev_button1_flag)
    {
        s_prev_button1_flag      = 1;
        s_continuous_touch_flag  = 1;
        s_continuous_touch_count = 0;
        R_Config_TAU0_5_Start();
    }

    /* Continuous change on long press touch */
    if (1 == s_continuous_touch_flag)
    {
        s_continuous_touch_flag = 0;

        P6 &= (~_10_Pn4_OUTPUT_1);
        P6 |= _20_Pn5_OUTPUT_1;

        /* 60over or 24over of hours */
        if ((MAX_SEC_MIN <= (*sp_time_address[s_unit]))
                || ((MAX_HOUR <= (*sp_time_address[s_unit])) && (UNIT_HOUR == s_unit)))
        {
            (*sp_time_address[s_unit]) = MIN_SEC_MIN_HOUR;
        }
        else
        {
            (*sp_time_address[s_unit])++;
        }
        r_time_show();
    }
}
/**********************************************************************************************************************
 End of function r_touch_plus_set_time
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_touch_minus_set_time
 * Description  : Callback for Touch Button 2
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_minus_set_time(void)
{
    /* Detect touch */
    s_set_time_limit_count = 0;

    if (0 == s_prev_button2_flag)
    {
        s_prev_button2_flag      = 1;
        s_continuous_touch_flag  = 1;
        s_continuous_touch_count = 0;
        R_Config_TAU0_5_Start();
    }

    /* Continuous change on long press touch */
    if (1 == s_continuous_touch_flag)
    {
        s_continuous_touch_flag = 0;

        P6 &= (~_20_Pn5_OUTPUT_1);
        P6 |= _10_Pn4_OUTPUT_1;
        if (MIN_SEC_MIN_HOUR == (*sp_time_address[s_unit]))
        {
            if (UNIT_HOUR == s_unit)
            {
                (*sp_time_address[s_unit]) = MAX_HOUR;
            }
            else
            {
                (*sp_time_address[s_unit]) = MAX_SEC_MIN;
            }
        }
        else
        {
            (*sp_time_address[s_unit])--;
        }
        r_time_show();
    }
}
/**********************************************************************************************************************
 End of function r_touch_minus_set_time
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_touch_both_buttons
 * Description  : Detect touch on both buttons
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_both_buttons(void)
{
    /* Detect touch on both buttons */
    P6 &= (~(_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1));

    s_set_time_limit_count  = 0;
    s_continuous_touch_flag = 0;
    s_prev_button1_flag     = 1;
    s_prev_button2_flag     = 1;
    R_Config_TAU0_5_Stop();
}
/**********************************************************************************************************************
 End of function r_touch_both_buttons
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_no_touch
 * Description  : Detect no touch
 * Return Value : None
 *********************************************************************************************************************/
void r_no_touch(void)
{
    /* Detect no touch */
    P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);

    s_continuous_touch_flag = 0;
    s_prev_button1_flag     = 0;
    s_prev_button2_flag     = 0;
    R_Config_TAU0_5_Stop();
}
/**********************************************************************************************************************
 End of function r_no_touch
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_lcd_show
 * Description  : Show on the LCD
 * Arguments    : value
 *              : digit
 * Return Value : None
 *********************************************************************************************************************/
static void r_lcd_show(uint8_t value, uint8_t digit)
{
    for (uint8_t i = 0; i < 4; i++)
    {
        R_Config_LCD_Set_DisplayData(g_digit_segdata[digit][i], g_show_segdata[value][i]);
    }
}
/**********************************************************************************************************************
 End of function r_lcd_show
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_time_show
 * Description  : Show the time on the LCD
 * Return Value : None
 *********************************************************************************************************************/
static void r_time_show(void)
{
    r_lcd_show((s_lcd_seconds % 10), 7);
    r_lcd_show((s_lcd_seconds / 10), 6);
    r_lcd_show(37, 5); /* 37:[.] */
    r_lcd_show((s_lcd_minutes % 10), 4);
    r_lcd_show((s_lcd_minutes / 10), 3);
    r_lcd_show(37, 2); /* 37:[.] */
    r_lcd_show((s_lcd_hours % 10), 1);
    r_lcd_show((s_lcd_hours / 10), 0);
}
/**********************************************************************************************************************
 End of function r_time_show
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_change_time
 * Description  : Update the time
 * Return Value : None
 *********************************************************************************************************************/
static void r_change_time(void)
{
    uint8_t sum;
    
    if (0 == g_rtc_interrupt_flag)
    {
        return;
    }
    g_rtc_interrupt_flag = 0;

    /* Update the time */
    RWAIT = 1;
    while (0 == RWST)
    {
        ;
    }

    sum = ((SEC  >> 4) *10);
    sum += (SEC  & 0xF);
    s_lcd_seconds = sum;
    
    sum = ((MIN  >> 4) *10);
    sum += (MIN  & 0xF);
    s_lcd_minutes = sum;
    
    sum = ((HOUR >> 4) *10);
    sum += (HOUR & 0xF);
    s_lcd_hours = sum;

    RWAIT = 0;
    while (1 == RWST)
    {
        ;
    }
}
/**********************************************************************************************************************
 End of function r_change_time
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_blink_set_time
 * Description  : Blinking of the time
 * Return Value : None
 *********************************************************************************************************************/
static void r_blink_set_time(void)
{
    switch (s_unit)
    {
        case UNIT_SEC:
            r_lcd_show(38, 7); /* 38:[ ] */
            r_lcd_show(38, 6); /* 38:[ ] */
            break;

        case UNIT_MIN:
            r_lcd_show(38, 4); /* 38:[ ] */
            r_lcd_show(38, 3); /* 38:[ ] */
            break;

        case UNIT_HOUR:
            r_lcd_show(38, 1); /* 38:[ ] */
            r_lcd_show(38, 0); /* 38:[ ] */
            break;

        default:
            break;
    }
}
/**********************************************************************************************************************
 End of function r_blink_set_time
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_array_show
 * Description  : Show array characters on the LCD
 * Arguments    : array
 *              : num
 *              : delay
 * Return Value : None
 *********************************************************************************************************************/
static void r_array_show(uint8_t * array, uint8_t num, uint8_t delay)
{
    for (uint8_t i = 0; i < num; i++)
    {
        r_lcd_show(array[i], i);
        r_delay_100ms(delay);
    }
}
/**********************************************************************************************************************
 End of function r_array_show
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_clear_show
 * Description  : Clear the LCD
 * Return Value : None
 *********************************************************************************************************************/
static void r_clear_show(void)
{
    for (uint8_t i = 0; i < 8; i++)
    {
        r_lcd_show(38, i);
    }
}
/**********************************************************************************************************************
 End of function r_clear_show
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_delay_100ms
 * Description  : Delay of 100ms
 * Argument     : num
 * Return Value : None
 *********************************************************************************************************************/
static void r_delay_100ms(uint8_t num)
{
    if (0 < num)
    {
        s_100ms_count = 0;
        R_Config_TAU0_3_Start();
        while (num >= s_100ms_count)
        {
            ;
        }
        R_Config_TAU0_3_Stop();
    }
}
/**********************************************************************************************************************
 End of function r_delay_100ms
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_time_unit_change
 * Description  : Update the selected time unit
 * Return Value : None
 *********************************************************************************************************************/
static void r_time_unit_change(void)
{
    /* Start time change */
    if (0 == s_clock_mode)
    {
        s_unit              = UNIT_SEC;
        s_clock_mode        = 1;
        g_touch_button_flag = 1;
        R_Config_TAU0_1_Start();
    }
    else
    {
        /* Update the selected time unit */
        s_unit++;
        if (UNIT_HOUR < s_unit)
        {
            s_unit = UNIT_SEC;
        }
    }
}
/**********************************************************************************************************************
 End of function r_time_unit_change
 *********************************************************************************************************************/

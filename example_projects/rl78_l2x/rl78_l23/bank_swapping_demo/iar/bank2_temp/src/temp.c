/**********************************************************************************************************************
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : temp.c
 * Version      : 1.0
 * Description  : Temperature demo program for RL78/L23.
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
#include "temp.h"
#include "r_smc_entry.h"
#include "sample_control_bank_programming.h"
#include "sample_control_bank_swap.h"
#include "sample_defines.h"
#include "sample_config.h"

#include "sample_bank_swapped_code.h"

#include "r_rfd_common_api.h"
#include "r_rfd_common_control_api.h"

#include "platform.h"

/**********************************************************************************************************************
 Exported global variables
 *********************************************************************************************************************/
extern const uint8_t g_show_segdata[40][4];  /* Characters displayed on the LCD */
extern const uint8_t g_digit_segdata[8][4];  /* Number of display digits on the LCD */

uint8_t g_touch_button_flag             = 0; /* Flag for enabling touch function */
uint8_t g_out_of_range_main_flag        = 0; /* Flag for indicating that the value is out of range
                                              * and the main clock is operating */

static uint8_t s_lcd_value              = DEFAULT_VALUE; /* LCD display value  */
static uint8_t s_100ms_count            = 0; /* Flag for counting every 100ms */
static uint8_t s_prev_button1_flag      = 0; /* Flag for previous state of button1 */
static uint8_t s_prev_button2_flag      = 0; /* Flag for previous state of button2 */

static uint8_t s_demo_change_flag       = 0; /* Flag for demo changing */
static uint8_t s_demo_change_count_flag = 0; /* Flag for starting the counter that determines demo changes */
static uint8_t s_demo_change_count      = 0; /* Flag for user switch long press duration counter */

static uint8_t s_standby_count_flag     = 0; /* Flag for starting the count to transition to standby */
static uint8_t s_standby_count          = 0; /* Flag for standby transition counter */

static uint8_t s_continuous_touch_flag  = 0; /* Flag for continuous button press detection */
static uint8_t s_continuous_touch_count = 0; /* Flag for continuous touch counter */

static uint8_t s_userswitch_on_off_flag = 0; /* Flag for determining the ON/OFF status of the user switch */


/**********************************************************************************************************************
 Private (static) variables and functions
 *********************************************************************************************************************/
static void r_lcd_show (uint8_t value, uint8_t digit);
static void r_value_show (void);
static void r_array_show (uint8_t * array, uint8_t num, uint8_t delay);
static void r_clear_show (void);
static void r_delay_100ms (uint8_t num);
static void r_value_out_of_range (void);
static void r_value_continuous (void);

static uint8_t r_bank_swap (void);

/**********************************************************************************************************************
 * Function Name: r_bank2_temp_start
 * Description  : Start the bank2 temp demo
 * Return Value : None
 *********************************************************************************************************************/
void r_bank2_temp_start(void)
{
    uint8_t start_show[8] =
    { 28, 22, 7, 8, 39, 22, 2, 3 }; /* RL78/L23 */
    uint8_t demo_show[7] =
    { 12, 11, 24, 21, 2, 38, 30 }; /* BANK2 T */

    /* Enable the LCD */
    R_Config_LCD_Voltage_On();
    R_Config_LCD_Start();

    /* LCD display for "RL78/L23" and "BNAK2 T" */
    r_array_show(start_show, 8, 2);
    r_delay_100ms(20);

    r_clear_show();
    r_delay_100ms(3);

    r_array_show(demo_show, 7, 2);
    r_delay_100ms(5);

    r_clear_show();
    r_delay_100ms(5);

    r_array_show(demo_show, 7, 0);
    r_delay_100ms(5);

    r_clear_show();
    r_delay_100ms(5);

    r_array_show(demo_show, 7, 0);
    r_delay_100ms(20);

    r_clear_show();
    r_delay_100ms(5);

    /* Disable the LCD */
    R_Config_LCD_Stop();
    R_Config_LCD_Voltage_Off();

    /* Enable the user switch */
    R_Config_INTC_INTP0_Start();
}
/**********************************************************************************************************************
 End of function r_bank2_temp_start
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_change_demo
 * Description  : Switch to Demo
 * Return Value : None
 *********************************************************************************************************************/
void r_change_demo(void)
{
    uint8_t array_change[8] =
    { 14, 15, 23, 25, 38, 13, 18, 17 }; /* DEMO CHG */

    /* Long press detected on the user switch */
    if (1 == s_demo_change_flag)
    {
        P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
        R_Config_INTC_INTP0_Stop();
        R_Config_RTC_Stop();
        R_Config_TAU0_3_Stop();
        R_Config_TAU0_5_Stop();

        /* Enable the LCD */
        LCDM0 |= _80_LCD_VOLTAGE_MODE_CAPACITOR;
        R_Config_LCD_Voltage_On();
        R_Config_LCD_Start();

        /* LCD display for "DEMO CHG" */
        r_array_show(array_change, 8, 0);
        r_delay_100ms(5);
        r_clear_show();
        r_delay_100ms(5);
        r_array_show(array_change, 8, 0);
        r_delay_100ms(5);
        r_clear_show();
        r_delay_100ms(5);
        r_array_show(array_change, 8, 0);
        r_delay_100ms(10);
        r_clear_show();

        /* Bank swap */
        r_bank_swap();
    }
}
/**********************************************************************************************************************
 End of function r_change_demo
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
        s_demo_change_count_flag = 0;
        s_standby_count_flag     = 1;
    }
}
/**********************************************************************************************************************
 End of function r_userswitch_release
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_userswitch_callback
 * Description  : Callback for user switch
 * Return Value : None
 *********************************************************************************************************************/
void r_userswitch_callback(void)
{
    /* User switch detection */
    if ((P13 & 0x80) == 0x00)
    {
        s_userswitch_on_off_flag = 1;
        if (0 == g_touch_button_flag)
        {
            g_touch_button_flag = 1;
            LCDM0              |= _80_LCD_VOLTAGE_MODE_CAPACITOR;
            R_Config_LCD_Voltage_On();
            R_Config_LCD_Start();
            r_value_show();
        }

        /* Start detecting long press for bank swap */
        s_demo_change_count_flag = 1;
        s_demo_change_count      = 0;
        s_standby_count          = 0;
        R_Config_RTC_Start();
    }
    else if ((P13 & 0x80) == 0x80)
    {
        s_userswitch_on_off_flag = 0;
        s_demo_change_count_flag = 0;
        s_standby_count_flag     = 1;
    }
    else
    {
        NOP();
    }
}
/**********************************************************************************************************************
 End of function r_userswitch_callback
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_rtc_long_press_callback
 * Description  : Callback for RTC
 * Return Value : None
 *********************************************************************************************************************/
void r_rtc_long_press_callback(void)
{
    if (0 == s_demo_change_count_flag)
    {
        if (0 == s_standby_count_flag)
        {
            R_Config_RTC_Stop();
            return;
        }
        else
        {
            /* Detect transition to standby mode */
            s_standby_count++;
            if ((VALUE_SETTING_FINISH <= s_standby_count) && (0 == g_out_of_range_main_flag))
            {
                s_standby_count_flag = 0;
                s_standby_count      = 0;
                g_touch_button_flag  = 0;
                R_Config_LCD_Stop();
                R_Config_LCD_Voltage_Off();
                P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
            }
        }
    }
    else
    {
        /* Detect long press for bank swap */
        s_demo_change_count++;
        if (LONG_PRESS_SEC <= s_demo_change_count)
        {
            s_demo_change_flag  = 1;
            g_touch_button_flag = 0;
        }
    }
}
/**********************************************************************************************************************
 End of function r_rtc_long_press_callback
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
 * Function Name: r_touch_plus_value
 * Description  : Callback for Touch Button 1
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_plus_value(void)
{
    /* Detect touch */
    s_standby_count = 0;

    if (0 == s_prev_button1_flag)
    {
        s_continuous_touch_flag  = 0;
        s_continuous_touch_count = 0;
        s_prev_button1_flag      = 1;
        s_lcd_value++;
        r_value_out_of_range();
        r_value_show();

    }

    /* Continuous change on long press touch */
    if (1 == s_continuous_touch_flag)
    {
        s_continuous_touch_flag = 0;
        s_lcd_value++;
        P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
        r_value_continuous();
        r_value_show();
    }
}
/**********************************************************************************************************************
 End of function r_touch_plus_value
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_touch_minus_value
 * Description  : Callback for Touch Button 2
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_minus_value(void)
{
    /* Detect touch */
    s_standby_count = 0;

    if (0 == s_prev_button2_flag)
    {
        s_continuous_touch_flag  = 0;
        s_continuous_touch_count = 0;
        s_prev_button2_flag      = 1;
        s_lcd_value--;
        r_value_out_of_range();
        r_value_show();
    }

    /* Continuous change on long press touch */
    if (1 == s_continuous_touch_flag)
    {
        s_continuous_touch_flag = 0;
        s_lcd_value--;
        P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
        r_value_continuous();
        r_value_show();
    }
}
/**********************************************************************************************************************
 End of function r_touch_minus_value
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_touch_both_buttons
 * Description  : Detect touch on both buttons
 * Return Value : None
 *********************************************************************************************************************/
void r_touch_both_buttons(void)
{
    /* Detect touch on both buttons */
    s_standby_count = 0;
    if (0 == g_out_of_range_main_flag)
    {
        P6 &= (~(_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1));
    }
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
    if (0 == g_out_of_range_main_flag)
    {
        P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
    }
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
 * Function Name: r_value_show
 * Description  : Show the value on the LCD
 * Return Value : None
 *********************************************************************************************************************/
static void r_value_show(void)
{
    r_lcd_show((s_lcd_value % 10), 7);
    r_lcd_show((s_lcd_value / 10), 6);
    r_lcd_show(38, 5);
    r_lcd_show(38, 4);
    r_lcd_show(38, 3);
    r_lcd_show(38, 2);
    r_lcd_show(38, 1);
    r_lcd_show(38, 0);
}
/**********************************************************************************************************************
 End of function r_value_show
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
 * Function Name: r_value_out_of_range
 * Description  : Check for out-of-range value
 * Return Value : None
 *********************************************************************************************************************/
static void r_value_out_of_range(void)
{
    /* Upper limit value */
    if (MAX_VALUE <= s_lcd_value)
    {
        s_lcd_value              = MAX_VALUE;
        g_out_of_range_main_flag = 1;
        R_Config_TAU0_5_Stop();
        P6 &= (~_10_Pn4_OUTPUT_1);
        P6 |= _20_Pn5_OUTPUT_1;
    }
    /* Lower limit value */
    else if (s_lcd_value <= MIN_VALUE)
    {
        s_lcd_value              = MIN_VALUE;
        g_out_of_range_main_flag = 1;
        R_Config_TAU0_5_Stop();
        P6 |= _10_Pn4_OUTPUT_1;
        P6 &= (~_20_Pn5_OUTPUT_1);
    }
    else
    {
        g_out_of_range_main_flag = 0;
        R_Config_TAU0_5_Start();
        P6 |= (_10_Pn4_OUTPUT_1 | _20_Pn5_OUTPUT_1);
    }
}
/**********************************************************************************************************************
 End of function r_value_out_of_range
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_value_continuous
 * Description  : Check the value during continuous touch
 * Return Value : None
 *********************************************************************************************************************/
static void r_value_continuous(void)
{
    /* Upper limit value */
    if (MAX_VALUE_CONTINUOUS <= s_lcd_value)
    {
        s_lcd_value = MAX_VALUE_CONTINUOUS;
    }
    /* Lower limit value */
    else if (s_lcd_value <= MIN_VALUE_CONTINUOUS)
    {
        s_lcd_value = MIN_VALUE_CONTINUOUS;
    }
    else
    {
        g_out_of_range_main_flag = 0;
    }
}
/**********************************************************************************************************************
 End of function r_value_continuous
 *********************************************************************************************************************/

/**********************************************************************************************************************
 * Function Name: r_bank_swap
 * Description  : Bank swap
 * Return Value : Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK                 : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_PARAMETER          : Parameter error
 *                  - SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED    : Mode mismatched error
 *                  - SAMPLE_ENUM_RET_ERR_CONFIGURATION      : Configuration error
 *                  - SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA   : Check write data error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_ERASE          : Erase command error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_WRITE          : Write command error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_BLANKCHECK     : Blankcheck command error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_SET_EXTRA_AREA : Set extra area command (boot flag) error
 *********************************************************************************************************************/
static uint8_t r_bank_swap(void)
{
    /* Local variable definition */
    e_rfd_ret_t    l_e_rfd_status_flag;
    e_sample_ret_t l_e_sam_ret_value;

    /* Check whether HOCO is already started */
    if (SAMPLE_VALUE_U01_MASK0_1BIT == HIOSTOP)
    {
        /* Initialize RFD */
        l_e_rfd_status_flag = R_RFD_Init(CPU_FREQUENCY);

        if (R_RFD_ENUM_RET_STS_OK == l_e_rfd_status_flag)
        {
            l_e_sam_ret_value = SAMPLE_ENUM_RET_STS_OK;
            if (SAMPLE_ENUM_RET_STS_OK == l_e_sam_ret_value)
            {
                /* Bank swap */
                l_e_sam_ret_value = Sample_BankSwapControl();
                if (SAMPLE_ENUM_RET_STS_OK == l_e_sam_ret_value)
                {
                    /* Dummy call to ensure that the bank swapped code is linked, but never call here */
                    sample_bank_swapped_code();
                }
                else
                {
                    /* Failed bank swap */
                    /* Error code is already set */
                    NOP();
                }
            }
            else
            {
                /* Failed bank programming */
                /* Error code is already set */
                NOP();
            }
        }
        else
        {
            /* Failed to initialize RFD */
            l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_PARAMETER;
        }
    }
    else
    {
        /* HOCO is not started */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_CONFIGURATION;
    }

    /* Return status */
    return ((uint8_t) l_e_sam_ret_value);
}
/**********************************************************************************************************************
 End of function r_bank_swap
 *********************************************************************************************************************/

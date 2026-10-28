/***********************************************************************************************************************
 * File Name    : tau.c
 * Description  : Contains declarations of data structures and functions used in hal_entry.c
 **********************************************************************************************************************/
/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/

#include "r_cg_macrodriver.h"
#include "tau.h"
#include "common_utils.h"
#include "r_smc_entry.h"

/*******************************************************************************************************************//**
 * @addtogroup tau
 * @{
 **********************************************************************************************************************/

/* TAU Callback flag */
static volatile _Bool g_led1_status_flag_cur        = false;
static volatile _Bool g_input_capture_detect_flag   = false;
static volatile _Bool g_external_counter_flag       = false;
static volatile _Bool g_measure_pulse_width_flag    = false;
static volatile _Bool g_delay_timer_end_flag        = false;

/* Led status flag */
static _Bool g_led2_status_flag     = false;
static _Bool g_led1_status_flag_old = false;

/* Counting valid edge */
static uint32_t g_capture_value     = RESET_VALUE;

/* Counting variable */
static uint8_t g_led1_blink_times  = RESET_VALUE;
static uint8_t g_interrupt_counter = RESET_VALUE;
static uint8_t g_measure_times     = RESET_VALUE;


/* The buffer contains user input */
char g_rx_buffer [TERM_BUFFER_SIZE] = {RESET_VALUE};

/* Private function declarations */
static fsp_err_t tau_interval_and_delay_timer_operation(void);
static fsp_err_t tau_external_event_counter_operation(void);
static fsp_err_t tau_measure_low_level_pulse_width_operation(void);
static void tau_deinit(void);
static void handle_error(fsp_err_t err, uint8_t * err_str);
static uint32_t max_timer_calculate (tau_mode_t tau_mode);
static float min_timer_calculate (tau_mode_t tau_mode);
static uint16_t get_user_input(uint16_t min_value, uint16_t max_value);

/*******************************************************************************************************************//**
 *  @brief       This function is used to start the tau example operation.
 *  @param[in]   None
 *  @retval      None
 **********************************************************************************************************************/
void tau_entry(void)
{
    fsp_err_t err = FSP_SUCCESS;
    /* Initialize terminal */
    err = (fsp_err_t)TERM_INIT();
    if (FSP_SUCCESS != err)
    {
        /* Error trap */
        ERROR_TRAP;
    }

    /* Example Project information printed on the terminal */
    APP_PRINT(BANNER_INFO, EP_VERSION);
    APP_PRINT0(EP_INFO);

    while (true)
    {
        /* Initialize terminal */
        err = (fsp_err_t)TERM_INIT();
        if (FSP_SUCCESS != err)
        {
            /* Error trap */
            ERROR_TRAP;
        }

        /* Wait until there is any user input */
        uint16_t input_value = get_user_input(1,3);

        switch(input_value){
        case 1:
            /* Start interval timer and delay timer mode. */
            APP_PRINT0(SEQUENCE1_INFO);
            err = tau_interval_and_delay_timer_operation ();
            APP_ERR_HANDLE(err, "\r\n **tau_interval_and_delay_timer_operation failed**");
            break;

        case 2:
            /* Go to external event counter mode */
            APP_PRINT0(SEQUENCE2_INFO);
            err = tau_external_event_counter_operation ();
            APP_ERR_HANDLE(err, "\r\n **tau_external_event_counter_operation failed**");
            break;

        case 3:
            /* Go to measure low level pulse width mode */
            APP_PRINT0(SEQUENCE3_INFO);
            err = tau_measure_low_level_pulse_width_operation ();
            APP_ERR_HANDLE(err, "\r\n **tau_measure_low_level_pulse_width_operation failed**");
            APP_PRINT0("\r\n=======End of Application. Please enter any key to restart!=======\r\n");
            break;

        default:
            break;
        }
    }
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to demonstrate the interval timer and the delay timer by set cycle blink of LED 1
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t tau_interval_and_delay_timer_operation(void)
{
    fsp_err_t err = FSP_SUCCESS;

    /* Open instance TAU interval timer */
    R_TAU0_2_Create();
    /* Open instance TAU delay timer */
    R_TAU0_3_Create();

    /* Start instance TAU interval timer after set period blink for LED 1  */
    R_TAU0_2_Start();

    /* Enable instance TAU delay timer */
    R_TAU0_3_Start();
    APP_ERR_RET0 (err != FSP_SUCCESS,err, "\r\n **Enable instance TAU delay timer failed**");

    APP_PRINT0("\r\nPlease observe LED1's behavior to verify\r\n");
    while (true)
    {
        if (g_delay_timer_end_flag)
        {
            g_delay_timer_end_flag = false;
            g_led1_status_flag_cur = false;
            /* Reset interval timer */
            R_TAU0_3_Stop();
            R_TAU0_3_Start();
            APP_ERR_RET0(err != FSP_SUCCESS,err,"Reset interval timer failed");
        }

        /* Check blink times of LED 1 */
        if (g_led1_blink_times < DEMO_TIMES)
        {
            /* Toggle LED 1 status if g_led1_status_flag changes */
            if (g_led1_status_flag_old != g_led1_status_flag_cur)
            {
                g_led1_status_flag_old = g_led1_status_flag_cur;
                if (true == g_led1_status_flag_old)
                {
                    PIN_WRITE(LED1) = 0U;
                }
                else
                {
                    PIN_WRITE(LED1) = 1U;
                    g_led1_blink_times++;
                }
            }
        }
        else
        {
            /* Close instance TAU interval timer */
            R_TAU0_2_Stop();
            /* Close instance TAU delay timer */
            R_TAU0_3_Stop();

            APP_PRINT("\r\nLed 1 blink times: %d\r\n", g_led1_blink_times);
            /* Reset led 1 blink times */
            g_led1_blink_times = RESET_VALUE;

            break;
        }
    }
    return err;
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to measure the input pulse width of square wave from another TAU channel
 *               and counts blink times of LED 2
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t tau_external_event_counter_operation(void)
{
    fsp_err_t err = FSP_SUCCESS;
    float input_pulse_frequency_value     = RESET_VALUE;
    char timer_buffer[BUFF_SIZE]          = {RESET_VALUE};
    uint32_t external_event_count         = RESET_VALUE;
    uint32_t input_pulse_max              = RESET_VALUE;
    float input_pulse_min                 = RESET_VALUE;

    /* Open instance TAU square wave output sequence 2*/
    R_TAU0_1_Create();
    /* Open instance TAU divider */
    R_TAU0_0_Create();
    /* Open instance TAU input capture */
    R_TAU0_4_Create();
    /* Open instance TAU external event counter */
    R_TAU0_5_Create();

    /* The limit of measurable input signal is based on the configured clock frequency. */
    input_pulse_min = min_timer_calculate(INPUT_CAPTURE);
    input_pulse_max = max_timer_calculate(INPUT_CAPTURE);
    sprintf (timer_buffer, "%.03f", input_pulse_min);
    APP_PRINT("\r\nInput signal range can be measured: from %sHz to %dHz\r\n", timer_buffer, input_pulse_max);

    /* Start instance TAU square wave output sequence 2 after set frequency */
    R_TAU0_1_Start();
    /* Start divider square wave */
    R_TAU0_0_Start();
    /* Enable instance TAU input capture to measure pulse width */
    R_TAU0_4_Start();
    /* Enable instance TAU external event counter to count turn-on times of LED 2*/
    R_TAU0_5_Start();

    APP_PRINT0("\r\nPlease observe LED2's behavior to verify\r\n");
    while (true)
    {
        /*Check capture flag and ignore the first measurement since it could have started in the middle of a pulse. */
        if (g_input_capture_detect_flag && g_interrupt_counter > ONE)
        {
            /* Blink LED2 once rising edge detected */
            g_led2_status_flag = g_led2_status_flag ? false : true;
            if (g_led2_status_flag)
            {
                /* Turn ON LED 2 */
                PIN_WRITE(LED2) = 0U;
                /* Calculate input pulse width  */
                uint16_t divider = 1U << TPS0;
                uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / (2 * divider));

                input_pulse_frequency_value = (float) ((float) (clock_frequency) / (float) (g_capture_value));
                sprintf (timer_buffer, "%.03f", input_pulse_frequency_value);
                APP_PRINT("\r\nInput pulse width measurement value: %sHz\r\n", timer_buffer);
                external_event_count ++;
                /* Reset captured valid edge */
                g_capture_value = RESET_VALUE;
            }
            else
            {
                /* Turn OFF LED 2 */
                PIN_WRITE(LED2) = 1U;
            }
            /* Reset input capture detect flag */
            g_input_capture_detect_flag = false;
        }

        else if (g_external_counter_flag)
        {
            /* Print external event count to confirm with configuration */
            APP_PRINT("\r\nExternal event count: %d\n", external_event_count);

            /* Reset external counter flag */
            g_external_counter_flag = false;
            /* Reset interrupt counter */
            g_interrupt_counter = RESET_VALUE;
            /* Reset external event count */
            external_event_count = RESET_VALUE;

            /* Close instance TAU square wave output sequence 2 */
            R_TAU0_1_Stop();
            /* Close instance TAU divider */
            R_TAU0_0_Stop();
            /* Close instance TAU input capture */
            R_TAU0_4_Stop();
            /* Close instance TAU external event counter */
            R_TAU0_5_Stop();

            break;
        }
        else
        {
            /* Do nothing */
        }
    }
    return err;
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to measures the low level pulse width of square wave, which is generated by
 *               another TAU channel
 *  @param[in]   None
 *  @retval      FSP_SUCCESS    Upon successful operation
 *  @retval      Any Other Error code apart from FSP_SUCCESS
 **********************************************************************************************************************/
static fsp_err_t tau_measure_low_level_pulse_width_operation(void)
{
    fsp_err_t err                               = FSP_SUCCESS;
    float low_level_pulse_width                 = RESET_VALUE;
    char timer_buffer[BUFF_SIZE]                = {RESET_VALUE};
    uint32_t low_level_width;

    /* Open instance TAU square wave output sequence 3 */
    R_TAU0_6_Create();
    /* Open instance TAU measure low level pulse width */
    R_TAU0_7_Create();

    /* Enable instance TAU to measure low level pulse width of square wave */
    R_TAU0_7_Start();

    /* Start instance TAU square wave output sequence 3 after set period */
    R_TAU0_6_Start();

    while (DEMO_TIMES > g_measure_times)
    {
        /*Check measure flag and ignore the first measurement since it could have started in the middle of a pulse. */
        if (g_measure_pulse_width_flag && g_interrupt_counter > ONE)
        {
            /* Calculate low level pulse width  */
            uint16_t divider = 1U << TPS0;
            uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / ( divider));
            R_TAU0_7_Get_PulseWidth(&low_level_width);
            low_level_pulse_width = (float) (( (float) (low_level_width) / (float) (clock_frequency)) * CONVERT_SECOND_TO_MILISECOND);
            sprintf (timer_buffer, "%.03f", low_level_pulse_width);
            APP_PRINT("\r\nLow level pulse width measurement value: %sms\r\n", timer_buffer);

            /* Reset g_measure_pulse_width_flag */
            g_measure_pulse_width_flag = false;
            /* Reset g_capture_value */
            low_level_width = RESET_VALUE;
            g_measure_times++;
        }
    }
    /* Close instance TAU square wave output sequence 3 */
    R_TAU0_6_Stop();
    /* Close instance TAU measure low level pulse width */
    R_TAU0_7_Stop();
    /* Reset low level measurement times */
    g_measure_times = RESET_VALUE;
    /* Reset interrupt counter */
    g_interrupt_counter = RESET_VALUE;
    return err;
}

/*********************************************************************************************************************
 * @brief  This function is used to get the user inputs.
 * @param[in]   None
 * @retval      input_value    Returns input buffer after receive enter key
 *********************************************************************************************************************/
static uint16_t get_user_input(uint16_t min_value, uint16_t max_value)
{
    uint16_t input_value = RESET_VALUE;
    uint8_t dummy = 0U;

    while (true)
    {
        /* Cleaning buffer */
        memset (g_rx_buffer, NULL_CHAR, sizeof(g_rx_buffer));
        /* Wait until there is any user input */
            while (!APP_CHECK_DATA)
            {
                ;
            }

            /* Clear RX event (data is provided via g_rx_buffer[0] by ISR) */
            (void)APP_READ(&dummy, 1);

            /* Convert ASCII digit to integer */
            input_value = (uint16_t)(g_rx_buffer[0] - '0');

        if (input_value >= min_value && input_value <= max_value)
        {
            break;
        }
        else
        {
            APP_PRINT("\r\nInvalid input. Please enter a valid input between %u and %u.\r\n", min_value, max_value);
            /* Reset user input value if it is an invalid input */
            input_value = RESET_VALUE;
        }
    }
    return input_value;
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to determine the maximum value of timer.
 *  @param[in]   tau_mode   Select TAU operation function
 *  @retval      max_val    Maximum value of timer mode
 **********************************************************************************************************************/
static uint32_t max_timer_calculate (tau_mode_t tau_mode)
{
    uint32_t max_val    = RESET_VALUE;

    if (INTERVAL_TIMER == tau_mode || DELAY_COUNTER == tau_mode)
    {
        /* Determine the maximum values of interval timer and delay counter corresponding to the selected TAU clock source */
        uint16_t divider = 1U << TPS0;
        uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / (2 * divider));
        max_val = ((MAX_PERIOD * CONVERT_SECOND_TO_MILISECOND) / clock_frequency);
    }
    else if (SQUARE_WAVE_SEQUENCE2 == tau_mode || INPUT_CAPTURE == tau_mode)
    {
        /* Determine the maximum frequency of square wave output sequence 2 and the maximum measurable input pulse signal corresponding to the selected TAU clock source */
        uint16_t divider = 1U << TPS0;
        uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / (2 * divider));
        max_val = ((clock_frequency / MIN_PERIOD) / CONVERT_HALF_TO_ONE_CYCLE);
    }
    else if (SQUARE_WAVE_SEQUENCE3 == tau_mode)
    {
        /* Determine the maximum period of square wave output sequence 3 corresponding to the selected TAU clock source */
        uint16_t divider = 1U << TPS0;
        uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / (2 * divider));
        max_val = (((MAX_PERIOD * CONVERT_HALF_TO_ONE_CYCLE) * CONVERT_SECOND_TO_MILISECOND) / clock_frequency);
    }
    else
    {
        /* Do nothing */
    }
    return max_val;
}

/*******************************************************************************************************************//**
 *  @brief       This function is used to determine the minimum value of timer.
 *  @param[in]   tau_mode       Select TAU operation function
 *  @retval      min_val        Minimum measurable value of timer mode
 **********************************************************************************************************************/
static float min_timer_calculate (tau_mode_t tau_mode)
{
    float min_val = RESET_VALUE;

    if (INPUT_CAPTURE == tau_mode)
    {
        /* Determine the minimum frequency can be measured by input capture operation corresponding to the selected TAU clock source */
        uint16_t divider = 1U << TPS0;
        uint32_t clock_frequency = ((uint32_t) BSP_CFG_FCLK_HZ / (2 * divider));
        min_val = (float) ((float) clock_frequency / (float) CAPTURE_VALUE_MAX);
    }

    return min_val;
}

/*******************************************************************************************************************//**
 * @brief       Interval timer callback function
 * @param[in]   p_args    : TAU Callback arguments.
 * @return      None
 **********************************************************************************************************************/
void tau_interval_timer_callback(tau_event_t args)
{
    if (TIMER_EVENT_CYCLE_END == args)
    {
        g_led1_status_flag_cur = true;
    }
}

/*******************************************************************************************************************//**
 *  @brief      Delay timer callback function
 *  @param[in]  p_args   Callback
 *  @retval     None
 **********************************************************************************************************************/
void tau_delay_timer_callback(tau_event_t args)
{
    if (TIMER_EVENT_CYCLE_END == args)
    {
        g_delay_timer_end_flag = true;
    }
}

/*******************************************************************************************************************//**
 *  @brief      Capture input pulse callback function
 *  @param[in]  p_args   Callback
 *  @retval     None
 **********************************************************************************************************************/
void tau_input_capture_timer_callback(tau_event_t args)
{
    if (TIMER_EVENT_CAPTURE_EDGE == args)
    {
        g_input_capture_detect_flag = true;
        R_TAU0_4_Get_PulseWidth(&g_capture_value);
        g_interrupt_counter++;
    }
}

/*******************************************************************************************************************//**
 *  @brief      External event counter callback function
 *  @param[in]  p_args   Callback
 *  @retval     None
 **********************************************************************************************************************/
void tau_external_event_counter_callback(tau_event_t args)
{
    if (TIMER_EVENT_CYCLE_END == args)
    {
        g_external_counter_flag = true;
    }
}

/*******************************************************************************************************************//**
 *  @brief      Measure low level callback function
 *  @param[in]  p_args   Callback
 *  @retval     None
 **********************************************************************************************************************/
void tau_measure_low_level_pulse_width_timer_callback(tau_event_t args)
{
    if (TIMER_EVENT_CAPTURE_EDGE == args)
    {
        g_measure_pulse_width_flag = true;
        g_interrupt_counter++;
    }
}
/*******************************************************************************************************************//**
 * @brief This function handles errors, prints error function and prints errors.
 * @param[IN]   error code, error function ,error string
 * @retval      None
 **********************************************************************************************************************/
static void handle_error(fsp_err_t err, uint8_t * err_str)
{
    /* Print error information and error code */
    APP_ERR_PRINT0(err_str);
    /* Close the opened TAU modules*/
    tau_deinit ();
    /* Error trap */
    APP_ERR_TRAP(err);
}

/*******************************************************************************************************************//**
 * @brief This function closes opened TAU module.
 * @param[IN]   error code, error string
 * @retval      None
 **********************************************************************************************************************/
static void tau_deinit(void)
{
    /* Close opened instance TAU interval timer */
    R_TAU0_2_Stop();

    /* Close opened instance TAU delay timer */
    R_TAU0_3_Stop();

    /* Close opened instance TAU square wave output sequence 2*/
    R_TAU0_1_Stop();

    /* Close opened instance TAU divider */
    R_TAU0_0_Stop();

    /* Close opened instance TAU input capture */
    R_TAU0_4_Stop();

    /* Close opened instance TAU external event counter */
    R_TAU0_5_Stop();

    /* Close opened instance TAU square wave output sequence 3*/
    R_TAU0_6_Stop();

    /* Close opened instance TAU measure low level pulse width*/
    R_TAU0_7_Stop();
}

/*******************************************************************************************************************//**
 * @} (end addtogroup tau)
 **********************************************************************************************************************/

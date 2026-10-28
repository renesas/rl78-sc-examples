/***********************************************************************************************************************
* Copyright (c) 2020 - 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
************************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : qe_touch_sample.c
* Description  : Main Program for RL78
***********************************************************************************************************************/
#include "qe_touch_config.h"

#include "clock.h"

#define TOUCH_SCAN_INTERVAL_EXAMPLE (20 * 1000)    /* microseconds */


extern uint8_t g_touch_button_flag;     /* Flag for enabling touch function */





void R_CTSU_PinSetInit(void);
void qe_touch_main(void);
void qe_touch_delay(uint16_t delay_us);




uint64_t button_status;
#if (TOUCH_CFG_NUM_SLIDERS != 0)
uint16_t slider_position[TOUCH_CFG_NUM_SLIDERS];
#endif
#if (TOUCH_CFG_NUM_WHEELS != 0)
uint16_t wheel_position[TOUCH_CFG_NUM_WHEELS];
#endif






void qe_touch_main(void)
{
    fsp_err_t err;

    BSP_ENABLE_INTERRUPT();

    /* Start the clock demo */
    r_clock_demo_start();

    /* Initialize pins (function created by Smart Configurator) */
    R_CTSU_PinSetInit();

    /* Open Touch middleware */
    err = RM_TOUCH_Open(g_qe_touch_instance_config01.p_ctrl, g_qe_touch_instance_config01.p_cfg);
    if (FSP_SUCCESS != err)
    {
        while (true)
        {
            ;
        }
    }

    /* Main loop */
    while (true)
    {
        if (0 == g_touch_button_flag)
        {
            STOP();
        }

        if (1 == g_touch_button_flag)
        {
            /* for [CONFIG01] configuration */
            err = RM_TOUCH_ScanStart(g_qe_touch_instance_config01.p_ctrl);
            if (FSP_SUCCESS != err)
            {
                while (true)
                {
                    ;
                }
            }

            while (0 == g_qe_touch_flag)
            {
                ;
            }
            g_qe_touch_flag = 0;

            err = RM_TOUCH_DataGet(g_qe_touch_instance_config01.p_ctrl, &button_status, NULL, NULL);
            if (FSP_SUCCESS == err)
            {
                /* TODO: Add your own code here. */
                switch (button_status)
                {
                    case 0x00:
                        r_no_touch();
                        break;

                    case 0x01:
                        r_touch_plus_set_time();
                        break;

                    case 0x02:
                        r_touch_minus_set_time();
                        break;

                    case 0x03:
                        r_touch_both_buttons();
                        break;

                    default:
                        break;
                }
            }

            /* FIXME: Since this is a temporary process, so re-create a waiting process yourself. */
            qe_touch_delay(TOUCH_SCAN_INTERVAL_EXAMPLE);
        }
    }
}

void qe_touch_delay(uint16_t delay_us)
{
    uint32_t i;
    uint32_t loops_required;
    uint16_t clock_mhz;

    clock_mhz = (uint16_t) (R_BSP_GetFclkFreqHz () / 1000000);
    if (0 == clock_mhz)
    {
        clock_mhz = 1;
    }

    loops_required = ((uint32_t) delay_us * (uint32_t) clock_mhz);
    loops_required /= 20;
    for (i = 0; i < loops_required; i++)
    {
        BSP_NOP();
    }
}



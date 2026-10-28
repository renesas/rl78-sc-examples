/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/


#include "r_smc_entry.h"
#include "ADC.h"
#include "INTC.h"
#include "Pin.h"
#include "adc_fpb_rl78g23_ep.h"


volatile uint16_t g_adc_result = 0U;
volatile uint8_t  g_sw1_request = SW1_REQUEST_CLEAR;

/*******************************************************************************************************************//**
 * @addtogroup r_adc_ep
 * @{
 **********************************************************************************************************************/

void main(void)
{
     R_ADC_Set_OperationOn(); /* Enable ADC comparator operation if required */

    EI();
    R_INTC_INTP0_Start();

    while (1)
    {
        HALT(); /* Wait for interrupts (SW1) */

        if (SW1_REQUEST_SET == g_sw1_request)
        {
            g_sw1_request = SW1_REQUEST_CLEAR;

            /* Clear LED1 before conversion (board polarity dependent) */
            PIN_WRITE(LED1) = LED1_OFF;

            /* Start A/D conversion */
            R_ADC_Start();

            /* Store conversion result by r_ADC_interrupt */
            /* Do not call R_ADC_Stop() here to avoid clearing pending INTAD */
        }
    }
}

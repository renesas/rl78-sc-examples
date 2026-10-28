/***********************************************************************************************************************
* Copyright (c) 2020 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/


#ifndef ADC_FPB_RL78G23_EP_H
#define ADC_FPB_RL78G23_EP_H

#include <stdint.h>

/* SW1 request flag */
#define SW1_REQUEST_CLEAR    (0U)
#define SW1_REQUEST_SET      (1U)

/* Bit values */
#define BIT_CLEAR            (0U)
#define BIT_SET              (1U)

/* LED polarity dependent (keep your current meaning) */
#define LED1_OFF             (1U)
#define LED1_ON              (0U)

/* globals */
extern volatile uint16_t g_adc_result;
extern volatile uint8_t g_sw1_request;

#endif /* ADC_FPB_RL78G23_EP_H */

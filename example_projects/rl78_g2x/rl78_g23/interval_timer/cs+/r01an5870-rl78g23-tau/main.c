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
/***********************************************************************/
/*                                                                     */
/*  FILE        :Main.c                                                */
/*  DATE        :                                                      */
/*  DESCRIPTION :Main Program                                          */
/*  CPU TYPE    :                                                      */
/*                                                                     */
/*  NOTE:THIS IS A TYPICAL EXAMPLE.                                    */
/*                                                                     */
/***********************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_smc_entry.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
__saddr uint8_t g_sw_counter = 0U;         /* Variable for counter of SW input */
__saddr uint16_t g_tdr00_work = 0U;        /* Variable of keeping next setting */
__saddr uint8_t g_inttm00_counter = 0U;    /* Variable for counter of INTTM00 */

/* Compare value table for interval timer */
const uint16_t g_tdr00_data[] =
    {
        (64000-1),                /* 2ms interval compare value */
        (32000-1),                /* 1ms interval compare value */
        (16000-1),                /* 0.5ms interval compare value */
        (8000-1)                  /* 0.25ms interval compare value */
    };

/* 10ms wait count value table */
const uint8_t g_10ms_count[] =
    {
        (5+1),                    /* For 2ms interval */
        (10+1),                   /* For 1ms interval */
        (20+1),                   /* For 0.5ms interval */
        (40+1)                    /* For 0.25ms interval */
    };

void main (void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    g_inttm00_counter = 0U;         /* Configuration counter of number of TM00 interrupt */
    g_sw_counter = 0U;              /* Initialization counter of SW input */
    g_tdr00_work = g_tdr00_data[0]; /* Set initial interval */

    R_Config_INTC_INTP0_Start();    /* Enable INTP0 interrupt */
    R_Config_TAU0_0_Start();        /* Start TAU0 channel 0 counter */
    EI();

    /* Wait interrupt */
    while (1U)
    {
        HALT();
    }
}
/******************************************************************************
End of function main
******************************************************************************/

/******************************************************************************
* Function Name: r_invert_led
* Description : This function invert LED function.
* Arguments : none
* Return Value : none
******************************************************************************/
void r_invert_led(void)
{
    if (250 == (++g_inttm00_counter))    /* 250 times interrupt ? */
    {
        TDR00 = g_tdr00_work;            /* Set new timer interval to TAU0 channel 0 */

        P5 ^= 0x08;                      /* Invert LED output */

        g_inttm00_counter = 0U;          /* Clear TM00 interrupt count */
    }
    else
    {
        ;
    }
}
/******************************************************************************
End of function r_invert_led
******************************************************************************/

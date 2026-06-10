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
* Copyright (C) 2021, 2023 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_TRD0_user.c
* Component Version: 1.2.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TRD0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_TRD0_trd0_interrupt(vect=INTTRD0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* TRD0 input capture mode */
volatile uint32_t g_tmrd0_active_width_a = 0UL;
volatile uint32_t g_tmrd0_inactive_width_a = 0UL;
volatile uint32_t g_tmrd0_active_width_b = 0UL;
volatile uint32_t g_tmrd0_inactive_width_b = 0UL;
volatile uint32_t g_tmrd0_active_width_c = 0UL;
volatile uint32_t g_tmrd0_inactive_width_c = 0UL;
volatile uint32_t g_tmrd0_active_width_d = 0UL;
volatile uint32_t g_tmrd0_inactive_width_d = 0UL;
volatile uint32_t g_tmrd0_active_width_elc = 0UL;
volatile uint32_t g_tmrd0_inactive_width_elc = 0UL;
uint16_t g_tmrd0_trdgra_old = 0U;
uint8_t  g_tmrd0_ovf_a = 0U;
/* Start user code for global. Do not edit comment generated here */
uint8_t  g_capture_flg;

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Create_UserInit
* Description  : This function adds user code after initializing the TRD0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */

    TRDOER1  = 0xF5U;        /* TRDIOD0 output disable : Output enabled
                                TRDIOC0 output disable : Output disabled (TRDIOC0 pin functions as an I/O port.)
                                TRDIOB0 output disable : Output enable
                                TRDIOA0 output disable : Output disabled (TRDIOA0 pin functions as an I/O port.) */

    TRDOCR   = 0x00U;        /* TRDIOD0 initial output level select : Low initial output
                                TRDIOB0 initial output level select : Low initial output */

    TRDIORA0 = 0x26U;        /* High output by compare match with TRDGRB0
                                TRDGRB mode select : Output compare function */

    TRDIORC0 = 0xACU;        /* High output by compare match with TRDGRD0
                                TRDGRD mode select : Output compare function */

    TRDGRB0  = 0x3FFFU;      /* Compare value : Set 1/4 of the overflow period(683us) */

    TRDGRD0  = 0x7FFFU;      /* Compare value : Set 1/2 of the overflow period(683us) */

    /* Set TRDIOB0 pin */
    POM1  &= 0xDFU;
    PMCA1 &= 0xDFU;
    P1    &= 0xDFU;
    PM1   &= 0xDFU;

    /* Set TRDIOD0 pin */
    POM1  &= 0xEFU;
    PMCA1 &= 0xEFU;
    P1    &= 0xEFU;
    PM1   &= 0xEFU;

    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_TRD0_trd0_interrupt
* Description  : This function is INTTRD0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_Config_TRD0_trd0_interrupt(void)
{
    uint16_t tmrd_pul_a_cur = TRDGRA0;
    uint8_t trdier0_temp = TRDIER0;

    TRDIER0 = 0x00U;

    /* overflow process */
    if ((TRDSR0 & _10_TRD_INTOV_GENERATE_FLAG) == _10_TRD_INTOV_GENERATE_FLAG)
    {
        TRDSR0 &= (uint8_t)~_10_TRD_INTOV_GENERATE_FLAG;
        g_tmrd0_ovf_a += 1U;
        /* Start user code */

        g_capture_flg |= 0x01U;

        /* End user code */
    }

    /* TRDGRA0 input capture interrupt */
    if ((TRDSR0 & _01_TRD_INTA_GENERATE_FLAG) == _01_TRD_INTA_GENERATE_FLAG)
    {
        TRDSR0 &= (uint8_t)~_01_TRD_INTA_GENERATE_FLAG;
        if (0U == g_tmrd0_ovf_a)
        {
            if ((P1 & 0x80U) == 0x80U)
            {
                g_tmrd0_inactive_width_a = (uint32_t)((uint32_t)tmrd_pul_a_cur - (uint32_t)g_tmrd0_trdgra_old);
                /* Start user code */

                g_capture_flg |= 0x02U;

                /* End user code */
            }
            else
            {
                g_tmrd0_active_width_a = (uint32_t)((uint32_t)tmrd_pul_a_cur - (uint32_t)g_tmrd0_trdgra_old);
                /* Start user code */

                g_capture_flg |= 0x04U;

                /* End user code */
            }
        }
        else
        {
            if ((P1 & 0x80U) == 0x80U)
            {
                g_tmrd0_inactive_width_a = (uint32_t)(((0x10000UL * (uint32_t)g_tmrd0_ovf_a) + (uint32_t)tmrd_pul_a_cur)
                                              - (uint32_t)g_tmrd0_trdgra_old);
                /* Start user code */

                g_capture_flg |= 0x02U;

                /* End user code */
            }
            else
            {
                g_tmrd0_active_width_a = (uint32_t)(((0x10000UL * (uint32_t)g_tmrd0_ovf_a) + (uint32_t)tmrd_pul_a_cur)
                                            - (uint32_t)g_tmrd0_trdgra_old);
                /* Start user code */

                g_capture_flg |= 0x04U;

                /* End user code */
            }
            g_tmrd0_ovf_a = 0U;
        }
        g_tmrd0_trdgra_old = tmrd_pul_a_cur;
    }

    TRDIER0 = trdier0_temp;
    /* Start user code for r_Config_TRD0_trd0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


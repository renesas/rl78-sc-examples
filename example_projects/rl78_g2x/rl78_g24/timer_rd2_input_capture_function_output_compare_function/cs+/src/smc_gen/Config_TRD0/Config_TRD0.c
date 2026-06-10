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
* File Name        : Config_TRD0.c
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
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* TRD0 input capture mode */
extern volatile uint32_t g_tmrd0_active_width_a;
extern volatile uint32_t g_tmrd0_inactive_width_a;
extern volatile uint32_t g_tmrd0_active_width_b;
extern volatile uint32_t g_tmrd0_inactive_width_b;
extern volatile uint32_t g_tmrd0_active_width_c;
extern volatile uint32_t g_tmrd0_inactive_width_c;
extern volatile uint32_t g_tmrd0_active_width_d;
extern volatile uint32_t g_tmrd0_inactive_width_d;
extern volatile uint32_t g_tmrd0_active_width_elc;
extern volatile uint32_t g_tmrd0_inactive_width_elc;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Create
* Description  : This function initializes the TRD0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Create(void)
{
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TRD_TRD0_COUNT_START;    /* disable TRD0 operation */
    TRDMK0 = 1U;    /* disable TRD0 interrupt */
    TRDIF0 = 0U;    /* clear TRD0 interrupt flag */
    /* Set INTTRD0 low priority */
    TRDPR10 = 1U;
    TRDPR00 = 1U;
    TRDMR &= _C1_TRD_TRD0_FUNCTION_CLEAR;
    TRDMR |= (_00_TRD_TRDGRD0_GENERAL | _00_TRD_TRDGRC0_GENERAL);
    TRDDF0 = _C0_TRD_DIGITAL_FILTER_CLOCK_SOURCE | _00_TRD_TRDIOD_DIGITAL_FILTER_DISABLE | 
             _00_TRD_TRDIOC_DIGITAL_FILTER_DISABLE | _00_TRD_TRDIOB_DIGITAL_FILTER_DISABLE | 
             _01_TRD_TRDIOA_DIGITAL_FILTER_ENABLE;
    TRDCR0 = _00_TRD_INTERNAL_CLOCK_FTRD1 | _00_TRD_COUNTER_CLEAR_DISABLE;
    TRDIER0 = _10_TRD_OVIE_ENABLE | _01_TRD_IMIA_ENABLE;
    /* Set TRDGRA0 and TRDGRB0 register function */
    TRDIORA0 = _40_TRD_TRDGRB_CAPTURE | _04_TRD_TRDGRA_CAPTURE | _02_TRD_TRDGRA_CAPTURE_EDGE_BOTH;
    /* Set TRDGRC0 and TRDGRD0 register function */
    TRDIORC0 = _80_TRD_TRDGRD_GENERAL_BUFFER_REGISTER | _08_TRD_TRDGRC_GENERAL_BUFFER_REGISTER | 
               _40_TRD_TRDGRD_CAPTURE | _04_TRD_TRDGRC_CAPTURE;
    /* Set TRDIOA0 pin */
    PMCA1 &= 0x7FU;
    CCDE &= 0xFDU;
    PM1 |= 0x80U;

    R_Config_TRD0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Start
* Description  : This function starts the TRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF0 = 0U;    /* clear INTTRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
    TRDMK0 = 0U;    /* enable INTTRD0 interrupt */
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _01_TRD_TRD0_COUNT_START;    /* start TRD0 counter */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Stop
* Description  : This function stops the TRD0 counter.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_Stop(void)
{
    volatile uint8_t trdsr_dummy;
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR &= (uint8_t)~_01_TRD_TRD0_COUNT_START;    /* stop TRD0 counter */
    TRDMK0 = 1U;    /* disable INTTRD0 interrupt */
    TRDIF0 = 0U;    /* clear INTTRD0 interrupt flag */
    trdsr_dummy = TRDSR0; /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U; /* clear TRD0 each interrupt request */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_Get_PulseWidth
* Description  : This function calculates the TRD0 pulse width.
* Arguments    : active_width -
*                    high-level width
*                inactive_width -
*                    low-level width
*                channel -
*                    register used as capture mode
* Return Value : status -
*                    MD_OK, MD_ERROR or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_Config_TRD0_Get_PulseWidth(uint32_t * const active_width, uint32_t * const inactive_width,
                                        e_timer_channel_t channel)
{
    MD_STATUS status = MD_OK;

    switch (channel)
    {
        case TMCHANNELA:
            if ((TRDIORA0 & _04_TRD_TRDGRA_CAPTURE) == 0U)
            {
                status = MD_ERROR;
            }
            else
            {
                *active_width = g_tmrd0_active_width_a;
                *inactive_width = g_tmrd0_inactive_width_a;
            }

            break;
        case TMCHANNELB:
            if ((TRDIORA0 & _40_TRD_TRDGRB_CAPTURE) == 0U)
            {
                status = MD_ERROR;
            }
            else
            {
                *active_width = g_tmrd0_active_width_b;
                *inactive_width = g_tmrd0_inactive_width_b;
            }

            break;
        case TMCHANNELC:
            if ((TRDIORC0 & _04_TRD_TRDGRC_CAPTURE) == 0U)
            {
                status = MD_ERROR;
            }
            else
            {
                *active_width = g_tmrd0_active_width_c;
                *inactive_width = g_tmrd0_inactive_width_c;
            }

            break;
        case TMCHANNELD:
            if ((TRDIORC0 & _40_TRD_TRDGRD_CAPTURE) == 0U)
            {
                status = MD_ERROR;
            }
            else
            {
                *active_width = g_tmrd0_active_width_d;
                *inactive_width = g_tmrd0_inactive_width_d;
            }

            break;
        case TMCHANNELELC:
            if ((TRDIORC0 & _40_TRD_TRDGRD_CAPTURE) == 0U)
            {
                status = MD_ERROR;
            }
            else
            {
                *active_width = g_tmrd0_active_width_elc;
                *inactive_width = g_tmrd0_inactive_width_elc;
            }

            break;
        default:
            status = MD_ARGERROR;

            break;
    }
    return status;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


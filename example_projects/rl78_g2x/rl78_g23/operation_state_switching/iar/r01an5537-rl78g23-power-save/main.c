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
 * Copyright (C) 2020-2022 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_INTC.h"
#include "Config_PCLBUZ0.h"
#include "r_smc_entry.h"

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint16_t g_transition_status = _00_TRANSITION_STATUS_0;


void main(void);

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    R_Config_INTC_INTP0_Start();
    R_Config_PCLBUZ0_Start();
    EI();
    
    r_switch_flashmode_to_HS();
    g_transition_status = _00_TRANSITION_STATUS_0;

    while (1U)
    {
        HALT();
    }
}

/******************************************************/
/*                                                    */
/*           Flash Mode Switching Functions           */
/*                                                    */
/******************************************************/

void r_switch_flashmode_to_HS(void)
{
    //////* switching process to HS mode, the original purpose, start from here *//////    
    /* switch the flash operation mode. */
    FLMWEN = 1U;
    FLMODE = 0xC0U;            /* HS mode */
    FLMWEN = 0U;

    /* HOCO clock (fIH) is set to 32MHz. */
    HOCODIV = 0x00U;

    P5_bit.no3 = LED_ON;
    P5_bit.no2 = LED_ON;
}

void r_switch_flashmode_to_LS(void)
{
    /* HOCO clock (fIH) is set to 2MHz. */
    HOCODIV = 0x04U;
    
    /* switch the flash operation mode. */
    FLMWEN = 1U;
    FLMODE = 0x80U;           /* LS mode */
    FLMWEN = 0U;

    /* HOCO clock (fIH) is set to 16MHz. */
    HOCODIV = 0x01U;
    
    P5_bit.no3 = LED_ON;
    P5_bit.no2 = LED_OFF;
}

void r_switch_flashmode_to_LP(void)
{
    /* HOCO clock (fIH) is set to 2MHz. */
    HOCODIV = 0x04U;
    
    /* switch the flash operation mode. */
    FLMWEN = 1U;
    FLMODE = 0x40U;           /* LP mode */
    FLMWEN = 0U;
   
    P5_bit.no3 = LED_OFF;
    P5_bit.no2 = LED_ON;
}

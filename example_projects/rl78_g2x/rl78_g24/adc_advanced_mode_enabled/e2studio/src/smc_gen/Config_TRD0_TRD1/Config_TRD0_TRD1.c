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
* File Name        : Config_TRD0_TRD1.c
* Component Version: 1.2.0
* Device(s)        : R7F101GLGxFB
* Description      : This file implements device driver for Config_TRD0_TRD1.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_TRD0_TRD1.h"
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
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Create
* Description  : This function initializes the TRD0 and TRD1 modules.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Create(void)
{
    TRDSTR |= (_04_TRD_TRD0_COUNT_CONTINUES | _08_TRD_TRD1_COUNT_CONTINUES);
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_START_INITIAL_VALUE;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    /* Set INTTRD1 low priority */
    TRDPR11 = 1U;
    TRDPR01 = 1U;
    TRDELC = _00_TRD_ELC0_CUTOFF_DISABLE | _00_TRD_ELC1_CUTOFF_DISABLE;
    TRDFCR &= _FC_TRD_COMBINATION_MODE_CLEAR;
    TRDFCR |= _02_TRD_EXTEND_COMPLE_PWM_MODE;
    TRDMR &= (~_01_TRD_SYNCHRONOUSLY);
    TRDMR |= (_20_TRD_TRDGRD0_BUFFER | _40_TRD_TRDGRC1_BUFFER | _80_TRD_TRDGRD1_BUFFER);
    TRDFCR = _80_TRD_TRDFCR_DEFAULT_VALUE | _20_TRD_EXTEND_PWM_MODE | _00_TRD_PWM_OUTPUT_SYMMETRY | 
             _08_TRD_COUNTER_PHASE_LEVEL_LH | _04_TRD_NORMAL_PHASE_LEVEL_LH | _02_TRD_EXTEND_COMPLE_PWM_MODE;
    TRDPOE = _00_TRD_TRDIOC0_OUTPUT_ENABLE;
    TRDOER1 = _01_TRD_TRDIOA0_OUTPUT_DISABLE | _00_TRD_TRDIOB0_OUTPUT_ENABLE | _00_TRD_TRDIOC0_OUTPUT_ENABLE | 
              _00_TRD_TRDIOD0_OUTPUT_ENABLE | _00_TRD_TRDIOA1_OUTPUT_ENABLE | _00_TRD_TRDIOB1_OUTPUT_ENABLE | 
              _00_TRD_TRDIOC1_OUTPUT_ENABLE | _00_TRD_TRDIOD1_OUTPUT_ENABLE;
    TRDOER2 = _00_TRD_INTP0_CUTOFF_DISABLE;
    TRDCR0 = _00_TRD_INTERNAL_CLOCK_FTRD1;
    TRDCR1 = _00_TRD_INTERNAL_CLOCK_FTRD1;
    TRDIER0 = _00_TRD_IMIA_DISABLE | _00_TRD_IMIB_DISABLE;
    TRDIER1 = _00_TRD_IMIA_DISABLE | _00_TRD_IMIB_DISABLE | _10_TRD_OVIE_ENABLE;
    TRDOCR = _00_TRD_TRDIOC0_NOT_ACTIVE_LEVEL;
    TRD0 = _01E0_TRD_TRD0_VALUE;
    TRDGRC0 = _149E_TRD_TRDGRC0_VALUE;
    TRDGRA0 = _149E_TRD_TRDGRA0_VALUE;
    TRDGRD0 = _095F_TRD_TRDGRD0_VALUE;
    TRDGRB0 = _095F_TRD_TRDGRB0_VALUE;
    TRDGRA1 = _095F_TRD_TRDGRA1_VALUE;
    TRDGRB1 = _095F_TRD_TRDGRB1_VALUE;
    TRDGRC1 = _095F_TRD_TRDGRC1_VALUE;
    TRDGRD1 = _095F_TRD_TRDGRD1_VALUE;
    TRDADCR = _00_TRD_AD_TRIGGER1_DISABLE | _02_TRD_AD0_COMPARE_DOWN | _01_TRD_AD_TRIGGER0_ENABLE;
    TRDADTC0 = _0000_TRD_TRDADTC0_VALUE;
    TRDADTB0 = _0000_TRD_TRDADTB0_VALUE;
    /* Set TRDIOB0 pin */
    POM1 &= 0xDFU;
    PMCA1 &= 0xDFU;
    P1 &= 0xDFU;
    PM1 &= 0xDFU;
    /* Set TRDIOC0 pin */
    PMCA1 &= 0xBFU;
    CCDE &= 0xFEU;
    P1 &= 0xBFU;
    PM1 &= 0xBFU;
    /* Set TRDIOD0 pin */
    POM1 &= 0xEFU;
    PMCA1 &= 0xEFU;
    P1 &= 0xEFU;
    PM1 &= 0xEFU;
    /* Set TRDIOA1 pin */
    POM1 &= 0xF7U;
    PMCA1 &= 0xF7U;
    P1 &= 0xF7U;
    PM1 &= 0xF7U;
    /* Set TRDIOB1 pin */
    POM1 &= 0xFBU;
    PMCA1 &= 0xFBU;
    P1 &= 0xFBU;
    PM1 &= 0xFBU;
    /* Set TRDIOC1 pin */
    POM1 &= 0xFDU;
    PMCA1 &= 0xFDU;
    CCDE &= 0x7FU;
    P1 &= 0xFDU;
    PM1 &= 0xFDU;
    /* Set TRDIOD1 pin */
    POM1 &= 0xFEU;
    PMCA1 &= 0xFEU;
    CCDE &= 0xBFU;
    P1 &= 0xFEU;
    PM1 &= 0xFEU;

    R_Config_TRD0_TRD1_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Start
* Description  : This function starts TRD0 and TRD1 counters.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Start(void)
{
    volatile uint8_t trdsr_dummy;
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR0;    /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U;    /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1;    /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U;    /* clear TRD1 each interrupt request */
    TRDMK1 = 0U;    /* enable TMRD1 interrupt */
    TRDSTR |= _04_TRD_TRD0_COUNT_CONTINUES;
    TRDSTR |= _08_TRD_TRD1_COUNT_CONTINUES;
    TRDSTR |= _03_TRD_COUNT_START_INITIAL_VALUE;    /* start TMRD counter */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Stop
* Description  : This function stops TRD0 and TRD1 counters.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_TRD0_TRD1_Stop(void)
{
    volatile uint8_t trdsr_dummy;

    TRDSTR |= (_04_TRD_TRD0_COUNT_CONTINUES | _08_TRD_TRD1_COUNT_CONTINUES);
    TRDSTR &= (uint8_t)~_03_TRD_COUNT_START_INITIAL_VALUE;
    TRDMK1 = 1U;    /* disable TMRD1 interrupt */
    TRDIF1 = 0U;    /* clear TMRD1 interrupt flag */
    trdsr_dummy = TRDSR0;    /* read TRDSR0 before write 0 */
    TRDSR0 = 0x00U;    /* clear TRD0 each interrupt request */
    trdsr_dummy = TRDSR1;    /* read TRDSR1 before write 0 */
    TRDSR1 = 0x00U;    /* clear TRD1 each interrupt request */
}

/***********************************************************************************************************************
* Function Name: R_Config_TRD0_TRD1_Set_TRD_ReloadTrigger
* Description  : This function generates TRD buffer registers reload trigger.
* Arguments    : buffer -
*                    buffer registers value
* Return Value : status -
*                    MD_OK or MD_ERROR
***********************************************************************************************************************/
MD_STATUS R_Config_TRD0_TRD1_Set_TRD_ReloadTrigger(st_extcompwm_buffer_registers_t * buffer)
{
    MD_STATUS status = MD_OK;

    if (_01_TRD_TRDRSF_RELOAD_WAITING_STATUS == (TRDRSF1 & _01_TRD_TRDRSF_RELOAD_WAITING_STATUS))
    {
        status = MD_ERROR;
    }
    else
    {
        TRDGRD0 = buffer->trdgrd0;
        TRDCMPD0 = buffer->trdcmpd0;
        TRDGRC1 = buffer->trdgrc1;

        TRDCMPC1 = buffer->trdcmpc1;
        TRDGRD1 = buffer->trdgrd1;
        TRDCMPD1 = buffer->trdcmpd1;
        TRDADTB0 = buffer->trdadtb0;
        TRDRDT0 |= _01_TRD_TRDRDT0_RELOAD_REGISTER;
        TRDRDT1 |= _01_TRD_TRDRDT1_RELOAD_REGISTER;
    }

    return status;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


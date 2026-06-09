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
* Copyright (C) 2021, 2024 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : Config_INTC_user.c
* Component Version: 1.4.0
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_INTC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_INTC.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_cg_itl.h"
#include "r_cg_itl_common.h"
#include "Config_ITL000.h"
#include "Config_ITL001.h"
#include "Config_ITL012.h"
#include "Config_ITL013.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_INTC_Create_UserInit
* Description  : This function adds user code after initializing the INTC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_INTC_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_Config_INTC_intp0_interrupt
* Description  : This function is INTP0 interrupt service routine
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
#pragma vector = INTP0_vect
__interrupt static void r_Config_INTC_intp0_interrupt(void)
{
    /* Start user code for r_Config_INTC_intp0_interrupt. Do not edit comment generated here */
    //*********************
    /* Chattering Avoidance */
    //*********************
    int i = 0U;
    int WaitMax = WAITCOUNT_32M;

     for (i=0; i<WaitMax; i++)
    {
        NOP();
    }
    if (1 == P13_bit.no7)
    {
        return;
    }
    else
    {
        /* Do Nothing */
    }
    
    for (i=0; i<WaitMax; i++)
    {
        NOP();
    }
    if (1 == P13_bit.no7)
    {
        return;
    }
    else
    {
        /* Do Nothing */
    }
 
    g_transition_status++;
    if(8 <= g_transition_status)
    {
        g_transition_status = 0;
    }

    ITLMKF0 |= 0x0FU;
    ITLS0 = 0x00U;
    ITLCTL0 &= 0xF0U;
    R_ITL_Stop_Interrupt();
    
    ITLFDIV00 &= _F8_ITL_ITL000_FITL0_CLEAR;
    ITLFDIV00 |= g_itldiv_table[g_transition_status][0];
    ITLFDIV00 &= _8F_ITL_ITL001_FITL0_CLEAR;
    ITLFDIV00 |= g_itldiv_table[g_transition_status][1];
    ITLFDIV01 &= _F8_ITL_ITL012_FITL0_CLEAR;
    ITLFDIV01 |= g_itldiv_table[g_transition_status][2];
    ITLFDIV01 &= _8F_ITL_ITL013_FITL0_CLEAR;
    ITLFDIV01 |= g_itldiv_table[g_transition_status][3];    

    ITLS0 = 0x00U;
    ITLMKF0 &= 0xF0U;
    ITLCTL0 |= 0x0FU;
    R_ITL_Start_Interrupt();
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


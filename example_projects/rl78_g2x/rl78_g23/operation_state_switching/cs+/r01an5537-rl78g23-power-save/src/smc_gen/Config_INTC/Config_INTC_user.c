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
* File Name        : Config_INTC_user.c
* Component Version: 1.4.0
* Device(s)        : R7F100GLGxFA
* Description      : This file implements device driver for Config_INTC.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_INTC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_Config_INTC_intp0_interrupt(vect=INTP0)
/* Start user code for pragma. Do not edit comment generated here */
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
static void __near r_Config_INTC_intp0_interrupt(void)
{
    /* Start user code for r_Config_INTC_intp0_interrupt. Do not edit comment generated here */
    //*********************
    /* Chattering Avoidance */
    //*********************
    int i = 0U;
    int WaitMax = 0;
    
    switch (g_transition_status)
    {
        case    _00_TRANSITION_STATUS_0:         // Now in HS
            WaitMax = WAITCOUNT_32M;
            break;
            
        case    _01_TRANSITION_STATUS_1:        // Now in LS
        case    _03_TRANSITION_STATUS_3:        // Now in LS
            WaitMax = WAITCOUNT_16M;
            break;
            
        case    _02_TRANSITION_STATUS_2:        // Now in LP
            WaitMax = WAITCOUNT_2M;
            break;
            
        default:
        ;
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
    
    //***************
    /* Branch process */
    //***************
    switch (g_transition_status)
    {
        case    _00_TRANSITION_STATUS_0:         // Now in HS. Then going into LS
            r_switch_flashmode_to_LS();
            g_transition_status = _01_TRANSITION_STATUS_1; // go to STATUS_1
            break;
            
        case    _01_TRANSITION_STATUS_1:        // Now in LS. Then going into LP
            r_switch_flashmode_to_LP();
            g_transition_status = _02_TRANSITION_STATUS_2;
            break;
            
        case    _02_TRANSITION_STATUS_2:        // Now in LP. Then going into LS
            r_switch_flashmode_to_LS();
            g_transition_status = _03_TRANSITION_STATUS_3;
            break;
            
        case    _03_TRANSITION_STATUS_3:        // Now in LS. Then going into HS
            r_switch_flashmode_to_HS();
            g_transition_status = _00_TRANSITION_STATUS_0;
            break;
            
        default:
        ;
    }
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

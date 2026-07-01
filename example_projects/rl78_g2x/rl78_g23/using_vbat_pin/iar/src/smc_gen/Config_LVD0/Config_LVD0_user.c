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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : Config_LVD0_user.c
* Version      : 1.1.0
* Device(s)    : R7F100GLGxFB
* Description  : This file implements device driver for Config_LVD0.
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
#include "Config_LVD0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static int g_vdd_down = _00_VDD_NOT_DOWN;
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_LVD0_Create_UserInit
* Description  : This function adds user code after initializing the voltage detector.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_LVD0_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/***********************************************************************************************************************
* Function Name: r_is_vdd_over
* Description  : This function returns the status of VDD
* Arguments    : None
* Return Value : 1 -
*                    supply voltage (VDD) >= detection voltage (VLVD0)
*                0 -
*                    supply voltage (VDD) < detection voltage (VLVD0)
***********************************************************************************************************************/
int r_is_vdd_over(void)
{
    return (_00_LVD0_FLAG_OVER == LVD0F);
}

/***********************************************************************************************************************
* Function Name: r_set_vdd_down_flag
* Description  : This function set VDD down flag
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void r_set_vdd_down_flag(void)
{
    g_vdd_down = _01_VDD_DOWN;
}

/***********************************************************************************************************************
* Function Name: r_is_vdd_down
* Description  : This function returns the down status of VDD
* Arguments    : None
* Return Value : 1 -
*                    VDD wend down even onse
*                0 -
*                    VDD has never gone down
***********************************************************************************************************************/
int r_is_vdd_down(void)
{
    int vdd_down;

    DI();
    vdd_down = g_vdd_down;
    g_vdd_down = _00_VDD_NOT_DOWN;
    EI();
    
    return (_01_VDD_DOWN==vdd_down);
}
/* End user code. Do not edit comment generated here */


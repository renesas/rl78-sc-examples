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
* File Name    : r_cg_comp_common.c
* Version      : 1.0.1
* Device(s)    : R7F100GLGxFA
* Description  : None
* Creation Date: 2021-06-01
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_COMP0.h"
#include "Config_COMP1.h"
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
* Function Name: R_COMP_Create
* Description  : This function initializes the comparator module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_COMP_Create(void)
{
    CMPEN = 1U;     /* starts COMP clock */
    /* Set COMP settings */
    R_Config_COMP0_Create();
    R_Config_COMP1_Create();
}

/***********************************************************************************************************************
* Function Name: R_COMP_Set_PowerOn
* Description  : This function starts the clock supply for comparator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_COMP_Set_PowerOn(void)
{
    CMPEN = 1U;     /* starts input clock supply */
}

/***********************************************************************************************************************
* Function Name: R_COMP_Set_PowerOff
* Description  : This function stops the clock supply for comparator.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_COMP_Set_PowerOff(void)
{
    CMPEN = 0U;     /* stops input clock supply */
}

/***********************************************************************************************************************
* Function Name: R_COMP_Set_Reset
* Description  : This function sets comparator module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_COMP_Set_Reset(void)
{
    CMPRES = 1U;    /* resets comparator */
}

/***********************************************************************************************************************
* Function Name: R_COMP_Release_Reset
* Description  : This function releases comparator module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_COMP_Release_Reset(void)
{
    CMPRES = 0U;    /* releases reset comparator */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

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
* File Name        : r_cg_pgacomp_common.c
* Version          : 1.0.20
* Device(s)        : R7F101GLGxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_COMP1.h"
#include "r_cg_pgacomp_common.h"
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
* Function Name: R_PGACOMP_Create
* Description  : This function initializes the comparator or programmable gain amplifier module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGACOMP_Create(void)
{
    PGACMPEN = 1U;    /* starts PGA, COMP clock */
    /* Set COMP settings */
    R_Config_COMP1_Create();
}

/***********************************************************************************************************************
* Function Name: R_PGACOMP_Set_PowerOn
* Description  : This function starts the clock supply for comparator or programmable gain amplifier.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGACOMP_Set_PowerOn(void)
{
    PGACMPEN = 1U;    /* start PGA, COMP clock */
}

/***********************************************************************************************************************
* Function Name: R_PGACOMP_Set_PowerOff
* Description  : This function stops the clock supply for comparator or programmable gain amplifier.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGACOMP_Set_PowerOff(void)
{
    PGACMPEN = 0U;    /* stop PGA, COMP clock */
}

/***********************************************************************************************************************
* Function Name: R_PGACOMP_Set_Reset
* Description  : This function sets comparator or programmable gain amplifier module in reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGACOMP_Set_Reset(void)
{
    PGACMPRES = 1U;    /* reset PGA, COMP */
}

/***********************************************************************************************************************
* Function Name: R_PGACOMP_Release_Reset
* Description  : This function releases comparator or programmable gain amplifier module from reset state.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_PGACOMP_Release_Reset(void)
{
    PGACMPRES = 0U;    /* release PGA, COMP */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


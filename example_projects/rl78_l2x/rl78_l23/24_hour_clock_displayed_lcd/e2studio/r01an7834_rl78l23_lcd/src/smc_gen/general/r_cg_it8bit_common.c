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
* Copyright (C) 2021, 2025 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name        : r_cg_it8bit_common.c
* Version          : 1.0.41
* Device(s)        : R7F100LPLxFB
* Description      : None
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "Config_IT00.h"
#include "Config_IT01.h"
#include "r_cg_it8bit_common.h"
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
* Function Name: R_IT0_Create
* Description  : This function enables IT0 input clock supply and initializes IT0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT0_Create(void)
{
    TRTCR0_bit.no4 = 1U;    /* start IT0 clock */
    /* Set IT0 settings */
    R_Config_IT00_Create();
    R_Config_IT01_Create();
}

/***********************************************************************************************************************
* Function Name: R_IT1_Create
* Description  : This function enables IT1 input clock supply and initializes IT1 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT1_Create(void)
{
    TRTCR1_bit.no4 = 1U;    /* start IT1 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT2_Create
* Description  : This function enables IT2 input clock supply and initializes IT2 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT2_Create(void)
{
    TRTCR2_bit.no4 = 1U;    /* start IT2 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT3_Create
* Description  : This function enables IT3 input clock supply and initializes IT3 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT3_Create(void)
{
    TRTCR3_bit.no4 = 1U;    /* start IT3 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT4_Create
* Description  : This function enables IT4 input clock supply and initializes IT4 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT4_Create(void)
{
    TRTCR4_bit.no4 = 1U;    /* start IT4 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT5_Create
* Description  : This function enables IT5 input clock supply and initializes IT5 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT5_Create(void)
{
    TRTCR5_bit.no4 = 1U;    /* start IT5 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT6_Create
* Description  : This function enables IT6 input clock supply and initializes IT6 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT6_Create(void)
{
    TRTCR6_bit.no4 = 1U;    /* start IT6 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT7_Create
* Description  : This function enables IT7 input clock supply and initializes IT7 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT7_Create(void)
{
    TRTCR7_bit.no4 = 1U;    /* start IT7 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT0_Set_PowerOn
* Description  : This function starts the clock supply for IT0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT0_Set_PowerOn(void)
{
    TRTCR0_bit.no4 = 1U;    /* start IT0 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT0_Set_PowerOff
* Description  : This function stops the clock supply for IT0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT0_Set_PowerOff(void)
{
    TRTCR0_bit.no4 = 0U;    /* stop IT0 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT1_Set_PowerOn
* Description  : This function starts the clock supply for IT1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT1_Set_PowerOn(void)
{
    TRTCR1_bit.no4 = 1U;    /* start IT1 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT1_Set_PowerOff
* Description  : This function stops the clock supply for IT1.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT1_Set_PowerOff(void)
{
    TRTCR1_bit.no4 = 0U;    /* stop IT1 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT2_Set_PowerOn
* Description  : This function starts the clock supply for IT2.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT2_Set_PowerOn(void)
{
    TRTCR2_bit.no4 = 1U;    /* start IT2 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT2_Set_PowerOff
* Description  : This function stops the clock supply for IT2.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT2_Set_PowerOff(void)
{
    TRTCR2_bit.no4 = 0U;    /* stop IT2 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT3_Set_PowerOn
* Description  : This function starts the clock supply for IT3.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT3_Set_PowerOn(void)
{
    TRTCR3_bit.no4 = 1U;    /* start IT3 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT3_Set_PowerOff
* Description  : This function stops the clock supply for IT3.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT3_Set_PowerOff(void)
{
    TRTCR3_bit.no4 = 0U;    /* stop IT3 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT4_Set_PowerOn
* Description  : This function starts the clock supply for IT4.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT4_Set_PowerOn(void)
{
    TRTCR4_bit.no4 = 1U;    /* start IT4 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT4_Set_PowerOff
* Description  : This function stops the clock supply for IT4.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT4_Set_PowerOff(void)
{
    TRTCR4_bit.no4 = 0U;    /* stop IT4 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT5_Set_PowerOn
* Description  : This function starts the clock supply for IT5.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT5_Set_PowerOn(void)
{
    TRTCR5_bit.no4 = 1U;    /* start IT5 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT5_Set_PowerOff
* Description  : This function stops the clock supply for IT5.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT5_Set_PowerOff(void)
{
    TRTCR5_bit.no4 = 0U;    /* stop IT5 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT6_Set_PowerOn
* Description  : This function starts the clock supply for IT6.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT6_Set_PowerOn(void)
{
    TRTCR6_bit.no4 = 1U;    /* start IT6 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT6_Set_PowerOff
* Description  : This function stops the clock supply for IT6.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT6_Set_PowerOff(void)
{
    TRTCR6_bit.no4 = 0U;    /* stop IT6 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT7_Set_PowerOn
* Description  : This function starts the clock supply for IT7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT7_Set_PowerOn(void)
{
    TRTCR7_bit.no4 = 1U;    /* start IT7 clock */
}

/***********************************************************************************************************************
* Function Name: R_IT7_Set_PowerOff
* Description  : This function stops the clock supply for IT7.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IT7_Set_PowerOff(void)
{
    TRTCR7_bit.no4 = 0U;    /* stop IT7 clock */
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

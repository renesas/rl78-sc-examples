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
* File Name        : Config_ELC.c
* Component Version: 1.2.0
* Device(s)        : R7F102GGExFB
* Description      : This file implements device driver for Config_ELC.
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
#include "Config_ELC.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_Config_ELC_Create
* Description  : This function initializes the ELC module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_Config_ELC_Create(void)
{
    ELSELR01 = _07_ELC_EVENT_LINK_TML32;

    R_Config_ELC_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_Config_ELC_Stop
* Description  : This function stops the ELC event resources.
* Arguments    : event -
*                    event resources to be stoped (bit n for ELSELRn)
* Return Value : None
***********************************************************************************************************************/
void R_Config_ELC_Stop(uint32_t event)
{
    volatile uint32_t w_count;
    uint8_t * p_sfr_addr;

    p_sfr_addr = (uint8_t *) &ELSELR00;

    for (w_count = 0U; w_count < _ELC_DESTINATION_COUNT; w_count++ )
    {
        if (((event >> w_count) & 0x1U) == 0x1U)
        {
            *p_sfr_addr = _00_ELC_EVENT_LINK_DISABLE;
        }

        p_sfr_addr++;
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

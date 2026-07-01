/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No 
* other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all 
* applicable laws, including copyright laws. 
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, 
* FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM 
* EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES 
* SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS 
* SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of 
* this software. By using this software, you agree to the additional terms and conditions found by accessing the 
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2021 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : vecttbl.c
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 22.04.2021 1.10     Added support of Security ID Codes for On-Chip Debugging (When using IAR).
*         : 25.05.2021 1.11     Renamed following macro definitions.
*                               - BSP_CFG_OPTBYTE0_VALUE
*                               - BSP_CFG_OPTBYTE1_VALUE
*                               - BSP_CFG_OPTBYTE2_VALUE
*                               - BSP_CFG_OPTBYTE3_VALUE

***********************************************************************************************************************/

/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Private global variables and functions
 *************************************************/
/* Option byte setting(When using IAR) */
#pragma location = "OPTBYTE"
__root const uint8_t opbyte0 = BSP_CFG_OPTBYTE0_VALUE;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte1 = BSP_CFG_OPTBYTE1_VALUE;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte2 = BSP_CFG_OPTBYTE2_VALUE;
#pragma location = "OPTBYTE"
__root const uint8_t opbyte3 = BSP_CFG_OPTBYTE3_VALUE;

/* Security ID Codes for On-Chip Debugging setting(When using IAR) */
#pragma location = "SECUID"
__root const uint8_t secuid[10] =
{BSP_CFG_SECUID0_VALUE, BSP_CFG_SECUID1_VALUE, BSP_CFG_SECUID2_VALUE, BSP_CFG_SECUID3_VALUE, BSP_CFG_SECUID4_VALUE,
 BSP_CFG_SECUID5_VALUE, BSP_CFG_SECUID6_VALUE, BSP_CFG_SECUID7_VALUE, BSP_CFG_SECUID8_VALUE, BSP_CFG_SECUID9_VALUE};

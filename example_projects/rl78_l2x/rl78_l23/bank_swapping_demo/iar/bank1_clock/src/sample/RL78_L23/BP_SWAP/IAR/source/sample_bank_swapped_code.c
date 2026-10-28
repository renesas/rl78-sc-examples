/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Programming & Bank Swap)
    
    File Name       : sample_bank_swapped_code.c
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample program for swapped bank code
**********************************************************************************************************************/

/**********************************************************************************************************************
    DISCLAIMER
    This software is supplied by Renesas Electronics Corporation and is only intended for use with
    Renesas products. No other uses are authorized. This software is owned by Renesas Electronics
    Corporation and is protected under all applicable laws, including copyright laws.
    THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING THIS SOFTWARE,
    WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
    TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR
    ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR
    CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
    BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
    Renesas reserves the right, without notice, to make changes to this software and to discontinue the
    availability of this software. By using this software, you agree to the additional terms and conditions
    found by accessing the following link:
    http://www.renesas.com/disclaimer
    
    Copyright (C) 2024,2025 Renesas Electronics Corporation. All rights reserved.
**********************************************************************************************************************/

/**********************************************************************************************************************
 Includes   <System Includes> , "Project Includes"
 *********************************************************************************************************************/
#include "sample_bank_swapped_code.h"

#include "ior7f100lpl.h"
#include "ior7f100lpl_ext.h"

/**********************************************************************************************************************
 * Function name : sample_bank_swapped_code
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_BPS
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Sample codes to execute after bank swap.
 *  Turn on the LED and loop infinitely.
 *  
 *  @param[in]      -
 *  @return         ---
 */
/*********************************************************************************************************************/
void sample_bank_swapped_code(void)
{
    /* This function is just sample codes to execute after bank swap */
    /* Do not write complicated codes or any function call in this function */
    
    /* Example code : Turn on the LED connected to P64 */
    /* Set port mode to output mode */
    /* PM6_bit.no4 = 0; */
    /* Turn on the LED (Low) */
    /* P6_bit.no4 = 0; */
    
    while (1)
    {
        /* An endless loop */
    }
}

#define  SAMPLE_END_SECTION_SMP_BPS
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function sample_bank_swapped_code
 *********************************************************************************************************************/

/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Programming & Bank Swap)
    
    File Name       : sample_initsct_bank_swap.c
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample program to copy the sections for bank programming & bank swap control
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
#include "sample_initsct_bank_swap.h"

/**********************************************************************************************************************
 Macro definitions
 *********************************************************************************************************************/
/* The number of the sections to be copied */
#define SAMPLE_VALUE_U16_COPYSEC_MAX (3u)

/**********************************************************************************************************************
 Static global variables
 *********************************************************************************************************************/

/**
 * @struct st_sample_copysec_t
 * Sample copy section table for bank programming & bank swap
 */
static const struct st_sample_copysec_t
{
    uint8_t __far  * copy_rom_sectop;  /* Copy source section top address */
    uint8_t __far  * copy_rom_secend;  /* Copy source section end address+1 */
    uint8_t __near * copy_ram_sectop;  /* Copy destination section top address */
} sg_st_copysec_table[SAMPLE_VALUE_U16_COPYSEC_MAX] = {
    {(uint8_t __far  *)__sectop("RFD_DATA_n"),
     (uint8_t __far  *)__secend("RFD_DATA_n"),
     (uint8_t __near *)__sectop("RFD_DATA_nR")},
    {(uint8_t __far  *)__sectop("RFD_EX_f"),
     (uint8_t __far  *)__secend("RFD_EX_f"),
     (uint8_t __near *)__sectop("RFD_EX_fR")},
    {(uint8_t __far  *)__sectop("SMP_EX_f"),
     (uint8_t __far  *)__secend("SMP_EX_f"),
     (uint8_t __near *)__sectop("SMP_EX_fR")}};

/**********************************************************************************************************************
 * Function name : Sample_INITSCT_BankSwap
 *********************************************************************************************************************/
/**
 *  Sample function to copy the sections for bank programming & bank swap control.
 *  
 *  @param[in]      -
 *  @return         ---
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC void Sample_INITSCT_BankSwap(void)
{
    /* Local variable definition */
    uint16_t         l_u16_count;
    uint8_t __far  * lfp_u08_rom;
    uint8_t __near * lnp_u08_ram;
    
    /* Copy the sections */
    for (l_u16_count = 0; l_u16_count < SAMPLE_VALUE_U16_COPYSEC_MAX; l_u16_count++)
    {
        lfp_u08_rom = sg_st_copysec_table[l_u16_count].copy_rom_sectop;
        lnp_u08_ram = sg_st_copysec_table[l_u16_count].copy_ram_sectop;
        while (lfp_u08_rom != sg_st_copysec_table[l_u16_count].copy_rom_secend)
        {
            *lnp_u08_ram = *lfp_u08_rom;
            lfp_u08_rom++;
            lnp_u08_ram++;
        }
    }
}
/**********************************************************************************************************************
 End of function Sample_INITSCT_BankSwap
 *********************************************************************************************************************/

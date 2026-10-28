/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Programming)
    
    File Name       : sample_control_bank_programming.c
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample program for bank programming control
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
#include "sample_control_bank_programming.h"
#include "sample_defines.h"
#include "sample_config.h"

#include "r_rfd.h"
#include "r_rfd_code_flash_control_api.h"
#include "r_rfd_code_flash_api.h"

#if (COMPILER_CC == COMPILER)
#include "iodefine.h"
#elif (COMPILER_IAR == COMPILER)
#include "ior7f100lpl.h"
#include "ior7f100lpl_ext.h"
#elif (COMPILER_LLVM == COMPILER)
#include "iodefine.h"
#include "iodefine_ext.h"
#endif

/**********************************************************************************************************************
 * Function name : Sample_BankProgrammingControl
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_CF
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Sample function for bank programming control.
 *  BlankCheck -> Erase -> Write (Bank Programming)
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK               : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED  : Mode mismatched error
 *                  - SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA : Check write data error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_ERASE        : Erase command error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_WRITE        : Write command error
 *                  - SAMPLE_ENUM_RET_ERR_CMD_BLANKCHECK   : Blankcheck command error
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_sample_ret_t Sample_BankProgrammingControl(void)
{
    /* Local variable definition */
    e_rfd_ret_t     l_e_rfd_ret_status;
    e_sample_ret_t  l_e_sam_ret_status;
    e_sample_ret_t  l_e_sam_ret_value;
    bool            l_e_sam_error_flag;
    uint16_t        l_u16_count;
    uint16_t        l_u16_block_number_0_swapped_bank;
    uint16_t        l_u16_block_number_swapped_bank_code;
    uint32_t        l_u32_check_write_data_addr;
    uint32_t        l_u32_source_write_data_addr;
    uint8_t         l_au08_write_data[4];
    
    /* Set local variables */
    l_e_sam_ret_value   = SAMPLE_ENUM_RET_STS_OK;
    l_e_sam_error_flag  = false;
    
    /* This expression (actual block number) never exceeds the range of casting uint16_t */
    l_u16_block_number_0_swapped_bank 
      = (uint16_t)(START_ADDRESS_BANK_PROGRAMMING >> SAMPLE_VALUE_U08_SHIFT_ADDR_TO_BLOCK_CF);
    l_u16_block_number_swapped_bank_code 
      = (uint16_t)(WRITE_ADDRESS_SWAPPED_CODE >> SAMPLE_VALUE_U08_SHIFT_ADDR_TO_BLOCK_CF);
    l_u32_check_write_data_addr  = WRITE_ADDRESS_SWAPPED_CODE;
    l_u32_source_write_data_addr = READ_ADDRESS_SWAPPED_CODE;
    
    /******************************************************************************************************************
     * Set the bank programming mode
     *****************************************************************************************************************/
    FLMWEN = 1u;
    FLMODE = (FLMODE & 0xC0u) | 0x02u;
    FLMWEN = 0u;
    
    /******************************************************************************************************************
     * Set the code flash programming mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetCFProgrammingMode();
    
    if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * BLANKCHECK -> ERASE (Block 0 after bank swap)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        /* BLANKCHECK (1 block) */
        R_RFD_BlankCheckCodeFlashReq(l_u16_block_number_0_swapped_bank);
        l_e_sam_ret_status = Sample_CheckCFSeqEnd();
        
        if (SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK == l_e_sam_ret_status)
        {
            /* ERASE (1 block) */
            R_RFD_EraseCodeFlashReq(l_u16_block_number_0_swapped_bank);
            l_e_sam_ret_status = Sample_CheckCFSeqEnd();
            
            if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
            {
                l_e_sam_error_flag = true;
                l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_ERASE;
            }
            else
            {
                /* No operation */
            }
        }
        else if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_BLANKCHECK;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * WRITE (Reset vector for swapped bank)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        /* Set the write data for reset vector */
        l_au08_write_data[0] = (uint8_t)(RESET_VECTOR_SWAPPED_BANK & SAMPLE_VALUE_U08_MASK1_8BIT);
        l_au08_write_data[1] = (uint8_t)((RESET_VECTOR_SWAPPED_BANK >> 8) & SAMPLE_VALUE_U08_MASK1_8BIT);
        l_au08_write_data[2] = SAMPLE_VALUE_U08_MASK1_8BIT;
        l_au08_write_data[3] = SAMPLE_VALUE_U08_MASK1_8BIT;
        
        /* WRITE (reset vector) */
        R_RFD_WriteCodeFlashReq(WRITE_ADDRESS_RESET_VECTOR, &l_au08_write_data[0]);
        l_e_sam_ret_status = Sample_CheckCFSeqEnd();
        if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_WRITE;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * WRITE (Option byte data for swapped bank)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        /* Set the write data for option byte */
        l_au08_write_data[0] = (uint8_t)((OPTION_BYTE_SWAPPED_BANK >> 16) & SAMPLE_VALUE_U08_MASK1_8BIT);
        l_au08_write_data[1] = (uint8_t)((OPTION_BYTE_SWAPPED_BANK >> 8) & SAMPLE_VALUE_U08_MASK1_8BIT);
        l_au08_write_data[2] = (uint8_t)(OPTION_BYTE_SWAPPED_BANK & SAMPLE_VALUE_U08_MASK1_8BIT);
        l_au08_write_data[3] = OPTION_BYTE_OCD_SWAPPED_BANK;
        
        /* WRITE (option byte) */
        R_RFD_WriteCodeFlashReq(WRITE_ADDRESS_OPTION_BYTE, &l_au08_write_data[0]);
        l_e_sam_ret_status = Sample_CheckCFSeqEnd();
        
        if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_WRITE;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * WRITE (OCD (On-Chip Debug) security ID fixed to 00000000000000000000)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        l_au08_write_data[0] = SAMPLE_VALUE_U08_MASK0_8BIT;
        l_au08_write_data[1] = SAMPLE_VALUE_U08_MASK0_8BIT;
        l_au08_write_data[2] = SAMPLE_VALUE_U08_MASK0_8BIT;
        l_au08_write_data[3] = SAMPLE_VALUE_U08_MASK0_8BIT;
        for (l_u16_count = 0u; l_u16_count < 12u; l_u16_count += 4u)
        {
            /* Reset write data beyond the size of OCD security ID (10 bytes) */
            if (8u == l_u16_count)
            {
                l_au08_write_data[2] = SAMPLE_VALUE_U08_MASK1_8BIT;
                l_au08_write_data[3] = SAMPLE_VALUE_U08_MASK1_8BIT;
            }
            else
            {
                /* No operation */
            }
            
            /* WRITE (OCD security ID) */
            R_RFD_WriteCodeFlashReq(WRITE_ADDRESS_OCD_SECURITY_ID + l_u16_count, &l_au08_write_data[0]);
            l_e_sam_ret_status = Sample_CheckCFSeqEnd();
            
            if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
            {
                l_e_sam_error_flag = true;
                l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_WRITE;
                break;
            }
            else
            {
                /* No operation */
            }
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * BLANKCHECK -> ERASE (Program for swapped bank code)(1 block)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        /* BLANKCHECK (1 block) */
        R_RFD_BlankCheckCodeFlashReq(l_u16_block_number_swapped_bank_code);
        l_e_sam_ret_status = Sample_CheckCFSeqEnd();
        
        if (SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK == l_e_sam_ret_status)
        {
            /* ERASE (1 block) */
            R_RFD_EraseCodeFlashReq(l_u16_block_number_swapped_bank_code);
            l_e_sam_ret_status = Sample_CheckCFSeqEnd();
            
            if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
            {
                l_e_sam_error_flag = true;
                l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_ERASE;
            }
            else
            {
                /* No operation */
            }
        }
        else if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
        {
            l_e_sam_error_flag = true;
            l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_BLANKCHECK;
        }
        else
        {
            /* No operation */
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    /******************************************************************************************************************
     * WRITE (Program for swapped bank code)(1 block)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        for (l_u16_count = 0u; l_u16_count < SAMPLE_VALUE_U16_CODE_FLASH_BLOCK_SIZE; l_u16_count += 4u)
        {
            /* Read codes from READ_ADDRESS_SWAPPED_CODE and set write data */
            l_au08_write_data[0] = (*(uint8_t __far *)(((uint32_t)READ_ADDRESS_SWAPPED_CODE) + l_u16_count));
            l_au08_write_data[1] = (*(uint8_t __far *)(((uint32_t)READ_ADDRESS_SWAPPED_CODE) + l_u16_count + 0x01u));
            l_au08_write_data[2] = (*(uint8_t __far *)(((uint32_t)READ_ADDRESS_SWAPPED_CODE) + l_u16_count + 0x02u));
            l_au08_write_data[3] = (*(uint8_t __far *)(((uint32_t)READ_ADDRESS_SWAPPED_CODE) + l_u16_count + 0x03u));
            
            R_RFD_WriteCodeFlashReq(WRITE_ADDRESS_SWAPPED_CODE + l_u16_count, &l_au08_write_data[0]);
            l_e_sam_ret_status = Sample_CheckCFSeqEnd();
            
            if (SAMPLE_ENUM_RET_STS_OK != l_e_sam_ret_status)
            {
                l_e_sam_error_flag = true;
                l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CMD_WRITE;
                break;
            }
            else
            {
                /* No operation */
            }
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set non-programmable mode
     *****************************************************************************************************************/
    l_e_rfd_ret_status = R_RFD_SetCFNonProgrammableMode();
    
    if (R_RFD_ENUM_RET_STS_OK != l_e_rfd_ret_status)
    {
        l_e_sam_error_flag = true;
        l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_MODE_MISMATCHED;
    }
    else
    {
        /* No operation */
    }
    
    /******************************************************************************************************************
     * Set the user mode (Exit from the bank programming mode)
     *****************************************************************************************************************/
    FLMWEN = 1u;
    FLMODE = FLMODE & 0xC0u;
    FLMWEN = 0u;
    
    /******************************************************************************************************************
     * Check write data for program for swapped bank code (1 block)
     *****************************************************************************************************************/
    if (false == l_e_sam_error_flag)
    {
        for (l_u16_count = 0u; l_u16_count < SAMPLE_VALUE_U16_CODE_FLASH_BLOCK_SIZE; l_u16_count++)
        {
            if ((*(uint8_t __far *)(l_u32_check_write_data_addr)) != (*(uint8_t __far *)(l_u32_source_write_data_addr)))
            {
                l_e_sam_error_flag = true;
                l_e_sam_ret_value  = SAMPLE_ENUM_RET_ERR_CHECK_WRITE_DATA;
                break;
            }
            else
            {
                /* No operation */
            }
            l_u32_check_write_data_addr++;
            l_u32_source_write_data_addr++;
        }
    }
    else /* true == l_e_sam_error_flag */
    {
        /* No operation */
    }
    
    return (l_e_sam_ret_value);
}

#define  SAMPLE_END_SECTION_SMP_CF
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function Sample_BankProgrammingControl
 *********************************************************************************************************************/


/**********************************************************************************************************************
 * Function name : Sample_CheckCFSeqEnd
 *********************************************************************************************************************/
#define  SAMPLE_START_SECTION_SMP_CF
#include "sample_memmap.h"
/*********************************************************************************************************************/
/**
 *  Check the state of the code/data flash memory sequencer and result.
 *  
 *  @param[in]      -
 *  @return         Execution result status
 *                  - SAMPLE_ENUM_RET_STS_OK             : Successful completion
 *                  - SAMPLE_ENUM_RET_ERR_CFDF_SEQUENCER : CF/DF sequencer error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_ERASE      : Erase action error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_WRITE      : Write action error
 *                  - SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK : Blankcheck action error
 */
/*********************************************************************************************************************/
R_RFD_FAR_FUNC e_sample_ret_t Sample_CheckCFSeqEnd(void)
{
    /* Local variable definition */
    e_sample_ret_t l_e_sam_ret_value;
    uint8_t        l_u08_status_flag;
    
    /* Set local variables */
    l_e_sam_ret_value = SAMPLE_ENUM_RET_STS_OK;
    
    /* Sequencer busy loop step1 */
    while (R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckCFSeqEndStep1())
    {
        /* No operation */
        /* It is possible to write the program for detecting timeout here as necessity requires */
    }
    
    /* Sequencer busy loop step2 */
    while (R_RFD_ENUM_RET_STS_BUSY == R_RFD_CheckCFSeqEndStep2())
    {
        /* No operation */
        /* It is possible to write the program for detecting timeout here as necessity requires */
    }
    
    /* Action error check */
    R_RFD_GetCFSeqErrorStatus(&l_u08_status_flag);
    
    /* Check error status */
    if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_CFDF_SEQUENCER))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_CFDF_SEQUENCER;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_ERASE))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_ERASE;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_WRITE))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_WRITE;
    }
    else if (SAMPLE_VALUE_U08_MASK0_8BIT != (l_u08_status_flag & SAMPLE_VALUE_U08_MASK1_FSQ_STATUS_ERR_BLANKCHECK))
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_ERR_ACT_BLANKCHECK;
    }
    else
    {
        /* Set return value */
        l_e_sam_ret_value = SAMPLE_ENUM_RET_STS_OK;
    }
    
    /* Clear sequencer registers */
    R_RFD_ClearCFSeqRegister();
    
    return (l_e_sam_ret_value);
}

#define  SAMPLE_END_SECTION_SMP_CF
#include "sample_memmap.h"
/**********************************************************************************************************************
 End of function Sample_CheckCFSeqEnd
 *********************************************************************************************************************/

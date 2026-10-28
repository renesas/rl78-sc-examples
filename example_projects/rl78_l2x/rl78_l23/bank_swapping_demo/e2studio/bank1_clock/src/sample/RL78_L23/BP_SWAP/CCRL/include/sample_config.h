/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Programming & Bank Swap)
    
    File Name       : sample_config.h
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample user configurable parameters file
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

#ifndef SAMPLE_CONFIG_H
#define SAMPLE_CONFIG_H

/**********************************************************************************************************************
  User configurable parameters
**********************************************************************************************************************/

/**** CPU frequency (MHz) ****/
/* It must be rounded up digits after the decimal point to form an integer (MHz). */
#define CPU_FREQUENCY                       (32u)

/**** Reset vector for swapped bank ****/
#define RESET_VECTOR_SWAPPED_BANK           (0x5000u)

/**** Option byte data for swapped bank ****/
#define OPTION_BYTE_SWAPPED_BANK            (0x6EFFE8uL)

/**** Option byte data for swapped bank ****/
#define OPTION_BYTE_OCD_SWAPPED_BANK        (0x85u)

/**** Start address of bank programming area ****/
/* It should be the head address of the bank programming area. */
#define START_ADDRESS_BANK_PROGRAMMING      (0x00040000uL)

/**** Address to write reset vector data for swapped bank ****/
#define WRITE_ADDRESS_RESET_VECTOR          (START_ADDRESS_BANK_PROGRAMMING + 0x0000u)

/**** Address to write option byte data for swapped bank ****/
#define WRITE_ADDRESS_OPTION_BYTE           (START_ADDRESS_BANK_PROGRAMMING + 0x00C0u)

/**** Address to write OCD (On-Chip Debug) security ID data for swapped bank ****/
#define WRITE_ADDRESS_OCD_SECURITY_ID       (START_ADDRESS_BANK_PROGRAMMING + 0x00C4u)

/**** Address to read the target code to be swapped ****/
/* It must be the head address of the flash block and the start address of the section SMP_BPS */
#define READ_ADDRESS_SWAPPED_CODE           (0x6000u)

/**** Address to write the target code to be swapped ****/
#define WRITE_ADDRESS_SWAPPED_CODE          (START_ADDRESS_BANK_PROGRAMMING + RESET_VECTOR_SWAPPED_BANK)

#endif /* end of SAMPLE_CONFIG_H */

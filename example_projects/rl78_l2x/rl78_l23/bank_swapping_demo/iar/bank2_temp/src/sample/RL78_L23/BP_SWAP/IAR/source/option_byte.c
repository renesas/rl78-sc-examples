/**********************************************************************************************************************
    Program Name    : Sample program for Renesas Flash Driver (RFD RL78 Type11) (Bank Programming & Bank Swap)
    
    File Name       : option_byte.c
    Program Version : V1.00.00
    Device(s)       : RL78/L23 microcontroller
    Description     : Sample option byte setting
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
 * Option byte setting
 *********************************************************************************************************************/
//#pragma location = "OPTBYTE"
//__root const unsigned char option_bytes[4] = {
//    0x6E,   /* 01101110 */
//            /* |||||||| */
//            /* |||||||+-- Watchdog timer     */
//            /* |||||||    operation stopped  */
//            /* |||||||    in HALT/STOP mode  */
//            /* ||||+++--- Watchdog timer     */
//            /* ||||       overflow time is   */
//            /* ||||       2^17 / fIL =       */
//            /* ||||       3478.26 ms         */
//            /* |||+------ Watchdog timer     */
//            /* |||        operation disabled */
//            /* |++------- 100% window open   */
//            /* |          period             */
//            /* +--------- Interval interrupt */
//            /*            is not used        */
//    0xFF,   /* 11111111 */
//            /*        | */
//            /*        +-- LVD reset mode */
//    0xE8,   /* HS mode 32 MHz */
//    0x85    /* OCD: enables on-chip debugging function */
//};

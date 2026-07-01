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
* File Name        : r_cg_userdefine.h
* Version          : 1.0.13
* Device(s)        : R7F100GLGxFA
* Description      : User header file for code generation.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

#ifndef USER_DEF_H
#define USER_DEF_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/* Start user code for register. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Start user code for macro define. Do not edit comment generated here */
/* LED ON/OFF states. The bit4-0 are indicated as LED5-LED1. */
typedef enum {
    R_LED_STATE_A    = 0x00,     /* 0b00000; after-reset */
    R_LED_STATE_B    = 0x13,     /* 0b10011; high-speed-on-chip-oscillator-clock(working) */
    R_LED_STATE_C    = 0x0B,     /* 0b01011; id-speed-on-chip-oscillator-clock(working) */
    R_LED_STATE_D    = 0x17,     /* 0b10111; high-speed-system-clock(working) */
    R_LED_STATE_E    = 0x0F,     /* 0b01111; sub-system-clock(working) */
    R_LED_STATE_F    = 0x1B,     /* 0b11011; low-speed-on-chip-oscillator-clock(working) */
    R_LED_STATE_G    = 0x12,     /* 0b10010; high-speed-on-chip-oscillator-clock(halt) */
    R_LED_STATE_H    = 0x10,     /* 0b10000; high-speed-on-chip-oscillator-clock(stop) */
    R_LED_STATE_I    = 0x11,     /* 0b10001; high-speed-on-chip-oscillator-clock(snooze) */
    R_LED_STATE_J    = 0x0A,     /* 0b01010; mid-speed-on-chip-oscillator-clock(halt) */
    R_LED_STATE_K    = 0x08,     /* 0b01000; mid-speed-on-chip-oscillator-clock(stop) */
    R_LED_STATE_L    = 0x09,     /* 0b01001; mid-speed-on-chip-oscillator-clock(snooze) */
    R_LED_STATE_M    = 0x16,     /* 0b10110; high-speed-system-clock(halt) */
    R_LED_STATE_N    = 0x14,     /* 0b10100; high-speed-system-clock(stop) */
    R_LED_STATE_O    = 0x0E,     /* 0b01110; sub-system-clock(halt) */
    R_LED_STATE_P    = 0x1A,     /* 0b11010; ow-speed-on-chip-oscillator-clock(halt) */
    R_LED_STATE_Q    = 0x18,     /* 0b11000; high-speed-on-chip-oscillator(stop on high-speed-awakening) */
    R_LED_STATE_END  = 0x1F,     /* 0b11111; end */
} r_main_LED_state_t;

/* fCLK modes. This will be used to set CKC registers. */
typedef enum {
   R_fCLK_fMAIN_fOCO_HIGH = 0x01,
   R_fCLK_fMAIN_fOCO_MID  = 0x02,
   R_fCLK_fMAIN_fOCO_LOW  = 0x03,
   R_fCLK_fMAIN_fMX       = 0x08,
   R_fCLK_fSUB            = 0x10,
} r_fclk_mode_t;

/* Awaken modes. */
typedef enum {
   R_NORMAL_AWAKEN        = 0U,
   R_HIGHSPEED_AWAKEN     = 1U,
} r_awaken_mode_t;

/* Mask to port type. */
typedef enum {
   R_CONFIG_PORT_NEGATIVE_MASK        = 0U,
   R_CONFIG_PORT_POSITIVE_MASK        = 1U,
} r_config_port_mask_t;

#define R_MSEC_PER_COUNT                  (33UL)    /* ref. fSXL = 32.768kHz */
#define R_WAIT_OSTC_COUNT                 (0xD0U)
#define R_WAIT_MSEC_HIGH_OCO              (4UL)
#define R_WAIT_MSEC_MID_OCO               (4UL)
#define R_WAIT_MSEC_LOW_OCO               (4UL)
#define R_WAIT_MSEC_XT1                   (4UL)
#define R_WAIT_MSEC_CHATTERING            (5UL)
#define R_WAIT_MSEC_SNOOZE                (20000UL)

#define _0_INTERRUPT_FLAG_OFF                (0U)
#define _1_INTERRUPT_FLAG_ON                 (1U)
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
/* Start user code for type define. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

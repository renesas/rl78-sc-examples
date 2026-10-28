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
* File Name        : r_cg_userdefine.h
* Version          : 1.0.41
* Device(s)        : R7F100LPLxFA
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
#define FLAG_CLEAR			(0)
#define FLAG_SET			(1)
#define BLINK_OFF			(1)
#define BLINK_ON				(2)
#define BLINK_SKIPPED		(0)		/* Constant value used to determine whether the process was executed. */
#define BLINK_HANDLED		(1)		/* Constant value used to determine whether the process was executed. */
#define WATCH_DISPLAY		(0)	/* Display status(time display) */
#define HOUR_ADJUST		(1)	/* Display status(hour adjust) */
#define MINUTE_ADJUST		(2)	/* Display status(minute adjust) */
#define MAX_MIN				(59)		/* Maximum value of seconds and minutes */
#define MAX_HOUR			(23)		/* Maximum value of hours */
#define LONG_PRESS_THRESHOLD  (100)	/* Threshold value for long press detection. */
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
void r_main_userinit(void);
void r_lcd_show(uint8_t value, uint8_t digit);
void r_lcd_blinking_show(uint8_t value, uint8_t digit);
void r_time_show(uint8_t blinking_colon);
void r_minutes_adjust_show(void);
void  r_hours_adjust_show(void);
void r_rtc_get_counter_value(void);
void r_rtc_set_counter_value(void);
void r_increment_time(uint8_t *time_val, uint8_t max_val);
void r_handle_watch_display(void);
void r_handle_time_adjust(uint8_t *val, uint8_t max_val, uint8_t blink_digit);
uint8_t r_handle_blink(uint8_t blink_digit);
/* End user code. Do not edit comment generated here */
#endif

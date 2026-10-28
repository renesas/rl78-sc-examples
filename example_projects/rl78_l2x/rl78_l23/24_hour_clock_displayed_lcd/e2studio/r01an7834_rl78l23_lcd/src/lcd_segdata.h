/**********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO
 * THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2020-2022 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/
/***********************************************************************/
/*  FILE        :lcd_segdata.h                                         			*/
/*  DESCRIPTION :segment data for LCD                                  	*/
/***********************************************************************/
/* Segment data for RL78/L23 FPB */

/*********************************
 Const data
*********************************/
    /* VIM-878-DP(LCD) segment */
    /* CA, F, E, D *//* I, J, K, L *//* H, G, N, M *//* A, B, C, DP */
const uint8_t g_show_segdata[15][4] = {
    {0x77, 0x00, 0x00, 0xEE},		/* 0 */
    {0x00, 0x00, 0x00, 0x66},		/* 1 */
    {0x33, 0x22, 0x44, 0xCC},		/* 2 */
    {0x11, 0x22, 0x44, 0xEE},		/* 3 */
    {0x44, 0x22, 0x44, 0x66},		/* 4 */
    {0x55, 0x22, 0x44, 0xAA},		/* 5 */
    {0x77, 0x22, 0x44, 0xAA},		/* 6 */
    {0x44, 0x00, 0x00, 0xEE},		/* 7 */
    {0x77, 0x22, 0x44, 0xEE},		/* 8 */
    {0x55, 0x22, 0x44, 0xEE},		/* 9 */
    {0xFF, 0xFF, 0xFF, 0xFF},		/* all segments */
    {0x00, 0x00, 0x00, 0x11},		/* comma (11) */
    {0x00, 0x00, 0x00, 0x00},		/* space (12) */
    {0x00, 0x44, 0x22, 0x00},		/* slash (13) */
    {0x00, 0x88, 0x11, 0x00},		/* colon (14) */
};

const uint8_t g_blinking_show_segdata[15][4] = {
    {0x07, 0x00, 0x00, 0x0E},		/* 0 */
    {0x00, 0x00, 0x00, 0x06},		/* 1 */
    {0x03, 0x02, 0x04, 0x0C},		/* 2 */
    {0x01, 0x02, 0x04, 0x0E},		/* 3 */
    {0x04, 0x02, 0x04, 0x06},		/* 4 */
    {0x05, 0x02, 0x04, 0x0A},		/* 5 */
    {0x07, 0x02, 0x04, 0x0A},		/* 6 */
    {0x04, 0x00, 0x00, 0x0E},		/* 7 */
    {0x07, 0x02, 0x04, 0x0E},		/* 8 */
    {0x05, 0x02, 0x04, 0x0E},		/* 9 */
    {0x0F, 0x0F, 0x0F, 0x0F},		/* all segments */
    {0x00, 0x00, 0x00, 0x01},		/* comma (11) */
    {0x00, 0x00, 0x00, 0x00},		/* space (12) */
    {0x00, 0x04, 0x02, 0x00},		/* slash (13) */
    {0x00, 0x08, 0x01, 0x00},		/* colon (14) */
};

const uint8_t g_digit_segdata[8][4] = {
    {0x08, 0x07, 0x0C, 0x0D},		/* 1 (far left) */
    {0x06, 0x05, 0x0E, 0x0F},		/* 2 */
    {0x04, 0x03, 0x10, 0x11},		/* 3 */
    {0x02, 0x01, 0x14, 0x15},		/* 4 */
    {0x00, 0x32, 0x1C, 0x33},		/* 5 */
    {0x31, 0x30, 0x34, 0x35},		/* 6 */
    {0x2F, 0x27, 0x36, 0x37},		/* 7 */
    {0x26, 0x25, 0x23, 0x24},		/* 8 (far right) */
};

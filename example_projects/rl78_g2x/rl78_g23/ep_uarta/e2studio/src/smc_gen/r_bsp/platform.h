/*
* Copyright (c) 2021 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : platform.h
* Description  : The user chooses which MCU and board they are developing for in this file. If the board you are using
*                is not listed below, please add your own or use the default 'User Board'.
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 08.03.2021 1.00     First Release
*         : 28.02.2022 1.20     Added RL78F23,RL78F24
*         : 31.05.2022 1.30     Added RL78G15
*         : 11.11.2022 1.40     Added RL78G22
*         : 31.01.2023 1.50     Added RL78G16
*         : 28.02.2023 1.60     Added RL78G24
*         : 07.06.2024 1.70     Added RL78F25
*         : 09.08.2024 1.80     Added RL78F22
*         : 29.11.2024 1.90     Added RL78L23
*         : 04.07.2025 1.92     Changed the disclaimer.
*         : 10.12.2025 2.00     Added RL78G21
***********************************************************************************************************************/

/* Multiple inclusion prevention macro */
#ifndef PLATFORM_H
#define PLATFORM_H

/***********************************************************************************************************************
DEFINE YOUR SYSTEM - UNCOMMENT THE INCLUDE PATH FOR THE PLATFORM YOU ARE USING.
***********************************************************************************************************************/
// GENERIC_RL78_G23
#include "./board/generic_rl78_g23/r_bsp.h"

// GENERIC_RL78_F23
//#include "./board/generic_rl78_f23/r_bsp.h"

// GENERIC_RL78_F24
//#include "./board/generic_rl78_f24/r_bsp.h"

// GENERIC_RL78_G15
//#include "./board/generic_rl78_g15/r_bsp.h"

// GENERIC_RL78_G22
//#include "./board/generic_rl78_g22/r_bsp.h"

// GENERIC_RL78_G16
//#include "./board/generic_rl78_g16/r_bsp.h"

// GENERIC_RL78_G24
//#include "./board/generic_rl78_g24/r_bsp.h"

// GENERIC_RL78_F25
//#include "./board/generic_rl78_f25/r_bsp.h"

// GENERIC_RL78_F22
//#include "./board/generic_rl78_f22/r_bsp.h"

// GENERIC_RL78_L23
//#include "./board/generic_rl78_l23/r_bsp.h"

// GENERIC_RL78_G21
//#include "./board/generic_rl78_g21/r_bsp.h"

/***********************************************************************************************************************
MAKE SURE AT LEAST ONE PLATFORM WAS DEFINED - DO NOT EDIT BELOW THIS POINT
***********************************************************************************************************************/
#ifndef PLATFORM_DEFINED
#error  "Error - No platform defined in platform.h!"
#endif

#endif /* PLATFORM_H */

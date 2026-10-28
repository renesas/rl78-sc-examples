/*
* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/
/***********************************************************************************************************************
* File Name    : r_bsp.h
* H/W Platform : GENERIC_RL78_G21
* Description  : 
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 10.12.2025 2.00     First Release
***********************************************************************************************************************/
/* Make sure that no other platforms have already been defined. Do not touch this! */
#ifdef  PLATFORM_DEFINED
#error  "Error - Multiple platforms defined in platform.h!"
#else
#define PLATFORM_DEFINED
#endif


/***********************************************************************************************************************
INCLUDE APPROPRIATE MCU AND BOARD FILES
***********************************************************************************************************************/
#include    "r_bsp_config.h"
#include    "mcu/all/r_bsp_rl78_compiler.h"
#include    "mcu/all/r_bsp_common.h"
#include    "mcu/all/r_rtos.h"

#include    "mcu/all/fsp_common_api.h"
#include    "mcu/all/r_fsp_error.h"

#if defined(__CCRL__)
#include    "mcu/rl78_g21/register_access/ccrl/iodefine.h"
#elif defined(__ICCRL78__)
#include "mcu/rl78_g21/register_access/iccrl/iodefine.h"
#include "mcu/rl78_g21/register_access/iccrl/iodefine_ext.h"
#include "mcu/rl78_g21/register_access/iccrl/intrinsics.h"
#elif defined(__llvm__)
#include "mcu/rl78_g21/register_access/llvm/iodefine.h"
#include "mcu/rl78_g21/register_access/llvm/iodefine_ext.h"
#endif /* defined(__CCRL__), defined(__ICCRL__), defined(__llvm__) */

#include    "mcu/rl78_g21/mcu_clocks.h"
#include    "mcu/rl78_g21/mcu_info.h"

#include    "board/generic_rl78_g21/hdwinit.h"

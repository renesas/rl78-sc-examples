
/* Make sure that no other platforms have already been defined. Do not touch this! */
#ifdef  PLATFORM_DEFINED
#error  "Error - Multiple platforms defined in platform.h!"
#else
#define PLATFORM_DEFINED
#endif


/***********************************************************************************************************************
INCLUDE APPROPRIATE MCU AND BOARD FILES
***********************************************************************************************************************/
#include    "mcu/all/r_bsp_common.h"
#include    "mcu/all/r_bsp_rl78_compiler.h"

#include    "r_bsp_config.h"


#if defined(__CCRL__)
#include    "mcu/rl78_g23/register_access/ccrl/iodefine.h"
#elif defined(__ICCRL78__)
#include "mcu/rl78_g23/register_access/iccrl/ior7f100glg.h"
#include "mcu/rl78_g23/register_access/iccrl/ior7f100glg_ext.h"
#include "mcu/rl78_g23/register_access/iccrl/intrinsics.h"
#elif defined(__llvm__)
#include "mcu/rl78_g23/register_access/llvm/iodefine.h"
#include "mcu/rl78_g23/register_access/llvm/iodefine_ext.h"
#endif /* defined(__CCRL__), defined(__ICCRL__), defined(__llvm__) */

#include    "mcu/rl78_g23/mcu_clocks.h"
#include    "mcu/rl78_g23/mcu_info.h"

#include    "board/generic_rl78_g23/hdwinit.h"



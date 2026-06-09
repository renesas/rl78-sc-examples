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
 * Copyright (C) 2024 Renesas Electronics Corporation. All rights reserved.
 *********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "r_cg_itl.h"
#include "r_cg_itl_common.h"
#include "Config_INTC.h"
#include "Config_ITL000.h"
#include "Config_ITL001.h"
#include "Config_ITL012.h"
#include "Config_ITL013.h"
/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
uint16_t g_transition_status = 0;
uint8_t  g_itldiv_table[][4] =
{
    {    _00_ITL_ITL000_FITL0_1  , _20_ITL_ITL001_FITL0_4  , _04_ITL_ITL012_FITL0_16 , _60_ITL_ITL013_FITL0_64  },
    {    _01_ITL_ITL000_FITL0_2  , _30_ITL_ITL001_FITL0_8  , _05_ITL_ITL012_FITL0_32 , _70_ITL_ITL013_FITL0_128 },
    {    _02_ITL_ITL000_FITL0_4  , _40_ITL_ITL001_FITL0_16 , _06_ITL_ITL012_FITL0_64 , _00_ITL_ITL013_FITL0_1   },
    {    _03_ITL_ITL000_FITL0_8  , _50_ITL_ITL001_FITL0_32 , _07_ITL_ITL012_FITL0_128, _10_ITL_ITL013_FITL0_2   },
    {    _04_ITL_ITL000_FITL0_16 , _60_ITL_ITL001_FITL0_64 , _00_ITL_ITL012_FITL0_1  , _20_ITL_ITL013_FITL0_4   },
    {    _05_ITL_ITL000_FITL0_32 , _70_ITL_ITL001_FITL0_128, _01_ITL_ITL012_FITL0_2  , _30_ITL_ITL013_FITL0_8   },
    {    _06_ITL_ITL000_FITL0_64 , _00_ITL_ITL001_FITL0_1  , _02_ITL_ITL012_FITL0_4  , _40_ITL_ITL013_FITL0_16  },
    {    _07_ITL_ITL000_FITL0_128, _10_ITL_ITL001_FITL0_2  , _03_ITL_ITL012_FITL0_8  , _50_ITL_ITL013_FITL0_32  }
};
int16_t g_inttm00_counter = 0;
int16_t g_inttm01_counter = 0;
int16_t g_inttm02_counter = 0;
int16_t g_inttm03_counter = 0;

void main(void);
void UserInit(void);
/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    UserInit();

    while (1U)
    {
        HALT();
    }
}

/***********************************************************************************************************************
* Function Name: UserInit
* Description  : This function adds user code before implementing main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void UserInit(void)
{
    R_Config_INTC_INTP0_Start();
    ITLS0 = 0x00U;
    ITLMKF0 &= 0xF0U;
    ITLCTL0 |= 0x0FU;
    R_ITL_Start_Interrupt();
    EI();
}

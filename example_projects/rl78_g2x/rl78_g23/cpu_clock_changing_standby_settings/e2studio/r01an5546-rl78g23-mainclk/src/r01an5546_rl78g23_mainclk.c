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
* Copyright (C) 2020 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_port.h"
#include "r_cg_intc.h"
#include "r_cg_ad.h"
#include "r_cg_itl.h"
#include "r_cg_itl_common.h"
#include "r_cg_rtc.h"
/* Start user code for include. Do not edit comment generated here */
#include "Config_PORT.h"
#include "Config_INTC.h"
#include "Config_ADC.h"
#include "Config_ITL000_ITL001_ITL012_ITL013.h"
#include "Config_RTC.h"
/* End user code. Do not edit comment generated here */
#include "r_cg_userdefine.h"

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
/* Start user code for global. Do not edit comment generated here */
static void r_AtoB(void);
static void r_BtoE(void);
static void r_EtoO(void);
static void r_OtoE(void);
static void r_EtoB(void);
static void r_BtoD(void);
static void r_DtoE(void);
static void r_EtoD(void);
static void r_DtoM(void);
static void r_MtoD(void);
static void r_DtoN(void);
static void r_NtoD(void);
static void r_DtoB(void);
static void r_BtoG(void);
static void r_GtoB(void);
static void r_BtoH(void);
static void r_HtoB(void);
static void r_BtoI(void);
static void r_ItoB(void);
static void r_BtoC(void);
static void r_CtoD(void);
static void r_DtoF(void);
static void r_FtoD(void);
static void r_DtoC(void);
static void r_CtoJ(void);
static void r_JtoC(void);
static void r_CtoK(void);
static void r_KtoC(void);
static void r_CtoL(void);
static void r_LtoC(void);
static void r_CtoE(void);
static void r_EtoC(void);
static void r_CtoF(void);
static void r_FtoC(void);
static void r_CtoB(void);
static void r_BtoF(void);
static void r_FtoP(void);
static void r_PtoF(void);
static void r_FtoB(void);
static void r_BtoQ(void);
static void r_QtoB(void);
static void r_end(void);

static void r_nop_loop(void);
static void r_halt(void);
static void r_stop(void);
static void r_snooze(void);

static void r_start_high_oco(void);
static void r_start_mid_oco(void);
static void r_start_low_oco(void);
static void r_start_x1(void);
static void r_start_xt1(void);
static void r_stop_high_oco(void);
static void r_stop_mid_oco(void);
static void r_stop_low_oco(void);
static void r_stop_x1(void);
static void r_stop_xt1(void);
static void r_set_fclk(r_fclk_mode_t mode);
static void r_set_high_speed_awakening(r_awaken_mode_t flag);

static void r_wait_OSTC(void);

static void r_user_init(void);
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: main
* Description  : This function implements main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void main(void)
{
    r_user_init();
    /* Start user code. Do not edit comment generated here */
    {
        /* Initialize Clock-Generator registers */
        /* CMC register can set once only. It has already set in mcu_clocks.c.
        CMC = 0x51;
        */
        /*    0b01010001;
                |||||||+------- AMPH (1: 10MHz<fx<=32MHz)
                |||||++-------- AMPHS1,AMPHS0 (00: low-consumption-oscillation 1)
                ||||+---------- XTSEL (Read Only)
                ||++----------- EXCLKS,OSCSELS (01: XT1 oscillation mode)
                ++------------- EXCLK,OSCSEL (01: X1 oscillation mode)
        */
        OSMC = 0x91;
        /*     0b0010001;
                 |||||||+------ HIPREC (1: A highOSC runs with high precision)
                 ||||||+------- Must be 0
                 ||||++-------- Unused
                 |||+---------- WUTMMCK0 (1: A 32 bit interval timer uses a low-OSC)
                 |++----------- Must be 0
                 +------------- RTCLPC (0: A subsystem-clock provides for peripheral devices)
        */

        EI();                              /* Enable the interrupts. */

        r_AtoB();
        r_BtoE();
        r_EtoO();
        r_OtoE();
        r_EtoB();
        r_BtoD();
        r_DtoE();
        r_EtoD();
        r_DtoM();
        r_MtoD();
        r_DtoN();
        r_NtoD();
        r_DtoB();
        r_BtoG();
        r_GtoB();
        r_BtoH();
        r_HtoB();
        r_BtoI();
        r_ItoB();
        r_BtoC();
        r_CtoD();
        r_DtoF();
        r_FtoD();
        r_DtoC();
        r_CtoJ();
        r_JtoC();
        r_CtoK();
        r_KtoC();
        r_CtoL();
        r_LtoC();
        r_CtoE();
        r_EtoC();
        r_CtoF();
        r_FtoC();
        r_CtoB();
        r_BtoF();
        r_FtoP();
        r_PtoF();
        r_FtoB();
        r_BtoQ();
        r_QtoB();
        r_end();

        /* Loop for eternally. */
        while (1U)
        {
            HALT();
        }
    }
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_user_init
* Description  : This function adds user codes before the main function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_user_init(void)
{
    /* Start user code. Do not edit comment generated here */
    DI();                                  /* Disable the interrupts. */
    /* End user code. Do not edit comment generated here */
}

/* Start user code for adding. Do not edit comment generated here */
/**********************************************************************************************************************
 * Function Name: r_AtoB
 ******************************************************************************************************************//**
 * @brief Change a state from after-reset to high-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_AtoB(void)
{
    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoE
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to sub-system-clock(working).
 * @param none
 * @return none
 */
static void r_BtoE(void)
{
    /* OSMC and CMC register has been set. */
    r_start_xt1();
    r_set_fclk(R_fCLK_fSUB);
    r_stop_high_oco();

    r_port_set_LED(R_LED_STATE_E);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_EtoO
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to sub-system-clock(halt).
 * @param none
 * @return none
 */
static void r_EtoO(void)
{
    r_port_set_LED(R_LED_STATE_O);

    r_halt();
}
/**********************************************************************************************************************
 * Function Name: r_OtoE
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(halt) to sub-system-clock(working).
 * @param none
 * @return none
 */
static void r_OtoE(void)
{
    /* HALT-mode has been removed by INTP0. */
    r_port_set_LED(R_LED_STATE_E);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_EtoB
 ******************************************************************************************************************//**
 * @brief Change a state from sub-system-clock(working) to high-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_EtoB(void)
{
    r_start_high_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_HIGH);
    r_stop_xt1();

    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoD
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_BtoD(void)
{
    /* CMC and OSTS register has been set. */
    r_start_x1();
    r_set_fclk(R_fCLK_fMAIN_fMX);
    r_stop_high_oco();

    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoE
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(working) to sub-system-clock(working).
 * @param none
 * @return none
 */
static void r_DtoE(void)
{
    /* OSMC and CMC register has been set. */
    r_start_xt1();
    r_set_fclk(R_fCLK_fSUB);
    r_stop_x1();

    r_port_set_LED(R_LED_STATE_E);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_EtoD
 ******************************************************************************************************************//**
 * @brief Change a state from sub-system-clock(working) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_EtoD(void)
{
    /* CMC and OSTC register has been set. */
    r_start_x1();
    r_set_fclk(R_fCLK_fMAIN_fMX);
    r_stop_xt1();

    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoM
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(working) to high-speed-system-clock(halt).
 * @param none
 * @return none
 */
static void r_DtoM(void)
{
    r_port_set_LED(R_LED_STATE_M);

    r_halt();
}
/**********************************************************************************************************************
 * Function Name: r_MtoD
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(halt) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_MtoD(void)
{
    /* HALT-mode has been removed by INTP0. */
    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoN
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(working) to high-speed-system-clock(stop).
 * @param none
 * @return none
 */
static void r_DtoN(void)
{
    r_port_set_LED(R_LED_STATE_N);

    r_stop();
}
/**********************************************************************************************************************
 * Function Name: r_NtoD
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(stop) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_NtoD(void)
{
    /* STOP-mode has been removed by INTP0. */
    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoB
 ******************************************************************************************************************//**
 * @brief Change a state from  high-speed-system-clock(working).to high-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_DtoB(void)
{
    r_start_high_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_HIGH);
    r_stop_x1();

    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoG
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to 
 *        high-speed-on-chip-oscillator-clock(halt) 
 * @param none
 * @return none
 */
static void r_BtoG(void)
{
    r_port_set_LED(R_LED_STATE_G);

    r_halt();
}
/**********************************************************************************************************************
 * Function Name: r_GtoB
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(halt) to 
 *        high-speed-on-chip-oscillator-clock(working) 
 * @param none
 * @return none
 */
static void r_GtoB(void)
{
    /* HALT-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoH
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to 
 *        high-speed-on-chip-oscillator-clock(stop) 
 * @param none
 * @return none
 */
static void r_BtoH(void)
{
    r_port_set_LED(R_LED_STATE_H);

    r_stop();
}
/**********************************************************************************************************************
 * Function Name: r_HtoB
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(stop) to 
 *        high-speed-on-chip-oscillator-clock(working) 
 * @param none
 * @return none
 */
static void r_HtoB(void)
{
    /* STOP-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoI
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to 
 *        high-speed-on-chip-oscillator-clock(snooze) 
 * @param none
 * @return none
 */
static void r_BtoI(void)
{
    r_port_set_LED(R_LED_STATE_I);

    r_snooze();
}
/**********************************************************************************************************************
 * Function Name: r_ItoB
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(snooze) to 
 *        high-speed-on-chip-oscillator-clock(working) 
 * @param none
 * @return none
 */
static void r_ItoB(void)
{
    /* SNOOZE-mode has been removed by INTAD or INTLVI. */
    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoC
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to 
 *        mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_BtoC(void)
{
    r_start_mid_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_MID);
    r_stop_high_oco();

    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoD
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_CtoD(void)
{
    /* CMC and OSTS register has been set. */
    r_start_x1();
    r_set_fclk(R_fCLK_fMAIN_fMX);
    r_stop_mid_oco();

    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoF
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(working) to low-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_DtoF(void)
{
    r_start_low_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_LOW);
    r_stop_x1();

    r_port_set_LED(R_LED_STATE_F);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_FtoD
 ******************************************************************************************************************//**
 * @brief Change a state from low-speed-on-chip-oscillator-clock(working) to high-speed-system-clock(working).
 * @param none
 * @return none
 */
static void r_FtoD(void)
{
    /* CMC and OSTS register has been set. */
    r_start_x1();
    r_set_fclk(R_fCLK_fMAIN_fMX);
    r_stop_low_oco();

    r_port_set_LED(R_LED_STATE_D);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_DtoC
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-system-clock(working) to mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_DtoC(void)
{
    r_start_mid_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_MID);
    r_stop_x1();

    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoJ
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to 
 *        mid-speed-on-chip-oscillator-clock(halt).
 * @param none
 * @return none
 */
static void r_CtoJ(void)
{
    r_port_set_LED(R_LED_STATE_J);

    r_halt();
}
/**********************************************************************************************************************
 * Function Name: r_JtoC
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(halt) to 
 *        mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_JtoC(void)
{
    /* HALT-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoK
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to 
 *        mid-speed-on-chip-oscillator-clock(stop).
 * @param none
 * @return none
 */
static void r_CtoK(void)
{
    r_port_set_LED(R_LED_STATE_K);

    r_stop();
}
/**********************************************************************************************************************
 * Function Name: r_KtoC
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(stop) to 
 *        mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_KtoC(void)
{
    /* STOP-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoL
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to 
 *        mid-speed-on-chip-oscillator-clock(snooze).
 * @param none
 * @return none
 */
static void r_CtoL(void)
{
    r_port_set_LED(R_LED_STATE_L);

    r_snooze();
}
/**********************************************************************************************************************
 * Function Name: r_JtoC
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(snooze) to 
 *        mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_LtoC(void)
{
    /* SNOOZE-mode has been removed by INTAD or INTLVI. */
    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoE
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to sub-system-clock(working).
 * @param none
 * @return none
 */
static void r_CtoE(void)
{
    /* OSMC and CMC register has been set. */
    r_start_xt1();
    r_set_fclk(R_fCLK_fSUB);
    r_stop_mid_oco();

    r_port_set_LED(R_LED_STATE_E);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_EtoC
 ******************************************************************************************************************//**
 * @brief Change a state from sub-system-clock(working) to mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_EtoC(void)
{
    r_start_mid_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_MID);
    r_stop_xt1();

    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoF
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to
 *        low-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_CtoF(void)
{
    r_start_low_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_LOW);
    r_stop_mid_oco();

    r_port_set_LED(R_LED_STATE_F);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_FtoC
 ******************************************************************************************************************//**
 * @brief Change a state from low-speed-on-chip-oscillator-clock(working) to
 *        mid-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_FtoC(void)
{
    r_start_mid_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_MID);
    r_stop_low_oco();

    r_port_set_LED(R_LED_STATE_C);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_CtoB
 ******************************************************************************************************************//**
 * @brief Change a state from mid-speed-on-chip-oscillator-clock(working) to
 *        high-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_CtoB(void)
{
    r_start_high_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_HIGH);
    r_stop_mid_oco();

    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoF
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to
 *        low-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_BtoF(void)
{
    r_start_low_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_LOW);
    r_stop_high_oco();

    r_port_set_LED(R_LED_STATE_F);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_FtoP
 ******************************************************************************************************************//**
 * @brief Change a state from low-speed-on-chip-oscillator-clock(working) to 
          low-speed-on-chip-oscillator-clock(halt).
* @param none
 * @return none
 */
static void r_FtoP(void)
{
    r_port_set_LED(R_LED_STATE_P);

    r_halt();
}
/**********************************************************************************************************************
 * Function Name: r_PtoF
 ******************************************************************************************************************//**
 * @brief Change a state from low-speed-on-chip-oscillator-clock(halt) to 
          low-speed-on-chip-oscillator-clock(working).
* @param none
 * @return none
 */
static void r_PtoF(void)
{
    /* HALT-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_F);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_FtoB
 ******************************************************************************************************************//**
 * @brief Change a state from low-speed-on-chip-oscillator-clock(working) to 
          high-speed-on-chip-oscillator-clock(working).
* @param none
 * @return none
 */
static void r_FtoB(void)
{
    r_start_high_oco();
    r_set_fclk(R_fCLK_fMAIN_fOCO_HIGH);
    r_stop_low_oco();

    r_port_set_LED(R_LED_STATE_B);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_BtoQ
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(working) to 
 *        high-speed-on-chip-oscillator-clock(stop on high-speed-awakening).
 * @param none
 * @return none
 */
static void r_BtoQ(void)
{
    r_set_high_speed_awakening(R_HIGHSPEED_AWAKEN);

    r_port_set_LED(R_LED_STATE_Q);

    r_stop();
}
/**********************************************************************************************************************
 * Function Name: r_QtoB
 ******************************************************************************************************************//**
 * @brief Change a state from high-speed-on-chip-oscillator-clock(stop on high-speed-awakening) to 
 *        high-speed-on-chip-oscillator-clock(working).
 * @param none
 * @return none
 */
static void r_QtoB(void)
{
    /* HALT-mode has been removed by INTP0 or INTLVI. */
    r_port_set_LED(R_LED_STATE_B);

    r_set_high_speed_awakening(R_NORMAL_AWAKEN);

    r_nop_loop();
}
/**********************************************************************************************************************
 * Function Name: r_end
 ******************************************************************************************************************//**
 * @brief Change a state to end.
 * @param none
 * @return none
 */
static void r_end(void)
{
    DI();
    r_port_set_LED(R_LED_STATE_END);
}
/**********************************************************************************************************************
 * Function Name: r_nop_loop
 ******************************************************************************************************************//**
 * @brief Wait with NOPs.
 * @param none
 * @return none
 */
static void r_nop_loop(void)
{
    r_intp0_clear_flag();      /* Clear the INTP0 interrupt flag. */
    R_Config_INTC_INTP0_Start();           /* Enable the INTP0 interrupt */

    do
    {
        NOP();
    } while (! r_intp0_is_flag_on());

    R_Config_INTC_INTP0_Stop();            /* Disable the INTP0 interrupt */
}
/**********************************************************************************************************************
 * Function Name: r_halt
 ******************************************************************************************************************//**
 * @brief Wait in HALT-mode
 * @param none
 * @return none
 */
static void r_halt(void)
{
    r_intp0_clear_flag();      /* Clear the INTP0 interrupt flag. */
    R_Config_INTC_INTP0_Start();           /* Enable the INTP0 interrupt */

    do
    {
        HALT();
    } while (! r_intp0_is_flag_on());

    R_Config_INTC_INTP0_Stop();            /* Disable the INTP0 interrupt */
}
/**********************************************************************************************************************
 * Function Name: r_stop
 ******************************************************************************************************************//**
 * @brief Wait in STOP-mode
 * @param none
 * @return none
 */
static void r_stop(void)
{
    r_intp0_clear_flag();      /* Clear the INTP0 interrupt flag. */
    R_Config_INTC_INTP0_Start();           /* Enable the INTP0 interrupt */

    do
    {
        STOP();
    } while (! r_intp0_is_flag_on());

    R_Config_INTC_INTP0_Stop();            /* Disable the INTP0 interrupt */
}
/**********************************************************************************************************************
 * Function Name: r_snooze
 ******************************************************************************************************************//**
 * @brief Wait in SNOOZE-mode
 * @param none
 * @return none
 */
static void r_snooze(void)
{
    /* Start an AD converter in Snooze-mode */
    R_Config_ADC_Set_OperationOn();
    R_Config_ADC_Set_SnoozeOn();
    R_Config_ADC_Start();

    /* Start an RTC for a hardware trigger of ADC */
    {
        RTCIF = 0U;
        RTCMK = 1U;
        RTCE = 1U;
    }

    /* In this case, keep INTP0 disabled. 
       STOP will be cancelled by INTAD. 
       INTAD occurs when VDD is put to ANI2. */
    STOP();

    R_Config_RTC_Stop();

    /* Stop the AD Converter. */
    R_Config_ADC_Stop();
    R_Config_ADC_Set_SnoozeOff();
    R_Config_ADC_Set_OperationOff();
}
/**********************************************************************************************************************
 * Function Name: r_start_high_oco
 ******************************************************************************************************************//**
 * @brief Start a high-speed-on-chip-oscillator-clock. This function contains wait times.
 * @param none
 * @return none
 */
static void r_start_high_oco(void)
{
    HIOSTOP = 0;
    r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer(R_WAIT_MSEC_HIGH_OCO);
}
/**********************************************************************************************************************
 * Function Name: r_start_mid_oco
 ******************************************************************************************************************//**
 * @brief Start a mid-speed-on-chip-oscillator-clock. This function contains wait times.
 * @param none
 * @return none
 */
static void r_start_mid_oco(void)
{
    MIOEN = 1;
    r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer(R_WAIT_MSEC_MID_OCO);
}
/**********************************************************************************************************************
 * Function Name: r_start_low_oco
 ******************************************************************************************************************//**
 * @brief Start a low-speed-on-chip-oscillator-clock. This function contains wait times.
 * @param none
 * @return none
 */
static void r_start_low_oco(void)
{
    /* CLS shall be 0, when SELLOSC is changed. */
    while (0 != CLS)
    {
        NOP();
    }
    SELLOSC = 1;
    r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer(R_WAIT_MSEC_LOW_OCO);
}
/**********************************************************************************************************************
 * Function Name: r_start_x1
 ******************************************************************************************************************//**
 * @brief Start a high-speed-system-clock. This function contains wait times.
 * @param none
 * @return none
 */
static void r_start_x1(void)
{
    MSTOP = 0;
    r_wait_OSTC();
}
/**********************************************************************************************************************
 * Function Name: r_start_xt1
 ******************************************************************************************************************//**
 * @brief Start a sub-system-clock. This function contains wait times.
 * @param none
 * @return none
 */
static void r_start_xt1(void)
{
    XTSTOP = 0;
    r_ITL000_ITL001_ITL012_ITL013_wait_interval_timer(R_WAIT_MSEC_XT1);
}
/**********************************************************************************************************************
 * Function Name: r_stop_high_oco
 ******************************************************************************************************************//**
 * @brief Stop a high-speed-on-chip-oscillator-clock.
 * @param none
 * @return none
 */
static void r_stop_high_oco(void)
{
    /* Wait for the valid status */
    while ((1 != MCS1) && (1 != MCS) && (1 != CLS))
    {
        NOP();
    }
    HIOSTOP = 1;
}
/**********************************************************************************************************************
 * Function Name: r_stop_mid_oco
 ******************************************************************************************************************//**
 * @brief Stop a mid-speed-on-chip-oscillator-clock.
 * @param none
 * @return none
 */
static void r_stop_mid_oco(void)
{
    /* Wait for the valid status */
    while ((0 != MCS1) && (1 != MCS) && (1 != CLS))
    {
        NOP();
    }
    MIOEN = 0;
}
/**********************************************************************************************************************
 * Function Name: r_stop_low_oco
 ******************************************************************************************************************//**
 * @brief Stop a low-speed-on-chip-oscillator-clock.
 * @param none
 * @return none
 */
static void r_stop_low_oco(void)
{
    /* Wait for the valid status */
    while (0 != CLS)
    {
        NOP();
    }
    SELLOSC = 0;
}
/**********************************************************************************************************************
 * Function Name: r_stop_x1
 ******************************************************************************************************************//**
 * @brief Stop a high-speed-system-clock.
 * @param none
 * @return none
 */
static void r_stop_x1(void)
{
    /* Wait for the valid status */
    while ((0 != MCS) && (1 != CLS))
    {
        NOP();
    }
    MSTOP = 1;
}
/**********************************************************************************************************************
 * Function Name: r_stop_xt1
 ******************************************************************************************************************//**
 * @brief Stop a sub-system-clock.
 * @param none
 * @return none
 */
static void r_stop_xt1(void)
{
    /* Wait for the valid status */
    while (0 != CLS)
    {
        NOP();
    }
    XTSTOP = 1;
}
/**********************************************************************************************************************
 * Function Name: r_set_fclk
 ******************************************************************************************************************//**
 * @brief Set CKC register depend on a clock to use. This function waits until the setting is valid.
 * @param [in] mode   A mode of a clock to use.
 * @return none
 */
static void r_set_fclk(r_fclk_mode_t mode)
{
   /* Set CKC register depend on the clock mode */
   switch (mode)
   {
       case R_fCLK_fMAIN_fOCO_HIGH:
          CSS = 0;      /* Use the main clock. */
          /* Wait until the status is valid */
          while (0 != CLS)
          {
              NOP();
          }
          MCM0 = 0;     /* Use the OCO clock as the main one. */
          MCM1 = 0;     /* Use the high-OCO. */
          /* Wait until the status is valid */
          while (0 != MCS || 0 != MCS1)
          {
              NOP();
          }
          break;
       case R_fCLK_fMAIN_fOCO_MID:
          CSS = 0;      /* Use the main clock. */
          /* Wait until the status is valid */
          while (0 != CLS)
          {
              NOP();
          }
          MCM0 = 0;     /* Use the OCO clock as the main one. */
          MCM1 = 1;     /* Use the mid-OCO. */
          /* Wait until the status is valid */
          while (0 != MCS || 1 != MCS1)
          {
              NOP();
          }
          break;
       case R_fCLK_fMAIN_fOCO_LOW:
          CSS = 1;      /* Use the sub clock */
          /* Wait until the status is valid */
          while (1 != CLS)
          {
              NOP();
          }
          break;
       case R_fCLK_fMAIN_fMX:
          CSS = 0;      /* Use the main clock */
          /* Wait until the status is valid */
          while (0 != CLS)
          {
              NOP();
          }
          MCM0 = 1;     /* Use the high-speed-system-clock as the main one. */
          /* Wait until the status is valid */
          while (1 != MCS)
          {
              NOP();
          }
          break;
       case R_fCLK_fSUB:
          CSS = 1;      /* Use the sub clock */
          /* Wait until the status is valid */
          while (1 != CLS)
          {
              NOP();
          }
          break;
       default:
          /* It shall not reach here. */
          break;
    }
}
/**********************************************************************************************************************
 * Function Name: r_Set_HightSpeedAwakening
 ******************************************************************************************************************//**
 * @brief Set WKUPMD register.
 * @param [in] mode   An awaken mode(high-speed or normal).
 * @return none
 */
static void r_set_high_speed_awakening(r_awaken_mode_t mode)
{
    switch (mode)
    {
        case R_NORMAL_AWAKEN:
           FWKUP = 0;
           break;
        case R_HIGHSPEED_AWAKEN:
           FWKUP = 1;
           break;
        default:
           /* It shall not reach here */
           break;
    }
}
/**********************************************************************************************************************
 * Function Name: r_wait_OSTC
 ******************************************************************************************************************//**
 * @brief Wait until OSMC register reaches the specific value.
 * @param none
 * @return none
 */
static void r_wait_OSTC(void)
{
    while (R_WAIT_OSTC_COUNT > OSTC)
    {
        NOP();
    }
}
/* End user code. Do not edit comment generated here */

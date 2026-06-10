
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/
/* Comparison value of oscillation stabilization time counter status register(OSTC)
 * against oscillation stabilization time select register(OSTS) */
#if BSP_CFG_X1_WAIT_TIME_SEL == 0x00
    /* 2^8/fx or higher */
    #define STAB_WAIT (0x80)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x01
    /* 2^9/fx or higher */
    #define STAB_WAIT (0xC0)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x02
    /* 2^10/fx or higher */
    #define STAB_WAIT (0xE0)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x03
    /* 2^11/fx or higher */
    #define STAB_WAIT (0xF0)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x04
    /* 2^13/fx or higher */
    #define STAB_WAIT (0xF8)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x05
    /* 2^15/fx or higher */
    #define STAB_WAIT (0xFC)
#elif BSP_CFG_X1_WAIT_TIME_SEL == 0x06
    /* 2^17/fx or higher */
    #define STAB_WAIT (0xFE)
#else
    /* 2^18/fx or higher */
    #define STAB_WAIT (0xFF)
#endif

/* Macro definition for option byte reference
 * - Setting of flash operation mode
 * - Frequency of the high-speed on-chip oscillator clock
 */
#define OPTBYTE_C2         (*(volatile __far unsigned char  *)0x000C2)

/* Macro definition for option byte reference
 * - Use of interval interrupt of watchdog timer
 * - Watchdog timer window open period
 * - Operation control of watchdog timer counter
 * - Watchdog timer overflow time
 * - Operation control of watchdog timer counter(HALT/STOP mode)
 */
#define OPTBYTE_C0         (*(volatile __far unsigned char  *)0x000C0)
/* Operation control of watchdog timer counter */
#define WDTON (OPTBYTE_C0 & 0x10 >> 4)

/*************************************************
 * Private global variables and functions
 *************************************************/
/* Frequency of the high-speed on-chip oscillator */
const uint32_t fIH_hz[] = {
    24000000,
    12000000,
    6000000,
    3000000,
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    0,                  /* Setting prohibited */
    32000000,
    16000000,
    8000000,
    4000000,
    2000000,
    1000000,
    0,                  /* Setting prohibited */
    0                   /* Setting prohibited */
};

/* Frequency of Middle-speed on-chip oscillator */
const uint32_t fIM_hz[] = {
    4000000,
    2000000,
    1000000,
    0
};

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: start_clock
 * Description  : Start the specified clock
 * Arguments    : Clock to start
 * Return value : BSP_OK if the specified clock is started.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
bsp_err_t start_clock(clock_mode_t mode)
{
    bsp_err_t           status = BSP_OK;
#if BSP_CFG_HISYSCLK_SOURCE == 1
    uint8_t             tmp_stab_wait;
#endif
    volatile uint32_t   w_count;

    switch (mode)
    {
    case SYSCLK:
        if (1U == MSTOP)
        {
            MSTOP = 0U;

#if BSP_CFG_HISYSCLK_SOURCE == 1
            /* WAIT_LOOP */
            do{
                tmp_stab_wait = OSTC;
                tmp_stab_wait &= STAB_WAIT;
            }while(tmp_stab_wait != STAB_WAIT);
#endif
        }
        break;

    case SXCLK:
        if (1U == XTSTOP)
        {
            XTSTOP = 0U;

#if BSP_CFG_SUBCLK_SOURCE == 1
            /* WAIT_LOOP */
            for (w_count = 0U; w_count <= BSP_SUBWAITTIME; w_count++)
            {
                BSP_NOP();
            }
#endif
        }
        break;

    case HIOCLK:
        if (1U == HIOSTOP)
        {
            HIOSTOP = 0U;

            /* WAIT_LOOP */
            for (w_count = 0U; w_count <= BSP_FIHWAITTIME; w_count++)
            {
                BSP_NOP();
            }
        }
        break;

    case MIOCLK:
        if (0U == MIOEN)
        {
            MIOEN = 1U;

            /* WAIT_LOOP */
            for (w_count = 0U; w_count <= BSP_FIMWAITTIME; w_count++)
            {
                BSP_NOP();
            }
        }
        break;

    default:
        status = BSP_ARG_ERROR;
        break;
    }
    return status;
}

/*************************************************
 * Function name: stop_clock
 * Description  : Stop the specified clock
 * Arguments    : Clock to stop
 * Return value : BSP_OK if the specified clock is stopped.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
**************************************************/
bsp_err_t stop_clock(clock_mode_t mode)
{
    bsp_err_t    status = BSP_OK;

    switch (mode)
    {
    case SYSCLK:
        MSTOP = 1U;
        break;

    case SXCLK:
        XTSTOP = 1U;
        break;

    case HIOCLK:
        HIOSTOP = 1U;
        break;

    case MIOCLK:
        MIOEN = 0U;
        break;

    default:
        status = BSP_ARG_ERROR;
        break;
    }
    return status;
}

/*************************************************
 * Function name: set_fclk_clock_source
 * Description  : Switch CPU/peripheral hardware clock(fCLK) clock source.
 * Arguments    : Clock to switch.
 * Return value : BSP_OK when switching to the specified clock.
 *                BSP_ERROR1 When HIOCLK is specified, but high-speed on-chip oscillator is stopped.
 *                BSP_ERROR2 When SYSCLK is specified, but high-speed system clock is stopped.
 *                BSP_ERROR3 When SXCLK is specified, but Subsystem clock is stopped.
 *                BSP_ERROR4 When MIOCLK is specified, but middle-speed on-chip oscillator is stopped.
 *                BSP_ARG_ERROR if the specified clock is incorrect.
 * Attention    : Start the clock to switch to before calling this function.
**************************************************/
bsp_err_t set_fclk_clock_source(clock_mode_t mode)
{
    bsp_err_t            status = BSP_OK;
    clock_mode_t         old_mode;
    volatile uint32_t    w_count;

    /* Get current clock source */
    if (1U == CLS)
    {
        if (1U == SELLOSC)
        {
            old_mode = LOCLK;
        }
        else
        {
            old_mode = SXCLK;
        }
    }
    else
    {
        if (1U == MCS)
        {
            old_mode = SYSCLK;
        }
        else
        {
            if (1U == MCS1)
            {
                old_mode = MIOCLK;
            }
            else
            {
                old_mode = HIOCLK;
            }
        }
    }

    /* Only switch if the current clock source and the
     * specified clock source are different.
     */
    if (mode != old_mode)
    {
        switch (mode)
        {
        case HIOCLK:
            if (1U == HIOSTOP)
            {
                /* Error if the high-speed on-chip oscillator is stopped. */
                status = BSP_ERROR1;
            }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
            else if ((CLS == 1) && ((MCS != 0) || (MCS1 != 0)))
            {
                // Error if the high-speed on-chip oscillator is not selected.
                status = BSP_ERROR2;
            }
            else if ((old_mode == SYSCLK) && (MCS1 != 0))
            {
                // Error if the high-speed on-chip oscillator is not selected.
                status = BSP_ERROR2;
            }
#endif
            else
            {
                CSS = 0U;
                MCM0 = 0U;
                MCM1 = 0U;
            }
            break;

        case SYSCLK:
            if (1U == MSTOP)
            {
                /* Error if the high-speed system clock is stopped. */
                status = BSP_ERROR1;
            }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
            else if ((CLS == 1) && (MCS != 1))
            {
                // Error if the high-speed system clock is not selected.
                status = BSP_ERROR2;
            }
#endif
            else
            {
                CSS = 0U;
                MCM0 = 1U;
            }
            break;

        case SXCLK:
            if (1U == XTSTOP)
            {
                // Error if the subsystem clock is stopped.
                status = BSP_ERROR1;
            }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
            else if (old_mode == LOCLK)
            {
                status = BSP_ERROR3;
            }
#endif
            else
            {
                SELLOSC = 0U;
                CSS = 1U;
            }
            break;

        case MIOCLK:
            if (0U == MIOEN)
            {
                // Error if the middle-speed on-chip oscillator is stopped.
                status = BSP_ERROR1;
            }
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
            else if ((CLS == 1) && ((MCS != 0) || (MCS1 != 1)))
            {
                // Error if the middle-speed on-chip oscillator is not selected.
                status = BSP_ERROR2;
            }
            else if ((old_mode == SYSCLK) && (MCS1 != 1))
            {
                // Error if the middle-speed on-chip oscillator is not selected.
                status = BSP_ERROR2;
            }
#endif
            else
            {
                CSS = 0U;
                MCM0 = 0U;
                MCM1 = 1U;
            }
            break;

        case LOCLK:
#if BSP_CFG_PARAM_CHECKING_ENABLE == 1
            if (old_mode == SXCLK)
            {
                status = BSP_ERROR3;
            }
            else if (XTSTOP == 0)
            {
                status = BSP_ERROR3;
            }
#endif
            SELLOSC = 1U;
            /* WAIT_LOOP */
            for (w_count = 0U; w_count <= BSP_FILWAITTIME; w_count++)
            {
                BSP_NOP();
            }
            CSS = 1U;
            break;

        default:
            status = BSP_ARG_ERROR;
            break;
        }
    }

    return status;
}

/*************************************************
 * Function name: get_fclk_freq_hz
 * Description  : Returns CPU/peripheral hardware clock(fCLK) frequency.
 * Arguments    : none
 * Return value : CPU/peripheral hardware clock(fCLK) frequency specified by the r_bsp.
 * Attention    : Error if 0Hz is returned.
 *                When fCLK is a high-speed on-chip oscillator, 0Hz is returned
 *                when the value of the register to which it refers is out of the allowable range.
**************************************************/
uint32_t get_fclk_freq_hz(void)
{
    uint32_t    sys_clock_src_freq;

    /* fCLK clock source is fSUB */
    /* fCLK : CPU/peripheral hardware clock */
    /* fSUB : Subsystem clock */
    if (1U == CLS)
    {
        /* fSUB clock source is fIL */
        /* fSUB : Subsystem clock */
        /* fIL  : Low-speed on-chip oscillator clock */
        if (1U == SELLOSC)
        {
            sys_clock_src_freq = BSP_LOCO_HZ;
        }
        /* fSUB clock source is fSX */
        /* fSUB : Subsystem clock */
        /* fSX  : Subsystem clock oscillator clock */
        else
        {
            /* fSX clock source is fXT */
            /* fSX : Subsystem clock oscillator clock */
            /* fXT : XT1 clock oscillation */
            sys_clock_src_freq = BSP_SUB_CLOCK_HZ;
        }
    }
    /* fCLK clock source is fMAIN */
    /* fCLK  : CPU/peripheral hardware clock */
    /* fMAIN : Main system clock */
    else
    {
        /* fMAIN clock source is fMX */
        /* fMAIN : Main system clock */
        /* fMX   : High-speed system clock */
        if (1U == MCS)
        {
            /* fMX clock source is fX */
            /* fMX : High-speed system clock */
            /* fX  : X1 clock oscillation */
            uint8_t i;
            /* WAIT_LOOP */
            sys_clock_src_freq = BSP_CFG_FMX_HZ;
            for (i = MOSCDIV; i > 0; i--)
            {
                sys_clock_src_freq /= 2;
            }
        }
        /* fMAIN clock source is fOCO */
        /* fMAIN : Main system clock */
        /* fOCO  : Main on-chip oscillator clock */
        else
        {
            /* fOCO clock source is fIM */
            /* fOCO : Main on-chip oscillator clock */
            /* fIM  : Middle-speed on-chip oscillator clock */
            if (1U == MCS1)
            {
                sys_clock_src_freq = fIM_hz[MOCODIV & 0x03];
            }
            /* fOCO clock source is fIH */
            /* fOCO : Main on-chip oscillator clock */
            /* fIH  : High-speed on-chip oscillator clock */
            else
            {
                unsigned char temp1, temp2;
                temp1 = OPTBYTE_C2;
                temp2 = HOCODIV;
                sys_clock_src_freq = fIH_hz[(temp1 & 0x08) | (temp2 & 0x07)];
            }
        }
    }

    return sys_clock_src_freq;
}


#if BSP_CFG_STARTUP_DISABLE == 0
/*************************************************
 * Function name: mcu_clock_setup
 * Description  : Clock initialization.
 * Arguments    : none
 * Return value : none
**************************************************/
void mcu_clock_setup(void)
{
    uint8_t cmc_tmp;

#if BSP_CFG_MOCO_SOURCE == 1 || BSP_CFG_SUBCLK_SOURCE == 1 || BSP_CFG_SUBSYSCLK_SOURCE == 1
    volatile uint32_t w_count;
#endif
#if BSP_CFG_HISYSCLK_SOURCE == 1
    uint8_t tmp_stab_wait;
#endif

    cmc_tmp = 0x00;

    /* High-speed system clock(fMX) setting */
#if BSP_CFG_HISYSCLK_SOURCE == 0
    /* Not used.
     * When using high-speed on-chip oscillator,
     * when using middle-speed on-chip oscillator or
     * when not using main system clock
     */
#elif BSP_CFG_HISYSCLK_SOURCE == 1
    /* fX(Crystal/ceramic resonator connection */
    /* High-speed system clock division register(MOSCDIV) setting */
    MOSCDIV = BSP_CFG_MOSC_DIVIDE;
    /* Control of X1 clock oscillation frequency(AMPH) setting */
    #if BSP_CFG_FMX_HZ >= 1000000 && BSP_CFG_FMX_HZ <= 10000000
        /* 1MHz <= fX <= 10MHz */
        cmc_tmp |= 0x40;
    #else
        /* 10MHz < fX <= 32MHz */
        cmc_tmp |= 0x41;
    #endif
#else
    /* fEX(External clock input) */
    /* High-speed system clock division register(MOSCDIV) setting */
    MOSCDIV = BSP_CFG_MOSC_DIVIDE;
    /* Control of X1 clock oscillation frequency(AMPH) setting */
    #if BSP_CFG_FMX_HZ >= 1000000 && BSP_CFG_FMX_HZ <= 10000000
        /* 1MHz <= fX <= 10MHz */
        cmc_tmp |= 0xC0;
    #else
        /* 10MHz < fX <= 32MHz */
        cmc_tmp |= 0xC1;
    #endif
#endif

    /* High-speed on-chip oscillator(fIH) setting */
    /* High-speed on-chip oscillator frequency select register(HOCODIV) setting */
    HOCODIV = BSP_CFG_HOCO_DIVIDE;

    /* Subsystem clock oscillator clock(fSX) setting */
#if BSP_CFG_SUBCLK_SOURCE == 0
    /* Not used.
     * When using the low-speed on-chip oscillator or
     * when not using subsystem clock(fSUB)
     */
#elif BSP_CFG_SUBCLK_SOURCE == 1
    #if BSP_CFG_MCU_PART_PIN_NUM <= 2
        /* 30 - 36 pin device */
        /* XTSEL setting */
        cmc_tmp |= 0x08;
    #endif
    /* fXT(Crystal resonator connection) */
    #if BSP_CFG_XT1_OSCMODE == 0
        /* Low power consumption oscillation */
        /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
        cmc_tmp |= 0x10;
    #elif BSP_CFG_XT1_OSCMODE == 1
        /* Normal oscillation */
        /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
        cmc_tmp |= 0x12;
    #else
        /* Ultra-low power consumption oscillation */
        /* EXCLKS/OSCSELS/AMPHS1/AMPHS0 setting */
        cmc_tmp |= 0x14;
    #endif
#else
    #if BSP_CFG_MCU_PART_PIN_NUM <= 2
        /* 30 - 36 pin device */
        /* XTSEL setting */
        cmc_tmp |= 0x08;
    #endif
    /* fEXS(External subsystem clock) */
    /* EXCLKS/OSCSELS setting */
    cmc_tmp |= 0x30;
#endif
    /* Clock operation mode control register(CMC) setting */
    CMC = cmc_tmp;

    /* Middle-speed on-chip oscillator clock(fIM) setting */
#if BSP_CFG_MOCO_SOURCE == 1
    MOCODIV = BSP_CFG_MOCO_DIVIDE;
#endif

    /* When to use X1 clock oscillator(fX) */
#if BSP_CFG_HISYSCLK_SOURCE == 1
    /* Oscillation stabilization time select register(OSTS) setting */
    OSTS = BSP_CFG_X1_WAIT_TIME_SEL;
#endif

    /* High-speed system clock oscillation */
#if BSP_CFG_HISYSCLK_SOURCE != 0
    /* Start oscillation */
    MSTOP = 0U;

    #if BSP_CFG_HISYSCLK_SOURCE != 2
        /* Wait for oscillation stabilization unless external clock input */
        /* WAIT_LOOP */
        do{
            tmp_stab_wait = OSTC;
            tmp_stab_wait &= STAB_WAIT;
        }while(tmp_stab_wait != STAB_WAIT);
    #endif
#else
    /* X1 oscillation stopped if high-speed system clock is not used */
    MSTOP = 1U;
#endif

    /* When to use middle-speed on-chip oscillator clock(fIM) */
#if BSP_CFG_MOCO_SOURCE == 1
    MIOEN = 1U;

    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_FIMWAITTIME; w_count++)
    {
        BSP_NOP();
    }
#else
    /* Oscillation stopped if middle-speed on-chip oscillator clock(fIM) is not used */
    MIOEN = 0U;
#endif

    /* Main on-chip oscillator clock(fOCO) setting */
#if BSP_CFG_OCOCLK_SOURCE == 0
    /* High-speed on-chip oscillator clock(fIH) */
    MCM1 = 0U;
#else
    /* Middle-speed on-chip oscillator clock(fIM) */
    MCM1 = 1U;
#endif

    /* Main system clock(fMAIN) setting */
#if BSP_CFG_MAINCLK_SOURCE == 0
    /* Main on-chip oscillator clock(fOCO) */
    MCM0 = 0U;
#else
    /* High-speed system clock(fMX) */
    MCM0 = 1U;
#endif

    /* Subsystem clock oscillation */

    /* Subsystem clock supply mode control register(OSMC) setting */
#if BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 0 && BSP_CFG_RTC_OUT_CLK_SOURCE == 0
    OSMC |= 0x00U;
#elif BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 1 && BSP_CFG_RTC_OUT_CLK_SOURCE == 0
    OSMC |= 0x80U;
#elif BSP_CFG_ALLOW_FSUB_IN_STOPHALT == 0 && BSP_CFG_RTC_OUT_CLK_SOURCE == 1
    OSMC |= 0x10U;
#else
    OSMC |= 0x90U;
#endif

    /* When to use subsystem clock oscillator clock(fSX) */
    /* Subsystem clock oscillator clock oscillation */
#if BSP_CFG_SUBCLK_SOURCE != 0
    /* Start oscillation */
    XTSTOP = 0U;

    #if BSP_CFG_SUBCLK_SOURCE != 2
    /* Wait for oscillation stabilization unless external clock input */
    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_SUBWAITTIME; w_count++)
    {
        BSP_NOP();
    }
    #endif

#else
    /* XT1 oscillator stopped if subsystem clock oscillator clock is not used */
    XTSTOP = 1U;
#endif

#if BSP_CFG_SUBSYSCLK_SOURCE == 1
    SELLOSC = 1U;
    /* WAIT_LOOP */
    for (w_count = 0U; w_count <= BSP_FILWAITTIME; w_count++)
    {
        BSP_NOP();
    }
#endif

    /* fCLK selection */
#if BSP_CFG_FCLK_SOURCE == 0
    /* When using a high-speed system clock, high-speed on-chip oscillator,
     * or middle-speed on-chip oscillator
     */
    CSS = 0U;
#else
    /* When using subsystem clock or low-speed on-chip oscillator */
    CSS = 1U;
#endif

    /* Starts high-speed on-chip oscillator */
    /* Only the high-speed on-chip oscillator is activated after reset,
     * so stop this clock last.
     */
#if BSP_CFG_FIH_START_ON_STARTUP == 1
    /* High-speed on-chip oscillator startup setting at
     * STOP mode release and SNOOZE mode transition.
     */
    #if (BSP_CFG_OCOCLK_SOURCE == 0) && (BSP_CFG_MAINCLK_SOURCE == 0) && (BSP_CFG_FCLK_SOURCE == 0)
        FWKUP = BSP_CFG_WAKEUP_MODE;
    #endif
    HIOSTOP = 0U;
#else
    HIOSTOP = 1U;
#endif
}
#endif    // BSP_CFG_STARTUP_DISABLE == 0

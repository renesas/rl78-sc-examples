
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Function definition
 *************************************************/

/**********************************************************************************************************************
 * Function Name: R_BSP_StartClock
 ******************************************************************************************************************//**
 * @brief Start the specified clock and return.
 * @param[in] mode Clock to start.
 * @retval BSP_OK BSP_OK if the specified clock is started.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function starts the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
bsp_err_t R_BSP_StartClock(clock_mode_t mode)
{
    return start_clock(mode);
}

/**********************************************************************************************************************
 * Function Name: R_BSP_StopClock
 ******************************************************************************************************************//**
 * @brief Stop the specified clock and return.
 * @param[in] mode Clock to stop.
 * @retval BSP_OK BSP_OK if the specified clock is stopped.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function stops the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
bsp_err_t R_BSP_StopClock(clock_mode_t mode)
{
    return stop_clock(mode);
}

/**********************************************************************************************************************
 * Function Name: R_BSP_SetClockSource
 ******************************************************************************************************************//**
 * @brief Switch CPU/peripheral hardware clock(fCLK) clock source and return.
 * @param[in] mode Clock to switch.
 * @retval BSP_OK BSP_OK when switching to the specified clock.
 * @retval BSP_ERROR1 When HIOCLK is specified, but high-speed on-chip oscillator is stopped.
 * @retval BSP_ERROR2 When SYSCLK is specified, but high-speed system clock is stopped.
 * @retval BSP_ERROR3 When SXCLK is specified, but Subsystem clock is stopped.
 * @retval BSP_ERROR4 When MIOCLK is specified, but middle-speed on-chip oscillator is stopped.
 * @retval BSP_ARG_ERROR BSP_ARG_ERROR if the specified clock is incorrect.
 * @details This function switches the specified clock.
 * Specify one of the following for mode.
 * HIOCLK : High-speed on-chip oscillator
 * SYSCLK : High-speed system clock
 * SXCLK  : Subsystem clock
 * MIOCLK : Middle-speed on-chip oscillator
 * LOCLK  : Low-speed on-chip oscillator
 */
bsp_err_t R_BSP_SetClockSource(clock_mode_t mode)
{
    return set_fclk_clock_source(mode);
}

/**********************************************************************************************************************
 * Function Name: R_BSP_GetfclkFreqHz
 ******************************************************************************************************************//**
 * @brief Returns CPU/peripheral hardware clock(fCLK) frequency.
 * @return CPU/peripheral hardware clock(fCLK) frequency specified by the r_bsp.
 * @details This function returns the CPU/peripheral hardware clock(fCLK) frequency.
 * For example, when the CPU/peripheral hardware clock(fCLK) is set to 20 MHz in r_bsp_config.h
 * and the r_bsp has completed to specify the clock setting, then even if the user changed the
 * CPU/peripheral hardware clock(fCLK) frequency to 10 MHz, the return value is '10000000'.
 */
uint32_t R_BSP_GetFclkFreqHz(void)
{
    return get_fclk_freq_hz();  // Get the MCU specific ICLK frequency
} /* End of function R_BSP_GetFclkFreqHz() */


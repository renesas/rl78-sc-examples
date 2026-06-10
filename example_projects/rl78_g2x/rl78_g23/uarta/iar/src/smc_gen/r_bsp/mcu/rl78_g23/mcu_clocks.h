
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/

/*************************************************
 * Macro definitions
 *************************************************/
/* Multiple inclusion prevention macro */
#ifndef MCU_CLOCKS_H
#define MCU_CLOCKS_H

/*************************************************
 * Function declaration
 *************************************************/
bsp_err_t start_clock(clock_mode_t mode);
bsp_err_t stop_clock(clock_mode_t mode);

bsp_err_t set_fclk_clock_source(clock_mode_t mode);
uint32_t get_fclk_freq_hz(void);
void mcu_clock_setup(void);

#endif    // #ifndef MCU_CLOCKS_H



/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
/* I/O Register and board definitions */
#include "platform.h"
#if BSP_CFG_CONFIGURATOR_SELECT == 1
#include "r_cg_macrodriver.h"
#endif

/*************************************************
 * Macro definitions
 *************************************************/

/*************************************************
 * Private global variables and functions
 *************************************************/
/* MCU I/O port configuration function declaration */
static void output_ports_configure(void);

/* Interrupt configuration function declaration */
static void interrupts_configure(void);

/* MCU peripheral module configuration function declaration */
static void peripheral_modules_enable(void);

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: hdwinit
 * Description  : Peripheral function initialization
 * Arguments    : none
 * Return value : none
**************************************************/
void hdwinit(void)
{
#if BSP_CFG_DATA_FLASH_ACCESS_ENABLE == 1
    volatile uint32_t w_count;
#endif

    output_ports_configure();
    interrupts_configure();
    peripheral_modules_enable();

    /* Safety function setting */
#if BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE == 0
    IAWCTL = 0x00;
#else
    IAWCTL = (BSP_CFG_INVALID_MEMORY_ACCESS_DETECTION_ENABLE << 7) |
             (BSP_CFG_RAM_GUARD_FUNC << 4) |
             (BSP_CFG_PORT_FUNCTION_GUARD << 2) |
             (BSP_CFG_INT_FUNCTION_GUARD << 1) |
             (BSP_CFG_CHIP_STATE_CTRL_GUARD);
#endif

    /* Data flash access control */
#if BSP_CFG_DATA_FLASH_ACCESS_ENABLE == 1
    DFLEN = 1U;
    /* WAIT_LOOP */
    for (w_count = 0U; w_count < 2U; w_count++)
    {
        BSP_NOP();
    }
#endif
}

/*************************************************
 * Function name: output_ports_configure
 * Description  : Output port setting
 * Arguments    : none
 * Return value : none
**************************************************/
static void output_ports_configure(void)
{
    /* Add code here to setup additional output ports */
    BSP_NOP();
} /* End of function output_ports_configure() */

/*************************************************
 * Function name: interrupts_configure
 * Description  : Interrupt setting
 * Arguments    : none
 * Return value : none
**************************************************/
static void interrupts_configure(void)
{
    /* Add code here to setup additional interrupts */
    BSP_NOP();
} /* End of function interrupts_configure() */

/*************************************************
 * Function name: peripheral_modules_enable
 * Description  : Peripheral module setting
 * Arguments    : none
 * Return value : none
**************************************************/
static void peripheral_modules_enable(void)
{
    /* Add code here to enable peripherals used by the application */
#if BSP_CFG_CONFIGURATOR_SELECT == 1
    /* Smart Configurator initialization function */
    R_Systeminit();
#endif
} /* End of function peripheral_modules_enable() */



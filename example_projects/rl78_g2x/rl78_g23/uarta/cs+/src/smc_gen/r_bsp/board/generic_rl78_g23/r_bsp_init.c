
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include "platform.h"

/*************************************************
 * Macro definitions
 *************************************************/

/*************************************************
 * External function Prototypes
 *************************************************/

#if BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED != 0
/* If user is requesting warm start callback functions then these are the prototypes. */
void BSP_CFG_USER_WARM_START_PRE_C_FUNCTION(void);
#endif

#if BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED != 0
/* If user is requesting warm start callback functions then these are the prototypes. */
void BSP_CFG_USER_WARM_START_POST_C_FUNCTION(void);
#endif

/*************************************************
 * Private global variables and functions
 *************************************************/

/*************************************************
 * Function definition
 *************************************************/
/*************************************************
 * Function name: bsp_init_system
 * Description  : BSP initial setting(clock)
 * Arguments    : none
 * Return value : none
**************************************************/
void bsp_init_system(void)
{
    /* Pin setting */
    #if BSP_CFG_MCU_PART_PIN_NUM == 0
        /* 30-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 1
        /* 32-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 2
        /* 36-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 3
        /* 40-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 4
        /* 44-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 5
        /* 48-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 6
        /* 52-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 7
        /* 64-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 8
        /* 80-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #elif BSP_CFG_MCU_PART_PIN_NUM == 9
        /* 100-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #else
        /* 128-pin */
        PIOR = BSP_CFG_PIOR0 || (BSP_CFG_PIOR1 << 1) || (BSP_CFG_PIOR2 << 2) ||
              (BSP_CFG_PIOR3 << 3) || (BSP_CFG_PIOR4 << 4) || (BSP_CFG_PIOR5 << 5);
    #endif

    /* Clock initialization */
#if BSP_CFG_STARTUP_DISABLE == 0
    mcu_clock_setup();
#endif

    /* If the warm start Pre C runtime callback is enabled, then call it. */
#if BSP_CFG_USER_WARM_START_CALLBACK_PRE_INITC_ENABLED == 1
    BSP_CFG_USER_WARM_START_PRE_C_FUNCTION();
#endif
}

/*************************************************
 * Function name: bsp_init_hardware
 * Description  : BSP initial setting(Peripheral functions)
 * Arguments    : none
 * Return value : none
**************************************************/
void bsp_init_hardware(void)
{
    /* If the warm start Post C runtime callback is enabled, the call it. */
#if BSP_CFG_USER_WARM_START_CALLBACK_POST_INITC_ENABLED == 1
    BSP_CFG_USER_WARM_START_POST_C_FUNCTION();
#endif

    /* Peripheral function initialization */
    hdwinit();
}

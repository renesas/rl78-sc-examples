
/*************************************************
 * Includes  <System Includes> , "Project Includes"
 *************************************************/
#include    <stdint.h>
#include    <stdbool.h>
#include    <stdio.h>
#include    <stddef.h>

/*************************************************
 * Macro definitions
 *************************************************/
/* Multiple inclusion prevention macro */
#ifndef R_BSP_COMMON_H
#define R_BSP_COMMON_H

/* Version Number of r_bsp. */
#define R_BSP_VERSION_MAJOR           (1)
#define R_BSP_VERSION_MINOR           (00)

/* Interrupt disable/enable(assembler instruction) */
#define BSP_DI()            __DI()                      /* Interrupt disable */
#define BSP_EI()            __EI()                      /* Interrupt enable */

/* NOP(assembler instruction) */
#if defined(__CCRL__)
#define BSP_NOP()           __nop()                     /* NOP instruction */
#elif defined(__ICCRL78__)
#define BSP_NOP     (__no_operation)
#elif defined(__llvm__)
#define BSP_NOP()   NOP()
#endif
/* clock mode */
typedef enum
{
    HIOCLK,     // High-speed on-chip oscillator
    SYSCLK,     // High-speed system clock
    SXCLK,      // Subsystem clock
    MIOCLK,     // Middle-speed on-chip oscillator
    LOCLK       // Low-speed on-chip oscillator
} clock_mode_t;

/* Error identification */
typedef enum
{
    BSP_OK,
    BSP_ARG_ERROR,
    BSP_ERROR1,
    BSP_ERROR2,
    BSP_ERROR3
} bsp_err_t;

/*************************************************
 * Function declaration
 *************************************************/
bsp_err_t R_BSP_StartClock(clock_mode_t mode);
bsp_err_t R_BSP_StopClock(clock_mode_t mode);
uint32_t R_BSP_GetFclkFreqHz(void);
bsp_err_t R_BSP_SetClockSource(clock_mode_t mode);


#endif    // #define R_BSP_COMMON_H

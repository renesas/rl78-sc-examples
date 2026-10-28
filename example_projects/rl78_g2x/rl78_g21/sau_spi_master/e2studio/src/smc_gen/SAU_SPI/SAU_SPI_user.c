/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : SAU_SPI_user.c
* Component Version: 1.9.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for SAU_SPI.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "SAU_SPI.h"
/* Start user code for include. Do not edit comment generated here */
#include "sau_spi_master_ep.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_SAU_SPI_interrupt(vect=INTCSI10)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern uint16_t g_csi10_send_length;              /* csi10 send data length */
extern volatile uint8_t * gp_csi10_tx_address;    /* csi10 send buffer address */
extern volatile uint16_t g_csi10_tx_count;        /* csi10 send data count */
extern volatile uint8_t * gp_csi10_rx_address;    /* csi10 receive buffer address */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_SAU_SPI_Create_UserInit
* Description  : This function adds user code after initializing the CSI10.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_SAU_SPI_Create_UserInit(void)
{
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_SPI_callback_sendend
* Description  : This function is a callback function when CSI10 finishes transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_SPI_callback_sendend(void)
{
    /* Start user code for r_SAU_SPI_callback_sendend. Do not edit comment generated here */
    sau_spi_callback(SPI_EVENT_TRANSFER_COMPLETE);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_SPI_callback_receiveend
* Description  : This function is a callback function when CSI10 finishes reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_SPI_callback_receiveend(void)
{
    /* Start user code for r_SAU_SPI_callback_receiveend. Do not edit comment generated here */
    sau_spi_callback(SPI_EVENT_TRANSFER_COMPLETE);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_SPI_callback_error
* Description  : This function is a callback function when CSI10 reception error occurs.
* Arguments    : err_type -
*                    error type value
* Return Value : None
***********************************************************************************************************************/
static void r_SAU_SPI_callback_error(uint8_t err_type)
{
    /* Start user code for r_SAU_SPI_callback_error. Do not edit comment generated here */
    sau_spi_callback(SPI_EVENT_ERR_OVERRUN);
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_SAU_SPI_interrupt
* Description  : This function is INTCSI10 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_SAU_SPI_interrupt(void)
{
    uint8_t err_type;

    err_type = (uint8_t)(SSR02 & _0001_SAU_OVERRUN_ERROR);
    SIR02L = err_type;

    if (1U == err_type)
    {
        r_SAU_SPI_callback_error(err_type);    /* overrun error occurs */
    }
    else
    {
        if (g_csi10_tx_count > 0U)
        {
            if ((g_csi10_send_length - 1U) != g_csi10_tx_count)
            {
                *gp_csi10_rx_address = SIO10;
                gp_csi10_rx_address++;
            }

            SIO10 = *gp_csi10_tx_address;
            gp_csi10_tx_address++;
            g_csi10_tx_count--;
        }
        else
        {
            if (1U == (SMR02 & _0001_SAU_BUFFER_EMPTY))
            {
                r_SAU_SPI_callback_sendend();    /* complete send */
                *gp_csi10_rx_address = SIO10;
                gp_csi10_rx_address++;

                if (0U == (SSR02 & _0040_SAU_UNDER_EXECUTE))
                {
                    *gp_csi10_rx_address = SIO10;
                    r_SAU_SPI_callback_receiveend();    /* complete receive */
                }
                else
                {
                    SMR02 &= (uint16_t)~_0001_SAU_BUFFER_EMPTY;
                }
            }
            else
            {
                *gp_csi10_rx_address = SIO10;
                r_SAU_SPI_callback_receiveend();    /* complete receive */
            }
        }
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

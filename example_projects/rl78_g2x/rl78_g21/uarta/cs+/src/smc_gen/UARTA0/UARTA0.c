/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : UARTA0.c
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for UARTA0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "UARTA0.h"
/* Start user code for include. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
volatile uint16_t g_uarta0_rx_total_num;
volatile uint8_t * gp_uarta0_rx_address;
volatile uint16_t g_uarta0_rx_num;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_UARTA0_Create
* Description  : This function initializes the UARTA0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Create(void)
{
    UTAEN = 1U;    /* supply UARTA0 clock */
    UARTAEN0 = 0U;
    UTMK0 = 1U;    /* disable INTUT0 interrupt */
    UTIF0 = 0U;    /* clear INTUT0 interrupt flag */
    URMK0 = 1U;    /* disable INTUR0 interrupt */
    URIF0 = 0U;    /* clear INTUR0 interrupt flag */
    /* Set INTUT0 low priority */
    UTPR10 = 1U;
    UTPR00 = 1U;
    /* Set INTUR0 low priority */
    URPR10 = 1U;
    URPR00 = 1U;
    BRGCA0 = _8B_UARTA_OUTPUT_BAUDRATE;
    ASIMA01 = _00_UARTA_PARITY_NONE | _18_UARTA_TRANSFER_LENGTH_8 | _00_UARTA_STOP_BIT_1 | _02_UARTA_DIRECTION_LSB | 
              _00_UARTA_DATA_NORMAL;
    ASIMA00 = _00_UARTA_TRANSFER_END | _01_UARTA_INTUR_OCCUR;
    UTA0CK = _20_UARTA0_FSEL_SELECT_FIHP | _00_UARTA0_SELECT_FSEL;
    /* Set TxDA0 pin */
    P7 |= 0x04U;
    PM7 &= 0xFBU;
    /* Set RxDA0 pin */
    PM7 |= 0x02U;

    R_UARTA0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Start
* Description  : This function starts UARTA0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Start(void)
{
    volatile uint8_t w_count;

    URIF0 = 0U;    /* clear INTUR0 interrupt flag */
    URMK0 = 0U;    /* enable INTUR0 interrupt */
    UARTAEN0 = 1U;
    UTA0CK_bit.no7 = 0U;    /* disables CLKA0 output */
    TXEA0 = 1U;

    /* Wait for the period of at least one cycle of the UARTA operation clock */
    for (w_count = 0U; w_count <= UARTA0_WAIT_1_CLOCK_CYCLE; w_count++ )
    {
        NOP();
    }

    RXEA0 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Stop
* Description  : This function stops UARTA0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Stop(void)
{
    URMK0 = 1U;    /* disable INTUR0 interrupt */
    URIF0 = 0U;    /* clear INTUR0 interrupt flag */
    TXEA0 = 0U;
    RXEA0 = 0U;
    UTA0CK_bit.no7 = 0U;    /* disables CLKA0 output */
    UARTAEN0 = 0U;
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Send
* Description  : This function sends UARTA0 data.
* Arguments    : tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UARTA0_Send(uint8_t * const tx_buf, uint16_t tx_num)
{
    MD_STATUS status = MD_OK;
    uint8_t * tx_address;
    uint16_t tx_count;

    if (tx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Disable UARTA0 interrupt operation */
        UTMK0 = 1U;
        tx_address = tx_buf;
        tx_count = tx_num;

        while (0U < tx_count)
        {
            while (0U != (ASISA0 & _20_UARTA_DATA_EXIST_IN_TXBA))
            {
                ;
            }

            TXBA0 = *tx_address;
            tx_count--;
            tx_address++;
        }

        while (0U != (ASISA0 & _10_UARTA_HAVE_NEXT_TRANSFER))
        {
            ;
        }

        R_UARTA0_PollingEnd_UserCode();
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Receive
* Description  : This function receives UARTA0 data.
* Arguments    : rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
* Return Value : status -
*                    MD_OK or MD_ARGERROR
***********************************************************************************************************************/
MD_STATUS R_UARTA0_Receive(uint8_t * const rx_buf, uint16_t rx_num)
{
    MD_STATUS status = MD_OK;

    if (rx_num < 1U)
    {
        status = MD_ARGERROR;
    }
    else
    {
        /* Set receive setting */
        g_uarta0_rx_total_num = rx_num;
        gp_uarta0_rx_address = rx_buf;
        g_uarta0_rx_num = 0U;
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Loopback_Enable
* Description  : This function enables the UARTA0 loopback function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Loopback_Enable(void)
{
    ULBS4 = 1U;
}

/***********************************************************************************************************************
* Function Name: R_UARTA0_Loopback_Disable
* Description  : This function disables the UARTA0 loopback function.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_UARTA0_Loopback_Disable(void)
{
    ULBS4 = 0U;
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


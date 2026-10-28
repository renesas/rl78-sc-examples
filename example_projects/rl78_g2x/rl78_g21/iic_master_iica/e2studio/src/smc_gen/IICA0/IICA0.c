/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : IICA0.c
* Component Version: 1.12.0
* Device(s)        : R7F103GLJxFB
* Description      : This file implements device driver for IICA0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "IICA0.h"
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
volatile uint16_t g_iica0_time_count;             /* timer count value for 50us */
volatile uint8_t g_iica0_status;                  /* iica0 master operation flag */
/*
    0x00(BUS_FREE)  : I2C bus is free(SUCCESS)
    0x12(TX_MODE)   : transmit operation mode
    0x14(RX_MODE)   : receive operation mode
    0x16(TX_ADDR_REG): transmit address register
    0x18(TX_SADDR)  : transmit slave address
    0x20(OP_END)    : operation end and hold I2C bus
    0x22(TX_END)    : transmit end and hold I2C bus
    0x24(RX_END)    : receive and and hold I2C bus
    0x8F(BUS_ERROR) : bus or IICAn is busy error
    0x80(NO_SLAVE)  : NACK for slave address
    0xC0(NO_ACK)    : NACK for transmit data
*/
volatile uint8_t * gp_iica0_rx_address;           /* iica0 receive buffer address */
uint16_t g_iica0_rx_len;                          /* iica0 receive data length */
volatile uint16_t g_iica0_rx_cnt;                 /* iica0 receive data count */
volatile uint8_t * gp_iica0_tx_address;           /* iica0 send buffer address */
volatile uint16_t g_iica0_tx_cnt;                 /* iica0 send data count */
volatile uint8_t g_iica0_sl_addr;                 /* iica0 slave address (8bit) */
volatile uint8_t g_iica0_adr_reg;                 /* iica0 address register (8bit) */
volatile uint8_t g_iica0_adr_flag;                /* iica0 address register flag */
volatile uint8_t g_iica0_limit_time = 0xFFU;
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IICA0_Create
* Description  : This function initializes the IICA0 module.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Create(void)
{
    IICA0EN = 1U;    /* enables input clock supply */
    IICE0 = 0U;
    IICAMK0 = 1U;    /* disable INTIICA0 interrupt */
    IICAIF0 = 0U;    /* clear INTIICA0 interrupt flag */
    /* Set INTIICA0 low priority */
    IICAPR10 = 1U;
    IICAPR00 = 1U;
    /* Set SCLA0, SDAA0 pin */
    PM6 |= 0x03U;
    P6 &= 0xFCU;
    SMC0 = 0U;
    IICWL0 = _4C_IICA0_IICWL_VALUE;
    IICWH0 = _55_IICA0_IICWH_VALUE;
    PRS0 = 1U;    /* selects fCLK/2 */
    SVA0 = _10_IICA0_MASTERADDRESS;
    STCEN0 = 1U;
    IICRSV0 = 1U;
    SPIE0 = 0U;
    WTIM0 = 1U;
    ACKE0 = 1U;
    IICAMK0 = 0U;
    IICE0 = 1U;
    LREL0 = 1U;
    /* Set SCLA0, SDAA0 pin */
    PM6 &= 0xFCU;

    R_IICA0_Create_UserInit();
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Stop
* Description  : This function stops IICA0 module operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Stop(void)
{
    IICE0 = 0U;    /* disable IICA0 operation */
}

/***********************************************************************************************************************
* Function Name: R_IICA0_StopCondition
* Description  : This function stops the IICA0 condition.
* Arguments    : None
* Return Value : status -
*                    SUCCESS, BUS_FREE or BUS_ERROR
***********************************************************************************************************************/
uint8_t R_IICA0_StopCondition(void)
{
    uint8_t status = SUCCESS;    /* set dummy status "SUCCESS" */
    uint8_t w_count;

    SPT0 = 1U;    /* issue stop condition to stop */

    for (w_count = 0U; w_count <= g_iica0_limit_time; w_count++ )    /* wait for detection */
    {
        if (1U == SPD0)
        {    /* detect stop detection */
            g_iica0_status = BUS_FREE;    /* set bus is free */
            break;
        }
    }

    if (0U == SPD0)
    {
        status = BUS_ERROR;    /* not detect stop detection */
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Master_Send
* Description  : This function starts to send data as master mode.
* Arguments    : sladr8 -
*                    transfer address
*                tx_buf -
*                    transfer buffer pointer
*                tx_num -
*                    buffer size
*                wait -
*                    wait for start condition
* Return Value : status -
*                    BUS_ERROR, SUCCESS
***********************************************************************************************************************/
uint8_t R_IICA0_Master_Send(uint8_t sladr8, uint8_t * const tx_buf, uint16_t tx_num, uint8_t wait)
{
    uint8_t status = BUS_ERROR;    /* set dummy status "error" flag */

    g_iica0_limit_time = wait;    /* set timeout data */
    status = R_IICA0_Bus_Check();    /* check IIC bus status */

    if (SUCCESS == status)
    {
        g_iica0_adr_flag = 0x00U;    /* disable address register */
        g_iica0_tx_cnt = tx_num;    /* set data number to transmit */
        gp_iica0_tx_address = tx_buf;    /* set data pointer */
        g_iica0_status = TX_SADDR;    /* set operation mode flag */
        /* Get IIC bus and start to access IIC bus */
        IICA0 = (sladr8 & 0xFEU);    /* transmit slave address */
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Master_Receive
* Description  : This function starts to receive data as master mode.
* Arguments    : sladr8 -
*                    receive address
*                rx_buf -
*                    receive buffer pointer
*                rx_num -
*                    buffer size
*                wait -
*                    wait for start condition
* Return Value : status -
*                    COM_ERROR, SUCCESS
***********************************************************************************************************************/
uint8_t R_IICA0_Master_Receive(uint8_t sladr8, uint8_t * const rx_buf, uint16_t rx_num, uint8_t wait)
{
    uint8_t status = COM_ERROR;

    g_iica0_limit_time = wait;    /* set timeout data */

    if (0x00U != rx_num)    /* exit if data number is 0 */
    {
        status = R_IICA0_Bus_Check();    /* check IIC bus status */

        if (SUCCESS == status)
        {
            /* Get IIC bus and set access parameters */
            g_iica0_adr_flag = 0x00U;    /* disable address register */
            g_iica0_rx_len = rx_num;    /* set data number to transmit */
            g_iica0_rx_cnt = 0U;
            gp_iica0_rx_address = rx_buf;    /* set data pointer */
            g_iica0_status = TX_SADDR;    /* set operation mode flag */
            /* Start to access IIC bus */
            IICA0 = (sladr8 | 0x01U);    /* transmit slave address */
        }
    }

    return (status);
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Check_Comstate
* Description  : This function readouts of communication status.
* Arguments    : None
* Return Value : g_iica0_status -
***********************************************************************************************************************/
uint8_t R_IICA0_Check_Comstate(void)
{
    return (g_iica0_status);
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Poll
* Description  : This function checks the communication status. Judging by the value of the status variable.
* Arguments    : None
* Return Value : status -
*                    SUCCESS, ON_COMMU, BUS_ERROR, NO_SLAVE, NO_ACK
***********************************************************************************************************************/
uint8_t R_IICA0_Poll(void)
{
    uint8_t status = SUCCESS;    /* set dummy status "SUCCESS" */

    status = g_iica0_status;    /* get communication status */

    if (0x30U > status)    /* check status is error or not */
    {    /* there is no error status */
        if (OP_END <= status)    /* check operation end or not */
        {
            status = SUCCESS;    /* set operation success flag */
        }
        else
        {    /* continue communication */
            status = ON_COMMU;
        }
    }

    return (status);    /* return with status */
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Wait_Comend
* Description  : This function waits in the function until communication is finished.
* Arguments    : stop -
*                    issue stop condition
* Return Value : status -
*                    ON_COMMU, SUCCESS
***********************************************************************************************************************/
uint8_t R_IICA0_Wait_Comend(uint8_t stop)
{
    uint8_t status = ON_COMMU;

    while (ON_COMMU == status)
    {
        status = R_IICA0_Poll();    /* check new status */
        NOP();    /* wait for communication end */
    }

    if ((SUCCESS != status) || (0x00U != stop))
    {
        /* Communication error or argument */
        R_IICA0_StopCondition();    /* issue STOP condition */
        R_IICA0_Wait_Time();    /* wait for 50us */
    }

    return (status);    /* return with status */
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Bus_Check
* Description  : This function checks bus status and issues start condition if released.
* Arguments    : None
* Return Value : status -
*                    BUS_ERROR, BUS_HOLD, SUCCESS
***********************************************************************************************************************/
uint8_t R_IICA0_Bus_Check(void)
{
    uint8_t status = BUS_ERROR;    /* set dummy error flag */

    /* IICA0 is not operating */
    if (0x00U == (g_iica0_status & 0x10U))    /* check if operating or not */
    {
        /* Return with status */
        if ((1U == MSTS0) || (0U == IICBSY0))    /* check if IIC is busy */
        {
            /* IIC bus is usable */
            status = R_IICA0_StartCondition();    /* issue start condition */

            if (SUCCESS == status)
            {
                g_iica0_status = BUS_HOLD;
            }
        }
    }

    return (status);    /* return with status */
}

/***********************************************************************************************************************
* Function Name: R_IICA0_StartCondition
* Description  : This function processes of issuing start condition.
* Arguments    : None
* Return Value : status -
*                    BUS_ERROR, SUCCESS
***********************************************************************************************************************/
uint8_t R_IICA0_StartCondition(void)
{
    uint8_t status = BUS_ERROR;    /* set dummy status "error" flag */
    uint8_t w_count;

    STT0 = 1U;    /* issue IICA0 start condition */

    /* Wait for start condition is detected */
    for (w_count = 0U; w_count <= g_iica0_limit_time; w_count++ )
    {
        if (1U == STD0)
        {
            break;    /* exit with start condition */
        }
    }

    /* Detect start condition or timeout */
    if ((1U == MSTS0) && (1U == STD0))    /* check bus status */
    {
        /* Get bus and success to issue start condition */
        status = SUCCESS;    /* set good result */
        g_iica0_status = BUS_HOLD;    /* set new status */
    }

    return (status);    /* return with status */
}

/***********************************************************************************************************************
* Function Name: R_IICA0_Wait_Time
* Description  : This function waits 50us.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Wait_Time(void)
{
    uint16_t w_count;

    for (w_count = 0U; w_count <= g_iica0_time_count; w_count++ )
    {
        NOP();
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */


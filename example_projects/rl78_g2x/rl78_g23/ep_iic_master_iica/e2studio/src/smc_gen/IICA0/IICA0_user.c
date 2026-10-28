/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : IICA0_user.c
* Component Version: 1.12.0
* Device(s)        : R7F100GSNxFB
* Description      : This file implements device driver for IICA0.
***********************************************************************************************************************/
/***********************************************************************************************************************
Includes
***********************************************************************************************************************/
#include "r_cg_macrodriver.h"
#include "r_cg_userdefine.h"
#include "IICA0.h"
/* Start user code for include. Do not edit comment generated here */
#include "i2c_sensor.h"
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Pragma directive
***********************************************************************************************************************/
#pragma interrupt r_IICA0_interrupt(vect=INTIICA0)
/* Start user code for pragma. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
Global variables and functions
***********************************************************************************************************************/
extern volatile uint16_t g_iica0_time_count;             /* timer count value for 50us */
extern volatile uint8_t g_iica0_status;                  /* iica0 master operation flag */
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
extern volatile uint8_t * gp_iica0_rx_address;           /* iica0 receive buffer address */
extern uint16_t g_iica0_rx_len;                          /* iica0 receive data length */
extern volatile uint16_t g_iica0_rx_cnt;                 /* iica0 receive data count */
extern volatile uint8_t * gp_iica0_tx_address;           /* iica0 send buffer address */
extern volatile uint16_t g_iica0_tx_cnt;                 /* iica0 send data count */
extern volatile uint8_t g_iica0_sl_addr;                 /* iica0 slave address (8bit) */
extern volatile uint8_t g_iica0_adr_reg;                 /* iica0 address register (8bit) */
extern volatile uint8_t g_iica0_adr_flag;                /* iica0 address register flag */
/*
    0x00 : not use address register (for conventional API)
    0x01 : use address c for write mode (only send address register)
    0x10 : use address register for read mode (restart is needed)
*/
extern volatile uint8_t g_iica0_limit_time;              /* timeout limit of start and stop condition */
/* Start user code for global. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Function Name: R_IICA0_Create_UserInit
* Description  : This function adds user code after initializing the IICA0.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
void R_IICA0_Create_UserInit(void)
{
    uint16_t w_freq;    /* clock frequency (MHz unit) */
    uint16_t w_work;    /* w_work for get frequency (MHz unit) */

    /* Please ensure to enable the API function of R_BSP_GetFclkFreqHz() in BSP */
    w_work = get_fclk_freq_hz() >> 16U;    /* get upper 16 bits of Hz */
    w_work <<= 3U;
    w_freq = (w_work + 61U) / 122U;    /* get clock frequency (MHz unit) */

    g_iica0_time_count = ((w_freq * 50U) - 14U) / 7U;    /* set loop count for 50us */
    /* Start user code for user init. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IICA0_callback_master_sendend
* Description  : This function is a callback function when IICA0 finishes master transmission.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_IICA0_callback_master_sendend(void)
{
    SPT0 = 1U;
/* Start user code for r_IICA0_callback_master_sendend. Do not edit comment generated here */
    i2c_master_callback(IICA_MASTER_EVENT_SENDEND);
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IICA0_callback_master_receiveend
* Description  : This function is a callback function when IICA0 finishes master reception.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_IICA0_callback_master_receiveend(void)
{
    SPT0 = 1U;
/* Start user code for r_IICA0_callback_master_receiveend. Do not edit comment generated here */
    i2c_master_callback(IICA_MASTER_EVENT_RECEIVEEND);
/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IICA0_callback_master_error
* Description  : This function is a callback function when IICA0 master error occurs.
* Arguments    : flag -
*                    status flag
* Return Value : None
***********************************************************************************************************************/
static void r_IICA0_callback_master_error(MD_STATUS flag)
{
    /* Start user code for r_IICA0_callback_master_error. Do not edit comment generated here */
    i2c_master_callback(IICA_MASTER_EVENT_ABORTED);
	/* End user code. Do not edit comment generated here */
}

/***********************************************************************************************************************
* Function Name: r_IICA0_master_handler
* Description  : This function is IICA0 master handler
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void r_IICA0_master_handler(void)
{
    uint8_t status = BUS_ERROR;    /* set dummy error flag */

    if (1U == STD0)    /* slave address transmit end */
    {
        /* Slave address transmission end */
        if (1U == ACKD0)
        {
            /* ACK response for slave address and start data transfer */
            if (1U == TRC0)
            {
                /* Data transmit mode operation */
                if (0x00U == g_iica0_adr_flag)    /* check send address register */
                {
                    /* Not address register but data transmit */
                    g_iica0_status = TX_MODE;    /* set data transmit mode */
                    if (g_iica0_tx_cnt > 0U)
                    {
                        /* More data to transmit */
                        IICA0 = *gp_iica0_tx_address;    /* set transmit data */
                        gp_iica0_tx_address++;    /* move pointer to next data */
                        g_iica0_tx_cnt--;    /* count down data number */
                    }
                    else
                    {
                        /* No more data to transmit */
                        g_iica0_status = TX_END;    /* set data transmit end */
                        r_IICA0_callback_master_sendend();
                    }
                }    /* end of data transmit */
                else
                {
                    /* Address register transmit */
                    IICA0 = g_iica0_adr_reg;    /* send address register */
                    g_iica0_status = TX_ADDR_REG;    /* set status */
                }
            }    /* end of data transmit */
            else
            {
                /* Data receive mode operation */
                WTIM0 = 0U;   /* set 8 bit wait mode */
                ACKE0 = 1U;

                IICA0 = DUMMY_DATA;    /* canceling wait and start Rx */
                g_iica0_status = RX_MODE;    /* set receive mode flag */
            }
        }    /* end of ACK for slave address */
        else
        {
            /* NAK response for slave address */
            SPT0 = 1U;    /* issue stop condition */
            g_iica0_status = NO_SLAVE;    /* set communication error flag */
            r_IICA0_callback_master_error(MD_NACK);
        }
    }    /* end of slave address transmit operation */
    else
    {
        /* Data transfer stage(STD0 is 0) */
        if (1U == TRC0)    /* check transmit or receive */
        {
            /* Transmit operation mode */
            if (1U == ACKD0)    /* check slave state */
            {    /* slave is ready for next data */
                /* Success data transfer */
                if ((TX_ADDR_REG == g_iica0_status) && (0x10U == g_iica0_adr_flag))
                {
                    /* End of transmit address register for RAM read mode and restart to read mode */
                    status = R_IICA0_StartCondition();
                    if (SUCCESS == status)
                    {
                        IICA0 = (g_iica0_sl_addr | 0x01U);
                        g_iica0_status = RX_MODE;    /* set receive mode flag */
                    }
                    else
                    {
                        LREL0 = 1U;
                        g_iica0_status = BUS_ERROR;
                    }
                }
                else
                {
                    /* Success data transfer and check remaining data */
                    g_iica0_status = TX_MODE;    /* set transmit mode flag */
                    if (g_iica0_tx_cnt > 0U)    /* check tranmit data number */
                    {
                        /* Prepare next transmit data */
                        IICA0 = *gp_iica0_tx_address;    /* transmit data */
                        gp_iica0_tx_address++;    /* move pointer to next data */
                        g_iica0_tx_cnt--;    /* count down data number */
                    }    /* end of one data transmit */
                    else
                    {
                        /* Data transmit complete, set end flag and exit */
                        g_iica0_status = TX_END;    /* set data transfer end */
                        r_IICA0_callback_master_sendend();
                    }    /* end of transmit all data */
                }
            }    /* end by ACK response */
            else
            {
                g_iica0_status = NO_ACK;    /* set communication error flag */
                r_IICA0_callback_master_error(MD_NACK);
            }    /* end by NACK transmit */
        }    /* end of data transmit */
        else
        {
            /* Receive operation mode */
            if (g_iica0_rx_cnt < g_iica0_rx_len)
            {
                /* Store recieved data */
                *gp_iica0_rx_address = IICA0;    /* store recieved data */
                gp_iica0_rx_address++;    /* move store pointer */
                g_iica0_rx_cnt++;    /* countup data number */

                if (g_iica0_rx_cnt == g_iica0_rx_len)
                {
                    ACKE0 = 0U;    /* NACK for last data */
                    WTIM0 = 1U;    /* change to 9 clock wait */
                    WREL0 = 1U;    /* canceling awit to end */
                 }
                 else
                 {
                    WREL0 = 1U;    /* start next reception */
                 }
            }    /* end of receive continue */
            else
            {
                /* Receive operation complete at 9th clock */
                g_iica0_status = RX_END;    /* set data receive end */
                r_IICA0_callback_master_receiveend();
            }    /* end of data number check of receive */
        }    /* end of data receive */
    }    /* end of data transfer */
/* Master transfer operation end */
}    /* end of r_IICA0_master_handler */

/***********************************************************************************************************************
* Function Name: r_IICA0_interrupt
* Description  : This function is INTIICA0 interrupt service routine.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
static void __near r_IICA0_interrupt(void)
{
    /* Start user code for r_IICA0_interrupt. Do not edit comment generated here */
    /* End user code. Do not edit comment generated here */
    if (1U == MSTS0)    /* check master mode */
    {    /* master mode interrupt */
        r_IICA0_master_handler();
    }
    else
    {   /* slave mode interrupt */
        g_iica0_status = BUS_ERROR;   /* end of master mode with error */
    }
}

/* Start user code for adding. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */

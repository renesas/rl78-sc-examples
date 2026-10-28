/*
* Copyright (c) 2021 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

/***********************************************************************************************************************
* File Name        : r_cg_iica.h
* Version          : 1.0.200
* Device(s)        : R7F103GLJxFB
* Description      : General header file for IICA peripheral.
***********************************************************************************************************************/

#ifndef IICA_H
#define IICA_H

/***********************************************************************************************************************
Macro definitions (Register bit)
***********************************************************************************************************************/
/*
    Peripheral Enable Register 0 (PER0)
*/
/* Control of IICA0 input clock (IICA0EN) */
#define _00_IICA0_CLOCK_STOP                (0x00U)    /* stops supply of input clock */
#define _10_IICA0_CLOCK_SUPPLY              (0x10U)    /* supplies input clock */

/*
    Peripheral Reset Control Register 0 (PPR0)
*/
/* Peripheral reset control of IICA0 (IICA0RES) */
#define _00_IICA0_RESET_RELEASE             (0x00U)    /* released from the reset state */
#define _10_IICA0_RESET_SET                 (0x10U)    /* reset */

/*
    IICA Control Register (IICCTLn0)
*/
/* IIC operation enable (IICEn) */
#define _00_IICA_OPERATION_DISABLE          (0x00U)    /* stop operation */
#define _80_IICA_OPERATION_ENABLE           (0x80U)    /* enable operation */
/* Exit from communications (LRELn) */
#define _00_IICA_COMMUNICATION_NORMAL       (0x00U)    /* normal operation */
#define _40_IICA_COMMUNICATION_EXIT         (0x40U)    /* exit from current communication */
/* Wait cancellation (WRELn) */
#define _00_IICA_WAIT_NOTCANCEL             (0x00U)    /* do not cancel wait */
#define _20_IICA_WAIT_CANCEL                (0x20U)    /* cancel wait */
/* Generation of interrupt when stop condition (SPIEn) */
#define _00_IICA_STOPINT_DISABLE            (0x00U)    /* disable */
#define _10_IICA_STOPINT_ENABLE             (0x10U)    /* enable */
/* Wait and interrupt generation (WTIMn) */
#define _00_IICA_WAITINT_CLK8FALLING        (0x00U)    /* generated at the eighth clock's falling edge */
#define _08_IICA_WAITINT_CLK9FALLING        (0x08U)    /* generated at the ninth clock's falling edge */
/* Acknowledgement control (ACKEn) */
#define _00_IICA_ACK_DISABLE                (0x00U)    /* disable acknowledgement */
#define _04_IICA_ACK_ENABLE                 (0x04U)    /* enable acknowledgement */
/* Start condition trigger (STTn) */
#define _00_IICA_START_NOTGENERATE          (0x00U)    /* do not generate start condition */
#define _02_IICA_START_GENERATE             (0x02U)    /* generate start condition */
/* Stop condition trigger (SPTn) */
#define _00_IICA_STOP_NOTGENERATE           (0x00U)    /* do not generate stop condition */
#define _01_IICA_STOP_GENERATE              (0x01U)    /* generate stop condition */

/*
    IICA Status Register (IICSn)
*/
/* Master device status (MSTSn) */
#define _00_IICA_STATUS_NOTMASTER           (0x00U)    /* slave device status or communication standby status */
#define _80_IICA_STATUS_MASTER              (0x80U)    /* master device communication status */
/* Detection of arbitration loss (ALDn) */
#define _00_IICA_ARBITRATION_NO             (0x00U)    /* arbitration win or no arbitration */
#define _40_IICA_ARBITRATION_LOSS           (0x40U)    /* arbitration loss */
/* Detection of extension code reception (EXCn) */
#define _00_IICA_EXTCODE_NOT                (0x00U)    /* extension code not received */
#define _20_IICA_EXTCODE_RECEIVED           (0x20U)    /* extension code received */
/* Detection of matching addresses (COIn) */
#define _00_IICA_ADDRESS_NOTMATCH           (0x00U)    /* addresses do not match */
#define _10_IICA_ADDRESS_MATCH              (0x10U)    /* addresses match */
/* Detection of transmit/receive status (TRCn) */
#define _00_IICA_STATUS_RECEIVE             (0x00U)    /* receive status */
#define _08_IICA_STATUS_TRANSMIT            (0x08U)    /* transmit status */
/* Detection of acknowledge signal (ACKDn) */
#define _00_IICA_ACK_NOTDETECTED            (0x00U)    /* ACK signal was not detected */
#define _04_IICA_ACK_DETECTED               (0x04U)    /* ACK signal was detected */
/* Detection of start condition (STDn) */
#define _00_IICA_START_NOTDETECTED          (0x00U)    /* start condition not detected */
#define _02_IICA_START_DETECTED             (0x02U)    /* start condition detected */
/* Detection of stop condition (SPDn) */
#define _00_IICA_STOP_NOTDETECTED           (0x00U)    /* stop condition not detected */
#define _01_IICA_STOP_DETECTED              (0x01U)    /* stop condition detected */

/*
    IICA Flag Register (IICFn)
*/
/* STT clear flag (STCFn) */
#define _00_IICA_STARTFLAG_GENERATE         (0x00U)    /* generate start condition */
#define _80_IICA_STARTFLAG_UNSUCCESSFUL     (0x80U)    /* start condition generation unsuccessful */
/* IIC bus status flag (IICBSYn) */
#define _00_IICA_BUS_RELEASE                (0x00U)    /* bus release status */
#define _40_IICA_BUS_COMMUNICATION          (0x40U)    /* bus communication status */
/* Initial start enable trigger (STCENn) */
#define _00_IICA_START_WITHSTOP             (0x00U)    /* generate start condition upon detecting a stop condition */
#define _02_IICA_START_WITHOUTSTOP          (0x02U)    /* generate start condition no detection a stop condition */
/* Communication reservation function disable bit (IICRSVn) */
#define _00_IICA_RESERVATION_ENABLE         (0x00U)    /* enable communication reservation */
#define _01_IICA_RESERVATION_DISABLE        (0x01U)    /* disable communication reservation */

/*
    IICA Control Register 1 (IICCTLn1)
*/
/* Control of address match wakeup (WUPn) */
#define _00_IICA_WAKEUP_STOP                (0x00U)    /* stop address match wakeup function in STOP mode */
#define _80_IICA_WAKEUP_ENABLE              (0x80U)    /* enable address match wakeup function in STOP mode */
/* Address match disabling flag (SVADISn) */
#define _00_IICA_ADDRESS_MATCH_DISABLE_FLAG (0x00U)    /* disables the all address match function */
#define _40_IICA_ADDRESS_MATCH_ENABLE_FLAG  (0x40U)    /* enables the all address match function */
/* Detection of SCL0 pin level (CLDn) */
#define _00_IICA_SCL_LOW                    (0x00U)    /* detect clock line at low level */
#define _20_IICA_SCL_HIGH                   (0x20U)    /* detect clock line at high level */
/* Detection of SDA0 pin level (DADn) */
#define _00_IICA_SDA_LOW                    (0x00U)    /* detect data line at low level */
#define _10_IICA_SDA_HIGH                   (0x10U)    /* detect data line at high level */
/* Operation mode switching (SMCn) */
#define _00_IICA_MODE_STANDARD              (0x00U)    /* operates in standard mode */
#define _08_IICA_MODE_HIGHSPEED             (0x08U)    /* operates in high-speed mode */
/* Digital filter operation control (DFCn) */
#define _00_IICA_FILTER_OFF                 (0x00U)    /* digital filter off */
#define _04_IICA_FILTER_ON                  (0x04U)    /* digital filter on */
/* Operation of clock dividing frequency permission (PRSn) */
#define _00_IICA_fCLK                       (0x00U)    /* clock of dividing frequency operation (fCLK) */
#define _01_IICA_fCLK_HALF                  (0x01U)    /* 2 clock of dividing frequency operation (fCLK/2) */
/* IICA used flag */
#define _80_IICA_ADDRESS_COMPLETE           (0x80U)
#define _00_IICA_MASTER_FLAG_CLEAR          (0x00U)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define DUMMY_DATA                          (0xFFU)     /* dummy data for receive */
#define BUS_FREE                            (0x00U)     /* I2C bus is free */
#define BUS_HOLD                            (0x20U)     /* hold I2C bus (same as above) */
#define TX_MODE                             (0x12U)     /* transmit operation mode */
#define RX_MODE                             (0x14U)     /* receive operation mode */
#define TX_ADDR_REG                         (0x16U)     /* TX address register */
#define TX_SADDR                            (0x18U)     /* TX slave address */
#define OP_END                              (0x20U)     /* operation complete */
#define TX_END                              (0x22U)     /* transmit operation end */
#define RX_END                              (0x24U)     /* receive operation end */
#define ON_COMMU                            (0x01U)     /* on communication */
#define BUS_BUSY                            (0x0FU)     /* I2C bus is busy */
#define BUS_ERROR                           (0x8FU)     /* bus or IICA0 is busy error */
#define NO_SLAVE                            (0x80U)     /* NACK for slave address */
#define NO_ACK                              (0xC0U)     /* NACK for transmit data */
#define SUCCESS                             (0x00U)     /* operation complete */
#define COM_ERROR                           (0xFFU)     /* other error of communication */

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Global functions
***********************************************************************************************************************/
/* Start user code for function. Do not edit comment generated here */
/* End user code. Do not edit comment generated here */
#endif

; Generated configuration header file - do not edit
;;/*
;;* Copyright (c) 2025 Renesas Electronics Corporation and/or its affiliates
;;*
;;* SPDX-License-Identifier: BSD-3-Clause
;;*/
;;/***********************************************************************************************************************
;;* File Name    : r_bsp_config_reference.inc
;;* H/W Platform : GENERIC_RL78_G21
;;* Description  : 
;;***********************************************************************************************************************/
;;/***********************************************************************************************************************
;;* History : DD.MM.YYYY Version  Description
;;*         : 19.12.2025 2.00     First Release
;;***********************************************************************************************************************/

$IFDEF __r_bsp_config_inc__
$ELSE

__r_bsp_config_inc__                .EQU    1
;;/* This macro lets other modules no if a RTOS is being used.
;; 0 : RTOS is not used.
;; 1 : FreeRTOS is used.
;; 2 : embOS is used.(This is not available.)
;; 3 : MicroC_OS is used.(This is not available.)
;; 4 : Renesas ITRON is used.
;; (Note)
;;   Set the same value to BSP_CFG_RTOS_USED in r_bsp_config.h.
;;*/
BSP_CFG_ASM_RTOS_USED               .EQU    0

$ENDIF    ; __r_bsp_config_inc__

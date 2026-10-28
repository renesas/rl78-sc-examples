;;/*
;;* Copyright (c) 2022 Renesas Electronics Corporation and/or its affiliates
;;*
;;* SPDX-License-Identifier: BSD-3-Clause
;;*/
;;/***********************************************************************************************************************
;;* File Name    : r_bsp_config_reference.inc
;;* H/W Platform : GENERIC_RL78_G23
;;* Description  : 
;;***********************************************************************************************************************/
;;/***********************************************************************************************************************
;;* History : DD.MM.YYYY Version  Description
;;*         : 28.02.2022 1.20     First Release
;;*         : 04.07.2025 1.92     Changed the disclaimer.
;;*         : 19.12.2025 2.00     Added notes to prevent omissions in macro definitions setting when using an RTOS.
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

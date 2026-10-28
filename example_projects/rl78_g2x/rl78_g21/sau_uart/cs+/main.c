/*
* Copyright (c) 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
*/

#include "r_smc_entry.h"
#include "sau_uart_ep.h"

int main (void);

int main(void)
{
    EI();
    sau_uart_ep_entry();
    return 0;
}

/***********************************************************************************************************************
* Copyright (c) 2024 - 2026 Renesas Electronics Corporation and/or its affiliates
*
* SPDX-License-Identifier: BSD-3-Clause
***********************************************************************************************************************/
#include "r_smc_entry.h"
#include "tau.h"

int main (void);

int main(void)
{
    EI();
    tau_entry();
    return 0;
}

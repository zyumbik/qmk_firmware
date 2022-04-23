/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, K03, K04, K05, K06, K07, \
    K00_A, K01_A, K02_A, K03_A, K04_A, K05_A, K06_A, K07_A, \
    K00_B, K01_B, K02_B, K03_B, K04_B, K05_B, K06_B, K07_B  \
) \
{ \
    { K00, K01, K02, K03, K04, K05, K06, K07 }, \
    { K00_A, K01_A, K02_A, K03_A, K04_A, K05_A, K06_A, K07_A }, \
    { K00_B, K01_B, K02_B, K03_B, K04_B, K05_B, K06_B, K07_B }  \
}


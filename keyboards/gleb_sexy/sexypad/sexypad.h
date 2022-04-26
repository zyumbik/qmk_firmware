/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "quantum.h"

#define LAYOUT( \
    K00, K01, K02, \
    K00_A, K01_A, K02_A, \
    K00_B, K01_B, K02_B, \
    K10, K11  \
) \
{ \
    { K00, K01, K02, K00_A, K00_B, K01_A, K01_B, K02_A, K02_B }, \
    { K10, K11 }  \
}


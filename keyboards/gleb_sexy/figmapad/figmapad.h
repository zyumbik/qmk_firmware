/* Copyright 2022 Gleb Sabirzyanov <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "quantum.h"

// Bottom, Middle, Top, Encoder Bottom, Encoder Top
// Joystick: Left, Right, Top, Bottom, Middlе
#define LAYOUT( \
    K00, K01, K03, K04, K02 , \
    K05, K08, K07, K06, K09   \
) \
{ \
    { K00, K01, K02, K03, K04 }, \
    { K05, K06, K07, K08, K09 }  \
}

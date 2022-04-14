/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xC88B
#define PRODUCT_ID      0x3388
#define DEVICE_VER      0x0003
#define MANUFACTURER    DPB
#define PRODUCT         Macro3

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 3

/* key matrix pins */
#define DIRECT_PINS {   \
    { B3, B2, B6 }, \
    { B5, B4, E6 }  \
}

#define ENCODERS_PAD_A { F4, F4, B1 }
#define ENCODERS_PAD_B { F5, F6, F7 }

#define ENCODER_RESOLUTION 4

#define UNUSED_PINS

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


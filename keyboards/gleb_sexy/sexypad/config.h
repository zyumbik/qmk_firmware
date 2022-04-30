/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0000
#define PRODUCT_ID      0x0001
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gleb
#define PRODUCT         Sexypad

/* key matrix size */
#define MATRIX_ROWS 2
#define MATRIX_COLS 9

/* key matrix pins */
#define DIRECT_PINS {   \
    { B3, B2, B6, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }, \
    { B5, B4 }  \
}

#define ENCODERS_PAD_A { F4, F4, B1 }
#define ENCODERS_PAD_B { F6, F5, F7 }

#define ENCODER_RESOLUTION 4

#define ENCODERS 3

#define ENCODERS_CW_KEY \
    {                   \
        { 3, 0 },       \
        { 5, 0 },       \
        { 7, 0 }        \
    }
#define ENCODERS_CCW_KEY \
    {                    \
        { 4, 0 },        \
        { 6, 0 },        \
        { 8, 0 }         \
    }

#define UNUSED_PINS

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* */
/* */
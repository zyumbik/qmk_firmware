/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#pragma once
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x0000
#define PRODUCT_ID      0x0002
#define DEVICE_VER      0x0001
#define MANUFACTURER    Gleb
#define PRODUCT         Big L

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 8

/* key matrix pins */
#define DIRECT_PINS {   \
    { B2, B3, B6, C6, D7, B5, E6, B4 }, \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }, \
    { NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN, NO_PIN }  \
}

/*                       0   1   2   3   4   5   6   7    */
#define ENCODERS_PAD_A { F5, F7, F4, F4, F4, F5, F5, F6 }
#define ENCODERS_PAD_B { B1, F4, F5, B1, F6, F6, F7, F7 }

#define ENCODER_RESOLUTION 4

/* Definitions for encoder actions */

#define ENCODERS 8

#define ENCODERS_CW_KEY \
    {                   \
        { 0, 1 },       \
        { 1, 1 },       \
        { 2, 1 },       \
        { 3, 1 },       \
        { 4, 1 },       \
        { 5, 1 },       \
        { 6, 1 },       \
        { 7, 1 }        \
    }
#define ENCODERS_CCW_KEY \
    {                    \
        { 0, 2 },       \
        { 1, 2 },       \
        { 2, 2 },       \
        { 3, 2 },       \
        { 4, 2 },       \
        { 5, 2 },       \
        { 6, 2 },       \
        { 7, 2 }        \
    }

#define UNUSED_PINS

#define BOOTMAGIC_LITE_ROW 0
#define BOOTMAGIC_LITE_COLUMN 0

#define DYNAMIC_KEYMAP_LAYER_COUNT 8

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5


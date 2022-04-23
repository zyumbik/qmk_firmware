/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

#define LAYOUT_via( \
    K00, K01, K02, \
    K00_A, K00_B,  \
    K01_A, K01_B,  \
    K02_A, K02_B,  \
    K10, K11 \
) { \
    { K00, K01, K02, \
    K00_A, K00_B,  \
    K01_A, K01_B,  \
    K02_A, K02_B }, \
    { K10, K11 } \
}

#define empty LAYOUT_via( \
    _______, _______, _______, \
    _______, _______, \
    _______, _______, \
    _______, _______, \
    _______, _______ \
)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT_via(
        KC_A, KC_B, KC_C,
        KC_1, KC_2,
        KC_3, KC_4,
        KC_5, KC_6,
        KC_D, KC_E
    ),
    [1] = LAYOUT_via(
        _______, _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [2] = LAYOUT_via(
        _______, _______, _______,
        _______, _______,
        _______, _______,
        _______, _______,
        _______, _______
    ),
    [3] = empty,
    [4] = empty,
    [5] = empty,
    [6] = empty,
    [7] = empty
};

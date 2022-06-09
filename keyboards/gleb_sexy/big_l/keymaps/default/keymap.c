/* Copyright 2022 <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E, KC_F, KC_G, KC_H,
        KC_1, KC_3, KC_5, KC_7, KC_9, KC_I, KC_K, KC_M,
        KC_2, KC_4, KC_6, KC_8, KC_0, KC_J, KC_L, KC_N
    ),
    [1] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______
    )
};

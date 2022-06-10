/* Copyright 2022 Gleb Sabirzyanov <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H, KC_I, KC_J
    )
};
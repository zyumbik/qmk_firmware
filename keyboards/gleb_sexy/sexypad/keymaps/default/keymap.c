/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_RGBTEST,
        KC_1, KC_3, KC_5,
        KC_2, KC_4, KC_6,
        KC_D, KC_E
    )
};


void keyboard_post_init_user(void) {
    // rgblight_sethsv_at(HSV_WHITE, 0);
}
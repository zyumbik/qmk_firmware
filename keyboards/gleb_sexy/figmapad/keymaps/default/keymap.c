/* Copyright 2022 Gleb Sabirzyanov <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

// Bottom, Middle, Top, Encoder Bottom, Encoder top
// Joystick: Left, Right, Top, Bottom, Middlе
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        KC_A, KC_B, KC_C, KC_D, KC_E,
        KC_F, KC_G, KC_H, KC_I, KC_J
    )
};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    oled_write_P(PSTR("Hello World!"), false);
    return false;
};
#endif
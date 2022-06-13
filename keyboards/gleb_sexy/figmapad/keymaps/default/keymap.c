/* Copyright 2022 Gleb Sabirzyanov <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

enum layer_names {
    _BASE,
    _SFT,
    _AL,
    _NAV
};

// Bottom, Middle, Top, Encoder Bottom, Encoder top
// Joystick: Left, Right, Top, Bottom, Middlе
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_LEFT_GUI, MO(_AL), MO(_NAV), LSFT(2), LSFT(0),
        KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, OSL(_SFT)
    ),
    [_SFT] = LAYOUT(
        KC_LEFT_GUI, MO(_AL), MO(_NAV), LSFT(2), LSFT(0),
        S(KC_LEFT), S(KC_RIGHT), S(KC_UP), S(KC_DOWN), _______
    ),
    [_AL] = LAYOUT(
        KC_LEFT_GUI, MO(_AL), MO(_NAV), LSFT(2), LSFT(0),
        KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, KC_LEFT_SHIFT
    ),
    [_NAV] = LAYOUT(
        KC_LEFT_GUI, MO(_AL), MO(_NAV), LSFT(2), LSFT(0),
        KC_LEFT, KC_RIGHT, KC_UP, KC_DOWN, KC_LEFT_SHIFT
    )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_BASE] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_SFT] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_AL] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
    [_NAV] =   { ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_VOLD, KC_VOLU)  },
};
#endif

#if defined(OLED_ENABLE)
bool oled_task_user(void) {
    oled_write_P(PSTR("Hello World!"), false);
    return false;
};
#endif
/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

#define SHR_LATCH E6
#define SHR_CLOCK C7
#define SHR_DATA  D6

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
    
    writePinLow(C6);
}
/**/
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    writePinLow(C6);
    if (record->event.key.col==0 && record->event.key.row==0 && record->event.pressed) {
        writePinHigh(C6);
    }
    return true;
}

/*
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _RAISE:
        rgblight_setrgb (0x00,  0x00, 0xFF);
        break;
    case _LOWER:
        rgblight_setrgb (0xFF,  0x00, 0x00);
        break;
    case _PLOVER:
        rgblight_setrgb (0x00,  0xFF, 0x00);
        break;
    case _ADJUST:
        rgblight_setrgb (0x7A,  0x00, 0xFF);
        break;
    default: //  for any other layers, or the default layer
        rgblight_setrgb (0x00,  0xFF, 0xFF);
        break;
    }
  return state;
}
*/
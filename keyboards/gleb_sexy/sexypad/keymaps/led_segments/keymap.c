/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include QMK_KEYBOARD_H

#define SHR_LATCH E6
#define SHR_CLOCK C6
#define SHR_DATA  D7
 
static const int led_num[] = {126,12,182,158,204,218,250,14,254,222,0};
static int nums_length = sizeof(led_num) / sizeof(int);

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        RGB_TOG, RGB_MODE_FORWARD, RGB_MODE_RGBTEST,
        KC_1, KC_3, KC_5,
        KC_2, KC_4, KC_6,
        KC_D, KC_E
    )
};

static inline void shift_pulse(void) {
    writePinHigh(SHR_CLOCK);
    writePinLow(SHR_CLOCK);
}

static void shift_out(uint8_t value) {
    writePinLow(SHR_LATCH);
    for (uint8_t i = 0; i < 8; i++) {
        if (value & 0b10000000) {
            writePinHigh(SHR_DATA);
        } else {
            writePinLow(SHR_DATA);
        }

        shift_pulse();
        value = value << 1;
    }
    writePinHigh(SHR_LATCH);
}

static void set_number(int number) {
    shift_out((uint8_t)led_num[number % nums_length]);
}

void keyboard_post_init_user(void) {
    setPinOutput(SHR_DATA);
    setPinOutput(SHR_LATCH);
    setPinOutput(SHR_CLOCK);

    set_number(10);
}

/*
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.key.col==0 && record->event.key.row==0 && record->event.pressed) {
        
    }
    return true;
}
*/

layer_state_t layer_state_set_user(layer_state_t state) {
    int layer = get_highest_layer(state);
    if (layer == 0) {
        set_number(10);
    } else {
        set_number(layer);
    }
    return state;
}
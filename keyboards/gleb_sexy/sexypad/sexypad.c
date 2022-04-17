/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "sexypad.h"

#if !defined(VIA_ENABLE) && defined(ENCODER_ENABLE)
bool encoder_update_kb(uint8_t index, bool clockwise) {
    // if (!encoder_update_user(index, clockwise)) { return false; }
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_1);
        } else {
            tap_code(KC_2);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_3);
        } else {
            tap_code(KC_4);
        }
    } else if (index == 2) {
        if (clockwise) {
            tap_code(KC_5);
        } else {
            tap_code(KC_6);
        }
    }
    return true;
}
#endif


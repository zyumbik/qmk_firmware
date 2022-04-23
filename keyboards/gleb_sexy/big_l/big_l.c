/* Copyright 2020 David Philip Barr <@davidphilipbarr>
 * Copyright 2021 @filterpaper
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "big_l.h"

#if !defined(ENCODERS) && defined(ENCODER_ENABLE)
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
    } else if (index == 3) {
        if (clockwise) {
            tap_code(KC_7);
        } else {
            tap_code(KC_8);
        }
    } else if (index == 4) {
        if (clockwise) {
            tap_code(KC_9);
        } else {
            tap_code(KC_0);
        }
    } else if (index == 5) {
        if (clockwise) {
            tap_code(KC_A);
        } else {
            tap_code(KC_B);
        }
    } else if (index == 6) {
        if (clockwise) {
            tap_code(KC_C);
        } else {
            tap_code(KC_D);
        }
    } else if (index == 7) {
        if (clockwise) {
            tap_code(KC_E);
        } else {
            tap_code(KC_F);
        }
    }
    return true;
}
#endif


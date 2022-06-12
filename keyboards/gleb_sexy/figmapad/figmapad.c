/* Copyright 2022 Gleb Sabirzyanov <@zyumbik>
 * SPDX-License-Identifier: GPL-2.0+
 */

#include "figmapad.h"

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
    }
    return true;
}
#endif


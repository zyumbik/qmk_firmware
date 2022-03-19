/* Copyright 2021 Drashna Jael're
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

#define LAYOUT_nano( \
    k00, k01, k02, \
    k00_a, k00_b \
) { \
    { k00, k01,   k02, k00_a, k00_b } \
}

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define NAVIG 2 // numbers/motion
#define MEDIA 3 // media



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [BASE] = LAYOUT_nano(
        _______, KC_LSFT, MO(1),
        KC_RIGHT, KC_LEFT
    ),
    [SYMB] = LAYOUT_nano(
        RESET,   _______, _______,
        _______, _______
    ),
    [NAVIG] = LAYOUT_nano(
        _______, _______, _______,
        _______, _______
    ),
    [MEDIA] = LAYOUT_nano(
        _______, _______, _______,
        _______, _______
    )
};

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {6, 4, HSV_RED},       // Light 4 LEDs, starting with LED 6
    {12, 4, HSV_RED}       // Light 4 LEDs, starting with LED 12
);
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {9, 2, HSV_CYAN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {11, 2, HSV_PURPLE}
);
// Light LEDs 13 & 14 in green when keyboard layer 3 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {13, 2, HSV_GREEN}
);
// etc..

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides other layers
    my_layer3_layer     // Overrides other layers
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

layer_state_t default_layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(1, layer_state_cmp(state, BASE));
    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(2, layer_state_cmp(state, SYMB));
    rgblight_set_layer_state(3, layer_state_cmp(state, NAVIG));
    return state;
}

// led_config_t g_led_config = {
//     {
//         {  NO_LED, 1, 0 }
//     }, {
//         {  103,  32 }, {  122,  32 }
//     }, {
//         4, 4
//     }
// };

// Gergo se2svorak layout by cttsrk@gmail.com, rev.63
//
// This is a modified Swedish dvorak ("svorak") layout intended for connecting
// to PC systems configured with a regular Swedish or Finnish layout, or MacOS
// systems with the equivalent "Pro" layout. Switching between PC and MAC mode
// persists across power off.
//
// The layout attempts to be comfortable for programming and typing in English
// and Swedish. Some effort has been made to keep symbols accessible and
// compatible with their common bigrams. All symbols are on the base layer or
// the numsym layer, and none are on the shift modifier. This avoids excessive
// modifier-hopping when typing e.g `print!("{:#x?}\n", foo);`.
//
// NOTICE that the layout does not use 10 of the keys (5 per hand) available on
// the Gergo, as they are less ergonomic and not needed for this layout paradigm.
//

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"
#include "se2svorak.h"

// To enable combo keys, uncomment the following line and make the appropriate
// changes in `rules.mk`, `combos.def` and `gergo.def`
//#include "g/keymap_combo.h"

enum se2svorak_layers {
    base = 0,
    base_mac,
    shft,
    numsym,
    numsym_mac,
    navdia,
    ctl,
};

static bool mac_toggled = true;

// `process_record_user` is a hook that runs before the regular processing of
// any key event. Return `true` to continue processing the key event. Return
// `false` to disable further processing of a key event.
//
// Work hard to make layer and modifier switching really robust. We want to be
// able to mash buttons and still end up with the correct active modifiers and
// correct key input. No stuck modifiers, no weird special symbols from odd
// os-specific combinations, just the desired characters and nothing more.
//
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // If the current layer is ctl, deactivate MOD_LCTL for enter, escape or
    // backspace. Activate MOD_LCTL for all other keys.
    if (biton32(layer_state) == ctl) {
        if (keycode == ENT || keycode == ESC || keycode == BSPC) {
            unregister_mods(MOD_LCTL);
        } else {
            if (record->event.pressed) { register_mods(MOD_LCTL); }
        }
        // Deactivate shift for ctrl+w (always ctrl+w and not ctrl+W)
        if (keycode == SE_W) {
            unregister_mods(MOD_LSFT);
        }
    }

    // If the current layer is shft, deactivate MOD_LSFT for quote, comma and
    // dot. Activate MOD_LSFT for all other keys.
    if (biton32(layer_state) == shft) {
        if (keycode == QUOT || keycode == COMM || keycode == DOT) {
            unregister_mods(MOD_LSFT);
        } else {
            if (record->event.pressed) { register_mods(MOD_LSFT); }
        }
    }

    // If the current layer is numsym, deactivate MOD_LSFT for dollar.
    if (biton32(layer_state) == numsym || biton32(layer_state) == numsym_mac) {
        if (keycode == DLR) {
            unregister_mods(MOD_LSFT);
        }
    }

    switch (keycode) {
        // Deactivate MOD_LCTL when releasing the ctl layer
        case MO(ctl):
            if (! record->event.pressed) { unregister_mods(MOD_LCTL); }
            return true;

        // Deactivate MOD_LSFT when releasing the shft layer
        case MO(shft):
            if (! record->event.pressed) { unregister_mods(MOD_LSFT); }
            return true;

        // Persistent toggle between PC and MAC modes
        case KC_F24:
            if (record->event.pressed) {
                if (mac_toggled) {
                    set_single_persistent_default_layer(base);
                    mac_toggled = false;
                } else {
                    set_single_persistent_default_layer(base_mac);
                    mac_toggled = true;
                }
            }
            return false;

        // We want zero to act as a shift modifier since it's on the same
        // physical key as shift. This does nothing when on the numsym layer
        // (which is where zero lives), but make sure we do the right thing if
        // it's held after numsym is released.
        case KC_P0:
            layer_invert(shft);
            unregister_mods(MOD_LSFT);
            return true;

        // Toggle both numsym and numsym_mac layers when in MacOS mode. `MO()`
        // can only toggle one layer, so use layer_invert like so instead:
        case KC_F20:
            layer_invert(numsym);
            layer_invert(numsym_mac);
            return false;
            
        // Send a space when releasing dead grave accent to make it live
        case GRV:
            if (! record->event.pressed) { SEND_STRING(" "); }
            return true;

        // Process all other keys normally
        default:                   
            return true; 
    }
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base layer and macos version.
+-----+-----+-----+-----+-----+-----+                              +-----+-----+-----+-----+-----+-----+
|     |  '  |  ,  |  .  |  p  |  y  |                              |  f  |  g  |  c  |  r  |  l  |     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
| TAB |  a  |  o  |  e  |  u  |  i  |     |                  |     |  d  |  h  |  t  |  n  |  s  |  _  |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
| CTRL|  (  |  q  |  j  |  k  |  x  |     |+-----+    +-----+|     |  b  |  m  |  w  |  v  |  z  |  )  |
+-----+-----+-----+-----+-----+-----+-----+|     |    |     |+-----+-----+-----+-----+-----+-----+-----+
                     +-----++-------++-----+-----+    +-----+-----++-------++-----+
                     | ALT || SPACE || NUM |     |    |     | NAV || SHIFT || WIN |
                     +-----++-------+| SYM |     |    |     | DIA |+-------++-----+
                     MAC CMD         +-----+-----+    +-----+-----+         MAC OPT                   */
[base] = LAYOUT_gergo(
    ____, QUOT, COMM, DOT,  SE_P, SE_Y,                            SE_F, SE_G, SE_C, SE_R, SE_L, ____,
    TAB,  SE_A, SE_O, SE_E, SE_U, SE_I, ____,                ____, SE_D, SE_H, SE_T, SE_N, SE_S, UNDS,
    MO(ctl),LPRN,SE_Q,SE_J, SE_K, SE_X, ____, ____,    ____, ____, SE_B, SE_M, SE_W, SE_V, SE_Z, RPRN,
                    KC_LALT, SPC, MO(numsym), ____,    ____, MO(navdia), MO(shft), KC_LGUI            ),
[base_mac] = LAYOUT_gergo(
    ____, ____, ____, ____, ____, ____,                            ____, ____, ____, ____, ____, ____,           
    ____, ____, ____, ____, ____, ____, ____,                ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____,
                       KC_LCMD, ____, KC_F20, ____,    ____, MO(navdia), ____, KC_LOPT                ),
[shft] = LAYOUT_gergo(
    ____, ____, ____, ____, ____, ____,                            ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____,                ____, ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ____,
                            ____, ____, ____, ____,    ____, ____, ____, ____                         ),

/* Numbers and symbols layer. 
+-----+-----+-----+-----+-----+-----+                              +-----+-----+-----+-----+-----+-----+
|     |  !  |     |     |  :  |  %  |                              |  |  |  7  |  8  |  9  |  ?  |     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
|  "  |  [  |  {  |  }  |  ]  |  \  |     |                  |     |  /  |  4  |  5  |  6  |  +  |  -  |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
|     |  ;  |  <  |  >  |  &  |  #  |     |+-----+    +-----+|     |  *  |  1  |  2  |  3  |  `  |  =  |
+-----+-----+-----+-----+-----+-----+-----+|     |    |     |+-----+-----+-----+-----+-----+-----+-----+
                     +-----++-------++-----+-----+    +-----+-----++-------++-----+
                     |     ||       || XXX |     |    |     |     ||   0   ||     |
                     +-----++-------+| XXX |     |    |     |     |+-------++-----+
                                     +-----+-----+    +-----+-----+                                   */
[numsym] = LAYOUT_gergo(
    ____, EXLM, ____, ____, COLN, PERC,                            PIPE,KC_P7,KC_P8,KC_P9, QUES, ____,
    DQUO, LBRC, LCBR, RCBR, RBRC, BSLS, ____,                ____, SLSH,KC_P4,KC_P5,KC_P6, PLUS, MINS,
    ____, SCLN, LABK, RABK, AMPR, HASH, ____, ____,    ____, ____, ASTR,KC_P1,KC_P2,KC_P3, GRV,  EQL,
                            ____, ____, ____, ____,    ____, ____, KC_P0, ____                        ),
[numsym_mac] = LAYOUT_gergo(
 ____, ____,  ____,  ____,  ____,  ____,                        A(KC_7), ____, ____, ____, ____, ____,
 ____,____,S(LBRC),S(RBRC),____,S(A(KC_7)),____,             ____, ____, ____, ____, ____, ____, ____,
 ____, ____,  ____,  ____,  ____,  ____,  ____, ____,  ____, ____, ____, ____, ____, ____, ____, ____,
                            ____,  ____,  ____, ____,  ____, ____, ____, ____                         ),

/* Navigation and diacritics layer.
+-----+-----+-----+-----+-----+-----+                              +-----+-----+-----+-----+-----+-----+
|     |     |     |     |     |     |                              |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
|     |aring| odia| adia| dia |acute|     |                  |     | pgup| circ|  up |tilde| home|     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
|     |  @  |     |     |     |  $  |     |+-----+    +-----+|     | pgdn| left| down|right| end |     |
+-----+-----+-----+-----+-----+-----+-----+|     |    |     |+-----+-----+-----+-----+-----+-----+-----+
                     +-----++-------++-----+-----+    +-----+-----++-------++-----+
                     |     ||       ||     |     |    |     | XXX ||       ||     |
                     +-----++-------+|     |     |    |     | XXX |+-------++-----+
                                     +-----+-----+    +-----+-----+                                   */
[navdia] = LAYOUT_gergo(
    ____, ____, ____, ____, ____, ____,                            ____, ____, ____, ____, ____, ____,
    ____, ARNG, ODIA, ADIA, DIAE, ACUT, ____,                ____, PGUP, CIRC, KC_UP,TILD, HOME, ____,
    ____, AT,   ____, ____, ____, DLR,  ____, ____,    ____, ____, PGDN, LEFT,KC_DOWN,RGHT, END, ____,
                            ____, ____, ____, ____,    ____, ____, ____, ____                         ),

/* Control modifier layer.
+-----+-----+-----+-----+-----+-----+                              +-----+-----+-----+-----+-----+-----+
|     |pcmac|     |     |     |     |                              |     |     |     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
|     |     |     | esc |     |     |     |                  |     |     | bspc|     |     |     |     |
+-----+-----+-----+-----+-----+-----+-----+                  +-----+-----+-----+-----+-----+-----+-----+
| XXX |     |     |     |     |     |     |+-----+    +-----+|     |     |     |     |     |     |enter|
+-----+-----+-----+-----+-----+-----+-----+|     |    |     |+-----+-----+-----+-----+-----+-----+-----+
                     +-----++-------++-----+-----+    +-----+-----++-------++-----+
                     |     ||       ||     |     |    |     |     ||       ||     |
                     +-----++-------+|     |     |    |     |     |+-------++-----+
                                     +-----+-----+    +-----+-----+                                   */
[ctl] = LAYOUT_gergo(
    ____,KC_F24,____, ____, ____, ____,                            ____, ____, ____, ____, ____, ____,
    ____, ____, ____, ESC,  ____, ____, ____,                ____, ____, BSPC, ____, ____, ____, ____,
    ____, ____, ____, ____, ____, ____, ____, ____,    ____, ____, ____, ____, ____, ____, ____, ENT,
                            ____, ____, ____, ____,    ____, ____, ____, ____                         ),

};

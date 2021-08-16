#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

#define SPC_FN2 LT(2, KC_SPC)
#define BSPC_FN1 LT(1, KC_BSPC)
#define ALT_TAB LALT(KC_TAB)

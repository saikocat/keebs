#pragma once

#include QMK_KEYBOARD_H

/* Define Hardware Microcontroller is using Bit-C */
#define HW_BITC 1

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    SPC_FN2 = LT(2, KC_SPC),
    BSPC_FN1 = LT(1, KC_BSPC),
};

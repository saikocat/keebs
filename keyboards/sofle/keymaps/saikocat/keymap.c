/* Copyright 2021 Saikocat
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

enum layer_number {
  _BASE = 0,
  _SYMBOLS,
  _NAVUTIL,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_LGUI, KC_ENT, LALT_T(KC_GRV), LT(1,KC_BSPC), KC_SPC, KC_SPC, LT(2,KC_ENT), RCTL_T(KC_DEL), KC_RALT, KC_RGUI),
    [_SYMBOLS] = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_EQL, KC_LCBR, KC_RCBR, KC_MINS, KC_PIPE, _______, KC_MINS, KC_MINS, KC_MINS, KC_PLUS, _______, KC_TILD, KC_LBRC, KC_9, KC_0, KC_RBRC, KC_BSLS, KC_ASTR, KC_PLUS, KC_EQL, KC_UNDS, KC_COLN, KC_DQUO, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, XXXXXXX, KC_CIRC, KC_AMPR, KC_LT, KC_GT, KC_QUES, _______, _______, _______, _______, _______, KC_ENT, KC_BSPC, _______, _______, _______, _______),
    [_NAVUTIL] = LAYOUT(KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, _______, RESET, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_BSPC), _______, LCTL(KC_RGHT), KC_PSCR, KC_DEL, _______, _______, _______, _______, _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, DF(0), _______, _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, DF(2), _______, _______, _______, _______, _______, KC_BSPC, KC_ENT, _______, KC_GRV, _______, _______),
    [_ADJUST] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};



/* Function: encoder
 * -----------------
 * A rotary encoder is a device that you can twist to perform actions.
 * Some encoders can also be pushed, just like a button!
 * A rotary encoder twists clockwise and counter clockwise.
 * It lends itself to actions that you'd otherwise need to repeatedly press a button for,
 * and to actions that have both a forward and a reverse direction.
 *
 * Reference: https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
 */

#ifdef ENCODER_ENABLE

/* Audio control */
void fn_rotary_audio_control(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

/* Scrolling */
void fn_rotary_scrolling(bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGDOWN);
    } else {
        tap_code(KC_PGUP);
    }
}

/* Tabbing
 * -------
 * Moving through browser mimicing Control + Tab and Control + Shift + Tab
 */
void fn_rotary_tabbing(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
}

/* History Scrubbing
 * -----------------
 * This will perform Control + Z when you turn the encoder clockwise,
 * and Control + Y when turning it counterclockwise.
 * With this, you can easily "scroll" through the history when editing a document.
 */
void fn_rotary_history_scrubbing(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_Y));
    } else {
        tap_code16(C(KC_Z));
    }
}

/* Scrolling Horizontally by Word
 * ------------------------------
 * This will perform Control + Right Arrow when you turn the encoder clockwise,
 * and Control + Left Arrow when turning it counterclockwise.
 * If you hold shift while turning the encoder, you'll be able to select words while the cursor moves!
 */
void fn_rotary_word_scrolling(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_RGHT));
    } else {
        tap_code16(C(KC_LEFT));
    }
}

/* Scrolling Through Search Results
 * --------------------------------
 * Shortcuts to move to the next or previous result. F3 and Shift + F3.
 */
void fn_rotary_search_through_results(bool clockwise) {
    if (clockwise) {
        tap_code(KC_F3);
    } else {
        tap_code16(S(KC_F3));
    }
}

/* User defined func that will be called by QMK every time encoder is turned */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        fn_rotary_search_through_results(clockwise);
    } else if (index == 1) {
        fn_rotary_audio_control(clockwise);
    }
    return true;
}

#endif

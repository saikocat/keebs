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

#include "definitions.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE]   = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_LGUI, SH_MON, LALT_T(KC_GRV), LT(1, KC_BSPC), KC_SPC, KC_ENT, LT(2, KC_SPC), RCTL_T(KC_DEL), KC_RALT, KC_RGUI),
    [_LOWER]  = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, _______, KC_EXLM, KC_DLR, KC_LCBR, KC_RCBR, KC_PIPE, KC_CIRC, KC_UNDS, KC_MINS, KC_EQL, KC_BSLS, _______, _______, KC_AT, KC_PERC, KC_LPRN, KC_RPRN, KC_GRV, KC_AMPR, KC_PLUS, KC_EQL, KC_UNDS, KC_COLN, KC_DQUO, _______, KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, _______, XXXXXXX, KC_ASTR, KC_MINS, KC_LT, KC_GT, KC_QUES, _______, _______, _______, _______, _______, KC_ENT, KC_BSPC, _______, _______, _______, _______),
    [_RAISE]  = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, DF(0), KC_INS, KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, DF(2), _______, _______, _______, _______, _______, KC_BSPC, KC_ENT, _______, _______, _______, _______),
    [_ADJUST] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, _______, _______, _______, _______, _______, _______, KC_PSCR, _______, _______, _______, _______, KC_F11, _______, _______, RESET, EEP_RST, _______, _______, KC_CAPS, _______, _______, _______, _______, _______, _______, KC_F12, DF(0), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
    // clang-format on

    /*
     * [Layer Template]
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /       /       \      \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
};

/* Hold _LOWER and _RAISE set to _ADJUST */
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_FN1:
            return 130;
        case SPC_FN2:
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}

/* Press a Mod Tap key, tap another key (press and release) and then release the Mod Tap key,
 * all within the tapping term, it will output the tapping function for both keys.
 */
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_FN1:
            return true;
        default:
            return false;
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
#    include "features/pet_neko.h"
    pet_handle_keycode(keycode, record);
#endif

    return true;
}

void suspend_power_down_user(void) {
#ifdef OLED_DRIVER_ENABLE
    oled_off();
#endif
}

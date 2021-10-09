/* Copyright (C) 2021 @saikocat
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


/* ,-----------------------------------------.                ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | GESC |  A   |  S   |  D   |  F   |  G   |                |  H   |  J   |  K   |  L   | ; :  | ' "  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |SFTENT|  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  |OS_SFT|
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             | ALT  | LWR  |      |  |RSFT_T| RSE  | ADJ  |
 *                             | ESC  | BSPC | SPC  |  | ENT  | SPC  | COL  |
 *                             `--------------------'  `--------------------'
 */
#define __LLY_S3X6H3__QWERTY \
    KC_TAB,  _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________, KC_BSPC,       \
    KC_LCTL, _________________QWERTY_L2_________________,        _________________QWERTY_R2_________________,                \
    KC_LSFT, _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________, OSM(MOD_LSFT), \
             _____________BOTTOM_HOMEROW_L______________,        _____________BOTTOM_HOMEROW_R______________

/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  Q   |  W   |  F   |  P   |  B   |                |  J   |  L   |  U   |  Y   | ; :  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  A   |  R   |  S   |  T   |  G   |                |  M   |  N   |  E   |  I   |  O   | ' "  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  D   |  V   |                |  K   |  H   | , <  | . >  | / ?  |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LLY_S3X6H3__COLEMAK_DH \
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,        ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,       \
    KC_LCTL, ______________COLEMAK_MOD_DH_L2____________,        ______________COLEMAK_MOD_DH_R2____________,                \
    KC_LSFT, ______________COLEMAK_MOD_DH_L3____________,        ______________COLEMAK_MOD_DH_R3____________, OSM(MOD_LSFT), \
             _____________BOTTOM_HOMEROW_L______________,        _____________BOTTOM_HOMEROW_R______________



#define __LLY_S3X6H3__LOWER \
    _______,   _________________LOWER_L1__________________,        _________________LOWER_R1__________________, _______, \
    _______,   _________________LOWER_L2__________________,        _________________LOWER_R2__________________, KC_DQUO, \
    KC_SFTENT, _________________LOWER_L3__________________,        _________________LOWER_R3__________________, _______, \
                                SH_MON, _______,   _______,        _______, _______, _______


#define __LLY_S3X6H3__RAISE \
    _______, _________________RAISE_L1__________________,        _________________RAISE_R1__________________, KC_DEL,  \
    _______, _________________RAISE_L2__________________,        _________________RAISE_R2__________________, KC_LCTL, \
    _______, _________________RAISE_L3__________________,        _________________RAISE_R3__________________, _______, \
                               _______, _______, _______,        _______, _______, _______


#define __LLY_S3X6H3__ADJUST \
    _______, _________________ADJUST_L1_________________,        _________________ADJUST_R1_________________,  KC_BSPC, \
    _______, _________________ADJUST_L2_________________,        _________________ADJUST_R2_________________,  _______, \
    _______, _________________ADJUST_L3_________________,        _________________ADJUST_R3_________________,  KC_LGUI, \
                              KC_0,    _______,  _______,        _______, _______, _______


#define __LLY_S3X6H3__SPECIAL \
    _______, RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,                              XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,                              XXXXXXX, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, XXXXXXX, \
    _______, C_S_T(KC_Z), C_S_T(KC_X), C_S_T(KC_C), C_S_T(KC_V), C_S_T(KC_TAB),        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                                     _______, _______, _______,        _______, _______, _______

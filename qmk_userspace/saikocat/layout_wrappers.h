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

#pragma once

#include "layouts/crkbd.h"
#include "layouts/sofle.h"
#include "layouts/std_split_3x6_3.h"

#define HR_SGAC(k1, k2, k3, k4) SFT_T(k1), GUI_T(k2), ALT_T(k3), CTL_T(k4)
#define HR_SCGA(k1, k2, k3, k4) SFT_T(k1), CTL_T(k2), GUI_T(k3), ALT_T(k4)

// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH



#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH


#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_GRV
#define _________________LOWER_L3__________________       KC_RBRC, KC_EQL,  KC_PLUS, KC_MINS, KC_TILD

#define _________________LOWER_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS
#define _________________LOWER_R2__________________       KC_DQUO, KC_LCBR, KC_EQL,  KC_RCBR, KC_RBRC
#define _________________LOWER_R3__________________       KC_ASTR, KC_PLUS, KC_LT,   KC_GT,   KC_LBRC


#define _________________RAISE_L1__________________       KC_PAST, KC_7,   KC_8,    KC_9,    KC_PMNS
#define _________________RAISE_L2__________________       KC_EQL,  KC_4,   KC_5,    KC_6,    KC_PPLS
#define _________________RAISE_L3__________________       KC_P0,   KC_1,   KC_2,    KC_3,    KC_PSLS

#define _________________RAISE_R1__________________       DF(_QWERTY), DF(_COLEMAK_DH), DF(_RAISE), DF(_GAME),  KC_PSCR
#define _________________RAISE_R2__________________       KC_LEFT,     KC_DOWN,         KC_UP,      KC_RGHT,    KC_LSFT
#define _________________RAISE_R3__________________       KC_HOME,     KC_PGDN,         KC_PGUP,    KC_END,     KC_INS


#define _________________ADJUST_L1_________________       _______,  _______, _______, _______, _______
#define _________________ADJUST_L2_________________       KC_LSFT,  KC_LCTL, KC_LGUI, KC_LALT, KC_CAPS
#define _________________ADJUST_L3_________________       C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), C(KC_TAB)

#define _________________ADJUST_R1_________________       _______, KC_F7, KC_F8, KC_F9, KC_F10
#define _________________ADJUST_R2_________________       _______, KC_F4, KC_F5, KC_F6, KC_F11
#define _________________ADJUST_R3_________________       _______, KC_F1, KC_F2, KC_F3, KC_F12


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define _________________FUNC_LEFT_________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define _________________FUNC_RIGHT________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10

#define ___________________BLANK___________________       _______, _______, _______, _______, _______

#define _____________BOTTOM_HOMEROW_L______________       ESC_ALT,    BSPC_LWR, SPC_NUM
#define _____________BOTTOM_HOMEROW_R______________       KC_SFTENT,  SPC_RSE,  COLN_ADJ

// clang-format on

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

#include "layouts/std_split_3x6_3.h"
#include "layouts/crkbd.h"
#include "layouts/kyria.h"

#define HRM_GACS(k1, k2, k3, k4) GUI_T(k1), ALT_T(k2), SFT_T(k3), CTL_T(k4)

// clang-format off
#define _________________QWERTY_L1_________________       KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _________________QWERTY_L2_________________       KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _________________QWERTY_L3_________________       KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _________________QWERTY_R1_________________       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _________________QWERTY_R2_________________       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN
#define _________________QWERTY_R3_________________       KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define _________________QWERTY_HR_L2______________       HR_A,    HR_S,    HR_D,    HR_F,    KC_G
#define _________________QWERTY_HR_R2______________       KC_H,    HR_J,    HR_K,    HR_L,    HR_SCLN
#define _________________QWERTY_HR_ALT_L2__________       KC_A,    HR_S,    HR_D,    HR_F,    KC_G
#define _________________QWERTY_HR_ALT_R2__________       KC_H,    HR_J,    HR_K,    HR_L,    KC_SCLN
#define _________________QWERTY_HR_ALT_L3__________       HR_Z,    KC_X,    KC_C,    KC_V,    KC_B
#define _________________QWERTY_HR_ALT_R3__________       KC_N,    KC_M,    KC_COMM, KC_DOT,  HR_SLSH

#define ______________COLEMAK_MOD_DH_L1____________       KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define ______________COLEMAK_MOD_DH_L2____________       KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define ______________COLEMAK_MOD_DH_L3____________       KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define ______________COLEMAK_MOD_DH_R1____________       KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define ______________COLEMAK_MOD_DH_R2____________       KC_M,    KC_N,    KC_E,    KC_I,    KC_O
#define ______________COLEMAK_MOD_DH_R3____________       KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

#define ______________COLEMAK_MOD_DH_HR_L2_________       HR_A,    HR_R,    HR_S,    HR_T,    KC_G
#define ______________COLEMAK_MOD_DH_HR_R2_________       KC_M,    HR_N,    HR_E,    HR_I,    HR_O
#define ______________COLEMAK_MOD_DH_HR_ALT_L2_____       KC_A,    HR_R,    HR_S_CM, HR_T,    KC_G
#define ______________COLEMAK_MOD_DH_HR_ALT_R2_____       KC_M,    HR_N,    HR_E,    HR_I,    KC_O
#define ______________COLEMAK_MOD_DH_HR_ALT_L3_____       HR_Z,    KC_X,    KC_C,    KC_D,    KC_V
#define ______________COLEMAK_MOD_DH_HR_ALT_R3_____       KC_K,    KC_H,    KC_COMM, KC_DOT,  HR_SLSH

#define _________________LOWER_L1__________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define _________________LOWER_L2__________________       KC_LBRC, KC_LPRN, KC_UNDS, KC_RPRN, KC_GRV
#define _________________LOWER_L3__________________       KC_RBRC, KC_EQL,  KC_PLUS, KC_MINS, KC_TILD

#define _________________LOWER_R1__________________       KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS
#define _________________LOWER_R2__________________       KC_DQUO, KC_LCBR, KC_EQL,  KC_RCBR, KC_RBRC
#define _________________LOWER_R3__________________       KC_ASTR, KC_PLUS, KC_LT,   KC_GT,   KC_LBRC


#define _________________RAISE_L1__________________       _______,    _______,     _______,      CAPSWRD,   G(KC_SPC) 
#define _________________RAISE_L2__________________       C(KC_LEFT), C(KC_RIGHT), C(S(KC_TAB)), C(KC_TAB), CMB_TOG
#define _________________RAISE_L3__________________       C(KC_Z),    C(KC_X),     C(KC_C),      ALT_TAB,   C(KC_V)

#define _________________RAISE_R1__________________       DF(_QWERTY), DF(_COLEMAK_DH), DF(_NAVIGATION), DF(_GAME),  KC_PSCR
#define _________________RAISE_R2__________________       KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_INS
#define _________________RAISE_R3__________________       KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______


#define _________________ADJUST_L1_________________       _______, _______, _______,  KC_CAPS, _______
#define _________________ADJUST_L2_________________       ________________MOUSE_BUTTON_______________
#define _________________ADJUST_L3_________________       C(KC_Z),  C(KC_X), C(KC_C), C(KC_V), _______

#define _________________ADJUST_R1_________________       _______, KC_F7, KC_F8, KC_F9, KC_F10
#define _________________ADJUST_R2_________________       _______, KC_F4, KC_F5, KC_F6, KC_F11
#define _________________ADJUST_R3_________________       _______, KC_F1, KC_F2, KC_F3, KC_F12


#define _________________SYMBOL_L1_________________       _______, KC_AT,   KC_DLR,  KC_HASH, _______
#define _________________SYMBOL_L2_________________       KC_LBRC, KC_LPRN, KC_DQUO, KC_RPRN, KC_GRV
#define _________________SYMBOL_L3_________________       KC_TILD, KC_EXLM, KC_PERC, KC_MINS, _______

#define _________________SYMBOL_R1_________________       _______, KC_AMPR, KC_CIRC, KC_ASTR, _______
#define _________________SYMBOL_R2_________________       KC_PLUS, KC_LCBR, KC_EQL,  KC_RCBR, KC_RBRC
#define _________________SYMBOL_R3_________________       _______, KC_UNDS, KC_PIPE, KC_BSLS, KC_QUOT


#define ________________NUMBER_LEFT________________       KC_1,    KC_2,    KC_3,    KC_4,    KC_5
#define ________________NUMBER_RIGHT_______________       KC_6,    KC_7,    KC_8,    KC_9,    KC_0
#define ________________NUMBER_LEFT_BEAKL__________       KC_3,    KC_2,    KC_1,    KC_0,    KC_4
#define ________________NUMBER_RIGHT_BEAKL_________       KC_7,    KC_6,    KC_5,    KC_9,    KC_8
#define ________________FUNC_LEFT__________________       KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5
#define ________________FUNC_RIGHT_________________       KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10
#define ________________SYMBOL_LEFT________________       KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC
#define ________________SYMBOL_RIGHT_______________       KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

#define ________________NUMPAD_TOP_________________       _______,  KC_7,  KC_8,  KC_9,  KC_EQL
#define ________________NUMPAD_MID_________________       KC_PAST,  KC_4,  KC_5,  KC_6,  KC_PPLS
#define ________________NUMPAD_BOT_________________       KC_PSLS,  KC_1,  KC_2,  KC_3,  KC_PMNS
#define ________________NUMPAD_THUMB_______________       KC_ENT,   KC_P0, KC_PDOT


#define _________________SPECIAL_L1________________       QK_BOOT, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX
#define _________________SPECIAL_L2________________       XXXXXXX, XXXXXXX, EH_LEFT, EH_RGHT, CG_TOGG


#define ________________MOUSE_BUTTON_______________       TB_SCR,  TB_MCL,  TB_RCL,  TB_LCL,  TB_RCL

#define ________________HOME_ROW_L_________________       KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______
#define ________________HOME_ROW_R_________________       _______, KC_RCTL, KC_RSFT, KC_RALT, KC_RGUI
#define ________________HOME_ROW_OSM_L_____________       OSM(MOD_LGUI), OSM(MOD_LALT), OSM(MOD_LSFT), OSM(MOD_LCTL), _______
#define ________________HOME_ROW_OSM_R_____________       _______,       OSM(MOD_RCTL), OSM(MOD_RSFT), OSM(MOD_RALT), OSM(MOD_RGUI)

#define ___________________BLANK___________________       _______, _______, _______, _______, _______
#define _________________DISABLED__________________       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX


#define ______________THUMBCLUSTER_3x3_L___________       ESC_ALT, DEL_LWR, BSPC_NUM
#define ______________THUMBCLUSTER_3x3_R___________       KC_SPC,  SPC_RSE, COLN_ADJ
#define ______________THUMBCLUSTER_3x3_GAME_R______       KC_ENT,  SPC_RSE, COLN_ADJ

// clang-format on

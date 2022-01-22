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

#include "quantum.h"

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _GAME,

    _LOWER,
    _RAISE,
    _NUM,
    _SYMNUM,
    _ADJUST,
    _SPECIAL,
    _GAME_NUM,

    _SYMBOL     = _LOWER,
    _NAVIGATION = _RAISE,
};

/* Define custom keycodes */
enum userspace_custom_keycodes {
    QMK_BEST = SAFE_RANGE,
    ALT_TAB,
    COLN_ADJ = LT(_ADJUST, KC_SCLN),
    SPC_LWR  = LT(_LOWER, KC_SPC),
    BSPC_LWR = LT(_LOWER, KC_BSPC),
    TAB_LWR  = LT(_LOWER, KC_TAB),
    SPC_RSE  = LT(_RAISE, KC_SPC),
    DEL_LWR  = LT(_LOWER, KC_DEL),
    DEL_RSE  = LT(_RAISE, KC_DEL),
    ENT_RSE  = LT(_RAISE, KC_ENTER),
    SCLN_ADJ = LT(_ADJUST, KC_SCLN),
    SPC_ADJ  = LT(_ADJUST, KC_SPC),
    SPC_NUM  = LT(_NUM, KC_SPC),
    BSPC_NUM = LT(_NUM, KC_BSPC),
    ESC_ALT  = LALT_T(KC_ESC),
    QUOT_CTL = MT(MOD_RCTL, KC_QUOTE),
    /* Trackball: Scroll, Left Click, Right Click, Middle Click */
    TB_SCR,
    TB_LCL,
    TB_RCL,
    TB_MCL,
    /* Home row mods left hand */
    HR_Z = LGUI_T(KC_Z),
    HR_A = LGUI_T(KC_A),
    HR_S = LALT_T(KC_S),
    HR_D = LSFT_T(KC_D),
    HR_F = LCTL_T(KC_F),
    // Colemak //
    HR_R    = LALT_T(KC_R),
    HR_S_CM = LSFT_T(KC_S),
    HR_T    = LCTL_T(KC_T),
    /* Home row mods right hand */
    HR_J    = RCTL_T(KC_J),
    HR_K    = RSFT_T(KC_K),
    HR_L    = LALT_T(KC_L),
    HR_SCLN = RGUI_T(KC_SCLN),
    HR_SLSH = RGUI_T(KC_SLSH),
    // Colemak //
    HR_N = RCTL_T(KC_N),
    HR_E = RSFT_T(KC_E),
    HR_I = LALT_T(KC_I),
    HR_O = RGUI_T(KC_O),
};

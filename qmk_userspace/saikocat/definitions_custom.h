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

/* Define layer names */
enum userspace_layers {
    _QWERTY = 0,
    _COLEMAK_DH,
    _GAME,
    _NUM_NUMPAD,
    _LOWER,
    _RAISE,
    _ADJUST,
    _SPECIAL,
    _GAME_NUM,
    _SYMBOL     = _LOWER,
    _NAVIGATION = _RAISE,
    _NUM_FN     = _ADJUST,
};

/* Define custom keycodes */
enum userspace_custom_keycodes {
    QMK_BEST = SAFE_RANGE,
    COLN_ADJ,
    SPC_LWR  = LT(_LOWER, KC_SPC),
    BSPC_LWR = LT(_LOWER, KC_BSPC),
    SPC_RSE  = LT(_RAISE, KC_SPC),
    DEL_RSE  = LT(_RAISE, KC_DEL),
    ENT_RSE  = LT(_RAISE, KC_ENTER),
    SCLN_ADJ = LT(_ADJUST, KC_SCLN),
    SPC_ADJ  = LT(_ADJUST, KC_SPC),
    SPC_NUM  = LT(_NUM_NUMPAD, KC_SPC),
    ESC_ALT  = LALT_T(KC_ESC),
};

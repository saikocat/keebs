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
#include "version.h"
#include "action.h"

#include "layers.h"

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
    ESC_ALT  = LALT_T(KC_ESC),
};

void unshift_key_tap(uint16_t kc, uint16_t shift_kc);

bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer);
bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed);

bool process_record_tri_layer_state(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);
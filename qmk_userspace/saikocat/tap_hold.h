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

#include "definitions_custom.h"

uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record);
bool     get_hold_on_other_key_press_keymap(uint16_t keycode, keyrecord_t *record);
bool     get_permissive_hold_keymap(uint16_t keycode, keyrecord_t *record);

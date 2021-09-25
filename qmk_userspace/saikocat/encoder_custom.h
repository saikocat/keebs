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

void matrix_scan_encoder(void);
bool encoder_update_keymap(uint8_t index, bool clockwise);

void encoder_fn_audio_control(bool clockwise);
void encoder_fn_scrolling(bool clockwise);
void encoder_fn_tabbing(bool clockwise);
void encoder_fn_history_scrubbing(bool clockwise);
void encoder_fn_word_scrolling(bool clockwise);
void encoder_fn_search_through_results(bool clockwise);
void encoder_fn_wins_tabbing(bool clockwise, bool* is_alt_tab_active, uint16_t* alt_tab_timer);
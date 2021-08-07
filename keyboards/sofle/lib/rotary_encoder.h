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

#pragma once

#include "quantum.h"

bool is_alt_tab_active;
uint16_t alt_tab_timer;

void fn_rotary_audio_control(bool clockwise);
void fn_rotary_scrolling(bool clockwise);
void fn_rotary_tabbing(bool clockwise);
void fn_rotary_history_scrubbing(bool clockwise);
void fn_rotary_word_scrolling(bool clockwise);
void fn_rotary_search_through_results(bool clockwise);
void fn_rotary_wins_tabbing(bool clockwise);

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

#include "saikocat.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_QWERTY]     = LAYOUT_sofle_wrapper(__LLY__QWERTY),
    [_COLEMAK_DH] = LAYOUT_sofle_wrapper(__LLY__COLEMAK_DH),
    [_LOWER]      = LAYOUT_sofle_wrapper(__LLY__LOWER),
    [_RAISE]      = LAYOUT_sofle_wrapper(__LLY__RAISE),
    [_ADJUST]     = LAYOUT_sofle_wrapper(__LLY__ADJUST),
    [_SPECIAL]    = LAYOUT_sofle_wrapper(__LLY__SPECIAL),
};
// clang-format on

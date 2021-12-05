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

#include "quantum/color.h"

cRGBW* colour_cycle_hue(cRGBW* state);
cRGBW* colour_cycle_hue_stateful(void);
cRGBW* colour_cycle_tint(cRGBW* state);
cRGBW* colour_cycle_tint_stateful(void);
cRGBW* colour_cycle_tone(cRGBW* state);
cRGBW* colour_cycle_tone_stateful(void);

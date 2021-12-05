/* Copyright (C) 2021 @saikocat
 *
 * This program is free software: you can ristribute it and/or modify
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

#include "colours_control.h"

// http://www.workwithcolor.com/color-chart-full-01.htm

cRGBW rgbw_curr_state = {.r = 255, .g = 0, .b = 0, .w = 0};

cRGBW* colour_cycle_hue(cRGBW* state) {
    if (state->r != 255 && state->g != 255 && state->b != 255) {
        state->r = 255;
    }
    if (state->r == 255 && state->g < 255 && state->b == 0) {
        state->g += 15;
    } else if (state->g == 255 && state->b == 0 && state->r > 0) {
        state->r -= 15;
    } else if (state->r == 0 && state->b < 255 && state->g == 255) {
        state->b += 15;
    } else if (state->b == 255 && state->g > 0 && state->r == 0) {
        state->g -= 15;
    } else if (state->g == 0 && state->b == 255 && state->r < 255) {
        state->r += 15;
    } else if (state->g == 0 && state->b > 0 && state->r == 255) {
        state->b -= 15;
    }
    return state;
}

cRGBW* colour_cycle_hue_stateful(void) { return colour_cycle_hue(&rgbw_curr_state); }

cRGBW* colour_cycle_tint(cRGBW* state) {
    if (state->w < 255) {
        state->w += 15;
    } else {
        state->w = 0;
    }
    return state;
}

cRGBW* colour_cycle_tint_stateful(void) { return colour_cycle_tint(&rgbw_curr_state); }

cRGBW* colour_cycle_tone(cRGBW* state) {
    if (state->g > 0) {
        state->g -= 15;
    }
    if (state->r > 0) {
        state->r -= 15;
    }
    if (state->b > 0) {
        state->b -= 15;
    }
    return state;
}

cRGBW* colour_cycle_tone_stateful(void) { return colour_cycle_tone(&rgbw_curr_state); }

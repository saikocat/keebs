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

#ifdef OLED_ENABLE
#    define OLED_TIMEOUT 64000
#    define OLED_BRIGHTNESS 128
#    define OLED_UPDATE_INTERVAL 50
#endif

/* Restore default values for TAPPING_TERM & TAP_CODE_DELAY & ENCODER_RES */
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#    define TAPPING_TERM 200
#endif

#define TAPPING_TERM_PER_KEY

#ifdef TAP_CODE_DELAY
#    undef TAP_CODE_DELAY
#    define TAP_CODE_DELAY 10 /* 100 */
#endif

#define PERMISSIVE_HOLD_PER_KEY

#ifdef ENCODER_RESOLUTION
#    undef ENCODER_RESOLUTION
#    define ENCODER_RESOLUTION 4
#endif

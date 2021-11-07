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

/* Set Polling rate to 1000Hz */
#define USB_POLLING_INTERVAL_MS 1

/* Tap-Hold configurations */
#ifdef TAPPING_TERM
#    undef TAPPING_TERM
#endif
#if defined(KEYBOARD_crkbd)
#    define TAPPING_TERM 200
#else
#    define TAPPING_TERM 175
#endif

#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD_PER_KEY

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

/* Split keyboard setting */
#if defined(SPLIT_KEYBOARD)
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    ifdef WPM_ENABLE
#        define SPLIT_WPM_ENABLE
#    endif
#    ifdef OLED_ENABLE
#        define SPLIT_OLED_ENABLE
#    endif
#endif

/* OLED setting
 * - OLED_DISABLE_TIMEOUT: Prevent matrix_changed triggering oled_on(),
 *   timeout using our own idle timer
 */
#ifdef OLED_ENABLE
#    ifdef OLED_UPDATE_INTERVAL
#        undef OLED_UPDATE_INTERVAL
#    endif
#    ifdef SPLIT_KEYBOARD
#        define OLED_UPDATE_INTERVAL 60
#    else
#        define OLED_UPDATE_INTERVAL 15
#    endif
#    define OLED_DISABLE_TIMEOUT
#    ifdef OLED_FONT_H
#        undef OLED_FONT_H
#    endif
#    define OLED_FONT_H "oled_font.h"
#    define OLED_FONT_END 223
#endif

/* Encoder Resolution setting */
#ifdef ENCODER_ENABLE
#    ifdef ENCODER_CUSTOM_RESOLUTION
#        ifdef ENCODER_RESOLUTION
#            undef ENCODER_RESOLUTION
#        endif
#        define ENCODER_RESOLUTION ENCODER_CUSTOM_RESOLUTION
#    endif
#endif

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
#define QMK_KEYS_PER_SCAN 4

#define TAP_CODE_DELAY 5

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
#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
#define TAPPING_FORCE_HOLD_PER_KEY

/* Space saving option */
#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE
// #define NO_ACTION_ONESHOT 

/* Split keyboard setting */
#if defined(SPLIT_KEYBOARD)
#    define EE_HANDS
#    define SPLIT_LAYER_STATE_ENABLE
#    define SPLIT_LED_STATE_ENABLE
#    define SPLIT_MODS_ENABLE
#    ifdef WPM_ENABLE
#        define SPLIT_WPM_ENABLE
#    endif
#    ifdef OLED_ENABLE
#        ifndef SLAVE_OLED_MASTER_TRACKBALL
#            define SPLIT_OLED_ENABLE
#        endif
#    endif
#    ifdef CUSTOM_SPLIT_TRANSPORT_SYNC
#        define SPLIT_TRANSACTION_IDS_USER RPC_ID_USER_STATE_SYNC
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
#    define OLED_BRIGHTNESS 128
#    define OLED_FONT_H "features/oled_font.h"
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

/* Pimoroni Trackball */
/* Default configurations
 *
 * #define PIMORONI_TRACKBALL_INTERVAL_MS 8       // change update rate for trackball, from testing update rate seems to be limited to around 250. Updating more frequently will slow down the keyboard.
 * #define PIMORONI_TRACKBALL_SCALE 5             // 5 is default, I personally prefer 3 which feels a little smoother.
 * #define PIMORONI_TRACKBALL_DEBOUNCE_CYCLES 20  // number of cycles to stop motion after clicking. 20 x 8 (INTERVAL) so 160ms.
 * #define PIMORONI_TRACKBALL_ERROR_COUNT 10      // stops trying to read from the pimoroni after this many faults.
 */
#ifdef PIMORONI_TRACKBALL_ENABLE
#    define POINTING_DEVICE_ROTATION_90
#    define PIMORONI_TRACKBALL_SCALE 4
#    define PIMORONI_TRACKBALL_INTERVAL_MS 4
#endif

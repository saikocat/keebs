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

/* Function: encoder
 * -----------------
 * A rotary encoder is a device that you can twist to perform actions.
 * Some encoders can also be pushed, just like a button!
 * A rotary encoder twists clockwise and counter clockwise.
 * It lends itself to actions that you'd otherwise need to repeatedly press a button for,
 * and to actions that have both a forward and a reverse direction.
 *
 * Reference: https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
 */

#include "rotary_encoder.h"

/* Audio control */
void fn_rotary_audio_control(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

/* Scrolling */
void fn_rotary_scrolling(bool clockwise) {
    if (clockwise) {
        tap_code(KC_PGDOWN);
    } else {
        tap_code(KC_PGUP);
    }
}

/* Tabbing
 * -------
 * Moving through browser mimicing Control + Tab and Control + Shift + Tab
 */
void fn_rotary_tabbing(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_TAB));
    } else {
        tap_code16(S(C(KC_TAB)));
    }
}

/* History Scrubbing
 * -----------------
 * This will perform Control + Z when you turn the encoder clockwise,
 * and Control + Y when turning it counterclockwise.
 * With this, you can easily "scroll" through the history when editing a document.
 */
void fn_rotary_history_scrubbing(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_Y));
    } else {
        tap_code16(C(KC_Z));
    }
}

/* Scrolling Horizontally by Word
 * ------------------------------
 * This will perform Control + Right Arrow when you turn the encoder clockwise,
 * and Control + Left Arrow when turning it counterclockwise.
 * If you hold shift while turning the encoder, you'll be able to select words while the cursor moves!
 */
void fn_rotary_word_scrolling(bool clockwise) {
    if (clockwise) {
        tap_code16(C(KC_RGHT));
    } else {
        tap_code16(C(KC_LEFT));
    }
}

/* Scrolling Through Search Results
 * --------------------------------
 * Shortcuts to move to the next or previous result. F3 and Shift + F3.
 */
void fn_rotary_search_through_results(bool clockwise) {
    if (clockwise) {
        tap_code(KC_F3);
    } else {
        tap_code16(S(KC_F3));
    }
}

/* Window tabbing
 * --------------------------------
 * Like with tabs, you can also move through applications.
 * In Windows, you can do this with Alt + Tab and Alt + Shift + Tab.
 */
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

void fn_rotary_wins_tabbing(bool clockwise) {
    if (clockwise) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
    } else {
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
    }
}

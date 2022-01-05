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

#include "features/encoder.h"

encoder_mode_t encoder_left_mode;
encoder_mode_t encoder_right_mode;

void encoder_init_mode_user(void) {
    encoder_left_mode  = ENC_MODE_OS_APP_SWITCH;
    encoder_right_mode = ENC_MODE_PAGING;
}

/* Audio control */
void encoder_action_volume_control(bool clockwise) {
    if (clockwise) {
        tap_code(KC_VOLU);
    } else {
        tap_code(KC_VOLD);
    }
}

/* Scrolling */
void encoder_action_paging(bool clockwise) {
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
void encoder_action_browser_tab_nav(bool clockwise) {
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
void encoder_action_undo_redo(bool clockwise) {
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
void encoder_action_word_nav(bool clockwise) {
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
void encoder_action_incremental_search(bool clockwise) {
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
void encoder_action_os_app_switch_with_timer(bool clockwise, bool* is_alt_tab_active, uint16_t* alt_tab_timer) {
    if (!*is_alt_tab_active) {
        *is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    *alt_tab_timer = timer_read();

    if (clockwise) {
        tap_code16(KC_TAB);
    } else {
        tap_code16(S(KC_TAB));
    }
}

void encoder_action_horizontal_nav(bool clockwise) {
    if (clockwise) {
        tap_code(KC_RGHT);
    } else {
        tap_code(KC_LEFT);
    }
}

void encoder_action_vertical_nav(bool clockwise) {
    if (clockwise) {
        tap_code(KC_DOWN);
    } else {
        tap_code(KC_UP);
    }
}

void encoder_action_os_app_switch(bool clockwise) {
    extern bool     is_alt_tab_active;
    extern uint16_t alt_tab_timer;

    encoder_action_os_app_switch_with_timer(clockwise, &is_alt_tab_active, &alt_tab_timer);
}

const char* encoder_mode_stringify(encoder_mode_t mode) {
    switch (mode) {
        case ENC_MODE_VOLUME_CTRL:
            return PSTR("Volume       ");
        case ENC_MODE_WORD_NAV:
            return PSTR("Word Nav     ");
        case ENC_MODE_BROWSER_TAB_NAV:
            return PSTR("BrowserTabNav");
        case ENC_MODE_UNDO_REDO:
            return PSTR("Word Nav     ");
        case ENC_MODE_INCREMENTAL_SEARCH:
            return PSTR("Incr Search  ");
        case ENC_MODE_OS_APP_SWITCH:
            return PSTR("OS App Switch");
        case ENC_MODE_PAGING:
            return PSTR("PageUp/PageDn");
        case ENC_MODE_HORIZONTAL_NAV:
            return PSTR("HorizontalNav");
        case ENC_MODE_VERTICAL_NAV:
            return PSTR("Vertical Nav ");
        default:
            return PSTR("Undefined??? ");
    }
}

void encoder_action(encoder_mode_t mode, uint8_t clockwise) {
    switch (mode) {
        case ENC_MODE_VOLUME_CTRL:
            return encoder_action_volume_control(clockwise);
        case ENC_MODE_WORD_NAV:
            return encoder_action_word_nav(clockwise);
        case ENC_MODE_BROWSER_TAB_NAV:
            return encoder_action_browser_tab_nav(clockwise);
        case ENC_MODE_UNDO_REDO:
            return encoder_action_undo_redo(clockwise);
        case ENC_MODE_INCREMENTAL_SEARCH:
            return encoder_action_incremental_search(clockwise);
        case ENC_MODE_OS_APP_SWITCH:
            return encoder_action_os_app_switch(clockwise);
        case ENC_MODE_PAGING:
            return encoder_action_paging(clockwise);
        case ENC_MODE_HORIZONTAL_NAV:
            return encoder_action_horizontal_nav(clockwise);
        case ENC_MODE_VERTICAL_NAV:
            return encoder_action_vertical_nav(clockwise);
        default:
            return encoder_action_volume_control(clockwise);
    }
}

__attribute__((weak)) void matrix_scan_user_encoder(void) {}

__attribute__((weak)) bool process_record_user_encoder(uint16_t keycode, keyrecord_t* record) {
    // TODO: Probably can do a bitwise/bitshift here instead of 2 vars
    static bool sticky_mode  = false;
    static bool sticky_layer = false;

    switch (keycode) {
        case MO(_LOWER):
            if (record->event.pressed) {
                encoder_left_mode  = ENC_MODE_VOLUME_CTRL;
                encoder_right_mode = ENC_MODE_UNDO_REDO;
                sticky_mode        = true;
            } else {
                sticky_mode = sticky_layer ? true : false;
            }
            break;
        case MO(_RAISE):
            if (record->event.pressed) {
                encoder_left_mode  = ENC_MODE_BROWSER_TAB_NAV;
                encoder_right_mode = ENC_MODE_HORIZONTAL_NAV;
                sticky_mode        = true;
            } else {
                sticky_mode = sticky_layer ? true : false;
            }
            break;
        case DF(_NAVIGATION):
            encoder_left_mode  = ENC_MODE_VERTICAL_NAV;
            encoder_right_mode = ENC_MODE_HORIZONTAL_NAV;
            sticky_mode        = true;
            sticky_layer       = true;
            break;
        case DF(_QWERTY):
        case DF(_COLEMAK_DH):
            sticky_mode  = false;
            sticky_layer = false;
            break;
    }

    // If momentary layer is activated, we reset to default mode
    if (!sticky_mode) {
        encoder_left_mode  = ENC_MODE_OS_APP_SWITCH;
        encoder_right_mode = ENC_MODE_PAGING;
    }
    return true;
}

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {
    if (index == 0) {
        encoder_action(encoder_left_mode, clockwise);
    } else if (index == 1) {
        encoder_action(encoder_right_mode, clockwise);
    }

#ifdef OLED_ENABLE
#    include "features/oled.h"
    oled_force_on();
#endif

    return false;
}

/* User defined func that will be called by QMK every time encoder is turned */
__attribute__((weak)) bool encoder_update_user(uint8_t index, bool clockwise) { return encoder_update_keymap(index, clockwise); }

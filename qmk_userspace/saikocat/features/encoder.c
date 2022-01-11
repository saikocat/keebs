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
void encoder_action_os_app_switch_with_timer(bool clockwise, bool *is_alt_tab_active, uint16_t *alt_tab_timer) {
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

void encoder_action_noop(bool clockwise) {}

// Why we need these bunch of const for PROGMEM
// https://stackoverflow.com/a/59089877
// https://arduino-esp8266.readthedocs.io/en/latest/PROGMEM.html
// https://deskthority.net/viewtopic.php?f=2&t=24718
const char PROGMEM encoder_mode_name_00[] = "Volume       ";
const char PROGMEM encoder_mode_name_01[] = "PageUp/PageDn";
const char PROGMEM encoder_mode_name_02[] = "BrowserTabNav";
// const char PROGMEM encoder_mode_name_03[] = "Word Nav     ";
const char PROGMEM encoder_mode_name_04[] = "Undo/Redo    ";
// const char PROGMEM encoder_mode_name_05[] = "Incr Search  ";
const char PROGMEM encoder_mode_name_06[] = "OS App Switch";
const char PROGMEM encoder_mode_name_07[] = "HorizontalNav";
const char PROGMEM encoder_mode_name_08[] = "Vertical Nav ";

const char PROGMEM encoder_mode_name_undefined[] = "Undefined??? ";

typedef void (*EncoderAction)(bool clockwise);

static struct EncoderHandler {
    uint8_t       mode;
    const char   *name;
    EncoderAction action;
} encoder_handler_table[] = {
    // A bit brittle as we have to manually update,
    // but lazy for a codegen solution for now, or a for loop check handling in get_handler func
    // clang-format off
    { ENC_MODE_VOLUME_CTRL,        encoder_mode_name_00,    encoder_action_volume_control },
    { ENC_MODE_PAGING,             encoder_mode_name_01,    encoder_action_paging },
    { ENC_MODE_BROWSER_TAB_NAV,    encoder_mode_name_02,    encoder_action_browser_tab_nav },
    // { ENC_MODE_WORD_NAV,           encoder_mode_name_03,    encoder_action_word_nav },
    { ENC_MODE_UNDO_REDO,          encoder_mode_name_04,    encoder_action_undo_redo },
    // { ENC_MODE_INCREMENTAL_SEARCH, encoder_mode_name_05,    encoder_action_incremental_search },
    { ENC_MODE_OS_APP_SWITCH,      encoder_mode_name_06,    encoder_action_os_app_switch },
    { ENC_MODE_HORIZONTAL_NAV,     encoder_mode_name_07,    encoder_action_horizontal_nav },
    { ENC_MODE_VERTICAL_NAV,       encoder_mode_name_08,    encoder_action_vertical_nav },
    // clang-format on
};

static struct EncoderHandler encoder_default_handler = {ENC_MODE_NOOP, encoder_mode_name_undefined, encoder_action_noop};

struct EncoderHandler encoder_get_handler_or_default(encoder_mode_t mode) {
    size_t i;
    for (i = 0; i < sizeof(encoder_handler_table); i++) {
        if (encoder_handler_table[i].mode == mode) {
            return encoder_handler_table[i];
        }
    }

    return encoder_default_handler;

    // clang-format off
    // return (mode < _ENC_MODE_LAST)
    //     ? encoder_handler_table[mode]
    //     : encoder_default_handler;
    // clang-format on
}

const char *PROGMEM encoder_mode_stringify(encoder_mode_t mode) { return encoder_get_handler_or_default(mode).name; }

__attribute__((weak)) void matrix_scan_user_encoder(void) {}

__attribute__((weak)) layer_state_t layer_state_set_encoder(layer_state_t state) {
    switch (get_highest_layer(state | default_layer_state)) {
        case _LOWER:
            encoder_left_mode  = ENC_MODE_UNDO_REDO;
            encoder_right_mode = ENC_MODE_VOLUME_CTRL;
            break;
        case _RAISE:
            encoder_left_mode  = ENC_MODE_VERTICAL_NAV;
            encoder_right_mode = ENC_MODE_HORIZONTAL_NAV;
            break;
        default:
            encoder_left_mode  = ENC_MODE_OS_APP_SWITCH;
            encoder_right_mode = ENC_MODE_PAGING;
    }
    return state;
}

__attribute__((weak)) bool encoder_update_keymap(uint8_t index, bool clockwise) {
    if (index == 0) {
        // encoder_action(encoder_left_mode, clockwise);
        encoder_get_handler_or_default(encoder_left_mode).action(clockwise);
    } else if (index == 1) {
        // encoder_action(encoder_right_mode, clockwise);
        encoder_get_handler_or_default(encoder_right_mode).action(clockwise);
    }

#ifdef OLED_ENABLE
#    include "features/oled.h"
    oled_force_on();
#endif

    return false;
}

/* User defined func that will be called by QMK every time encoder is turned */
__attribute__((weak)) bool encoder_update_user(uint8_t index, bool clockwise) { return encoder_update_keymap(index, clockwise); }

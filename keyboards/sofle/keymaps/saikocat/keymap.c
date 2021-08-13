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

#include QMK_KEYBOARD_H

enum layer_number {
    _BASE = 0,
    _LOWER,
    _RAISE,
    _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_BASE]   = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, KC_NO, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_LGUI, KC_ENT, LALT_T(KC_GRV), LT(1,KC_BSPC), KC_SPC, KC_SPC, LT(2,KC_ENT), RCTL_T(KC_DEL), KC_RALT, KC_RGUI),
    [_LOWER]  = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_TRNS, KC_EXLM, KC_DLR, KC_LCBR, KC_RCBR, KC_PIPE, KC_CIRC, KC_MINS, KC_MINS, KC_MINS, KC_BSLS, KC_TRNS, KC_TRNS, KC_AT, KC_PERC, KC_LPRN, KC_RPRN, KC_GRV, KC_AMPR, KC_PLUS, KC_EQL, KC_UNDS, KC_COLN, KC_DQUO, KC_TRNS, KC_HASH, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS, KC_NO, KC_ASTR, KC_EQL, KC_LT, KC_GT, KC_QUES, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_ENT, KC_BSPC, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_RAISE]  = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, DF(0), KC_INS, KC_F12, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_HOME, KC_PGDN, KC_PGUP, KC_END, DF(2), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_BSPC, KC_ENT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
    [_ADJUST] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_TRNS, KC_TRNS, RESET, EEP_RST, KC_TRNS, KC_TRNS, KC_CAPS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12, DF(0), KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS)
    // clang-format on

    /*
     * [Layer Template]
     * ,-----------------------------------------.                    ,-----------------------------------------.
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
     * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
     * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
     * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
     * `-----------------------------------------/       /     \      \-----------------------------------------'
     *            |      |      |      |      | /       /       \      \  |      |      |      |      |
     *            |      |      |      |      |/       /         \      \ |      |      |      |      |
     *            `----------------------------------'           '------''---------------------------'
     */
};

/* Hold _LOWER and _RAISE set to _ADJUST */
layer_state_t layer_state_set_user(layer_state_t state) { return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST); }

/* Function: Bit-C microcontroller specific
 * ----------------------------------------
 * Just turn off OLED for the keyboard for now when CapsLock is not on
 * NOTE: Only work with Master, splitkb is not supported yet.
 */

#ifdef HW_BITC

#    include "features/bitc_led.h"

// Use Bit-C LED to show CAPS LOCK status
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        set_bitc_LED(led_state.caps_lock ? LED_DIM : LED_OFF);
    }
    return res;
}

#endif

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

#ifdef ENCODER_ENABLE

#    include "features/rotary_encoder.h"

/* User defined func that will be called by QMK every time encoder is turned */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        fn_rotary_wins_tabbing(clockwise);
    } else if (index == 1) {
        fn_rotary_scrolling(clockwise);
    }
    return true;
}

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) { /* 1250ms hold wait */
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#endif

#ifdef OLED_DRIVER_ENABLE

#    include "features/keystats.h"
#    include "features/pet_neko.h"

/* Function: Logos
 * ---------------
 */
static void render_logo(void) {
    // clang-format off
    /* 32x32 'awake' logo */
    static const char PROGMEM my_logo[] = {
        0x00, 0x40, 0x40, 0x80, 0x80, 0x04, 0x08, 0x10, 0x20, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80,
        0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x10, 0x08, 0x04, 0x80, 0x80, 0x40, 0x40, 0x00,
        0x08, 0x08, 0x08, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40, 0x5c, 0x00, 0x01,
        0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x01, 0x01, 0x08, 0x08, 0x08, 0x08, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x00,
        0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x90, 0x48, 0x64, 0x92, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18,
        0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x18, 0x00, 0x00, 0x00, 0x00,
    };
    // clang-format on

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

// clang-format off
/* 32 * 32 os logos */
static const char PROGMEM archlinux_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe,
    0xfe, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf9, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x07, 0x07,
    0x07, 0x07, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0x78, 0x3c, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x3c, 0x3c, 0x78, 0x60, 0x00
};
// clang-format on

/* Function: Display
 * -----------------
 */
static void display_logo_narrow(void) {
    render_logo();

    oled_set_cursor(0, 7);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR(" GIT "), false);
    oled_write_P(PSTR(" GUD!"), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("\n"), false);

    oled_set_cursor(0, 14);
    /* wpm counter */
    // uint8_t n = get_current_wpm();
    uint8_t n = current_wpm;
    char    wpm_str[4];
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);
    oled_set_cursor(0, 15);
    oled_write_P(PSTR(" wpm"), false);
}

static void display_status_narrow(void) {
    /* Display current mode */
    oled_set_cursor(0, 0);
    oled_write_raw_P(archlinux_logo, sizeof(archlinux_logo));

    oled_set_cursor(0, 5);

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("NAVIG"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_set_cursor(0, 7);

    /* Display current layer */
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(0, 8);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Symbl"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    /* Caps lock */
    oled_set_cursor(0, 10);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    /* Pet rendering */
    pet_render(0, 12);
}

/* QMK rendering starts here
 * -------------------------
 */

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void oled_task_user(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) {
        display_status_narrow();
    } else {
        display_logo_narrow();
    }
}

/* Turn off oled when computer is sleeping */
void suspend_power_down_user(void) { oled_off(); }

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_DRIVER_ENABLE
    pet_handle_keycode(keycode, record);
#endif

    return true;
}

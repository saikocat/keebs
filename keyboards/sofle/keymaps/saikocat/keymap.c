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
  _SYMBOLS,
  _NAVUTIL,
  _ADJUST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSLS, KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_MUTE, XXXXXXX, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, KC_LGUI, KC_ENT, LALT_T(KC_GRV), LT(1,KC_BSPC), KC_SPC, KC_SPC, LT(2,KC_ENT), RCTL_T(KC_DEL), KC_RALT, KC_RGUI),
    [_SYMBOLS] = LAYOUT(KC_F12, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_GRV, KC_EQL, KC_LCBR, KC_RCBR, KC_MINS, KC_PIPE, _______, KC_MINS, KC_MINS, KC_MINS, KC_PLUS, _______, KC_TILD, KC_LBRC, KC_9, KC_0, KC_RBRC, KC_BSLS, KC_ASTR, KC_PLUS, KC_EQL, KC_UNDS, KC_COLN, KC_DQUO, _______, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, _______, XXXXXXX, KC_CIRC, KC_AMPR, KC_LT, KC_GT, KC_QUES, _______, _______, _______, _______, _______, KC_ENT, KC_BSPC, _______, _______, _______, _______),
    [_NAVUTIL] = LAYOUT(KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS, _______, RESET, _______, _______, _______, _______, LCTL(KC_LEFT), LCTL(KC_BSPC), _______, LCTL(KC_RGHT), KC_PSCR, KC_DEL, _______, _______, _______, _______, _______, KC_CAPS, KC_LEFT, KC_DOWN, KC_UP, KC_RGHT, DF(0), _______, _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END, DF(2), _______, _______, _______, _______, _______, KC_BSPC, KC_ENT, _______, KC_GRV, _______, _______),
    [_ADJUST] = LAYOUT(_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______)
};


/* Function: Bit-C microcontroller specific
 * ----------------------------------------
 * Just turn off OLED for the keyboard for now when CapsLock is not on
 * NOTE: Only work with Master, splitkb is not supported yet.
 */

#ifdef HW_BITC

#include "bitc_led.h"

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

/* User defined func that will be called by QMK every time encoder is turned */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        fn_rotary_audio_control(clockwise);
    } else if (index == 1) {
        fn_rotary_scrolling(clockwise);
    }
    return true;
}

#endif


#ifdef OLED_DRIVER_ENABLE

/* Function: Logos
 * ---------------
 */
static void render_logo(void) {
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

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

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

/* Function: Neko Pet Animation
 * ----------------------------
 * - Keyboard Pets react to your wpm counter:
 *    under 10 wpm they sit
 *    between 10 and 40 wpm they will walk
 *    over 40 wpm they run
 * - They will move sneakily if you hold down Ctrl
 * - Will react if you activate Caps Lock!
 * - TODO: Jump every time you hit the space bar
 *
 * Immense thanks to /u/HellSingCoder existing implementation of Luna
 * and /u/whateverworks325 for sprites and idea.
 *
 * - Generalize animation naming
 * - Fix flickering on my OLED when oled's off interfere with animations
 */

/* WPM-responsive animation settings here */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 40

/* Animation settings */
#define ANIM_FRAME_DURATION 200 /* how long each frame lasts in ms */
#define ANIM_SIZE 128           /* number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024 */
#define ANIM_FRAMES 2

/* timers */
uint32_t anim_timer = 0;
uint32_t anim_sleep = 0;

/* current frame */
uint8_t current_frame = 0;

/* status variables */
int current_wpm = 0;
led_t led_usb_state;
/* bool current_oled_on = true; */

bool is_sneaking = false;
/* TODO: jump is causing artifact
bool is_jumping = false;
bool showed_jump = true;
*/

/* logic */
static void render_pet(int PET_X, int PET_Y) {

    /* Idle  */
    static const char PROGMEM idle[ANIM_FRAMES][ANIM_SIZE] = {
        /* 'sleep1', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x08, 0xa8, 0x48, 0xa8, 0x18, 0x08, 0x00, 0x00, 0x00,
            0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x03, 0x02, 0x02, 0x02, 0x02, 0x02, 0x00, 0x00, 0x80,
            0x44, 0x84, 0x06, 0x05, 0x04, 0x80, 0x40, 0x20, 0x10, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x20, 0x18, 0x04, 0x04, 0x02, 0x7a, 0x86, 0x01, 0x80,
            0x80, 0x01, 0x03, 0x05, 0x07, 0x01, 0x00, 0x00, 0x80, 0x83, 0x45, 0xfa, 0x3c, 0xe0, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x31, 0x22, 0x24,
            0x28, 0x29, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00,
        },

        /* 'sleep2', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x22, 0x22, 0x3a, 0x2a, 0x26, 0x22, 0x80, 0xc0,
            0x80, 0x00, 0x24, 0x34, 0x2c, 0xe4, 0x60, 0x10, 0x70, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0x38, 0x04, 0x02, 0x02, 0x01, 0x79, 0x87, 0x01, 0x80,
            0x81, 0x83, 0x05, 0x05, 0x03, 0x01, 0x00, 0x00, 0x80, 0x43, 0x05, 0xfa, 0x3c, 0xe0, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x08, 0x10, 0x10, 0x10, 0x10, 0x10, 0x31, 0x22, 0x24,
            0x28, 0x28, 0x29, 0x29, 0x3a, 0x18, 0x1c, 0x39, 0x24, 0x24, 0x3a, 0x2d, 0x26, 0x31, 0x1f, 0x00,
        }
    };

    /* Walk */
    static const char PROGMEM walk[ANIM_FRAMES][ANIM_SIZE] = {
        /* 'rtogi1', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x0f, 0x90, 0x10, 0x20, 0xf0, 0xf8, 0xf8,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08,
            0x48, 0x47, 0x88, 0x00, 0x00, 0x00, 0x00, 0x00, 0x08, 0x88, 0xc7, 0xc4, 0x62, 0x23, 0x10, 0x3f,
            0x80, 0x40, 0x20, 0x10, 0x88, 0xcc, 0x43, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0,
            0x80, 0x80, 0xc0, 0xe1, 0xbe, 0x98, 0x88, 0x0c, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x06, 0x04, 0x04, 0x04, 0x04,
            0x05, 0x04, 0x04, 0x04, 0x07, 0x07, 0x04, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'rtogi2', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0xc0, 0x20, 0x10, 0x10, 0x08, 0x04, 0x02, 0x01, 0x1f, 0xa0, 0x20, 0x40, 0x80, 0x00, 0xf0,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x20, 0x10, 0x10, 0x08, 0x08, 0x08, 0x08,
            0x48, 0x47, 0x88, 0x00, 0x00, 0x00, 0x00, 0x24, 0x24, 0x28, 0x6b, 0x40, 0xa0, 0x99, 0x86, 0xff,
            0x0f, 0x11, 0x22, 0x44, 0x48, 0x4c, 0x43, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0,
            0x80, 0x80, 0xc0, 0xe1, 0xbe, 0x98, 0x88, 0x0c, 0x04, 0x06, 0x06, 0x06, 0x0a, 0x0a, 0x06, 0x01,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x01, 0x06, 0x04, 0x04, 0x04, 0x04,
            0x05, 0x04, 0x04, 0x04, 0x07, 0x04, 0x07, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* Run */
    static const char PROGMEM run[ANIM_FRAMES][ANIM_SIZE] = {
        /* 'dwright1', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x10, 0x28, 0xa8, 0xe8, 0x64, 0x64, 0x24, 0x28, 0x08, 0x18, 0x10, 0x10,
            0x10, 0x10, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x3f, 0xc1, 0x00, 0x00, 0x00, 0x00, 0x04, 0x08, 0xf0, 0x00, 0x00,
            0x00, 0xe0, 0x10, 0x08, 0x06, 0x03, 0x81, 0x0f, 0x08, 0x04, 0x82, 0x01, 0x7f, 0x80, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0x10, 0x60, 0x80, 0x00, 0x30, 0xce, 0x01, 0xc0, 0x30,
            0x02, 0x03, 0x22, 0xc2, 0x40, 0x40, 0x43, 0x40, 0x40, 0xe0, 0x2b, 0x40, 0x20, 0x1f, 0x02, 0x02,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x06, 0x0c, 0x09, 0x0f, 0x04, 0x04,
            0x06, 0x02, 0x03, 0x02, 0x04, 0x04, 0x02, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'dwright2', 32x32px */
        {
            0x00, 0x20, 0x50, 0x50, 0x50, 0x90, 0x10, 0x20, 0x40, 0x90, 0xa8, 0xa8, 0x68, 0x08, 0x88, 0x48,
            0x38, 0x90, 0xd0, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0x20, 0x40, 0x80, 0x00, 0x00, 0x01, 0x01, 0x01, 0x00, 0x00,
            0x01, 0x80, 0x40, 0x41, 0x22, 0x1c, 0x08, 0x04, 0x1c, 0x30, 0xe0, 0x10, 0x10, 0x88, 0x78, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x02, 0x0c, 0x30, 0x40, 0x80,
            0x20, 0x4b, 0x88, 0x88, 0x10, 0x00, 0x00, 0x38, 0x00, 0x00, 0x80, 0x38, 0x80, 0xff, 0x10, 0x08,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x01, 0x02, 0x0c, 0x10, 0x21, 0x21, 0x3f, 0x03, 0x02, 0x06, 0x1a, 0x21, 0x23, 0x1c, 0x00, 0x00,
        }
    };

    /* Annoy */
    static const char PROGMEM annoy[ANIM_FRAMES][ANIM_SIZE] = {
        /* 'kaki1', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x10, 0x20, 0x20, 0x40, 0x40, 0x80,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x06, 0x1a, 0x22, 0xc2, 0x04, 0x04, 0x04, 0x07, 0x00, 0xc0, 0x20, 0x10, 0x80, 0x80,
            0x01, 0x01, 0x02, 0xfc, 0xfe, 0x02, 0x3c, 0x20, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x09, 0x08, 0x00,
            0x80, 0x00, 0x06, 0x09, 0x1b, 0xee, 0x00, 0x00, 0x00, 0x00, 0x81, 0xfe, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18,
            0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x16, 0x15, 0x14, 0x14, 0x14, 0x14, 0x08,
        },

        /* 'kaki2', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x10, 0x20, 0x40,
            0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x01, 0x02, 0x04, 0x04, 0x03, 0x80, 0x40, 0x40, 0x20,
            0x00, 0x01, 0x02, 0x8c, 0x70, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x0d, 0x8d, 0x55, 0x50, 0x94, 0xf0, 0x10, 0x0a, 0x0e, 0x1d,
            0x95, 0x24, 0x24, 0x27, 0x13, 0xe1, 0x01, 0x01, 0x01, 0x01, 0x02, 0xfc, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18,
            0x0f, 0x18, 0x10, 0x10, 0x1f, 0x19, 0x18, 0x1c, 0x14, 0x14, 0x17, 0x14, 0x14, 0x14, 0x14, 0x08,
        }
    };

    /* Sneak */
    static const char PROGMEM sneak[ANIM_FRAMES][ANIM_SIZE] = {
        /* 'down1', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x40, 0x7e, 0x01,
            0x01, 0x7e, 0x40, 0x40, 0x40, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xe0, 0x1c, 0x02, 0x01, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80,
            0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc1, 0x02, 0x04, 0x18, 0xe0, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x74, 0x4f, 0xe8, 0x30, 0x7f, 0x80, 0x00, 0x00, 0x70, 0x00, 0x01,
            0x81, 0x01, 0x00, 0x70, 0x00, 0x00, 0x80, 0x7f, 0x30, 0xe8, 0x4f, 0x74, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03, 0x02, 0x02, 0x06, 0x04,
            0x04, 0x04, 0x06, 0x02, 0x02, 0x03, 0x03, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        },

        /* 'down2', 32x32px */
        {
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf0, 0x0e, 0x01, 0x03, 0x0e, 0x30, 0x3e, 0x01,
            0x01, 0x3e, 0x20, 0x10, 0x0e, 0x03, 0x01, 0x0e, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf3, 0x0c, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80,
            0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x0c, 0xf3, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x04, 0x04, 0x08, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x70, 0x00, 0x01,
            0x81, 0x01, 0x00, 0x70, 0x00, 0x00, 0x80, 0xff, 0x3f, 0x08, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,
            0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x38, 0x41, 0x62, 0x3a, 0x06, 0x04,
            0x04, 0x04, 0x06, 0x3a, 0x62, 0x41, 0x38, 0x07, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        }
    };

    /* animation */
    void animate_pet(void) {

        /* TODO: jump is causing artifact
        // / jump /
        // if (is_jumping || !showed_jump) {
        //     / clear /
        //     oled_set_cursor(PET_X, PET_Y);
        //     oled_write("    ", false);
        //
        //     oled_set_cursor(PET_X, PET_Y-1);
        //     showed_jump = true;
        // } else {
        //     / clear /
        //     oled_set_cursor(PET_X, PET_Y-1);
        //     oled_write("    ", false);
        //
        //     oled_set_cursor(PET_X, PET_Y);
        // }
        */
        oled_set_cursor(PET_X, PET_Y);

        /* switch frame */
        current_frame = (current_frame + 1) % 2;

        /* current status */
        if(led_usb_state.caps_lock) {
            oled_write_raw_P(annoy[abs(1 - current_frame)], ANIM_SIZE);
        } else if(is_sneaking) {
            oled_write_raw_P(sneak[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_WALK_SPEED) {
            oled_write_raw_P(idle[abs(1 - current_frame)], ANIM_SIZE);
        } else if(current_wpm <= MIN_RUN_SPEED) {
            oled_write_raw_P(walk[abs(1 - current_frame)], ANIM_SIZE);
        } else {
            oled_write_raw_P(run[abs(1 - current_frame)], ANIM_SIZE);
        }
    }

    if(get_current_wpm() != 000) {
        oled_on();
        if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
            anim_timer = timer_read32();
            animate_pet();
        }
        anim_sleep = timer_read32();
    } else {
        if(timer_elapsed32(anim_sleep) > OLED_TIMEOUT) {
            oled_off();
        } else {
            if(timer_elapsed32(anim_timer) > ANIM_FRAME_DURATION) {
                anim_timer = timer_read32();
                animate_pet();
            }
        }
    }
}

/* modularize so easier to copy and paste */
void handle_keycode(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_LCTL:
        case KC_RCTL:
            if (record->event.pressed) {
                is_sneaking = true;
            } else {
                is_sneaking = false;
            }
            break;
        /* TODO: jump is causing artifact
        case KC_SPC:
            if (record->event.pressed) {
                is_jumping = true;
                showed_jump = false;
            } else {
                is_jumping = false;
            }
            break;
        */
    }
}

/* End Function: Neko Pet Animation */

/* Function: Display
 * -----------------
 */
static void display_logo_narrow(void) {
    render_logo();

    oled_set_cursor(0,7);
    oled_write("GIT", false);
    oled_set_cursor(0,8);
    oled_write("GUD!", false);

    /* wpm counter */
    uint8_t n = get_current_wpm();
    char wpm_str[4];
    oled_set_cursor(0,14);
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + ( n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);

    oled_set_cursor(0,15);
    oled_write(" wpm", false);
}

static void display_status_narrow(void) {
    /* Display current mode */
    oled_set_cursor(0,0);
    oled_write_raw_P(archlinux_logo, sizeof(archlinux_logo));

    oled_set_cursor(0,5);

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write("QWERT", false);
            break;
        case _NAVUTIL:
            oled_write("NAV  ", false);
            break;
        default:
            oled_write("UNDEF", false);
    }

    oled_set_cursor(0,7);

    /* Display current layer */
    oled_write("LAYER", false);

    oled_set_cursor(0,8);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write("Base ", false);
            break;
        case _SYMBOLS:
            oled_write("Symbl", false);
            break;
        case _NAVUTIL:
            oled_write("Nav  ", false);
            break;
        case _ADJUST:
            oled_write("Adj  ", false);
            break;
        default:
            oled_write("Undef", false);
    }

    /* Caps lock */
    oled_set_cursor(0,10);
    oled_write("CPSLK", led_usb_state.caps_lock);

    /* Pet rendering */
    render_pet(0,12);
}


/* QMK rendering starts here
 * -------------------------
 */

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    return OLED_ROTATION_270;
}

void oled_task_user(void) {
    current_wpm = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) {
        display_status_narrow();
    } else {
        display_logo_narrow();
    }
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    #ifdef OLED_DRIVER_ENABLE

    handle_keycode(keycode, record);

    #endif

    return true;
}

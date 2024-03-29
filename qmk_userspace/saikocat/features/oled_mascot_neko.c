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

/* For customization of desired sprites and sources
 *
 * - https://en.wikipedia.org/wiki/Neko_(software)
 * - http://www.daidouji.com/oneko/
 * - https://github.com/tie/oneko/tree/master/bitmaps
 * - https://javl.github.io/image2cpp/
 */

#include "quantum.h"

#include "features/oled_mascot.h"

/* Animation settings */
#define NEKO_FRAMES 2
#define NEKO_FRAME_DURATION 200 /* how long each frame lasts in ms */
#define NEKO_SIZE 128           /* number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024 */

// clang-format off
/* Sleep  */
static const char PROGMEM sleep[NEKO_FRAMES][NEKO_SIZE] = {
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
// clang-format on

// clang-format off
/* Walk */
static const char PROGMEM walk[NEKO_FRAMES][NEKO_SIZE] = {
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
// clang-format on

// clang-format off
/* Run */
static const char PROGMEM run[NEKO_FRAMES][NEKO_SIZE] = {
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
// clang-format on

// clang-format off
/* Sneak */
static const char PROGMEM sneak[NEKO_FRAMES][NEKO_SIZE] = {
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
// clang-format on

/* (Head) Scratch is different from the Claw animation against the wall btw :) */
// clang-format off
/* Scratch */
static const char PROGMEM scratch[NEKO_FRAMES][NEKO_SIZE] = {
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
// clang-format on

static void mascot_action(char const action[][NEKO_SIZE]) {
    static uint8_t current_frame = 0;
    current_frame                = (current_frame + 1) & 1;
    oled_write_raw_P(action[current_frame], NEKO_SIZE);
}

/* Impl render interface */
void oled_render_mascot_status(void) {
    /* Animation frame timer */
    static uint16_t anim_timer = 0;

#ifdef WPM_ENABLE
    static uint8_t  prev_wpm        = 0;
    static uint32_t oled_idle_timer = 0;
    /* Idle timer updated by sustained WPM */
    if (get_current_wpm() > prev_wpm || get_mods()) {
        oled_idle_timer = timer_read32();
    }
    prev_wpm = get_current_wpm();
#else
    /* oled_idle_timer updated by key presses in process_record_user() */
    extern uint32_t oled_idle_timer;
#endif

    /* Time gap between tap timer updates */
    uint32_t tap_interval = timer_elapsed32(oled_idle_timer);

    void animation_phase(void) {
        if (get_mods() & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock) {
            mascot_action(scratch);
        } else if (get_mods() & MOD_MASK_CAG) {
            mascot_action(sneak);
        } else if (tap_interval < NEKO_FRAME_DURATION * 4) {
            mascot_action(run);
        } else if (tap_interval < NEKO_FRAME_DURATION * 16) {
            mascot_action(walk);
        } else {
            mascot_action(sleep);
        }
    }

    /* Extra handling in standalone user case & when user prefers not to use OLED_DISABLE_TIMEOUT */
    if ((OLED_TIMEOUT > 0) && (tap_interval > OLED_TIMEOUT)) {
        oled_off();
        return;
    }

    if (timer_elapsed(anim_timer) > NEKO_FRAME_DURATION) {
        anim_timer = timer_read();
        animation_phase();
    }
}

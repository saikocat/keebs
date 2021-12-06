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

#include "sync_timer.h"

#include "definitions.h"
#include "features/oled.h"
#include "features/oled_mascot.h"

#define OLED_IDLE_THRESHOLD 60000U
/* keystroke/tap gap timer */
uint32_t oled_idle_timer = 0;

bool process_record_user_oled(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        /* keystroke/tap gap timer update */
        oled_idle_timer = sync_timer_read32();
#endif
    }
    return true;
}

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) { return OLED_ROTATION_270; }

#ifdef SWAP_HANDS_ENABLE
extern bool swap_hands;
#endif

void oled_render_logo(void) {
    // clang-format off
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,0
    };
    // clang-format on
    oled_write_P(logo, false);
}

void oled_render_layer_state(uint8_t const state) {
    // clang-format off
    /* 3x3 logo, 1x1 left-right padding = 5x3 space = 30x24px */
    /* order: middle, top, bottom, interlaced */
    static const char PROGMEM layers[4][16] = {
        {
            0x20, 0x94, 0x95, 0x96, 0x20,
            0x20, 0xb4, 0xb5, 0xb6, 0x20,
            0x20, 0xd4, 0xd5, 0xd6, 0x20, 0
        },
        {
            0x20, 0x9a, 0x9b, 0x9c, 0x20,
            0x20, 0xba, 0xbb, 0xbc, 0x20,
            0x20, 0xda, 0xdb, 0xdc, 0x20, 0
        },
        {
            0x20, 0x97, 0x98, 0x99, 0x20,
            0x20, 0xb7, 0xb8, 0xb9, 0x20,
            0x20, 0xd7, 0xd8, 0xd9, 0x20, 0
        },
        {
            0x20, 0x9d, 0x9e, 0x9f, 0x20,
            0x20, 0xbd, 0xbe, 0xbf, 0x20,
            0x20, 0xdd, 0xde, 0xdf, 0x20, 0 
        },
    };
    // clang-format on

    switch (state) {
        case _LOWER:
            oled_write_P(layers[1], false);
            break;
        case _RAISE:
            oled_write_P(layers[2], false);
            break;
        case _ADJUST:
        case _SPECIAL:
            oled_write_P(layers[3], false);
            break;
        default:
            oled_write_P(layers[0], false);
    }
}

enum sprite_position {
    _SP_LEFT   = 0,
    _SP_RIGHT  = 1,
    _SP_OFF    = 0,
    _SP_ON     = 1,
    _SP_TOP    = 0,
    _SP_BOTTOM = 1,
};

// clang-format off
/* 
 * left: 0, right : 1
 * off : 0, on    : 1
 * top : 0, bottom: 1
 */
static char const PROGMEM sprite_font_mod_status_gui_alt[2][2][2][3] = {
    {
        {{0x85, 0x86, 0}, {0xa5, 0xa6, 0}},
        {{0x8d, 0x8e, 0}, {0xad, 0xae, 0}},
    },
    {
        {{0x87, 0x88, 0}, {0xa7, 0xa8, 0}},
        {{0x8f, 0x90, 0}, {0xaf, 0xb0, 0}},
    },
};

static char const PROGMEM sprite_font_mod_status_ctl_shift[2][2][2][3] = {
    {
        {{0x89, 0x8a, 0}, {0xa9, 0xaa, 0}},
        {{0x91, 0x92, 0}, {0xb1, 0xb2, 0}},
    },
    {
        {{0x8b, 0x8c, 0}, {0xab, 0xac, 0}},
        {{0xcd, 0xce, 0}, {0xcf, 0xd0, 0}},
    },
};

/* Borders sprite from font
 *
 * 4 permutations - so we use binary bitshift combination to int index
 *  0 0
 *  0 1
 *  1 0 
 *  1 1
 *  
 * 2 sprites for top and bottom
 */
static char const PROGMEM sprite_font_mod_status_borders[4][2][2] = {
    {{0xc5, 0}, {0xc6, 0}},
    {{0xc9, 0}, {0xca, 0}},
    {{0xc7, 0}, {0xc8, 0}},
    {{0xcb, 0}, {0xcc, 0}},
};
// clang-format on

static void oled_render_mod_status_helper(uint8_t const left_mod, uint8_t const right_mod, char const sprite[2][2][2][3]) {
    uint8_t left_state  = left_mod ? 1 : 0;
    uint8_t right_state = right_mod ? 1 : 0;
    uint8_t border_idx  = (left_state << 1) | right_state;

    /* Top half and border padding */
    oled_write_P(sprite[_SP_LEFT][left_state][_SP_TOP], false);
    oled_write_P(sprite_font_mod_status_borders[border_idx][_SP_TOP], false);
    oled_write_P(sprite[_SP_RIGHT][right_state][_SP_TOP], false);

    /* Bottom half and border padding */
    oled_write_P(sprite[_SP_LEFT][left_state][_SP_BOTTOM], false);
    oled_write_P(sprite_font_mod_status_borders[border_idx][_SP_BOTTOM], false);
    oled_write_P(sprite[_SP_RIGHT][right_state][_SP_BOTTOM], false);
}

// Primary modifier status display function
void oled_render_mod_status(uint8_t modifiers) {
    // clang-format off
    oled_render_mod_status_helper(
        modifiers & MOD_MASK_GUI,
        modifiers & MOD_MASK_ALT,
        sprite_font_mod_status_gui_alt);
    //render_gui_alt(modifiers & MOD_MASK_GUI, modifiers & MOD_MASK_ALT);
    oled_render_mod_status_helper(
        modifiers & MOD_MASK_CTRL,
        modifiers & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock, 
        sprite_font_mod_status_ctl_shift);
    // clang-format on
}

void oled_render_blink_prompt(void) {
    /* TODO: make this more D.R.Y */
    static uint16_t anim_timer = 0;
    static uint8_t  blink      = 0;

    if (timer_elapsed(anim_timer) > 200) {
        anim_timer = timer_read();
        blink      = (blink + 1) & 1;
    }

    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _LOWER:
            oled_write_ln_P(blink ? PSTR("> lo_") : PSTR("> lo "), false);
            break;
        case _RAISE:
            oled_write_ln_P(blink ? PSTR("> hi_") : PSTR("> hi "), false);
            break;
        case _ADJUST:
            oled_write_ln_P(blink ? PSTR("> aj_") : PSTR("> aj "), false);
            break;
        case _SPECIAL:
            oled_write_ln_P(blink ? PSTR("> sp_") : PSTR("> sp "), false);
            break;
        case _GAME:
        case _GAME_NUM:
            oled_write_ln_P(blink ? PSTR("> gm_") : PSTR("> gm "), false);
            break;
        default:
            oled_write_ln_P(blink ? PSTR("> _  ") : PSTR(">    "), false);
    }
};

void oled_render_keyboard_layout(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWRTY"), false);
            break;
        case _COLEMAK_DH:
            oled_write_P(PSTR("CM-DH"), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR(" NAV "), false);
            break;
        case _GAME:
            oled_write_P(PSTR("GAMES"), false);
            break;
        case _GAME_NUM:
            oled_write_P(PSTR("GM-NB"), false);
            break;
    }
}

void oled_render_wpm(void) {
#ifdef WPM_ENABLE
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
#endif
}

__attribute__((weak)) void oled_render_logo_primary(void) { oled_render_logo(); }

__attribute__((weak)) void oled_render_logo_secondary(void) { oled_render_logo(); }

void oled_render_status_primary(void) {
    oled_render_logo_primary();

    oled_write_ln_P(PSTR(""), false);
    oled_render_keyboard_layout();

    oled_set_cursor(0, 7);
    oled_render_layer_state(get_highest_layer(layer_state | default_layer_state));

    oled_set_cursor(0, 11);
    oled_render_mod_status(get_mods());
}

void oled_render_status_secondary(void) {
    oled_render_logo_secondary();

    oled_write_ln_P(PSTR(""), false);
    oled_render_blink_prompt();
    oled_write_ln_P(PSTR(""), false);

#ifdef OLED_CUSTOM_MASCOT
    oled_render_mascot_status();
#endif

    oled_set_cursor(0, 13);
#ifdef WPM_ENABLE
    oled_render_wpm();
#endif
}

/* QMK OLED hook bindings */

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return oled_init_keymap(rotation); }

bool oled_off_if_idle(void) {
    /* Bail out of rendering if idled */
    if (sync_timer_elapsed32(oled_idle_timer) > OLED_IDLE_THRESHOLD) {
        oled_off();
        return true;
    } else {
        oled_on();
    }

    return false;
}

bool oled_task_user(void) {
// TODO: Fix this terrible condition
#if defined(SPLIT_OLED_ENABLE) && !defined(SLAVE_OLED_MASTER_TRACKBALL)
    if (is_keyboard_master()) {
        if (oled_off_if_idle()) {
            return false;
        }
    }
#else
    if (oled_off_if_idle()) {
       return false;
    }
#endif

    /* Render */
    if (is_keyboard_left()) {
        oled_render_status_primary();
    } else {
        oled_render_status_secondary();
    }

    return false;
}

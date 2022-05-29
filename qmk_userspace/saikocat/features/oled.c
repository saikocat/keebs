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

/* keystroke/tap gap timer */
uint32_t oled_idle_timer = 0;

bool process_record_user_oled(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        /* keystroke/tap gap timer update */
        oled_idle_timer = sync_timer_read32();
    }
    return true;
}

void oled_force_on(void) {
    oled_idle_timer = sync_timer_read32();
    oled_on();
}

__attribute__((weak)) oled_rotation_t oled_init_keymap(oled_rotation_t rotation) {
#ifdef OLED_DISPLAY_128X64
    return OLED_ROTATION_180;
#else
    return OLED_ROTATION_270;
#endif
}

#ifdef SWAP_HANDS_ENABLE
extern bool swap_hands;
#endif

void oled_render_logo(void) {
#ifdef OLED_DISPLAY_128X64
    // clang-format off
    static const char PROGMEM qmk_logo[][6] = {
        {0x80, 0x81, 0x82, 0x83, 0x84, 0},
        {0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0},
        {0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0},
    };
    // clang-format on

    oled_write_P(qmk_logo[0], false);
    oled_write_P(PSTR(":"), false);  // write left border
    oled_set_cursor(0, 1);
    oled_write_P(qmk_logo[1], false);
    oled_write_P(PSTR(":"), false);
    oled_set_cursor(0, 2);
    oled_write_P(qmk_logo[2], false);
    oled_write_P(PSTR(":"), false);
    oled_set_cursor(0, 3);
    oled_write_P(PSTR("::::::"), false);  // write bottom border
#else
    // clang-format off
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4,0
    };
    // clang-format on
    oled_write_P(logo, false);
#endif
}

__attribute__((weak)) void oled_render_layer_state(uint8_t const state) {
#ifdef OLED_DISPLAY_128X64
    // clang-format off
    static const char PROGMEM layers[4][3][6] = {
        {
            {0x20, 0x94, 0x95, 0x96, 0x20, 0},
            {0x20, 0xb4, 0xb5, 0xb6, 0x20, 0},
            {0x20, 0xd4, 0xd5, 0xd6, 0x20, 0},
        },
        {
            {0x20, 0x9a, 0x9b, 0x9c, 0x20, 0},
            {0x20, 0xba, 0xbb, 0xbc, 0x20, 0},
            {0x20, 0xda, 0xdb, 0xdc, 0x20, 0},
        },
        {
            {0x20, 0x97, 0x98, 0x99, 0x20, 0},
            {0x20, 0xb7, 0xb8, 0xb9, 0x20, 0},
            {0x20, 0xd7, 0xd8, 0xd9, 0x20, 0},
        },
        {
            {0x20, 0x9d, 0x9e, 0x9f, 0x20, 0},
            {0x20, 0xbd, 0xbe, 0xbf, 0x20, 0},
            {0x20, 0xdd, 0xde, 0xdf, 0x20, 0},
        },
    };
    // clang-format on

    void _render_sprite_stack(uint8_t const col, uint8_t const row, uint8_t const sprite_idx) {
        oled_set_cursor(col, row);
        oled_write_P(layers[sprite_idx][0], false);
        oled_set_cursor(col, row + 1);
        oled_write_P(layers[sprite_idx][1], false);
        oled_set_cursor(col, row + 2);
        oled_write_P(layers[sprite_idx][2], false);
    }

    switch (state) {
        case _LOWER:
        case _NUM:
        case _SYMNUM:
            _render_sprite_stack(7, 0, 1);
            break;
        case _RAISE:
            _render_sprite_stack(7, 0, 2);
            break;
        case _ADJUST:
        case _SPECIAL:
            _render_sprite_stack(7, 0, 3);
            break;
        default:
            _render_sprite_stack(7, 0, 0);
    }
#else
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
        case _NUM:
        case _SYMNUM:
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
#endif
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

void oled_render_mod_status_helper(oled_mods_render_data_t data, char const sprite[2][2][2][3]) {
    uint8_t left_state  = data.left_mod ? 1 : 0;
    uint8_t right_state = data.right_mod ? 1 : 0;
    uint8_t border_idx  = (left_state << 1) | right_state;

    /* Top half and border padding */
    if (data.use_cursor) {
        oled_set_cursor(data.col, data.row);
    }
    oled_write_P(sprite[_SP_LEFT][left_state][_SP_TOP], false);
    oled_write_P(sprite_font_mod_status_borders[border_idx][_SP_TOP], false);
    oled_write_P(sprite[_SP_RIGHT][right_state][_SP_TOP], false);

    /* Bottom half and border padding */
    if (data.use_cursor) {
        oled_set_cursor(data.col, data.row + 1);
    }
    oled_write_P(sprite[_SP_LEFT][left_state][_SP_BOTTOM], false);
    oled_write_P(sprite_font_mod_status_borders[border_idx][_SP_BOTTOM], false);
    oled_write_P(sprite[_SP_RIGHT][right_state][_SP_BOTTOM], false);
}

// Primary modifier status display function
void oled_render_mod_status(uint8_t modifiers) {
#if defined(OLED_DISPLAY_128X64)
    static bool use_cursor = true;
#else
    static bool use_cursor = false;
#endif
    oled_mods_render_data_t gui_alt = {
        .left_mod   = modifiers & MOD_MASK_GUI,
        .right_mod  = modifiers & MOD_MASK_ALT,
        .col        = 7,
        .row        = 3,
        .use_cursor = use_cursor,
    };
    oled_render_mod_status_helper(gui_alt, sprite_font_mod_status_gui_alt);

    oled_mods_render_data_t ctl_sft = {
        .left_mod   = modifiers & MOD_MASK_CTRL,
        .right_mod  = modifiers & MOD_MASK_SHIFT || host_keyboard_led_state().caps_lock,
        .col        = 12,
        .row        = 3,
        .use_cursor = use_cursor,
    };
    oled_render_mod_status_helper(ctl_sft, sprite_font_mod_status_ctl_shift);
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

__attribute__((weak)) void oled_render_keyboard_layout(void) {
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_QWERTY), false);
            break;
        case _COLEMAK_DH:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_COLEMAK_DH), false);
            break;
        case _NAVIGATION:
            oled_write_P(PSTR(OLED_RENDER_LAYER_NAV), false);
            break;
        case _GAME:
            oled_write_P(PSTR(OLED_RENDER_LAYER_GAME), false);
            break;
        default:
            oled_write_P(PSTR(OLED_RENDER_LAYOUT_UNDEFINED), false);
            break;
    }
}

void oled_render_wpm(void) {
#ifdef WPM_ENABLE
    oled_write_P(PSTR("WPM: "), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);
#endif
}

void oled_render_encoder(void) {
#ifdef ENCODER_ENABLE
#    include "features/encoder.h"
    extern encoder_mode_t encoder_left_mode;
    extern encoder_mode_t encoder_right_mode;

    // Encoders
    oled_write_P(PSTR("L-Enc: "), false);
    oled_write_P(encoder_mode_stringify(encoder_left_mode), false);
    oled_advance_page(true);
    oled_write_P(PSTR("R-Enc: "), false);
    oled_write_P(encoder_mode_stringify(encoder_right_mode), false);
    oled_advance_page(true);
#endif
}

void oled_render_combo(void) {
#    ifdef COMBO_ENABLE    
    oled_write_P(PSTR("Combo: "), false);
    oled_write_P(PSTR(" ON "), is_combo_enabled());
    oled_write_P(PSTR(" OFF "), !is_combo_enabled());
#endif
}

__attribute__((weak)) void oled_render_logo_primary(void) { oled_render_logo(); }

__attribute__((weak)) void oled_render_logo_secondary(void) { oled_render_logo(); }

__attribute__((weak)) void oled_render_status_primary(void) {
#if defined(OLED_DISPLAY_128X64)
    oled_render_logo_primary();

    // Render layer state horizontally to logo
    oled_render_layer_state(get_highest_layer(layer_state | default_layer_state));
    oled_set_cursor(12, 1);
    oled_render_keyboard_layout();

    // Render modstatus
    oled_set_cursor(0, 4);  // bottom alignment to mod icons
    oled_write_P(PSTR("Mods : "), false);
    oled_set_cursor(0, 3);
    oled_render_mod_status(get_mods());
    oled_advance_page(true);

#    ifdef ENCODER_ENABLE
    // Render encoder mode
    oled_render_encoder();
#    endif

#    ifdef COMBO_ENABLE
    oled_render_combo();
#    endif
#else
    oled_render_logo_primary();

    oled_write_ln_P(PSTR(""), false);
    oled_render_keyboard_layout();

    oled_set_cursor(0, 7);
    oled_render_layer_state(get_highest_layer(layer_state | default_layer_state));
    oled_set_cursor(0, 11);
    oled_render_mod_status(get_mods());
#endif
}

__attribute__((weak)) void oled_render_status_secondary(void) {
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

__attribute__((weak)) bool oled_task_user(void) {
// TODO: Fix this terrible condition
#if defined(SPLIT_OLED_ENABLE) && !defined(POINTING_DEVICE_RIGHT)
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

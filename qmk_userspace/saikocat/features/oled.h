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

#pragma once

#include "quantum.h"
#include "drivers/oled/oled_driver.h"

#ifndef OLED_IDLE_THRESHOLD
#    define OLED_IDLE_THRESHOLD 30000U
#endif

// clang-format off
#ifdef OLED_DISPLAY_128X64
#    define OLED_RENDER_LAYOUT_QWERTY     " QWERTY "
#    define OLED_RENDER_LAYOUT_COLEMAK_DH " cm-DH  "
#    define OLED_RENDER_LAYOUT_COLEMAK    " COLEMAK"
#    define OLED_RENDER_LAYOUT_UNDEFINED  " UNDEF  "

#    define OLED_RENDER_LAYER_NAV         " Navi   "
#    define OLED_RENDER_LAYER_GAME        " Games  "

#    define OLED_RENDER_WPM_COUNTER       "WPM: "
#else
#    define OLED_RENDER_LAYOUT_QWERTY     "QWRTY"
#    define OLED_RENDER_LAYOUT_COLEMAK_DH "cm-DH"
#    define OLED_RENDER_LAYOUT_COLEMAK    "CLMK "
#    define OLED_RENDER_LAYOUT_UNDEFINED  "UNDEF"

#    define OLED_RENDER_LAYER_NAV         " NAV "
#    define OLED_RENDER_LAYER_GAME        "GAMES"

#    define OLED_RENDER_WPM_COUNTER       "WPM: "
#endif
// clang-format on

typedef struct OledModsRenderData {
    uint8_t const left_mod;
    uint8_t const right_mod;
    uint8_t const col;  // initial col
    uint8_t const row;  // initial row
    bool const    use_cursor;
} oled_mods_render_data_t;

void oled_render_mod_status_helper_stub(oled_mods_render_data_t data);

/* User overridable to set oled orientation */
oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
/* Hook to main process_user_records */
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);

void oled_render_wpm(void);
void oled_render_encoder(void);
void oled_render_logo_primary(void);
void oled_render_logo_secondary(void);
void oled_render_mod_status(uint8_t modifiers);
void oled_render_layer_state(uint8_t const state);
void oled_render_keyboard_layout(void);
void oled_render_status_primary(void);
void oled_render_status_secondary(void);

void oled_force_on(void);

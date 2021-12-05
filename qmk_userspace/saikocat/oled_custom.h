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

#ifdef OLED_ENABLE
#    include "quantum.h"
#    include "oled_driver.h"

#    include "definitions_custom.h"
#    include "oled_mascot.h"

/* User overridable to set oled orientation */
oled_rotation_t oled_init_keymap(oled_rotation_t rotation);
/* Hook to main process_user_records */
bool process_record_user_oled(uint16_t keycode, keyrecord_t *record);

void oled_render_wpm(void);
void oled_render_logo_primary(void);
void oled_render_logo_secondary(void);
void oled_render_mod_status(uint8_t modifiers);
void oled_render_layer_state(uint8_t const state);
void oled_render_keyboard_layout(void);
#endif
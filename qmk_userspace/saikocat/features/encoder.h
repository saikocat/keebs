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

#include "definitions.h"

typedef enum {
    ENC_MODE_NOOP,
    ENC_MODE_VOLUME_CTRL,
    ENC_MODE_PAGING,
    ENC_MODE_BROWSER_TAB_NAV,
    ENC_MODE_WORD_NAV,
    ENC_MODE_UNDO_REDO,
    ENC_MODE_INCREMENTAL_SEARCH,
    ENC_MODE_OS_APP_SWITCH,
    ENC_MODE_ALT_TAB = ENC_MODE_OS_APP_SWITCH,
    ENC_MODE_HORIZONTAL_NAV,
    ENC_MODE_VERTICAL_NAV,
    _ENC_MODE_LAST  // Do not use, except for looping through enum values
} encoder_mode_t;

void encoder_init_mode_user(void);
bool encoder_update_keymap(uint8_t index, bool clockwise);
void matrix_scan_user_encoder(void);

const char* PROGMEM encoder_mode_stringify(encoder_mode_t mode);

void encoder_action(encoder_mode_t mode, uint8_t clockwise);
void encoder_action_volume_control(bool clockwise);
void encoder_action_paging(bool clockwise);
void encoder_action_browser_tab_nav(bool clockwise);
void encoder_action_word_nav(bool clockwise);
void encoder_action_undo_redo(bool clockwise);
void encoder_action_incremental_search(bool clockwise);
void encoder_action_os_app_switch(bool clockwise);
void encoder_action_os_app_switch_with_timer(bool clockwise, bool* is_alt_tab_active, uint16_t* alt_tab_timer);
void encoder_action_horizontal_nav(bool clockwise);

layer_state_t layer_state_set_encoder(layer_state_t state);

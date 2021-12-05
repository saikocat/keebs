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

#include QMK_KEYBOARD_H

#include "definitions_custom.h"
#include "layout_wrappers.h"
#include "process_records.h"
#ifdef LED_INDICATOR_ENABLE
#    include "led_custom.h"
#endif
#ifdef OLED_ENABLE
#    include "oled_custom.h"
#endif
#ifdef ENCODER_ENABLE
#    include "encoder_custom.h"
#endif
#ifdef PIMORONI_TRACKBALL_ENABLE
#    include "pimoroni_trackball_custom.h"
#    include "colours_control.h"
#endif
#ifdef SPLIT_KEYBOARD
#    include "transport_sync.h"
#endif

/* Layer state check */
layer_state_t layer_state_set_keymap(layer_state_t state);

/* Power management */
void suspend_power_down_keymap(void);
void suspend_wakeup_init_keymap(void);

/* Matrix scan */
void matrix_scan_keymap(void);

/* Post keyboard init */
void keyboard_post_init_keymap(void);
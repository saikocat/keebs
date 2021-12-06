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

#include "pointing_device.h"
#include "drivers/sensors/pimoroni_trackball.h"

#ifndef PIMORONONI_TRACKBALL_LED_TIMEOUT
#    define PIMORONONI_TRACKBALL_LED_TIMEOUT 60000
#endif

#ifndef PIMORONONI_TRACKBALL_SCROLL_DIVIDER
#    define PIMORONONI_TRACKBALL_SCROLL_DIVIDER 12
#endif

void keyboard_post_init_keymap_trackball(void);

void pointing_device_suspend_power_down_keymap(void);

bool process_record_user_pimoroni_trackball(uint16_t keycode, keyrecord_t *record);

void pimoroni_trackball_set_scrolling(bool scrolling);

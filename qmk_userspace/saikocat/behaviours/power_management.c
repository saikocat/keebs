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

#include "behaviours/power_management.h"
#include "features/oled.h"
#include "features/pimoroni_trackball.h"

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) {
#ifdef OLED_ENABLE
    oled_on();
#endif
    suspend_wakeup_init_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}
void                       suspend_power_down_user(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
#ifdef PIMORONI_TRACKBALL_ENABLE
    pointing_device_suspend_power_down_keymap();
#endif
    suspend_power_down_keymap();
}

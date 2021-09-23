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

#ifdef LED_INDICATOR_ENABLE
#    include "led_custom.h"

__attribute__((weak)) void led_update_mcu(led_t led_state) {}
__attribute__((weak)) void led_update_keymap(led_t led_state) {}

bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        led_update_mcu(led_state);
        led_update_keymap(led_state);
    }
    return res;
}

#endif
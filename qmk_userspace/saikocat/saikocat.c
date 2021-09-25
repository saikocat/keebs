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

#include "saikocat.h"

/* Layer state check */
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) { return state; }
layer_state_t                       layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    // state = update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
    // state = update_tri_layer_state(state, _LOWER, _ADJUST, _SPECIAL);
    state = layer_state_set_keymap(state);
    return state;
}

/* Power management */
__attribute__((weak)) void suspend_power_down_keymap(void) {}
void                       suspend_power_down_user(void) {
#ifdef OLED_ENABLE
    oled_off();
#endif
    suspend_power_down_keymap();
}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) { suspend_wakeup_init_keymap(); }

/* Matrix scan */
__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
#ifdef ENCODER_ENABLE
    matrix_scan_encoder();
#endif
    matrix_scan_keymap();
}
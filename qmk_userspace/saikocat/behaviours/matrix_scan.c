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

#include "quantum.h"

#include "features/encoder.h"

bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

__attribute__((weak)) void matrix_scan_keymap(void) {}
void                       matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) { /* 1000 hold wait */
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
#ifdef ENCODER_ENABLE
    matrix_scan_user_encoder();
#endif
    matrix_scan_keymap();
}
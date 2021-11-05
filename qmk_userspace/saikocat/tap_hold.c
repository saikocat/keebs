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

#include "tap_hold.h"

__attribute__((weak)) uint16_t get_tapping_term_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_LWR:
            return 175;
        case SPC_RSE:
            return 175;
        default:
            return TAPPING_TERM;
    }
}

#ifdef TAPPING_TERM_PER_KEY
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) { return get_tapping_term_keymap(keycode, record); }
#endif

__attribute__((weak)) bool get_permissive_hold_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_LWR:
            return true;
        case SPC_RSE:
            return false;
        default:
            return false;
    }
}

#ifdef PERMISSIVE_HOLD_PER_KEY
bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) { return get_permissive_hold_keymap(keycode, record); }
#endif

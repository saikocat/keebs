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

#include "process_records.h"
#include "oled_custom.h"

__attribute__((weak)) bool process_record_tri_layer_state(uint16_t keycode, keyrecord_t *record) {
    static uint16_t my_colon_timer;

    switch (keycode) {
        case BSPC_LWR:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
        case SPC_RSE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            break;
        case ADJ_SCLN:
            if (record->event.pressed) {
                layer_on(_ADJUST);
                update_tri_layer(_LOWER, _ADJUST, _SPECIAL);
            } else {
                layer_off(_ADJUST);
                update_tri_layer(_LOWER, _ADJUST, _SPECIAL);
            }
            break;
    }
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
bool                       process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    process_record_user_oled(keycode, record);
#endif
    process_record_tri_layer_state(keycode, record);
    return process_record_keymap(keycode, record);
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) { post_process_record_keymap(keycode, record); }

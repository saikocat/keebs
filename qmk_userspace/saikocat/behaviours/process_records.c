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


#include "definitions.h"
#include "behaviours/process_records.h"
#include "features/oled.h"
#include "features/pimoroni_trackball.h"

/* Reverse of shift
 *
 * If shift is held, output its non-shifted version
 * If shift is not held, output its shifted version
 *
 * Use this mainly for vim command shortcut (:)
 */
#ifdef NO_ACTION_ONESHOT
void unshift_key_tap(uint16_t kc, uint16_t shift_kc) {
    uint8_t temp_mod = get_mods();
    clear_mods();
    if (temp_mod & MOD_MASK_SHIFT) {
        tap_code(kc);
    } else {
        tap_code16(shift_kc);
    }
    set_mods(temp_mod);
}
#else
void unshift_key_tap(uint16_t kc, uint16_t shift_kc) {
    uint8_t temp_mod = get_mods();
    uint8_t temp_osm = get_oneshot_mods();
    clear_mods();
    clear_oneshot_mods();
    if ((temp_mod | temp_osm) & MOD_MASK_SHIFT) {
        tap_code(kc);
    } else {
        tap_code16(shift_kc);
    }
    set_mods(temp_mod);
}
#endif

bool mod_key_press(uint16_t code, uint16_t mod_code, bool pressed, uint16_t this_timer) {
    if (pressed) {
        this_timer = timer_read();
    } else {
        if (timer_elapsed(this_timer) < TAPPING_TERM) {
            tap_code(code);
        } else {
            register_code(mod_code);
            tap_code(code);
            unregister_code(mod_code);
        }
    }
    return false;
}

bool is_keyrecord_held(keyrecord_t *record) { return !record->tap.count && record->event.pressed; }

bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    return mod_key_press(code, mod_code, pressed, this_timer);
}

__attribute__((weak)) bool process_record_tri_layer_state(uint16_t keycode, keyrecord_t *record) {
    static uint16_t layer_tap_colon_timer;

    switch (keycode) {
        case COLN_ADJ:
            if (is_keyrecord_held(record)) {
                /* held state */
                layer_on(_ADJUST);
                update_tri_layer(_LOWER, _ADJUST, _SPECIAL);

                layer_tap_colon_timer = timer_read();
            } else {
                layer_off(_ADJUST);
                update_tri_layer(_LOWER, _ADJUST, _SPECIAL);

                /* send colon cos vim cmd */
                if (timer_elapsed(layer_tap_colon_timer) < TAPPING_TERM) {
                    unshift_key_tap(KC_SCLN, KC_COLN);
                }
            }
            return false;
    }
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) { return true; }
__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef OLED_ENABLE
    process_record_user_oled(keycode, record);
#endif
#ifdef PIMORONI_TRACKBALL_ENABLE
    if (!process_record_user_pimoroni_trackball(keycode, record)) {
        return false;
    }
#endif
    if (!process_record_tri_layer_state(keycode, record)) {
        return false;
    }
    return process_record_keymap(keycode, record);
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        /* swaphand without layer state conflict */
        case SH_MON:
            if (record->event.pressed && layer_state_is(_LOWER)) {
                layer_off(_LOWER);
            }
            break;
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) { post_process_record_keymap(keycode, record); }

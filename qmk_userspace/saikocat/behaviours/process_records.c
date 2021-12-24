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

bool is_keyrecord_tap(keyrecord_t *record) { return record->tap.count && record->event.pressed; }

bool mod_key_press_timer(uint16_t code, uint16_t mod_code, bool pressed) {
    static uint16_t this_timer;
    return mod_key_press(code, mod_code, pressed, this_timer);
}

__attribute__((weak)) bool process_record_tri_layer_state(uint16_t keycode, keyrecord_t *record) { return true; }

__attribute__((weak)) bool process_record_homerow_modifier_cancellation(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case RCTL_T(KC_N):
            /*
            This piece of code nullifies the effect of Right Shift when tapping
            the RCTL_T(KC_N) key.
            This helps rolling over RSFT_T(KC_E) and RCTL_T(KC_N)
            to obtain the intended "en" instead of "N".
            Consequently, capital N can only be obtained by tapping RCTL_T(KC_N)
            and holding LSFT_T(KC_S) (which is the left Shift mod tap).
            */

            /*
            Detect the tap.
            We're only interested in overriding the tap behaviour
            in a certain cicumstance. The hold behaviour can stay the same.
            */
            if (record->tap.count > 0) {
                // Detect right Shift
                if (get_mods() & MOD_BIT(KC_RSHIFT)) {
                    // temporarily disable right Shift
                    // so that we can send KC_E and KC_N
                    // without Shift on.
                    unregister_mods(MOD_BIT(KC_RSHIFT));
                    tap_code(KC_E);
                    tap_code(KC_N);
                    // restore the mod state
                    add_mods(MOD_BIT(KC_RSHIFT));
                    // to prevent QMK from processing RCTL_T(KC_N) as usual in our special case
                    return false;
                }
            }
            /*else process RCTL_T(KC_N) as usual.*/
            return true;

        case LCTL_T(KC_T):
            /*
            This piece of code nullifies the effect of Left Shift when
            tapping the LCTL_T(KC_T) key.
            This helps rolling over LSFT_T(KC_S) and LCTL_T(KC_T)
            to obtain the intended "st" instead of "T".
            Consequently, capital T can only be obtained by tapping LCTL_T(KC_T)
            and holding RSFT_T(KC_E) (which is the right Shift mod tap).
            */

            if (record->tap.count > 0) {
                if (get_mods() & MOD_BIT(KC_LSHIFT)) {
                    unregister_mods(MOD_BIT(KC_LSHIFT));
                    tap_code(KC_S);
                    tap_code(KC_T);
                    add_mods(MOD_BIT(KC_LSHIFT));
                    return false;
                }
            }
            /*else process LCTL_T(KC_T) as usual.*/
            return true;
    }
    return true;
}

__attribute__((weak)) bool process_record_super_alt_tab(uint16_t keycode, keyrecord_t *record) {
    extern bool     is_alt_tab_active;
    extern uint16_t alt_tab_timer;

    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
    }
    return true;
}

__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLN_ADJ:
            if (is_keyrecord_tap(record)) {
                unshift_key_tap(KC_SCLN, KC_COLN);
                return false;
            }
            break;
    }
    return true;
}

__attribute__((weak)) bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    process_record_super_alt_tab(keycode, record);
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
    if (!process_record_homerow_modifier_cancellation(keycode, record)) {
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

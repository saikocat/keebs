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

#include "definitions_custom.h"

/* Do check process_record/tri_layer_state for more conflicts */

__attribute__((weak)) uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_LWR:
            return TAPPING_TERM - 25;
        case SPC_ADJ:
        case SPC_LWR:
        case SPC_RSE:
            return TAPPING_TERM + 25;
        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case ALT_R:
        case SFT_S:
        case CTL_T:
        case CTL_J:
        case SFT_K:
        case ALT_L:
        case GUI_SCLN:
        case CTL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
        case GUI_Z:
        case GUI_SCSH:
            return TAPPING_TERM + 25;
        default:
            return TAPPING_TERM;
    }
}

__attribute__((weak)) bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is pressed (tapped and released)
    // return true;
    // Do not select the hold action when another key is pressed.
    // return false;
    switch (keycode) {
        case ESC_ALT:
        case BSPC_NUM:
            return true;
        default:
            return false;
    }
}

__attribute__((weak)) bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    // Immediately select the hold action when another key is tapped:
    // return true;
    // Do not select the hold action when another key is tapped.
    // return false;
    switch (keycode) {
        case ESC_ALT:
        case BSPC_LWR:
        case BSPC_NUM:
            return true;
        default:
            return false;
    }
}

__attribute__((weak)) bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
    // Do not force the mod-tap key press to be handled as a modifier
    // if any other key was pressed while the mod-tap key is held down.
    // return true;
    // Force the mod-tap key press to be handled as a modifier if any
    // other key was pressed while the mod-tap key is held down.
    // return false;
    switch (keycode) {
        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case ALT_R:
        case SFT_S:
        case CTL_T:
        case CTL_J:
        case SFT_K:
        case ALT_L:
        case GUI_SCLN:
        case CTL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
        case GUI_Z:
        case GUI_SCSH:
            return true;
        default:
            return false;
    }
}
__attribute__((weak)) bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    // Disable repeated tapping
    switch (keycode) {
        case GUI_A:
        case ALT_S:
        case SFT_D:
        case CTL_F:
        case ALT_R:
        case SFT_S:
        case CTL_T:
        case CTL_J:
        case SFT_K:
        case ALT_L:
        case GUI_SCLN:
        case CTL_N:
        case SFT_E:
        case ALT_I:
        case GUI_O:
        case GUI_Z:
        case GUI_SCSH:
            return true;
        default:
            return false;
    }
}

__attribute__((weak)) bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    // Output keycode regardless after hold is done
    switch (keycode) {
        default:
            return false;
    }
}

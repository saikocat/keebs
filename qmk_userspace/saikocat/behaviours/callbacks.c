/* Copyright (C) 2022 @saikocat
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

#include "combos/combos.h"
#include "features/encoder.h"
#include "transports/split_transport_sync.h"

/* Layer state check */
__attribute__((weak)) layer_state_t layer_state_set_keymap(layer_state_t state) {
    // state = update_tri_layer_state(state, _LOWER, _ADJUST, _SPECIAL);

#ifdef ENCODER_ENABLE
    layer_state_set_encoder(state);
#endif

#ifdef COMBO_ENABLE
    layer_state_set_combo(state);
#endif

    return state;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    if (!is_keyboard_master()) {
        return state;
    }

    state = layer_state_set_keymap(state);
    return state;
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
#if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
    keyboard_post_init_transport_sync();
#endif
#if defined(ENCODER_ENABLE)
    encoder_init_mode_user();
#endif
    // #ifdef CONSOLE_ENABLE
    //     debug_enable=true;
    // #endif
    keyboard_post_init_keymap();
}

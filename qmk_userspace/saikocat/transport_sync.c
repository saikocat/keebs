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

#include <string.h>
#include "transactions.h"
#include "sync_timer.h"

#include "transport_sync.h"

uint32_t transport_user_state = 0;

#ifdef SLAVE_OLED_MASTER_TRACKBALL
extern uint32_t oled_idle_timer;
#endif

user_runtime_config_t user_state;

void user_state_sync(uint8_t initiator2target_buffer_size, const void* initiator2target_buffer, uint8_t target2initiator_buffer_size, void* target2initiator_buffer) {
    if (initiator2target_buffer_size == sizeof(transport_user_state)) {
        memcpy(&transport_user_state, initiator2target_buffer, initiator2target_buffer_size);
    }
}

void keyboard_post_init_transport_sync(void) {
    // Register keyboard state sync split transaction
    transaction_register_rpc(RPC_ID_USER_STATE_SYNC, user_state_sync);
}

void user_transport_update(void) {
    if (is_keyboard_master()) {
#ifdef SLAVE_OLED_MASTER_TRACKBALL
        user_state.oled_idle_timer = oled_idle_timer;
#endif

        transport_user_state = user_state.raw;
    } else {
        user_state.raw = transport_user_state;

#ifdef SLAVE_OLED_MASTER_TRACKBALL
        oled_idle_timer = user_state.oled_idle_timer;
#endif
    }
}

void user_transport_sync(void) {
    if (is_keyboard_master()) {
        // Keep track of the last state, so that we can tell if we need to propagate to slave
        static uint32_t last_sync[0], last_user_state = 0;
        bool            needs_sync = false;

        // Check if the state values are different
        if (memcmp(&transport_user_state, &last_user_state, sizeof(transport_user_state))) {
            needs_sync = true;
            memcpy(&last_user_state, &transport_user_state, sizeof(transport_user_state));
        }
        // Send to slave every 500ms regardless of state change
        if (sync_timer_elapsed32(last_sync[0]) > 250) {
            needs_sync = true;
        }

        // Perform the sync if requested
        if (needs_sync) {
            if (transaction_rpc_send(RPC_ID_USER_STATE_SYNC, sizeof(user_state), &user_state)) {
                last_sync[0] = sync_timer_read32();
            }
            needs_sync = false;
        }
    }
}

void housekeeping_task_user(void) {
    // Update kb_state so we can send to slave
    user_transport_update();

    // Data sync from master to slave
    user_transport_sync();
}

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

#include "led_custom.h"
#include "led_provider_bit_c.h"

void set_led(uint8_t mode) {
    switch (mode) {
        case LED_ON:
            setPinOutput(PIN_LED);
            writePin(PIN_LED, GPIO_STATE_HIGH);
            break;

        case LED_DIM:
            setPinInput(PIN_LED);
            break;

        case LED_OFF:
            setPinOutput(PIN_LED);
            writePin(PIN_LED, GPIO_STATE_LOW);
            break;

        default:
            break;
    }
}

void led_update_mcu(led_t led_state) { set_led(led_state.caps_lock ? LED_DIM : LED_OFF); }
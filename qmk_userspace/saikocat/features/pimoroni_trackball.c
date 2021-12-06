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
#include "quantum.h"
#include "report.h"
#include "timer.h"

#include "lib/lib8tion/lib8tion.h"

#include "definitions.h"
#include "features/pimoroni_trackball.h"

static report_mouse_t last_mouse_report               = {0};
static uint32_t       last_mouse_activity_timer       = 0;
static bool           pimoroni_trackball_is_scrolling = false;

void pimoroni_trackball_set_scrolling(bool scrolling) { pimoroni_trackball_is_scrolling = scrolling; }

void pimoroni_trackball_led_off(void) { pimoroni_trackball_set_rgbw(0x00, 0x00, 0x00, 0x00); }

void pimoroni_trackball_led_update_colours(void) {
    switch (get_highest_layer(layer_state | default_layer_state)) {
        case _COLEMAK_DH:
        case _QWERTY:
            pimoroni_trackball_set_rgbw(0, 51, 102, 23);  // PleasingBlue
            break;
        case _RAISE:
            pimoroni_trackball_set_rgbw(255, 0, 255, 80);  // Magenta
            break;
        case _LOWER:
            pimoroni_trackball_set_rgbw(255, 191, 0, 0);  // Amber
            break;
        case _GAME:
            pimoroni_trackball_set_rgbw(48, 213, 200, 80);  // Turquoise
            break;
        case _ADJUST:
            pimoroni_trackball_set_rgbw(153, 0, 110, 39);  // DarkMagenta
            break;
        default:
            pimoroni_trackball_set_rgbw(0, 0, 0, 80);
    }
}

// clang-format off
bool pimoroni_trackball_led_is_timeout(void) {
    return PIMORONONI_TRACKBALL_LED_TIMEOUT > 0 
        && timer_elapsed32(last_mouse_activity_timer) > PIMORONONI_TRACKBALL_LED_TIMEOUT;
}
// clang-format on

static void handle_mouse_button(uint8_t mouse_button_keycode, keyrecord_t *record) {
    // TODO: This handles only const defined in report.h (MOUSE_BTN1).
    // MOUSEKEY ENABLE have to deal with differently
    report_mouse_t current_report = pointing_device_get_report();
    if (record->event.pressed) {
        current_report.buttons |= mouse_button_keycode;
    } else {
        current_report.buttons &= ~mouse_button_keycode;
    }
    pointing_device_set_report(current_report);
    pointing_device_send();
}

static report_mouse_t handle_scrolling(report_mouse_t mouse_report) {
    static int8_t scroll_h;
    static int8_t scroll_v;

    int8_t clamped_x = mouse_report.x, clamped_y = mouse_report.y;
    mouse_report.x = 0;
    mouse_report.y = 0;

    // accumulate scroll
    scroll_h += clamped_x;
    scroll_v += clamped_y;

    int8_t scaled_scroll_h = scroll_h / PIMORONONI_TRACKBALL_SCROLL_DIVIDER;
    int8_t scaled_scroll_v = scroll_v / PIMORONONI_TRACKBALL_SCROLL_DIVIDER;

    // clear accumulated scroll on assignment
    if (scaled_scroll_h != 0) {
        mouse_report.h = -scaled_scroll_h;
        scroll_h       = 0;
    }

    if (scaled_scroll_v != 0) {
        mouse_report.v = -scaled_scroll_v;
        scroll_v       = 0;
    }

    return mouse_report;
}

__attribute__((weak)) report_mouse_t pointing_device_task_user(report_mouse_t mouse_report) {
#ifdef POINTING_DEVICE_RIGHT
    if (!is_keyboard_master()) {
        return mouse_report;
    }
#endif

    if (has_mouse_report_changed(last_mouse_report, mouse_report)) {
        last_mouse_activity_timer = timer_read32();
        memcpy(&last_mouse_report, &mouse_report, sizeof(mouse_report));
        pimoroni_trackball_led_update_colours();
    } else if (pimoroni_trackball_led_is_timeout()) {
        pimoroni_trackball_led_off();
    } else {
        pimoroni_trackball_led_update_colours();
    }

    if (pimoroni_trackball_is_scrolling) {
        mouse_report = handle_scrolling(mouse_report);
    }

    // mouse_report = smooth_it(mouse_report);
    return mouse_report;
}

bool process_record_user_pimoroni_trackball(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TB_SCR:
            if (record->event.pressed) {
                pimoroni_trackball_set_scrolling(!pimoroni_trackball_is_scrolling);
            }
            return false;
        case TB_LCL:
            handle_mouse_button(MOUSE_BTN1, record);
            return false;
        case TB_RCL:
            handle_mouse_button(MOUSE_BTN2, record);
            return false;
        case TB_MCL:
            handle_mouse_button(MOUSE_BTN3, record);
            return false;
    }
    return true;
}

__attribute__((weak)) void pointing_device_init_user() { pimoroni_trackball_led_update_colours(); }

__attribute__((weak)) void pointing_device_suspend_power_down_keymap(void) { pimoroni_trackball_led_off(); }

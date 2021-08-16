/* Function: Bit-C microcontroller specific
 * ----------------------------------------
 * Just turn off OLED for the keyboard for now when CapsLock is not on
 * NOTE: Only work with Master, splitkb is not supported yet.
 */

#ifdef HW_BITC

#    include "features/bitc_led.h"

// Use Bit-C LED to show CAPS LOCK status
bool led_update_kb(led_t led_state) {
    bool res = led_update_user(led_state);
    if (res) {
        set_bitc_LED(led_state.caps_lock ? LED_DIM : LED_OFF);
    }
    return res;
}

#endif

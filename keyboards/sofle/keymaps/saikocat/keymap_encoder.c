/* Function: encoder
 * -----------------
 * A rotary encoder is a device that you can twist to perform actions.
 * Some encoders can also be pushed, just like a button!
 * A rotary encoder twists clockwise and counter clockwise.
 * It lends itself to actions that you'd otherwise need to repeatedly press a button for,
 * and to actions that have both a forward and a reverse direction.
 *
 * Reference: https://docs.splitkb.com/hc/en-us/articles/360010513760-How-can-I-use-a-rotary-encoder-
 */

#ifdef ENCODER_ENABLE

#    include "features/rotary_encoder.h"

/* TODO: what if other func requires matrix_scan_user */
bool     is_alt_tab_active = false;
uint16_t alt_tab_timer     = 0;

void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) { /* 1250ms hold wait */
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

/* User defined func that will be called by QMK every time encoder is turned */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        fn_rotary_wins_tabbing(clockwise, &is_alt_tab_active, &alt_tab_timer);
    } else if (index == 1) {
        fn_rotary_scrolling(clockwise);
    }
    return true;
}

#endif

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

/* User defined func that will be called by QMK every time encoder is turned */
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        fn_rotary_wins_tabbing(clockwise);
    } else if (index == 1) {
        fn_rotary_scrolling(clockwise);
    }
    return true;
}

/* TODO: what if other func requires matrix_scan_user */
void matrix_scan_user(void) {
    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1250) { /* 1250ms hold wait */
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

#endif

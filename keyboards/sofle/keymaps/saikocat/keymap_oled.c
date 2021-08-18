#ifdef OLED_DRIVER_ENABLE

#    include "definitions.h"
#    include "features/pet_neko.h"

/* status variables */
uint8_t current_wpm;
led_t led_usb_state;

/* Function: Logos
 * ---------------
 */
static void render_logo(void) {
    // clang-format off
    /* 32x32 'awake' logo */
    static const char PROGMEM my_logo[] = {
        0x00, 0x40, 0x40, 0x80, 0x80, 0x04, 0x08, 0x10, 0x20, 0x00, 0xc0, 0x30, 0x08, 0x10, 0x60, 0x80,
        0x00, 0x80, 0x60, 0x10, 0x08, 0x30, 0xc0, 0x00, 0x10, 0x08, 0x04, 0x80, 0x80, 0x40, 0x40, 0x00,
        0x08, 0x08, 0x08, 0x08, 0x00, 0x01, 0x01, 0x00, 0x00, 0x7f, 0x80, 0x40, 0x40, 0x5c, 0x00, 0x01,
        0x41, 0x01, 0x00, 0x5c, 0x40, 0x40, 0x80, 0x7f, 0x00, 0x01, 0x01, 0x08, 0x08, 0x08, 0x08, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x40, 0x40, 0x80, 0xe1, 0x12, 0x0a, 0x06, 0x00,
        0x80, 0x00, 0x06, 0x0a, 0x12, 0xe1, 0x90, 0x48, 0x64, 0x92, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x18, 0x1f, 0x14, 0x14, 0x10, 0x10, 0x11, 0x1f, 0x10, 0x10, 0x18,
        0x0f, 0x18, 0x10, 0x10, 0x1f, 0x11, 0x10, 0x10, 0x14, 0x14, 0x1f, 0x18, 0x00, 0x00, 0x00, 0x00,
    };
    // clang-format on

    oled_write_raw_P(my_logo, sizeof(my_logo));
}

// clang-format off
/* 32 * 32 os logos */
static const char PROGMEM archlinux_logo[] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfe,
    0xfe, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xf8, 0xf9, 0xff, 0xff, 0xff,
    0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0xc0, 0xf0, 0xfc, 0xff, 0xff, 0xff, 0xff, 0x7f, 0x0f, 0x07, 0x07,
    0x07, 0x07, 0x0f, 0x7f, 0xff, 0xff, 0xff, 0xff, 0xfc, 0xf0, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x60, 0x78, 0x3c, 0x3f, 0x1f, 0x1f, 0x0f, 0x0f, 0x07, 0x07, 0x07, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x07, 0x07, 0x07, 0x0f, 0x0f, 0x1f, 0x1e, 0x3c, 0x3c, 0x78, 0x60, 0x00
};
// clang-format on

/* Function: Display
 * -----------------
 */
static void display_logo_narrow(void) {
    render_logo();

    oled_set_cursor(0, 7);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR(" GIT "), false);
    oled_write_P(PSTR(" GUD!"), false);
    oled_write_P(PSTR("-----"), false);
    oled_write_P(PSTR("\n"), false);

    oled_set_cursor(0, 14);
    /* wpm counter */
    // uint8_t n = get_current_wpm();
    uint8_t n = current_wpm;
    char    wpm_str[4];
    wpm_str[3] = '\0';
    wpm_str[2] = '0' + n % 10;
    wpm_str[1] = '0' + (n /= 10) % 10;
    wpm_str[0] = '0' + n / 10;
    oled_write(wpm_str, false);
    oled_set_cursor(0, 15);
    oled_write_P(PSTR(" wpm"), false);
}

static void display_status_narrow(void) {
    /* Display current mode */
    oled_set_cursor(0, 0);
    oled_write_raw_P(archlinux_logo, sizeof(archlinux_logo));

    oled_set_cursor(0, 5);

    switch (get_highest_layer(default_layer_state)) {
        case _BASE:
            oled_write_P(PSTR("QWERT"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("NAVIG"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("ADJST"), false);
            break;
        default:
            oled_write_P(PSTR("UNDEF"), false);
    }

    oled_set_cursor(0, 7);

    /* Display current layer */
    oled_write_P(PSTR("LAYER"), false);

    oled_set_cursor(0, 8);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_P(PSTR("Base "), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Symbl"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Nav  "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj  "), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }

    /* Caps lock */
    oled_set_cursor(0, 10);
    oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

    /* Pet rendering */
    pet_render(0, 12);
}

/* QMK rendering starts here
 * -------------------------
 */

oled_rotation_t oled_init_user(oled_rotation_t rotation) { return OLED_ROTATION_270; }

void oled_task_user(void) {
    current_wpm   = get_current_wpm();
    led_usb_state = host_keyboard_led_state();

    if (is_keyboard_master()) {
        display_status_narrow();
    } else {
        display_logo_narrow();
    }
}

/* Turn off oled when computer is sleeping - we put this in keymap.c instead */
/* void suspend_power_down_user(void) { oled_off(); } */

#endif
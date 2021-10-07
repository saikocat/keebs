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

#if defined(KEYBOARD_sofle)

// Sofle Layout Wrapper
#define LAYOUT_sofle_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_base_wrapper(k) LAYOUT_sofle_wrapper(k)
// clang-format off

/*
 * _QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | | \  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | LCTL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  | , <  |  . > |  / ? |ShfEnt|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | SH   | ESC  |LOWER | / SPACE /       \ ENTER\  | SPC   |  :   | RAlt | RGUI |
 *            |      |      | ALT  |      |/       /         \      \ | RSE   | ADJ  |      |      |
 *            `-----------------------------------'           '------''----------------------------'
 */
#define __LLY__QWERTY \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                       KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,       \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,       \
    KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                       KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,       \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,  KC_MUTE,    XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_LSFT), \
                    KC_LGUI, SH_MON, ESC_ALT, BSPC_LWR, KC_SPC,     KC_SFTENT, SPC_RSE, COLN_ADJ, KC_RALT, KC_RGUI

/*
 * _COLEMAK_DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | SH   | ESC  |LOWER | / SPACE /       \ ENTER\  | SPC   |  :   | RAlt | RGUI |
 *            |      |      | ALT  |      |/       /         \      \ | RSE   | ADJ  |      |      |
 *            `-----------------------------------'           '------''----------------------------'
 */
#define __LLY__COLEMAK_DH \
    KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSLS,   \
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,   \
    KC_LCTL, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,   \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, _______,    XXXXXXX, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, OSM(MOD_LSFT), \
                  KC_LGUI, SH_MON, ESC_ALT, BSPC_LWR,  KC_SPC,     KC_SFTENT, SPC_RSE, COLN_ADJ, KC_RALT, KC_RGUI

/*
 * _LOWER / _SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
#define __LLY__LOWER \
    _______,   _______, _______, _______, _______, _______,                      _______, _______, _______, _______, _______, _______, \
    _______,   KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_PIPE, KC_BSLS, _______, \
    _______,   KC_UNDS, KC_LBRC, KC_LPRN, KC_RPRN, KC_GRV,                       KC_DQUO, KC_LCBR, KC_RCBR, KC_RBRC, KC_EQL,  KC_DQUO, \
    KC_SFTENT, KC_EQL,  KC_RBRC, KC_PLUS, KC_MINS, KC_TILD, _______,    _______, KC_ASTR, KC_PLUS, KC_LT,   KC_GT,   KC_QUES, _______, \
                        _______, _______, SH_MON,  _______, _______,    _______, _______, _______, _______, _______

/*
 * _RAISE / _NAVIGATION
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

#define __LLY__RAISE \
    _______, _______,    _______,    _______,    _______,    _______,                             _______,     _______,         _______,    _______, _______, _______, \
    _______, KC_PSCR,    KC_ESC,     LCTL(KC_F), KC_TAB,     KC_INS,                              DF(_QWERTY), DF(_COLEMAK_DH), DF(_RAISE), XXXXXXX, _______, KC_DEL,  \
    _______, KC_LSFT,    KC_LGUI,    KC_LALT,    KC_LCTL,    KC_CAPS,                             KC_LEFT,     KC_DOWN,         KC_UP,      KC_RGHT, KC_F11,  KC_LCTL, \
    _______, LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_TAB), _______,      _______, KC_HOME,     KC_PGDN,         KC_PGUP,    KC_END,  KC_F12,  _______, \
                                         _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______

/*
* _ADJUST
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
* |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*            |      |      |      |      | /       /       \      \  |      |      |      |      |
*            |      |      |      |      |/       /         \      \ |      |      |      |      |
*            `----------------------------------'           '------''---------------------------'
*/

#define __LLY__ADJUST \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, KC_PAST, KC_7,    KC_8,    KC_9,    KC_PMNS,                      DF(_QWERTY),     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_BSPC, \
    _______, KC_PEQL, KC_4,    KC_5,    KC_6,    KC_PPLS,                      DF(_COLEMAK_DH), KC_F4,   KC_F5,   KC_F6,   KC_F11,  _______, \
    _______, KC_P0,   KC_1,    KC_2,    KC_3,    KC_PSLS, XXXXXXX,    XXXXXXX, DF(_RAISE),      KC_F1,   KC_F2,   KC_F3,   KC_F12,  KC_LGUI, \
                  _______, _______,  KC_0,       _______, _______,    _______, _______, _______, _______, _______


/*
* _SPECIAL
* ,-----------------------------------------.                    ,-----------------------------------------.
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |                    |      |      |      |      |      |      |
* |------+------+------+------+------+------|                    |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
* |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
* |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
* `-----------------------------------------/       /     \      \-----------------------------------------'
*            |      |      |      |      | /       /       \      \  |      |      |      |      |
*            |      |      |      |      |/       /         \      \ |      |      |      |      |
*            `----------------------------------'           '------''---------------------------'
*/

#define __LLY__SPECIAL \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, CG_TOGG,                                            XXXXXXX, KC_RCTL, KC_RALT, KC_RGUI, KC_RSFT, XXXXXXX, \
    _______, C_S_T(KC_Z), C_S_T(KC_X), C_S_T(KC_C), C_S_T(KC_V), C_S_T(KC_TAB), XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                                            _______, _______, _______, _______, _______,    _______, _______, _______, _______, _______
// clang-format on

#endif

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


// clang-format off

/* ,-----------------------------------------.                ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                |  Y   |  U   |  I   |  O   |  P   | BSPC |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | GESC |  A   |  S   |  D   |  F   |  G   |                |  H   |  J   |  K   |  L   | ; :  | ' "  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |SFTENT|  Z   |  X   |  C   |  V   |  B   |                |  N   |  M   | , <  | . >  | / ?  |OS_SFT|
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             | ALT  | LWR  |      |  |RSFT_T| RSE  | ADJ  |
 *                             | ESC  | BSPC | SPC  |  | ENT  | SPC  | COL  |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__QWERTY \
    KC_TAB,  _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________, KC_BSPC,  \
    KC_LCTL, _________________QWERTY_L2_________________,        _________________QWERTY_R2_________________, QUOT_CTL, \
    KC_LSFT, _________________QWERTY_L3_________________,        _________________QWERTY_R3_________________, KC_DEL,   \
             ______________3x3_THUMBCLUSTER_L___________,        ______________3x3_THUMBCLUSTER_R___________


#define __LAYOUT_SPLIT_3x6_3__QWERTY__HR \
    KC_TAB,  _________________QWERTY_L1_________________,        _________________QWERTY_R1_________________, KC_BSPC,  \
    KC_LCTL, KC_A,  ALT_S, SFT_D, CTL_F, KC_G,                   KC_H, CTL_J, SFT_K,   ALT_L,  KC_SCLN,       QUOT_CTL, \
    KC_LSFT, GUI_Z, KC_X,  KC_C,  KC_V,  KC_B,                   KC_N, KC_M,  KC_COMM, KC_DOT, GUI_SLSH,      KC_DEL,   \
             ______________3x3_THUMBCLUSTER_L___________,        ______________3x3_THUMBCLUSTER_R___________



/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  Q   |  W   |  F   |  P   |  B   |                |  J   |  L   |  U   |  Y   | ; :  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  A   |  R   |  S   |  T   |  G   |                |  M   |  N   |  E   |  I   |  O   | ' "  |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  Z   |  X   |  C   |  D   |  V   |                |  K   |  H   | , <  | . >  | / ?  |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__COLEMAK_DH \
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,        ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,  \
    KC_LCTL, ______________COLEMAK_MOD_DH_L2____________,        ______________COLEMAK_MOD_DH_R2____________, QUOT_CTL, \
    KC_LSFT, ______________COLEMAK_MOD_DH_L3____________,        ______________COLEMAK_MOD_DH_R3____________, KC_DEL,   \
             ______________3x3_THUMBCLUSTER_L___________,        ______________3x3_THUMBCLUSTER_R___________


#define __LAYOUT_SPLIT_3x6_3__COLEMAK_DH__HR \
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,        ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,  \
    KC_LCTL, KC_A,  ALT_R, SFT_S, CTL_T, KC_G,                   KC_M, CTL_N, SFT_E,   ALT_I,   KC_O,         QUOT_CTL, \
    KC_LSFT, GUI_Z, KC_X,  KC_C,  KC_D,  KC_V,                   KC_K, KC_H,  KC_COMM, KC_DOT,  GUI_SLSH,     KC_DEL,   \
             ______________3x3_THUMBCLUSTER_L___________,        ______________3x3_THUMBCLUSTER_R___________


/* ,-----------------------------------------.                ,-----------------------------------------.
 * | TAB  |  Q   |  W   |  E   |  R   |  T   |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | GESC |  A   |  S   |  D   |  F   |  G   |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * | SFT  |  Z   |  X   |  C   |  V   |  B   |                |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             | SH   | SPC  |GNUMB |  |RSFT_T| RSE  |      |
 *                             |      |      |      |  | ENT  | SPC  |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__GAME \
    KC_TAB,  _________________QWERTY_L1_________________,        ___________________BLANK___________________, _______,   \
    KC_LCTL, _________________QWERTY_L2_________________,        ___________________BLANK___________________, _______,   \
    KC_LSFT, _________________QWERTY_L3_________________,        ___________________BLANK___________________, A(KC_TAB), \
                           SH_MON, KC_SPC, MO(_GAME_NUM),        ______________3x3_THUMBCLUSTER_R___________



/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC  |      |  @   |  $   |  #   |      |                |      |  &   |  ^   |   *  |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  [   |  (   |  "   |  )   |  `   |                |  +   |  {   |  =   |   }  |  ]   |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  ~   |  !   |  %   |  -   |      |                |      |  _   |  |   |  \|  |  '   |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__LOWER \
    KC_ESC,    _________________SYMBOL_L1_________________,        _________________SYMBOL_R1_________________, _______, \
    _______,   _________________SYMBOL_L2_________________,        _________________SYMBOL_R2_________________, KC_DQUO, \
    KC_SFTENT, _________________SYMBOL_L3_________________,        _________________SYMBOL_R3_________________, _______, \
                                  SH_MON, _______, _______,        _______, MO(_SYMNUM), _______



/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |G(SPC)|                | DF(0)| DF(1)| DF(3)| DF(6)| PSCR |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |PRVWRD|NXTWRD| CTAB | PTAB | ATAB |                | LEFT | DOWN |  UP  | RIGHT| INS  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      | C(Z) | C(X) | C(C) | ATAB | C(V) |                | HOME | PGDN | PGUP | END  |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |  SFT |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__RAISE \
    _______, _________________RAISE_L1__________________,        _________________RAISE_R1__________________, KC_DEL,  \
    KC_LCTL, _________________RAISE_L2__________________,        _________________RAISE_R2__________________, KC_LCTL, \
    KC_LSFT, _________________RAISE_L3__________________,        _________________RAISE_R3__________________, _______, \
                               KC_LALT, _______, _______,        KC_RSFT, _______, _______



/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |      |      |      |      |      |                |      |  F7  |  F8  |  F9  |  F10 |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |TB_SCR|TB_MCL|TB_RCL|TB_LCL|      |                |      |  F4  |  F5  |  F6  |  F11 |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      | C(Z) | C(X) | C(C) | C(V) |      |                |      |  F1  |  F2  |  F3  |  F12 |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__ADJUST \
    _______, _________________ADJUST_L1_________________,        _________________ADJUST_R1_________________,  KC_BSPC, \
    _______, _________________ADJUST_L2_________________,        _________________ADJUST_R2_________________,  KC_SPC,  \
    _______, _________________ADJUST_L3_________________,        _________________ADJUST_R3_________________,  KC_RGUI, \
                               _______, _______, _______,        _______, _______, _______



/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      | RESET|EEPRST|      |      |      |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |EHLEFT|EHRGHT| CG_TG|                |      | CTRL | SFT  |  ALT | RGUI |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__SPECIAL \
    _______, RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, EH_LEFT, EH_RGHT, CG_TOGG,         XXXXXXX, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               _______, _______, _______,         _______, _______, _______


/* ,-----------------------------------------.                ,-----------------------------------------.
 * | ESC  | C(3) | C(2) | C(1) | C(0) | C(4) |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  3   |  2   |  1   |  0   |  4   |                |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |SFTENT|  F3  |  F2  |  F1  |  F4  |  F5  |                |      |      |      |      |      |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |RSFT_T| RSE  |      |
 *                             |      |      |      |  | ENT  | SPC  |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__GAME_NUM \
    KC_ESC,    C(KC_3), C(KC_2), C(KC_1), C(KC_0), C(KC_4),        DF(_QWERTY), DF(_COLEMAK_DH), DF(_RAISE), DF(_GAME),  KC_PSCR, _______, \
    KC_LCTL,   ________________NUMBER_LEFT_BEAKL__________,        ___________________BLANK___________________, _______, \
    KC_SFTENT, KC_F3,   KC_F2,   KC_F1,   KC_F4,   KC_F5,          ___________________BLANK___________________, _______, \
                                 _______, _______, _______,        ______________3x3_THUMBCLUSTER_R___________


/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      | C(3) | C(2) | C(1) | C(0) | C(4) |                |      |   7  |   8  |   9  |   =  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  3   |  2   |  1   |  0   |  4   |                |   *  |   4  |   5  |   6  |   +  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  7   |  6   |  5   |  9   |  8   |                |   /  |   1  |   2  |   3  |   -  |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |   0  |   .  |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__NUM \
    _______, C(KC_3), C(KC_2), C(KC_1), C(KC_0), C(KC_4),      ________________NUMPAD_TOP_________________,  KC_BSPC, \
    _______, ________________NUMBER_LEFT_BEAKL__________,      ________________NUMPAD_MID_________________,  _______, \
    _______, ________________NUMBER_RIGHT_BEAKL_________,      ________________NUMPAD_BOT_________________,  _______, \
                               _______, _______, _______,      ________________NUMPAD_THUMB_______________


/* ,-----------------------------------------.                ,-----------------------------------------.
 * |      |  1   |  2   |  3   |  4   |  5   |                |   6  |   7  |   8  |   9  |   0  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |  !   |  @   |  #   |  $   |  %   |                |   ^  |   &  |   *  |  (   |   )  |      |
 * |------+------+------+------+------+------|                |------+------+------+------+------+------|
 * |      |      |      |  {   |  }   |      |                |      |  [   |   ]  |  -_  |  =+  |      |
 * `------+------+------+------+------+------+------.  ,------+------+------+------+------+------+------'
 *                             |      |      |      |  |      |      |      |
 *                             `--------------------'  `--------------------'
 */
#define __LAYOUT_SPLIT_3x6_3__SYMNUM \
    _______, ________________NUMBER_LEFT________________,        ________________NUMBER_RIGHT_______________,  _______, \
    _______, ________________SYMBOL_LEFT________________,        ________________SYMBOL_RIGHT_______________,  _______, \
    _______, _______, _______, KC_LCBR, KC_RCBR, _______,        _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,   _______, \
                               _______, _______, _______,        _______,  _______, _______

// clang-format on

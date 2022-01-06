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

#define LAYOUT_kyria_wrapper(...) LAYOUT(__VA_ARGS__)

#if defined(KEYBOARD_splitkb_kyria)
#    define LAYOUT_base_wrapper(k) LAYOUT_kyria_wrapper(k)
#endif

// clang-format off

#define ________LAYOUT_KYRIA_THUMBCLUSTER_L________    _______,   ESC_ALT, MO(_LOWER), KC_SPC,   BSPC_NUM
#define ________LAYOUT_KYRIA_THUMBCLUSTER_R________    KC_SFTENT, KC_SPC,  MO(_RAISE), COLN_ADJ, _______

/*
 * Base Layer: QWERTY
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |  Del   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC/ | LOWER| Space| NUM  |  |SFTENT| Space| RAISE| COLN |      |
 *                        |      | ALT  |      |      |      |  |      |      |      | ADJ  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__QWERTY \
    KC_TAB,  _________________QWERTY_L1_________________,                                      _________________QWERTY_R1_________________, KC_BSPC,  \
    KC_LCTL, _________________QWERTY_L2_________________,                                      _________________QWERTY_R2_________________, QUOT_CTL  \
    KC_LSFT, _________________QWERTY_L3_________________, _______, _______, _______, _______,  _________________QWERTY_R3_________________, KC_DEL,   \
                               ________LAYOUT_KYRIA_THUMBCLUSTER_L________, ________LAYOUT_KYRIA_THUMBCLUSTER_R________


#define __LAYOUT_KYRIA__QWERTY__HR \
    KC_TAB,  _________________QWERTY_L1_________________,                                     _________________QWERTY_R1_________________, KC_BSPC,  \
    KC_LCTL, KC_A,  ALT_S, SFT_D, CTL_F, KC_G,                                                KC_H,  CTL_J, SFT_K,   ALT_L,  KC_SCLN,      QUOT_CTL, \
    KC_LSFT, GUI_Z, KC_X,  KC_C,  KC_V,  KC_B,            _______, _______, _______, _______, KC_N, KC_M,  KC_COMM, KC_DOT, GUI_SLSH,      KC_DEL,   \
                               ________LAYOUT_KYRIA_THUMBCLUSTER_L________, ________LAYOUT_KYRIA_THUMBCLUSTER_R________

/*
 * Base Layer: Colemak DH
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   F  |   P  |   B  |                              |   J  |   L  |   U  |   Y  | ;  : |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Ctrl/Esc|   A  |   R  |   S  |   T  |   G  |                              |   M  |   N  |   E  |   I  |   O  |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   D  |   V  |      |      |  |      |      |   K  |   H  | ,  < | . >  | /  ? | Del    |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | ESC/ | LOWER| Space| NUM  |  |SFTENT| Space| RAISE| COLN |      |
 *                        |      | ALT  |      |      |      |  |      |      |      | ADJ  |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__COLEMAK_DH \
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,                                     ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,  \
    KC_LCTL, ______________COLEMAK_MOD_DH_L2____________,                                     ______________COLEMAK_MOD_DH_R2____________, QUOT_CTL, \
    KC_LSFT, ______________COLEMAK_MOD_DH_L3____________, _______, _______, _______, _______, ______________COLEMAK_MOD_DH_R3____________, KC_DEL,   \
                               ________LAYOUT_KYRIA_THUMBCLUSTER_L________, ________LAYOUT_KYRIA_THUMBCLUSTER_R________


#define __LAYOUT_KYRIA__COLEMAK_DH__HR \
    KC_TAB,  ______________COLEMAK_MOD_DH_L1____________,                          ______________COLEMAK_MOD_DH_R1____________, KC_BSPC,  \
    KC_LCTL, KC_A,  ALT_R, SFT_S, CTL_T, KC_G,                                     KC_M, CTL_N, SFT_E,   ALT_I,   KC_O,         QUOT_CTL, \
    KC_LSFT, GUI_Z, KC_X,  KC_C,  KC_D,  KC_V, _______, _______, _______, _______, KC_K, KC_H,  KC_COMM, KC_DOT,  GUI_SLSH,     KC_DEL,   \
                    ________LAYOUT_KYRIA_THUMBCLUSTER_L________, ________LAYOUT_KYRIA_THUMBCLUSTER_R________


/* 
 * Base Layer: Game
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |                              |   Y  |   U  |   I  |   O  |   P  |  Bksp  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * | LCtrl  |   A  |   S  |   D  |   F  |   G  |                              |   H  |   J  |   K  |   L  | ;  : |Ctrl/' "|
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   Z  |   X  |   C  |   V  |   B  |      |      |  |      |      |   N  |   M  | ,  < | . >  | /  ? |  Del   |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      | SH   | LOWER| Space| GNUM |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__GAME \
    KC_TAB,   _________________QWERTY_L1_________________,                                     ___________________BLANK___________________, _______,   \
    KC_LCTL,  _________________QWERTY_L2_________________,                                     ___________________BLANK___________________, _______,   \
    KC_LSFT,  _________________QWERTY_L3_________________, _______, _______, _______, _______, ___________________BLANK___________________, A(KC_TAB), \
                      _______, SH_MON, MO(_GAME_NUM), KC_SPC, MO(_GAME_NUM), ________LAYOUT_KYRIA_THUMBCLUSTER_R________



/*
 * Sym Layer: Symbol / Lower
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ESC   |      |  @   |  $   |  #   |      |                              |      |  &   |  ^   |   *  |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  [   |  (   |  "   |  )   |  `   |                              |  +   |  {   |  =   |   }  |  ]   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  ~   |  !   |  %   |  -   |      |      |      |  |      |      |      |  _   |  |   |  \|  |  '   |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__LOWER \
    KC_ESC,    _________________SYMBOL_L1_________________,                                     _________________SYMBOL_R1_________________, _______, \
    _______,   _________________SYMBOL_L2_________________,                                     _________________SYMBOL_R2_________________, _______, \
    KC_SFTENT, _________________SYMBOL_L3_________________, _______, _______, _______, _______, _________________SYMBOL_R3_________________, _______, \
                                 _______, SH_MON,  _______, _______, _______, _______, _______, MO(_SYMNUM), _______, _______


/*
 * Nav Layer: Navigation / Raise
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |G(SPC)|                              | DF(0)| DF(1)| DF(3)| DF(6)| PSCR |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |PRVWRD|NXTWRD| CTAB | PTAB | ATAB |                              | LEFT | DOWN |  UP  | RIGHT| INS  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | C(Z) | C(X) | C(C) | ATAB | C(V) |      |      |  |      |      | HOME | PGDN | PGUP | END  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__RAISE \
    _______, _________________RAISE_L1__________________,                                     _________________RAISE_R1__________________, KC_DEL,  \
    KC_LCTL, _________________RAISE_L2__________________,                                     _________________RAISE_R2__________________, KC_LCTL, \
    KC_LSFT, _________________RAISE_L3__________________, _______, _______, _______, _______, _________________RAISE_R3__________________, _______, \
                               _______, KC_LALT, _______, _______, _______, KC_RSFT, _______, _______, _______, _______


/*
 * Number Layer: Number
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | C(3) | C(2) | C(1) | C(0) | C(4) |                              |      |   7  |   8  |   9  |   =  |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  3   |  2   |  1   |  0   |  4   |                              |   *  |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  7   |  6   |  5   |  9   |  8   |      |      |  |      |      |   /  |   1  |   2  |   3  |   -  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |  .   |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__NUM \
    _______, C(KC_3), C(KC_2), C(KC_1), C(KC_0), C(KC_4),                                     ________________NUMPAD_TOP_________________,  KC_BSPC, \
    _______, ________________NUMBER_LEFT_BEAKL__________,                                     ________________NUMPAD_MID_________________,  _______, \
    _______, ________________NUMBER_RIGHT_BEAKL_________, _______, _______, _______, _______, ________________NUMPAD_BOT_________________,  _______, \
                              _______, _______,  _______, _______, _______, KC_SPC, ________________NUMPAD_THUMB_______________, _______


/*
 * Sym Layer: Numbers and symbols
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  1   |  2   |  3   |  4   |  5   |                              |   6  |  7   |  8   |  9   |  0   |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  !   |  @   |  #   |  $   |  %   |                              |   ^  |  &   |  *   |  (   |  )   |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |  {   |  }   |      |      |      |  |      |      |  [   |   ]  |  -_  |  =+  |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__SYMNUM \
    _______, ________________NUMBER_LEFT________________,                                     ________________NUMBER_RIGHT_______________,  _______, \
    _______, ________________SYMBOL_LEFT________________,                                     ________________SYMBOL_RIGHT_______________,  _______, \
    _______, _______, _______, KC_LCBR, KC_RCBR, _______, _______, _______, _______, _______, _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL,   _______, \
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______



/*
 * Adjust/Function Layer: Function keys
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |  F7  |  F8  |  F9  |  F10 |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |TB_SCR|TB_MCL|TB_RCL|TB_LCL|      |                              |      |  F4  |  F5  |  F6  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | C(Z) | C(X) | C(C) | C(V) |      |      |      |  |      |      |      |  F1  |  F2  |  F3  |  F12 |        |
 * `--------+------+------+------+------+------+-------------.  ,------+------+------+------+------+------+---------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__ADJUST \
    _______, _________________ADJUST_L1_________________,                                     _________________ADJUST_R1_________________,  KC_BSPC, \
    _______, _________________ADJUST_L2_________________,                                     _________________ADJUST_R2_________________,  KC_SPC,  \
    _______, _________________ADJUST_L3_________________, _______, _______, _______, _______, _________________ADJUST_R3_________________,  KC_RGUI, \
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


/*
 * Special Layer: Reset and boot magic toggle
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | RESET|EEPRST|      |      |      |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |EHLEFT|EHRGHT| CG_TG|                              |      | CTRL | SFT  |  ALT | RGUI |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__SPECIAL \
    _______, RESET,   EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, EH_LEFT, EH_RGHT, CG_TOGG,                                     XXXXXXX, KC_RCTL, KC_RSFT, KC_LALT, KC_RGUI, XXXXXXX, \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______


/*
 * Game Layer: Game Num
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   ESC  | C(3) | C(2) | C(1) | C(0) | C(4) |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  3   |  2   |  1   |  0   |  4   |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | SFTENT |  F3  |  F2  |  F1  |  F4  |  F5  |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
#define __LAYOUT_KYRIA__GAME_NUM \
    KC_ESC,    C(KC_3), C(KC_2), C(KC_1), C(KC_0), C(KC_4),                                     DF(_QWERTY), DF(_COLEMAK_DH), DF(_RAISE), DF(_GAME),  KC_PSCR, _______, \
    KC_LCTL,   ________________NUMBER_LEFT_BEAKL__________,                                     ___________________BLANK___________________, _______, \
    KC_SFTENT, KC_F3,   KC_F2,   KC_F1,   KC_F4,   KC_F5,   _______, _______, _______, _______, ___________________BLANK___________________, _______, \
                                 _______, _______, _______, _______, _______, ________LAYOUT_KYRIA_THUMBCLUSTER_R________



// /*
//  * Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
//     ),

// clang-format on

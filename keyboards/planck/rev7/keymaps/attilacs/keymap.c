/* Copyright 2015-2023 Jack Humbert
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

#include QMK_KEYBOARD_H

enum planck_layers { _COLEMAK, _QWERTY, _LOWER, _RAISE, _NUMBERS, _ADJUST, _NUMPAD, _NAV };

enum planck_keycodes { COLEMAK = SAFE_RANGE, QWERTY, BACKLIT };

#define LOWER MO(_LOWER)
#define NAV LT(_NAV, KC_ESC)
#define NUMBERS MO(_NUMBERS)
#define NUMPAD TG(_NUMPAD)
#define RAISE MO(_RAISE)

/* Unicode */
#define AACUTE UP(A_ACUTE_LOWER, A_ACUTE_UPPER)
#define ADIAERESIS UP(A_DIAERESIS_LOWER, A_DIAERESIS_UPPER)
#define EACUTE UP(E_ACUTE_LOWER, E_ACUTE_UPPER)
#define IACUTE UP(I_ACUTE_LOWER, I_ACUTE_UPPER)
#define OACUTE UP(O_ACUTE_LOWER, O_ACUTE_UPPER)
#define ODACUTE UP(O_DOUBLE_ACUTE_LOWER, O_DOUBLE_ACUTE_UPPER)
#define ODIAERESIS UP(O_DIAERESIS_LOWER, O_DIAERESIS_UPPER)
#define SHARPS UM(S_SHARP)
#define UACUTE UP(U_ACUTE_LOWER, U_ACUTE_UPPER)
#define UDACUTE UP(U_DOUBLE_ACUTE_LOWER, U_DOUBLE_ACUTE_UPPER)
#define UDIAERESIS UP(U_DIAERESIS_LOWER, U_DIAERESIS_UPPER)

enum unicode_names {
    A_ACUTE_LOWER,        // á
    A_ACUTE_UPPER,        // Á
    A_DIAERESIS_LOWER,    // ä
    A_DIAERESIS_UPPER,    // Ä
    E_ACUTE_LOWER,        // é
    E_ACUTE_UPPER,        // É
    I_ACUTE_LOWER,        // í
    I_ACUTE_UPPER,        // Í
    O_ACUTE_LOWER,        // ó
    O_ACUTE_UPPER,        // Ó
    O_DOUBLE_ACUTE_LOWER, // ő
    O_DOUBLE_ACUTE_UPPER, // Ő
    O_DIAERESIS_LOWER,    // ö
    O_DIAERESIS_UPPER,    // Ö
    S_SHARP,              // ß
    U_ACUTE_LOWER,        // ú
    U_ACUTE_UPPER,        // Ú
    U_DOUBLE_ACUTE_LOWER, // ű
    U_DOUBLE_ACUTE_UPPER, // Ű
    U_DIAERESIS_LOWER,    // ü
    U_DIAERESIS_UPPER,    // Ü
};

const uint32_t PROGMEM unicode_map[] = {
    [A_ACUTE_LOWER]        = 0x00E1, // á
    [A_ACUTE_UPPER]        = 0x00C1, // Á
    [A_DIAERESIS_LOWER]    = 0x00E4, // ä
    [A_DIAERESIS_UPPER]    = 0x00C4, // Ä
    [E_ACUTE_LOWER]        = 0x00E9, // é
    [E_ACUTE_UPPER]        = 0x00C9, // É
    [I_ACUTE_LOWER]        = 0x00ED, // í
    [I_ACUTE_UPPER]        = 0x00CD, // Í
    [O_ACUTE_LOWER]        = 0x00F3, // ó
    [O_ACUTE_UPPER]        = 0x00D3, // Ó
    [O_DOUBLE_ACUTE_LOWER] = 0x0151, // ő
    [O_DOUBLE_ACUTE_UPPER] = 0x0150, // Ő
    [O_DIAERESIS_LOWER]    = 0x00F6, // ö
    [O_DIAERESIS_UPPER]    = 0x00D6, // Ö
    [S_SHARP]              = 0x00DF, // ß
    [U_ACUTE_LOWER]        = 0x00FA, // ú
    [U_ACUTE_UPPER]        = 0x00DA, // Ú
    [U_DOUBLE_ACUTE_LOWER] = 0x0171, // ű
    [U_DOUBLE_ACUTE_UPPER] = 0x0170, // Ű
    [U_DIAERESIS_LOWER]    = 0x00FC, // ü
    [U_DIAERESIS_UPPER]    = 0x00DC, // Ü
};

/* Tap dance */
#define TDALT TD(TD_ALT)

// Tap Dance declarations
enum {
    TD_ALT,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Alt, twice for AltGr
    [TD_ALT] = ACTION_TAP_DANCE_DOUBLE(KC_LALT, KC_RALT),
};

/* clang-format off */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Colemak-DH
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | NAV  |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |TDAlt |      |Lower |Space | Nums |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
    NAV,     KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, TDALT,   XXXXXXX, LOWER,   KC_SPC,  NUMBERS, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | GUI  |TDAlt |      |Lower |Space | Nums |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL, KC_LGUI, TDALT,   XXXXXXX, LOWER,   KC_SPC,  NUMBERS, RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |   \  |   |  |   _  |   +  |      |      |   {  |   }  |   -  |   =  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   ^  |   @  |   $  |   %  |      |   #  |   [  |   ]  |   (  |   )  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   !  |   *  |   `  |   '  |   ~  |   &  |   "  |   <  |   >  |   ?  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Space |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______, KC_BSLS, KC_PIPE, KC_UNDS, KC_PLUS, XXXXXXX, XXXXXXX, KC_LCBR, KC_RCBR, KC_MINS, KC_EQL,  _______,
    _______, KC_CIRC, KC_AT,   KC_DLR,  KC_PERC, XXXXXXX, KC_HASH, KC_LBRC, KC_RBRC, KC_LPRN, KC_RPRN, _______,
    _______, KC_EXLM, KC_ASTR, KC_GRV,  KC_QUOT, KC_TILD, KC_AMPR, KC_DQUO, KC_LABK, KC_RABK, KC_QUES, _______,
    _______, _______, _______, _______, _______, _______, KC_SPC,  _______, _______, _______, _______, _______
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |   Ű  |   Ú  |   Ü  |   Ö  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |   Ä  |   ß  |   Á  |      |      |   Ő  |   É  |   Í  |   Ó  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, _______, _______,    _______, _______, _______, _______, UDACUTE, UACUTE,  UDIAERESIS, ODIAERESIS, _______,
    _______, AACUTE,  ADIAERESIS, SHARPS,  _______, _______, _______, ODACUTE, EACUTE,  IACUTE,     OACUTE,     _______,
    _______, DM_REC1, DM_REC2,    DM_PLY1, DM_PLY2, DM_RSTP, _______, DM_PLY1, DM_PLY2, _______,    _______,    _______,
    _______, _______, _______,    _______, _______, _______, _______, _______, _______, _______,    _______,    _______
),

/* Numbers
 * ,-----------------------------------------------------------------------------------.
 * |      | F1   | F2   | F3   | F4   | F5   | F6   | F7   | F8   | F9   | F10  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  1   |  2   |  3   |  4   |  5   |  6   |  7   |  8   |  9   |  0   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  *   |  x   | Down | F11  |  -   |  +   | F12  | Up   |  .   |  /   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMBERS] = LAYOUT_planck_grid(
    _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  _______,
    _______, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______,
    _______, KC_ASTR, KC_X,    KC_DOWN, KC_F11,  KC_MINS, KC_PLUS, KC_F12,  KC_UP,   KC_DOT,  KC_SLSH, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DB_TOGG, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, KC_DEL ,
    _______, EE_CLR,  MU_NEXT, AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, _______, _______,
    UC_NEXT, AU_PREV, AU_NEXT, MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, UC_NEXT,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

/* Numpad
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      | NUML |  7   |  8   |  9   |  -   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  4   |  5   |  6   |  +   | PENT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |  1   |  2   |  3   |  *   |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |Numpad|  0   |      |  .   |  /   |      |
 * `-----------------------------------------------------------------------------------'
 */
[_NUMPAD] = LAYOUT_planck_grid(
    _______, _______, _______, _______, _______, _______, KC_NUM,  KC_P7, KC_P8,   KC_P9,   KC_PMNS, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_P4, KC_P5,   KC_P6,   KC_PPLS, KC_PENT,
    _______, _______, _______, DM_PLY1, DM_PLY2, _______, _______, KC_P1, KC_P2,   KC_P3,   KC_PAST, _______,
    _______, _______, _______, _______, _______, _______, NUMPAD,  KC_P0, XXXXXXX, KC_PDOT, KC_PSLS, _______
),

/* NAV
 * ,-----------------------------------------------------------------------------------.
 * |      |Mouse1| MUp  |Mouse2| MWhUp|      |Insert| Home |      | Print|PageUp| Del  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MLeft| MDown|MRight| MWhDw|      | Left | Down | Up   | Right|PageDw|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | MWhL |Mouse3| MWhR |      |      | MPlay| End  | VolUp|VolDwn| Mute |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | CAPSL| MPrev|      |      | MNext|
 * `-----------------------------------------------------------------------------------'
 */
[_NAV] = LAYOUT_planck_grid(
    _______, KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U, _______, KC_INS,  KC_HOME, XXXXXXX, KC_PSCR,  KC_PGUP, KC_DEL,
    _______, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_PGDN, _______,
    _______, KC_WH_L, KC_BTN3, KC_WH_R, _______, _______, KC_MPLY, KC_END,  KC_VOLD, KC_VOLU,  KC_MUTE, _______,
    _______, _______, _______, _______, CW_TOGG, _______, NUMPAD,  KC_CAPS, KC_MPRV, _______,  _______, KC_MNXT
),

};
/* clang-format on */

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
            break;
        case QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
            break;
        case BACKLIT:
            if (record->event.pressed) {
                register_code(KC_RSFT);
            } else {
                unregister_code(KC_RSFT);
            }
            return false;
            break;
    }
    return true;
}

/* clang-format off */
float melody[8][2][2] = {
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
    {{440.0f, 8}, {440.0f, 24}},
};
/* clang-format on */

#define JUST_MINOR_THIRD 1.2
#define JUST_MAJOR_THIRD 1.25
#define JUST_PERFECT_FOURTH 1.33333333
#define JUST_TRITONE 1.42222222
#define JUST_PERFECT_FIFTH 1.33333333

#define ET12_MINOR_SECOND 1.059463
#define ET12_MAJOR_SECOND 1.122462
#define ET12_MINOR_THIRD 1.189207
#define ET12_MAJOR_THIRD 1.259921
#define ET12_PERFECT_FOURTH 1.33484
#define ET12_TRITONE 1.414214
#define ET12_PERFECT_FIFTH 1.498307

deferred_token tokens[8];

uint32_t reset_note(uint32_t trigger_time, void *note) {
    *(float*)note = 440.0f;
    return 0;
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    cancel_deferred_exec(tokens[index]);
    if (clockwise) {
        melody[index][1][0] = melody[index][1][0] * ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] / ET12_PERFECT_FIFTH;
        audio_play_melody(&melody[index], 2, false);
    } else {
        melody[index][1][0] = melody[index][1][0] / ET12_MINOR_SECOND;
        melody[index][0][0] = melody[index][1][0] * ET12_TRITONE;
        audio_play_melody(&melody[index], 2, false);
    }
    tokens[index] = defer_exec(1000, reset_note, &melody[index][1][0]);
    return false;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
#ifdef AUDIO_ENABLE
            static bool play_sound = false;
#endif
            if (active) {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                }
#endif
                layer_on(_ADJUST);
            } else {
#ifdef AUDIO_ENABLE
                if (play_sound) {
                }
#endif
                layer_off(_ADJUST);
            }
#ifdef AUDIO_ENABLE
            play_sound = true;
#endif
            break;
        }
    }
    return true;
}

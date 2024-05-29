/* Copyright 2015-2021 Jack Humbert
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

enum planck_layers {
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl | Alt  | GUI  |   -  |Lower |    Space    |Raise |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_ortho_4x12(
    KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_TAB,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_ENT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT ,
    KC_LCTL, KC_LALT, KC_LGUI, KC_MINS, LOWER,   KC_SPC,  KC_SPC,  RAISE,   _______, _______, _______, _______
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |      |      |  Up  |      | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |  F7  |  F8  |  F9  | F10  | F11  | F12  |      | Left | Down |Right |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|      |      |      |      |      |      |      |      |      |      |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt | GUI  |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
     KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______, _______, KC_UP,   _______,  KC_BSPC,
     KC_TAB,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______, KC_LEFT, KC_DOWN, KC_RIGHT, KC_ENT,
     KC_LSFT, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  KC_RSFT,
     KC_LCTL, KC_LALT, KC_LGUI, _______, _______, KC_SPC,  KC_SPC,  _______, _______, _______, _______,  _______
 ),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |WHDown|  MS1 | MSUp |  MS2 | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   7  |   8  |   9  |   0  |   -  |   ~  | WHUp |MSLeft|MSDown|MSRight|Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   @  |   [  |   ]  |   \  |   |  |   :  |      |  MS4 |  MS3 |  MS5 |Shift |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |  Alt |  GUI |      |      |    Space    |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
     KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_MS_WH_DOWN, KC_MS_BTN1, KC_MS_UP,   KC_MS_BTN2,  KC_BSPC,
     KC_TAB,  KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_MS_WH_UP,   KC_MS_LEFT, KC_MS_DOWN, KC_MS_RIGHT, KC_ENT,
     KC_LSFT, KC_LBRC, KC_RBRC, KC_NUHS, KC_INT1, KC_INT3, KC_QUOT, _______,       KC_MS_BTN4, KC_MS_BTN3, KC_MS_BTN5,  KC_RSFT,
     KC_LCTL, KC_LALT, KC_LGUI, KC_NUHS, _______, KC_SPC,  KC_SPC,  _______,       _______,    _______,    _______,     _______
),

/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_ortho_4x12(
    _______, QK_BOOT, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL ,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

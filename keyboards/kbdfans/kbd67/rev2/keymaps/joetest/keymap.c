/*
 * The following code is used to create a JSON file for VIA Configurator.
 */

/* Copyright 2020 'elmo-space'
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

bool rgb_mode_plain = true;
bool caps_lock_on = false;

enum custom_keycodes {
    CAPSLIGHT = SAFE_RANGE,

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case CAPSLIGHT:
        if (record->event.pressed) {
                // toggle Caps Lock
                if (caps_lock_on) {
                    // register_mods(MOD_MASK_SHIFT);
                    // using MASK_SHIFT causes a lot of fucked up behavior
                    unregister_code(KC_CAPS_LOCK);
                } else {
                    // register_mods(MOD_MASK_SHIFT);
                    register_code(KC_CAPS_LOCK);
                }
                caps_lock_on = !caps_lock_on;

                // toggle RGB mode
                if (rgb_mode_plain) {
                    rgblight_mode(RGBLIGHT_MODE_RAINBOW_SWIRL);
                } else {
                    rgblight_mode(RGBLIGHT_MODE_STATIC_LIGHT);
                }
                rgb_mode_plain = !rgb_mode_plain;
        }
        break;
    }
    return true;
};

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 20};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[0] = LAYOUT_65_ansi_blocker(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC, KC_HOME,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_PGUP,
  CAPSLIGHT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,          KC_ENT,  KC_PGDN,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,          KC_UP,   KC_END,
  KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                             MO(1),   KC_LCTL,         KC_LEFT,  KC_DOWN, KC_RGHT),

[1] = LAYOUT_65_ansi_blocker(
  KC_GRV,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_INS,
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_PSCR, KC_SCRL, KC_PAUS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_PGUP, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS,                   KC_TRNS,                            KC_TRNS, RGB_MOD,          KC_HOME, KC_PGDN, KC_END),

};

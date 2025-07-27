/* Copyright 2022 Dennis Kruyt (dennis@kruyt.org)
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
#include "config.h"

<<<<<<< Updated upstream
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< Updated upstream
bool WINDOWS = true;
bool MAC = false;
=======
bool WINDOWS = false;
bool MAC = true;
>>>>>>> Stashed changes
=======
bool WINDOWS = true;
bool MAC = false;
>>>>>>> 23ef7c29ca (merging with upstream)
=======
bool WINDOWS = true;
bool MAC = false;
>>>>>>> b06656350e (Stable version with windows and mac. Missing testing Mac)
bool LINUX = false;
bool unregister_alt = false;
=======
bool WINDOWS = true;
bool MAC     = false;
bool LINUX = falser bool unregister_alt = false;
>>>>>>> Stashed changes

enum custom_keycodes { KC_ACCENT = SAFE_RANGE, KC_TEST, KC_SWITCH, KC_CMD, KC_CTRL };

enum layer_names { _DVORAK, _QWERTY, _LEFT_RAISE, _RIGHT_RAISE, _SYSTEM };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {[_DVORAK] = LAYOUT_ortho_4x12(KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y, KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSPC, KC_ESC, KC_A, KC_O, KC_E, KC_U, KC_I, KC_D, KC_H, KC_T, KC_N, KC_S, KC_ENT, KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X, KC_B, KC_M, KC_W, KC_V, KC_Z, KC_RSFT, KC_CTRL, KC_GRV, KC_LALT, KC_CMD, MO(2), KC_SPC, KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

                                                              [_QWERTY] = LAYOUT_ortho_4x12(KC_TAB, KC_Q, KC_W, KC_E, KC_R, _______, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC, KC_ESC, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, KC_LGUI, KC_GRV, KC_LALT, KC_LCTL, MO(2), KC_SPC, KC_SPC, MO(3), KC_LEFT, KC_DOWN, KC_UP, KC_RGHT),

                                                              [_LEFT_RAISE] = LAYOUT_ortho_4x12(RCS(KC_TAB), RCTL(KC_R), KC_3, KC_2, KC_1, RCTL(KC_TAB), KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_BSPC, KC_DEL, LCTL(KC_C), KC_6, KC_5, KC_4, KC_NO, KC_NO, KC_EQL, KC_LBRC, KC_RBRC, KC_SLSH, _______, _______, LCTL(KC_V), KC_9, KC_8, KC_7, KC_0, KC_NO, KC_LT, KC_GT, KC_BSLS, KC_BSLS, _______, _______, LCTL(KC_W), _______, _______, _______, _______, _______, MO(4), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

                                                              [_RIGHT_RAISE] = LAYOUT_ortho_4x12(KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_PERC, KC_LCBR, KC_RCBR, KC_AMPR, KC_CIRC, KC_PAST, KC_QUES, _______, KC_DEL, KC_QUOT, KC_LPRN, KC_RPRN, KC_UNDS, KC_MINS, KC_DLR, KC_EQL, KC_LBRC, KC_RBRC, KC_SLSH, _______, _______, KC_PPLS, KC_NO, KC_NO, KC_NO, KC_ACCENT, KC_TILD, KC_LT, KC_GT, KC_NUHS, KC_PIPE, _______, KC_1, _______, _______, KC_RALT, MO(4), _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY),

                                                              [_SYSTEM] = LAYOUT_ortho_4x12(QK_BOOT, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, KC_SWITCH, _______, KC_F1, KC_F2, KC_F3, KC_F10, DB_TOGG, _______, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______, KC_F4, KC_F5, KC_F6, KC_F11, CG_RNRM, _______, RGB_RMOD, RGB_SPD, RGB_SPI, _______, _______, _______, KC_F7, KC_F8, KC_F9, KC_F12, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_MRWD, _______, _______, KC_MFFD)};

// layer_state_t layer_state_set_user(layer_state_t state) {
//     switch (get_highest_layer(state)) {
//     case _DVORAK:
//         rgblight_sethsv (0x00,  0x00, 0xFF);
//         break;
//     case _LEFT_RAISE:
//         rgblight_sethsv (0xFF,  0x00, 0x00);
//         break;
//     case _RIGHT_RAISE:
//         rgblight_sethsv (0x00,  0xFF, 0x00);
//         break;
//     case _SYSTEM:
//         rgblight_sethsv (0x7A,  0x00, 0xFF);
//         break;
//     default: //  for any other layers, or the default layer
//         rgblight_sethsv (0x00,  0xFF, 0xFF);
//         break;
//     }
//   return state;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_TAB:
            if (WINDOWS) {
                if (record->event.pressed && (get_mods() & MOD_MASK_CTRL) != 0) {
                    unregister_code(KC_LCTL);
                    register_code(KC_LALT);
                    tap_code16(KC_TAB);
                    unregister_alt = true;
                } else if (record->event.pressed) {
                    tap_code16(KC_TAB);
                }
            }
            return false;
        case KC_ACCENT:
            if (record->event.pressed) {
                if (WINDOWS) {
                    tap_code16(RALT(KC_QUOT));
                } else if (MAC) {
                    tap_code16(RALT(KC_E));
                } else if (LINUX) {
                    tap_code16(RALT(KC_U));
                }
            } else {
                // Do something else when release
            }
            return false; // Skip all further processing of this key

        // WINDOW -> MAC -> LINUX
        case KC_SWITCH:
            if (record->event.pressed) {
                if (WINDOWS) {
                    WINDOWS = false;
                    LINUX   = false;
                    MAC     = true;
                    // rgblight_sethsv (0x00,  0x00, 0xFF);
                } else if (MAC) {
                    WINDOWS = false;
                    LINUX   = true;
                    MAC     = false;
                    // rgblight_sethsv (0x00,  0x00, 0xFF);
                } else {
                    WINDOWS = true;
                    LINUX   = false;
                    MAC     = false;
                    // rgblight_sethsv (0x00,  0x00, 0xFF);
                }
            }
            return false;
        case KC_CMD:
            if (record->event.pressed) {
                if (WINDOWS || LINUX) {
                    register_code(KC_LCTL);
                } else {
                    register_code(KC_LGUI);
                }
            } else {
                if (WINDOWS || LINUX) {
                    if (unregister_alt) {
                        unregister_code(KC_LALT);
                        unregister_alt = false;
                    } else {
                        unregister_code(KC_LCTL);
                    }
                } else {
                    unregister_code(KC_LGUI);
                }
            }
            return false;
        case KC_CTRL:
            if (record->event.pressed) {
                if (WINDOWS || LINUX) {
                    register_code(KC_LGUI);
                } else {
                    register_code(KC_LCTL);
                }
            } else {
                if (WINDOWS || LINUX) {
                    unregister_code(KC_LGUI);
                } else {
                    unregister_code(KC_LCTL);
                }
            }
            return false;
        default:
            return true; // Process all other keycodes normally
    }
}

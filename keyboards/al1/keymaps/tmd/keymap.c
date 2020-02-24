/* Copyright 2018 MechMerlin
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

#define _MACBASE 0
#define _MACFUNC 1

#define _WINBASE 10
#define _WINFUNC 11

#define _SETTINGS 20


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
       [_MACBASE] = LAYOUT(\
       KC_GESC,   KC_1,    KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  		KC_ESC,   	KC_NLCK,  G(S(KC_4)),  C(KC_C),  G(C(KC_Q)),\
       KC_TAB,      KC_Q,    KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, 		KC_DELETE, 	KC_P7,    KC_P8,    KC_P9,    KC_PPLS,\
       KC_CAPS,      KC_A,    KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                 		KC_P4,    KC_P5,    KC_P6,          \
       KC_LSFT,       KC_Z,    KC_X,     KC_C,    KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH,        KC_RSFT,  KC_RSFT,          	KC_UP,    	KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
       KC_LCTL, KC_LALT,  KC_LGUI, 			KC_SPACE,			   		KC_RGUI,  KC_RALT,  MO(_MACFUNC),             KC_LEFT,  KC_DOWN,  KC_RIGHT, 	  KC_P0,    KC_PDOT         ),

       [_MACFUNC] = LAYOUT(\
       KC_GRV,  KC_F1,    KC_F2,     KC_F3,    KC_F4,     KC_F5,     KC_F6,     KC_F7,    KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,    _______,  	BL_TOGG,   	BL_BRTG,  KC_PSCR,  KC_PAUS,  LCAG(KC_U),\
       _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, 		BL_STEP, 	KC_P7,    KC_P8,    KC_P9,    KC_PPLS,\
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                			KC_P4,    KC_P5,    KC_P6,          \
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,          		KC_PGUP,    	KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
       _______, _______,  _______, 			MO(_SETTINGS),   			   _______,  _______,  _______,         	      KC_HOME,  KC_PGDN,  KC_END,	  KC_P0,    KC_PDOT         ),

       [_WINBASE] = LAYOUT(\
       KC_GESC,   KC_1,    KC_2,     KC_3,    KC_4,     KC_5,     KC_6,     KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,     KC_BSPC,  		KC_ESC,   	KC_NLCK,  A(KC_PSCR),  C(KC_C),  G(KC_L),\
       KC_TAB,      KC_Q,    KC_W,     KC_E,    KC_R,     KC_T,     KC_Y,     KC_U,    KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS, 		KC_DELETE, 	KC_P7,    KC_P8,    KC_P9,    KC_PPLS,\
       KC_CAPS,      KC_A,    KC_S,     KC_D,    KC_F,     KC_G,     KC_H,     KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,                 		KC_P4,    KC_P5,    KC_P6,          \
       KC_LSFT,       KC_Z,    KC_X,     KC_C,    KC_V,     KC_B,     KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_SLSH,        KC_RSFT,  KC_RSFT,          	KC_UP,    	KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
       KC_LCTL, KC_LGUI,  KC_LALT, 			KC_SPACE,			   		KC_RALT,  KC_RGUI,  MO(_WINFUNC),             KC_LEFT,  KC_DOWN,  KC_RIGHT, 	  KC_P0,    KC_PDOT         ),

       [_WINFUNC] = LAYOUT(\
       KC_GRV,  KC_F1,    KC_F2,     KC_F3,    KC_F4,     KC_F5,     KC_F6,     KC_F7,    KC_F8,     KC_F9,     KC_F10,     KC_F11,  KC_F12,    _______,  	BL_TOGG,   	BL_BRTG,  KC_PSCR,  KC_PAUS,  LCAG(KC_U),\
       _______,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, 		BL_STEP, 	KC_P7,    KC_P8,    KC_P9,    KC_PPLS,\
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                			KC_P4,    KC_P5,    KC_P6,          \
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,          		KC_PGUP,    	KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
       _______, _______,  _______, 			MO(_SETTINGS),   			   _______,  _______,  _______,         	      KC_HOME,  KC_PGDN,  KC_END,	  KC_P0,    KC_PDOT         ),

       [_SETTINGS] = LAYOUT(\
       RESET,    _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  		TO(_MACBASE),   	BL_BRTG,  KC_PSCR,  KC_PAUS,  LCAG(KC_U),\
       _______,    _______,  _______,  _______,  RESET,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______, 		TO(_WINBASE), 	KC_P7,    KC_P8,    KC_P9,    KC_PPLS,\
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,                			KC_P4,    KC_P5,    KC_P6,          \
       _______,      _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,          		KC_PGUP,    	KC_P1,    KC_P2,    KC_P3,    KC_PENT, \
       _______, _______,  _______, 			_______,   			   _______,  _______,  _______,         	      KC_HOME,  KC_PGDN,  KC_END,	  KC_P0,    KC_PDOT         ),

};

void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}

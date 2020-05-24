/* Copyright 2019 Chuck Lauer Vose <vosechu@gmail.com>
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

// // Debugging
// #include <print.h>

#define BASE   TO(_BASE)
#define MIDI1  TO(_MIDI1)
#define MIDI2 TO(_MIDI2)
#define ADJ    TO(_ADJ)

enum my_layers {
    _BASE = 0,
    _MIDI1,
    _MIDI2,
    _ADJ
};

enum custom_keys {
  MI_CH_C = SAFE_RANGE,
  MI_CH_Cs,
  MI_CH_Db = MI_CH_Cs,
  MI_CH_D,
  MI_CH_Ds,
  MI_CH_Eb = MI_CH_Ds,
  MI_CH_E,
  MI_CH_F,
  MI_CH_Fs,
  MI_CH_Gb = MI_CH_Fs,
  MI_CH_G ,
  MI_CH_Gs,
  MI_CH_Ab = MI_CH_Gs,
  MI_CH_A,
  MI_CH_As,
  MI_CH_Bb = MI_CH_As,
  MI_CH_B,

  // MIDI Chord Keycodes Minor

  MI_CH_Cm,
  MI_CH_Csm,
  MI_CH_Dbm = MI_CH_Csm,
  MI_CH_Dm,
  MI_CH_Dsm,
  MI_CH_Ebm = MI_CH_Dsm,
  MI_CH_Em,
  MI_CH_Fm,
  MI_CH_Fsm,
  MI_CH_Gbm = MI_CH_Fsm,
  MI_CH_Gm,
  MI_CH_Gsm,
  MI_CH_Abm = MI_CH_Gsm,
  MI_CH_Am,
  MI_CH_Asm,
  MI_CH_Bbm = MI_CH_Asm,
  MI_CH_Bm,

  //MIDI Chord Keycodes Dominant Seventh

  MI_CH_CDom7,
  MI_CH_CsDom7,
  MI_CH_DbDom7 = MI_CH_CsDom7,
  MI_CH_DDom7,
  MI_CH_DsDom7,
  MI_CH_EbDom7 = MI_CH_DsDom7,
  MI_CH_EDom7,
  MI_CH_FDom7,
  MI_CH_FsDom7,
  MI_CH_GbDom7 = MI_CH_FsDom7,
  MI_CH_GDom7,
  MI_CH_GsDom7,
  MI_CH_AbDom7 = MI_CH_GsDom7,
  MI_CH_ADom7,
  MI_CH_AsDom7,
  MI_CH_BbDom7 = MI_CH_AsDom7,
  MI_CH_BDom7,

  // MIDI Chord Keycodes Diminished Seventh

  MI_CH_CDim7,
  MI_CH_CsDim7,
  MI_CH_DbDim7 = MI_CH_CsDim7,
  MI_CH_DDim7,
  MI_CH_DsDim7,
  MI_CH_EbDim7 = MI_CH_DsDim7,
  MI_CH_EDim7,
  MI_CH_FDim7,
  MI_CH_FsDim7,
  MI_CH_GbDim7 = MI_CH_FsDim7,
  MI_CH_GDim7,
  MI_CH_GsDim7,
  MI_CH_AbDim7 = MI_CH_GsDim7,
  MI_CH_ADim7,
  MI_CH_AsDim7,
  MI_CH_BbDim7 = MI_CH_AsDim7,
  MI_CH_BDim7,

};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT(
        KC_SPACE, MIDI2  , KC_ENTER,
        MIDI1 ,  KC_UP,      ADJ,
        KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_MIDI1] = LAYOUT(
        _______, BASE   , MI_ALLOFF,
        MI_OCTD, MI_CH_G , MI_OCTU,
        MI_CH_F  , MI_CH_D  , MI_CH_A
    ),
    [_MIDI2] = LAYOUT(
        _______, _______, _______,
        MI_CH_Bm   , MI_CH_Gm   , MI_CH_Cm,
        MI_C   , MI_G   , MI_D
    ),
    [_ADJ] = LAYOUT(
        RESET,   BASE,  RGB_TOG,
        MIDI1,   BASE   , MIDI2   ,
        BASE   , BASE   , BASE
    )
};

bool base_mode = false;
bool midi1_mode = false;
bool midi2_mode = false;
bool adj_mode = false;

uint32_t layer_state_set_user(uint32_t state) {
    base_mode = false;
    midi1_mode = false;
    midi2_mode = false;
    adj_mode = false;

    switch (biton32(state)) {
    case _MIDI1:
        midi1_mode = true; // For use in encoder evaluation
        rgblight_sethsv_noeeprom(HSV_BLUE);
        break;
    case _MIDI2:
        midi2_mode = true; // For use in encoder evaluation
        rgblight_sethsv_noeeprom(HSV_CYAN);
        break;
    case _ADJ:
        adj_mode = true; // For use in encoder evaluation
        rgblight_sethsv_noeeprom(HSV_RED);
        break;
    default: //  for any other layers, or the default layer
        base_mode = true;
        rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
        break;
    }
    return state;
}

void keyboard_post_init_user(void) {
    // Call the post init code.
    rgblight_enable_noeeprom(); // enables Rgb, without saving settings
    rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
}


void encoder_update_user(uint8_t index, bool clockwise) {
    if(base_mode == true) {
        if (index == 0) {
            if (clockwise) {
                tap_code(KC_VOLU);
            } else {
                tap_code(KC_VOLD);
            }
        }
        else if (index == 1) {
            if (clockwise) {
                tap_code(KC_UP);
            } else {
                tap_code(KC_DOWN);
            }
        }
    }

    if(midi1_mode == true || midi2_mode == true) {
        if (index == 0) {
            //mod wheel
            if (clockwise) {
                tap_code16(MI_MODSU);
            } else {
                tap_code16(MI_MODSD);
            }
        }
        else if (index == 1) {
            //pitch bend
            if (clockwise) {
                tap_code16(MI_BENDU);
            } else {
                tap_code16(MI_BENDD);
            }
        }
    }

    if(adj_mode == true) {
        if (index == 0) {
            if (clockwise) {
                tap_code16(LGUI(KC_UP));
            } else {
                tap_code16(LGUI(KC_DOWN));
            }
        }
        else if (index == 1) {
            if (clockwise) {
                tap_code16(RGB_MOD);
            } else {
                // Trim right
                tap_code16(RGB_MOD);
            }
        }
    }
}

bool process_record_user (uint16_t keycode, keyrecord_t *record) {

  uint16_t root_note = MIDI_INVALID_NOTE; // Starting value for the root note of each chord
  
  switch(keycode) {

    // MIDI Chord Keycodes
    
  case MI_CH_C ... MI_CH_B: // Major Chords
    root_note = keycode - MI_CH_C + MI_C;
    process_midi(root_note, record);
    process_midi(root_note + 4, record); // Major Third Note
    process_midi(root_note + 7, record); // Fifth Note
    break;

  case MI_CH_Cm ... MI_CH_Bm: // Minor Chord
    root_note = keycode - MI_CH_Cm + MI_C;
    process_midi(root_note, record);
    process_midi(root_note + 3, record); // Minor Third Note
    process_midi(root_note + 7, record); // Fifth Note
    break;

  case MI_CH_CDom7 ... MI_CH_BDom7: // Dominant 7th Chord
    root_note = keycode - MI_CH_CDom7 + MI_C;
    process_midi(root_note, record);
    process_midi(root_note + 4, record); // Major Third Note
    process_midi(root_note + 10, record); // Minor Seventh Note
    break;

  case MI_CH_CDim7 ... MI_CH_BDim7: // Diminished 7th Chord
    root_note = keycode - MI_CH_CDim7 + MI_C;
    process_midi(root_note, record);
    process_midi(root_note + 3, record); // Minor Third Note
    process_midi(root_note - 3, record); // Diminished 7th Note
    break;
  }
  return true;
}

#include QMK_KEYBOARD_H

#define _MAIN 0
#define _UP 1


enum {
  TD_RGB = 0
};

uint16_t encoderup[2] = {KC_UP, KC_LEFT};
uint16_t encoderdown[2] = {KC_DOWN, KC_RIGHT};
uint8_t layer = 0;



void dance_rgb_finished (qk_tap_dance_state_t *state, void *user_data) {
  if (state->count == 1) {
    register_code (KC_MNXT);
  unregister_code (KC_MNXT);
  } else if (state->count == 2) {
    rgblight_toggle();
  } else if (state->count == 3) {
    rgblight_step();
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
 [TD_RGB] = ACTION_TAP_DANCE_FN_ADVANCED (NULL, dance_rgb_finished, NULL)
};

void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) { 
    if (clockwise) {
      tap_code(encoderdown[layer]);
    } else {
      tap_code(encoderup[layer]);
    }
  } 
}


uint32_t layer_state_set_user(uint32_t state) {
    
  //switch (biton32(state)) {
  //   case _MIDI1:
  //       midi1_mode = true; // For use in encoder evaluation
  //       rgblight_sethsv_noeeprom(HSV_BLUE);
  //       break;
  //   case _MIDI2:
  //       midi2_mode = true; // For use in encoder evaluation
  //       rgblight_sethsv_noeeprom(HSV_CYAN);
  //       break;
  //   case _ADJ:
  //       adj_mode = true; // For use in encoder evaluation
  //       rgblight_sethsv_noeeprom(HSV_RED);
  //       break;
  //   default: //  for any other layers, or the default layer
  //       base_mode = true;
  //       rgblight_sethsv_noeeprom(HSV_SPRINGGREEN);
  //       break;
  //  }

   layer = get_highest_layer(state);

    return state;
}

//
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = { //buttion closest to usb is first
  [_MAIN] = LAYOUT(
     TO(1), KC_ENT, KC_PGUP, KC_PGDN
  ),
  [_UP] = LAYOUT(
     TO(0), KC_SPACE, KC_UP, KC_DOWN
  )

};

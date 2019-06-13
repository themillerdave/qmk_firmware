/* Copyright 2019 Danny Nguyen <danny@keeb.io>
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

#include "quantum/joystick.h"
#include <print.h>
#include <drivers/avr/analog.h>

#if 0
int main(void)
{
  DDRB = 1;
  DDRD = 1 << 5;
  PORTB = 1;
  PORTD = 1 << 5;
  
  analogReference(ADC_REF_POWER);
  
  ADMUX = (1<<REFS0);// | (1<<MUX2) | (1<<MUX1);
  ADCSRA = (1<<ADEN) | ADC_PRESCALER;
  ADCSRB = 1 << MUX5;
  
  wait_ms(1000);
  
  while (1){
    
    //uint16_t adcval = analogRead(4);
    uint16_t adcval = 0;
    ADCSRA |= 1<<ADSC;
    
    while (ADCSRA & (1<<ADSC)) ;			// wait for result
    adcval = ADCL;					// must read LSB first
    adcval |= (ADCH << 8) | adcval;
    
    if (adcval>512){
      PORTB = 0;
    } else {
      PORTB = 0x1;
    }
    
    if (adcval>256){
      PORTD = 0;
    } else {
      PORTD = 1 << 5;
    }
    
    wait_ms(1000);
  }
  
  return 0;
}
#endif

enum custom_keycodes {
  TEST = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [0] = LAYOUT(
        TEST, KC_HOME,   KC_MPLY, \
        MO(1),   KC_UP,   KC_ENT, \
        KC_LEFT, KC_DOWN, KC_RGHT \
    ),
    [1] = LAYOUT(
        RESET,   RESET, KC_STOP, \
        _______, KC_HOME, KC_ENT, \
        KC_MPRV, KC_END,  KC_MNXT \
    ),
};

void matrix_init_user(void) {
#ifdef JOYSTICK_ENABLE
  analogReference(ADC_REF_POWER);//set ADC VRef to AVcc
#endif
}

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch(keycode){
#ifdef JOYSTICK_ENABLE
    case TEST:
    if (record->event.pressed){
      uprintf("axis 0 : %u\n", joystick_status.axes[0]);
      uprintf("axis 1 : %u\n", joystick_status.axes[1]);
    }
    break;
#endif
  }
  
  return true;
}

//joystick config
joystick_config_t joystick_axes[JOYSTICK_AXES_COUNT] = {
  [0] = JOYSTICK_AXIS_IN(D7, 1023, 511, 0)
, [1] = JOYSTICK_AXIS_IN(D4, 1023, 526, 0)
};

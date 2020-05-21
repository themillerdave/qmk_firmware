/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0x6061
#define DEVICE_VER      0x0001
#define MANUFACTURER    a-chol
#define PRODUCT         Farewell
#define DESCRIPTION     3x3 macropad with option rotary encoder and joystick

/* key matrix size */
#define MATRIX_ROWS 3
#define MATRIX_COLS 3

#define MATRIX_ROW_PINS { B3, B2, B6 }
#define MATRIX_COL_PINS { B5, B4, E6 }
#define UNUSED_PINS

#define NUMBER_OF_ENCODERS 2
#define ENCODERS_PAD_A { F5, F7 }
#define ENCODERS_PAD_B { F4, F6 }

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

#endif

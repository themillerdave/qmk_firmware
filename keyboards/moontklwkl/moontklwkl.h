/* Copyright 2019
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
#pragma once

#include "quantum.h"
#define ____ KC_NO

/* This a shortcut to help you visually see your layout.
 *
 * The first section contains all of the arguments representing the physical
 * layout of the board and position of the keys.
 *
 * The second converts the arguments into a two-dimensional array which
 * represents the switch matrix.

        ESC, F1,  F2,  F3,  F4,  F5,  F6,  F7,  F8,  F9,  F10,  \
        GRV, 1,   2,   3,   4,   5,   6,   7,   8,   9,   0,    \
        TAB, Q,   W,   E,   R,   T,   Y,   U,   I,   O,   P,    \
        CAPS,A,   S,   D,   F,   G,   H,   J,   K,   L,   SCLN, \
        LSFT,     Z,   X,   C,   V,   B,   N,   M,   COMM,DOT,  \
        LCTL,LGUI,LGUI,SPC,      RALT,RGUI,FN0, LEFT,DOWN,RGHT, \
        F11, F12, PSCR,FN1, NLCK,MINS,EQL, BSPC,INS, HOME,PGUP, \
        LBRC,RBRC,BSLS,DEL, END, PGDN,QUOT,ENT, SLSH,UP,  RSFT),
 
 */
#define LAYOUT_75_ansi( \
    K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K, \
    K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K, \
    K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K, \
    K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K, \
    K4A,      K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K, \
    K5A, K5B, K5C, K5D,      K5F, K5G, K5H, K5I, K5J, K5K, \
    K6A, K6B, K6C, K6D, K6E, K6F, K6G, K6H, K6I, K6J, K6K, \
    K7A, K7B, K7C, K7D, K7E, K7F, K7G, K7H, K7I, K7J, K7K  \
) { \
    { K0A, K0B, K0C, K0D, K0E, K0F, K0G, K0H, K0I, K0J, K0K }, \
    { K1A, K1B, K1C, K1D, K1E, K1F, K1G, K1H, K1I, K1J, K1K }, \
    { K2A, K2B, K2C, K2D, K2E, K2F, K2G, K2H, K2I, K2J, K2K }, \
    { K3A, K3B, K3C, K3D, K3E, K3F, K3G, K3H, K3I, K3J, K3K }, \
    { K4A, KC_NO,    K4C, K4D, K4E, K4F, K4G, K4H, K4I, K4J, K4K }, \
    { K5A, K5B, K5C, K5D, KC_NO,    K5F, K5G, K5H, K5I, K5J, K5K }, \
    { K6A, K6B, K6C, K6D, K6E, K6F, K6G, K6H, K6I, K6J, K6K }, \
    { K7A, K7B, K7C, K7D, K7E, K7F, K7G, K7H, K7I, K7J, K7K }  \
}

#define LAYOUT_75_iso( \
    K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K115, K116, \
    K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214,       K216, \
    K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313,             K316, \
    K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412,       K414, K415, K416, \
    K501, K502, K503, K504, K505, K506, K507, K508, K509, K510, K511, K512, K513,       K515, K516, \
    K601, K602, K603,                       K607,               K611, K612, K613, K614, K615, K616  \
) { \
    { K101, K102, K103, K104, K105, K106, K107, K108, K109, K110, K111, K112, K113, K114, K116 }, \
    { K201, K202, K203, K204, K205, K206, K207, K208, K209, K210, K211, K212, K213, K214, K216 }, \
    { K301, K302, K303, K304, K305, K306, K307, K308, K309, K310, K311, K312, K313, ____, K316 }, \
    { K401, K402, K403, K404, K405, K406, K407, K408, K409, K410, K411, K412, K414, K415, K416 }, \
    { K501, K502, K503, K504, K505, K506, K507, K508, K509, K510, K511, K512, K513, K515, K516 }, \
    { K601, K602, K603, ____, ____, K607, K115, ____, K613, ____, K611, K612, K614, K615, K616 }  \
}

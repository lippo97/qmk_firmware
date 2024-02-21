/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

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

#pragma once

#define MASTER_LEFT

#define QUICK_TAP_TERM 100
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD

#define LAYOUT_COLUMNS_4(...) LAYOUT_COLUMNS_4_W(__VA_ARGS__)
#define LAYOUT_COLUMNS_4_W( \
         LN5, LT5, LM5, LB5,                  RN5, RT5, RM5, RB5,          \
         LN4, LN3, LN2, LN1, LN0,             RN0, RN1, RN2, RN3, RN4,     \
         LT4, LT3, LT2, LT1, LT0,             RT0, RT1, RT2, RT3, RT4,     \
         LM4, LM3, LM2, LM1, LM0,             RM0, RM1, RM2, RM3, RM4,     \
         LB4, LB3, LB2, LB1, LB0, LBA,   RBA, RB0, RB1, RB2, RB3, RB4      \
) \
    LN5, LN4, LN3, LN2, LN1, LN0,             RN0, RN1, RN2, RN3, RN4, RN5, \
    LT5, LT4, LT3, LT2, LT1, LT0,             RT0, RT1, RT2, RT3, RT4, RT5, \
    LM5, LM4, LM3, LM2, LM1, LM0,             RM0, RM1, RM2, RM3, RM4, RM5, \
    LB5, LB4, LB3, LB2, LB1, LB0, LBA,   RBA, RB0, RB1, RB2, RB3, RB4, RB5


#define LAYOUT_INNER(...) LAYOUT_INNER_W(__VA_ARGS__)
// #define LAYOUT_INNER_W(LBA, RBA, ...) LAYOUT_INNER(LBA, RBA, __VA_ARGS__)
#define LAYOUT_INNER_W( \
    LBA, RBA, \
    LT4, LT3, LT2, LT1, LT0,   RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,   RM0, RM1, RM2, RM3, RM4, \
    LB4, LB3, LB2, LB1, LB0,   RB0, RB1, RB2, RB3, RB4  \
) \
    LT4, LT3, LT2, LT1, LT0,             RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,             RM0, RM1, RM2, RM3, RM4, \
    LB4, LB3, LB2, LB1, LB0, LBA,   RBA, RB0, RB1, RB2, RB3, RB4

#define GASC_BOTTOM(...) GASC_BOTTOM_IMPL(__VA_ARGS__)
#define GASC_BOTTOM_IMPL( \
    LT4, LT3, LT2, LT1, LT0,   RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,   RM0, RM1, RM2, RM3, RM4, \
    LB4, LB3, LB2, LB1, LB0,   RB0, RB1, RB2, RB3, RB4  \
) \
    LT4, LT3, LT2, LT1, LT0,   RT0, RT1, RT2, RT3, RT4, \
    LM4, LM3, LM2, LM1, LM0,   RM0, RM1, RM2, RM3, RM4, \
    LGUI_T(LB4), LALT_T(LB3), LSFT_T(LB2), LCTL_T(LB1), LB0,   RB0, RCTL_T(RB1), RSFT_T(RB2), LALT_T(RB3), RGUI_T(RB4)

#define NUMBERS \
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,       KC_6,    KC_7,    KC_8,    KC_9,    KC_0

#define QWERTY  \
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, \
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, \
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH

#define SEMIMAK_JQ  \
    KC_F,    KC_L,    KC_H,    KC_V,    KC_Z,    KC_QUOT,    KC_W,    KC_U,    KC_O,    KC_Y, \
    KC_S,    KC_R,    KC_N,    KC_T,    KC_K,       KC_C,    KC_D,    KC_E,    KC_A,    KC_I, \
    KC_X,    KC_J,    KC_B,    KC_M,    KC_Q,       KC_P,    KC_G, KC_COMM,  KC_DOT, KC_SLSH

#define ISRT_MATRIX  \
    KC_Y,    KC_C,    KC_L,    KC_M,    KC_K,       KC_Z,    KC_F,    KC_U, KC_COMM, KC_QUOT, \
    KC_I,    KC_S,    KC_R,    KC_T,    KC_G,       KC_P,    KC_N,    KC_E,    KC_A,    KC_O, \
    KC_Q,    KC_V,    KC_W,    KC_D,    KC_J,       KC_B,    KC_H, KC_SLSH, KC_DOT,    KC_X

#define CANARY_MATRIX  \
    KC_W,    KC_L,    KC_Y,    KC_P,    KC_B,       KC_Z,    KC_F,    KC_O,    KC_U, KC_QUOT, \
    KC_C,    KC_R,    KC_S,    KC_T,    KC_G,       KC_M,    KC_N,    KC_E,    KC_I,    KC_A, \
    KC_Q,    KC_J,    KC_V,    KC_D,    KC_K,       KC_X,    KC_H, KC_SLSH, KC_COMM, KC_DOT

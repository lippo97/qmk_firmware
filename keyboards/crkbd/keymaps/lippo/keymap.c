#include QMK_KEYBOARD_H
#include "layouts.h"
#include "mods.h"

#define LAYOUT_W(...) LAYOUT_split_3x6_3(__VA_ARGS__)

enum layer_number {
    _BASE = 0,
    _SEMI,
    _SYM,
    _NUM,
    _FUN,
    _NAV,
    _GME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE] = LAYOUT_W(
        LAYOUT_3x6(
            KC_ESC, KC_LCTL, KC_LSFT, KC_MINS, KC_QUOT, _______,
            GASC_BOTTOM(QWERTY)
        ),
        LT(_NAV, KC_TAB), KC_LSFT, KC_BSPC, LT(_SYM, KC_SPC), KC_ENT, LT(_NUM, KC_DEL)
    ),
    [_SEMI] = LAYOUT_W(
        LAYOUT_3x6(
            KC_TAB, KC_LCTL, KC_LSFT, KC_MINS, KC_QUOT, _______,
            GASC_BOTTOM(SEMIMAK_JQ)
        ),
        LT(_NAV, KC_ESC), KC_LSFT, KC_BSPC, LT(_SYM, KC_SPC), KC_ENT, LT(_NUM, KC_DEL)
    ),
    [_SYM] = LAYOUT_split_3x6_3(
        _______, KC_BSLS, KC_TILD, KC_HASH, KC_QUES, KC_PIPE,                   KC_ASTR, KC_COLN, KC_LBRC, KC_RBRC,  KC_GRV, _______,
        _______, KC_PLUS, KC_MINS,  KC_EQL, KC_EXLM,   KC_AT,                   KC_SLSH, KC_LPRN, KC_RPRN, KC_UNDS, KC_SCLN, _______,
        _______, _______, _______, KC_LABK, KC_RABK, KC_PERC,                   KC_AMPR,  KC_DLR, KC_LCBR, KC_RCBR, KC_CIRC, _______,
                                   _______, _______, _______,                   _______, _______, _______
    ),
    [_NUM] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   _______, _______, _______, _______, _______, _______,
                                  MO(_FUN), _______, _______,                   _______, _______, _______
    ),
    [_FUN] = LAYOUT_split_3x6_3(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______,  KC_F11,  KC_F12, _______,
        _______,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,                   _______, _______, _______
    ),
    [_NAV] = LAYOUT_W(
        _______, _______, _______,TO(_SEMI),TO(_GME), _______,                   _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
        _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
                                   _______, _______, _______,                   _______, _______, _______
    ),
    [_GME] = LAYOUT_W(
         KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
         KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,     KC_I,   KC_O,    KC_P, _______,
        KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,     KC_K,   KC_L, KC_SCLN, _______,
                                      KC_B, KC_LALT, KC_BSPC,                   _______, _______, TO(_BASE)
    )
  //   [0] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,   KC_P,  KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                         KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,  KC_ESC,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI,   MO(1),  KC_SPC,     KC_ENT,   MO(2), KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  //
  // ),
  //
  //   [1] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_LEFT, KC_DOWN,   KC_UP,KC_RIGHT, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT,   MO(3), KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //
  //   [2] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //      KC_TAB, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,                      KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_BSPC,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_MINS,  KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS,  KC_GRV,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE, KC_TILD,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI,   MO(3),  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // ),
  //
  //   [3] = LAYOUT_split_3x6_3(
  // //,-----------------------------------------------------.                    ,-----------------------------------------------------.
  //       QK_BOOT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
  //     RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD, XXXXXXX, XXXXXXX,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  // //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
  //                                         KC_LGUI, _______,  KC_SPC,     KC_ENT, _______, KC_RALT
  //                                     //`--------------------------'  `--------------------------'
  // )
};

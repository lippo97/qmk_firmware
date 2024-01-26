#include QMK_KEYBOARD_H

#define LD_LH3 KC_LALT
#define LD_LH2 MO(_SYM)
#define LD_LH1 KC_LSFT
#define LD_LH0 KC_BSPC

#define LD_RH0 LT(_SYM, KC_SPC)
#define LD_RH1 KC_ENT
#define LD_RH2 MO(_NAV)
#define LD_RH3 KC_RSFT

#define LD_LBA KC_LBRC
#define LD_RBA KC_RBRC

#define ALT_TAB_TIMER 500

enum layer_number {
  _BASE = 0,
  _NAV,
  _SYM,
  _GAME,
};

enum my_keycodes {
  KC_DCTL = SAFE_RANGE,
  KC_TGAM,
  ALT_TAB,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT(
  LD_LN5, LD_LN4, LD_LN3, LD_LN2, LD_LN1, LD_LN0,                   LD_RN0, LD_RN1, LD_RN2, LD_RN3, LD_RN4, LD_RN5,
  LD_LT5, LD_LT4, LD_LT3, LD_LT2, LD_LT1, LD_LT0,                   LD_RT0, LD_RT1, LD_RT2, LD_RT3, LD_RT4, LD_RT5,
  LD_LM5, LD_LM4, LD_LM3, LD_LM2, LD_LM1, LD_LM0,                   LD_RM0, LD_RM1, LD_RM2, LD_RM3, LD_RM4, LD_RM5,
  LD_LB5, LD_LB4, LD_LB3, LD_LB2, LD_LB1, LD_LB0, LD_LBA,   LD_RBA, LD_RB0, LD_RB1, LD_RB2, LD_RB3, LD_RB4, LD_RB5,
                          LD_LH3, LD_LH2, LD_LH1, LD_LH0,   LD_RH0, LD_RH1, LD_RH2, LD_RH3
),

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, ALT_TAB, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT,  KC_F12, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
                             _______, _______, KC_CAPS,  KC_DEL, _______, _______, _______, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_BSLS, KC_TILD, KC_HASH, KC_QUES, KC_PIPE,                   KC_QUOT, KC_DQUO, KC_LCBR, KC_RCBR, KC_GRV, _______,
  _______, KC_PLUS, KC_MINS,  KC_EQL, KC_EXLM,   KC_AT,                   KC_UNDS, KC_SLSH, KC_LPRN, KC_RPRN, KC_ASTR, _______,
  _______, _______, _______, KC_LABK, KC_RABK, KC_PERC, _______, _______, KC_AMPR,  KC_DLR, KC_LBRC, KC_RBRC, KC_CIRC, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_DCTL,    KC_RBRC,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TGAM,
                             KC_P, KC_LGUI, KC_LALT,    KC_BSPC,    KC_SPC,   KC_ENT, _______,    KC_RSFT
)

};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_TGAM:
      if (record->event.pressed) {
        if (IS_LAYER_ON(_BASE)) {
          SEND_STRING(SS_TAP(X_F15));
          layer_move(_GAME);
          return false;
        } else if (IS_LAYER_ON(_GAME)) {
          SEND_STRING(SS_TAP(X_F14));
          layer_move(_BASE);
          return false;
        }
      }
    case KC_DCTL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_RCTL()));
        return false;
      }
    // https://github.com/qmk/qmk_firmware/blob/master/docs/feature_macros.md
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) {
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        alt_tab_timer = timer_read();
        register_code(KC_TAB);
      } else {
        unregister_code(KC_TAB);
      }
      break;
  }
  return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > ALT_TAB_TIMER) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

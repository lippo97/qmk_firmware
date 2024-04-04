#include QMK_KEYBOARD_H

#define LAYOUT_W(...) LAYOUT(__VA_ARGS__)

#define ALT_TAB_TIMER 400

//Tap Dance Declarations
enum {
  TD_MY_CAPS = 0
};

//Tap Dance Definitions
tap_dance_action_t tap_dance_actions[] = {
  [TD_MY_CAPS]  = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)
};

enum layer_number {
  _BASE = 0,
  _SEMIJQ,
  _NAV,
  _SYM,
  _NUM,
  _GAME,
};

enum my_keycodes {
  DCTL = SAFE_RANGE,
  DCTL_MT,
  KC_TGAM,
  ALT_TAB,
};

#define KC_PSTE C(KC_V)
#define KC_COPY C(KC_C)
#define KC_CUT C(KC_X)
#define KC_UNDO C(KC_Z)
#define KC_BOL C(KC_A)
#define KC_TERM C(KC_D)
#define KC_INTR C(KC_C)
#define KC_EOL C(KC_E)
#define LCOL5  KC_ESC, KC_TAB, KC_LCTL, KC_LGUI
#define RCOL5 KC_MINS, KC_EQL, KC_QUOT, KC_TGAM
#define THUMB_ROW KC_LALT, MO(_NUM), TD(TD_MY_CAPS), KC_BSPC, LT(_SYM, KC_SPC), KC_ENT, MO(_NAV), KC_RSFT

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE] = LAYOUT_W(
  LAYOUT_COLUMNS_4(
    KC_ESC, KC_TAB, KC_LCTL, TO(_SEMIJQ),
    RCOL5,
    NUMBERS,
    LAYOUT_INNER(
      ALT_TAB,
      ALT_TAB,
      GASC_BOTTOM(QWERTY)
    )
  ),
  THUMB_ROW
),

[_SEMIJQ] = LAYOUT_W(
  LAYOUT_COLUMNS_4(
    // LEFT COL
    KC_ESC, KC_TAB, KC_LCTL, TO(_BASE),
    // RIGHT COL
    KC_MINS, KC_EQL, KC_SCLN, KC_TGAM,
    NUMBERS,
    LAYOUT_INNER(
      ALT_TAB,
      ALT_TAB,
      GASC_BOTTOM(SEMIMAK_JQ)
    )
  ),
  KC_LALT, MO(_SYM), KC_LSFT, KC_BSPC, KC_SPC, KC_ENT, MO(_NAV), KC_RSFT
),

[_NAV] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, KC_PSTE, KC_COPY,  KC_CUT, KC_UNDO, _______,
  _______,  KC_BOL, KC_TERM, KC_INTR,  KC_EOL, _______,                   KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______,
  _______, KC_LGUI, KC_LALT, KC_LSFT, KC_LCTL, _______, _______, _______, _______, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, _______,
                             _______, _______, _______,  KC_DEL, _______, _______, _______, _______
),

[_SYM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, KC_BSLS, KC_TILD, KC_HASH, KC_QUES, KC_PIPE,                   KC_ASTR, KC_COLN, KC_LBRC, KC_RBRC,  KC_GRV, _______,
  _______, KC_PLUS, KC_MINS,  KC_EQL, KC_EXLM,   KC_AT,                   KC_SLSH, KC_LPRN, KC_RPRN, KC_UNDS, KC_SCLN, _______,
  _______, _______, _______, KC_LABK, KC_RABK, KC_PERC, _______, _______, KC_AMPR,  KC_DLR, KC_LCBR, KC_RCBR, KC_CIRC, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

[_NUM] = LAYOUT(
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
  _______,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0, _______,
  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                             _______, _______, _______, _______, _______, _______, _______, _______
),

[_GAME] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                         KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS,
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  KC_LCTL,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    DCTL,    DCTL_MT,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_TGAM,
                             KC_P, KC_LGUI, KC_LALT, KC_BSPC,     KC_SPC,  KC_ENT, _______,    KC_RSFT
)

};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case LT(_SYM, KC_SPC):
      if (record->event.pressed) {
        if ((get_mods() & MOD_MASK_SHIFT)) {
          tap_code(KC_MINS);
          return false;
        }
      }
      break;
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
    case DCTL:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_RCTL()));
        return false;
      }
    case DCTL_MT:
      if (record->event.pressed) {
        SEND_STRING(SS_LCTL(SS_RCTL()) SS_DELAY(50) SS_TAP(X_F8) SS_LCTL(SS_RCTL()));
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
      return false;
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

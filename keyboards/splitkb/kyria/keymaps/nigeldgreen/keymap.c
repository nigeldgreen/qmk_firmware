#include QMK_KEYBOARD_H
#include <stdio.h>

/* Define our QWERTY home row mods */
#define _CTL_F CTL_T(KC_F)
#define _CTL_J CTL_T(KC_J)
#define _SFT_D SFT_T(KC_D)
#define _SFT_K SFT_T(KC_K)
#define _GUI_S GUI_T(KC_S)
#define _GUI_L GUI_T(KC_L)
#define _ALT_A ALT_T(KC_A)
#define _ALT_SC ALT_T(KC_SCLN)
#define _MEH_G MEH_T(KC_G)
#define _MEH_H MEH_T(KC_H)
/* Define our layer switching keys */
#define _SYM_TAB LT(1, KC_TAB)
#define _NUM_ESC LT(2, KC_ESC)
#define _SYM_ENT LT(1, KC_ENT)
/* Define some character keys to keep letter count low */
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define SFT_Z SFT_T(KC_Z)
#define _I3SCRMV S(G(KC_MINS))
#define _I3RSCR S(G(KC_SPC))
#define _I3QUIT S(G(KC_Q))
#define _I3TABS S(G(KC_W))
#define _I3RST S(G(KC_R))
#define _I3STCK S(G(KC_S))
#define _I3MV S(G(KC_COMM))
#define _I3SCR G(KC_MINS)
#define _I3RSCR S(G(KC_SPC))
#define _I3SPC G(KC_SPC)
#define _I3TAB G(KC_TAB)
#define _I3TERM G(KC_ENT)

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_shift_enter[] = {KC_Z, KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_prn[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_brc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cmb_prn),
    COMBO_ACTION(cmb_brc),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_shift_enter, S(KC_ENT)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
      }
      break;
    case 1:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
      }
      break;
  }
}

enum custom_keycodes {
    COMSPC = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case COMSPC:
        if (record->event.pressed) {
            SEND_STRING(", ");
         }
         break;
    }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
  KC_NO,      KC_Q,       KC_W,       KC_E,       KC_R,        KC_T,                                         KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      KC_NO,
  KC_NO,    _ALT_A,     _GUI_S,     _SFT_D,     _CTL_F,      _MEH_G,                                         _MEH_H,     _CTL_J,     _SFT_K,     _GUI_L,     _ALT_SC,   KC_NO,
  KC_NO,      KC_Z,       KC_X,       KC_C,       KC_V,        KC_B,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_NO,     KC_NO,
                                     KC_NO,      MO(3),    _SYM_TAB, _NUM_ESC, KC_NO,      KC_NO, _SYM_ENT,  KC_SPC,     MO(3),      KC_NO
  ),
  [1] = LAYOUT(
   KC_NO,    KC_GRV,   KC_PLUS,    KC_NUHS,    KC_LCBR,    KC_RCBR,                                         KC_DLR,     _UNDSCR,    KC_MINS,    KC_EQL,     KC_QUOT,   KC_NO,
   KC_NO,   KC_NUBS,   KC_PAST,    KC_EXLM,    KC_LPRN,    KC_RPRN,                                         KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   S(KC_2),   KC_NO,
   KC_NO,   S(KC_3),   KC_AMPR,    _ATSIGN,    KC_LBRC,    KC_RBRC,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_PERC,    _TILDE,     KC_SLSH,    KC_QUES,    _PIPE,     KC_NO,
                                     KC_NO,    CW_TOGG,    KC_TRNS,  KC_NO,   KC_NO,      KC_NO,  KC_TRNS,  KC_BSPC,    KC_NO,      KC_NO
  ),
  [2] = LAYOUT(
    KC_NO,    KC_NO,     KC_F7,      KC_F8,      KC_F9,     KC_F10,                                         KC_PGUP,    KC_7,       KC_8,       KC_9,       KC_MINS,   KC_NO,
    KC_NO,  QK_BOOT,     KC_F4,      KC_F5,      KC_F6,     KC_F11,                                         KC_NO,      KC_4,       KC_5,       KC_6,       COMSPC,    KC_NO,
    KC_NO,    KC_NO,     KC_F1,      KC_F2,      KC_F3,     KC_F12,  KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_PGDN,    KC_1,       KC_2,       KC_3,       KC_PLUS,   KC_NO,
                                     KC_NO,      KC_NO,      KC_NO, KC_TRNS,  KC_NO,      KC_NO,   KC_HOME, KC_0,       KC_END,     KC_NO
  ),
  [3] = LAYOUT(
    KC_NO,  _I3QUIT,   _I3TABS,    G(KC_E),     _I3RST,      KC_NO,                                         G(KC_0),    G(KC_7),    G(KC_8),    G(KC_9),    _I3SCRMV,  KC_NO,
    KC_NO,    KC_NO,   _I3STCK,      KC_NO,    _I3TERM,      KC_NO,                                         _I3MV,      G(KC_4),    G(KC_5),    G(KC_6),    _I3SCR,    KC_NO,
    KC_NO,    KC_NO,   G(KC_X),      KC_NO,      KC_NO,      KC_NO,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_NO,      G(KC_1),    G(KC_2),    G(KC_3),    _I3RSCR,   KC_NO,
                                     KC_NO,      KC_NO,      KC_NO, _I3TAB,   KC_NO,      KC_NO,    KC_NO,  _I3SPC,     KC_NO,      KC_NO
  ),
};

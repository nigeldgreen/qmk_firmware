#include QMK_KEYBOARD_H
#include <stdio.h>
#define _SYMTAB LT(3, KC_TAB)
#define _NUMESC LT(4, KC_ESC)
#define _FUNENT LT(5, KC_ENT)
#define _SYMSPC LT(2, KC_SPC)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _QWERTY DF(0)
#define _COLEMAK DF(1)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _SFT_Z SFT_T(KC_Z)
#define _I3QUIT S(G(KC_Q))
#define _I3TABS S(G(KC_W))
#define _I3RST S(G(KC_R))
#define _I3STCK S(G(KC_S))
#define _I3MV S(G(KC_COMM))
#define _I3ASCR S(G(KC_MINS))
#define _I3SCR G(KC_MINS)
#define _I3RSCR S(G(KC_SPC))
#define _I3SPC G(KC_SPC)
#define _I3TAB G(KC_TAB)

const uint16_t PROGMEM cmb_leader[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_escape[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_cbr[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_prn[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_brc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cmb_cbr),
    COMBO_ACTION(cmb_prn),
    COMBO_ACTION(cmb_brc),
    COMBO(cmb_leader, QK_LEAD),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_escape, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_lcbr, KC_LCBR),
    COMBO(cmb_rcbr, KC_RCBR),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
      }
      break;
    case 1:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
      }
      break;
    case 2:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
      }
      break;
  }
}

enum custom_keycodes {
    _LOREM = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _LOREM:
        if (record->event.pressed) {
            SEND_STRING("dummy text ");
        }
        break;
    }
    return true;
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_NO,
     KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_NO,
     KC_NO,  _SFT_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                 KC_Z,   MO(6), _SYMTAB, _NUMESC, KC_QUOT,      KC_NO,   _FUNENT, _SYMSPC,  MO(6),    QK_LEAD
  ),
  [1] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                          KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_NO,
     KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                          KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    KC_NO,
     KC_NO,  _SFT_Z,    KC_X,    KC_C,    KC_D,    KC_V,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  ),
  [2] = LAYOUT(
     KC_NO,  KC_GRV, KC_PERC, KC_NUHS, KC_AMPR, KC_PLUS,                                          KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO, KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),                                          C(KC_F),  _LCTL,    _GUI,    _ALT,    _MEH,    KC_NO,
     KC_NO, S(KC_3),   _PIPE, _ATSIGN,  KC_DLR,  _LOREM,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  ),
  [3] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_PGUP,  _UNDSCR,  KC_MINS, KC_EQL,   KC_NO,  KC_NO,
     KC_NO,    _MEH,    _ALT,    _GUI,   _LCTL, C(KC_F),                                          KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_NO,  KC_NO,
     KC_NO,   KC_NO,   _SALT,   _SGUI,   _SCTL,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_PGDN,  _TILDE,   KC_SLSH, KC_QUES,  KC_NO,  KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  ),
  [4] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,                                          KC_NO,    KC_7,     KC_8,    KC_9,    KC_NO,   KC_NO,
     KC_NO,    _MEH,    _ALT,    _GUI,   _LCTL, C(KC_F),                                          KC_NO,    KC_4,     KC_5,    KC_6,    KC_NO,   KC_NO,
     KC_NO,   KC_NO,   _SALT,   _SGUI,   _SCTL,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_1,     KC_2,    KC_3,    KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  ),
  [5] = LAYOUT(
     KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                          KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                          C(KC_F),  _LCTL,    _GUI,    _ALT,    _MEH,    KC_NO,
     KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  ),
  [6] = LAYOUT(
     KC_NO, _I3QUIT, _I3TABS, G(KC_E),  _I3RST,   KC_NO,                                          KC_NO,    G(KC_7),  G(KC_8), G(KC_9), _I3ASCR, KC_NO,
     KC_NO,   KC_NO, _I3STCK,   KC_NO, KC_LSFT,   KC_NO,                                          _I3MV,    G(KC_4),  G(KC_5), G(KC_6),  _I3SCR, KC_NO,
     KC_NO,   KC_NO, G(KC_X),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    G(KC_1),  G(KC_2), G(KC_3), _I3RSCR, KC_NO,
                                KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,    KC_NO,    KC_NO
  )
};


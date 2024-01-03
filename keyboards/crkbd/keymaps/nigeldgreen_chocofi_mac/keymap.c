#include QMK_KEYBOARD_H
#include <stdio.h>
#define SYMTAB LT(3, KC_TAB)
#define NUMESC LT(4, KC_ESC)
#define SYMENT LT(2, KC_ENT)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define ATSIGN S(KC_QUOT)
#define UNDSCR S(KC_MINS)
#define TILDE S(KC_GRV)

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_G, KC_B, COMBO_END};
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
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_cut, G(KC_X)),
    COMBO(cmb_copy, G(KC_C)),
    COMBO(cmb_paste, G(KC_V)),
    COMBO(cmb_undo, G(KC_Z)),
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
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    FFNXT,
    FFPRV,
    LOREM,
    COMSPC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMXNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "n");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "p");
        }
        break;
    case FFPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
        }
        break;
    case FFNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL(SS_TAP(X_PGDN)));
        }
        break;
    case LOREM:
        if (record->event.pressed) {
            SEND_STRING("dummy text ");
         }
         break;
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
       KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_NO,
       KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_NO,
       KC_NO, SC_LSPO,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,     KC_M,     KC_COMM, KC_DOT,  SC_RSPC, KC_NO,
                                            KC_NO,  SYMTAB,  NUMESC,       SYMENT, KC_SPC,   KC_NO
  ),
  [1] = LAYOUT(
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,     KC_L,     KC_U,    KC_O,    KC_Y,    KC_NO,
      CW_TOGG,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,     KC_N,     KC_E,    KC_I,    KC_SCLN, KC_NO,
        LOREM, KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                            KC_NO,  SYMTAB,  NUMESC,       SYMENT, KC_SPC,   KC_NO
  ),
  [2] = LAYOUT(
      KC_TRNS,  KC_GRV, KC_PERC, KC_AMPR, A(KC_3), KC_PLUS,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, KC_BSLS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),                        KC_NO,    _LCTL,    _GUI,    _ALT,    _MEH,    KC_TRNS,
      KC_TRNS,    KC_Z,  KC_DLR,  ATSIGN, KC_LBRC, KC_RBRC,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,  TMXPRV,  TMXNXT,      KC_TRNS, KC_TRNS,  KC_TRNS
  ),
  [3] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_PGUP,  UNDSCR,   KC_MINS, KC_EQL,   KC_HOME, KC_NO,
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL, KC_TRNS,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_END,  KC_NO,
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,                        KC_PGDN,  TILDE,    KC_SLSH, KC_QUES,  CW_TOGG, KC_NO,
                                            KC_NO, KC_TRNS,   KC_NO,      MO(5),  KC_BSPC,  KC_TRNS
  ),
  [4] = LAYOUT(
      KC_TRNS,   KC_F5,   KC_F7,   KC_F8,  KC_F9,   KC_F10,                        KC_PGUP,  KC_7,     KC_8,    KC_9,    KC_MINS,  KC_TRNS,
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL,  KC_F12,                        KC_Z,     KC_4,     KC_5,    KC_6,    COMSPC,   KC_TRNS,
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_F2,                        KC_PGDN,  KC_1,     KC_2,    KC_3,    KC_PLUS,  KC_TRNS,
                                            KC_NO,   KC_NO, KC_TRNS,      KC_BSPC, KC_0,     KC_TRNS
  ),
  [5] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        KC_NO,    _LCTL,    _GUI,    _ALT,   _MEH,     KC_TRNS,
      KC_TRNS,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,   FFPRV,   FFNXT,     KC_TRNS,  KC_NO,    KC_TRNS
  ),
};

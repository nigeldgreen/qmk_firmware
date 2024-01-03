#include QMK_KEYBOARD_H

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
#define TILDE S(KC_NUHS)
#define PIPE S(KC_NUBS)
#define SFTZ SFT_T(KC_Z)

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_shift_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_squote[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_dquote[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_less[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_grtr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_cbr[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_prn[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_brc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cmb_prn),
    COMBO_ACTION(cmb_brc),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_shift_enter, S(KC_ENT)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_space, KC_SPC),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_squote, KC_QUOT),
    COMBO(cmb_dquote, S(KC_2)),
    COMBO(cmb_less, S(KC_COMM)),
    COMBO(cmb_grtr, S(KC_DOT)),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
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
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    COMSPC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMXNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "P");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "p");
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
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
         SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_RSFT,
                                  SYMTAB,  NUMESC,        SYMENT,  KC_SPC
  ),
  [1] = LAYOUT(
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_O,     KC_Y,
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,     KC_SCLN,
         SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,   KC_RSFT,
                                  SYMTAB,  NUMESC,        SYMENT,  KC_SPC
  ),
  [2] = LAYOUT(
       KC_GRV, KC_PLUS, KC_AMPR, KC_NUHS, S(KC_6),        KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,
      KC_NUBS, KC_PAST, KC_EXLM, KC_PERC,  KC_DLR,        KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,
      S(KC_3),    PIPE,  ATSIGN,  TMXPRV,  TMXNXT,        KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_NO,
                                   KC_NO,   KC_NO,        KC_TRNS, KC_NO
  ),
  [3] = LAYOUT(
        DF(0),  KC_SPC, KC_BSPC,  KC_DEL,  KC_ENT,        KC_PGUP, UNDSCR, KC_MINS, KC_EQL,   KC_HOME,
        DF(1),    _ALT,    _GUI,   _LCTL,   KC_NO,        KC_LEFT, KC_DOWN, KC_UP,  KC_RIGHT, KC_END,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_PGDN, TILDE,  KC_SLSH, KC_QUES,  CW_TOGG,
                                 KC_TRNS,   KC_NO,        MO(5),   KC_BSPC
  ),
  [4] = LAYOUT(
      QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        _SCTL,   KC_7,     KC_8,    KC_9,     KC_MINS,
         _MEH,    _ALT,    _GUI,   _LCTL,   KC_NO,        _LCTL,   KC_4,     KC_5,    KC_6,     COMSPC,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_NO,   KC_1,     KC_2,    KC_3,     KC_PLUS,
                                   KC_NO, KC_TRNS,        KC_BSPC, KC_0
  ),
  [5] = LAYOUT(
      KC_NO,     KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,
      KC_NO,     KC_F4,   KC_F5,   KC_F6,  KC_F11,        KC_NO,   _LCTL,    _GUI,    _ALT,     _MEH,
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,    _SGUI,   _SALT,    KC_NO,
                                   KC_NO, KC_TRNS,        KC_TRNS, KC_NO
  ),
};

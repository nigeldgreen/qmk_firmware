#include QMK_KEYBOARD_H
#include <stdio.h>

#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _TMUX C(KC_F)
#define _QWERTY DF(0)
#define _COLEMAK DF(1)
#define _MOUSE DF(6)
#define _NUM MO(4)
#define _SYMTAB LT(3, KC_TAB)
#define _SYMSPC LT(2, KC_SPC)
#define _NUMESC LT(4, KC_ESC)
#define _FUNENT LT(5, KC_ENT)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _SFTZ SFT_T(KC_Z)

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _SYMSPC:
            return true;
        default:
            return false;
    }
}


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,     KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
       _SFTZ,     KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,
                                _SYMTAB, _NUMESC,        _FUNENT, _SYMSPC
  ),
  [1] = LAYOUT(
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        _SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT,
                                 _SYMTAB, _NUMESC,        _FUNENT, _SYMSPC
  ),
  [2] = LAYOUT(
       KC_GRV, KC_PLUS, KC_NUHS, KC_LCBR, KC_RCBR,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NUBS, KC_PAST, KC_EXLM, KC_LPRN, KC_RPRN,        _TMUX,   _LCTL,   _GUI,    _ALT,    _MEH,
      S(KC_3), KC_AMPR, _ATSIGN, KC_LBRC, KC_RBRC,        KC_NO,   _SCTL,   _SGUI,   _SALT,   KC_TRNS,
                                 KC_HOME,  KC_END,        KC_NO,   KC_TRNS
  ),
  [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_DLR,   _UNDSCR,  KC_MINS, KC_EQL,  S(KC_2),
         _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,KC_QUOT,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_PERC,  _TILDE,   KC_SLSH, KC_QUES, _PIPE,
                                 KC_TRNS,  _MOUSE,        KC_DEL,   KC_BSPC
  ),
  [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_LCBR,  KC_7,     KC_8,    KC_9,    KC_RCBR,
         _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,        KC_LPRN,  KC_4,     KC_5,    KC_6,    KC_RPRN,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_LBRC,  KC_1,     KC_2,    KC_3,    KC_RBRC,
                                   KC_NO, KC_TRNS,        KC_NO,    KC_0
  ),
  [5] = LAYOUT(
        KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,        _TMUX,   _LCTL,   _GUI,    _ALT,    _MEH,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,   _SGUI,   _SALT,   KC_TRNS,
                                   KC_NO,   KC_NO,        KC_TRNS, KC_NO
  ),
  [6] = LAYOUT(
        KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F12,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      _QWERTY,   KC_NO, KC_BSPC,  KC_ENT, C(KC_C),        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
        KC_NO,   KC_NO,   KC_NO,  KC_SPC, C(KC_V),        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                   KC_NO, KC_TRNS,        KC_NO,   G(KC_0)
  ),
};

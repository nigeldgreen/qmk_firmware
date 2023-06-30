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
#define _I3TAB G(KC_TAB)
#define _I3RST S(G(KC_R))
#define _I3STCK S(G(KC_S))
#define _I3MV S(G(KC_COMM))
#define _I3ASCR S(G(KC_MINS))
#define _I3SCR G(KC_MINS)
#define _I3RSCR S(G(KC_SPC))
#define _I3SPC G(KC_SPC)
#define _I3TAB G(KC_TAB)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                          KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_NO,
     KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                          KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_NO,
     KC_NO, KC_LSFT,    KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC, MEH(KC_E),  MEH(KC_C), KC_RBRC, KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                 KC_Z,   MO(6), _SYMTAB, _NUMESC, KC_QUOT,     S(KC_2),  _FUNENT, _SYMSPC,  MO(6),    KC_CAPS
  ),
  [1] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                          KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN, KC_NO,
     KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                          KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    KC_NO,
     KC_NO, KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V, DF(0), MEH(KC_E),     MEH(KC_C), _LCTL,  KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                 KC_Z,   MO(6), _SYMTAB, _NUMESC, KC_QUOT,     S(KC_2),  _FUNENT, _SYMSPC,  MO(6),    KC_CAPS
  ),
  [2] = LAYOUT(
     KC_NO,  KC_GRV, KC_PERC, KC_NUHS, KC_AMPR, KC_PLUS,                                          KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO, KC_NUBS, KC_PAST, KC_EXLM, KC_LPRN, KC_RPRN,                                          C(KC_F),  _LCTL,    _GUI,    _ALT,    _MEH,    KC_NO,
     KC_NO, KC_TRNS, _PIPE,   _ATSIGN,  KC_DLR,   KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_NO,
                              KC_TRNS,   KC_NO,   KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_TRNS,  KC_NO,    KC_TRNS
  ),
  [3] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                          KC_PGUP,  _UNDSCR,  KC_MINS, KC_EQL,  KC_HOME, KC_NO,
     KC_NO,    _MEH,    _ALT,    _GUI,   _LCTL,  KC_DEL,                                          KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,KC_END,  KC_NO,
     KC_NO, KC_TRNS,   _SALT,   _SGUI,   _SCTL,  KC_ENT, DF(7), KC_NO,              KC_NO, KC_NO, KC_PGDN,  _TILDE,   KC_SLSH, KC_QUES, KC_TRNS,   KC_NO,
                              KC_TRNS,   KC_NO, KC_TRNS, KC_NO, KC_NO,              KC_NO, KC_NO, KC_BSPC,  KC_NO,    KC_TRNS
  ),
  [4] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,                                          KC_NO,    KC_7,     KC_8,    KC_9,    KC_PLUS,   KC_NO,
     KC_NO,    _MEH,    _ALT,    _GUI,   _LCTL, C(KC_F),                                          KC_NO,    KC_4,     KC_5,    KC_6,    KC_MINS,   KC_NO,
     KC_NO, KC_TRNS,   _SALT,   _SGUI,   _SCTL, KC_LBRC,   KC_NO, KC_NO,            KC_NO, KC_NO, KC_RBRC,  KC_1,     KC_2,    KC_3,    _UNDSCR,   KC_NO,
                              KC_TRNS,   KC_NO, KC_TRNS,   KC_NO, KC_NO,            KC_NO, KC_NO, KC_0,     KC_NO,    KC_TRNS
  ),
  [5] = LAYOUT(
     KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                          KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                          C(KC_F),  _LCTL,    _GUI,    _ALT,    _MEH,    KC_NO,
     KC_NO, KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_NO,
                              KC_TRNS,   KC_NO,   KC_NO, KC_NO, KC_NO,            KC_NO, KC_TRNS, KC_NO,    KC_NO,    KC_TRNS
  ),
  [6] = LAYOUT(
     KC_NO, _I3QUIT, _I3TABS, G(KC_E),  _I3RST,   KC_NO,                                          KC_NO,    G(KC_7),  G(KC_8), G(KC_9), _I3ASCR, KC_NO,
     KC_NO,   KC_NO, _I3STCK,   KC_NO, KC_LSFT,   KC_NO,                                          _I3MV,    G(KC_4),  G(KC_5), G(KC_6),  _I3SCR, KC_NO,
     KC_NO, KC_TRNS, G(KC_X),   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,    G(KC_1),  G(KC_2), G(KC_3), _I3RSCR, KC_NO,
                              KC_TRNS,   KC_NO,  _I3TAB, KC_NO, KC_NO,          KC_NO, G(KC_ENT), _I3SPC,   G(KC_0),    KC_TRNS
  ),
  [7] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_F8,   KC_F9,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_Z,   KC_NO,                                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, DF(0), KC_NO,              KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,              KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO
  ),
};

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _SYMSPC:
            return true;
        case _SYMTAB:
            return true;
        case _NUMESC:
            return true;
        case _FUNENT:
            return true;
        default:
            return false;
    }
}

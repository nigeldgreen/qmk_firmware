#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWER,
  _CMAK,
  _SYML,
  _SYMR,
  _NUM,
  _FUN,
  _I3,
};

#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _SFT_Z SFT_T(KC_Z)
#define _SYMR_TAB LT(_SYMR, KC_TAB)
#define _NUM_ESC LT(_NUM, KC_ESC)
#define _SYML_ENT LT(_SYML, KC_ENT)
#define _FUN_DEL LT(_FUN, KC_DEL)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _I3SHFT LM(_I3, MOD_LSFT)
#define _I3SCR G(KC_MINS)
#define _I3SCRMV S(G(KC_MINS))
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | Q         | W         | E         | R         | T         |   | Y         | U         | I         | O         | P         |
      KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,           KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | A         | S         | D         | F         | G         |   | H         | J         | K         | L         | ;         |
      KC_A,       KC_S,       KC_D,       KC_F,       KC_G,           KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | Z         | X         | C         | V         | B         |   | N         | M         | ,         | .         | Z         |
      KC_LSFT,    KC_X,       KC_C,       KC_V,       KC_B,           KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_RSFT,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | > _SYM    | > _NUM    |   | > _SYML    | Space     |
                                          _SYMR_TAB,  _NUM_ESC,       _SYML_ENT,  KC_SPC
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_CMAK] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | Q         | W         | F         | P         | B         |   | J         | L         | U         | Y         | ;         |
      KC_Q,       KC_W,       KC_F,       KC_P,       KC_B,           KC_J,       KC_L,       KC_U,       KC_Y,       KC_SCLN,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | A         | R         | S         | T         | G         |   | M         | N         | E         | I         | O         |
      KC_A,       KC_R,       KC_S,       KC_T,       KC_G,           KC_M,       KC_N,       KC_E,       KC_I,       KC_O,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | Z         | X         | C         | D         | V         |   | K         | H         | ,         | .         | Z         |
      KC_LSFT,    KC_X,       KC_C,       KC_D,       KC_V,           KC_K,       KC_H,       KC_COMM,    KC_DOT,     KC_RSFT,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | > _SYM    | > _NUM    |   | > _SYML    | Space     |
                                          _SYMR_TAB,  _NUM_ESC,       _SYML_ENT,  KC_SPC
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_SYML] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | `         | +         | #         | {         | }         |   | --        | --        | --        | --        | --        |
      KC_GRV,    KC_PLUS,     KC_NUHS,    KC_LCBR,    KC_RCBR,        TO(_QWER),  TO(_CMAK),  KC_NO,      KC_NO,      KC_NO,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | \         | *         | !         | (         | )         |   | --        | CTRL      | WIN KEY   | ALT       | CTLSFTALT         |
      KC_NUBS,    KC_PAST,    KC_EXLM,    KC_LPRN,    KC_RPRN,        KC_NO,      _LCTL,      _GUI,       _ALT,       _MEH,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | £         | &         | @         | [         | ]         |   | --        | S CTRL    | S WIN     | S ALT     | SHIFT     |
      S(KC_3),    KC_AMPR,    _ATSIGN,    KC_LBRC,    KC_RBRC,        KC_NO,      _SCTL,      _SGUI,      _SALT,      KC_TRNS,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | > _I3     | > S _I3   |   | --        | --        |
                                          MO(_I3),    _I3SHFT,        KC_TRNS,    KC_NO
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_SYMR] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | --        | --        | --        | --        | --        |   | $         | _         | -         | =         | '         |
      KC_NO,      KC_NO,      KC_NO,      KC_F8,      KC_F2,          KC_DLR,     _UNDSCR,    KC_MINS,    KC_EQL,     KC_QUOT,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | CTLSFTALT | ALT       | WIN KEY   | CTRL      | --        |   | LEFT      | DOWN      | UP        | RIGHT     | "         |
      _MEH,       _ALT,       _GUI,       _LCTL,      KC_DEL,         KC_LEFT,    KC_DOWN,    KC_UP,      KC_RIGHT,   S(KC_2),
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | SFT_Z     | S ALT     | S WIN     | S CTRL    | --        |   | %         | ~         | /         | ?         | |         |
      KC_TRNS,    _SALT,      _SGUI,      _SCTL,      KC_ENT,         KC_PERC,    _TILDE,     KC_SLSH,    KC_QUES,    _PIPE,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | --        | --        |   | DEL       | BSPC      |
                                          KC_TRNS,    KC_NO,          _FUN_DEL,   KC_BSPC
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_NUM] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | --        | --        | --        | --        | --        |   | PAGE UP   | 7         | 8         | 9         | HOME      |
      KC_NO,      KC_NO,      KC_NO,      KC_F8,      KC_F2,          KC_PGUP,    KC_7,       KC_8,       KC_9,       KC_HOME,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | CTLSFTALT | ALT       | WIN KEY   | CTRL      | --        |   | Z         | 4         | 5         | 6         | END       |
      _MEH,       _ALT,       _GUI,       _LCTL,      KC_DEL,         KC_Z,       KC_4,       KC_5,       KC_6,       KC_END,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | SFT_Z     | S ALT     | S WIN     | S CTRL    | --        |   | PAGE DOWN | 1         | 2         | 3         | --        |
      KC_TRNS,    _SALT,      _SGUI,      _SCTL,      KC_ENT,         KC_PGDN,    KC_1,       KC_2,       KC_3,       KC_NO,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | --        | --        |   | --        | 0         |
                                          KC_NO,      KC_TRNS,        KC_NO,      KC_0
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_FUN] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | --        | F7        | F8        | F9        | F10       |   | --        | --        | --        | --        | --        |
      KC_NO,      KC_F7,      KC_F8,      KC_F9,      KC_F10,         TO(_QWER),  TO(_CMAK),  KC_NO,      KC_NO,      KC_NO,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | KB_BOOT   | F4        | F5        | F6        | F11       |   | --        | CTRL      | WIN KEY   | ALT       | CTLSFTALT
      QK_BOOT,    KC_F4,      KC_F5,      KC_F6,      KC_F11,         KC_NO,      _LCTL,      _GUI,       _ALT,       _MEH,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//  | --        | F1        | F2        | F3        | F12       |   | --        | S CTRL    | S WIN     | S ALT     | SHIFT     |
      KC_NO,      KC_F1,      KC_F2,      KC_F3,      KC_F12,         KC_NO,      _SCTL,      _SGUI,      _SALT,      KC_TRNS,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|-----------|
//                                      | --        | --        |   | --        | --        |
                                          KC_NO,      KC_NO,          KC_TRNS,    KC_NO
//                                      |-----------|-----------|   |-----------|-----------|
  ),
  [_I3] = LAYOUT(
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|--------------|
//  | --        | --        | --        | --        | --        |   | --        | WS 7      | WS 8      | LOCK SCN  | SCRATCH MOVE |
      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      G(KC_7),    G(KC_8),    G(KC_9),    _I3SCRMV,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|--------------|
//  | --        | --        | --        | --        | --        |   | --        | WS 4      | WS 5      | WS 6      | SHOW SCRATCH |
      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      G(KC_4),    G(KC_5),    G(KC_6),    _I3SCR,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|--------------|
//  | --        | --        | --        | --        | --        |   | --        | WS 1      | WS 2      | WS 3      | --           |
      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,          KC_NO,      G(KC_1),    G(KC_2),    G(KC_3),    KC_NO,
//  |-----------|-----------|-----------|-----------|-----------|   |-----------|-----------|-----------|-----------|--------------|
//                                      | --        | --        |   | > _NUM    | PWR MENU  |
                                          KC_TRNS,    KC_TRNS,        KC_NO,      G(KC_0)
//                                      |-----------|-----------|   |-----------|-----------|
  ),
};

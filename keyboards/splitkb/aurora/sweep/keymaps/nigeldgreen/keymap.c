#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWER,
  _CMAK,
  _SYMR,
  _SYML,
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
#define _CTLSPC C(KC_SPC)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _I3SHFT LM(_I3, MOD_LSFT)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
       KC_Q,   KC_W,      KC_E,     KC_R,        KC_T,             KC_Y,      KC_U,       KC_I,    KC_O,     KC_P,
       KC_A,   KC_S,      KC_D,     KC_F,        KC_G,             KC_H,      KC_J,       KC_K,    KC_L,     KC_SCLN,
SFT_T(KC_Z),   KC_X,      KC_C,     KC_V,        KC_B,             KC_N,      KC_M,       KC_COMM, KC_DOT,   KC_RSFT,
                 LT(_SYMR, KC_TAB),  LT(_NUM, KC_ESC),             LT(_FUN, KC_ENT),  LT(_SYML, KC_SPC)
  ),
  [_CMAK] = LAYOUT(
       KC_Q,   KC_W,      KC_F,     KC_P,        KC_B,             KC_J,      KC_L,      KC_U,     KC_Y,     KC_SCLN,
       KC_A,   KC_R,      KC_S,     KC_T,        KC_G,             KC_M,      KC_N,      KC_E,     KC_I,     KC_O,
SFT_T(KC_Z),   KC_X,      KC_C,     KC_D,        KC_V,             KC_K,      KC_H,      KC_COMM,  KC_DOT,   KC_RSFT,
                 LT(_SYMR, KC_TAB),  LT(_NUM, KC_ESC),             LT(_FUN, KC_ENT),  LT(_SYML, KC_SPC)
  ),
  [_SYMR] = LAYOUT(
      KC_NO,  KC_NO,     KC_NO,     KC_NO,    QK_BOOT,             KC_DLR,   _UNDSCR,    KC_MINS,  KC_EQL,   KC_QUOT,
       _MEH,   _ALT,      _GUI,     _LCTL,    _CTLSPC,             KC_LEFT,   KC_DOWN,   KC_UP,    KC_RIGHT, S(KC_2),
    KC_TRNS,  _SALT,     _SGUI,     _SCTL,      KC_NO,             KC_PERC,   _TILDE,    KC_SLSH,  KC_QUES,  _PIPE,
                                    KC_TRNS,    KC_NO,             KC_DEL,    KC_BSPC
  ),
  [_SYML] = LAYOUT(
     KC_GRV, KC_PLUS,  KC_NUHS,   KC_LCBR,    KC_RCBR,             DF(_QWER), DF(_CMAK), KC_NO,    KC_NO,    KC_NO,
    KC_NUBS, KC_PAST,  KC_EXLM,   KC_LPRN,    KC_RPRN,             _CTLSPC,   _LCTL,     _GUI,     _ALT,     _MEH,
    S(KC_3), KC_AMPR,  _ATSIGN,   KC_LBRC,    KC_RBRC,             KC_NO,     _SCTL,     _SGUI,    _SALT,    KC_TRNS,
                                  MO(_I3),    _I3SHFT,             KC_TRNS,   KC_NO
  ),
  [_NUM] = LAYOUT(
      KC_NO,   KC_NO,    KC_NO,     KC_NO,    QK_BOOT,             KC_PGUP,   KC_7,      KC_8,     KC_9,     KC_HOME,
       _MEH,    _ALT,     _GUI,     _LCTL,    _CTLSPC,             KC_NO,     KC_4,      KC_5,     KC_6,     KC_END,
    KC_TRNS,   _SALT,    _SGUI,     _SCTL,      KC_NO,             KC_PGDN,   KC_1,      KC_2,     KC_3,     KC_TRNS,
                                    KC_NO,    KC_TRNS,             KC_BSPC,   KC_0
  ),
  [_FUN] = LAYOUT(
      KC_NO,   KC_F7,    KC_F8,     KC_F9,     KC_F10,             DF(_QWER), DF(_CMAK), KC_NO,    KC_NO,    KC_NO,
      KC_NO,   KC_F4,    KC_F5,     KC_F6,     KC_F11,             _CTLSPC,   _LCTL,     _GUI,     _ALT,     _MEH,
    KC_TRNS,   KC_F1,    KC_F2,     KC_F3,     KC_F12,             KC_NO,     _SCTL,     _SGUI,    _SALT,    KC_TRNS,
                                    KC_NO,    KC_CAPS,             KC_TRNS,   KC_NO
  ),
  [_I3] = LAYOUT(
      KC_NO,   KC_NO,  G(KC_E),     KC_NO,    G(KC_Q),             G(KC_MINS), G(KC_7),  G(KC_8),  G(KC_9),  KC_NO,
      KC_NO,   KC_NO,    KC_NO,   KC_LSFT,    G(KC_R),             G(KC_LT),   G(KC_4),  G(KC_5),  G(KC_6),  KC_NO,
    KC_TRNS,   KC_NO,    KC_NO,     KC_NO,    G(KC_W),             KC_NO,      G(KC_1),  G(KC_2),  G(KC_3),  KC_TRNS,
                                  KC_TRNS,    KC_TRNS,             KC_NO,      G(KC_0)
  ),
};

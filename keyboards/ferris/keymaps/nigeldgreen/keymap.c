#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWER,
  _CMAK,
  _SYM1,
  _SYM2,
  _NUM,
  _NAV,
  _FUN,
};

#define COMBO_COUNT 15
uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM cmb_esc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_caps_word[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_tmux[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_caps_word, CW_TOGG),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_tmux, C(KC_SPC)),
    COMBO(cmb_lcbr, KC_LCBR),
    COMBO(cmb_rcbr, KC_RCBR),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
};

/* RIGHT HAND LAYOUT */
/*     Y   U   I   O   P */
/*     J  LTH  K   L   ; */
/*     M   ,  RTH SFT  H */
/*     .   N */
#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _LSFT OSM(MOD_LSFT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _MVSCRT SGUI(KC_MINS)
#define _SHSCRT G(KC_MINS)
#define _KTYCFG RCS(KC_F2)
#define _KTYRST RCS(KC_F5)
#define _REBOOT QK_BOOTLOADER
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
    KC_Q,      KC_W,      KC_E,     KC_R,       KC_T,              KC_Y,      KC_U,       KC_I,    KC_O,     KC_P,
    KC_A,      KC_S,      KC_D,     KC_F,       KC_G,              KC_J,      MO(_SYM2),  KC_K,    KC_L,     KC_SCLN,
    KC_Z,      KC_X,      KC_C,     KC_V,       KC_B,              KC_M,      KC_COMM,    KC_SPC,  KC_RSFT,  KC_H,
                                MO(_NUM),  MO(_SYM1),              KC_DOT,    KC_N
  ),
  [_CMAK] = LAYOUT(
    KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,              KC_J,      KC_L,       KC_U,    KC_Y,     KC_SCLN,
    KC_A,      KC_R,      KC_S,      KC_T,      KC_G,              KC_N,      MO(_SYM2),  KC_E,    KC_I,     KC_O,
    KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,              KC_H,      KC_COMM,    KC_SPC,  KC_RSFT,  KC_M,
                                 MO(_NUM), MO(_SYM1),              KC_DOT,    KC_K
  ),
  [_SYM1] = LAYOUT(
    KC_NO,    KC_NO,   _MVSCRT,   _SHSCRT,     KC_NO,              KC_NO,     _UNDSCR,    KC_MINS, KC_EQL,   KC_PAST,
    _LSFT,     _ALT,      _GUI,     _LCTL,      _MEH,              KC_QUOT,   MO(_FUN),   S(KC_2), KC_CIRC,  C(KC_6),
    KC_NO,    KC_NO,     KC_NO,     _SGUI,     KC_NO,              _TILDE,    KC_SLSH,    KC_BSPC, KC_TRNS,  KC_NO,
                                    KC_NO,   KC_TRNS,              KC_NUBS,   KC_NO
  ),
  [_SYM2] = LAYOUT(
     KC_GRV,  KC_DLR,  KC_PLUS,   KC_NUHS,     KC_NO,              KC_NO,     KC_NO,      KC_NO,   KC_NO,    KC_NO,
    S(KC_3), KC_PERC,  KC_EXLM,   KC_QUES,     KC_NO,              _LCTL,     KC_TRNS,    _GUI,    _ALT,     _LSFT,
    KC_TRNS, KC_AMPR,    _PIPE,   _ATSIGN,     KC_NO,              KC_NO,     KC_NO,      KC_NO,   KC_NO,      _MEH,
                                 MO(_NAV),     KC_NO,              KC_NO,     KC_NO
  ),
  [_NUM] = LAYOUT(
      KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO,             KC_LEFT,    KC_7,       KC_8,    KC_9,     KC_RIGHT,
      _LSFT,    _ALT,     _GUI,     _LCTL,      _MEH,             KC_4,       KC_BSPC,    KC_5,    KC_6,     KC_NO,
    KC_TRNS,   KC_NO,    KC_NO,     KC_NO,    KC_DEL,             KC_1,       KC_2,       KC_0,    KC_TRNS,  KC_NO,
                                  KC_TRNS,     KC_NO,             KC_3,       KC_NO
  ),
  [_NAV] = LAYOUT(
      KC_NO,   KC_NO,    KC_NO,     KC_NO,     KC_NO,              KC_PGUP,   KC_HOME,    KC_NO,   KC_NO,    KC_NO,
      _LSFT,    _ALT,     _GUI,     _LCTL,      _MEH,              KC_DOWN,   KC_NO,      KC_UP,   KC_RIGHT, KC_NO,
    KC_TRNS,   KC_NO,    _SCTL,     _SGUI,     KC_NO,              KC_END,    KC_NO,      KC_NO,   KC_TRNS,  KC_LEFT,
                                  KC_TRNS,     KC_NO,              KC_NO,     KC_PGDN
  ),
  [_FUN] = LAYOUT(
      KC_NO,   KC_F7,    KC_F8,     KC_F9,    KC_F10,              DF(_QWER), DF(_CMAK),  KC_NO,   KC_NO,    KC_NO,
    _KTYCFG,   KC_F4,    KC_F5,     KC_F6,    KC_F11,              _LCTL,     KC_TRNS,    _GUI,    _ALT,     _LSFT,
    _KTYRST,   KC_F1,    KC_F2,     KC_F3,    KC_F12,              KC_NO,     KC_NO,      KC_NO,   KC_NO,    _MEH,
                                  _REBOOT,   KC_LCTL,              KC_NO,     KC_NO
  ),
};


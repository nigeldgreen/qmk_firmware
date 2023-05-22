#include QMK_KEYBOARD_H

enum ferris_layers {
  _QWER,
  _CMAK,
  _SYM,
  _NUM,
};

/* Define our QWERTY home row mods */
#define _ALT_A ALT_T(KC_A)
#define _GUI_S GUI_T(KC_S)
#define _SFT_D SFT_T(KC_D)
#define _CTL_F CTL_T(KC_F)
#define _CTL_J CTL_T(KC_J)
#define _SFT_K SFT_T(KC_K)
#define _GUI_L GUI_T(KC_L)
#define _ALT_SC ALT_T(KC_SCLN)

/* Define our Colemak home row mods */
#define _GUI_R GUI_T(KC_R)
#define _SFT_S SFT_T(KC_S)
#define _CTL_T CTL_T(KC_T)
#define _CTL_N CTL_T(KC_N)
#define _SFT_E SFT_T(KC_E)
#define _GUI_I GUI_T(KC_I)
#define _ALT_O ALT_T(KC_O)

/* Define our layer switching keys */
#define _SYM_TAB LT(_SYM, KC_TAB)
#define _NUM_ESC LT(_NUM, KC_ESC)
#define _NUM_ENT LT(_NUM, KC_ENT)
#define _SYM_SPC LT(_SYM, KC_SPC)

/* Define some character keys to keep letter count low */
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)

/* RIGHT HAND LAYOUT */
/*     Y   U   I   O   P */
/*     J  LTH  K   L   ; */
/*     M   ,  RTH SFT  H */
/*     .   N */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
       KC_Q,     KC_W,     KC_E,      KC_R,     KC_T,      KC_Y,      KC_U,     KC_I,     KC_O,      KC_P,
     _ALT_A,   _GUI_S,   _SFT_D,    _CTL_F,     KC_G,      _CTL_J,    _NUM_ENT, _SFT_K,   _GUI_L,    _ALT_SC,
       KC_Z,     KC_X,     KC_C,      KC_V,     KC_B,      KC_M,      KC_COMM,  _SYM_SPC, KC_NO,    KC_H,
                                  _NUM_ESC, _SYM_TAB,      KC_DOT,     KC_N
  ),
  [_CMAK] = LAYOUT(
       KC_Q,     KC_W,     KC_F,      KC_P,     KC_B,      KC_J,      KC_L,     KC_U,     KC_Y,      KC_SCLN,
     _ALT_A,   _GUI_R,   _SFT_S,    _CTL_T,     KC_G,      KC_M,      _CTL_N,   _SFT_E,   _GUI_I,    _ALT_O,
       KC_Z,     KC_X,     KC_C,      KC_D,     KC_V,      KC_K,      KC_H,     KC_COMM,  KC_DOT,    KC_NO,
                                  _NUM_ESC, _SYM_TAB,      _NUM_ENT,  _SYM_SPC
  ),
  [_SYM] = LAYOUT(
     KC_GRV,  KC_PLUS,  KC_NUHS,   KC_LCBR,  KC_RCBR,      KC_DLR,    _UNDSCR,  KC_MINS,  KC_EQL,    KC_QUOT,
    KC_NUBS,  KC_PAST,  KC_EXLM,   KC_LPRN,  KC_RPRN,      KC_DOWN,   KC_DEL,   KC_UP,    KC_RIGHT,  S(KC_2),
    S(KC_3),  KC_AMPR,  _ATSIGN,   KC_LBRC,  KC_RBRC,      _TILDE,    KC_SLSH,  KC_BSPC,  _PIPE,     KC_LEFT,
                                     KC_NO,    KC_NO,      KC_QUES, KC_PERC
  ),
  [_NUM] = LAYOUT(
      KC_NO,    KC_F7,    KC_F8,     KC_F9,   KC_F10,      KC_PGUP,   KC_7,     KC_8,     KC_9,      KC_HOME,
    QK_BOOT,    KC_F4,    KC_F5,     KC_F6,   KC_F11,      KC_4,      KC_BSPC,  KC_5,     KC_6,      KC_END,
      KC_NO,    KC_F1,    KC_F2,     KC_F3,   KC_F12,      KC_1,      KC_2,     KC_0,     KC_NO,      KC_NO,
                                     KC_NO,    KC_NO,      KC_3,   KC_PGDN
  ),
};

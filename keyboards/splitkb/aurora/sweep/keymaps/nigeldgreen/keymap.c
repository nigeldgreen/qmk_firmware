#include QMK_KEYBOARD_H

/* Define our QWERTY home row mods */
#define _ALT_A ALT_T(KC_A)
#define _ALT_SC ALT_T(KC_SCLN)
#define _GUI_S GUI_T(KC_S)
#define _GUI_L GUI_T(KC_L)
#define _SFT_D SFT_T(KC_D)
#define _SFT_K SFT_T(KC_K)
#define _CTL_F CTL_T(KC_F)
#define _CTL_J CTL_T(KC_J)
#define _MEH_G MEH_T(KC_G)
#define _MEH_H MEH_T(KC_H)
/* Define our layer switching keys */
#define _SYM_TAB LT(1, KC_TAB)
#define _SYM_ENT LT(2, KC_ENT)
#define _NUM_ESC LT(3, KC_ESC)

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _ALT_A:
        case _ALT_SC:
        case _GUI_S:
        case _GUI_L:
        case _SFT_D:
        case _SFT_K:
        case _CTL_F:
        case _CTL_J:
        case _MEH_G:
        case _MEH_H:
        case _SYM_TAB:
        case _NUM_ESC:
        case _SYM_ENT:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
         KC_Q,       KC_W,     KC_E,       KC_R,      KC_T,           KC_Y,      KC_U,       KC_I,     KC_O,     KC_P,
       _ALT_A,     _GUI_S,   _SFT_D,     _CTL_F,    _MEH_G,           _MEH_H,    _CTL_J,     _SFT_K,   _GUI_L,   _ALT_SC,
      SC_LSPO,       KC_X,     KC_C,       KC_V,      KC_B,           KC_N,      KC_M,       KC_COMM,  KC_DOT,   SC_RSPC,
                                       _SYM_TAB,  _NUM_ESC,           _SYM_ENT,  KC_SPC
  ),
  [1] = LAYOUT(
        KC_NO,      KC_NO,  KC_BSPC,     KC_DEL,     KC_NO,           KC_PGUP,   S(KC_MINS), KC_MINS,  KC_EQL,   KC_HOME,
        KC_NO,      KC_NO,   KC_SPC,     KC_ENT,     KC_NO,           KC_LEFT,   KC_DOWN,    KC_UP,    KC_RIGHT, KC_END,
      C(KC_Z),    C(KC_X),  C(KC_C),    C(KC_V),     KC_NO,           KC_PGDN,   S(KC_NUHS), KC_SLSH,  KC_QUES,  CW_TOGG,
                                        KC_TRNS,     KC_NO,           KC_DEL,    KC_BSPC
  ),
  [2] = LAYOUT(
       KC_GRV,    KC_PLUS,  KC_LCBR,    KC_RCBR,   S(KC_2),           KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,
      KC_NUBS,    KC_NUHS,  KC_LPRN,    KC_RPRN,   KC_QUOT,           KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,
         KC_Z, S(KC_QUOT),  KC_LBRC,    KC_RBRC,     KC_NO,           KC_NO,     KC_NO,      KC_NO,    KC_NO,    KC_NO,
                                        KC_TRNS,     KC_NO,           KC_TRNS,   KC_NO
  ),
  [3] = LAYOUT(
        KC_NO,      KC_F7,    KC_F8,      KC_F9,    KC_F10,           KC_NO,     KC_7,       KC_8,     KC_9,     KC_NO,
      QK_BOOT,      KC_F4,    KC_F5,      KC_F6,    KC_F11,           KC_NO,     KC_4,       KC_5,     KC_6,     KC_NO,
        KC_NO,      KC_F1,    KC_F2,      KC_F3,    KC_F12,           KC_NO,     KC_1,       KC_2,     KC_3,     KC_NO,
                                          KC_NO,   KC_TRNS,           KC_BSPC,   KC_0
  ),
};

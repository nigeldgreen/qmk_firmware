#include QMK_KEYBOARD_H
#define COMBO_COUNT 3
uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_esc[] = {KC_E, KC_R, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_esc, KC_ESC),
};

enum ferris_layers {
  _QWERTY,
  _NUMBERS,
  _SYMBOLS,
  _NAV,
  _FNKEYS,
};

#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)

/* RIGHT HAND LAYOUT */
/*     Y   U   I   O   P */
/*     J  LTH  K   L   ; */
/*     M   ,  RTH SFT  H */
/*     .   N */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    KC_Q,    KC_W,       KC_E,         KC_R,       KC_T,              KC_Y,  KC_U,            KC_I,     KC_O,      KC_P,
    KC_A,    KC_S,       KC_D,         KC_F,       KC_G,              KC_J,  MO(_NUMBERS),    KC_K,     KC_L,      KC_SCLN,
    KC_LSFT, KC_X,       KC_C,         KC_V,       KC_B,              KC_M,  KC_COMM,         KC_SPC,   KC_LSFT,   KC_H,
                                  MO(_NUMBERS), KC_LCTL,              KC_DOT, KC_N
  ),
  [_NUMBERS] = LAYOUT(
    KC_NO,   KC_NO,   KC_NO,        KC_NO,        KC_NO,              KC_LEFT, KC_7,         KC_8,    KC_9,    KC_RIGHT,
    _MEH,    _ALT,    _SGUI,        _GUI,      MO(_NAV),              KC_4,    MO(_SYMBOLS), KC_5,    KC_6,    KC_NO,
    KC_TRNS, KC_Z,    KC_NO,        KC_NO,       KC_DEL,              KC_1,    KC_2,         KC_BSPC, KC_TRNS, MO(_FNKEYS),
                                  MO(_SYMBOLS), KC_LCTL,              KC_3,    KC_0
  ),
  [_SYMBOLS] = LAYOUT(
    KC_GRV,  KC_DLR,  KC_PLUS,      KC_NUHS,    KC_LCBR,              KC_RCBR,    S(KC_MINS), KC_MINS, KC_EQL,  KC_PAST,
    S(KC_3), KC_PERC, KC_EXLM,      KC_QUES,    KC_LPRN,              KC_QUOT,    MO(_NAV),   S(KC_2), KC_CIRC, C(KC_6),
    KC_TRNS, KC_AMPR, S(KC_NUBS),   S(KC_QUOT), KC_LBRC,              S(KC_NUHS), KC_SLSH,    KC_DEL,  KC_TRNS, KC_RPRN,
                                    KC_TRNS,    KC_LCTL,              KC_NUBS, KC_RBRC
  ),
  [_NAV] = LAYOUT(
    KC_NO,   KC_NO,   RCS(KC_PGUP), C(KC_PGUP),   KC_NO,              KC_PGUP, KC_HOME,      KC_NO,       KC_NO,    KC_NO,
    KC_NO,   KC_NO,   KC_NO,        KC_NO,        KC_NO,              KC_DOWN, SGUI(KC_DOT), KC_UP,       KC_RIGHT, KC_NO,
    KC_TRNS, KC_NO,   KC_NO,        KC_NO,        KC_NO,              KC_END,  KC_NO,        G(KC_RIGHT), KC_TRNS,  KC_LEFT,
                                         _SCTL, KC_LCTL,              KC_TRNS, KC_PGDN
  ),
  [_FNKEYS] = LAYOUT(
    KC_NO,      KC_F7,    KC_F8,       KC_F9,    KC_F10,              KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,
    RCS(KC_F2), KC_F4,    KC_F5,       KC_F6,    KC_F11,              KC_NO, KC_NO,    KC_NO,    KC_NO,    KC_NO,
    RCS(KC_F5), KC_F1,    KC_F2,       KC_F3,    KC_F12,              KC_NO, KC_NO,    KC_NO,    KC_TRNS,    KC_NO,
                                 QK_BOOTLOADER, KC_LCTL,              KC_NO, KC_NO
  ),
};


#include QMK_KEYBOARD_H

#define COMBO_COUNT 13
uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM cmb_leader[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_esc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_bsp[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_i3_launch[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_i3_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_z[] = {KC_LSFT, KC_X, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_leader, QK_LEAD),
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_bsp, KC_BSPC),
    COMBO(cmb_del, KC_DEL),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_i3_launch, G(KC_SPC)),
    COMBO(cmb_i3_tab, G(KC_TAB)),
    COMBO(cmb_z, KC_Z),
};

void leader_end_user(void) {
    if (leader_sequence_two_keys(KC_R, KC_R)) {
        reset_keyboard();
        /* kitty maps */
    } else if (leader_sequence_two_keys(KC_K, KC_C)) {
        tap_code16(RCS(KC_F2));
    } else if (leader_sequence_two_keys(KC_K, KC_R)) {
        tap_code16(RCS(KC_F5));
        /* single and double clicks for brackets */
    } else if (leader_sequence_one_key(KC_F)) {
        tap_code16(KC_LPRN);
    } else if (leader_sequence_one_key(KC_D)) {
        tap_code16(KC_LCBR);
    } else if (leader_sequence_one_key(KC_G)) {
        tap_code16(KC_LBRC);
    } else if (leader_sequence_two_keys(KC_F, KC_F)) {
        tap_code16(KC_RPRN);
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        tap_code16(KC_RCBR);
    } else if (leader_sequence_two_keys(KC_G, KC_G)) {
        tap_code16(KC_RBRC);
    } else if (leader_sequence_three_keys(KC_F, KC_F, KC_F)) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_D)) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
    } else if (leader_sequence_three_keys(KC_G, KC_G, KC_G)) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
    }
}


#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _LSFT OSM(MOD_LSFT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _CTLSPC C(KC_SPC)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _SYMTAB LT(_SYM1, KC_TAB)
#define _NUMESC LT(_NUM, KC_ESC)
#define _SYMSPC LT(_SYM2, KC_SPC)
#define _FUNENT LT(_FUN, KC_ENT)

enum ferris_layers {
  _QWER,
  _CMAK,
  _SYM1,
  _SYM2,
  _NUM,
  _FUN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
    KC_Q,      KC_W,      KC_E,     KC_R,        KC_T,             KC_Y,      KC_U,       KC_I,    KC_O,     KC_P,
    KC_A,      KC_S,      KC_D,     KC_F,        KC_G,             KC_H,      KC_J,       KC_K,    KC_L,     KC_SCLN,
    KC_LSFT,   KC_X,      KC_C,     KC_V,        KC_B,             KC_N,      KC_M,       KC_COMM, KC_DOT,   KC_RSFT,
                                MO(_NUM),   MO(_SYM1),             KC_SPC,    MO(_SYM2)
  ),
  [_CMAK] = LAYOUT(
    KC_Q,      KC_W,      KC_F,      KC_P,       KC_B,             KC_J,      KC_L,       KC_U,    KC_Y,     KC_SCLN,
    KC_A,      KC_R,      KC_S,      KC_T,       KC_G,             KC_M,      KC_N,       KC_E,    KC_I,     KC_O,
    KC_LSFT,   KC_X,      KC_C,      KC_D,       KC_V,             KC_K,      KC_H,      KC_COMM,  KC_DOT,   KC_RSFT,
                                 MO(_NUM),  MO(_SYM1),             KC_SPC,    MO(_SYM2)
  ),
  [_SYM1] = LAYOUT(
    KC_NO,    KC_NO,     KC_NO,     KC_NO,      KC_NO,             KC_QUOT,   _UNDSCR,    KC_MINS, KC_EQL,   KC_PAST,
    _MEH,      _ALT,      _GUI,     _LCTL,    _CTLSPC,             KC_LEFT,   KC_DOWN,    KC_UP,   KC_RIGHT, KC_CIRC,
    KC_TRNS,  KC_NO,     _SGUI,     _SCTL,      KC_NO,             S(KC_2),   _TILDE,    KC_SLSH,  KC_NUBS,  KC_TRNS,
                                    KC_NO,    KC_TRNS,             KC_BSPC,   MO(_FUN)
  ),
  [_SYM2] = LAYOUT(
     KC_GRV,  KC_DLR,  KC_PLUS,   KC_NUHS,      KC_NO,             KC_NO,     KC_NO,      KC_NO,   KC_NO,    KC_NO,
    S(KC_3), KC_PERC,  KC_EXLM,   KC_QUES,      KC_NO,             _CTLSPC,   _LCTL,      _GUI,    _ALT,     _MEH,
    KC_TRNS, KC_AMPR,    _PIPE,   _ATSIGN,      KC_NO,             KC_NO,     _SCTL,      _SGUI,   KC_NO,    KC_NO,
                                    KC_NO,      KC_NO,             KC_NO,     KC_TRNS
  ),
  [_NUM] = LAYOUT(
      KC_NO,   KC_NO,    KC_NO,     KC_NO,      KC_NO,             KC_PGUP,   KC_7,      KC_8,   KC_9,      KC_HOME,
     _MEH,      _ALT,     _GUI,     _LCTL,    _CTLSPC,             KC_NO,     KC_4,      KC_5,   KC_6,      KC_END,
     KC_TRNS,  KC_NO,    _SGUI,     _SCTL,      KC_NO,             KC_PGDN,   KC_1,      KC_2,   KC_3,      KC_TRNS,
                                  KC_TRNS,      KC_NO,             KC_BSPC,   KC_0
  ),
  [_FUN] = LAYOUT(
      KC_NO,   KC_F7,    KC_F8,     KC_F9,     KC_F10,             DF(_QWER), DF(_CMAK),  KC_NO,   KC_NO,    KC_NO,
      KC_NO,   KC_F4,    KC_F5,     KC_F6,     KC_F11,             _CTLSPC,   _LCTL,      _GUI,    _ALT,     _MEH,
      KC_NO,   KC_F1,    KC_F2,     KC_F3,     KC_F12,             KC_NO,     _SCTL,      _SGUI,   KC_NO,   KC_TRNS,
                                    KC_NO,     KC_CAPS,            KC_NO,     KC_TRNS
  ),
};

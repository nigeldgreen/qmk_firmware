#include QMK_KEYBOARD_H

#define COMBO_COUNT 20
uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM cmb_leader1[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_leader2[] = {KC_T, KC_E, COMBO_END};
const uint16_t PROGMEM cmb_esc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_bsp[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_i3_launch[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_i3_tab[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_z[] = {KC_LSFT, KC_X, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(cmb_leader1, QK_LEAD),
    COMBO(cmb_leader2, QK_LEAD),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_ent, KC_ENT),
    COMBO(cmb_esc, KC_ESC),
    COMBO(cmb_bsp, KC_BSPC),
    COMBO(cmb_del, KC_DEL),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_lcbr, KC_LCBR),
    COMBO(cmb_rcbr, KC_RCBR),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
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
        /* i3 switch windows */
    } else if (leader_sequence_one_key(KC_M)) {
        tap_code16(G(KC_1));
    } else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16(G(KC_2));
    } else if (leader_sequence_one_key(KC_DOT)) {
        tap_code16(G(KC_3));
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(G(KC_4));
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(G(KC_5));
    } else if (leader_sequence_one_key(KC_L)) {
        tap_code16(G(KC_6));
    } else if (leader_sequence_one_key(KC_U)) {
        tap_code16(G(KC_7));
    } else if (leader_sequence_one_key(KC_I)) {
        tap_code16(G(KC_8));
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(G(KC_9));
    } else if (leader_sequence_one_key(KC_M)) {
        tap_code16(G(KC_0));
        /* i3 send to workspace */
    } else if (leader_sequence_two_keys(KC_M, KC_M)) {
        tap_code16(S(G(KC_1)));
    } else if (leader_sequence_two_keys(KC_COMM, KC_COMM)) {
        tap_code16(S(G(KC_2)));
    } else if (leader_sequence_two_keys(KC_DOT, KC_DOT)) {
        tap_code16(S(G(KC_3)));
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        tap_code16(S(G(KC_4)));
    } else if (leader_sequence_two_keys(KC_K, KC_K)) {
        tap_code16(S(G(KC_5)));
    } else if (leader_sequence_two_keys(KC_L, KC_L)) {
        tap_code16(S(G(KC_6)));
    } else if (leader_sequence_two_keys(KC_U, KC_U)) {
        tap_code16(S(G(KC_7)));
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        tap_code16(S(G(KC_8)));
        /* i3 quit */
    } else if (leader_sequence_one_key(KC_Q)) {
        tap_code16(S(G(KC_Q)));
        /* i3 set windows to tab */
    } else if (leader_sequence_one_key(KC_W)) {
        tap_code16(S(G(KC_W)));
        /* i3 reset windows */
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(G(KC_E));
        /* i3 remove window from scratch */
    } else if (leader_sequence_one_key(KC_SPC)) {
        tap_code16(S(G(KC_SPC)));
        /* i3 restart */
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(S(G(KC_R)));
        /* i3 send workspace to other monitor */
    } else if (leader_sequence_one_key(KC_H)) {
        tap_code16(S(G(KC_COMM)));
    }
}

// Tap Dance declarations
enum {
    TD_CBR,
    TD_PRN,
    TD_BRC,
};

// Tap Dance definitions
tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_CBR] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_PRN] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_BRC] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
};

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

/* RIGHT HAND LAYOUT */
/*     Y   U   I   O   P */
/*     J  LTH  K   L   ; */
/*     M   ,  RTH SFT  H */
/*     .   N */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
    KC_Q,      KC_W,      KC_E,     KC_R,        KC_T,             KC_Y,      KC_U,       KC_I,    KC_O,     KC_P,
    KC_A,      KC_S,      KC_D,     KC_F,        KC_G,             KC_J,      _FUNENT,    KC_K,    KC_L,     KC_SCLN,
    KC_LSFT,   KC_X,      KC_C,     KC_V,        KC_B,             KC_M,      KC_COMM,    _SYMSPC, KC_RSFT,  KC_H,
                                 _NUMESC,     _SYMTAB,            KC_DOT,    KC_N
  ),
  [_CMAK] = LAYOUT(
    KC_Q,      KC_W,      KC_F,      KC_P,       KC_B,             KC_J,      KC_L,       KC_U,    KC_Y,     KC_SCLN,
    KC_A,      KC_R,      KC_S,      KC_T,       KC_G,             KC_N,      MO(_SYM2),  KC_E,    KC_I,     KC_O,
    KC_LSFT,   KC_X,      KC_C,      KC_D,       KC_V,             KC_H,      KC_COMM,    KC_SPC,  KC_RSFT,  KC_M,
                                 MO(_NUM),  MO(_SYM1),             KC_DOT,    KC_K
  ),
  [_SYM1] = LAYOUT(
    KC_NO,    KC_NO,     KC_NO,     KC_NO,      KC_NO,             KC_QUOT,   _UNDSCR,    KC_MINS, KC_EQL,   KC_PAST,
    _MEH,      _ALT,      _GUI,     _LCTL,    _CTLSPC,             KC_DOWN,   MO(_FUN),   KC_UP, KC_RIGHT,   KC_CIRC,
    KC_TRNS,  KC_NO,     _SGUI,     _SCTL,      KC_NO,             _TILDE,    KC_SLSH,    KC_BSPC, KC_TRNS,  KC_LEFT,
                                    KC_NO,    KC_TRNS,             KC_NUBS,   S(KC_2)
  ),
  [_SYM2] = LAYOUT(
     KC_GRV,  KC_DLR,  KC_PLUS,   KC_NUHS, TD(TD_CBR),             KC_NO,     KC_NO,      KC_NO,   KC_NO,    KC_NO,
    S(KC_3), KC_PERC,  KC_EXLM,   KC_QUES, TD(TD_PRN),             _LCTL,     KC_TRNS,    _GUI,    _ALT,     _MEH,
    KC_TRNS, KC_AMPR,    _PIPE,   _ATSIGN, TD(TD_BRC),             _SCTL,     _SGUI,      KC_NO,   KC_TRNS,  _CTLSPC,
                                    KC_NO,      KC_NO,             KC_NO,     KC_NO
  ),
  [_NUM] = LAYOUT(
      KC_NO,   KC_NO,    KC_NO,     KC_NO,      KC_NO,             KC_PGUP,   KC_7,       KC_8,   KC_9,      KC_HOME,
     _MEH,      _ALT,     _GUI,     _LCTL,    _CTLSPC,             KC_4,      KC_BSPC,    KC_5,   KC_6,      KC_END,
     KC_TRNS,  KC_NO,    _SGUI,     _SCTL,      KC_NO,             KC_1,      KC_2,       KC_0,   KC_TRNS,   KC_NO,
                                  KC_TRNS,      KC_NO,             KC_3,      KC_PGDN
  ),
  [_FUN] = LAYOUT(
      KC_NO,   KC_F7,    KC_F8,     KC_F9,     KC_F10,             DF(_QWER), DF(_CMAK),  KC_NO,   KC_NO,    KC_NO,
      KC_NO,   KC_F4,    KC_F5,     KC_F6,     KC_F11,             _LCTL,     KC_TRNS,    _GUI,    _ALT,     _MEH,
      KC_NO,   KC_F1,    KC_F2,     KC_F3,     KC_F12,             _SCTL,     _SGUI,      KC_NO,   KC_TRNS,  _CTLSPC,
                                  CW_TOGG,      KC_NO,             KC_NO,     KC_NO
  ),
};

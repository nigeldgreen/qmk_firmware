#include QMK_KEYBOARD_H

/* Define names for our layers */
enum ferris_layers {
  _QWER,
  _CMAK,
  _SYMR,
  _SYML,
  _NUM,
  _FUN,
  _I3,
};

/* Define aliases for longer keysends to keep our map tidy */
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

enum combos {
  SD_ESC,
  DF_TAB,
  SDF_ENT,
  WER_BSP,
  ER_DEL,
  RT_CUT,
  FG_COPY,
  VB_PASTE,
  HJ_UNDO,
  NM_Z,
  YU_CTL_SFT_R,
  UI_LCBR,
  IO_RCBR,
  UIO_CBRs,
  JK_LPRN,
  KL_RPRN,
  JKL_PRNs,
  M_COMM_LBRC,
  COMM_DOT_RBRC,
  M_COMM_DOT_BRCs,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;
/* Set up and define all of our combos */
const uint16_t PROGMEM cmb_esc[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ent[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_bsp[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_del[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_z[] = {KC_N, KC_M, COMBO_END};
const uint16_t PROGMEM cmb_ctl_sft_r[] = {KC_Y, KC_U, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_acbr[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_aprn[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_abrc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    [SD_ESC] = COMBO(cmb_esc, KC_ESC),
    [DF_TAB] = COMBO(cmb_tab, KC_TAB),
    [SDF_ENT] = COMBO(cmb_ent, KC_ENT),
    [WER_BSP] = COMBO(cmb_bsp, KC_BSPC),
    [ER_DEL] = COMBO(cmb_del, KC_DEL),
    [FG_COPY] = COMBO(cmb_copy, C(KC_C)),
    [VB_PASTE] = COMBO(cmb_paste, C(KC_V)),
    [RT_CUT] = COMBO(cmb_cut, C(KC_X)),
    [HJ_UNDO] = COMBO(cmb_undo, C(KC_Z)),
    [NM_Z] = COMBO(cmb_z, KC_Z),
    [YU_CTL_SFT_R] = COMBO(cmb_ctl_sft_r, S(C(KC_R))),
    [UI_LCBR] = COMBO(cmb_lcbr, KC_LCBR),
    [IO_RCBR] = COMBO(cmb_rcbr, KC_RCBR),
    [JK_LPRN] = COMBO(cmb_lprn, KC_LPRN),
    [KL_RPRN] = COMBO(cmb_rprn, KC_RPRN),
    [M_COMM_LBRC] = COMBO(cmb_lbrc, KC_LBRC),
    [COMM_DOT_RBRC] = COMBO(cmb_rbrc, KC_RBRC),
    [UIO_CBRs] = COMBO_ACTION(cmb_acbr),
    [JKL_PRNs] = COMBO_ACTION(cmb_aprn),
    [M_COMM_DOT_BRCs] = COMBO_ACTION(cmb_abrc),
};


void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case UIO_CBRs:
      if (pressed) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
      }
      break;
    case JKL_PRNs:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
      }
      break;
    case M_COMM_DOT_BRCs:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
      }
      break;
  }
}

/* Finally, define the keymap for all of our layers */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWER] = LAYOUT(
    KC_Q,      KC_W,      KC_E,     KC_R,        KC_T,             KC_Y,      KC_U,       KC_I,    KC_O,     KC_P,
    KC_A,      KC_S,      KC_D,     KC_F,        KC_G,             KC_H,      KC_J,       KC_K,    KC_L,     KC_SCLN,
    KC_LSFT,   KC_X,      KC_C,     KC_V,        KC_B,             KC_N,      KC_M,       KC_COMM, KC_DOT,   KC_RSFT,
                               MO(_SYMR),    MO(_NUM),             MO(_SYML), KC_SPC
  ),
  [_CMAK] = LAYOUT(
    KC_Q,      KC_W,      KC_F,     KC_P,        KC_B,             KC_J,      KC_L,      KC_U,     KC_Y,     KC_SCLN,
    KC_A,      KC_R,      KC_S,     KC_T,        KC_G,             KC_M,      KC_N,      KC_E,     KC_I,     KC_O,
    KC_LSFT,   KC_X,      KC_C,     KC_D,        KC_V,             KC_K,      KC_H,      KC_COMM,  KC_DOT,   KC_RSFT,
                               MO(_SYMR),    MO(_NUM),             MO(_SYML), KC_SPC
  ),
  [_SYMR] = LAYOUT(
    KC_NO,    KC_NO,     KC_NO,     KC_NO,    QK_BOOT,             KC_DLR,   _UNDSCR,    KC_MINS,  KC_EQL,   KC_QUOT,
    _MEH,      _ALT,      _GUI,     _LCTL,    _CTLSPC,             KC_LEFT,   KC_DOWN,   KC_UP,    KC_RIGHT, S(KC_2),
    KC_TRNS,  _SALT,     _SGUI,     _SCTL,      KC_NO,             KC_PERC,   _TILDE,    KC_SLSH,  KC_QUES,  _PIPE,
                                    KC_TRNS,    KC_NO,             MO(_FUN), KC_BSPC
  ),
  [_SYML] = LAYOUT(
     KC_GRV, KC_PLUS,  KC_NUHS,   KC_LCBR,    KC_RCBR,             DF(_QWER), DF(_CMAK), KC_NO,    KC_NO,    KC_NO,
    KC_NUBS, KC_PAST,  KC_EXLM,   KC_LPRN,    KC_RPRN,             _CTLSPC,   _LCTL,     _GUI,     _ALT,     _MEH,
    S(KC_3), KC_AMPR,  _ATSIGN,   KC_LBRC,    KC_RBRC,             KC_NO,     _SCTL,     _SGUI,    _SALT,    KC_TRNS,
                                  MO(_I3),    _I3SHFT,             KC_TRNS,   KC_NO
  ),
  [_NUM] = LAYOUT(
     KC_NO,    KC_NO,    KC_NO,     KC_NO,    QK_BOOT,             KC_PGUP,   KC_7,      KC_8,     KC_9,     KC_HOME,
     _MEH,      _ALT,     _GUI,     _LCTL,    _CTLSPC,             KC_NO,     KC_4,      KC_5,     KC_6,     KC_END,
     KC_TRNS,  _SALT,    _SGUI,     _SCTL,      KC_NO,             KC_PGDN,   KC_1,      KC_2,     KC_3,     KC_TRNS,
                                    KC_NO,    KC_TRNS,             KC_BSPC,   KC_0
  ),
  [_FUN] = LAYOUT(
      KC_NO,   KC_F7,    KC_F8,     KC_F9,     KC_F10,             DF(_QWER), DF(_CMAK), KC_NO,    KC_NO,    KC_NO,
      KC_NO,   KC_F4,    KC_F5,     KC_F6,     KC_F11,             _CTLSPC,   _LCTL,     _GUI,     _ALT,     _MEH,
      KC_TRNS, KC_F1,    KC_F2,     KC_F3,     KC_F12,             KC_NO,     _SCTL,     _SGUI,    _SALT,    KC_TRNS,
                                    KC_NO,    KC_CAPS,             KC_TRNS,   KC_NO
  ),
  [_I3] = LAYOUT(
   G(KC_Q),  G(KC_W),   G(KC_E),    G(KC_R),  QK_BOOT,             G(KC_MINS), G(KC_7),  G(KC_8),  G(KC_9),  KC_NO,
     KC_NO,    KC_NO,     KC_NO,    KC_LSFT,    KC_NO,             G(KC_LT),   G(KC_4),  G(KC_5),  G(KC_6),  KC_NO,
   KC_TRNS,    KC_NO,     KC_NO,      KC_NO,    KC_NO,             KC_NO,      G(KC_1),  G(KC_2),  G(KC_3),  KC_TRNS,
                                    KC_TRNS,    KC_NO,             KC_NO,      G(KC_0)
  ),
};

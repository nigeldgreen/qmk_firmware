#include QMK_KEYBOARD_H
#include <stdio.h>

const uint16_t PROGMEM cmb_leader[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_escape[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_i3_tab[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM cmb_i3_drun[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_H, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_lcbr[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_rcbr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_cbr[] = {KC_U, KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_prn[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_brc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cmb_cbr),
    COMBO_ACTION(cmb_prn),
    COMBO_ACTION(cmb_brc),
    COMBO(cmb_leader, QK_LEAD),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_escape, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_i3_tab, G(KC_TAB)),
    COMBO(cmb_i3_drun, G(KC_SPC)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_lcbr, KC_LCBR),
    COMBO(cmb_rcbr, KC_RCBR),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
};

void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        tap_code16(KC_LCBR);
        tap_code16(KC_RCBR);
      }
      break;
    case 1:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
      }
      break;
    case 2:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
      }
      break;
  }
}

enum custom_keycodes {
    _LOREM = SAFE_RANGE,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case _LOREM:
        if (record->event.pressed) {
            SEND_STRING("dummy text ");
        }
        break;
    }
    return true;
};

#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _TMUX C(KC_F)
#define _QWERTY DF(0)
#define _COLEMAK DF(1)
#define _NUM MO(4)
#define _SYMTAB LT(3, KC_TAB)
#define _SYMSPC LT(2, KC_SPC)
#define _NUMESC LT(4, KC_ESC)
#define _FUNENT LT(5, KC_ENT)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _SFTZ SFT_T(KC_Z)

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _SYMSPC:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
        KC_Q,     KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
        KC_A,     KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
       _SFTZ,     KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,
                                 _SYMTAB, _NUMESC,        _FUNENT, _SYMSPC
  ),
  [1] = LAYOUT(
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,    KC_O,
        _SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_RSFT,
                                 _SYMTAB, _NUMESC,        _FUNENT, _SYMSPC
  ),
  [2] = LAYOUT(
       KC_GRV, KC_PLUS, KC_NUHS, KC_LCBR, KC_RCBR,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      KC_NUBS, KC_PAST, KC_EXLM, KC_LPRN, KC_RPRN,        _TMUX,   _LCTL,   _GUI,    _ALT,    _MEH,
      S(KC_3), KC_AMPR, _ATSIGN, KC_LBRC, KC_RBRC,        KC_NO,   _SCTL,   _SGUI,   _SALT,   KC_TRNS,
                                 KC_HOME,  KC_END,        KC_NO, KC_TRNS
  ),
  [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_DLR,   _UNDSCR,  KC_MINS, KC_EQL,  S(KC_2),
         _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,KC_QUOT,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_PERC,  _TILDE,   KC_SLSH, KC_QUES, _PIPE,
                                   KC_TRNS, KC_NO,        KC_DEL,   KC_BSPC
  ),
  [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_LCBR,  KC_7,     KC_8,    KC_9,    KC_RCBR,
         _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,        KC_LPRN,  KC_4,     KC_5,    KC_6,    KC_RPRN,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_LBRC,  KC_1,     KC_2,    KC_3,    KC_RBRC,
                                 KC_NO,   KC_TRNS,        KC_NO,    KC_0
  ),
  [5] = LAYOUT(
        KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
      QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,        _TMUX,   _LCTL,   _GUI,    _ALT,    _MEH,
        KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,   _SGUI,   _SALT,   KC_TRNS,
                                     KC_NO, KC_NO,        KC_TRNS, KC_NO
  ),
};
void leader_end_user(void) {
    if (leader_sequence_one_key(KC_Q)) {
        tap_code16(LGUI(S(KC_Q)));
    } else if (leader_sequence_one_key(KC_W)) {
        tap_code16(LGUI(S(KC_W)));
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(LGUI(KC_E));
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(LGUI(S(KC_R)));
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(LGUI(S(KC_S)));
    } else if (leader_sequence_one_key(KC_SPC)) {
        tap_code16(LGUI(KC_SPC));
    } else if (leader_sequence_one_key(KC_TAB)) {
        tap_code16(LGUI(KC_TAB));
    } else if (leader_sequence_one_key(KC_H)) {
        tap_code16(LGUI(S(KC_COMM)));
    } else if (leader_sequence_one_key(KC_M)) {
        tap_code16(LGUI(KC_1));
    } else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16(LGUI(KC_2));
    } else if (leader_sequence_one_key(KC_DOT)) {
        tap_code16(LGUI(KC_3));
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(LGUI(KC_4));
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(LGUI(KC_5));
    } else if (leader_sequence_one_key(KC_L)) {
        tap_code16(LGUI(KC_6));
    } else if (leader_sequence_one_key(KC_U)) {
        tap_code16(LGUI(KC_7));
    } else if (leader_sequence_one_key(KC_I)) {
        tap_code16(LGUI(KC_8));
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(LGUI(KC_9));
    } else if (leader_sequence_one_key(KC_SPC)) {
        tap_code16(LGUI(KC_0));
    } else if (leader_sequence_two_keys(KC_M, KC_M)) {
        tap_code16(LGUI(S(KC_1)));
    } else if (leader_sequence_two_keys(KC_COMM, KC_COMM)) {
        tap_code16(LGUI(S(KC_2)));
    } else if (leader_sequence_two_keys(KC_DOT, KC_DOT)) {
        tap_code16(LGUI(S(KC_3)));
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        tap_code16(LGUI(S(KC_4)));
    } else if (leader_sequence_two_keys(KC_K, KC_K)) {
        tap_code16(LGUI(S(KC_5)));
    } else if (leader_sequence_two_keys(KC_L, KC_L)) {
        tap_code16(LGUI(S(KC_6)));
    } else if (leader_sequence_two_keys(KC_U, KC_U)) {
        tap_code16(LGUI(S(KC_7)));
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        tap_code16(LGUI(S(KC_8)));
    }
}

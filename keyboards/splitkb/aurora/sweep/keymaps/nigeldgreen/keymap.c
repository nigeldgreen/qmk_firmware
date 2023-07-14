#include QMK_KEYBOARD_H

enum custom_keycodes {
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    FFNXT,
    FFPRV,
    CMASPC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    case TMXNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "n");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "p");
        }
        break;
    case FFPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL(SS_TAP(X_PGUP)));
        }
        break;
    case FFNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL(SS_TAP(X_PGDN)));
        }
        break;
    case CMASPC:
        if (record->event.pressed) {
           SEND_STRING(", ");
        }
        break;
    }
    return true;
};

#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _QWERTY DF(0)
#define _COLEMAK DF(1)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _SFTZ SFT_T(KC_Z)
#define _I3QUIT S(G(KC_Q))
#define _I3TABS S(G(KC_W))
#define _I3RST S(G(KC_R))
#define _I3STCK S(G(KC_S))
#define _I3MV S(G(KC_COMM))
#define _I3ASCR S(G(KC_MINS))
#define _I3SCR G(KC_MINS)
#define _I3RSCR S(G(KC_SPC))
#define _I3SPC G(KC_SPC)
#define _I3TAB G(KC_TAB)

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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
        _SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,   KC_RSFT,
                                   MO(2),   MO(3),        MO(1),   KC_SPC
  ),
  [1] = LAYOUT(
       KC_GRV, KC_PERC, KC_NUHS, KC_AMPR, KC_PLUS,        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
      KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),        KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,
      KC_TRNS,   _PIPE, _ATSIGN,  KC_DLR,  _LOREM,        KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_TRNS,
                                  TMXPRV,  TMXNXT,        KC_TRNS, KC_NO
  ),
  [2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_PGUP, _UNDSCR, KC_MINS, KC_EQL,   KC_HOME,
         _MEH,    _ALT,    _GUI,   _LCTL,   KC_NO,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_PGDN, _TILDE,  KC_SLSH, KC_QUES,  KC_NO,
                                   KC_TRNS, KC_NO,        MO(4),    KC_BSPC
  ),
  [3] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,  KC_7,     KC_8,    KC_9,     KC_MINS,
         _MEH,    _ALT,    _GUI,   _LCTL,   KC_NO,        KC_Z,   KC_4,     KC_5,    KC_6,     CMASPC,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_NO,  KC_1,     KC_2,    KC_3,     KC_PLUS,
                                 KC_NO,   KC_TRNS,        KC_NO,  KC_0
  ),
  [4] = LAYOUT(
      QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
      KC_NO  ,   KC_F4,   KC_F5,   KC_F6,  KC_F11,        KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_TRNS,
                                   FFPRV,   FFNXT,        KC_TRNS, KC_NO
  ),
};

const uint16_t PROGMEM cmb_leader[] = {KC_F, KC_J, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_escape[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_X, KC_C, KC_V, COMBO_END};
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
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_escape, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_space, KC_SPC),
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

void leader_end_user(void) {
    if (leader_sequence_one_key(KC_M)) {
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
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(S(G(KC_R)));
    } else if (leader_sequence_one_key(KC_W)) {
        tap_code16(S(G(KC_W)));
    } else if (leader_sequence_one_key(KC_Q)) {
        tap_code16(S(G(KC_Q)));
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(S(G(KC_S)));
    } else if (leader_sequence_one_key(KC_H)) {
        tap_code16(S(G(KC_COMM)));
    } else if (leader_sequence_one_key(KC_SPC)) {
        tap_code16(G(KC_SPC));
    } else if (leader_sequence_one_key(KC_Y)) {
        tap_code16(G(KC_0));
    } else if (leader_sequence_one_key(KC_P)) {
        tap_code16(S(G(KC_MINS)));
    } else if (leader_sequence_one_key(KC_SCLN)) {
        tap_code16(G(KC_MINS));
    } else if (leader_sequence_one_key(KC_RSFT)) {
        tap_code16(S(G(KC_SPC)));
    } else if (leader_sequence_one_key(KC_X)) {
        tap_code16(G(KC_X));
    } else if (leader_sequence_two_keys(KC_K, KC_C)) {
        tap_code16(S(C(KC_F2)));
    } else if (leader_sequence_two_keys(KC_K, KC_R)) {
        tap_code16(S(C(KC_F5)));
    }
}


#include QMK_KEYBOARD_H
#include <stdio.h>
#define SYMTAB LT(3, KC_TAB)
#define NUMESC LT(4, KC_ESC)
#define SYMENT LT(2, KC_ENT)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define ATSIGN S(KC_QUOT)
#define UNDSCR S(KC_MINS)
#define TILDE S(KC_NUHS)
#define PIPE S(KC_NUBS)
#define SFTZ SFT_T(KC_Z)

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_shift_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_squote[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_dquote[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_less[] = {KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM cmb_grtr[] = {KC_I, KC_O, COMBO_END};
const uint16_t PROGMEM cmb_lprn[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_rprn[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_prn[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lbrc[] = {KC_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM cmb_rbrc[] = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM cmb_brc[] = {KC_M, KC_COMM, KC_DOT, COMBO_END};
combo_t key_combos[] = {
    COMBO_ACTION(cmb_prn),
    COMBO_ACTION(cmb_brc),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_shift_enter, S(KC_ENT)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_space, KC_SPC),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_squote, KC_QUOT),
    COMBO(cmb_dquote, S(KC_2)),
    COMBO(cmb_less, S(KC_COMM)),
    COMBO(cmb_grtr, S(KC_DOT)),
    COMBO(cmb_lprn, KC_LPRN),
    COMBO(cmb_rprn, KC_RPRN),
    COMBO(cmb_lbrc, KC_LBRC),
    COMBO(cmb_rbrc, KC_RBRC),
};
void process_combo_event(uint16_t combo_index, bool pressed) {
  switch(combo_index) {
    case 0:
      if (pressed) {
        tap_code16(KC_LPRN);
        tap_code16(KC_RPRN);
      }
      break;
    case 1:
      if (pressed) {
        tap_code16(KC_LBRC);
        tap_code16(KC_RBRC);
      }
      break;
  }
}

enum custom_keycodes {
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    COMSPC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMXNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "P");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("f") "p");
        }
        break;
    case COMSPC:
        if (record->event.pressed) {
            SEND_STRING(", ");
         }
         break;
    }
    return true;
};

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case SYMTAB:
            return true;
        case NUMESC:
            return true;
        case SYMENT:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
         //                 |  Q  |  W  |  E  |  R  |  T  |        |  Y  |  U  |  I  |  O  |  P  |
         //                 |  A  |  S  |  D  |  F  |  G  |        |  H  |  J  |  K  |  L  |  ;  |
         //                 |Z/SFT|  X  |  C  |  V  |  B  |        |  N  |  M  |  ,  |  .  | SFT |
         KC_NO,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,     KC_U,    KC_I,    KC_O,     KC_P,     KC_NO,
         KC_NO,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,     KC_J,    KC_K,    KC_L,     KC_SCLN,  KC_NO,
         KC_NO,   SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,     KC_M,    KC_COMM, KC_DOT,   KC_RSFT,  KC_NO,
                                  QK_LEAD, SYMTAB,  NUMESC,        SYMENT,   KC_SPC,  CW_TOGG
  ),
  [1] = LAYOUT(
         //                 |  Q  |  W  |  F  |  P  |  B  |        |  J  |  L  |  U  |  O  |  Y  |
         //                 |  A  |  S  |  D  |  F  |  G  |        |  M  |  N  |  E  |  I  |  ;  |
         //                 |Z/SFT|  X  |  C  |  V  |  B  |        |  K  |  H  |  ,  |  .  | SFT |
         KC_NO,   KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,     KC_L,    KC_U,    KC_O,     KC_Y,     KC_NO,
         KC_NO,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,     KC_N,    KC_E,    KC_I,     KC_SCLN,  KC_NO,
         KC_NO,   SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,     KC_H,    KC_COMM, KC_DOT,   KC_RSFT,  KC_NO,
                                 QK_LEAD,  SYMTAB,  NUMESC,        SYMENT,   KC_SPC,  CW_TOGG
  ),
  [2] = LAYOUT(
         //                 |  `  |  +  |  &  |  #  |  ^  |        | --- | --- | --- | --- | --- |
         //                 |  \  |  *  |  !  |  %  |  $  |        | --- | CTL | GUI | ALT | MEH |
         //                 |  £  |  |  |  @  | <-T | T-> |        | --- | SCTL| SGUI| SALT| --- |
      KC_NO,    KC_GRV, KC_PLUS, KC_AMPR, KC_NUHS, S(KC_6),        KC_NO,    KC_NO,    KC_NO,  KC_NO,    KC_NO,     KC_NO,
      KC_NO,   KC_NUBS, KC_PAST, KC_EXLM, KC_PERC,  KC_DLR,        KC_NO,    _LCTL,   _GUI,    _ALT,     _MEH,     KC_NO,
      KC_NO,   KC_TRNS,    PIPE,  ATSIGN,  TMXPRV,  TMXNXT,        KC_NO,    _SCTL,   _SGUI,   _SALT,    KC_TRNS,  KC_NO,
                                   KC_NO,   KC_NO,   KC_NO,        KC_TRNS,  KC_NO,   KC_NO
  ),
  [3] = LAYOUT(
         //                 | --- | SPC | BSPC| DEL | ENT |        | PGUP|  _  |  -  |  =  | HOME|
         //                 | MEH | ALT | GUI | CTL | --- |        | LEFT| UP  |RIGHT| DOWN| END |
         //                 | --- | SALT| SGUI| SCTL| --- |        | PGDN|  ~  |  /  |  ?  | --- |
      KC_NO,     KC_NO,  KC_SPC, KC_BSPC,  KC_DEL,  KC_ENT,         KC_PGUP, UNDSCR,  KC_MINS, KC_EQL,   KC_HOME,   KC_NO,
      KC_NO,      _MEH,    _ALT,    _GUI,   _LCTL,   KC_NO,         KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,    KC_NO,
      KC_NO,   KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,         KC_PGDN, TILDE,   KC_SLSH, KC_QUES,  KC_TRNS,   KC_NO,
                                   KC_NO, KC_TRNS,   KC_NO,         MO(5),   KC_BSPC, KC_NO
  ),
  [4] = LAYOUT(
         //                 | --- | --- | --- | --- | --- |        | --- |  7  |  8  |  9  |  -  |
         //                 | MEH | ALT | GUI | CTL | --- |        | --- |  4  |  5  |  6  | ', '|
         //                 | --- | SALT| SGUI| SCTL| --- |        | --- |  1  |  2  |  3  |  +  |
      KC_NO,   QK_BOOT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,    KC_7,    KC_8,    KC_9,     KC_MINS,   KC_NO,
      KC_NO,      _MEH,    _ALT,    _GUI,   _LCTL,   KC_NO,        KC_NO,    KC_4,    KC_5,    KC_6,     COMSPC,    KC_NO,
      KC_NO,   KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,        KC_NO,    KC_1,    KC_2,    KC_3,     KC_TRNS,   KC_NO,
                                   KC_NO,   KC_NO, KC_TRNS,        KC_BSPC,  KC_0,    KC_NO
  ),
  [5] = LAYOUT(
         //                 | BOOT|  F7 |  F8 |  F9 | F10 |        | --- | --- | --- | --- | --- |
         //                 |QWERT|  F4 |  F5 |  F6 | F11 |        | --- | CTL | GUI | ALT | MEH |
         //                 |CLMAK|  F1 |  F2 |  F3 | F12 |        | --- | SCTL| SGUI| SALT| --- |
      KC_NO,   QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,     KC_NO,
      KC_NO,     KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_F11,        KC_NO,   _LCTL,    _GUI,    _ALT,     _MEH,      KC_NO,
      KC_NO,   KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,    _SGUI,   _SALT,    KC_TRNS,   KC_NO,
                                   KC_NO,   KC_NO, KC_TRNS,        KC_TRNS, KC_NO,    KC_NO
  ),
};

void leader_start_user(void) {
    // Do something when the leader key is pressed
}

void leader_end_user(void) {
    // Cut, copy, paste
    if (leader_sequence_one_key(KC_X)) {
        tap_code16(C(KC_X));
    } else if (leader_sequence_two_keys(KC_X, KC_X)) {
        tap_code16(S(C(KC_X)));
    } else if (leader_sequence_one_key(KC_C)) {
        tap_code16(C(KC_C));
    } else if (leader_sequence_two_keys(KC_C, KC_C)) {
        tap_code16(S(C(KC_C)));
    } else if (leader_sequence_one_key(KC_V)) {
        tap_code16(C(KC_V));
    } else if (leader_sequence_two_keys(KC_V, KC_V)) {
        tap_code16(S(C(KC_V)));
    // Undo
    } else if (leader_sequence_one_key(KC_Z)) {
        tap_code16(KC_X);
    // move to / send to I3 workspace
    } else if (leader_sequence_one_key(KC_M)) {
        tap_code16(G(KC_1));
    } else if (leader_sequence_two_keys(KC_M, KC_M)) {
        tap_code16(S(G(KC_1)));
    } else if (leader_sequence_one_key(KC_COMM)) {
        tap_code16(G(KC_2));
    } else if (leader_sequence_two_keys(KC_COMM, KC_COMM)) {
        tap_code16(S(G(KC_2)));
    } else if (leader_sequence_one_key(KC_DOT)) {
        tap_code16(G(KC_3));
    } else if (leader_sequence_two_keys(KC_DOT, KC_DOT)) {
        tap_code16(S(G(KC_3)));
    } else if (leader_sequence_one_key(KC_J)) {
        tap_code16(G(KC_4));
    } else if (leader_sequence_two_keys(KC_J, KC_J)) {
        tap_code16(S(G(KC_4)));
    } else if (leader_sequence_one_key(KC_K)) {
        tap_code16(G(KC_5));
    } else if (leader_sequence_two_keys(KC_K, KC_K)) {
        tap_code16(S(G(KC_5)));
    } else if (leader_sequence_one_key(KC_L)) {
        tap_code16(G(KC_6));
    } else if (leader_sequence_two_keys(KC_L, KC_L)) {
        tap_code16(S(G(KC_6)));
    } else if (leader_sequence_one_key(KC_U)) {
        tap_code16(G(KC_7));
    } else if (leader_sequence_two_keys(KC_U, KC_U)) {
        tap_code16(S(G(KC_7)));
    } else if (leader_sequence_one_key(KC_I)) {
        tap_code16(G(KC_8));
    } else if (leader_sequence_two_keys(KC_I, KC_I)) {
        tap_code16(S(G(KC_8)));
    // move workspace to other monitor
    } else if (leader_sequence_one_key(KC_G)) {
        tap_code16(G(KC_G));
    } else if (leader_sequence_one_key(KC_H)) {
        tap_code16(G(KC_H));
    // lock and suspend
    } else if (leader_sequence_one_key(KC_O)) {
        tap_code16(G(KC_9));
    } else if (leader_sequence_one_key(KC_Y)) {
        tap_code16(G(KC_0));
    // launch and switch
    } else if (leader_sequence_one_key(KC_SPC)) {
        tap_code16(G(KC_SPC));
    } else if (leader_sequence_one_key(KC_TAB)) {
        tap_code16(G(KC_TAB));
    // window layout stuff
    } else if (leader_sequence_one_key(KC_W)) {
        tap_code16(G(KC_W));  // tabs
    } else if (leader_sequence_one_key(KC_S)) {
        tap_code16(G(KC_S));  // stacked
    } else if (leader_sequence_one_key(KC_E)) {
        tap_code16(G(KC_E));  // normal
    // quit and restart
    } else if (leader_sequence_one_key(KC_Q)) {
        tap_code16(S(G(KC_Q)));
    } else if (leader_sequence_one_key(KC_R)) {
        tap_code16(S(G(KC_R)));
    // manage the scratchpad
    } else if (leader_sequence_one_key(KC_SCLN)) {
        tap_code16(G(KC_MINS));     // show scratchpad
    } else if (leader_sequence_two_keys(KC_SCLN, KC_SCLN)) {
        tap_code16(S(G(KC_MINS)));  // move app to scratchpad
    } else if (leader_sequence_two_keys(KC_SPC, KC_SPC)) {
        tap_code16(S(G(KC_SPC)));  // take app out of scratchpad
    // app launchers
    } else if (leader_sequence_one_key(KC_ENT)) {
        tap_code16(G(KC_ENT));  // terminal
    } else if (leader_sequence_two_keys(KC_H, KC_H)) {
        tap_code16(KC_N);
    // switch base layer
    } else if (leader_sequence_one_key(KC_RSFT)) {
        layer_move(0);  // qwerty
    } else if (leader_sequence_two_keys(KC_RSFT, KC_RSFT)) {
        layer_move(1);  // colemak
    }
}



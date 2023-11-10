#include QMK_KEYBOARD_H
#include <stdio.h>

/* Define our layer switching and one-shot modifier keys */
#define SYMTAB LT(3, KC_TAB)
#define NUMESC LT(4, KC_ESC)
#define FUNENT LT(5, KC_ENT)
#define SYMSPC LT(2, KC_SPC)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _MEH OSM(MOD_LSFT | MOD_LCTL | MOD_LALT)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
/* Define some character keys to keep letter count low */
#define ATSIGN S(KC_QUOT)
#define UNDSCR S(KC_MINS)
#define TILDE S(KC_NUHS)
/* Define some shortcuts for I3 */
#define I3RST S(G(KC_P))
#define I3QUT S(G(KC_Q))
#define I3TAB G(KC_TAB)
#define I3SPC G(KC_SPC)
#define I3ASCR S(G(KC_MINS))
#define I3SCR G(KC_MINS)
#define I3RSCR S(G(KC_SPC))

const uint16_t PROGMEM cmb_delete[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_shift_enter[] = {KC_A, KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_X, KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_P, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_T, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_D, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_G, KC_V, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_shift_enter, S(KC_ENT)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_space, KC_SPC),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_undo, C(KC_Z)),
};

enum custom_keycodes {
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    COMSPC,
};
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case TMXNXT:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("t") "P");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL("t") "p");
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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
    KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                    KC_J,    KC_L,    KC_U,    KC_O,     KC_Y,    KC_NO,
    KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                    KC_M,    KC_N,    KC_E,    KC_I,     KC_SCLN, KC_NO,
    KC_NO, SC_LSPO,    KC_X,    KC_C,    KC_D,    KC_V,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_K,    KC_H,    KC_COMM, KC_DOT,   SC_RSPC, KC_NO,
                               KC_NO,   MO(6),  SYMTAB,  NUMESC, KC_NO,    KC_NO, FUNENT,  SYMSPC,  MO(6),   KC_NO
  ),
  [1] = LAYOUT(
    KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                    KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,    KC_NO,
    KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                    KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN, KC_NO,
    KC_NO, SC_LSPO,    KC_X,    KC_C,    KC_V,    KC_B,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_N,    KC_M,    KC_COMM, KC_DOT,   SC_RSPC, KC_NO,
                               KC_NO,   MO(6),  SYMTAB,  NUMESC, KC_NO,    KC_NO, FUNENT,  SYMSPC,  MO(6),   KC_NO
  ),
  [2] = LAYOUT(
    KC_NO,  KC_GRV, KC_PERC, KC_AMPR, KC_NUHS, KC_PLUS,                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_NO, KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),                                    KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,    KC_NO,
    KC_NO,    KC_Z,  KC_DLR,  ATSIGN, KC_LBRC, KC_RBRC,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_NO,   KC_NO,
                               KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_TRNS, KC_NO,   KC_NO
  ),
  [3] = LAYOUT(
    KC_NO,   DF(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                    KC_HOME, UNDSCR,  KC_MINS, KC_EQL,   CW_TOGG, KC_NO,
    KC_NO,   DF(1),    _ALT,    _GUI,   _LCTL,  TMXPRV,                                    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_NO,   KC_NO,
    KC_NO,   KC_NO,   _SALT,   _SGUI,   _SCTL,  TMXNXT,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_END,  TILDE,   KC_SLSH, KC_QUES,  KC_NO,   KC_NO,
                               KC_NO,   KC_NO, KC_TRNS,   KC_NO, KC_NO,    KC_NO, KC_DEL,  KC_BSPC, KC_NO,   KC_NO
  ),
  [4] = LAYOUT(
    KC_NO,   KC_F5,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                    KC_PGUP, KC_7,    KC_8,    KC_9,     KC_MINS, KC_NO,
    KC_NO,    _MEH,    _ALT,    _GUI,   _LCTL,  KC_F12,                                    KC_NO,   KC_4,    KC_5,    KC_6,     COMSPC,  KC_NO,
    KC_NO,   KC_NO,   _SALT,   _SGUI,   _SCTL,   KC_F2,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_PGDN, KC_1,    KC_2,    KC_3,     KC_PLUS, KC_NO,
                               KC_NO,   KC_NO,   KC_NO, KC_TRNS, KC_NO,    KC_NO, KC_BSPC, KC_0,    KC_NO,   KC_NO
  ),
  [5] = LAYOUT(
    KC_NO, QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                    KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO,
    KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                    KC_NO,   _LCTL,   _GUI,     _ALT,    _MEH,    KC_NO,
    KC_NO,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   _SCTL,   _SGUI,    _SALT,   KC_NO,   KC_NO,
                               KC_NO,   KC_NO,   KC_NO, KC_TRNS, KC_NO,    KC_NO, KC_TRNS, KC_0,    KC_END,  KC_NO
  ),
  [6] = LAYOUT(
    KC_NO,   I3QUT, G(KC_W), G(KC_F),   I3RST,   KC_NO,                                    G(KC_0), G(KC_I), G(KC_O), G(KC_9),  I3ASCR,  KC_NO,
    KC_NO,  (KC_Q),   KC_NO,   KC_NO,   KC_NO, G(KC_G),                                    G(KC_M), G(KC_T), G(KC_N), G(KC_E),  I3SCR,   KC_NO,
    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   I3TAB,   KC_NO, KC_NO,    KC_NO, KC_NO,   KC_NO,   G(KC_A), G(KC_R), G(KC_S),  I3RSCR,  KC_NO,
                               KC_NO, KC_TRNS,   KC_NO, KC_TRNS, KC_NO,    KC_NO, KC_TRNS, I3SPC,   KC_END,     KC_NO
  ),

};

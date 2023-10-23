#include QMK_KEYBOARD_H

#define SYMTAB LT(3, KC_TAB)
#define NUMESC LT(4, KC_ESC)
#define SYMSPC LT(2, KC_SPC)
#define FUNENT LT(5, KC_ENT)
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

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_shift_enter[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_space[] = {KC_X, KC_C, KC_V, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_shift_enter, S(KC_ENT)),
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_space, KC_SPC),
};

enum custom_keycodes {
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    FFNXT,
    FFPRV,
    COMSPC,
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
        case SYMSPC:
            return true;
        case SYMTAB:
            return true;
        case NUMESC:
            return true;
        default:
            return false;
    }
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
         KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,        KC_J,    KC_L,    KC_U,    KC_Y,     KC_SCLN,
         KC_A,    KC_R,    KC_S,    KC_T,    KC_G,        KC_M,    KC_N,    KC_E,    KC_I,     KC_O,
      SC_LSPO,    KC_X,    KC_C,    KC_D,    KC_V,        KC_K,    KC_H,    KC_COMM, KC_DOT,   SC_RSPC,
                                  SYMTAB,  NUMESC,        FUNENT,  SYMSPC
  ),
  [1] = LAYOUT(
         KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,        KC_Y,    KC_U,    KC_I,    KC_O,     KC_P,
         KC_A,    KC_S,    KC_D,    KC_F,    KC_G,        KC_H,    KC_J,    KC_K,    KC_L,     KC_SCLN,
      SC_LSPO,    KC_X,    KC_C,    KC_V,    KC_B,        KC_N,    KC_M,    KC_COMM, KC_DOT,   SC_RSPC,
                                  SYMTAB,  NUMESC,        FUNENT,  SYMSPC
  ),
  [2] = LAYOUT(
       KC_GRV, KC_PERC, KC_AMPR, KC_NUHS, KC_PLUS,        KC_NO,    KC_NO,    KC_NO,   KC_NO,    KC_NO,
      KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),        KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,
         KC_Z,  KC_DLR,  ATSIGN, KC_LBRC, KC_RBRC,        KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_TRNS,
                                   KC_NO,   KC_NO,        KC_NO,   KC_TRNS
  ),
  [3] = LAYOUT(
        DF(0),   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_PGUP,  UNDSCR, KC_MINS, KC_EQL,   KC_HOME,
        DF(1),    _ALT,    _GUI,   _LCTL,  TMXPRV,        KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_END,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,  TMXNXT,        KC_PGDN,  TILDE,  KC_SLSH, KC_QUES,  KC_TRNS,
                                 KC_TRNS,   KC_NO,        MO(5),   KC_BSPC
  ),
  [4] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,        KC_NO,  KC_7,     KC_8,    KC_9,     KC_MINS,
         _MEH,    _ALT,    _GUI,   _LCTL,   FFPRV,        KC_NO,  KC_4,     KC_5,    KC_6,     COMSPC,
      KC_TRNS,   _SALT,   _SGUI,   _SCTL,   FFNXT,        KC_NO,  KC_1,     KC_2,    KC_3,     KC_PLUS,
                                   KC_NO, KC_TRNS,        KC_NO,  KC_0
  ),
  [5] = LAYOUT(
      QK_BOOT,   KC_F7,   KC_F8,   KC_F9,  KC_F10,        KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,
      KC_NO  ,   KC_F4,   KC_F5,   KC_F6,  KC_F11,        KC_NO,   _LCTL,   _GUI,    _ALT,     _MEH,
      KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12,        KC_NO,   _SCTL,   _SGUI,   _SALT,    KC_NO,
                                   FFPRV,   FFNXT,        KC_TRNS, KC_NO
  ),
};

#include QMK_KEYBOARD_H
#include <stdio.h>

#define _CTLTAB MT(MOD_LCTL, KC_TAB)
#define _GUIESC MT(MOD_LGUI, KC_ESC)
#define _ALTENT MT(MOD_LALT, KC_ENT)

const uint16_t PROGMEM cmb_lsym[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_rsym[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM cmb_lnav[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_rnav[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_lnum[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_rnum[] = {KC_J, KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM cmb_li3[] = {KC_A, KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_ri3[] = {KC_J, KC_K, KC_L, KC_SCLN, COMBO_END};
const uint16_t PROGMEM cmb_lmeh[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_rmeh[] = {KC_H, KC_J, COMBO_END};
combo_t key_combos[] = {
    COMBO(cmb_lsym, OSL(2)),
    COMBO(cmb_rsym, OSL(2)),
    COMBO(cmb_lnum, OSL(3)),
    COMBO(cmb_rnum, OSL(3)),
    COMBO(cmb_lnav, OSL(4)),
    COMBO(cmb_rnav, OSL(4)),
    COMBO(cmb_li3, OSL(5)),
    COMBO(cmb_ri3, OSL(5)),
    COMBO(cmb_lmeh, OSM(MOD_MEH)),
    COMBO(cmb_rmeh, KC_MEH),
};


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
           SEND_STRING(SS_LCTL(" ") "n");
        }
        break;
    case TMXPRV:
        if (record->event.pressed) {
           SEND_STRING(SS_LCTL(" ") "p");
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

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case _ALTENT:
            return true;
        case _CTLTAB:
            return true;
        case _GUIESC:
            return true;
        default:
            return false;
    }
}

#define PIPE S(KC_NUBS)
#define ATSIGN S(KC_QUOT)
#define UNDSCR S(KC_MINS)
#define TILDE S(KC_NUHS)
#define SFTZ SFT_T(KC_Z)
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
#define _I3TERM G(KC_ENT)
#define MPDTOG MEH(KC_E)
#define PCTLTOG MEH(KC_C)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,     KC_U,     KC_I,    KC_O,     KC_P,    KC_NO,
     KC_NO,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,     KC_J,     KC_K,    KC_L,     KC_SCLN, KC_NO,
     KC_NO,    SFTZ,    KC_X,    KC_C,    KC_V,    KC_B,    KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_N,     KC_M,     KC_COMM, KC_DOT,   KC_RSFT, KC_NO,
                                KC_NO,  MPDTOG, KC_LPRN,  _CTLTAB, _GUIESC,    _ALTENT, KC_SPC, KC_RPRN,  PCTLTOG,  KC_NO
  ),
  [1] = LAYOUT(
     KC_NO,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                        KC_J,     KC_L,     KC_U,    KC_Y,     KC_Z,     KC_NO,
     KC_NO,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                        KC_M,     KC_N,     KC_E,    KC_I,     KC_O,     KC_NO,
     KC_NO,    SFTZ,    KC_X,    KC_C,    KC_D,    KC_V,   KC_NO,   KC_NO,     KC_NO,   KC_NO,  KC_K,     KC_H,     KC_COMM, KC_DOT,   KC_RSFT,  KC_NO,
                                KC_NO,  MPDTOG, KC_LPRN,  _CTLTAB, _GUIESC,    _ALTENT, KC_SPC, KC_RPRN,  PCTLTOG,  KC_NO
  ),
  [2] = LAYOUT(
     KC_NO,  KC_GRV, KC_PERC, KC_NUHS, KC_AMPR, KC_PLUS,                                        KC_NO,    UNDSCR,   KC_MINS, KC_EQL,   KC_NO,   KC_NO,
     KC_NO, KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),                                        KC_LCBR,  KC_LBRC,  KC_RBRC, KC_RCBR,  KC_NO,   KC_NO,
     KC_NO, KC_TRNS,    PIPE,  ATSIGN,  KC_DLR,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,  KC_NO,    TILDE,    KC_SLSH, KC_QUES,  KC_NO,   KC_NO,
                              KC_TRNS,  KC_ENT,  KC_DEL,   MO(3),   KC_NO,     KC_TRNS, KC_BSPC, KC_NO,   KC_NO,    KC_NO
  ),
  [3] = LAYOUT(
     KC_NO,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                                        KC_NO,    KC_7,     KC_8,    KC_9,    KC_MINS,  KC_NO,
     KC_NO,   KC_NO,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                                        KC_NO,    KC_4,     KC_5,    KC_6,    CMASPC,   KC_NO,
     KC_NO, KC_TRNS,   KC_F1,   KC_F2,   KC_F3,  KC_F12,   KC_NO,   KC_NO,     KC_NO,   KC_NO,  KC_RBRC,  KC_1,     KC_2,    KC_3,    KC_PLUS,  KC_NO,
                              KC_TRNS,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,     KC_TRNS, KC_0,   KC_NO,    KC_NO,    KC_NO
  ),
  [4] = LAYOUT(
     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                                        KC_PGUP,  KC_NO,    KC_NO,   KC_NO,    KC_HOME, KC_NO,
     KC_NO,   KC_NO,   KC_NO,  TMXPRV,  TMXNXT,   KC_NO,                                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_END,  KC_NO,
     KC_NO, KC_TRNS,   KC_NO,   FFPRV,   FFNXT,   KC_NO, KC_NO,   KC_NO,       KC_NO,   KC_NO,  KC_PGDN,  KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,
                                KC_NO,   KC_NO,   KC_NO, KC_LCTL, S(KC_LCTL),  KC_TRNS, KC_NO,  KC_NO,    KC_NO,    KC_NO
  ),
  [5] = LAYOUT(
     KC_NO, _I3QUIT, _I3TABS, G(KC_E),  _I3RST,  KC_F12,                                        G(KC_0),  G(KC_7),  G(KC_8), G(KC_9), _I3ASCR,  KC_NO,
     KC_NO,   KC_NO, _I3STCK,   KC_NO, _I3TERM,   KC_NO,                                        _I3MV,    G(KC_4),  G(KC_5), G(KC_6),  _I3SCR,  KC_NO,
     KC_NO, KC_TRNS, G(KC_X),   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_NO,     KC_NO,   KC_NO,   KC_NO,    G(KC_1),  G(KC_2), G(KC_3), _I3RSCR,  KC_NO,
                                KC_NO, KC_NO,   KC_TRNS,   KC_NO,  KC_NO,    KC_TRNS,_I3SPC,   KC_TRNS,  KC_NO,    KC_NO
  )
};

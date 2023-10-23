#include QMK_KEYBOARD_H
#include <stdio.h>

/* Define our QWERTY home row mods */
#define CTL_F CTL_T(KC_F)
#define CTL_J CTL_T(KC_J)
#define SFT_D SFT_T(KC_D)
#define SFT_K SFT_T(KC_K)
#define GUI_S GUI_T(KC_S)
#define GUI_L GUI_T(KC_L)
#define ALT_A ALT_T(KC_A)
#define ALT_SC ALT_T(KC_SCLN)
#define MEH_G MEH_T(KC_G)
#define MEH_H MEH_T(KC_H)
/* Define our layer switching keys */
#define SYM_TAB LT(1, KC_TAB)
#define NUM_ESC LT(3, KC_ESC)
#define FUN_ENT LT(4, KC_ENT)
#define SYM_SPC LT(2, KC_SPC)
/* Define some character keys to keep letter count low */
#define PIPE S(KC_NUBS)
#define ATSIGN S(KC_QUOT)
#define UNDSCR S(KC_MINS)
#define TILDE S(KC_NUHS)

bool get_retro_tapping(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_A:
        case ALT_SC:
        case GUI_S:
        case GUI_L:
        case SFT_D:
        case SFT_K:
        case CTL_F:
        case CTL_J:
        case MEH_G:
        case MEH_H:
        case SYM_TAB:
        case NUM_ESC:
        case FUN_ENT:
        case SYM_SPC:
        case SC_LSPO:
        case SC_RSPC:
            return true;
        default:
            return false;
    }
}

enum custom_keycodes {
    COMSPC = SAFE_RANGE,
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
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
  KC_NO,      KC_Q,       KC_W,       KC_E,       KC_R,        KC_T,                                         KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,      KC_NO,
  KC_NO,     ALT_A,      GUI_S,      SFT_D,      CTL_F,       MEH_G,                                          MEH_H,      CTL_J,      SFT_K,      GUI_L,      ALT_SC,   KC_NO,
  KC_NO,   SC_LSPO,       KC_X,       KC_C,       KC_V,        KC_B,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_N,       KC_M,       KC_COMM,    KC_DOT,     SC_RSPC,     KC_NO,
                                     KC_NO,      KC_NO,     SYM_TAB,  NUM_ESC, KC_NO,      KC_NO,  FUN_ENT,  SYM_SPC,    CW_TOGG,    KC_NO
  ),
  [1] = LAYOUT(
   KC_NO,     KC_NO,     KC_NO,    KC_BSPC,     KC_DEL,      KC_NO,                                         KC_PGUP,    UNDSCR,    KC_MINS,    KC_EQL,     KC_HOME,   KC_NO,
   KC_NO,     KC_NO,     KC_NO,     KC_SPC,     KC_ENT,      KC_NO,                                         KC_LEFT,    KC_DOWN,   KC_UP,      KC_RIGHT,   KC_END,    KC_NO,
   KC_NO,   C(KC_Z),   C(KC_X),    C(KC_C),    C(KC_V),      KC_NO,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_PGDN,    TILDE,     KC_SLSH,    KC_QUES,    KC_NO,     KC_NO,
                                     KC_NO,    CW_TOGG,    KC_TRNS,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_BSPC,    KC_NO,     KC_NO
  ),
  [2] = LAYOUT(
   KC_NO,    KC_GRV,   KC_PLUS,    KC_LCBR,    KC_RCBR,    S(KC_2),                                         KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,   KC_NO,
   KC_NO,   KC_NUBS,   KC_NUHS,    KC_LPRN,    KC_RPRN,    KC_QUOT,                                         KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,   KC_NO,
   KC_NO,     KC_Z, S(KC_QUOT),    KC_LBRC,    KC_RBRC,      KC_NO,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_NO,      KC_NO,      KC_NO,      KC_NO,       KC_NO,     KC_NO,
                                     KC_NO,    CW_TOGG,      KC_NO,  KC_NO,   KC_NO,      KC_NO,    KC_NO,  KC_TRNS,    KC_NO,      KC_NO
  ),
  [3] = LAYOUT(
    KC_NO,    KC_NO,     KC_F7,      KC_F8,      KC_F9,     KC_F10,                                         KC_NO,      KC_7,       KC_8,       KC_9,       KC_MINS,   KC_NO,
    KC_NO,  QK_BOOT,     KC_F4,      KC_F5,      KC_F6,     KC_F11,                                         KC_NO,      KC_4,       KC_5,       KC_6,       COMSPC,    KC_NO,
    KC_NO,    KC_NO,     KC_F1,      KC_F2,      KC_F3,     KC_F12,  KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,      KC_1,       KC_2,       KC_3,       KC_PLUS,   KC_NO,
                                     KC_NO,      KC_NO,      KC_NO, KC_TRNS,  KC_NO,      KC_NO,   KC_BSPC, KC_0,       KC_NO,     KC_NO
  ),
  [4] = LAYOUT(
    KC_NO,    KC_NO,     KC_F7,      KC_F8,      KC_F9,     KC_F10,                                         KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,   KC_NO,
    KC_NO,  QK_BOOT,     KC_F4,      KC_F5,      KC_F6,     KC_F11,                                         KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,    KC_NO,
    KC_NO,    KC_NO,     KC_F1,      KC_F2,      KC_F3,     KC_F12,  KC_NO,   KC_NO,      KC_NO,   KC_NO,   KC_NO,      KC_NO,       KC_NO,       KC_NO,       KC_NO,   KC_NO,
                                     KC_NO,      KC_NO,      KC_NO, KC_TRNS,  KC_NO,      KC_NO,   KC_TRNS, KC_0,       KC_END,     KC_NO
  ),
};

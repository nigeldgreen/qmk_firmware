#include QMK_KEYBOARD_H
#include <stdio.h>
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
#define I3QUIT S(G(KC_Q))
#define I3TABS G(KC_W)
#define I3RST S(G(KC_P))
#define I3STCK G(KC_F)
#define I3ASCR S(G(KC_MINS))
#define I3SCR G(KC_MINS)
#define I3RSCR S(G(KC_SPC))
#define I3SPC G(KC_SPC)
#define I3TAB G(KC_TAB)

const uint16_t PROGMEM cmb_delete[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_backspace[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM cmb_escape[] = {KC_S, KC_D, COMBO_END};
const uint16_t PROGMEM cmb_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_enter[] = {KC_S, KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM cmb_cut[] = {KC_R, KC_T, COMBO_END};
const uint16_t PROGMEM cmb_copy[] = {KC_F, KC_G, COMBO_END};
const uint16_t PROGMEM cmb_paste[] = {KC_V, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_undo[] = {KC_G, KC_B, COMBO_END};
const uint16_t PROGMEM cmb_i3drun[] = {KC_X, KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM cmb_i3tab[] = {KC_X, KC_C, COMBO_END};
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
    COMBO(cmb_delete, KC_DEL),
    COMBO(cmb_backspace, KC_BSPC),
    COMBO(cmb_escape, KC_ESC),
    COMBO(cmb_tab, KC_TAB),
    COMBO(cmb_enter, KC_ENT),
    COMBO(cmb_cut, C(KC_X)),
    COMBO(cmb_copy, C(KC_C)),
    COMBO(cmb_paste, C(KC_V)),
    COMBO(cmb_undo, C(KC_Z)),
    COMBO(cmb_i3drun, G(KC_SPC)),
    COMBO(cmb_i3tab, G(KC_TAB)),
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
    TMXNXT = SAFE_RANGE,
    TMXPRV,
    FFNXT,
    FFPRV,
    LOREM,
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
    case LOREM:
        if (record->event.pressed) {
            SEND_STRING("dummy text ");
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
       KC_ESC,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC,
      CW_TOGG,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT,
        LOREM, SC_LSPO,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,     KC_M,     KC_COMM, KC_DOT,  SC_RSPC, KC_NO,
                                            MO(6),  SYMTAB,  NUMESC,       FUNENT, SYMSPC,   MO(6)
  ),
  [1] = LAYOUT(
       KC_ESC,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,     KC_L,     KC_U,    KC_O,    KC_Y,    KC_BSPC,
      CW_TOGG,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,     KC_N,     KC_E,    KC_I,    KC_SCLN, KC_ENT,
        LOREM, KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_RSFT, KC_NO,
                                            MO(6),  SYMTAB,  NUMESC,       FUNENT, SYMSPC,   MO(6)
  ),
  [2] = LAYOUT(
      KC_TRNS,  KC_GRV, KC_PERC, KC_AMPR, KC_NUHS, KC_PLUS,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, KC_NUBS, KC_PAST, KC_EXLM, KC_QUOT, S(KC_2),                        KC_NO,    _LCTL,    _GUI,    _ALT,    _MEH,    KC_TRNS,
      KC_TRNS,    KC_Z,  KC_DLR,  ATSIGN, KC_LBRC, KC_RBRC,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,  TMXPRV,  TMXNXT,      KC_TRNS, KC_TRNS,  KC_TRNS
  ),
  [3] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_PGUP,  UNDSCR,   KC_MINS, KC_EQL,   KC_HOME, MEH(KC_E),
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL, KC_TRNS,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_END,  MEH(KC_C),
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,                        KC_PGDN,  TILDE,    KC_SLSH, KC_QUES,  CW_TOGG, KC_TRNS,
                                            KC_NO, KC_TRNS,   KC_NO,      KC_DEL,  KC_BSPC,  KC_TRNS
  ),
  [4] = LAYOUT(
      KC_TRNS,   KC_F5,   KC_F7,   KC_F8,  KC_F9,   KC_F10,                        KC_PGUP,  KC_7,     KC_8,    KC_9,    KC_MINS,  KC_TRNS,
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL,  KC_F12,                        KC_Z,     KC_4,     KC_5,    KC_6,    COMSPC,   KC_TRNS,
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_F2,                        KC_PGDN,  KC_1,     KC_2,    KC_3,    KC_PLUS,  KC_TRNS,
                                            KC_NO,   KC_NO, KC_TRNS,      KC_BSPC, KC_0,     KC_TRNS
  ),
  [5] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        KC_NO,    _LCTL,    _GUI,    _ALT,   _MEH,     KC_TRNS,
      KC_TRNS,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,   FFPRV,   FFNXT,     KC_TRNS,  KC_NO,    KC_TRNS
  ),
  [6] = LAYOUT(
        KC_NO,  I3QUIT,  I3TABS, I3STCK,   I3RST,  KC_F12,                        G(KC_0),  G(KC_I),  G(KC_O), G(KC_9),  I3ASCR,   KC_TRNS,
        KC_NO, G(KC_Q),   KC_NO,  KC_NO, KC_LSFT, G(KC_G),                        G(KC_M),  G(KC_T),  G(KC_N), G(KC_E),   I3SCR,   KC_TRNS,
      KC_TRNS, KC_NO,   G(KC_X),   KC_NO,   KC_NO,   I3TAB,                        KC_NO,    G(KC_A),  G(KC_R), G(KC_S),  I3RSCR,   KC_TRNS,
                                          KC_TRNS,   KC_NO,   KC_NO,       KC_NO,  I3SPC,   KC_TRNS
  )
};
#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

void oled_render_layer_state(void) {
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 0:
            oled_write_P(PSTR("QWERTY\n"), false);
            break;
        case 1:
            oled_write_P(PSTR("Colemak\n"), false);
            break;
        case 2:
            oled_write_P(PSTR("LEFT SYMBOLS\n"), false);
            break;
        case 3:
            oled_write_P(PSTR("RIGHT SYMBOLS\n"), false);
            break;
        case 4:
            oled_write_P(PSTR("NUMBERS\n"), false);
            break;
        case 5:
            oled_write_P(PSTR("FN KEYS\n"), false);
            break;
        case 6:
            oled_write_P(PSTR("I3 / SYSTEM\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("==CAP==\n") : PSTR("\n"), false);
    oled_write_P(led_state.num_lock ? PSTR("==NUM==\n") : PSTR("\n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("==SCR==\n") : PSTR("\n"), false);
}

void render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        /* oled_render_logo(); */
        oled_render_layer_state();
    } else {
        render_logo();
        /* oled_render_layer_state(); */
    }
    return false;
}
#endif // OLED_ENABLE

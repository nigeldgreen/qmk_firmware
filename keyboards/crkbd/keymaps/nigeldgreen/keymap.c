#include QMK_KEYBOARD_H
#include <stdio.h>

#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _TMUX C(KC_F)
#define _QWERTY DF(0)
#define _CMAK DF(1)
#define _MOUSE DF(7)
#define _NUM MO(4)
#define _I3DEL LT(6, KC_DEL)
#define _SYMTAB LT(3, KC_TAB)
#define _NUMESC LT(4, KC_ESC)
#define _FUNENT LT(5, KC_ENT)
#define _SYMSPC LT(2, KC_SPC)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _I3SCR G(KC_MINS)
#define _I3SSCR SGUI(KC_MINS)
#define _I3RSCR SGUI(KC_SPC)
#define _I3SHFT LM(6, MOD_LSFT)
#define _I3QUIT SGUI(KC_Q)
#define _I3RST SGUI(KC_R)
#define _I3TABS SGUI(KC_W)
#define _I3STCK SGUI(KC_S)
#define _I3MV S(G(KC_DOT))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
      _QWERTY,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,     KC_U,     KC_I,    KC_O,    KC_P,    _QWERTY,
       _MOUSE,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,     KC_J,     KC_K,    KC_L,    KC_SCLN, _CMAK,
    G(KC_SPC), KC_LSFT,    KC_X,    KC_C,    KC_V,    KC_B,                        KC_N,     KC_M,     KC_COMM, KC_DOT,  KC_RSFT, KC_CAPS,
                                           _I3DEL, _SYMTAB, _NUMESC,     _FUNENT,  _SYMSPC,  MO(6)
  ),
  [1] = LAYOUT(
      _QWERTY,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,     KC_L,     KC_U,    KC_Y,    KC_SCLN, _QWERTY,
       _MOUSE,    KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_M,     KC_N,     KC_E,    KC_I,    KC_O,    _CMAK,
         KC_Z, KC_LSFT,    KC_X,    KC_C,    KC_D,    KC_V,                        KC_K,     KC_H,     KC_COMM, KC_DOT,  KC_RSFT, KC_CAPS,
                                           _I3DEL, _SYMTAB, _NUMESC,     _FUNENT,  _SYMSPC,  MO(6)
  ),
  [2] = LAYOUT(
      KC_TRNS,  KC_GRV, KC_PLUS, KC_NUHS, KC_LCBR, KC_RCBR,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, KC_NUBS, KC_PAST, KC_EXLM, KC_LPRN, KC_RPRN,                        _TMUX,    _LCTL,    _GUI,    _ALT,    _MEH,    KC_TRNS,
      KC_TRNS, S(KC_3), KC_AMPR, _ATSIGN, KC_LBRC, KC_RBRC,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,   KC_NO,   KC_NO,       KC_NO,  KC_TRNS,    KC_NO
  ),
  [3] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_DLR,   _UNDSCR,  KC_MINS, KC_EQL,  S(KC_2), KC_TRNS,
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,                        KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT,KC_QUOT, KC_TRNS,
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,                        KC_PERC,  _TILDE,   KC_SLSH, KC_QUES, _PIPE,   KC_TRNS,
                                            KC_NO, KC_TRNS,   KC_NO,      KC_DEL,  KC_BSPC,  KC_NO
  ),
  [4] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,  KC_NO,    KC_NO,                        KC_PGUP,  KC_7,     KC_8,    KC_9,    KC_HOME, KC_TRNS,
      KC_TRNS,    _MEH,    _ALT,    _GUI,   _LCTL,   _TMUX,                        KC_Z,     KC_4,     KC_5,    KC_6,    KC_END,  KC_TRNS,
      KC_TRNS, KC_TRNS,   _SALT,   _SGUI,   _SCTL,   KC_NO,                        KC_PGDN,  KC_1,     KC_2,    KC_3,    KC_NO,   KC_TRNS,
                                            KC_NO,   KC_NO, KC_TRNS,       KC_NO,  KC_0,     KC_NO
  ),
  [5] = LAYOUT(
      KC_TRNS,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                        _TMUX,    _LCTL,    _GUI,    _ALT,    _MEH,    KC_TRNS,
      KC_TRNS,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                        KC_NO,    _SCTL,    _SGUI,   _SALT,   KC_TRNS, KC_TRNS,
                                            KC_NO,   KC_NO,   KC_NO,     KC_TRNS,  KC_NO,    KC_NO
  ),
  [6] = LAYOUT(
      KC_TRNS, _I3QUIT, _I3TABS, G(KC_E),  _I3RST,   KC_NO,                        KC_NO,    G(KC_7),  G(KC_8), G(KC_9), _I3SSCR, KC_TRNS,
      KC_TRNS,   KC_NO, _I3STCK,   KC_NO, G(KC_F),   KC_NO,                        _I3MV,    G(KC_4),  G(KC_5), G(KC_6), _I3SCR,  KC_TRNS,
      KC_TRNS, KC_LSFT,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                        KC_NO,    G(KC_1),  G(KC_2), G(KC_3), _I3RSCR, KC_TRNS,
                                          KC_TRNS,   KC_NO, KC_NO,         KC_NO,  G(KC_0),  KC_NO
  ),
  [7] = LAYOUT(
      _QWERTY,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_ENT,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_SPC,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,  KC_DEL,                        KC_NO,    KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_TRNS,
                                          KC_TRNS,   KC_NO, KC_TRNS,       KC_NO,  KC_NO,    KC_NO
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
            oled_write_P(PSTR("COLEMAK\n"), false);
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
            oled_write_P(PSTR("I3/SYSTEM\n"), false);
            break;
        case 7:
            oled_write_P(PSTR("MOUSE\n"), false);
            break;
        default:
            oled_write_P(PSTR("undefined\n"), false);
    }
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.num_lock ? PSTR("==NUM==\n") : PSTR("\n"), false);
    oled_write_P(led_state.caps_lock ? PSTR("==CAP==\n") : PSTR("\n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("==SCR==\n") : PSTR("\n"), false);
}

void oled_render_logo(void) {
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
        oled_render_logo();
        /* oled_render_layer_state(); */
    }
    return false;
}
#endif // OLED_ENABLE

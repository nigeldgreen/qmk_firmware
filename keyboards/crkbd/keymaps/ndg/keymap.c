#include QMK_KEYBOARD_H
#include <stdio.h>
#define _MEH OSM(MOD_MEH)
#define _ALT OSM(MOD_LALT)
#define _SALT OSM(MOD_LSFT | MOD_LALT)
#define _LCTL OSM(MOD_LCTL)
#define _SCTL OSM(MOD_LSFT | MOD_LCTL)
#define _GUI OSM(MOD_LGUI)
#define _SGUI OSM(MOD_LSFT | MOD_LGUI)
#define _CTLTAB CTL_T(KC_TAB)
#define _GUIESC GUI_T(KC_ESC)
#define _GUITAB GUI_T(KC_TAB)
#define _GUISPC GUI_T(KC_SPC)
#define _GUI0 G(KC_0)
#define _SFT_Z SFT_T(KC_Z)
#define _PIPE S(KC_NUBS)
#define _ATSIGN S(KC_QUOT)
#define _UNDSCR S(KC_MINS)
#define _TILDE S(KC_NUHS)
#define _I3SCR G(KC_MINS)
#define _I3SCRMV S(G(KC_MINS))
#define _I3SHFT LM(_I3, MOD_LSFT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      MO(2),  KC_Q,   KC_W,   KC_E,     KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     MO(2),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
       MO(1), KC_A,   KC_S,   KC_D,     KC_F,    KC_G,                         KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  MO(1),
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_Z,  KC_LSFT, KC_X,   KC_C,     KC_V,    KC_B,                         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_RSFT,  KC_NO,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                    _ALT, _CTLTAB, _GUIESC,           KC_ENT,  KC_SPC,  _MEH
                                      //`--------------------------'  `--------------------------'

  ),

  [1] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      KC_TRNS,  KC_GRV, KC_PLUS, KC_NUHS, KC_LCBR, KC_RCBR,                    KC_DLR,  _UNDSCR, KC_MINS, KC_EQL,   S(KC_2), KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+---------+--------+--------|
        MO(3), KC_NUBS, KC_PAST, KC_EXLM, KC_LPRN, KC_RPRN,                    KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, KC_QUOT, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+---------+--------+--------|
      KC_TRNS, S(KC_3), KC_AMPR, _ATSIGN, KC_LBRC, KC_RBRC,                    KC_PERC, _TILDE,  KC_SLSH, KC_QUES,  _PIPE,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+---------+--------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_DEL,  KC_BSPC, KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      KC_TRNS,   KC_NO,   KC_F7,   KC_F8,   KC_F9,  KC_F10,                    KC_PGUP, KC_7,    KC_8,    KC_9,    KC_HOME,  KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_TRNS, QK_BOOT,   KC_F4,   KC_F5,   KC_F6,  KC_F11,                    KC_Z,    KC_4,    KC_5,    KC_6,    KC_END,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_TRNS,   KC_NO,   KC_F1,   KC_F2,   KC_F3,  KC_F12,                    KC_PGDN, KC_1,    KC_2,    KC_3,    KC_NO,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                          KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_0,    KC_TRNS
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,------------------------------------------------------.
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                 S(G(KC_Q)), G(KC_7), G(KC_8), G(KC_9), _I3SCRMV, KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                 S(G(KC_R)), G(KC_4), G(KC_5), G(KC_6), _I3SCR,   KC_TRNS,
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+---------+--------|
      KC_TRNS,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                 S(G(KC_W)), G(KC_1), G(KC_2), G(KC_3), KC_NO,    KC_TRNS,
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+---------+--------|
                                   KC_NO, _GUITAB, _GUISPC,           KC_NO,   _GUI0,   KC_NO
                                      //`--------------------------'  `--------------------------'
  )
};

#ifdef OLED_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master()) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Symbols"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Numbers"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("I3 stuff"), false);
            break;
    }
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
        oled_render_layer_state();
    } else {
        oled_render_logo();
    }
    return false;
}
#endif // OLED_ENABLE

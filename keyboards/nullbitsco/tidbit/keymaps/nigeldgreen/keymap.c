#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT(
                  MEH(KC_X),  MEH(KC_C),  MEH(KC_V),
    MO(1),        KC_P7,      KC_P8,      KC_P9,
    KC_NO,        KC_P4,      KC_P5,      KC_P6,
    KC_KB_MUTE,   KC_P1,      KC_P2,      KC_P3,
    QK_BOOT,      KC_P0,      KC_PDOT,    KC_PENT
  ),

  [1] = LAYOUT(
             MEH(KC_W),  MEH(KC_E),  MEH(KC_R),
    KC_TRNS, _______,    _______,    _______,
    _______, _______,    _______,    _______,
    _______, _______,    _______,    _______,
    _______, _______,    _______,    _______
  )
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(KC_MS_WH_UP, KC_MS_WH_DOWN), ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN), ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN), },
    [1] = { ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), ENCODER_CCW_CW(_______, _______), },
};
#endif

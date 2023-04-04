#include QMK_KEYBOARD_H
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
#define EXTRA_SHORT_COMBOS
#define COMBO_COUNT 6
#define ACTION_TAP_DANCE_FN_KEYCODE(user_fn, kc) {  \
    .fn = { NULL, user_fn, NULL }, \
    .user_data = (void *)&((tap_dance_pair_t) { kc, 0 }) \
}
uint16_t COMBO_LEN = COMBO_COUNT;

const uint16_t PROGMEM mpd_prev[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM mpd_next[] = {KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM mpd_toggle[] = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM pctl_prev[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM pctl_next[] = {KC_C, KC_V, COMBO_END};
const uint16_t PROGMEM pctl_toggle[] = {KC_C, KC_X, KC_V, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(mpd_toggle, MEH(KC_E)),
    COMBO(mpd_prev, MEH(KC_W)),
    COMBO(mpd_next, MEH(KC_R)),
    COMBO(pctl_toggle, MEH(KC_C)),
    COMBO(pctl_prev, MEH(KC_X)),
    COMBO(pctl_next, MEH(KC_V)),
};

enum {
    I3_RST,
    I3_QUT,
    I3_TAB,
    I3_WIN, /* reset window tiling */
    TD_1,
    TD_2,
    TD_3,
    TD_4,
    TD_5,
    TD_6,
    TD_7,
    TD_8,
    TD_9,
};

enum ferris_layers {
  _QWERTY,
  _SYMBOLS,
  _NUMBERS,
  _NAV,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    TD(I3_QUT),  TD(I3_TAB),  TD(I3_WIN),  TD(I3_RST),  KC_T,    KC_Y,  KC_U,        KC_I,        KC_O,        KC_P,
    KC_A,        LT(3, KC_S), LT(2, KC_D), LT(1, KC_F), KC_G,    LT(1, KC_J),  MEH_T(KC_ENT), LT(2, KC_K), LT(3, KC_L), KC_SCLN,
    SFT_T(KC_Z), KC_X,        KC_C,        KC_V,        KC_B,    KC_M,  KC_COMM,        KC_SPC,     KC_LSFT,      KC_H,
                                GUI_T(KC_ESC), CTL_T(KC_TAB),    KC_DOT, KC_N
  ),
  [_SYMBOLS] = LAYOUT(
    KC_GRV,  KC_DLR,  KC_NUBS,    KC_NUHS,    KC_LCBR,    KC_RCBR,    S(KC_MINS), KC_MINS, KC_EQL,  KC_PAST,
    KC_NO,   KC_PERC, KC_EXLM,    KC_QUES,    KC_LPRN,    KC_QUOT,    KC_DEL,     S(KC_2), KC_CIRC, C(KC_6),
    KC_TRNS, KC_AMPR, S(KC_NUBS), S(KC_QUOT), KC_LBRC,    S(KC_NUHS), KC_SLSH,    KC_BSPC, KC_TRNS, KC_RPRN,
                         GUI_T(KC_ESC), CTL_T(KC_TAB),    S(KC_3), KC_RBRC
  ),
  [_NUMBERS] = LAYOUT(
    KC_F9, KC_F10, KC_F11, KC_F12,  KC_NO,                 KC_NO,     TD(TD_7), TD(TD_8), TD(TD_9), KC_NO,
    KC_F5, KC_F6,  KC_F7,  KC_F8,   RCS(KC_F2),                 TD(TD_4), KC_TRNS, TD(TD_5), TD(TD_6), KC_NO,
    KC_F1, KC_F2,  KC_F3,  KC_F4,   RCS(KC_F5),                 TD(TD_1), TD(TD_2), KC_TRNS, KC_TRNS, KC_NO,
                         KC_TRNS, KC_TRNS,                 TD(TD_3),   KC_0
  ),
  [_NAV] = LAYOUT(
    KC_NO, KC_NO, RCS(KC_PGUP), C(KC_PGUP), QK_BOOTLOADER,  KC_PGUP, KC_NO,     KC_NO, KC_NO,     KC_NO,
    KC_LCTL, KC_NO, RCS(KC_PGDN), C(KC_PGDN), KC_NO,          KC_DOWN, SGUI(KC_DOT), KC_UP, KC_RIGHT, KC_HOME,
    KC_LSFT, KC_NO, KC_NO,        KC_NO,      KC_NO,          KC_NO, KC_NO,     G(KC_RIGHT), KC_END,     KC_LEFT,
                     SGUI(KC_COMM), G(KC_LEFT),             KC_TRNS, KC_PGDN
  )
};

void process_num_key (tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    uint16_t keycode = pair->kc1;

    if (state->count == 1) {
        tap_code16(keycode);
    } else if (state->count == 2) {
        tap_code16(G(keycode));
    } else if (state->count == 3) {
        tap_code16(SGUI(keycode));
    } else {
        reset_tap_dance (state);
    }
}

void process_gui_key (tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    uint16_t keycode = pair->kc1;

    if (state->count == 1) {
        tap_code16(keycode);
    } else if (state->count == 2) {
        tap_code16(keycode);
        tap_code16(keycode);
    } else if (state->count == 3) {
        tap_code16(G(keycode));
    } else {
        reset_tap_dance (state);
    }
}

void process_sgui_key (tap_dance_state_t *state, void *user_data) {
    tap_dance_pair_t *pair = (tap_dance_pair_t *)user_data;
    uint16_t keycode = pair->kc1;

    if (state->count == 1) {
        tap_code16(keycode);
    } else if (state->count == 2) {
        tap_code16(keycode);
        tap_code16(keycode);
    } else if (state->count == 3) {
        tap_code16(SGUI(keycode));
    } else {
        reset_tap_dance (state);
    }
}

tap_dance_action_t tap_dance_actions[] = {
    [I3_RST] = ACTION_TAP_DANCE_FN_KEYCODE(process_sgui_key, KC_R),
    [I3_QUT] = ACTION_TAP_DANCE_FN_KEYCODE(process_sgui_key, KC_Q),
    [I3_TAB] = ACTION_TAP_DANCE_FN_KEYCODE(process_sgui_key, KC_W),
    [I3_WIN] = ACTION_TAP_DANCE_FN_KEYCODE(process_gui_key, KC_E),
    [TD_1] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_1),
    [TD_2] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_2),
    [TD_3] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_3),
    [TD_4] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_4),
    [TD_5] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_5),
    [TD_6] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_6),
    [TD_7] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_7),
    [TD_8] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_8),
    [TD_9] = ACTION_TAP_DANCE_FN_KEYCODE(process_num_key, KC_9),
};

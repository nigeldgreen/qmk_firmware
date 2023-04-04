#pragma once
#define MOUSEKEY_INTERVAL 16
#define MOUSEKEY_TIME_TO_MAX 40
#define MOUSEKEY_DELAY 100
#define MOUSEKEY_WHEEL_DELAY 100
#define MOUSEKEY_WHEEL_INTERVAL 50
#define MOUSEKEY_WHEEL_TIME_TO_MAX 100

#define TAPPING_TERM 200
#define PERMISSIVE_HOLD
#define IGNORE_MOD_TAP_INTERRUPT
#define QUICK_TAP_TERM 0

#undef DIRECT_PINS
#define DIRECT_PINS { \
    { D7, F7, F6, F5, F4 }, \
    { B1, B3, B2, B6, D3 }, \
    { D1, D0, D4, C6, E6 }, \
    { B4, B5, NO_PIN, NO_PIN, NO_PIN } \
}
#undef DIRECT_PINS_RIGHT
#define DIRECT_PINS_RIGHT { \
    { F4, F5, F6, F7, D7 }, \
    { D3, B6, B2, B3, B1 }, \
    { E6, C6, D4, D0, D1 }, \
    { B5, B4, NO_PIN, NO_PIN, NO_PIN } \
}

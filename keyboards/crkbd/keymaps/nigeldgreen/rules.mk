# MOUSEKEY_ENABLE = yes    # Mouse keys
# RGBLIGHT_ENABLE = yes    # Enable WS2812 RGB underlight.
OLED_ENABLE     = yes
OLED_DRIVER     = SSD1306
LTO_ENABLE      = yes

SRC += features/layer_lock.c
SRC += features/select_word.c

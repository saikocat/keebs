# VIA required
VIA_ENABLE = yes
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
TERMINAL_ENABLE = no

# Hardware build specific
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes

EXTRAKEY_ENABLE = yes
LTO_ENABLE = yes
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no

SRC += ./lib/rotary_encoder.c \
       ./lib/bitc_led.c

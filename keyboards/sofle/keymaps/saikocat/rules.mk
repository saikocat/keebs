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

# Bit-C uses atmel-dfu
BOOTLOADER = atmel-dfu

SRC += features/rotary_encoder.c \
       features/bitc_led.c \
       features/pet_neko.c

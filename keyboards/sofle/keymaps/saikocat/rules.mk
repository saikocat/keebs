# VIA required
VIA_ENABLE = yes

# Hardware build specific
OLED_DRIVER_ENABLE = yes
ENCODER_ENABLE = yes

LTO_ENABLE = yes
WPM_ENABLE = yes

EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = no

RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no
CONSOLE_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
NKRO_ENABLE = no

# Bit-C uses atmel-dfu
BOOTLOADER = atmel-dfu

LIB_SRC += features/rotary_encoder.c \
       features/bitc_led.c \
       features/pet_neko.c

SRC += keymap_encoder.c \
       keymap_led.c \
       keymap_oled.c

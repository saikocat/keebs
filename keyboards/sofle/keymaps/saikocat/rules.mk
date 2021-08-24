# VIA required
VIA_ENABLE = yes

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
FAUXCLICKY_ENABLE = no

# Bit-C uses atmel-dfu
BOOTLOADER = atmel-dfu


# If "-e OLED=" or "OLED=NEKO qmk ..." is passed as environment variable
ifneq ($(strip $(OLED)),)
       OLED_DRIVER_ENABLE = yes
       OPT_DEFS += -D${OLED}
       ifeq ($(OLED), $(filter $(OLED), NEKO))
              SRC += features/oled_pet_neko.c keymap_oled.c
       endif
endif

ifneq ($(strip $(BITC)),)
       OPT_DEFS += -DHW_BITC
       SRC += features/bitc_led.c keymap_led.c
endif

ifneq ($(strip $(ROTARY_ENCODER)),)
       ENCODER_ENABLE = yes
       SRC += features/rotary_encoder.c keymap_encoder.c
endif

# BITC=1 ROTARY_ENCODER=1 OLED=NEKO qmk compile -kb sofle/rev1 -km saikocat

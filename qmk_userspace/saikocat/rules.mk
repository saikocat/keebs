SRC += saikocat.c

# Enable Link Time Optimization wherever supported
ifneq ($(PLATFORM),CHIBIOS)
	ifneq ($(strip $(LTO_SUPPORTED)), no)
		LTO_ENABLE = yes
	endif
endif

# Disable unused features to reduce firmware size
GRAVE_ESC_ENABLE = no

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

EXTRAKEY_ENABLE = no
MOUSEKEY_ENABLE = no


# Enable additional LED features that Bit-C provided
ifeq ($(strip $(LED_INDICATOR_ENABLE)), yes)
	OPT_DEFS += -DLED_INDICATOR_ENABLE
	SRC += led_custom.c

	ifeq ($(strip $(LED_PROVIDER)), bit_c)
		OPT_DEFS += -DLED_PROVIDER_BIT_C
		SRC += led_provider_bit_c.c

        $(info Custom 'LED_PROVIDER' is $(LED_PROVIDER))
	endif
endif

ifneq ($(strip $(ENCODER_ENABLE)),)
	SRC += encoder_custom.c

	ifneq ($(strip $(ENCODER_CUSTOM_RESOLUTION)),)
		OPT_DEFS += -DENCODER_CUSTOM_RESOLUTION=$(ENCODER_CUSTOM_RESOLUTION)

        $(info Custom 'ENCODER_CUSTOM_RESOLUTION' is $(ENCODER_CUSTOM_RESOLUTION))
	endif
endif

# -e ENCODER_ENABLE=yes
# OPT_DEFS=-DENCODER_RESOLUTION=4

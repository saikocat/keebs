SRC += saikocat.c \
		behaviours/callbacks.c \
		behaviours/process_records.c \
		behaviours/matrix_scan.c \
		behaviours/power_management.c \
		behaviours/tap_hold.c

# Enable Link Time Optimization wherever supported
ifneq ($(PLATFORM),CHIBIOS)
	ifneq ($(strip $(LTO_SUPPORTED)), no)
		LTO_ENABLE = yes
	endif
endif

CONSOLE_ENABLE = no

# Disable unused features to reduce firmware size
GRAVE_ESC_ENABLE = no
RGBLIGHT_ENABLE = no
BACKLIGHT_ENABLE = no
SLEEP_LED_ENABLE = no
COMMAND_ENABLE = no
AUDIO_ENABLE = no
BLUETOOTH_ENABLE = no
MIDI_ENABLE = no
TERMINAL_ENABLE = no
UNICODE_ENABLE = no
NKRO_ENABLE = no
FAUXCLICKY_ENABLE = no
MUSIC_ENABLE = no
MOUSEKEY_ENABLE = no
# EXTRAKEY_ENABLE = no

LTO_ENABLE = yes
BOOTMAGIC_ENABLE = yes
BOOTLOADER = atmel-dfu

# Combos
ifeq ($(strip $(CUSTOM_COMBO_ENABLE)), yes)
	COMBO_ENABLE = yes
	VPATH += keyboards/gboards/
	SRC += combos/combos.c
endif

# Enable custom OLED features
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_ENABLE = yes
	OLED_DRIVER ?= SSD1306
	SRC += features/oled.c
    $(info 'OLED_ENABLE' is $(OLED_ENABLE))

	ifeq ($(OLED_CUSTOM_MASCOT), neko)
		OPT_DEFS += -DOLED_CUSTOM_MASCOT
		SRC += features/oled_mascot_neko.c

        $(info 'OLED_CUSTOM_MASCOT' is $(OLED_CUSTOM_MASCOT))
	endif
endif


ifeq ($(strip $(CUSTOM_ENCODER_ENABLE)), yes)
	SRC += features/encoder.c
	ENCODER_ENABLE = yes
    $(info 'ENCODER_ENABLE' is $(ENCODER_ENABLE))

	ifneq ($(strip $(ENCODER_CUSTOM_RESOLUTION)),)
		OPT_DEFS += -DENCODER_CUSTOM_RESOLUTION=$(ENCODER_CUSTOM_RESOLUTION)

        $(info 'ENCODER_CUSTOM_RESOLUTION' is $(ENCODER_CUSTOM_RESOLUTION))
	endif
else
	ENCODER_ENABLE = no
endif

# -e ENCODER_ENABLE=yes
# OPT_DEFS=-DENCODER_RESOLUTION=4

PIMORONI_TRACKBALL_ENABLE ?= no
ifeq ($(strip $(PIMORONI_TRACKBALL_ENABLE)), yes)
	POINTING_DEVICE_ENABLE = yes
	POINTING_DEVICE_DRIVER = pimoroni_trackball

	OPT_DEFS += -DPIMORONI_TRACKBALL_ENABLE

	# Extra custom sauces
	SRC += features/pimoroni_trackball.c

    $(info 'POINTING_DEVICE' is PIMORONI_TRACKBALL)
endif

SLAVE_OLED_MASTER_TRACKBALL ?= no
ifeq ($(strip $(SLAVE_OLED_MASTER_TRACKBALL)), yes)
	OPT_DEFS += -DSLAVE_OLED_MASTER_TRACKBALL
    $(info 'SLAVE_OLED_MASTER_TRACKBALL' is true)

	POINTING_DEVICE_RIGHT ?= yes
	ifeq ($(strip $(POINTING_DEVICE_RIGHT)), yes)
		OPT_DEFS += -DPOINTING_DEVICE_RIGHT
        $(info 'POINTING_DEVICE_RIGHT' is true)
	endif

	POINTING_DEVICE_LEFT ?= no
	ifeq ($(strip $(POINTING_DEVICE_LEFT)), yes)
		OPT_DEFS += -DPOINTING_DEVICE_LEFT
        $(info 'POINTING_DEVICE_LEFT' is true)
	endif
endif

CUSTOM_SPLIT_TRANSPORT_SYNC ?= yes
ifeq ($(strip $(CUSTOM_SPLIT_TRANSPORT_SYNC)), yes)
    ifeq ($(strip $(SPLIT_KEYBOARD)), yes)
        QUANTUM_LIB_SRC += $(USER_PATH)/transports/split_transport_sync.c
        OPT_DEFS += -DCUSTOM_SPLIT_TRANSPORT_SYNC

        $(info 'CUSTOM_SPLIT_TRANSPORT_SYNC' is enabled)
    endif
endif

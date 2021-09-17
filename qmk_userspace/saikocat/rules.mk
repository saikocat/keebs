SRC += saikocat.c

# Enable Link Time Optimization wherever supported
ifneq ($(PLATFORM),CHIBIOS)
    ifneq ($(strip $(LTO_SUPPORTED)), no)
        LTO_ENABLE = yes
    endif
endif

# Disable unused features to reduce firmware size
GRAVE_ESC_ENABLE = no

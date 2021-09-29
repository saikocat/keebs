## Build

    LED_INDICATOR_ENABLE=yes LED_PROVIDER=bit_c \
    OLED_CUSTOM=yes OLED_CUSTOM_MASCOT=neko \
    ENCODER_ENABLE=yes ENCODER_CUSTOM_RESOLUTION=4 \
    WPM_ENABLE=yes \
        qmk compile|flash -j3 -kb sofle/rev1 -km saikocat

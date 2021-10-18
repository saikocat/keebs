## Build

    OLED_CUSTOM=yes OLED_CUSTOM_MASCOT=neko \
    WPM_ENABLE=yes \
        qmk compile|flash -j3 -kb crkbd/rev1 -km saikocat

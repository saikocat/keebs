# VIA keymap for Sofle

Layout in *TODO*

**Importants**:
- Restore `TAPPING_TERM` and `TAP_CODE_DELAY` to default values
- Override `ENCODER_RESOLUTION` to `4`

Features:
- Bit-C Microcontroller LED supports (NOTE: Only work with Master)
- The OLED on master half shows selected mode and caps lock state and neko pet.

Build:

    BITC=1 ROTARY_ENCODER=1 OLED=NEKO qmk compile -kb sofle/rev1 -km saikocat

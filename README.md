# keebs

## Docs
1. [Practical VIA Keymap Guide](docs/pratical_via_keymap_guide.md)
2. [Iris Rev 4 Modding Blog](docs/iris_modding_log.md)
3. [WIP] [QMK Firmware Customization Missing Guide For Newbie](docs/qmk_missing_guide/)
4. [WIP] O-Rings mod guide (vibration dampening) for Sofle & Corne Keyboard for
   consistent sound and soft typing feels.

## Sofle Split Keyboard

### Case

[Sofle v2 RGB Case Remixed STL](https://www.thingiverse.com/thing:4909849)
- Enlarge the TRRS cable cutout hole to accommodate more cables with bigger housing (12mm width x 10mm height).
- Top clearance: 1.5mm, bottom: 2.5mm.
- Redesign mounting holes to add support for sandwich mounting style: M2 screw - Standoff - M2 screw configuration (illustrated in the hand drawn pic by keysbyluker)
- Add 1mm width clearance for USB-C cutout
- [Thingiverse](https://www.thingiverse.com/thing:4909849)

### Mod

    TODO: Standoffs, screws, and o-rings

### Keymap

Customed QMK keymap with modularized hardware features [here](keyboards/sofle/keymaps/saikocat).

- Bit-C Microcontroller LED supports (NOTE: Only work with Master)
- OLED with Neko pet animation - a Luna pet clone.
- Encoder with `ENCODER_RESOLUTION` set to `4`
- Restore default values for `TAPPING_TERM` & `TAP_CODE_DELAY`

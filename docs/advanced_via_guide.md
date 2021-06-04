# Advanced VIA Guide

Essential cheatsheet for staggered column and ortholinear setup. Also this serves as a gentle introduction to some of the advanced features of QMK that are usable in VIA.

## Space Cadet

You will find the keycodes for them under `SPECIAL` section in the bottom left panel.

|Keycode    |VIA UI  |Description                                |
|-----------|--------|-------------------------------------------|
|`KC_LSPO`  |`LS(`   |Left Shift when held, `(` when tapped      |
|`KC_RSPC`  |`RS)`   |Right Shift when held, `)` when tapped     |
|`KC_LCPO`  |`LC(`   |Left Control when held, `(` when tapped    |
|`KC_RCPC`  |`RC)`   |Right Control when held, `)` when tapped   |
|`KC_LAPO`  |`LA(`   |Left Alt when held, `(` when tapped        |
|`KC_RAPC`  |`RA)`   |Right Alt when held, `)` when tapped       |
|`KC_SFTENT`|`SFTENT`|Right Shift when held, Enter when tapped   |

It's highly recommended to use `KC_SFTENT` for `Right Shift` and `Enter` to leave `"` key usable from previous muscle memory in staggered/ortho mode.

If you are gaming then leave all the `Left Modifiers` alone without using `Space Cadets` as more often than not, you will be tapping these keycodes instead of hold (crouch, sprint, etc.).


## References

1. [Keycodes](https://docs.qmk.fm/#/keycodes)
2. [Layers](https://docs.qmk.fm/#/feature_layers)
3. [Mod-Tap](https://docs.qmk.fm/#/mod_tap)
4. [Space Cadet](https://docs.qmk.fm/#/feature_space_cadet)
5. [Jay Liu QMK Cheatsheet](https://jayliu50.github.io/qmk-cheatsheet/)
6. [Thomas Baart QMK Basics](https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk/qmk-basics/)

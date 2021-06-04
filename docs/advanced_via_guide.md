# Advanced VIA Guide

This serves as a gentle introduction to some of the advanced features of QMK that are usable in VIA. Also contains tips for staggered column and ortholinear setup.

## Enter "Any" QMK Keycode

`Any` is a unique key with *pastel pink background* that is located under `SPECIAL` section in the bottom left panel which allows us to assign most QMK keycodes/hex codes (`KC_XXXX`, `0xFF`, etc.). It serves a building block for many customizations in this guide as it allows us to unlock powerful key combination modifiers.

![Any key location](https://i.imgur.com/8uXDFvl.png)

Display wise after assigned the QMK keycode:

* `ADV` will be displayed on top of the keycap and hover over it will show the FULL assigned key combination.
* Some longer keycode like `LT()` will instead display the whole key function on the keycap.
* Invalid keycode will be displayed as a `blank keycap` and when you hover the key, it will show `KC_NO` (NOTHING) in the status bar at the bottom.

![Any key display](https://i.imgur.com/cfSrRXW.png)

## Layers

### Switching and Toggling Layers

These functions allow you to activate layers in various ways. Note that layers are not generally independent layouts – multiple layers can be activated at once, and it's typical for layers to use `KC_TRNS` to allow keypresses to pass through to lower layers. When using momentary layer switching with `MO()`, `LM()`, `TT()`, or `LT()`, make sure to leave the key on the above layers transparent or it may not work as intended.

In the table below, `layer` represents layer number, usual is `0 or 1 or 2 or 3` in VIA (as it has max 3 layers) and `KC_XXXX` represents any valid basic keycode.

|Keycode             |Description                                                                                         |
|--------------------|----------------------------------------------------------------------------------------------------|
|`MO(layer)`         |While held, `MO`mentarily activates `layer`.                                                        |
|`LT(layer, KC_XXXX)`|Layer Tap. <br/> When held: activate `layer`. <br/> When tapped: send `KC_XXXX`                     |
|`TG(layer)`         |Layer Toggle. <br/> When tapped: toggles `layer` on or off                                          |
|`TO(layer)`         |When tapped: activates `layer` and de-activates all other layers (except your default layer         |
|`TT(layer)`         |Layer Tap-Toggle. <br/> When tapped: toggles `layer` on or off. <br/> When held: activates `layer`. |
|`OSL(layer)`        |One-Shot Layer. <br/> Activate `layer` for the next keypress                                        |

### Examples

* Activate `Windows + Space` for language switching with the setup as below (Iris keyboard doesn't have enough keys for a dedicated Windows button). Press and hold `MO(2)` then `MOD_LGUI` key then **RELEASE** `MO(2)` key while still holding on to `MOD_LGUI`, then `KC_SPACE`.
  * `Space` binds on `layer_0`.
  * `Window` / `MOD_LGUI` binds on `layer_2` at `Z` key.
  * `Enter` binds on `layer_1` at `Space` key.
  * `Backspace` binds on `layer_2` at `Space` key.
  * `MO(2)` binds on any activation key.
* `LT(2, KC_ENT)` - when held the key, it activates `layer_2` while tap it serves as `Enter` key. To set up this binding, chose the only pastel pink color `Any` key under `SPECIAL` section and input `LT(2, KC_ENT)` for the key. I use this setup for the key next to my 2u Thumb Cluster on my Iris keyboard.
* VIA has a few useful pre-made and assignable such as `SPC_FN1`/`Space Fn1` (Hold = Layer1, Tap = Space) under `LAYERS` section.

### Caveats
Currently, the layer argument of `LT()` is limited to layers 0-15, and the `kc` argument to the Basic Keycode set, meaning you can’t use keycodes like `LCTL()`, `KC_TILD`, or anything greater than `0xFF`.

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

## Wishlist

As an avid VIM user, all I wanted is the `Leader Key` function to be usable in VIA :(

## References

1. [Keycodes](https://docs.qmk.fm/#/keycodes)
2. [Layers](https://docs.qmk.fm/#/feature_layers)
3. [Mod-Tap](https://docs.qmk.fm/#/mod_tap)
4. [Space Cadet](https://docs.qmk.fm/#/feature_space_cadet)
5. [Jay Liu QMK Cheatsheet](https://jayliu50.github.io/qmk-cheatsheet/)
6. [Thomas Baart QMK Basics](https://thomasbaart.nl/category/mechanical-keyboards/firmware/qmk/qmk-basics/)

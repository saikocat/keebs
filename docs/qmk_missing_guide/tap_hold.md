# Tap-Hold

This function is awesome as it allows you to have at least 2 purposes for modifier and layer based keys (hold-type) and a normal keycode (tap-type). It's especially helpful for small keyboards without many keys. I will just cover the common topics that is applicable for most people. 

I must say the default and example fromn the official QMK document is really good. And this is really a personal thing (depending on switch as well - short key travel and fast actuation switch will require a different settings; tap dance will definitely require a longer tapping term within one's preference).

## Principles

`TAPPING_TERM` is to determine what's a tap and what's a hold behaviour.
- Tapping term short (<100): on multi-purpose keys, slow taps may not register, but "holds" register easier. Multi-tap keys may be difficult to activate. (/u/wanleg)
- Tapping term long (>200): holds don't register as easily - noticeable when typing quickly (e.g. shift doesn't want to engage.) (/u/wanleg)
- Tapping term <1250ms you will notice a visible delay when outputing the tap key, that's why for Space key, the QMK recommended 1250 plus plus is really good as it's same as normal non-multi-purpose spacebar. Also for `LT(2, KC_SPC)`, You can still the desired layer but you have to fully actuate/bottom down the key in that layer while holding down layer key.
- However, for Backspace and MO(1), you want to lower tapping term, as less chance for you to accidental hit backspace as you want to access layer more often. Also since you want to fast access layer, `PERMISSIVE_HOLD` is really good for this use case.
- Understand the above principles, you can set the sweetspot of your tapping term for each of those multi-purpose keys.

## Example 

Hence, my recommended settings for most folks:

```c
/* keymaps/<yours>/config.h */
#define TAPPING_TERM 200

#define TAPPING_TERM_PER_KEY

#define PERMISSIVE_HOLD
```

```c
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    SPC_FN2 = LT(2, KC_SPC),    /* Hold: Layer 2, Tap: Space */
    BSPC_FN1 = LT(1, KC_BSPC),  /* Hold: Layer 1, Tap: Backspace */
};

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case BSPC_FN1:
            return 130;
        case SPC_FN2:
            return TAPPING_TERM + 1250;
        default:
            return TAPPING_TERM;
    }
}
```

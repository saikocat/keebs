# QMK Firmware Customization Missing Guide For Newbie

I'll not regurgitate the setup steps, compile and basic tutorials from official QMK guide.
This is the collection of my experiences when I customized my first firmware while stumbling to find answers.

## Useful CLI Tips

Astute readers can combine all these commands into a single one to automate their workflow.

### Convert QMK Configurator JSON Keymap to C

After you have created your desired keymap and export to JSON from [https://config.qmk.fm/](https://config.qmk.fm/), and you want to quickly generate a keymap in C lang for further customization. You can fire up `QMK_MSYS` or your trusty terminal of choice on non-Windows then follow this grammar:

```bash
$ qmk json2c <path/to/source_keymap>.json -o <path/to/destination_keymap>.c
```

Also qmk will automatically create one backup file if destination keymap c file exists! I suggest a different name for destination keymap (like `autogen_keymap.c`) then later copy the `keymaps` content into your real `keymap.c`

### Auto Replace `KC_TRNS` and `KC_NO` with their aliases

This trick is mainly for readability and nicer keymap ascii art. Basically, we'll run a command to convert all instances of NOOP key and Transparent key to their respective alias `XXXXXXX` and ` _______`.

```bash
$ sed -i 's/KC_TRNS/_______/g; s/KC_NO/XXXXXXX/g' <keymap.json|keymap.c>
```

### Format C Source Files

QMK provides option to format the C source files to their coding standard. Useful if you want to make your sources ready for a PR.

```bash
$ qmk cformat <path/to/sources.c>
```

### Exclude Certain Parts in C files from Being Auto Formatted

But sometimes you want to exclude certain parts from being formatted (for e.g: keymap layout portion).

You can use markers `// clang-format off` then `// clang-format on` like below to exclude the code portion in betweeen:

```c
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
    [_QWERTY] = LAYOUT(
    	...
    )
    // clang-format on
}
```


## Firmware Customization Tips

### Override Defined Once Value in `config.h`

Please exercise cautions and understand each defined once value carefully as they tie to the keyboard specifically (`#prama once`). But sometimes, like this example in Sofle is too personal to the author and might not be usable to your build.

```c
/* Snippet from solfe/rev1/config.h */
#pragma once
...
#define TAPPING_TERM 100
...
#define ENCODER_RESOLUTION 2
...
#define TAP_CODE_DELAY 10
```

Let us change the `ENCODER_RESOLUTION` to 4 in our keymap as 2 causes my build encoder indent/click to register twice. First we check if the value is defined (via `#ifdef` directive) then we undefine it (`#undef`) then define it again.

```c
/* Snippet from keymap/saikocat/config.h */
#ifdef ENCODER_RESOLUTION
    #undef ENCODER_RESOLUTION
    #define ENCODER_RESOLUTION 4
#endif
```

### Using Enum for Layers Numbering
TODO

### Reduce Firmware Size

#### Disable Unused Features
TODO

#### WPM Display Optimization
TODO

### Gems About PROGMEM Keywords
TODO

### Quick Access ADJUST Layer
TODO

### OLED Write Functions Explained
TODO

### Features Modularization
TODO


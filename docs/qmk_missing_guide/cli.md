# CLI Workflow Tips & Tricks

Astute readers can combine all these commands into a single one to automate their workflow.

## Convert QMK Configurator JSON Keymap to C

After you have created your desired keymap and export to JSON from [https://config.qmk.fm/](https://config.qmk.fm/), and you want to quickly generate a keymap in C lang for further customization. You can fire up `QMK_MSYS` or your trusty terminal of choice on non-Windows then follow this grammar:

```bash
$ qmk json2c <path/to/source_keymap>.json -o <path/to/destination_keymap>.c
```

Also qmk will automatically create one backup file if destination keymap c file exists! I suggest a different name for destination keymap (like `autogen_keymap.c`) then later copy the `keymaps` content into your real `keymap.c`

## Auto Replace `KC_TRNS` and `KC_NO` with their aliases

This trick is mainly for readability and nicer keymap ascii art. Basically, we'll run a command to convert all instances of NOOP key and Transparent key to their respective alias `XXXXXXX` and ` _______`.

```bash
$ sed -i 's/KC_TRNS/_______/g; s/KC_NO/XXXXXXX/g' <keymap.json|keymap.c>
```

## Format C Source Files

QMK provides option to format the C source files to their coding standard. Useful if you want to make your sources ready for a PR.

```bash
$ qmk cformat <path/to/sources.c>
```

## Exclude Certain Parts in C files from Being Auto Formatted

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

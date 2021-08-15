# OLED Customization

Everyone can copy and paste, but understanding how thing works is way more important for further customization.

## Sprite Size & Rendering

You want to customize the sprite animation of say [Luna pet](https://www.reddit.com/r/olkb/comments/lmtgxc/introducing_luna_the_qmk_keyboard_pet/), and reading the source code just give you the magic number like below:

```c
/* number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024 */
#define ANIM_SIZE 128           
```

Here I'll explain how allocate the right size from your image rather than plucking number from thin air.

* Monochrome pixel takes 1-bit to display (0 or 1) black or white.
* 1-byte = 8-bits

So a 32px by 32px image will take up `32 * 32 = 1024-bits` which divides by 8 will give you `128-bytes`. Applying the same formula, a `32x24` image will require `96 bytes` size array; and a `32x22` will require `88 bytes`.

All and all, this is just to save you from repeatedly type `sizeof(sprite_name)` and use a constant value when rendering part of animations using `oled_write_raw_P` function.

## Convert Image to Bytes Array

See [this excellent article](https://docs.splitkb.com/hc/en-us/articles/360013811280) by splitkb.

## Font Size & Max Rendering Width (per "physical line")

Most of the time the code you copy from is using the default font [glcdfont.c](https://github.com/qmk/qmk_firmware/blob/master/drivers/oled/glcdfont.c), which is Helidox 8x6 font.

It's a fixed-width font that means all character takes up the same width. In this case, 1 character will take up `6px` on screen.

From my experience, it seems for a 270 degrees rotation of a 128x32 OLED screen, we can display *max 5 characters* with 2px for screen gap (`6px * 5 + 2px = 32px`). That's why you see `QWERT` or `Undef` or `LAYER` or `CPSLK` or words being shortened as 5 characters is maximum you can display for 32px screen.

"Physical Line" was put in quote as it's the "physical" line we see on the display. The program will just print out the values in a continuous manner, advance to the next cursor / pixel (in this case reflow to a new line). It's easier to explain using illustration for this one, subtle so you need to be aware.

```c
/* Output 
-----

 GIT
 
 GUD!

-----
*/
oled_write_P(PSTR("-----\n"), false);
oled_write_P(PSTR(" GIT \n"), false);
oled_write_P(PSTR(" GUD!\n"), false);
oled_write_P(PSTR("-----\n"), false);
oled_write_P(PSTR("\n"), false);
```

```c
/* Output that we want
-----
 GIT
 GUD!
-----
*/
oled_write_P(PSTR("-----"), false);
oled_write_P(PSTR(" GIT "), false);
oled_write_P(PSTR(" GUD!"), false);
oled_write_P(PSTR("-----"), false);
oled_write_P(PSTR("\n"), false);
```

## PROGMEM Keyword

Let me digress a bit and talk about memory in microcontroller:
- **Flash memory** (program space) can be only populated at program runtime. You can't change the value in the flash after the program started running.
- **SRAM** (static random access memory) is where variables are created and manipulated when it runs (think wpm information). Fast but volatile so information will be lost when power is cycled.
- **EEPROM** is memory space that programmers can use to store long-term / persistent information (VIA stores keymap here)

Also note that SRAM storage is way limited compared to Flash memory (say ATMEGA32U4 has 32kb flash vs 2.5kb SRAM). So now you understand the limitations, and hence all the logos and sprites for animations have to use `PROGMEM` keyword in order to fit everything inside. This [answer from stackoverflow](https://arduino.stackexchange.com/a/52611) has more information on the constant space in SRAM allocation with most of the data in PROGMEM optimization.

**Rule of thumbs**: Constant c-strings or char array or large bytes array should be set with this PROGMEM identifier. String literals can be converted using `PSTR(s)` macro, and using `oled_write_P` to print out (the P is for PROGMEM)

**Examples**:

```c
/* logo image is big so we use PROGMEM keyword */
static const char PROGMEM my_logo[] = { 0x00, 0xc0, 0xf0, 0xfe }

/* CPSLK is a constant string, so we use PSTR() to store it in PROGMEM */
oled_write_P(PSTR("CPSLK"), led_usb_state.caps_lock);

/* wpm is constantly changing so we don't use PROGMEM, but the label "wpm" is */
oled_write(wpm_str, false);
oled_write_P(PSTR(" wpm"), false);
```

## WPM Display Optimization

You might have seen this copypasta and very short, sweet, and innoculous piece of code to display WPM:

```c
sprintf(wpm_str, " %03d", current_wpm);
```

However, it's not the most optimized for firmware size function out there, and I've come across this custom formatting code that's more preferred:

```c
uint8_t n = get_current_wpm();
char wpm_str[4];
oled_set_cursor(0, 14);
wpm_str[3] = '\0';
wpm_str[2] = '0' + n % 10;
wpm_str[1] = '0' + (n /= 10) % 10;
wpm_str[0] = '0' + n / 10;
```

`Sprintf` probably includes more instructions than the custom print, which is not very strange as it's more of a general purpose function. 

Even if firmware size is not an issue, try to avoid `sprintf` (I see lots of copy pasta for it) as it has security issues. `snprintf` is preferred as it limits buffer size or these highly recommeneded [safe variants of sprintf](https://docs.microsoft.com/en-us/cpp/c-runtime-library/reference/snprintf-s-snprintf-s-l-snwprintf-s-snwprintf-s-l`).


## Cursor Positioning
TODO

## Animation
TODO

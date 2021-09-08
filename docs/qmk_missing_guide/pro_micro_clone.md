SPLIT_USB_DETECT 

There's not a default option for forcing a side to be master. is_keyboard_master() is weak and can be overridden though https://github.com/qmk/qmk_firmware/blob/master/quantum/split_common/split_util.c#L115
So you could probably have something as simple as

```c
bool is_keyboard_master(void) {
  return true; //flash this to the master side
}
```
 
or

```c
bool is_keyboard_master(void) {
  return false;
}
```

for the slave.
You could use ifdefs to help with that a little.

Dasky#0592


if you do have handedness setup with EE_HANDS/SPLIT_HAND_PIN/SPLIT_HAND_MATRIX_GRID you could probably use

```c
bool is_keyboard_master(void) {
  return is_keyboard_left(); //sets left as master or use !is_keyboard_left() to set right as master.
}
```

Anyway those usb-c promicro do seem to have the diode. So it may work, if it doesn't I'd probably try adding a pulldown resistor to the anode side of the diode.

Could you be using this Pro Micro or an Elite-C version 3 (not 3.1) on the right side? Automatic master/slave detection is done by the microcontroller checking that the VBUS pin is not active. On a correctly functioning Pro Micro there should be a diode from VBUS (USB connector and RAW pin) to Vcc (Vcc pin), so that the VBUS pin is active only when a USB cable is connected. Some Pro Micro clones don't have the diode, and the Elite-C v 3 has a diode that is out of spec: it leaks some current, enough to activate VBUS detection. (this was fixed in Elite-C 3.1)

The other things you should check are the TRRS connectors and the pull-up resistors.

You'd need to look closely at the specs and circuit board to see if there are any differences. Some issues found in clones are:

Wider circuit board that won't fit sockets on keyboard PCBs.

Short between VBUS and Vcc, lacking a Shottky diode needed for split keyboards.

Use of 8 MHz crystal instead of 16 MHz.

https://github.com/qmk/qmk_firmware/issues/8990#issuecomment-912629906
I found that the problem is my pro micros, they could not detect VBUS (which should), VBUS is used to detect master/slave.

https://docs.splitkb.com/hc/en-us/articles/360010588860-Only-one-half-of-my-keyboard-works-at-a-time-but-not-when-they-are-both-connected

https://www.40percent.club/search/label/parts
https://www.40percent.club/2017/09/green-pro-micro.html
https://www.reddit.com/r/ErgoMechKeyboards/comments/ho6y6w/promicros_off_aliexpress_good_idea/fxg6fld/?utm_source=reddit&utm_medium=web2x&context=3

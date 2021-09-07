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

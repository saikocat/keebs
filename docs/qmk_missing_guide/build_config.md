# Per Build Configuration

## Override Defined Once Value in `config.h`

Please exercise cautions and understand each defined once value carefully as they tie to the keyboard specifically (`#prama once`). But sometimes, like this example in Sofle is too personal to the author and might not be usable to your build.

```c
/* Snippet from solfe/rev1/config.h */
#pramga once
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

If you don't do the check then redefine and just set define directive again, you'll get an error (warning as error) when compiling your keymap.

/* Function: Neko Pet Animation
 * ----------------------------
 * - Keyboard Pets react to your wpm counter:
 *    under 10 wpm they sit
 *    between 10 and 50 wpm they will walk
 *    over 50 wpm they run
 * - They will move sneakily if you hold down Ctrl
 * - Will react if you activate Caps Lock!
 * - TODO: Jump every time you hit the space bar
 *
 * Immense thanks to
 * - /u/HellSingCoder existing implementation of Luna
 * - /u/whateverworks325 for sprites and idea.
 * - b0rv3g4r4/Kyria-Mario-Keymap
 * - f/sofle-mario
 *
 * - Generalize animation naming
 * - Fix flickering on my OLED when oled's off interfere with animations
 */

#include "keystats.h"

/* WPM-responsive animation settings here */
#define MIN_WALK_SPEED 10
#define MIN_RUN_SPEED 50

/* Animation settings */
#define ANIM_FRAME_DURATION 200 /* how long each frame lasts in ms */
#define ANIM_SIZE 128           /* number of bytes in array. If you change sprites, minimize for adequate firmware size. max is 1024 */
#define ANIM_FRAMES 2

/* timers */
uint32_t pet_anim_timer;
uint32_t pet_anim_sleep;

/* current frame */
uint8_t pet_current_frame;

/* status variables */
bool pet_is_sneaking;
/* TODO: jump is causing artifact
bool is_jumping = false;
bool showed_jump = true;
*/

/* logic */
void pet_render(int PET_X, int PET_Y);

/* handle various keycode to respective state */
void pet_handle_keycode(uint16_t keycode, keyrecord_t *record);

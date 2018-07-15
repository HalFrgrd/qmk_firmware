// // this is the style you want to emulate.
// // This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include "mitosis.h"
// 
// 
// 
// // Fillers to make layering more clear
// #define _______ KC_TRNS
// #define XXXXXXX KC_NO
// 
// const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
// [0] = {
//   {KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,       KC_Y,    KC_U,    KC_I,    KC_O,    KC_P   },
//   {KC_A,    KC_S,    KC_D,    KC_F,    KC_G,       KC_H,    KC_J,    KC_K,    KC_L,    KC_COLON   },
//   {KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,       KC_N,    KC_M,    KC_COMM, KC_DOT,    KC_SLASH  },
//   {XXXXXXX, KC_1,    KC_2,    KC_3,    KC_4,       KC_5,    KC_6,    KC_8,    KC_9,     XXXXXXX}
// }
// 
// 
// 
// 
// };


enum custom_keycodes {
  QWERTY = 0,
  //ALTTHERN = 0,
  NAVIG,
  NUMBERS,
  FUNC,
  SYMB,
  BLANCK
};

enum {
   DB_SQ_BRACK = 10,
   DB_PR_BRACK,
   DB_CR_BRACK,
   DB_COLON,
   DB_QUOT,
   DB_UNDS
   
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |  Ent |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   Z  |   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *           ,---------------------------.    ,---------------------------.
 *    Tap:   | Esc  | L_GUI|Space | Tab  |    | Enter|BckSpc|      |      |
 *    Hold:  | Ctrl |LShft |Numbs |Navig |    |Symbol| Func |RShft |      |
 *           `---------------------------'    `---------------------------'
 */
 
[QWERTY] = KEYMAP( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT , \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  XXXXXXX, MT(KC_LCTL,KC_ESC), MT(MOD_LSFT, KC_LGUI), LT(NUMBERS,KC_SPC), LT(NAVIG,KC_TAB), LT(SYMB,KC_ENT), LT(FUNC,KC_BSPC), OSM(MOD_RSFT), XXXXXXX , XXXXXXX      \
), 

/* ALTTHERN
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   ,  |   C  |   D  |   F  |   Y  |           |   V  |   H  |   T  |   L  |   .  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |   S  |   E  |   R  |   K  |           |BckSpc|   N  |   I  |   O  |  Ent |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   X  |   W  |   G  |   B  |   J  |           |   Z  |   M  |   U  |   P  |   Q  |
 * `----------------------------------'           `----------------------------------'
 *           ,---------------------------.    ,---------------------------.
 *    Tap:   | Esc  | L_GUI|Space | Tab  |    |      |      |      |      |
 *    Hold:  | Ctrl |LShft |Numbs |Navig |    |Symbol| RShft| Func |      |
 *           `---------------------------'    `---------------------------'
 */
  
 
 /**
[ALTTHERN] = KEYMAP( \
  KC_COMM, KC_C,    KC_D,    KC_F,    KC_Y,         KC_V,    KC_H,    KC_T,    KC_L,    KC_DOT,    \
  KC_A,    KC_S,    KC_E,    KC_R,    KC_K,         KC_BSPC, KC_K,    KC_I,    KC_O,    KC_ENT , \
  KC_X,    KC_W,    KC_G,    KC_B,    KC_J,         KC_Z,    KC_M,    KC_U,    KC_P,    KC_Q, \
  XXXXXXX, MT(KC_LCTL,KC_ESC), MT(MOD_LSFT, KC_LGUI), LT(NUMBERS,KC_SPC), LT(NAVIG,KC_TAB), MO(SYMB), KC_RSFT, MO(FUNC), XXXXXXX , XXXXXXX  \
),
**/

/* Navigation
*
* ,----------------------------------.           ,----------------------------------.
* | Esc  |C W   | C L  |  Esc | C T  |           | CtrY | pgUp |  Up  | pgDwn|      |
* |------+------+------+------+------|           |------+------+------+------+------|
* | CSTb | CTb  |ATb   | Ctrl | Shft |           |ScrlUp| Left | Down | Right| Enter|
* |------+------+------+------+------|           |------+------+------+------+------|
* |  Undo|  Cut | Copy |Paste |SelAll|           |ScrDwn|  Home|  Del | End  |CtShfT|
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    |Ctrl- |Ctrl+ |Ctrl0 |      |
*            |      |      |      | Navig|    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/
[NAVIG] = KEYMAP( \
   KC_ESC , LCTL(KC_W), LCTL(KC_L), KC_ESC, LCTL(KC_T) ,      LCTL(KC_Y), KC_PGUP, KC_UP  , KC_PGDN, XXXXXXX , \
   LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), LALT(KC_TAB), KC_LCTL, KC_LSHIFT ,      KC_MS_WH_UP, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , \
   LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_A),      KC_MS_WH_DOWN, KC_HOME, KC_DEL ,  KC_END, LSFT(LCTL(KC_T)),  \
   XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, _______,      LCTL(KC_MINS), LCTL(KC_PLUS), LCTL(KC_0)   , XXXXXXX , XXXXXXX           \
),

/* Numbers
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |   +  |   7  |   8  |   9  |  -   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  !   |  e   |Space | DEL  |           | BS   |   4  |   5  |   6  |ENTER |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  (   |   )  |  %   |   <  |  >   |           |   *  |   1  |  2   |  3   |  /   |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      | Numbs|      |    |      |      |      |      |
 *            |      |      |      |      |    |  ^   |  =   |   0  |  .   |
 *            `---------------------------'    `---------------------------'
 */
[NUMBERS] = KEYMAP( \
   XXXXXXX, XXXXXXX, KC_QUES, XXXXXXX, XXXXXXX,      KC_PLUS, KC_7   , KC_8   , KC_9   , KC_MINS, \
   XXXXXXX, KC_EXLM, KC_E,    KC_SPC , KC_DEL ,      KC_BSPC, KC_4   , KC_5   , KC_6   , KC_ENT , \
   KC_LPRN, KC_RPRN, KC_PERC, KC_LABK, KC_RABK,      KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH, \
   XXXXXXX, XXXXXXX, XXXXXXX, _______, XXXXXXX,      KC_CIRC, KC_EQL,  KC_0   , KC_DOT , XXXXXXX  \
 ),

/* Function
 *
 * ,----------------------------------.           ,----------------------------------.
 * |NLock |      |      |      | VolUp|           |      |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      | Caps |VolDWn|           |  Ins |  F4  |  F5  |  F6  | F11  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |ScrSht| Mute |           |      |  F1  |  F2  |  F3  | F12  |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      | Reset|      |      |    |      |      |      |      |
 *            |      |      |      |      |    |      |      | Func |      |
 *            `---------------------------'    `---------------------------'
 */
[FUNC] = KEYMAP( \
   KC_LNUM, XXXXXXX, XXXXXXX, XXXXXXX, KC__VOLUP,    XXXXXXX, KC_F7   , KC_F8   , KC_F9   , KC_F10, \
   XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, KC__VOLDOWN,  KC_INS , KC_F4   , KC_F5   , KC_F6   , KC_F11, \
   XXXXXXX, XXXXXXX, XXXXXXX, KC_PSCR, KC_MUTE,      XXXXXXX, KC_F1   , KC_F2   , KC_F3   , KC_F12, \
   XXXXXXX, XXXXXXX, RESET  , XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, _______,   XXXXXXX , XXXXXXX  \
),

/* Symbol
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  @   |  #   |  $   |  %   |           |  ^   |  &   |   *  | +    |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  !   |      |      |      |      |           |      |[ DB ]|{ DB }|( DB )|; DB :|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  \   |  |   |  ~   |      |           |      |' DB "|- DB _|  /   |  ?   |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |Symbol|      |      |      |
 *            `---------------------------'    `---------------------------'
 */
[SYMB] = KEYMAP( \
   XXXXXXX, KC_AT  , KC_HASH, KC_DLR , KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, XXXXXXX, \
   KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, TD(DB_SQ_BRACK), TD(DB_CR_BRACK), TD(DB_PR_BRACK), TD(DB_COLON), \
   XXXXXXX, KC_BSLS, KC_PIPE, KC_TILD, XXXXXXX,      XXXXXXX, TD(DB_QUOT), TD(DB_UNDS), KC_SLSH, KC_QUES, \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            \
),

/* Blank
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |      |      |           |      |      |      |      |      |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |      |      |      |      |
 *            `---------------------------'    `---------------------------'
 */
[BLANCK] = KEYMAP( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX  \
)

};



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
          if (record->event.pressed) {
            register_code(KC_RSFT);
          } else {
            unregister_code(KC_RSFT);
          }
        break;
      }
    return MACRO_NONE;
};


qk_tap_dance_action_t tap_dance_actions[] = {
   [DB_SQ_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_RBRC),
   [DB_CR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
   [DB_PR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN,KC_RPRN),
   [DB_QUOT]     = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_DQUO),
   [DB_UNDS]     = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_UNDS),
   [DB_COLON]    = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON,KC_COLN)
};

void matrix_init_user(void) {

}


void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {

}


#include "mitosis.h"


enum {
  QWERTY = 0,
  //ALTTHERN = 0,
  NAVIG,
  NUMBERS,
  FUNC,
  SYMB,
  BLANCK,
};

enum {
    KCNAVIG = SAFE_RANGE
};

enum {
   DB_SQ_BRACK = 10,
   DB_PR_BRACK,
   DB_CR_BRACK,
   DB_COLON,
   DB_QUOT,
   DB_UNDS,
   MALTTAB,
   MALTSTAB,
   MESCNOMODS
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))



//changes: brightness keys, putting all symbols on one layer for programming


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {








/* Qwerty
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |   A  |  S   |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |Shft/Ent|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Ctl /Z|  X   |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |   /  |
 * `----------------------------------'           `----------------------------------'
 *           ,---------------------------.    ,---------------------------.
 *    Tap:   |GUI   |      |Space |      |    |      |BckSpc|      |      |
 *    Hold:  |      |      |Numbs |Navig |    |Symbol|      |      | Func |
 *           `---------------------------'    `---------------------------'
 */

[QWERTY] = KEYMAP( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_ENT) , \
  CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  XXXXXXX, KC_LGUI, XXXXXXX, LT(NUMBERS,KC_SPC), KCNAVIG, MO(SYMB), KC_BSPC, XXXXXXX, MO(FUNC) , XXXXXXX      \
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
* | Esc  |C W   |      |      |CtShfT|           |Ctrl0 | pgUp |  Up  | pgDwn|Alt+F4|
* |------+------+------+------+------|           |------+------+------+------+------|
* | Ctrl |CltTb |AltTab| Shft | Tab  |           |ScrUp | Left | Down | Right| Enter|
* |------+------+------+------+------|           |------+------+------+------+------|
* | Ctrl | Undo |      |      | GUI  |           |ScrDwn| Home |      | End  |      |
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    | Del  |BckSpc|      |      |
*            |      |      |      | Navig|    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/
[NAVIG] = KEYMAP( \
   KC_ESC , LCTL(KC_W), XXXXXXX, XXXXXXX, LSFT(LCTL(KC_T)) ,     LCTL(KC_0) , KC_PGUP, KC_UP  , KC_PGDN, LALT(KC_F4) , \
   KC_LCTL, LCTL(KC_TAB), M(MALTTAB), KC_LSHIFT, KC_TAB ,      KC_MS_WH_UP, KC_LEFT, KC_DOWN, KC_RGHT, _______ , \
   KC_LCTL, LCTL(KC_Z), XXXXXXX, XXXXXXX, KC_LGUI,       KC_MS_WH_DOWN, KC_HOME, XXXXXXX ,  KC_END, XXXXXXX,  \
   XXXXXXX,  _______, _______, _______, _______,      KC_DEL, KC_BSPC , _______,_______, XXXXXXX          \
),

/* Number
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  a   |  b   |  $   |   %  |           |   +  |   7  |   8  |   9  |  -   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  !   |  y   |  e   |  =   |  .   |           |   0  |   4  |   5  |   6  |ENTER |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  z   |  x   | Space| Left |Right |           |   *  |   1  |   2  |   3  |  /   |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    | BckSpc|del  | (    |  )   |
 *            |      |      | Numbs|      |    |      |      |      |      |
 *            `---------------------------'    `---------------------------'
 */

 /*
[NUMBERS] = KEYMAP( \
   XXXXXXX, KC_A   , KC_B   , KC_DLR , KC_PERC,      KC_PLUS, KC_7   , KC_8   , KC_9   , KC_MINS, \
   KC_EXLM, KC_Y,    KC_E,    KC_EQL , KC_DOT ,      KC_0   , KC_4   , KC_5   , KC_6   , KC_ENT , \
   KC_Z,    KC_X,    KC_SPC,  KC_LEFT, KC_RIGHT,      KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH, \
   XXXXXXX, _______, _______, _______, _______,       KC_BSPC, KC_DEL,  KC_LPRN, KC_RPRN, XXXXXXX  \
 ), */


/* Function
 *
 * ,----------------------------------.           ,----------------------------------.
 * |NLock |      |      |      | VolUp|           |      |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CALTDEL|TSKMGR|     | Caps |VolDWn|           |  Ins |  F4  |  F5  |  F6  | F11  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |ScrSht| Mute |           |      |  F1  |  F2  |  F3  | F12  |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |Reset |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |      |      | Func |      |
 *            `---------------------------'    `---------------------------'
 */

 /* Function ThinkPad-like
 *
 * ,----------------------------------.           ,----------------------------------.
 * | Caps | Mute |VolDwn| VolUp|      |           |      |      |  F11  | F12 |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * | F1   |  F2  |  F3  | F4   |  F5  |           | F6   |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |CALTDEL|TSKMGR|     |      |      |           |      |ScrSht|      |      |      |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |Reset |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |      |      | Func |      |
 *            `---------------------------'    `---------------------------'
 */
[FUNC] = KEYMAP( \
   KC_CAPS, KC_MUTE, KC__VOLDOWN, KC__VOLUP, XXXXXXX,XXXXXXX,XXXXXXX , KC_F11 , KC_F12  , XXXXXXX, \
   KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  ,     KC_F6  , KC_F7   , KC_F8  , KC_F9   , KC_F10, \
   CALTDEL, TSKMGR , XXXXXXX, XXXXXXX, XXXXXXX,     XXXXXXX, KC_PSCR , XXXXXXX, XXXXXXX , XXXXXXX, \
   XXXXXXX, RESET  , _______, _______, _______,     _______, _______ , _______, _______ , XXXXXXX  \
),

/* Symbol
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  @   |  #   |  $   |  %   |           |  ^   |  &   |   *  | +    |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  !   |  [   |  (   |  {   |  <   |           |  ¬   |  ;   |   -  |   '  |  :   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  \   |  ]   |  )   |  }   |  >   |           |  |   |  `   |   _  |   "  |  ?   |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |Symbol|      |      |      |
 *            `---------------------------'    `---------------------------'
 */
[SYMB] = KEYMAP( \
   XXXXXXX, KC_AT  , KC_HASH, KC_DLR , KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, XXXXXXX, \
   KC_EXLM, KC_LBRC, KC_LPRN, KC_LCBR, KC_LABK,      KC_TILD, KC_SCLN, KC_MINS, KC_QUOT, KC_COLN, \
   KC_BSLS, KC_RBRC, KC_RPRN, KC_RCBR, KC_RABK,      KC_PIPE, KC_GRV , KC_UNDS, KC_DQUO, KC_QUES, \
   XXXXXXX, _______, _______, _______, _______,      _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            \
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
),

/* QwertyKindaELY
 *
 * ,----------------------------------.           ,----------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |           |   Y  |   U  |   I  |   O  |   P  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Shift/a| S   |   D  |   F  |   G  |           |   H  |   J  |   K  |   L  |  Ent  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |Ctl /Z|   X  |   C  |   V  |   B  |           |   N  |   M  |   ,  |   .  |Func wiht ctrl z |
 * `----------------------------------'           `----------------------------------'
 *           ,---------------------------.    ,---------------------------.
 *    Tap:   |      |      |Space |      |    |      |BckSpc|     |      |
 *    Hold:  |      |      |LOWER |      |    |      |Raise |     |      |
 *           `---------------------------'    `---------------------------'
 */
 /* Func
  *
  * ,----------------------------------.           ,----------------------------------.
  * |      |      |      |      |      |           |      |      |      |      |      |
  * |------+------+------+------+------|           |------+------+------+------+------|
  * |      |      |      |      |      |           |      |      |      |      |      |
  * |------+------+------+------+------|           |------+------+------+------+------|
  * |      |      |      |      |      |           |      |      |      |      | func |
  * `----------------------------------'           `----------------------------------'
  *            ,---------------------------.    ,---------------------------.
  *            |      |      |      |      |    |      |BckSpc|      |      |
  *            |      |      |      |      |    |      |      |      |      |
  *            `---------------------------'    `---------------------------'
  */


/* Lower
*
* ,----------------------------------.           ,----------------------------------.
* |      |  -   |   +  |  =   |   %  |           |      |      |  *   |   /  |      |
* |------+------+------+------+------|           |------+------+------+------+------|
* |   1  |  2   |  3   |  4   |  5   |           |   6  |  7   |  8   |  9   |  0   |
* |------+------+------+------+------|           |------+------+------+------+------|
* | Ctrl | [DB] | (DB) | {DB} |      |           |      |      |  ,   |  .   |  /   |
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    | Del  | BckSpc|     |      |
*            |      |      | Lower|      |    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/

[NUMBERS] = KEYMAP( \
  XXXXXXX, KC_MINS, KC_PLUS, KC_EQL , KC_PERC,      XXXXXXX, XXXXXXX, KC_ASTR, KC_SLSH, XXXXXXX, \
  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , \
  KC_LCTL, TD(DB_SQ_BRACK), DB_PR_BRACK, DB_SQ_BRACK, XXXXXXX,      XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_SLSH, \
  XXXXXXX, _______, XXXXXXX, _______, _______,      KC_DEL, KC_BSPC, XXXXXXX, _______, XXXXXXX  \
)


};



qk_tap_dance_action_t tap_dance_actions[] = {
   [DB_SQ_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_RBRC),
   [DB_CR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
   [DB_PR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN,KC_RPRN),
//    [DB_QUOT]     = ACTION_TAP_DANCE_DOUBLE(KC_QUOT,KC_DQUO),
//    [DB_UNDS]     = ACTION_TAP_DANCE_DOUBLE(KC_MINS,KC_UNDS),
//    [DB_COLON]    = ACTION_TAP_DANCE_DOUBLE(KC_SCOLON,KC_COLN)
};

void matrix_init_user(void) {

}


void matrix_scan_user(void) {

}


void led_set_user(uint8_t usb_led) {

}

// Macro Definitions
const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    if (record->event.pressed) {
      switch(id) {

        // case NAVIG2MACRO: {
        //     if (record->event.pressed) {
        //         register_mods(MOD_BIT(KC_LALT));
        //         layer_on(NAVIG2);
        //         return false;
        //     } else {
        //         unregister_mods(MOD_BIT(KC_LALT));
        //         layer_off(NAVIG2);
        //         return false;
        //     }
        // }

        case MESCNOMODS: {
          clear_mods();
          return MACRO(T(ESC));
        }

        case MALTTAB: {
            return MACRO(D(LALT), T(TAB), END);

        }

        case MALTSTAB: {

                 return MACRO(D(LALT), D(LSFT), T(TAB), U(LSFT), END);
            }
        }

      }
      return MACRO_NONE;
};


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KCNAVIG:
            if (record->event.pressed) {
              layer_on(NAVIG);
            } else {
              layer_off(NAVIG);
              SEND_STRING(SS_LALT(""));
            }
            return false;
            break;
    // case QWERTY:
    //   if (record->event.pressed) {
    //     persistant_default_layer_set(1UL<<_QWERTY);
    //   }
    //   return false;
    //   break;
    // case KEYNAVIG:
    //   if (record->event.pressed) {
    //     layer_on(NAVIG);
    //     update_tri_layer(NAVIG, SYMB, FUNC);
    //   } else {
    //     layer_off(NAVIG);
    //     update_tri_layer(NAVIG, SYMB, FUNC);
    //   }
    //   return false;
    //   break;
    // case KEYSYMB:
    //   if (record->event.pressed) {
    //     layer_on(SYMB);
    //     update_tri_layer(NAVIG, SYMB, FUNC);
    //   } else {
    //     layer_off(SYMB);
    //     update_tri_layer(NAVIG, SYMB, FUNC);
    //   }
    //   return false;
    //   break;
    // case KEYADJUST:
    //   if (record->event.pressed) {
    //     layer_on(FUNC);
    //   } else {
    //     layer_off(FUNC);
    //   }
    //   return false;
    //   break;
  }
  return true;
}

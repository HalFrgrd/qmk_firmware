#include "mitosis.h"
#include "print.h"
#include <print.h>
#include "debug.h"

enum {
/* Copyright 2017 REPLACE_WITH_YOUR_NAME
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "porkchop.h"


enum custom_keycodes {
  QWERTY = 0,
  NAVIG,
  NUMBERS,
  FUNC,
  SYMB,
  BLANCK,
};


enum {
   DB_SQ_BRACK = 10,
   DB_PR_BRACK,
   DB_CR_BRACK,
   DB_COLON,
   DB_QUOT,
   DB_UNDS,


};

enum {
   ALT_TAB = SAFE_RANGE,
   SFT_ALT_TAB,
   MNAVIG
};

#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Defines for task manager and such
#define CALTDEL LCTL(LALT(KC_DEL))
#define TSKMGR LCTL(LSFT(KC_ESC))




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
 *    Tap:   |      |GUI   |Space | Tab  |    | Del  |BckSpc|      |      |
 *    Hold:  |      |      |Numbs |Navig |    |Symbol|      | Func |      |
 *           `---------------------------'    `---------------------------'
 */

[QWERTY] = KEYMAP( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_ENT) , \
  CTL_T(KC_Z),    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
  XXXXXXX, XXXXXXX, KC_LGUI, LT(NUMBERS,KC_SPC), MNAVIG, LT(SYMB,KC_DEL), KC_BSPC , MO(FUNC) , MO(FUNC), XXXXXXX      \
),

/* Navigation
*
* ,----------------------------------.           ,----------------------------------.
* | Esc  |C W   |      |      |CtShfT|           |Ctrl0 | pgUp |  Up  | pgDwn|Alt+F4|
* |------+------+------+------+------|           |------+------+------+------+------|
* | CSTb |CTb   |ASTab | AlTb | Tab  |           |ScrUp | Left | Down | Right| Enter|
* |------+------+------+------+------|           |------+------+------+------+------|
* | Ctrl | Undo |      |      | GUI  |           |ScrDwn| Home |      | End  |      |
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    | Del  |BckSpc|      |      |
*            |      |      |      | Navig|    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/

[NAVIG] = KEYMAP( \
  KC_ESC ,         LCTL(KC_W),   XXXXXXX, XXXXXXX, LSFT(LCTL(KC_T)) ,     LCTL(KC_0) ,   KC_PGUP, KC_UP  ,   KC_PGDN, LALT(KC_F4) , \
  LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), SFT_ALT_TAB, ALT_TAB, KC_TAB ,               KC_MS_WH_UP,   KC_LEFT, KC_DOWN,   KC_RGHT, _______ , \
  KC_LCTL,         LCTL(KC_Z),   XXXXXXX, XXXXXXX, KC_LGUI,               KC_MS_WH_DOWN, KC_HOME, XXXXXXX ,  KC_END,  XXXXXXX,  \
  XXXXXXX,          _______,     _______, _______, _______,               KC_DEL,        KC_BSPC,  _______,  _______, XXXXXXX          \
),



/* Numbers
*
* ,----------------------------------.           ,----------------------------------.
* |      |  -   |   +  |  =   |   %  |           |      |      |  *   |   /  |      |
* |------+------+------+------+------|           |------+------+------+------+------|
* |   1  |  2   |  3   |  4   |  5   |           |   6  |  7   |  8   |  9   |  0   |
* |------+------+------+------+------|           |------+------+------+------+------|
* | Ctrl | [DB] | (DB) | {DB} |      |           |      |      |  ,   |  .   |  /   |
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    | Del  |BckSpc|      |      |
*            |      |      |      |      |    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/

[NUMBERS] = KEYMAP( \
  XXXXXXX, KC_MINS, KC_PLUS, KC_EQL , KC_PERC,      XXXXXXX, XXXXXXX, KC_ASTR, KC_SLSH, XXXXXXX, \
  KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,      KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , \
  KC_LCTL, TD(DB_SQ_BRACK), TD(DB_PR_BRACK), TD(DB_SQ_BRACK), XXXXXXX,      XXXXXXX, XXXXXXX, KC_COMM, KC_DOT , KC_SLSH, \
  XXXXXXX, _______, XXXXXXX, _______, _______,      KC_DEL, KC_BSPC, XXXXXXX, _______, XXXXXXX  \
),

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
)


};



qk_tap_dance_action_t tap_dance_actions[] = {
   [DB_SQ_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC,KC_RBRC),
   [DB_CR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
   [DB_PR_BRACK] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN,KC_RPRN),
};

void matrix_init_user(void) {

}



bool is_alt_tab_active = false;
uint16_t mnavig_timer;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Use one button in the navig layer for alt tab. When you let go of navig key, alt is also released
    case ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) { //First time we press it
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_TAB);
      } else { // on key up
        unregister_code(KC_TAB);
      }
      break;

    case SFT_ALT_TAB:
      if (record->event.pressed) {
        if (!is_alt_tab_active) { //First time we press it
          is_alt_tab_active = true;
          register_code(KC_LALT);
        }
        register_code(KC_LSFT);
        register_code(KC_TAB);
      } else { // on key up
        unregister_code(KC_TAB);
        unregister_code(KC_LSFT);
      }
      break;

    case MNAVIG: //deals with navigation layer, clear alttab, and presses tab if only pressed for a bit.
      if(record->event.pressed){
        mnavig_timer = timer_read();
        layer_on(NAVIG);
      }else{
        layer_off(NAVIG);
        is_alt_tab_active = false;
        clear_mods();
        if(timer_elapsed(mnavig_timer) < TAPPING_TERM){
          tap_code(KC_TAB);
        }
      }
  }
  return true;
};

layer_state_t layer_state_set_user(layer_state_t state) {
  clear_mods();
  return state;
}

void matrix_scan_user(void) {

}

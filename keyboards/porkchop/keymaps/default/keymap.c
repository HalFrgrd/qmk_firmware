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
[QWERTY] = LAYOUT( \
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,         KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    \
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,         KC_H,    KC_J,    KC_K,    KC_L,    KC_ENT , \
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,         KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, \
           MT(KC_LCTL,KC_ESC), MT(MOD_LSFT, KC_LGUI), LT(NUMBERS,KC_SPC), LT(NAVIG,KC_TAB), LT(SYMB,KC_ENT), LT(FUNC,KC_BSPC), OSM(MOD_RSFT), XXXXXXX                 \
),

/* Navigation
*
* ,----------------------------------.           ,----------------------------------.
* | Esc  |C W   | C L  |  Esc | C T  |           | CtrY | pgUp |  Up  | pgDwn| End  |
* |------+------+------+------+------|           |------+------+------+------+------|
* | CSTb | CTb  |ATb   | Ctrl | Shft |           |ScrlUp| Left | Down | Right| Enter|
* |------+------+------+------+------|           |------+------+------+------+------|
* |  Undo|  Cut | Copy |Paste |SelAll|           |ScrDwn|  Home|  Del |BckSpc|CtShfT|
* `----------------------------------'           `----------------------------------'
*            ,---------------------------.    ,---------------------------.
*            |      |      |      |      |    |Ctrl- |Ctrl+ |Ctrl0 |      |
*            |      |      |      | Navig|    |      |      |      |      |
*            `---------------------------'    `---------------------------'
*/
[NAVIG] = LAYOUT( \
   KC_ESC , LCTL(KC_W), LCTL(KC_L), KC_ESC, LCTL(KC_T) ,      LCTL(KC_Y), KC_PGUP, KC_UP  , KC_PGDN, KC_END, \
   LSFT(LCTL(KC_TAB)), LCTL(KC_TAB), LALT(KC_TAB), KC_LCTL, KC_LSHIFT ,      KC_MS_WH_UP, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , \
   LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_A),      KC_MS_WH_DOWN, KC_HOME, KC_DEL , KC_BSPC , LSFT(LCTL(KC_T)), \
            XXXXXXX, XXXXXXX, XXXXXXX, _______,      LCTL(KC_MINS), LCTL(KC_PLUS), LCTL(KC_0)   , XXXXXXX            \
),

/* Numbers
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |      |      |      |      |           |   +  |   7  |   8  |   9  |  -   |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  !   |      |      | DEL  |           | BS   |   4  |   5  |   6  |ENTER |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  (   |   )  |  %   |   <  |  >   |           |   *  |   1  |  2   |  3   |  /   |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    |  ^   |  =   |   0  |  .   |
 *            |      |      | Numbs|      |    |      |      |      |      |
 *            `---------------------------'    `---------------------------'
 */
[NUMBERS] = LAYOUT( \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      KC_PLUS, KC_7   , KC_8   , KC_9   , KC_MINS, \
   XXXXXXX, KC_EXLM, XXXXXXX, XXXXXXX, KC_DEL ,      KC_BSPC, KC_4   , KC_5   , KC_6   , KC_ENT , \
   KC_LPRN, KC_RPRN, KC_PERC, KC_LABK, KC_RABK,      KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH, \
            XXXXXXX, XXXXXXX, _______, KC_CIRC,      KC_EQL, KC_0, KC_DOT, XXXXXXX            \
 ),

/* Function
 *
 * ,----------------------------------.           ,----------------------------------.
 * |NLock |      | Caps |      | VolUp|           |      |  F7  |  F8  |  F9  | F10  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  Win | Ctrl | Shift|  Alt | Mute |           |  Ins |  F4  |  F5  |  F6  | F11  |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |      |      |ScrSht|VolDWn|           |      |  F1  |  F2  |  F3  | F12  |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      | Reset|      |      |    |      |      |      |      |
 *            |      |      |      |      |    |      |Func  |      |      |
 *            `---------------------------'    `---------------------------'
 */
[FUNC] = LAYOUT( \
   KC_LNUM, XXXXXXX, KC_CAPS, XXXXXXX, KC__VOLUP,    XXXXXXX, KC_F7   , KC_F8   , KC_F9   , KC_F10, \
   KC_LGUI, KC_LCTL, KC_LSFT, KC_LALT, KC_MUTE,      KC_INS , KC_F4   , KC_F5   , KC_F6   , KC_F11 , \
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC__VOLDOWN,  XXXXXXX, KC_F1   , KC_F2   , KC_F3   , KC_F12, \
            XXXXXXX, RESET  , XXXXXXX, XXXXXXX,      XXXXXXX, _______, XXXXXXX, XXXXXXX            \
),

/* Symbol
 *
 * ,----------------------------------.           ,----------------------------------.
 * |      |  @   |  #   |  $   |  %   |           |  ^   |  &   |   *  | +    |      |
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |  !   |      |      |      |      |           |      |[ DB ]|{ DB }|( DB )|; DB :|
 * |------+------+------+------+------|           |------+------+------+------+------|
 * |      |  \   |  |   |  ~   |      |           |      |' DB "|- DB _|      |      |
 * `----------------------------------'           `----------------------------------'
 *            ,---------------------------.    ,---------------------------.
 *            |      |      |      |      |    |      |      |      |      |
 *            |      |      |      |      |    |Symbol|      |      |      |
 *            `---------------------------'    `---------------------------'
 */
[SYMB] = LAYOUT( \
   XXXXXXX, KC_AT  , KC_HASH, KC_DLR , KC_PERC,      KC_CIRC, KC_AMPR, KC_ASTR, KC_PLUS, XXXXXXX, \
   KC_EXLM, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, TD(DB_SQ_BRACK), TD(DB_CR_BRACK), TD(DB_PR_BRACK), TD(DB_COLON), \
   XXXXXXX, KC_BSLS, KC_PIPE, KC_TILD, XXXXXXX,      XXXXXXX, TD(DB_QUOT), TD(DB_UNDS), XXXXXXX, XXXXXXX, \
            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      _______, XXXXXXX, XXXXXXX, XXXXXXX            \
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
[BLANCK] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
           XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX            \
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

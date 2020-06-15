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
#include "hf40.h"
#include "mousekey.h"


#define BASE 0
#define SPAC 1
#define CAPL 2
#define NAVI 3
#define ALTB 7
#define SATB 8
#define COMM 9


#define _______ KC_TRNS
#define XXXXXXX KC_NO

#define SPECD LT(ALTB, KC_D) // special functin of d. if hold d and tap f = alt tab
#define SPECF LT(SATB, KC_F) // special functin of f. if hold f and tap d = shift alt tab
#define SPECK LT(COMM, KC_K) // special functin of k. if hold k and tap j = esc

#define TAPPING_TOGGLE 1 

#define MUL   20 // mouse up left
#define MUR   21 // mouse up right
#define MDL   22 // mouse down left
#define MDR   23 // mouse down right

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE LAYER
   * ,------------------------------------------             ------------------------------------------,
   * | tab  |   q  |    w |    e |   r  |   t  |             |   y  |   u  |    i |   o  |  p   | del  |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * | cpslk|   a  |    s |specd |specf |   g  |             |   h  |   j  |SpecK |   l  |  ;   | enter|
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |lshift|   z  |    x |    c |   v  |   b  |             |   n  |   m  |    , |   .  |  /   |rshift|
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * | ctrl |  gui | fn1  |  alt |  spc | spc  |lshift| enter|bckspc| NAV  | up   |  down| left | right|
   * `-------------------------------------------------------------------------------------------------'
  */

    [BASE] = KEYMAP( 
    KC_TAB       , KC_Q   , KC_W   , KC_E   , KC_R    , KC_T        ,                       KC_Y    , KC_U    , KC_I    , KC_O    , KC_P   , KC_DEL , \
  LT(2,KC_CAPS)  , KC_A   , KC_S   , SPECD  , SPECF   , KC_G        ,                       KC_H    , KC_J    , SPECK   , KC_L    , KC_SCLN, KC_ENT , \
    KC_LSPO      , KC_Z   , KC_X   , KC_C   , KC_V    , KC_B        ,                       KC_N    , KC_M    , KC_COMMA, KC_DOT  , KC_SLSH, KC_RSPC, \
    KC_LCTL      , KC_LGUI, XXXXXXX, KC_LALT, XXXXXXX , LT(1,KC_SPC), KC_LSPO,LT(1,KC_ENT), KC_BSPC , TT(NAVI), KC_UP   , KC_DOWN , KC_LEFT, KC_RIGHT \
  ),


  /* SPACE OR ENTER LAYER
   * ,------------------------------------------             ------------------------------------------,
   * |   ~  |   !  |   @  |   #  |   $  |   %  |             |   ^  |   &  |   *  |  (   |  )   |  -   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |   `  |   1  |    2 |    3 |   4  |   5  |             |   6  |   7  |   8  |  9   |  0   |  +   |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |   |  |   *  |   +  |   _  |             |   -  |  =   |  /   |      |      |      |
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |  del |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
  */

    [SPAC] = KEYMAP(
    KC_TILD, KC_EXLM, KC_AT  , KC_HASH, KC_DLR, KC_DLR   ,                  KC_CIRC, KC_AMPR, KC_ASTR   , KC_LPRN , KC_RPRN, KC_MINS, \
   KC_GRAVE, KC_1   , KC_2   , KC_3   , KC_4   , KC_5    ,                  KC_6   , KC_7   , KC_8      , KC_9    , KC_0,    KC_PLUS, \
    XXXXXXX, XXXXXXX, KC_PIPE, KC_ASTR, KC_PLUS, KC_UNDS ,                  KC_MINS, KC_EQL , KC_SLSH   , XXXXXXX , XXXXXXX, XXXXXXX, \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, KC_DEL , XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    ),

  /* CAPS LAYER
   * ,------------------------------------------             ------------------------------------------,
   * |      |   F1 |  F2  |  F3  |  F4  |  F5  |             |  F6  |  F7  |   F8 |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |   (  |   [  |      |             |   ]  |   )  |      |  "   |  '   |  F12 |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |   {  |      |      |             |      |   }  | PgUp | PgDwn|PgHome| End  |
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
  */

  [CAPL] = KEYMAP(
    XXXXXXX, KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5   ,                  KC_F6  , KC_F7  , KC_F8     , KC_F9   , KC_F10 , KC_F11 , \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LPRN, KC_LBRC, XXXXXXX ,                  KC_RBRC, KC_RPRN, XXXXXXX   , KC_DQUO , KC_QUOT, KC_F12 , \
    XXXXXXX, XXXXXXX, XXXXXXX, KC_LCBR, XXXXXXX, XXXXXXX ,                  XXXXXXX, KC_RCBR, KC_PGUP   , KC_PGDN , KC_HOME, KC_END , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    ),

  /* ALTB LAYER
   * ,------------------------------------------             ------------------------------------------,
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |Tab   |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
  */

  [ALTB] = KEYMAP(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_TAB , XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    ),

  /* SATB LAYER
   * ,------------------------------------------             ------------------------------------------,
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |ShiftTab|    |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      |
   * `-------------------------------------------------------------------------------------------------'
  */

  [SATB] = KEYMAP(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, M(0)   , XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    ),

  /* NAVIGATION LAYER: This layer is activated with a key on the right hand, because when the right hand isnt on the keyboard, it can do both of these (mouse and arrow keys)
   * ,------------------------------------------             ------------------------------------------, 
   * |      |      |mlfup |      | mrup |      |             |      | pgup |  home| pgdwn|      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      | mleft|mright| mdwn | mup  |      |             |      |  up  | down |left  | right|      | https://stackoverflow.com/questions/6698521/vim-users-where-do-you-rest-your-right-hand
   * |------+------+------+------+------+------|             |------+------+------+------+------+------| Answer should be best answer: Bukov
   * |      |      |mlfdwn|      |mrdwn |      |             |      |lfclik|rgclik|midclk|      |      | 
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | Mouse: all on home row; left and right are correct; up is on arrowkey up finger; same for down.
   * `-------------------------------------------------------------------------------------------------' mlfup and mlfdwn are on ring as thjis is ez-p in mind.
  */

  [NAVI] = KEYMAP(
    XXXXXXX, XXXXXXX, M(MUL) , XXXXXXX, M(MUR) , XXXXXXX ,                  XXXXXXX, KC_PGUP, KC_HOME   , KC_PGDN , XXXXXXX, XXXXXXX , \
    XXXXXXX, KC_MS_L, KC_MS_R, KC_MS_D, KC_MS_U, XXXXXXX ,                  XXXXXXX, KC_UP  , KC_DOWN   , KC_LEFT ,KC_RIGHT, XXXXXXX , \
    _______, XXXXXXX, M(MDL) , XXXXXXX, M(MDR) , XXXXXXX ,                  XXXXXXX, KC_BTN1, KC_BTN2   , KC_BTN3 , XXXXXXX, XXXXXXX , \
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    ),

  /* COMMAND LAYER
   * ,------------------------------------------             ------------------------------------------,
   * |      |      |      |      |      |      |             |      |      |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      | Esc  |      |      |      |      |
   * |------+------+------+------+------+------|             |------+------+------+------+------+------|
   * |      |      |      |      |      |      |             |      |      |      |      |      |      | 
   * |------+------+------+------+------+---------------------------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |      |      |      |      |      |      |      | 
   * `-------------------------------------------------------------------------------------------------'
  */

  [COMM] = KEYMAP(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, KC_ESC , XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,                  XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX , \
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX ,XXXXXXX ,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX   , XXXXXXX , XXXXXXX, XXXXXXX \
    )

};

const uint16_t PROGMEM fn_actions[] = {

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0: // shift alt tab
        if (record->event.pressed) {
            register_code(KC_LSFT);
            register_code(KC_TAB);
        }
        else {
            unregister_code(KC_TAB);
            unregister_code(KC_LSFT);
        }
        break;
     } 
    return MACRO_NONE;

};



void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  return true;
}

void led_set_user(uint8_t usb_led) {

}
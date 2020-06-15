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
#ifndef HF40_H
#define HF40_H

#include "quantum.h"

// This a shortcut to help you visually see your layout.
// The following is an example using the Planck MIT layout
// The first section contains all of the arguments
// The second converts the arguments into a two-dimensional array
#define KEYMAP( \
    L00, L01, L02, L03, L04, L05,           R00, R01, R02, R03, R04, R05, \
    L10, L11, L12, L13, L14, L15,           R10, R11, R12, R13, R14, R15, \
    L20, L21, L22, L23, L24, L25,           R20, R21, R22, R23, R24, R25, \
    L30, L31, L32, L33, L34, L35, L36, R30, R31, R32, R33, R34, R35, R36 \
) \
{ \
    { L00, L01, L02, L03, L04, L05, KC_NO, KC_NO, R00, R01, R02, R03, R04, R05 }, \
    { L10, L11, L12, L13, L14, L15, KC_NO, KC_NO, R10, R11, R12, R13, R14, R15 }, \
    { L20, L21, L22, L23, L24, L25, KC_NO, KC_NO, R20, R21, R22, R23, R24, R25 }, \
    { L30, L31, L32, L33, L34, L35, L36  , R30  , R31, R32, R33, R34, R35, R36 } \
}

#endif

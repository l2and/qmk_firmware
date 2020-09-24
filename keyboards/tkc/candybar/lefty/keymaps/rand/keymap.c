/* Copyright 2018 Jack Humbert
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

#include QMK_KEYBOARD_H
#include "rand.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _QWERTY: Base Layer (Default Layer)
   */
[_QWERTY] = LAYOUT_wrapper(
  //,-----------------------------. ,----------------------------------------------------.
  _____________NUMPAD_1_____________, _____________________QWERTY_1______________________, \
  _____________NUMPAD_2_____________, _____________________QWERTY_2______________________, \
  _____________NUMPAD_3_____________, _____________________QWERTY_3______________________, \
  _____________NUMPAD_4_____________, ______________________MOD_4________________________
  ),

  /* Keymap _FL: Function Layer
  */
[_FL] = LAYOUT_wrapper(
  ______________FUNC_1______________, ____________________FUNCTION_1_____________________, \
  ______________FUNC_2______________, ____________________FUNCTION_2_____________________, \
  ______________FUNC_3______________, ____________________FUNCTION_3_____________________, \
  ______________FUNC_4______________, ______________________MOD_4________________________
  )
};
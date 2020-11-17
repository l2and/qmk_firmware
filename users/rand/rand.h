/* Copyright 2019 @ninjonas
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
#pragma once
#include "quantum.h"
#include "version.h"
#include "eeprom.h"
#include "process_records.h"

#ifdef TAP_DANCE_ENABLE
  #include "tap_dances.h"
#endif

#if defined(KEYBOARD_kingly_keys_ave_ortho) & defined(RGBLIGHT_ENABLE)
    /* ws2812 RGB LED */
    #define RGB_DI_PIN B7
    #define RGBLED_NUM 2   // Number of LEDs
    
    #define RGBLIGHT_EFFECT_BREATHING
/*  #define RGBLIGHT_HUE_STEP 6
*   #define RGBLIGHT_SAT_STEP 4
*   #define RGBLIGHT_VAL_STEP 4
*/
#endif


#ifdef ENCODER_ENABLE   
bool left_encoder_rotated;
bool right_encoder_rotated;
uint16_t encoder_rotated_timer;
#endif

#define _QWERTY 0
#define _DVORAK 1
#define _GAMING 2
#define _LOWER 3
#define _RAISE 4
#define _ADJUST 5
#define _NUMPAD 6

// Shortcut Keys
#define K_LOCK LGUI(LCTL(KC_Q)) // Locks screen on MacOS
#define K_CSCN LGUI(LCTL(LSFT(KC_4))) // Copy a portion of the screen to the clipboard
#define K_CPRF LGUI(LSFT(KC_M)) //  Cmd + Shift + M. Used for switching Google Chrome profiles
#define K_MDSH LSFT(LALT(KC_MINS))

// Layer Keys
#define LT_LOW MO(_LOWER)
#define LT_RAI MO(_RAISE)
#define LT_ADJ MO(_ADJUST)

// Mod-Tap Keys
#define MT_DEL MT(MOD_LALT | MOD_LSFT, KC_DEL)
#define MT_EQL MT(MOD_RSFT, KC_EQL) 

// Layout blocks
#if defined(KEYBOARD_tkc_candybar_lefty)
  #define ___________________________QWERTY_R1__________________________ T_ESC, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_DEL, KC_BSPC
  #define ___________________________QWERTY_R2__________________________ KC_TAB, KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
  #define ___________________________QWERTY_R3__________________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT
  #define _____________________________MOD_4____________________________ KC_LCTL, KC_LALT, T_GUI, T_RAI, XXXXXXX, KC_SPC, _______________NAV_1______________

  #define ___________________________RAISE_R1___________________________ KC_GRV, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL, KC_BSPC
  #define ___________________________RAISE_R2___________________________ KC_TAB, _______________NAV_1______________, XXXXXXX, XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
  #define ___________________________RAISE_R3___________________________ KC_LSFT, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS

  #define ___________________________LOWER_R1___________________________ KC_TILD, KC_1, KC_2, KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_DEL, KC_BSPC
  #define ___________________________LOWER_R2___________________________ KC_TAB, _______________NAV_1______________, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
  #define ___________________________LOWER_R3___________________________ KC_LSFT, RESET, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS

  #define ______________________MOD_4________________________ KC_LCTL, KC_LALT, T_GUI, LT_CFL, KC_SPC, _______________NAV_1______________

  #define _______________FUNC_1______________ KC_F1, KC_F2, KC_F3, KC__VOLUP
  #define _______________FUNC_2______________ KC_F4, KC_F5, KC_F6, KC__VOLDOWN
  #define _______________FUNC_3______________ KC_F7, KC_F8, KC_F9, KC_EQL
  #define _______________FUNC_4______________ KC_F10, KC_F11, KC_F12, KC_PENT

#else

  #define _____________________QWERTY_L1______________________ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
  #define _____________________QWERTY_L2______________________ T_ESC, KC_A, KC_S, KC_D, KC_F, KC_G
  #define _____________________QWERTY_L3______________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B

  #define _____________________QWERTY_R1______________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC
  #define _____________________QWERTY_R2______________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
  #define _____________________QWERTY_R3______________________ KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT

  #define _____________________DVORAK_L1______________________ KC_TAB, KC_QUOT, KC_COMM, KC_DOT, KC_P, KC_Y
  #define _____________________DVORAK_L2______________________ T_ESC, KC_A, KC_O, KC_E, KC_U, KC_I
  #define _____________________DVORAK_L3______________________ KC_LSFT, KC_SCLN, KC_Q, KC_J, KC_K, KC_X

  #define _____________________DVORAK_R1______________________ KC_F, KC_G, KC_C, KC_R, KC_L, KC_BSLS
  #define _____________________DVORAK_R2______________________ KC_D, KC_H, KC_T, KC_N, KC_S, KC_SLSH
  #define _____________________DVORAK_R3______________________ KC_B, KC_M, KC_W, KC_V, KC_Z, MT_EQL

  #define _____________________GAMING_L1_____________________ KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T
  #define _____________________GAMING_L2_____________________ KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G
  #define _____________________GAMING_L3_____________________ KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B

  #define _____________________GAMING_R1_____________________ KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSPC
  #define _____________________GAMING_R2_____________________ KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_QUOT
  #define _____________________GAMING_R3_____________________ KC_K, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_ENT

  #define _____________________NUM_LEFT_______________________ T_GRV, KC_1, KC_2, KC_3, KC_4, KC_5
  #define _____________________NUM_RIGHT______________________ KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC

  #define _____________________RAISE_L2_______________________ KC_DEL, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
  #define _____________________RAISE_L3_______________________ KC_LSFT, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11

  #define _____________________RAISE_R2_______________________ KC_F6, KC_MINS, KC_EQL, KC_LBRC, KC_RBRC, KC_BSLS
  #define _____________________RAISE_R3_______________________ KC_F12, _______________NAV_1______________, KC_ENT

  #define _____________________FUNC_LEFT______________________ KC_F11, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
  #define _____________________FUNC_RIGHT_____________________ KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F12

  #define _____________________SYM_LEFT_______________________ KC_TILD, KC_EXLM, KC_AT, KC_HASH, KC_DLR, KC_PERC
  #define _____________________SYM_RIGHT______________________ KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL

  #define _____________________LOWER_L1_______________________ M_XXX2, M_XXX3, XXXXXXX, XXXXXXX, XXXXXXX, K_CSCN
  #define _____________________LOWER_L2_______________________ T_ESC, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  #define _____________________LOWER_L3_______________________ KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

  #define _____________________LOWER_R1_______________________ _______________NAV_1______________, XXXXXXX, K_MDSH
  #define _____________________LOWER_R2_______________________ XXXXXXX, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PIPE
  #define _____________________LOWER_R3_______________________ XXXXXXX, _______________NAV_1______________, KC_ENT

  #define _____________________ADJUST_L1______________________ M_MAKE, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

// ORTHO BLOCK
  #define ______________________MOD_4_________________________ T_CPAP, KC_LCTL, KC_LALT, T_GUI, LT_LOW, KC_SPC, KC_SPC, LT_RAI, _______________NAV_1______________


#endif

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________ADJUST_L2______________________ M_VRSN, M_MALL, RGB_SPI, RGB_SAI, RGB_HUI, RGB_VAI
  #define _____________________ADJUST_L3______________________ M_FLSH, XXXXXXX, RGB_SPD, RGB_SAD, RGB_HUD, RGB_VAD
#else
  #define _____________________ADJUST_L2______________________ M_VRSN, M_MALL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  #define _____________________ADJUST_L3______________________ M_FLSH, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#endif

#if defined(RGB_MATRIX_ENABLE) || defined(RGBLIGHT_ENABLE)
  #define _____________________ADJUST_R1______________________ RGB_TOG, XXXXXXX, XXXXXXX, GAMING,  DVORAK, QWERTY
  #define _____________________ADJUST_R3______________________ RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#else
  #define _____________________ADJUST_R1______________________ XXXXXXX, XXXXXXX, XXXXXXX, GAMING,  DVORAK, QWERTY
  #define _____________________ADJUST_R3______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
#endif
#define _____________________ADJUST_R2______________________ XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX

#if defined(KEYBOARD_tkc_candybar_lefty)
  #define ______________NUMPAD_1_____________ KC_P7, KC_P8, KC_P9, KC_ASTR
  #define ______________NUMPAD_2_____________ KC_P4, KC_P5, KC_P6, KC_QUOT
  #define ______________NUMPAD_3_____________ KC_P1, KC_P2, KC_P3, KC_RCBR
  #define ______________NUMPAD_4_____________ KC_P0, KC_P0, KC_PDOT, KC_PENT
#else
  #define _____________________NUMPAD_1_______________________ KC_P7, KC_P8, KC_P9, KC_PAST, XXXXXXX, XXXXXXX
  #define _____________________NUMPAD_2_______________________ KC_P4, KC_P5, KC_P6, KC_PMNS, XXXXXXX, XXXXXXX
  #define _____________________NUMPAD_3_______________________ KC_P1, KC_P2, KC_P3, KC_PPLS, XXXXXXX, XXXXXXX
  #define _____________________NUMPAD_4_______________________ LT_CFL, KC_P0, KC_PDOT, KC_PENT
#endif

// Kingly Keys Ave Top Row
#define _______________MOD_1______________ KC_MUTE, T_ESC, T_CPAP, T_GUI, M_TERM
#define _______________MOD_2______________ KC_MUTE, T_ESC, T_CPAP, M_FLAM, M_TERM
// End Ave layouts

#define _______________NAV_1______________ KC_LEFT, KC_DOWN, KC_UP, KC_RGHT
#define _______________NAV_2______________ KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT

#define _____________MOUSE_1______________ KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_D
#define _____________MOUSE_2______________ KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_U

#define __________________________________ _______, _______, _______, _______

#define _____________MOD_LEFT_____________ KC_LALT, T_GUI, KC_LCTL, LT_RAI
#define _____________MOD_RIGHT____________ LT_LOW, KC_BSPC, MT_DEL, T_CPAP

#define _______GAMING_LEFT_______ KC_SPC, LT_RAI, LT_LOW
#define _______GAMING_RIGHT______ T_GUI, LT_LOW, KC_LALT
#define _________MEDIA_3_________ XXXXXXX, KC_MRWD, KC__VOLDOWN

#if defined(KEYBOARD_crkbd_rev1)
  #define ________MOD_LEFT_________ KC_LCTL, LT_LOW, T_GUI
  #define ________MOD_RIGHT________ KC_SPC, LT_RAI, KC_LALT
#else
  #define ________MOD_LEFT_________ KC_LALT, T_GUI, KC_LCTL
  #define ________MOD_RIGHT________ KC_BSPC, MT_DEL, T_CPAP
#endif

// Layout wrappers
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)
#define LAYOUT_ortho_all_wrapper(...) LAYOUT_ortho_all(__VA_ARGS__)
#define LAYOUT_planck_grid_wrapper(...) LAYOUT_planck_grid(__VA_ARGS__)
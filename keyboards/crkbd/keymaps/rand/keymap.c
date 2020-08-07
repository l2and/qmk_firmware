#include QMK_KEYBOARD_H
#include "rand.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________QWERTY_L1______________________,       _____________________QWERTY_R1______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________QWERTY_L2______________________,       _____________________QWERTY_R2______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________QWERTY_L3______________________,       _____________________QWERTY_R3______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                ________MOD_LEFT_________,       ________MOD_RIGHT________
                                 //`---------------------'      `---------------------'
  ),

  [_DVORAK] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________DVORAK_L1______________________,       _____________________DVORAK_R1______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________DVORAK_L2______________________,       _____________________DVORAK_R2______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________DVORAK_L3______________________,       _____________________DVORAK_R3______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                ________MOD_LEFT_________,       ________MOD_RIGHT________
                                 //`---------------------'      `---------------------'
  ),

  [_GAMING] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________GAMING_L1_____________________,       _____________________GAMING_R1_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________GAMING_L2_____________________,       _____________________GAMING_R2_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________GAMING_L3_____________________,       _____________________GAMING_R3_____________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                _______GAMING_LEFT_______,       _______GAMING_RIGHT______
                                 //`---------------------'      `---------------------'
  ),

  [_LOWER] = LAYOUT_wrapper(
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________SYM_LEFT_______________________,       _____________________SYM_RIGHT______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________LOWER_L2_______________________,       _____________________LOWER_R2_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________LOWER_L3_______________________,       _____________________LOWER_R3_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),

  [_RAISE] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________NUM_LEFT_______________________,       _____________________NUM_RIGHT______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________RAISE_L2_______________________,       _____________________RAISE_R2_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________RAISE_L3_______________________,       _____________________RAISE_R3_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),

  [_ADJUST] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
     _____________________ADJUST_L1______________________,       _____________________ADJUST_R1______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________ADJUST_L2______________________,       _____________________ADJUST_R2______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
     _____________________ADJUST_L3______________________,       _____________________ADJUST_R3______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),

  [_NUMPAD] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
      _______, _______, _______, _______, _______, _______,      _____________________NUMPAD_1_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      _______, _______, _______, _______, _______, _______,      _____________________NUMPAD_2_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      _______, _______, _______, _______, _______, _______,      _____________________NUMPAD_3_______________________,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),
/*
  [_TEMPLATE] = LAYOUT_wrapper( \
  //,----------------------------------------------------.      ,----------------------------------------------------.
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|--------+--------+--------+--------+--------+-------|      |--------+--------+--------+--------+--------+-------|
                                    _______,_______,_______,     _______,_______,_______
                                 //`---------------------'      `---------------------'
  ),
*/
};
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
#include "rand.h"
#if defined(KEYBOARD_kingly_keys_ave_ortho)
  // RGB Indicator Customization: (100% stolen from Jetpacktuxedo)
  void keyboard_post_init_user(void) {
    #ifdef RGBLIGHT_ENABLE
  // Set up RGB effects on _only_ the first LED (index 0):
          rgblight_set_effect_range(0, 1);
  // Set LED effects to breathing mode in a "terminal-green" type color:
          rgblight_sethsv_noeeprom(50, 255, 100);
          rgblight_mode_noeeprom(RGBLIGHT_EFFECT_BREATHING + 2);
  // Init the second LED to a static color:
          setrgb(225, 185, 0, (LED_TYPE *)&led[1]);
      rgblight_set();
    #endif // RGBLIGHT_ENABLE
  }

  // RGB Indicator Customization: (cont.)
  layer_state_t layer_state_set_user(layer_state_t state){
      #ifdef RGBLIGHT_ENABLE
          uint8_t led1r = 0; uint8_t led1g = 0; uint8_t led1b = 0;
              if (layer_state_cmp(state, 1)) {
                  led1b = 255;
              }
              if (layer_state_cmp(state, 3)) {
                  led1r = 200;
              }
              setrgb(led1r, led1g, led1b, (LED_TYPE *)&led[1]);
          rgblight_set();
      #endif //RGBLIGHT_ENABLE
    return state;
  }
#else
  layer_state_t layer_state_set_user (layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
  }

  #ifdef RGBLIGHT_ENABLE
  extern rgblight_config_t rgblight_config;
  #endif
  void keyboard_post_init_user() {
    #ifdef RGBLIGHT_ENABLE
       // Cycles through the entire hue wheel and resetting to default color
       uint16_t default_hue = rgblight_config.hue;
       rgblight_enable_noeeprom(); 
       layer_state_set_user(layer_state);
       rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
       for (uint16_t i = 255; i > 0; i--) {
            rgblight_sethsv_noeeprom((i + default_hue) % 255, rgblight_config.sat, rgblight_config.val);
            matrix_scan();
            wait_ms(10);
       }
    #endif
    layer_state_set_user(layer_state);
  }
#endif

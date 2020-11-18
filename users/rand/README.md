Copyright 2020 @l2and

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.


# QMK User Configuration for [rand](https://github.com/l2and/qmk_firmware)
Tired of copying and pasting the same macros and tap dances for all my keymaps. Utilizing user keymaps functionality.
See: https://docs.qmk.fm/#/feature_userspace

* (WIP) modifying original settings to work in Pop_OS
* (WIP) still using default qwerty keymap, but wih dvorak selected in the settings. As such, shortcuts are modified to send the correct keystrokes using the default qwerty qmk base, but with dvorak selected in settings

**Taken and modified from [ninjonas](https://github.com/qmk/qmk_firmware/tree/master/users/ninjonas)**

## [rand.c](rand.c)
- l2and [QMK user configuration](https://github.com/qmk/qmk_firmware/blob/master/docs/feature_userspace.md)
- On `keymap.c` include `rand.h`
  ```c
  #include "rand.h"
  ```

## Supported Keyboards
- [Crkbd ](../../keyboards/crkbd/keymaps/rand)
- [Candybar Lefty](../../keyboards/tkc/candybar/lefty/keymaps/rand)
- [Ave](../../keyboards/kingly_keys/ave/ortho/keymaps/rand)
- [Planck](../../keyboards/planck/keymaps/rand)

## Features
### [Keys](rand.h)
|Code | Description |
|---|---|
|K_LOCK | MacOS shortcut to execute lock command Cmd + CTRL + Q |
|K_CSCN | MacOS shortcut to copy a portion of the screen to the clipboard |
|K_MDSH | MacOS shortcut to get em-dash `–` |
|K_CPRF | Cmd + Shift + M. Used for switching Google Chrome profiles | 

### [Layers](rand.h)
|Code | Description |
|---|---|
|LT_LOW | Tap for ENTER, hold for RAISE |
|LT_RAI | Tap for SPACE, hold for LOWER |

### [Mod-Taps](rand.h)
|Code | Description |
|---|---|
|MT_DEL | Tap for Delete, hold for ALT + SHIFT |
|MT_EQL | Tap for =, SHIFT |

### [Layout Blocks](rand.h)
Predefined keyboard layout templates to speed up configuring split keyboards

|Code | Description |
|---|---|
|QWERTY | Qwerty Layout |
|DVORAK | Dvorak Layout |
|GAMING | Gaming Layout |
|NUM | Number Rows |
|FUNC | Function Rows |
|SYM | Symbol Rows \(When holding shift on numbers\) |
|NAV | Navigation Cluster |
|MOUSE | Mouse Cluster |
|MEDIA | Media Cluster |
|MOD | Modifier Cluster |
|NUMPAD | Numpad Cluster |

### [Macros](process_records.c)
|Code | Description |
|---|---|
|M_PYNV | Macro to activate pyenv with the name `jira` |
|M_FLAM | open Flameshot |
|M_MAKE | Macro to send QMK make command to compile keyboard |
|M_MALL | Macro to send QMK make command to all [rand](#Supported%20Keyboards) keyboards |
|M_FLSH | Macro to send QMK make command to compile keyboard with the correct bootloader |
|M_VRSN | Macro to send QMK version |
|M_SHFT | Sends Cmd + alt + shift to a keycode to activate [ShiftIt](https://github.com/fikovnik/ShiftIt) |
|M_CODE | Opens Sulbime Text on current directory |
|M_TERM | Launches Spotlight and calls Terminal |
|M_00 | Types out double 0s `In progress`
|M_XXX1 to M_XXX5 | Reserved for secret macros see [Secrets](#secrets)  |

### [Tap-Dance](tap_dances.h)
|Code | Description |
|---|---|
|T_ESC | Tap once for ESC, double tap for CAPS_LOCK |
|T_LBRC | Tap once for [, double for back browser |
|T_RBRC | Tap once for ], double for forward browser |
|T_TAB | Tap once for TAB, double for CTRL + TAB |
|T_GRV | Tap once for GRV, double for Cmd + GRV |
|T_GUI | Tap once for Cmd, double to open launcher in PopOS |
|T_CPAP | Tap for Ctl + V, hold for Ctl + C, double tap to open [Franz](https://meetfranz.com) app, triple tap for Shopify. |
|T_Y | Tap for Y, double tap for NUMPAD layer |
|T_RAI | Tap for space, hold for `RAISE`, tap and hold for `LOWER` |

### [Combos](combos.h)
|Code | Description |
|---|---|
|EQ_QUIT | Press E + Q will trigger Cmd + Q |
|RW_CLOSE | Press R + W will trigger Cmd + W|
|ET_TAB | Press E + T will trigger Cmd + T| 
|ZC_COPY | Press Z + C will trigger Cmd + C| 
|XV_PASTE | Press X + V will trigger Cmd + V| 

### Secrets
There's times where you have macros you don't want to share like emails, an address you need but you always forget, passwords 😱, & and private strings. Based off [drashna's secret macros](https://github.com/qmk/qmk_firmware/blob/master/users/drashna/readme_secrets.md), it's now possible to do this. All you need to do is create a `secrets.c` file. Below is an example of how this is used.

```c
// secrets.c
#include "rand.h"

static const char * const secret[] = {
  "BLANK1",
  "BLANK2",
  "BLANK3",
  "BLANK4",
  "BLANK5"
};

bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case M_XXX1...M_XXX5:
      if (record->event.pressed) {
        send_string(secret[keycode - M_XXX1]);
      }
      break;
  }
  return true;
}

```
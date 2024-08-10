// bongocatcompress.h

// https://github.com/ADPenrose/qmk_firmware/tree/akemipad/keyboards/adpenrose/akemipad/keymaps/oled_bongocat

#pragma once

#include QMK_KEYBOARD_H
#include "animation_process.h"

#define _QWERTY 0
#define _HHKB 1
#define _LOWER 2
#define _RAISE 3
#define _FKEYS 4
#define _ADJUST 15

// enum custom_keycodes {
//   QWERTY = SAFE_RANGE,
//   HHKB,
//   LOWER,
//   RAISE,
//   ADJUST,
//   BACKLIT,
//   RGBRST
// };

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    render_anim();

    // WPM render
    oled_set_cursor(1, 0);
    oled_write_P(PSTR(">"), false);
    oled_write(get_u8_str(get_current_wpm(), '0'), false);


  return false;
}

/* WPM calculation considerations */
bool wpm_keycode_user(uint16_t keycode) {
  if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
      (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX) ||
      (keycode >= QK_MODS && keycode <= QK_MODS_MAX)) {
    keycode = keycode & 0xFF;
  } else if (keycode > 0xFF) {
    keycode = 0;
  }

  // Include keys in WPM calculation
  if ((keycode >= KC_TAB && keycode <= KC_SLASH) || // Tab - Slash (Symbols, Punctuation, Space)
      (keycode >= KC_KP_SLASH && keycode <= KC_KP_COMMA) ||  // Keypad numbers - Keypad Dot
      (keycode >= KC_F1 && keycode <= KC_F12)) { // F1 - F12
    return true;
  }

  return false;
}

#endif //OLED_ENABLE

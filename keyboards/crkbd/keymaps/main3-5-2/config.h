/*
This is the c configuration file for the keymap

Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert
Copyright 2018 Chris Lee <clee@mg8.org>

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
*/

#pragma once

/* Select hand configuration */

// #define EE_HANDS
#define MASTER_LEFT

// #define SSD1306OLED
// #define OLED_ENABLE
// #define OLED_FONT_H "keyboards/crkbd/lib/glcdfont.c"

// #define USE_SERIAL_PD2
// #define SPLIT_USB_DETECT

//#define IGNORE_MOD_TAP_INTERRUPT_PER_KEY
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
// #define TAPPING_FORCE_HOLD
//
/*#define SPLIT_WPM_ENABLE*/
/*#define SPLIT_LAYER_STATE_ENABLE*/
/*#define SPLIT_ACTIVITY_ENABLE*/

#define TAPPING_FORCE_HOLD
#undef TAPPING_TERM
#define TAPPING_TERM 240
#define RETRO_TAPPING


#undef MOUSEKEY_DELAY
#define MOUSEKEY_DELAY 5
#undef MOUSEKEY_INTERVAL
#define MOUSEKEY_INTERVAL 16
#undef MOUSEKEY_MOVE_DELTA
#define MOUSEKEY_MOVE_DELTA 1
#undef MOUSEKEY_INITIAL_SPEED
#define MOUSEKEY_INITIAL_SPEED 1
#undef MOUSEKEY_DECELERATED_SPEED
#define MOUSEKEY_DECELERATED_SPEED 12
#undef MOUSEKEY_MAX_SPEED
#define MOUSEKEY_MAX_SPEED 22
#define USB_SUSPEND_WAKEUP_DELAY 0
#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_INTERVAL
#define MOUSEKEY_WHEEL_INTERVAL 83

#undef MOUSEKEY_WHEEL_MAX_SPEED
#define MOUSEKEY_WHEEL_MAX_SPEED 3

// #define SPLIT_TRANSPORT_MIRROR
// #define SPLIT_MODS_ENABLE


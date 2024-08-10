#include QMK_KEYBOARD_H
// #include "oled.h"
// #include "bongocat.h"
// #include "bongocatcompress.h"
// #include "config.h"
extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define M_ALTD MT(MOD_LALT,KC_D)
#define M_CMDF MT(MOD_LGUI,KC_F)
#define M_CMDM MT(MOD_LGUI,KC_M)
#define M_ALTCOMM MT(MOD_LALT,KC_COMM)

enum tap_dance_codes {
    TD_G_DQUOTE,
    TD_H_SQUOTE,
    TD_O_MINS,
    TD_COMM_UND,
    TD_DOT_EXLM,
    TD_K_UND,
    TD_L_EXLM,
    TD_SCOL_COL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_split_3x6_3(
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
    KC_NO,    KC_Q,    KC_W,    KC_E, KC_R,    KC_T,                         KC_Y,    KC_U,    KC_I,    TD(TD_O_MINS),   KC_P,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
     KC_NO,    KC_A,    KC_S, M_ALTD,  M_CMDF,    TD(TD_G_DQUOTE),        TD(TD_H_SQUOTE),    KC_J,   TD(TD_K_UND),  TD(TD_L_EXLM), KC_SCLN, KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                     KC_N,    M_CMDM, M_ALTCOMM,  KC_DOT, KC_SLSH, KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                        KC_NO, MT(MOD_MEH,KC_SPACE), OSM(MOD_LSFT),     OSM(MOD_RCTL), TO(1), KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  [1] = LAYOUT_split_3x6_3( \
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_ESCAPE, KC_AT,  LSFT(KC_3), LSFT(KC_4), KC_PERC,                 KC_CIRC, KC_AMPR   ,KC_ASTR   ,TD(TD_SCOL_COL) ,KC_BSPC , KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TAB,    KC_EQL,  KC_NO  ,KC_NO, KC_NO                           ,KC_BSLS,   LSFT(KC_LBRC),LSFT(KC_RBRC),KC_PIPE ,KC_ENTER ,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TILD,   KC_NO,  KC_NO , KC_NO   ,KC_NO                          ,KC_LBRC     ,KC_LPRN   ,KC_RPRN   ,KC_RBRC   ,TO(3)   ,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, TO(0) ,OSM(MOD_LSFT) , KC_RALT  ,TO(2),  KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  [2] = LAYOUT_split_3x6_3( \
  //,---------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO, KC_ESCAPE, KC_MEDIA_PLAY_PAUSE,KC_MEDIA_PREV_TRACK,KC_MEDIA_NEXT_TRACK,LSFT(KC_MINS),KC_MINS,   KC_7,  KC_8, KC_9,KC_TRANSPARENT, KC_NO,\
  //|---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TAB,  KC_TRANSPARENT, KC_AUDIO_VOL_DOWN,KC_AUDIO_VOL_UP,LSFT(KC_EQL),   KC_EQL,   KC_4, KC_5, KC_6,   KC_ENTER, KC_NO,\
  //|---------------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_NO,   KC_KP_ASTERISK, KC_BRIGHTNESS_DOWN,KC_BRIGHTNESS_UP,KC_KP_DOT,   KC_0,   KC_1, KC_2, KC_3,   KC_TRANSPARENT, KC_NO,\
  //|---------------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO,TO(0), KC_LGUI,        KC_RALT ,TO(2), KC_NO\
                                      //`--------------------------'  `--------------------------'
  ),

  [3] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,  KC_ESC,   KC_MS_WH_LEFT,  KC_MS_UP,   KC_MS_WH_RIGHT, KC_NO, LGUI(KC_LBRC),LCTL(LSFT(KC_TAB)),RCTL(KC_TAB),   LGUI(KC_RBRC),KC_TRANSPARENT,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_TAB,   KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT, MT(MOD_LGUI,KC_DEL), KC_LEFT,   MT(MOD_RGUI,KC_DOWN), MT(MOD_RALT,KC_UP), KC_RIGHT,   KC_ENTER, KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO,  KC_NO,   KC_MS_BTN2,  KC_MS_WH_UP,  KC_MS_WH_DOWN, KC_TRANSPARENT, KC_MS_BTN1,     KC_MS_ACCEL0,   KC_MS_ACCEL1,   KC_MS_ACCEL2,  LT(4, KC_NO) ,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                    KC_NO,TO(0),    KC_TRANSPARENT,   KC_RALT,   TO(1), KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),

  [4] = LAYOUT_split_3x6_3( \
  //,-----------------------------------------------------.                    ,-----------------------------------------------------.
      KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                        KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TRNS, KC_TRNS,    KC_F, KC_TRNS, KC_TRNS,                        KC_F1,   KC_F2,   KC_F3,   KC_F4,  KC_F5,   KC_NO,\
  //|--------+--------+--------+--------+--------+--------|                    |--------+--------+--------+--------+--------+--------|
      KC_NO, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,\
  //|--------+--------+--------+--------+--------+--------+--------|  |--------+--------+--------+--------+--------+--------+--------|
                                          KC_NO, KC_TRNS, KC_TRNS,    KC_TRNS, KC_TRNS, KC_NO \
                                      //`--------------------------'  `--------------------------'
  ),
};

/*
tap_dance_action_t tap_dance_actions[] = {
    [TD_G_DQUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_DQUO),
    [TD_H_SQUOTE] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_QUOTE),
    [TD_LT_UND] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_UNDS),
    [TD_GT_EXL] = ACTION_TAP_DANCE_DOUBLE(KC_H, KC_EXLM),
    [TD_SCOL_COL] = ACTION_TAP_DANCE_DOUBLE(KC_SEMICOLON, KC_COLON),
};
*/

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    tap_dance_action_t *action;

    switch (keycode) {
        case TD(TD_G_DQUOTE):
        case TD(TD_H_SQUOTE):
        case TD(TD_O_MINS):
        case TD(TD_K_UND):
        case TD(TD_L_EXLM):
        case TD(TD_DOT_EXLM):
        case TD(TD_SCOL_COL):
        case TD(TD_COMM_UND):
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
    }
    return true;
}

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}

#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

tap_dance_action_t tap_dance_actions[] = {
    [TD_G_DQUOTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, LSFT(KC_QUOTE)), // 2
    [TD_H_SQUOTE] = ACTION_TAP_DANCE_TAP_HOLD(KC_H, KC_QUOTE), // 2
    [TD_O_MINS] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_MINS), // 2
    [TD_COMM_UND] = ACTION_TAP_DANCE_TAP_HOLD(KC_COMM, KC_UNDS), // 3 or 1
    [TD_DOT_EXLM] = ACTION_TAP_DANCE_TAP_HOLD(KC_DOT, KC_EXLM), // 1 or 3
    [TD_K_UND] = ACTION_TAP_DANCE_TAP_HOLD(KC_K, KC_UNDS), // 3 or 1
    [TD_L_EXLM] = ACTION_TAP_DANCE_TAP_HOLD(KC_L, KC_EXLM), // 1 or 3
    [TD_SCOL_COL] = ACTION_TAP_DANCE_TAP_HOLD(KC_SCLN, KC_COLON), // 15
};

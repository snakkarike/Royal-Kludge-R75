// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "quantum.h"

#include "features/defines.h"
#include "features/indicator_queue.h"
#include "features/tap_hold.h"
#include "features/indicators.h"
#include "features/rgb_keys.h"
#include "features/socd_cleaner.h"

void housekeeping_task_user(void) {
    // Note: We can decide what to do with the MAC Led in this function
    if (IS_LAYER_ON(1) || IS_LAYER_ON(3)) { // if the Ctl layer is active
        gpio_write_pin_low(LED_MAC_PIN);    // low means turn on
    } else {
        gpio_write_pin_high(LED_MAC_PIN); // high means turn off
    }

    if (IS_LAYER_ON(2)) { // Check if the layer 2 is active
        // Turn on the Win Lock LED when layer 2 is active
        gpio_write_pin_low(LED_WIN_LOCK_PIN);
    } else {
        // Turn off the Win Lock LED when not on layer 2
        gpio_write_pin_high(LED_WIN_LOCK_PIN);
    } // else we have enabled no_gui, skip re-using the LED
}

// *************
// * SOCD *
// *************
socd_cleaner_t socd_v = {{KC_W, KC_S}, SOCD_CLEANER_LAST};
socd_cleaner_t socd_h = {{KC_A, KC_D}, SOCD_CLEANER_LAST};

// *************
// * Tap Dance *
// *************
enum tap_dance_keys {
    TD_RESET, // require 3 taps to reset board
    TD_CLEAR, // require 3 taps to clear eeprom
    TD_CTL_TG // require double tap to enable ctl layer
};

// *****************************
// * Custom processing of keys *
// *****************************
enum custom_keycodes {
    SOCDON = SAFE_RANGE,
    SOCDOFF,
    SOCDTOG,
};

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
    [TD_RESET]  = ACTION_TAP_DANCE_FN(safe_reset),
    [TD_CLEAR]  = ACTION_TAP_DANCE_FN(safe_clear),
    [TD_CTL_TG] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_RCTL, _CTL_LYR)
};
// clang-format on

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_WIN_LYR] = LAYOUT( /* 0 */
        KC_ESC,   KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_MUTE,
        KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_HOME,  
        KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,  KC_PGUP,    
        KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,   KC_PGDN,          
        KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,            KC_UP,
        KC_LCTL,  KC_LCMD,  KC_LALT,                      KC_SPC,                                 KC_RALT,  MO(1),              KC_LEFT,  KC_DOWN,  KC_RGHT
        ),

    [1] = LAYOUT( /* FN */
        _______,  KC_MYCM,  KC_WHOM,  KC_MAIL,  KC_CALC,  KC_MSEL,  KC_MSTP,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,   KC_SCRL,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  KC_PSCR,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  RGB_MOD,  KC_PAUSE,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,             _______,  KC_END,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,   MO(4),              RGB_VAI,
        _______,  _______,  _______,                      _______,                                 MO(2),  _______,              RGB_SPD,  RGB_VAD,  RGB_SPI 
        ),

    [2] = LAYOUT( /* RESET */
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  TD_KB_RST,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  TD_KB_CLR,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                      _______,                                 _______,  _______,            _______,  _______,  _______ 
        ),

    [3] = LAYOUT( /* FN */
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  KC_P1,    KC_P2,    KC_P3,    KC_P4,    KC_P5,    KC_P6,    KC_P7,    KC_P8,    KC_P9,    KC_P0,    KC_PMNS,  KC_PPLS,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        KC_LCTL,  _______,  KC_LALT,                      _______,                                 _______,  _______,            _______,  _______,  _______ 
        ),   

    [4] = LAYOUT( /* Reset */
        _______, TO(0),     TO(2),    TO(3),    TO(4),    TO(5),    TO(6),    TO(7),    TO(8),    _______,    _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  SOCDTOG,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  QK_MAGIC_TOGGLE_NKRO,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                      _______,                                 _______,  _______,            _______,  _______,  _______ 
        ),

    [5] = LAYOUT( /* Disable SOCD */
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,  _______,
        _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,  _______,            _______,
        _______,  _______,  _______,                      _______,                                 _______,  _______,            _______,  _______,  _______ 
        ),
};

#ifdef ENCODER_MAP_ENABLE
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_WIN_LYR] = {ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},  // Volume control on layer 0
    [1] = {ENCODER_CCW_CW(KC_MRWD, KC_MFFD)},  // No action on layer 1
    [2] = {ENCODER_CCW_CW(_______, _______)}, // Media rewind/forward on layer 2
    [3] = {ENCODER_CCW_CW(_______, _______)},  // No action on layer 3
    [4] = {ENCODER_CCW_CW(_______, _______)},  // No action on layer 4
    [5] = {ENCODER_CCW_CW(_______, _______)},  // No action on layer 5
};
#endif
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!process_socd_cleaner(keycode, record, &socd_v)) {
        return false;
    }
    if (!process_socd_cleaner(keycode, record, &socd_h)) {
        return false;
    }
    if (!process_rgb_keys(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case QK_MAGIC_TOGGLE_NKRO:
            if (record->event.pressed) {
                clear_keyboard(); // clear first buffer to prevent stuck keys
                wait_ms(50);
                keymap_config.nkro = !keymap_config.nkro;
                blink_NKRO(keymap_config.nkro);
                wait_ms(50);
                clear_keyboard(); // clear first buffer to prevent stuck keys
                wait_ms(50);
            }
            return false;
        case SOCDON: // Turn SOCD Cleaner on.
            if (record->event.pressed) {
                socd_cleaner_enabled = true;
            }
            return false;
        case SOCDOFF: // Turn SOCD Cleaner off.
            if (record->event.pressed) {
                socd_cleaner_enabled = false;
            }
            return false;
        case SOCDTOG: // Toggle SOCD Cleaner.
            if (record->event.pressed) {
                socd_cleaner_enabled = !socd_cleaner_enabled;
            }
            return false;
        default:
            return true;
    }

    return true;
}
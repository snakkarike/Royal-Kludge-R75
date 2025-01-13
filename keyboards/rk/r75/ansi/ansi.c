// Copyright 2024 SDK (@sdk66)
// SPDX-License-Identifier: GPL-2.0-or-later
#include QMK_KEYBOARD_H

#define LED_ENABLE_PIN A5

void keyboard_pre_init_kb(void) {
    gpio_set_pin_output(LED_ENABLE_PIN);
    gpio_write_pin_high(LED_ENABLE_PIN);

    // Note: CAPS_LOCK is set in the keyboard json
    //       under "indicators": {"caps_lock": "B0","on_state": 0}

    // setup the Win Lock and Mac LEDs
    // Note: These must be set high to turn them off
    gpio_set_pin_output(LED_WIN_LOCK_PIN);
    gpio_write_pin_high(LED_WIN_LOCK_PIN);

    gpio_set_pin_output(LED_MAC_PIN);
    gpio_write_pin_high(LED_MAC_PIN);

    keyboard_pre_init_user();
}

void suspend_power_down_kb(void) {
    // turn off our RGB LEDs
    gpio_write_pin_low(LED_ENABLE_PIN);

    suspend_power_down_user();
}

void suspend_wakeup_init_kb(void) {
    // turn on our RGB LEDs
    gpio_write_pin_high(LED_ENABLE_PIN);

    suspend_wakeup_init_user();
}

void housekeeping_task_kb(void) {
    // Note: The Mac LED should be handled at the user level to provide more flexibility
    // put the code in a function with this signature
    // void housekeeping_task_user(void) { }

    // Control both LEDs based on the no_gui setting
    if (keymap_config.no_gui) {
        // If no_gui is enabled, turn on both LEDs
        gpio_write_pin_low(LED_MAC_PIN);      // Turn on Mac LED
        gpio_write_pin_low(LED_WIN_LOCK_PIN);  // Turn on Win Lock LED
    } else {
        // If no_gui is not enabled, turn off both LEDs
        gpio_write_pin_high(LED_MAC_PIN);     // Turn off Mac LED
        gpio_write_pin_high(LED_WIN_LOCK_PIN); // Turn off Win Lock LED
    }
}

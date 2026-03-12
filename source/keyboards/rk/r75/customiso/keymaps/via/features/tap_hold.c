#include "tap_hold.h"
#include "quantum.h"

void td_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    td_tap_hold_t *tap_hold = (td_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            // "press" the key specified on_hold
            register_code16(tap_hold->on_hold);
            // keep track of which key was used
            tap_hold->chosen = tap_hold->on_hold;
        } else {
            // "press" the key specified on_tap
            register_code16(tap_hold->on_tap);
            // keep track of which key was used
            tap_hold->chosen = tap_hold->on_tap;
        }
    }
}

void td_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    td_tap_hold_t *tap_hold = (td_tap_hold_t *)user_data;

    if (tap_hold->chosen) {
        // there is something to cleanup
        // release the key that was "pressed"
        unregister_code16(tap_hold->chosen);

        // reset the key to 0 to signify nothing is selected
        tap_hold->chosen = 0;
    }
}

void safe_reset(tap_dance_state_t *state, void *user_data) {
    // from https://thomasbaart.nl/2018/12/13/qmk-basics-tap-dance/
    if (state->count >= 3) {
        // Reset the keyboard if you tap the key more than three times
        reset_keyboard();
        reset_tap_dance(state);
    }
}

void safe_clear(tap_dance_state_t *state, void *user_data) {
    if (state->count >= 3) {
        // clear eprom if you tap the key more than three times
        eeconfig_init();
        soft_reset_keyboard();
        reset_tap_dance(state);
    }
}

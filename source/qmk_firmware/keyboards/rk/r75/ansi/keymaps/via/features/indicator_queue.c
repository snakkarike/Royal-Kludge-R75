#include "indicator_queue.h"

rgb_led_t get_complementary_color(rgb_led_t rgb_led, bool darken) {
    uint8_t new_r = 0xFF - rgb_led.r;
    uint8_t new_g = 0xFF - rgb_led.g;
    uint8_t new_b = 0xFF - rgb_led.b;

    if (darken) {
        // darken the new color by shifting all values down
        if (new_r > 0x80) { new_r = new_r - 0x80; }
        if (new_g > 0x80) { new_g = new_g - 0x80; }
        if (new_b > 0x80) { new_b = new_b - 0x80; }
    }

    return (rgb_led_t){.r = new_r, .g = new_g, .b = new_b};
}

void indicator_enqueue(uint8_t led_index, uint32_t interval, uint8_t times_to_flash, uint8_t r, uint8_t g, uint8_t b) {
    for (int i = 0; i < INDICATOR_QUEUE_MAX; i++) {
        if (!indicator_queue[i].active) {
            // this queue position is not active, so we can use it
            indicator_queue[i].active         = true;
            indicator_queue[i].led_index      = led_index;
            indicator_queue[i].last_update    = timer_read32();
            indicator_queue[i].interval       = interval;
            indicator_queue[i].times_to_flash = times_to_flash * 2;
            indicator_queue[i].r              = r;
            indicator_queue[i].g              = g;
            indicator_queue[i].b              = b;
            break;
        }
    }
}

void process_indicator_queue(uint8_t led_min, uint8_t led_max) {
    for (int i = 0; i < INDICATOR_QUEUE_MAX; i++) {
        if (indicator_queue[i].active) {
            // this queue position is active, process it
            if (timer_elapsed32(indicator_queue[i].last_update) >= indicator_queue[i].interval) {
                // the timer has elapsed, perform the action

                indicator_queue[i].last_update = timer_read32(); // reset the timer to now

                if (indicator_queue[i].times_to_flash) {
                    indicator_queue[i].times_to_flash--;
                }

                if (indicator_queue[i].times_to_flash <= 0) {
                    // we have flashed as many times as requested
                    // clear this queue spot
                    indicator_queue[i].active      = false;
                    indicator_queue[i].last_update = 0x00;
                }
            }

            if (indicator_queue[i].times_to_flash % 2) {
                INDICATOR_Q_MATRIX_SET_COLOR(indicator_queue[i]);
            } else {
                rgb_led_t this_rgb_led = INDICATOR_Q_GET_RGB_LED(indicator_queue[i]);
                rgb_led_t alt          = get_complementary_color(this_rgb_led, false);
                INDICATOR_Q_MATRIX_SET_COLOR_CUSTOM(indicator_queue[i], alt.r, alt.g, alt.b);
            }
        }
    }
}

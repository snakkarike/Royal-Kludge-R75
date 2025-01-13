#pragma once

#include QMK_KEYBOARD_H

#define INDICATOR_RGB_DARK_RED      0x80, 0x00, 0x00
#define INDICATOR_RGB_DARK_GREEN    0x00, 0x80, 0x00
#define INDICATOR_RGB_DARK_BLUE     0x00, 0x00, 0x80
#define INDICATOR_RGB_PASTEL_RED    0xCC, 0x66, 0x99
#define INDICATOR_RGB_PASTEL_GREEN  0x66, 0x99, 0x66
#define INDICATOR_RGB_PASTEL_BLUE   0x66, 0x99, 0xCC

// this is similar to RGB_MATRIX_INDICATOR_SET_COLOR
// but takes in an indicator_t instead
#define INDICATOR_Q_MATRIX_SET_COLOR(indicator)                                           \
    if (indicator.led_index >= led_min && indicator.led_index < led_max) {                \
        rgb_matrix_set_color(indicator.led_index, indicator.r, indicator.g, indicator.b); \
    }

#define INDICATOR_Q_MATRIX_SET_COLOR_CUSTOM(indicator, r, g, b)            \
    if (indicator.led_index >= led_min && indicator.led_index < led_max) { \
        rgb_matrix_set_color(indicator.led_index, r, g, b);                \
    }

#define INDICATOR_Q_GET_RGB_LED(indicator)                   \
    (rgb_led_t) {                                            \
        .r = indicator.r, .g = indicator.g, .b = indicator.b \
    }

#define INDICATOR_QUEUE_MAX 20

typedef struct {
    bool     active;
    uint8_t  led_index;
    uint32_t last_update;
    uint32_t interval;
    uint8_t  times_to_flash;
    uint8_t  r;
    uint8_t  g;
    uint8_t  b;
} indicator_t;

indicator_t indicator_queue[INDICATOR_QUEUE_MAX];

rgb_led_t get_complementary_color(rgb_led_t rgb_led, bool darken);

void indicator_enqueue(uint8_t led_index, uint32_t interval, uint8_t times_to_flash, uint8_t r, uint8_t g, uint8_t b);

void process_indicator_queue(uint8_t led_min, uint8_t led_max);

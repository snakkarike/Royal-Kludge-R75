#pragma once

#include QMK_KEYBOARD_H

void blink_arrows(void);
void blink_space(bool);
void blink_NKRO(bool);
void blink_numbers(bool);
void highlight_fn_keys(uint8_t led_min, uint8_t led_max);

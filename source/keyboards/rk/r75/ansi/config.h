// Copyright 2024 DV (@iamdanielv)
// SPDX-License-Identifier: GPL-2.0-or-later
#pragma once

// #define DYNAMIC_KEYMAP_LAYER_COUNT 6 // 9 -- defaults to 4, now defined in keyboard.json
// #define WEAR_LEVELING_LOGICAL_SIZE 2048 // defined below
// #define WEAR_LEVELING_BACKING_SIZE 4096 // defined in keyboard.json

// #define LED_CAPS_LOCK_PIN B0 // defined in keyboard.json
#define LED_WIN_LOCK_PIN B9
#define LED_MAC_PIN B8

/* SPI */
#define SPI_DRIVER SPIDQ
#define SPI_SCK_PIN B3
#define SPI_MOSI_PIN B5
#define SPI_MISO_PIN B4

/* Flash */
#define EXTERNAL_FLASH_SPI_SLAVE_SELECT_PIN C12
// #define WEAR_LEVELING_BACKING_SIZE // defined in keyboard.json
#define WEAR_LEVELING_LOGICAL_SIZE (WEAR_LEVELING_BACKING_SIZE / 2)

/* RGB Matrix */
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define RGB_MATRIX_KEYPRESSES

/* WS2812 */
#define WS2812_SPI_DRIVER SPIDM2
#define WS2812_SPI_DIVISOR 32

// Set defaults for LED matrix
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_SOLID_COLOR
#define RGB_MATRIX_DEFAULT_HUE 0
#define RGB_MATRIX_DEFAULT_SAT 0
#define RGB_MATRIX_DEFAULT_VAL 180

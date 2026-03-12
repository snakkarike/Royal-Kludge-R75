#pragma once

enum layer_names {
    _WIN_LYR,    // 0
    _WIN_FN_LYR, // 1
    _CTL_LYR,    // 2
    _NUM_LYR,    // 3
    _NAV_LYR,    // 4
    _FN_LYR,     // 5
};

// ******************************
// * Aliases to simplify keymap *
// ******************************
#define W_ALT_CAPS LT(_WIN_FN_LYR, KC_CAPS)
#define FN_RALT LT(_FN_LYR, KC_RALT)

#define MY_UNDO   C(KC_Z)
#define MY_CUT    C(KC_X)
#define MY_COPY   C(KC_INS)
#define MY_PASTE  S(KC_INS)
#define MY_TASK   LCTL(LSFT(KC_ESC))
#define MY_CONS   LCTL(LSFT(KC_GRV))
#define MY_BACK   A(KC_LEFT)
#define MY_FWD    A(KC_RIGHT)
#define MY_GRV    LT(_WIN_LYR, KC_GRV)

#define TG_NAV    TG(_NAV_LYR)
#define TG_NUM    TG(_NUM_LYR)
#define TG_CTL    TG(_CTL_LYR)
#define MO_CTL    MO(_CTL_LYR)
#define MO_FN     MO(_WIN_FN_LYR)
#define TD_TG_CTL TD(TD_CTL_TG)
#define TD_KB_RST TD(TD_RESET)
#define TD_KB_CLR TD(TD_CLEAR)

#include QMK_KEYBOARD_H
#include "version.h"

extern keymap_config_t keymap_config;

enum layers {
    _L0 = 0,
    _L1,
    _L2,
    _L3,
    _L4,
    _L5,
    _L6,
    _L7,
    _L8,
    _L9,
    _ADJ
};

enum custom_keycodes {
    DYNAMIC_MACRO_RANGE = SAFE_RANGE,
    QMK_REV,
    KC_TMD,
    KC_EML
};

extern backlight_config_t backlight_config;

#include "dynamic_macro.h"
#define FN_ZERO LT(_L9, KC_KP_0)
#define FN_FIVE LT(_ADJ,KC_DOWN)
#define KC_DMR1 DYN_REC_START1
#define KC_DMR2 DYN_REC_START2
#define KC_DMP1 DYN_MACRO_PLAY1
#define KC_DMP2 DYN_MACRO_PLAY2
#define KC_DMRS DYN_REC_STOP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /*## Layout Config:
    *       NAV            LIGHTS
    *     .-----------.  .-----------.  .-----------.  .-----------.  .-----------.
    *     |HOME|UP|PUP|  |+  |-  |*  |  |^  |&  |!  |  |VLU|Ver|WFD|  |VLU|NXT|FFD|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |L |FN/D |R |  |/  |%  |,  |  |D  |E  |F  |  |MUT|C-W|CHR|  |MUT|STP|PLY|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |END|D  |PDN|  |.  |=  |Ent|  |A  |B  |C  |  |VLD|CMP|WBK|  |VLD|PRV|RWD|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |#L0|_L9/0  |  |#L1|_L9    |  |#L2|_L9    |  |#L3|_L9    |  |#L4|_L9    |
    *     *-----------*  *-----------*  *-----------*  *-----------*  *-----------*
    *
    *          MATH         MOUSE FN      MACROZ        NUMBAHZ         LAYER SELECT
    *     .-----------.  .-----------.  .-----------.  .-----------.  .-----------.
    *     |+  |-  |*  |  |   |   |   |  |MP1|   |MP2|  |7  |8  |9  |  |_L6|_L7|_L8|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |/  |%  |,  |  |   |   |   |  |   |MRS|   |  |4  |5  |6  |  |_L3|_L4|_L5|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |.  |=  |Ent|  |   |   |   |  |MR1|   |MR2|  |1  |2  |3  |  |_L0|_L1|_L2|
    *     |-----------|  |-----------|  |-----------|  |-----------|  |-----------|
    *     |#L5|_L9    |  |#L6|_L9    |  |#L7|_L9    |  |#L8|_L9    |  |#L9|       |
    *     *-----------*  *-----------*  *-----------*  *-----------*  *-----------*
    *
    *       FIVE FUNCTIONS
    *     .-----------.
    *     |SCREEN OFF |BACKLIGHT TOGGLE  | SCREEN REFRESH  |
    *     |-----------|
    *     |SCREEN OFF |                  | SCREEN REFRESH  |
    *     |-----------|
    *     |SCREEN CAP |     CANCEL       |    WINDOW CAP   |
    *     |-----------|
    *     |#LADJ                            |RESET|
    *     *-----------*
    */
    [_L0] = {{KC_HOME, KC_UP, KC_PGUP}, 
            {KC_LEFT, FN_FIVE, KC_RIGHT}, 
            {KC_END, KC_DOWN, KC_PGDN}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L1] = {{BL_BRTG, BL_INC, BL_STEP}, 
            {KC_LEFT, BL_TOGG, KC_HOME}, 
            {LCAG(KC_U), BL_DEC,  LCAG(KC_T)},
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L2] = {{KC_CIRC, KC_AMPR, KC_EXLM}, 
            {S(KC_D), S(KC_E), S(KC_F)}, 
            {S(KC_A), S(KC_B), S(KC_C)}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L3] = {{KC_VOLU, QMK_REV, KC_WFWD},
            {KC_MUTE,  KC_EML,  KC_TMD }, 
            {KC_VOLD, KC_MYCM, KC_WBAK}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L4] = {{KC_VOLU, KC_MNXT, KC_MFFD}, 
            {KC_MUTE, KC_MSTP, KC_MPLY}, 
            {KC_VOLD, KC_MPRV, KC_MRWD}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L5] = {{KC_PPLS, KC_PMNS, KC_PAST}, 
            {KC_PSLS, KC_PERC, KC_COMM}, 
            {KC_PDOT, KC_EQL,  KC_PENT},
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L6] = {{KC_MS_BTN1, KC_MS_U, KC_MS_BTN2}, 
            {KC_MS_L, KC_MS_BTN1, KC_MS_R}, 
            {KC_WH_D, KC_MS_D, KC_WH_U}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L7] = {{KC_DMP1, _______, KC_DMP2}, 
            {_______, KC_DMRS, _______}, 
            {KC_DMR1, _______, KC_DMR2}, 
            {XXXXXXX, XXXXXXX, MO(_L9)}},

    [_L8] = {{KC_KP_7, KC_KP_8, KC_KP_9}, 
            {KC_KP_4, KC_KP_5, KC_KP_6}, 
            {KC_KP_1, KC_KP_2, KC_KP_3}, 
            {XXXXXXX, XXXXXXX, FN_ZERO}},

    [_L9] = {{TO(_L6),TO(_L7), TO(_L8)}, 
            {TO(_L3), TO(_L4), TO(_L5)}, 
            {TO(_L0), TO(_L1), TO(_L2)}, 
            {XXXXXXX, XXXXXXX, _______}},

    [_ADJ] ={{LCAG(KC_U), BL_TOGG,  LCAG(KC_T)}, 
            {LCAG(KC_U), _______,  LCAG(KC_T)}, 
            {SGUI(KC_3), LGUI(KC_DOT), SGUI(KC_4)}, 
            {XXXXXXX, XXXXXXX, RESET}},
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMK_REV:
            if (record->event.pressed) {
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP "@" QMK_VERSION ":" QMK_BUILDDATE);
            }
            return false;
            break;
        case KC_TMD:
            if (record->event.pressed) {
                //SEND_STRING(SS_LGUI("r"));
                //wait_ms(100);
                SEND_STRING("themillerdave\n");
            }
            return false;
            break;
        case KC_EML:
            if (record->event.pressed) {
                //SEND_STRING (SS_LCTRL("w"));
                SEND_STRING("dave@thisisareal.com\n");
            }
            return false;
            break;
    }
    // Dynamic Macros.
    if (!process_record_dynamic_macro(keycode, record)) {
        return false;
    }
    return true;
}

void custom_backlight_level(uint8_t level) {
    if (level > BACKLIGHT_LEVELS)
        level = BACKLIGHT_LEVELS;
    backlight_config.level = level;
    backlight_config.enable = !!backlight_config.level;
    backlight_set(backlight_config.level);
}

void matrix_init_user(void) {
  #ifdef BACKLIGHT_ENABLE
    custom_backlight_level(0);
  #endif
}

void matrix_scan_user(void) {

}

uint32_t layer_state_set_user(uint32_t state) {
    switch (biton32(state)) {
        case _L0:
            custom_backlight_level(0);
            break;
        case _L1:
            custom_backlight_level(1);
            break;
        case _L2:
            custom_backlight_level(2);
            break;
        case _L3:
            custom_backlight_level(3);
            break;
        case _L4:
            custom_backlight_level(4);
            break;
        case _L5:
            custom_backlight_level(5);
            break;
        case _L6:
            custom_backlight_level(6);
            break;
        case _L7:
            custom_backlight_level(6);
            break;
        case _L8:
            custom_backlight_level(6);
            break;
        case _L9:
            custom_backlight_level(0);
            break;
        default:
            custom_backlight_level(0);
            break;
    }
    return state;
}

void led_set_user(uint8_t usb_led) {

}

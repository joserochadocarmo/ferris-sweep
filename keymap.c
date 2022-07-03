// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "quantum.h"

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.

enum unicode_names {
    APOSTROPHE = 0,
    CEDILHA,
    CEDILHAM,
    LIBRA,
    IRONY
};

enum ferris_layers {
    _QWERTY,
    _NAVIGATION,
    _NUMPAD,
    _CARACTERES
};

enum ferris_tap_dances {
    TD_Q_F1,
    TD_W_F2,
    TD_E_F3,
    TD_R_F4,
    TD_T_F5,
    TD_Y_F8,
    TD_U_F9,
    TD_I_F10,
    TD_O_F11,
    TD_P_F12,
    TD_CDILHA,
    TD_ARROBA
};

enum custom_keycodes {
    RALT_TAB = SAFE_RANGE,
    LALT_TAB,
    CUT,
    COPY,
    PASTE
};

// #define KC_CTSC RCTL_T(KC_SCLN)
// #define KC_CTLA LCTL_T(KC_A)
// #define KC_LSHZ LSFT_T(KC_Z)
// #define KC_RLSH RSFT_T(KC_SLSH)
// #define KC_SPM2 LT(2, KC_SPC)
// #define KC_BSM1 LT(1, KC_BSPC)
// #define KC_GUTA GUI_T(KC_TAB)
// #define KC_CLGV CTL_T(KC_GRV)
#define A_LT2 LT(2,KC_A)
#define S_ALT LALT_T(KC_S)
#define D_CTRL LCTL_T(KC_D)
#define F_SHFT LSFT_T(KC_F)
#define G_GUI LGUI_T(KC_G)
#define H_GUI RGUI_T(KC_H)
#define J_SHFT RSFT_T(KC_J)
#define K_CTRL RCTL_T(KC_K)
#define L_ALT RALT_T(KC_L)
#define DQUO_LT3 LT(3,KC_DQUO)
#define BSPC_LT1 LT(1,KC_BSPC)
#define CEDLH XP(CEDILHA,CEDILHAM)
#define KC_APOS X(APOSTROPHE)
#define C_DILHA TD(TD_CDILHA)
#define QUES_ARR TD(TD_ARROBA)
#define Q_F1 TD(TD_Q_F1)
#define W_F2 TD(TD_W_F2)
#define E_F3 TD(TD_E_F3)
#define R_F4 TD(TD_R_F4)
#define T_F5 TD(TD_T_F5)
#define Y_F8 TD(TD_Y_F8)
#define U_F9 TD(TD_U_F9)
#define I_F10 TD(TD_I_F10)
#define O_F11 TD(TD_O_F11)
#define P_F12 TD(TD_P_F12)
#define EURO 0x20AC

const uint32_t PROGMEM unicode_map[] = {
    [APOSTROPHE] = 0x0027,  // '
    [CEDILHA] = 0x00E7,
    [CEDILHAM] = 0x00E7,
    [LIBRA] = 0x264E,
    [IRONY] = 0x2E2E,
};

const uint16_t PROGMEM CB_F6[]   = {R_F4, T_F5, COMBO_END}; // r + t = F6
const uint16_t PROGMEM CB_F7[]   = {Y_F8, U_F9, COMBO_END}; // y + u = F7
const uint16_t PROGMEM CB_VOLU[] = {O_F11, P_F12, COMBO_END}; // o + p = VOL +
const uint16_t PROGMEM CB_MUTE[] = {L_ALT, DQUO_LT3, COMBO_END}; // L + " = MUTE
const uint16_t PROGMEM CB_VOLD[] = {KC_DOT, QUES_ARR, COMBO_END}; // . + ? = VOL -
const uint16_t PROGMEM CB_BRIU[] = {I_F10, O_F11, P_F12, COMBO_END}; // i + o + p = Brighthess +
const uint16_t PROGMEM CB_BRID[] = {KC_COMM, KC_DOT, QUES_ARR, COMBO_END}; // , + . + ? = Brighthess -

combo_t key_combos[COMBO_COUNT] = {
    COMBO(CB_F6, KC_F6),
    COMBO(CB_F7, KC_F7),
    COMBO(CB_VOLU,KC_AUDIO_VOL_UP),
    COMBO(CB_MUTE, KC_AUDIO_MUTE),
    COMBO(CB_VOLD, KC_AUDIO_VOL_DOWN),
    COMBO(CB_BRIU, KC_BRIGHTNESS_UP),
    COMBO(CB_BRID, KC_BRIGHTNESS_DOWN),
    // COMBO(test_combo2, LCTL(KC_Z)), // keycodes with modifiers are possible too!
};

void matrix_init_user(void) {
    set_unicode_input_mode(UC_WINC); // REPLACE UC_XXXX with the Unicode Input Mode for your OS. See table below.
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT( /* QWERTY */
    Q_F1,   W_F2,    E_F3,    R_F4,    T_F5,            Y_F8,    U_F9,  I_F10,    O_F11,   P_F12,
    A_LT2,  S_ALT,   D_CTRL,  F_SHFT,  G_GUI,           H_GUI,   J_SHFT, K_CTRL, L_ALT,  DQUO_LT3,
    KC_Z,   KC_X,    C_DILHA, KC_V,    KC_B,            KC_N,    KC_M,  KC_COMM, KC_DOT, QUES_ARR,
                                    KC_TAB, BSPC_LT1, KC_SPC, KC_ENT
  ),

  [_NAVIGATION] = LAYOUT( /* [> NAVIGATION <] */
    KC_ESC,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_DEL,  KC_INS,  KC_HOME, KC_END,  KC_NO,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_CAPS, KC_LEFT, KC_UP,   KC_DOWN, KC_RGHT,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,         KC_NO,   KC_NO,   KC_PGUP, KC_PGDN, KC_NO,
                                    KC_NO, KC_TRNS, KC_TRNS, KC_TRNS  
  ),

  [_NUMPAD] = LAYOUT( /* [> NUMPAD <] */
    KC_NO,KC_NO,   KC_NO,   KC_NO,    TG(1),          KC_P7, KC_P8, KC_P9, KC_PSLS, KC_PPLS,
    KC_NO,LALT_T(CUT),LCTL_T(COPY), LSFT_T(PASTE), KC_NO,KC_P4, KC_P5, KC_P6, KC_PAST, KC_MINS,
    KC_NO,KC_NO,   KC_NO,   KC_NO,    KC_NO,          KC_P1, KC_P2, KC_P3, KC_PERC, KC_ENT,
                                    LALT_TAB, RALT_TAB, KC_P0, KC_PDOT
  ),

  [_CARACTERES] = LAYOUT( /* [> CARACTERES <] */
    KC_RBRC, KC_NUHS, KC_QUOT, KC_LPRN, KC_RPRN,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_RPRN, KC_HASH, KC_AMPR, KC_LBRC, KC_RBRC,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,
    KC_DLR,  UC(EURO),X(IRONY),KC_LT,KC_GT,              KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
      case RALT_TAB:
          if (record->event.pressed) {
              SEND_STRING(SS_RALT(SS_RCTL(SS_TAP(X_TAB))));
          }
          break;
      case LALT_TAB:
          if (record->event.pressed) {
              SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
          }
          break;
      case CUT:
          if (record->event.pressed) {
              SEND_STRING(SS_LALT(SS_TAP(X_X)));
          }
          break;
      case COPY:
          if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_C)));
          }
          break;
      case PASTE:
          if (record->event.pressed) {
              SEND_STRING(SS_LCTL(SS_TAP(X_V)));
          }
          break;
    }
    return true;
};

// Tap Dance Definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Q, twice for ESC
    [TD_Q_F1] = ACTION_TAP_DANCE_DOUBLE(KC_Q, KC_F1),
    [TD_W_F2] = ACTION_TAP_DANCE_DOUBLE(KC_W, KC_F2),
    [TD_E_F3] = ACTION_TAP_DANCE_DOUBLE(KC_E, KC_F3),
    [TD_R_F4] = ACTION_TAP_DANCE_DOUBLE(KC_R, KC_F4),
    [TD_T_F5] = ACTION_TAP_DANCE_DOUBLE(KC_T, KC_F5),
    [TD_Y_F8] = ACTION_TAP_DANCE_DOUBLE(KC_Y, KC_F8),
    [TD_U_F9] = ACTION_TAP_DANCE_DOUBLE(KC_U, KC_F9),
    [TD_I_F10] = ACTION_TAP_DANCE_DOUBLE(KC_I, KC_F10),
    [TD_O_F11] = ACTION_TAP_DANCE_DOUBLE(KC_O, KC_F11),
    [TD_P_F12] = ACTION_TAP_DANCE_DOUBLE(KC_P, KC_F12),
    [TD_CDILHA] = ACTION_TAP_DANCE_DOUBLE(KC_C, CEDLH),
    [TD_ARROBA] = ACTION_TAP_DANCE_DOUBLE(KC_QUES, KC_AT)
};

const key_override_t comm_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMM, KC_SCLN); // Shift , is ;
const key_override_t dot_key_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLN);  // Shift . is :
const key_override_t ques_key_override = ko_make_basic(MOD_MASK_SHIFT, QUES_ARR, KC_EXCLAIM); // Shift ? is !
const key_override_t dquo_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DQUO, KC_APOS); // Shift " is '
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_P1, KC_PIPE); // Shift 1 is |
const key_override_t psls_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PSLS, KC_BACKSLASH);  

const key_override_t** key_overrides = (const key_override_t*[]){
    &dot_key_override,
    &comm_key_override,
    &ques_key_override,
    &dquo_key_override,
    &pipe_key_override,
    &psls_key_override,
    NULL
};
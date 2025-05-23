#include QMK_KEYBOARD_H

//-------------------------------------------------------------------------------
// Modifier defines to simplify mapping and combo references

// BASE

// Thumbs
#define KA_LSFP   LSFT_T(KC_SPC)
#define KA_RSFEN  RSFT_T(KC_ENT)

// Fingers
#define KC_LCTRL_F    MT(MOD_LCTL, KC_F)
#define KC_LCTRL_4    MT(MOD_LCTL, KC_4)
#define KC_RCTRL_J    MT(MOD_RCTL, KC_J)
#define KC_RCTRL_7    MT(MOD_RCTL, KC_7)
#define KC_LALT_V     MT(MOD_LALT, KC_V)
#define KC_RALT_M     MT(MOD_RALT, KC_M)
#define KC_LGUI_T     MT(MOD_LGUI, KC_T)
#define KC_RGUI_Y     MT(MOD_RGUI, KC_Y)

// DUO
#define KC_LSHCTRL_G  MT(MOD_LCTL | MOD_LSFT, KC_G)
#define KC_RSHCTRL_H  MT(MOD_RCTL | MOD_RSFT, KC_H)
#define KC_LSHALT_B   MT(MOD_LALT | MOD_LSFT, KC_B)
#define KC_RSHALT_N   MT(MOD_RALT | MOD_RSFT, KC_N)

#define KC_LCTRLALT_R MT(MOD_LCTL | MOD_LALT, KC_R)
#define KC_RCTRLALT_U MT(MOD_RCTL | MOD_RALT, KC_U)

// MEH
#define KC_LMEH_D     MT(MOD_LCTL | MOD_LALT | MOD_LSFT, KC_D)
#define KC_RMEH_K     MT(MOD_RCTL | MOD_RALT | MOD_RSFT, KC_K)

// HYPER
#define KC_LHYPR_E    MT(MOD_LCTL | MOD_LALT | MOD_LSFT | MOD_LGUI, KC_E)
#define KC_RHYPR_I    MT(MOD_RCTL | MOD_RALT | MOD_RSFT | MOD_RGUI, KC_I)

// APPS Mapping
#define KA_LINKEDIN HYPR(KC_L)
#define KA_OUTLOOK  HYPR(KC_O)
#define KA_TEAMS    HYPR(KC_T)
#define KA_FILEMGR  RGUI(KC_E)
#define KA_POWERPT  HYPR(KC_P)
#define KA_WORD     HYPR(KC_W)
#define KA_TASKMGR  RCS(KC_ESC)
#define KA_RUN      RGUI(KC_R)
#define KA_EMOJIS   LGUI(KC_DOT)
#define KA_EXCEL    HYPR(KC_X)
#define KA_SNIP     SGUI(KC_S)
#define KA_CLIPBRD  RGUI(KC_V)
#define KA_LOCK     RGUI(KC_L)

// Behavior
#define KA_CADEL    C(A(KC_DEL))

// Browser

#define CR_NTAB     C(KC_T)
#define CR_NINCOG   RCS(KC_T)
#define CR_HOME     A(KC_HOME)
#define CR_BKMRKS   RCS(KC_O)
#define CR_BKMRK    C(KC_D)
#define CR_BKBAR    RCS(KC_B)
#define CR_NEWWIN   C(KC_N)
#define CR_INGWIN   RCS(KC_N)

const uint16_t lf_keylist[] = {KC_1, KC_2, KC_3, KC_4, KC_5, KC_Q, KC_W, KC_E, KC_R, KC_LGUI_T, KC_A, KC_S, KC_D, KC_LCTRL_F, KC_LSHCTRL_G, KC_Z, KC_X, KC_C, KC_LALT_V, KC_B, KC_TAB, KA_LSFP};
const uint16_t rt_keylist[] = {KC_6, KC_7, KC_8, KC_9, KC_0, KC_RGUI_Y, KC_U, KC_I, KC_O, KC_P, KC_RSHCTRL_H, KC_RCTRL_J, KC_K, KC_L, KC_SCLN, KC_N, KC_RALT_M, KC_COMM, KC_DOT, KC_SLSH, KA_RSFEN, KC_BSPC};


const int rt_keylist_size = sizeof(rt_keylist) / sizeof(rt_keylist[0]);
const int lf_keylist_size = sizeof(lf_keylist) / sizeof(lf_keylist[0]);


//-------------------------------------------------------------------------------

enum layers {
  _ALPHA,
  _NUMBSYM,
  _FUNCTION,
  _APPCONTROL,
  _MOUSE,
  LAYER_LENGTH
};

enum combos {
    DOUBLEQ_COMBO,
    SINGLEQ_COMBO,
    LPAR_COMBO,
    RPAR_COMBO,
    LBRACE_COMBO,
    RBRACE_COMBO,
    LCURLY_COMBO,
    RCURLY_COMBO,
    LESC_COMBO,
    DEFAULT_COMBO,
    MOUSE_COMBO,
    NUMB_COMBO,
    FUNC_COMBO,
    APP_COMBO,
    ONESHOT_SYM_COMBO,
    ONESHOT_SYM_LSHIFT_COMBO,
    ONESHOT_FUNC_COMBO,
    ONESHOT_APP_COMBO,
    DEL_COMBO,
    WINCLOSE_COMBO,
    APPCLOSE_COMBO,
    CAPLOCK_COMBO,
    CAPSWORD_COMBO,
    LEFTARROW_COMBO,
    RIGHTARROW_COMBO,
    UPARROW_COMBO,
    DOWNARROW_COMBO,
    PAGEUP_COMBO,
    PAGEDN_COMBO,
    HOME_COMBO,
    END_COMBO,
    TEAMS_MUTE,
    TEAMS_VIDTOG,
    CHROME_COMBO,
    MYCOMPUTER_COMBO,
    CONTROLPAN_COMBO,
    EDGE_COMBO,
    VSCODE_COMBO,
    NOTEPADPP_COMBO,
    BOOT_LEFT,
    BOOT_RIGHT,
    ONE_SHOT_CONTROL,
    ONE_SHOT_ALT,
    ONE_SHOT_SHIFT,
    ONE_SHOT_GUI,
    ONE_SHOT_MEH,
    ONE_SHOT_HYPER,
    MOUSE_LEFT_CLICK,
    MOUSE_RIGHT_CLICK,
    MOUSE_MIDDLE_CLICK,
    COMBO_LENGTH
};

enum custom_keycodes {
    BROWSWEROPEN = SAFE_RANGE,
    CONTROLPAN,
    NOTEPADPP,
    MSEDGE,
    VSCODE,
    MYCOMPUTER,
    ONESHOT_SYM_LSHIFT,
    ONESHOT_SYM_RSHIFT,
    CUSTOM_LENGTH
};

// Functions for bilateral combos
bool is_left(uint16_t keycode);
bool is_right(uint16_t keycode);
bool is_left_mod(uint8_t mod_state);
bool is_right_mod(uint8_t mod_state);

//-------------------------------------------------------------------------------
// Layer 0 combos

// Characters

const uint16_t PROGMEM doubleq_combo[]  = {KC_D, KC_LCTRL_F, COMBO_END};
const uint16_t PROGMEM singleq_combo[]  = {KC_RCTRL_J, KC_K, COMBO_END};
const uint16_t PROGMEM lpar_combo[]     = {KC_C, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rpar_combo[]     = {KC_RALT_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM lbrace_combo[]   = {KC_X, KC_C, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rbrace_combo[]   = {KC_RALT_M, KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM lcurly_combo[]   = {KC_X, KC_LALT_V, COMBO_END};
const uint16_t PROGMEM rcurly_combo[]   = {KC_RALT_M, KC_DOT, COMBO_END};

//-------------------------------------------------------------------------------
// Layer control combos

const uint16_t PROGMEM apps_combo[]     = {KC_RGUI_Y, KC_U, KC_I, COMBO_END};
const uint16_t PROGMEM osl_apps_combo[] = {KC_RGUI_Y, KC_I, COMBO_END};

const uint16_t PROGMEM numb_combo[]     = {KC_RSHCTRL_H, KC_RCTRL_J, KC_K, COMBO_END};
const uint16_t PROGMEM osl_numb_combo[] = {KC_RSHCTRL_H, KC_K, COMBO_END};
const uint16_t PROGMEM osl_numb_lshift_combo[] = {KC_RSHCTRL_H, KC_RCTRL_J, COMBO_END};

const uint16_t PROGMEM func_combo[]     = {KC_N, KC_RALT_M, KC_COMM, COMBO_END};
const uint16_t PROGMEM osl_func_combo[] = {KC_N, KC_COMM, COMBO_END};

const uint16_t PROGMEM default_combo[]     = {KC_RCTRL_J, KC_K, KC_L, COMBO_END};

const uint16_t PROGMEM mouse_combo[]       = {KC_W, KC_E,  KC_R, KC_LGUI_T, COMBO_END};


//--------------------------------------------------------------------------------
// Behavioral combos

const uint16_t PROGMEM lesc_combo[]       = {KC_LCTRL_F, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM winclose_combo[]   = {KC_R, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM appclose_combo[]   = {KC_LALT_V, KC_B, COMBO_END};

const uint16_t PROGMEM del_combo[]        = {KC_D, KC_LSHCTRL_G, COMBO_END};

const uint16_t PROGMEM caplock_combo[]    = {KC_Z, KC_X, KC_C,  COMBO_END};
const uint16_t PROGMEM capsword_combo[]   = {KC_C, KC_B, COMBO_END};

const uint16_t PROGMEM leftarrow_combo[]  = {KC_D, KC_LCTRL_F, KC_LSHCTRL_G, COMBO_END};
const uint16_t PROGMEM rightarrow_combo[] = {KC_E, KC_R, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM uparrow_combo[]    = {KC_W, KC_E, KC_R, COMBO_END};
const uint16_t PROGMEM downarrow_combo[]  = {KC_S, KC_D, KC_LCTRL_F, COMBO_END};

const uint16_t PROGMEM pageup_combo[]     = {KC_LCTRL_F, KC_RCTRL_J, COMBO_END};
const uint16_t PROGMEM pagedn_combo[]     = {KC_LALT_V, KC_RALT_M, COMBO_END};
const uint16_t PROGMEM home_combo[]       = {KC_LSHCTRL_G, KC_RSHCTRL_H, COMBO_END};
const uint16_t PROGMEM end_combo[]        = {KC_B, KC_N, COMBO_END};

const uint16_t PROGMEM teams_mute[]       = {KC_R, KC_U, COMBO_END};
const uint16_t PROGMEM teams_vidtog[]     = {KC_LGUI_T, KC_RGUI_Y, COMBO_END};

// Macro Combos
const uint16_t PROGMEM chrome_combo[]     = {KC_C, KC_RSHCTRL_H, COMBO_END};
const uint16_t PROGMEM mycomputer_combo[] = {KC_C, KC_RGUI_Y, COMBO_END};
const uint16_t PROGMEM controlpan_combo[] = {KC_C, KC_N, COMBO_END};
const uint16_t PROGMEM edge_combo[]       = {KC_C, KC_RCTRL_J, COMBO_END};
const uint16_t PROGMEM vscode_combo[]     = {KC_C, KC_U, COMBO_END};
const uint16_t PROGMEM notepadpp_combo[]  = {KC_C, KC_RALT_M, COMBO_END};

// Boot combos
const uint16_t PROGMEM boot_left_combo[]  = {KC_Q, KC_LGUI_T, COMBO_END};
const uint16_t PROGMEM boot_right_combo[] = {KC_RGUI_Y, KC_P, COMBO_END};

// OSM Mods
const uint16_t PROGMEM osm_ctrl_combo[]  = {KC_D, KC_K, COMBO_END};
const uint16_t PROGMEM osm_alt_combo[]   = {KC_C, KC_COMM, COMBO_END};
const uint16_t PROGMEM osm_shift_combo[] = {KC_S, KC_L, COMBO_END};
const uint16_t PROGMEM osm_meh_combo[]   = {KC_X, KC_DOT, COMBO_END};
const uint16_t PROGMEM osm_hyper_combo[] = {KC_W, KC_O, COMBO_END};
const uint16_t PROGMEM osm_gui_combo[]   = {KC_E, KC_I, COMBO_END};

//Mouse combos
const uint16_t PROGMEM left_mouse_combo[]   = {KC_S, KC_LCTRL_F, COMBO_END};
const uint16_t PROGMEM right_mouse_combo[]  = {KC_W, KC_R, COMBO_END};
const uint16_t PROGMEM middle_mouse_combo[] = {KC_E, KC_LGUI_T, COMBO_END};

// End layer 0 combo definitions
//--------------------------------------------------------------------------------
// Combo assignments

combo_t key_combos[] = {

//------------- Symbol combos

[DOUBLEQ_COMBO]      = COMBO(doubleq_combo, KC_DQUO),
[SINGLEQ_COMBO]      = COMBO(singleq_combo, KC_QUOT),
[LPAR_COMBO]         = COMBO(lpar_combo, KC_LPRN),
[RPAR_COMBO]         = COMBO(rpar_combo, KC_RPRN),
[LBRACE_COMBO]       = COMBO(lbrace_combo, KC_LBRC),
[RBRACE_COMBO]       = COMBO(rbrace_combo, KC_RBRC),
[LCURLY_COMBO]       = COMBO(lcurly_combo, KC_LCBR),
[RCURLY_COMBO]       = COMBO(rcurly_combo, KC_RCBR),

//------------- Layer combos

[APP_COMBO]          = COMBO(apps_combo, TG(_APPCONTROL)),
[NUMB_COMBO]         = COMBO(numb_combo, TG(_NUMBSYM)),
[FUNC_COMBO]         = COMBO(func_combo, TG(_FUNCTION)),
[ONESHOT_SYM_COMBO]  = COMBO(osl_numb_combo, OSL(_NUMBSYM)),
[ONESHOT_SYM_LSHIFT_COMBO]  = COMBO(osl_numb_lshift_combo, ONESHOT_SYM_LSHIFT),
[ONESHOT_FUNC_COMBO] = COMBO(osl_func_combo, OSL(_FUNCTION)),
[ONESHOT_APP_COMBO]  = COMBO(osl_apps_combo, OSL(_APPCONTROL)),
[DEFAULT_COMBO]      = COMBO(default_combo, TO(_ALPHA)),
[MOUSE_COMBO]        = COMBO(mouse_combo, TG(_MOUSE)),

//------------- Extras

[LESC_COMBO]         = COMBO(lesc_combo, KC_ESC),
[DEL_COMBO]          = COMBO(del_combo, KC_DEL),
[WINCLOSE_COMBO]     = COMBO(winclose_combo, LCTL(KC_F4)),
[APPCLOSE_COMBO]     = COMBO(appclose_combo, LALT(KC_F4)),
[LEFTARROW_COMBO]    = COMBO(leftarrow_combo,KC_LEFT),
[RIGHTARROW_COMBO]   = COMBO(rightarrow_combo,KC_RIGHT),
[UPARROW_COMBO]      = COMBO(uparrow_combo, KC_UP),
[DOWNARROW_COMBO]    = COMBO(downarrow_combo, KC_DOWN),
[PAGEUP_COMBO]       = COMBO(pageup_combo, KC_PGUP),
[PAGEDN_COMBO]       = COMBO(pagedn_combo, KC_PGDN),
[HOME_COMBO]         = COMBO(home_combo, KC_HOME),
[END_COMBO]          = COMBO(end_combo, KC_END),

//------------- Boot combos

[BOOT_LEFT] = COMBO(boot_left_combo,QK_BOOT),
[BOOT_RIGHT] = COMBO(boot_right_combo,QK_BOOT),

//------------- Teams toggles

[TEAMS_MUTE]         = COMBO(teams_mute, RCS(KC_M)),
[TEAMS_VIDTOG]       = COMBO(teams_vidtog, RCS(KC_O)),

//------------- Cap combos

[CAPLOCK_COMBO]      = COMBO(caplock_combo, KC_CAPS),
[CAPSWORD_COMBO]     = COMBO(capsword_combo, CW_TOGG),

//------------- One shot modifiers

[ONE_SHOT_CONTROL] = COMBO(osm_ctrl_combo,  OSM(KC_LCTL)),
[ONE_SHOT_ALT]     = COMBO(osm_alt_combo,   OSM(KC_LALT)),
[ONE_SHOT_SHIFT]   = COMBO(osm_shift_combo, OSM(KC_LSFT)),
[ONE_SHOT_GUI]     = COMBO(osm_gui_combo,   OSM(KC_LGUI)),
[ONE_SHOT_HYPER]   = COMBO(osm_hyper_combo, OSM(KC_HYPR)),
[ONE_SHOT_MEH]     = COMBO(osm_meh_combo,   OSM(KC_MEH)),

//------------ Macro combos

[CHROME_COMBO]     = COMBO(chrome_combo, BROWSWEROPEN),
[MYCOMPUTER_COMBO] = COMBO(mycomputer_combo, MYCOMPUTER),
[CONTROLPAN_COMBO] = COMBO(controlpan_combo, CONTROLPAN),
[EDGE_COMBO]       = COMBO(edge_combo, MSEDGE),
[VSCODE_COMBO]     = COMBO(vscode_combo, VSCODE),
[NOTEPADPP_COMBO]  = COMBO(notepadpp_combo, NOTEPADPP),

// Mouse combos

[MOUSE_LEFT_CLICK]   = COMBO(left_mouse_combo, KC_MS_BTN1),
[MOUSE_RIGHT_CLICK]  = COMBO(right_mouse_combo, KC_MS_BTN2),
[MOUSE_MIDDLE_CLICK] = COMBO(middle_mouse_combo, KC_MS_BTN3),

};

// end combos
//-------------------------------------------------------------------------------

// Functions

bool get_permissive_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LSFT_T(KC_SPACE):
        case RSFT_T(KC_ENTER):
            // Immediately select the hold action when another key is pressed.
             return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
  switch (index) {
      case APP_COMBO:
      case FUNC_COMBO:
      case NUMB_COMBO:
      case ONESHOT_APP_COMBO:
      case ONESHOT_FUNC_COMBO:
      case ONESHOT_SYM_COMBO:
      case MOUSE_COMBO:
        return 400;
      case WINCLOSE_COMBO:
      case APPCLOSE_COMBO:
        return 300;
      default:
        return COMBO_TERM;
    }
}

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
            add_weak_mods(MOD_BIT(KC_LSFT));  // Apply shift to next key.
            return true;
        // Keycodes that continue Caps Word, without shifting.
        case KC_BSPC:
        case KC_DEL:
            return true;
        default:
            return false;  // Deactivate Caps Word.
    }
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_RALT_M:
        case KC_LALT_V:
            return 500;
        case KC_LGUI_T:
            return 600;
        case KC_RGUI_Y:
            return 750;
        default:
            return TAPPING_TERM;
    }
}


bool is_left(uint16_t keycode) {
    for (int i = 0; i < lf_keylist_size; i++) {
        if (keycode == lf_keylist[i]) {
            return true;
        }
    }
    return false;
}

bool is_right(uint16_t keycode) {
    for (int i = 0; i < rt_keylist_size; i++) {
        if (keycode == rt_keylist[i]) {
            return true;
        }
    }
    return false;
}


bool is_left_mod(uint8_t mod_state){
    if ((mod_state & MOD_BIT(KC_LALT)) ||
        (mod_state & MOD_BIT(KC_LSFT)) ||
        (mod_state & MOD_BIT(KC_LCTL)) ||
        (mod_state & MOD_BIT(KC_LGUI))) {
            return true;
        };

    return false;
}

bool is_right_mod(uint8_t mod_state){
    if ((mod_state & MOD_BIT(KC_RALT)) ||
        (mod_state & MOD_BIT(KC_RSFT)) ||
        (mod_state & MOD_BIT(KC_RCTL)) ||
        (mod_state & MOD_BIT(KC_RGUI))) {
            return true;
        };

    return false;
}

uint8_t mod_state;
bool duo_key_combo_left;
bool duo_key_combo_right;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {

    mod_state = get_mods();

    if (mod_state) {
        if (record->event.pressed) {
            if((is_left(keycode) && is_left_mod(mod_state)) ||
               (is_right(keycode) && is_right_mod(mod_state)))
               {
                    clear_mods();
               }
        }
    }

  switch (keycode) {

    case BROWSWEROPEN:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("CHROME\n");
        }
        break;
    case CONTROLPAN:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("Control\n");
        }
        break;
    case MYCOMPUTER:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("Shell:MyComputerFolder\n");
        }
        break;
    case VSCODE:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("CODE\n");
        }
        break;
    case MSEDGE:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("MICROSOFT-EDGE:\n");
        }
        break;
    case NOTEPADPP:
        if (record->event.pressed) {
                SEND_STRING(SS_LGUI("r"));
                wait_ms(250);
                SEND_STRING("NOTEPAD++\n");
        }
        break;
    case ONESHOT_SYM_RSHIFT:
        if (record->event.pressed) {
            set_oneshot_mods(MOD_RSFT);
            set_oneshot_layer(_NUMBSYM, ONESHOT_START);
            duo_key_combo_right = true;
        }
        break;
    case ONESHOT_SYM_LSHIFT:
        if (record->event.pressed) {
            set_oneshot_mods(MOD_LSFT);
            set_oneshot_layer(_NUMBSYM, ONESHOT_START);
            duo_key_combo_left = true;
        }
        break;
    default:
        if (duo_key_combo_left && !record->event.pressed && (keycode != ONESHOT_SYM_LSHIFT)) {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
          duo_key_combo_left = false;
        }
        if (duo_key_combo_right && !record->event.pressed && (keycode != ONESHOT_SYM_RSHIFT)) {
          clear_oneshot_layer_state(ONESHOT_PRESSED);
          duo_key_combo_right = false;
        }
      return true; // Process all other keycodes normally.
  }
  return true;
}

//-------------------------------------------------------------------------------
// begin layers

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*  Layer 0 Alpha
*   _____________________________________________________________________     _____________________________________________________________________
*  |      Q      |      W      |  E-HYPR     | R-ctrlalt   | T-gui       |   |  Y-gui      | U-ctrltalt  |   I-HYPR    |      O      |      P      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      A      |      S      |  D-MEH      | F-ctrl      | G-ctrlshift |   | H-ctrlshift |  J-ctrl     |   K-MEH     |      L      |      ;:     |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      Z      |      X      |      C      | V-alt       | B-SHALT     |   |   N-SHALT   |  M-ALT      |      ,<     |      .>     |      /?     |
*  '-----------------------------------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | TAB         |  SPACE      |   | ENTER       | BACKSPACE   |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_ALPHA] = LAYOUT_split_3x5_2(
    KC_Q,  KC_W,   KC_E,       KC_R, KC_LGUI_T,                 /*-*/ KC_RGUI_Y,          KC_U,             KC_I,         KC_O,    KC_P,
    KC_A,  KC_S,   KC_D,       KC_LCTRL_F,    KC_LSHCTRL_G,     /*-*/ KC_RSHCTRL_H,       KC_RCTRL_J,       KC_K,         KC_L,    KC_SCLN,
    KC_Z,  KC_X,   KC_C,       KC_LALT_V,     KC_B,             /*-*/ KC_N,               KC_RALT_M,        KC_COMM,      KC_DOT,  KC_SLSH,
                               KC_TAB,        KA_LSFP,          /*-*/ KA_RSFEN,           KC_BSPC
  ),

/*  Layer 1 Symbol
*   _____________________________________________________________________     _____________________________________________________________________
*  |      !      |      @      |      #      |      $      |      %      |   |      ^      |      &      |      *      |      (      |      )      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      1      |      2      |      3      |      4      |      5      |   |      6      |      7      |      8      |      9      |      0      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      ` ~    |      \ |    |      =+     |      -      |      _      |   |     ' "     |     ;:      |      , <    |      . >    |     / ?     |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_NUMBSYM] = LAYOUT_split_3x5_2(
    KC_EXLM,      KC_AT,            KC_HASH,       KC_DLR,        KC_PERC, /*-*/ KC_CIRC,      KC_AMPR,      KC_ASTR,   KC_LPRN,        KC_RPRN,
    KC_1,         KC_2,             KC_3,          KC_4,          KC_5,    /*-*/ KC_6,         KC_7,         KC_8,      KC_9,           KC_0,
    KC_GRV,       KC_BSLS,          KC_EQL,        KC_MINS,       KC_UNDS, /*-*/ KC_QUOT,      KC_SCLN,      KC_TRNS,   KC_TRNS,        KC_TRNS,
                                                   KC_TRNS,       KC_TRNS, /*-*/ KC_TRNS,      KC_TRNS
  ),

/*  Layer 2 Function
*   _____________________________________________________________________     _____________________________________________________________________
*  |  Play/pause |  Stop       |  Next       | Previous    |      F11    |   |      F12    |  Mute       | Vol Up      | Vol Dn      |  Lock       |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |      F1     |      F2     |      F3     |      F4     |      F5     |   |      F6     |      F7     |      F8     |      F9     |      F10    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |ctrl-alt-del |      GUI    |      ALT    |      CTRL   |      MEH    |   |      HYPER  |      CTRL   |      ALT    |      GUI    |ctrl-alt-del |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-------------|---------------------------'
*                                            |   KC_TRNS   |   KC_TRNS   |   |   KC_TRNS   |   KC_TRNS   |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_FUNCTION] = LAYOUT_split_3x5_2(
    KC_MPLY,      KC_MSTP, KC_MEDIA_NEXT_TRACK, KC_MEDIA_PREV_TRACK, KC_F11,  /*-*/  KC_F12,    KC_VOLU, KC_VOLD, KC_MUTE, KA_LOCK,
    KC_F1,        KC_F2,   KC_F3,               KC_F4,               KC_F5,   /*-*/  KC_F6,     KC_F7,   KC_F8,   KC_F9,   KC_F10,
    C(A(KC_DEL)), KC_LGUI, KC_LALT,             KC_LCTL,             KC_MEH,  /*-*/  KC_HYPR,   KC_RCTL, KC_RALT, KC_RGUI, C(A(KC_DEL)),
                                                KC_TRNS,             KC_TRNS, /*-*/  KC_TRNS,   KC_TRNS
  ),

/*  Layer 3 APPS AND CONTROL
*   _____________________________________________________________________     _____________________________________________________________________
*  |             |             | LINKEDIN    | OUTLOOK     | TEAMS       |   | FILEMNGR    | bright up   | bright dn   |             |             |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  QK_BOOT    |             | Controlpanel| POWERPOINT  | WORD        |   | KC_CALC     | TASK        | RUN         |             |  QK_BOOT    |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  |  QK_REBOOT  |             | Browser     | EMOJIS      | EXCEL       |   | SNIP        | CLIPBOARD   | MYCOMPUTER  |             |  QK_REBOOT  |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-----------------------------------------'
*                                            | KC_TRNS     | KC_TRNS     |   | KC_TRNS     | KC_TRNS     |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_APPCONTROL] = LAYOUT_split_3x5_2(
    KC_NO,     KC_NO, KA_EMOJIS,  KA_RUN,     KA_TEAMS, /*-*/ KA_POWERPT, KC_BRIU,    KC_BRID,     KC_NO, KC_NO,
    QK_BOOT,   KC_NO, CONTROLPAN, KA_FILEMGR, KA_WORD,  /*-*/ KC_CALC,    KA_TASKMGR, KA_LINKEDIN, KC_NO, QK_BOOT,
    QK_REBOOT, KC_NO, KA_CLIPBRD, KA_OUTLOOK, KA_EXCEL, /*-*/ KA_SNIP,    KC_NO,      MYCOMPUTER,  KC_NO, QK_REBOOT,
                                  KC_TRNS,    KC_TRNS,  /*-*/ KC_TRNS,    KC_TRNS
  ),


  /*  Layer 4 Mouse
*   _____________________________________________________________________     _____________________________________________________________________
*  | BOOKMRKMGR  | NEW-TAB     | LAST-TAB    | HOME PG     | UP          |   | PGUP        | WHEEL LEFT  | MOUSE UP    | WHEEL RIGHT | VOL UP      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | BOOKMARK    | LEFT BUTTON | MID BUTTON  | RIGHT BUTTON| DOWN        |   | PGDN        | MOUSE LEFT  | MOUSE DOWN  | MOUSE RIGHT | VOL DN      |
*  |-------------|-------------|-------------|-------------|-------------|   |-------------|-------------|-------------|-------------|-------------|
*  | BOOKMARKBAR | NEW-WIN     | INCOG       | LEFT        | RIGHT       |   | HOME        | WHEEL UP    | WHEEL DOWN  | END         | MUTE        |
*  '---------------------------|-------------|-------------|-------------|   |-------------|-------------|-----------------------------------------'
*                                            | TAB/CTRL    | KC_TRNS     |   | KC_TRNS     | BCKSP/CTRL  |
*                                            |_____________|_____________|   |_____________|_____________|
*/

  [_MOUSE] = LAYOUT_split_3x5_2(
    CR_BKMRKS,  CR_NTAB,    CR_NINCOG,  CR_HOME,    KC_UP,     /*-*/ KC_PGUP, MS_WHLL,    KC_MS_UP,      MS_WHLR,     KC_VOLU,
    CR_BKMRK,   KC_MS_BTN1, KC_MS_BTN3, KC_MS_BTN2, KC_DOWN,   /*-*/ KC_PGDN, KC_MS_LEFT, KC_MS_DOWN,    KC_MS_RIGHT, KC_VOLD,
    CR_BKBAR,   CR_NEWWIN,  CR_INGWIN,  KC_LEFT,    KC_RIGHT,  /*-*/ KC_HOME, MS_WHLU,    KC_MS_WH_DOWN, KC_END,      KC_MUTE,
                                        KC_TRNS,    KC_TRNS,   /*-*/ KC_TRNS, KC_TRNS
  )
};

//-------------------------------------------------------------------------------

#include QMK_KEYBOARD_H
extern tap_dance_action_t tap_dance_actions[];
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_MINUS));
			clear_keyboard();
        } else {
            SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_EQUAL));
			clear_keyboard();
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_MS_WH_UP);
        } else {
            tap_code(KC_MS_WH_DOWN);
        }
    }
    if (index == 2) {
        if (clockwise) {
            tap_code(KC_KB_VOLUME_UP);
        } else {
            tap_code(KC_KB_VOLUME_DOWN);
        }
    } else if (index == 3) {
		if (clockwise) {
            tap_code(KC_MS_WH_RIGHT);
        } else {
            tap_code(KC_MS_WH_LEFT);
        }
    }
    return false;
}

enum layer_names {
    _QWERTY,
    _CUSTOM,
    _NUMS_AND_NAV,
    _DOUBLE_TROUBLE,
	_OTRO,
	_SPECIAL
};
enum custom_keycodes {
	VSCODE_BUSCAR = SAFE_RANGE,
	SYSTEM_MOVE_SCREEN_LEFT,
	SYSTEM_MOVE_SCREEN_RIGHT,
	MISSION_CONTROL,
	SPOTLIGHT_SEARCH,
	CONTROL_C,
	COMMAND_Z_INVERSE,
	TAB_INVERSE,
	GLOBAL_COMMAND_N,
	GLOBAL_COMMAND_T,
	GLOBAL_COMMAND_R,
	GLOBAL_COMMAND_F,
	GLOBAL_COMMAND_Z,
	GLOBAL_COMMAND_C,
	GLOBAL_COMMAND_V,
	GLOBAL_COMMAND_D,
	GLOBAL_COMMAND_X,
	GLOBAL_COMMAND_W,
	GLOBAL_COMMAND_S,
	GLOBAL_COMMAND_A,
	GLOBAL_COMMAND_Q,
	GLOBAL_COMMAND_K,
	GLOBAL_COMMAND_1,
	GLOBAL_COMMAND_2,
	GLOBAL_COMMAND_3,
	GLOBAL_COMMAND_4,
	GLOBAL_COMMAND_5,
	GLOBAL_COMMAND_6,
	GLOBAL_COMMAND_7,
	GLOBAL_COMMAND_8,
	GLOBAL_COMMAND_9,
	GLOBAL_COMMAND_UP,
	GLOBAL_COMMAND_DOWN,
	GLOBAL_COMMAND_ENTER,
	VSCODE_MOVE_WORD_LEFT,
	VSCODE_MOVE_WORD_RIGHT,
	VSCODE_MOVE_WORD_ARROW,
	VSCODE_SEARCH_IN_FILES,
	VSCODE_PHP_ARROW,
	VSCODE_COMMENT,
	VSCODE_0,
	VSCODE_1,
	VSCODE_2,
	VSCODE_3,
	VSCODE_4,
	VSCODE_5,
	VSCODE_SHIT_SHIT,
	SCREENSHOT_SELECTION,
	SCREENSHOT_SELECTION_LAYOUT,
	SCREENSHOT_FULL,
	VM_URL,
	GIT_CHECKOUT_DOT,
	GIT_PUSH_FORCE,
	GIT_COMMIT,
	GIT_YES,
	GIT_NO,
	GIT_STATUS,
	GIT_ADD_P
};
enum {
    CT_CLN,
};
typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	tap_dance_action_t *action;
	switch (keycode) {
		case TD(CT_CLN):
            action = &tap_dance_actions[TD_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
        }
		break;
		case SYSTEM_MOVE_SCREEN_LEFT:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_LEFT));
			} else {
				clear_keyboard();
			}
		break;
		case SYSTEM_MOVE_SCREEN_RIGHT:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_RIGHT));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_N:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_N));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_T:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_T));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_R:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_R));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_F:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_F));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_Z:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_Z));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_W:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_W));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_C:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_C));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_V:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_V));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_S:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_S));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_X:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_X));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_Q:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_Q));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_D:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_D));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_UP:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_UP));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_DOWN:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_DOWN));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_A:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_A));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_K:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_K));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_1:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_1));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_2:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_2));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_3:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_3));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_4:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_4));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_5:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_5));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_6:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_6));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_7:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_7));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_8:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_8));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_9:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_9));
			} else {
				clear_keyboard();
			}
		break;
		case GLOBAL_COMMAND_ENTER:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_ENTER));
			} else {
				clear_keyboard();
			}
		break;
		case MISSION_CONTROL:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_UP));
			} else {
				clear_keyboard();
			}
		break;
		case SPOTLIGHT_SEARCH:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_SPACE));
			} else {
				clear_keyboard();
			}
		break;
		case COMMAND_Z_INVERSE:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_Z))));
			} else {
				clear_keyboard();
			}
		break;
		case TAB_INVERSE:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_TAB));
			} else {
				clear_keyboard();
			}
		break;
		case CONTROL_C:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_CTRL) SS_TAP(X_C));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_BUSCAR:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_DOWN(X_LEFT_SHIFT) SS_TAP(X_F));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_MOVE_WORD_LEFT:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_LEFT))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_MOVE_WORD_RIGHT:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_RIGHT))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_MOVE_WORD_ARROW:
			if (record->event.pressed) {
				SEND_STRING("->");
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_SEARCH_IN_FILES:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_F))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_PHP_ARROW:
			if (record->event.pressed) {
				SEND_STRING("->");
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_COMMENT:
			if (record->event.pressed) {
				SEND_STRING(SS_DOWN(X_LEFT_GUI) SS_TAP(X_SLASH));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_1:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_1))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_2:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_2))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_3:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_3))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_4:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_4))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_5:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_5))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_0:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LOPT(SS_TAP(X_0))));
			} else {
				clear_keyboard();
			}
		break;
		case VSCODE_SHIT_SHIT:
			if (record->event.pressed) {
				SEND_STRING(SS_TAP(X_LEFT_SHIFT) SS_TAP(X_LEFT_SHIFT));
			} else {
				clear_keyboard();
			}
		break;
		case SCREENSHOT_SELECTION:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_4))));
			} else {
				clear_keyboard();
			}
		break;
		case SCREENSHOT_SELECTION_LAYOUT:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_5))));
			} else {
				clear_keyboard();
			}
		break;
		case SCREENSHOT_FULL:
			if (record->event.pressed) {
				SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_3))));
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_ADD_P:
			if (record->event.pressed) {
				SEND_STRING("git add -p ");
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_CHECKOUT_DOT:
			if (record->event.pressed) {
				SEND_STRING("gc -- .");
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_PUSH_FORCE:
			if (record->event.pressed) {
				SEND_STRING("git push origin -f ");
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_COMMIT:
			if (record->event.pressed) {
				SEND_STRING("git commit -m \"\"" SS_TAP(X_LEFT));
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_YES:
			if (record->event.pressed) {
				SEND_STRING("y" SS_TAP(X_ENTER));
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_NO:
			if (record->event.pressed) {
				SEND_STRING("n" SS_TAP(X_ENTER));
			} else {
				clear_keyboard();
			}
		break;
		case  GIT_STATUS:
			if (record->event.pressed) {
				SEND_STRING("gst" SS_TAP(X_ENTER));
			} else {
				clear_keyboard();
			}
		break;
		case  VM_URL:
			if (record->event.pressed) {
				SEND_STRING("jcarrillo.vm.dev.etsycloud.com");
			} else {
				clear_keyboard();
			}
		break;
	}
	return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
[_QWERTY] = LAYOUT(
	KC_Q,				KC_W,				KC_E,				KC_R,				KC_T,			KC_Y,	KC_U,				KC_I,				KC_O,				KC_P,
	KC_A,	 			KC_S,				KC_D,				KC_F,				KC_G,			KC_H,	KC_J,				KC_K,				KC_L,				KC_SCLN,
	KC_Z,				KC_X,		KC_C,KC_V,				KC_B,			KC_N,	KC_M,				KC_COMM,			KC_DOT,				KC_SLSH,
	KC_MEDIA_PREV_TRACK,	KC_LEFT_GUI,		KC_LEFT_SHIFT,		MO(1),	MISSION_CONTROL,		KC_MEDIA_PLAY_PAUSE,		LT(2, KC_SPACE),				OSL(5),			KC_CAPS_LOCK,		KC_MEDIA_NEXT_TRACK
),
[_CUSTOM] = LAYOUT(
	KC_ESCAPE, GLOBAL_COMMAND_W, SYSTEM_MOVE_SCREEN_LEFT, SYSTEM_MOVE_SCREEN_RIGHT,	GLOBAL_COMMAND_T,	SPOTLIGHT_SEARCH,	KC_MINUS,	KC_QUOT, KC_DOUBLE_QUOTE,	GLOBAL_COMMAND_ENTER,
	GLOBAL_COMMAND_A, GLOBAL_COMMAND_S,	GLOBAL_COMMAND_D, KC_BACKSPACE,	GLOBAL_COMMAND_F, 				KC_ENTER, GLOBAL_COMMAND_R,	GLOBAL_COMMAND_K, CONTROL_C,	KC_COLN,
	GLOBAL_COMMAND_Z, GLOBAL_COMMAND_X,	GLOBAL_COMMAND_C, GLOBAL_COMMAND_V, GLOBAL_COMMAND_Q,	KC_LEFT_PAREN, KC_RIGHT_PAREN,	KC_LEFT_BRACKET, KC_RIGHT_BRACKET,	VSCODE_COMMENT,
	KC_NO,	KC_NO,	KC_NO,	KC_NO,	KC_NO,			KC_NO,	MO(3),	KC_NO,	KC_NO,	KC_NO
),
[_NUMS_AND_NAV] = LAYOUT(
	KC_1, KC_2, KC_3, KC_4, KC_5,				KC_6, KC_7, KC_8, KC_9, KC_0,
	KC_NO, KC_NO, KC_NO, KC_BACKSPACE, KC_NO, 			KC_ENTER, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT,
	KC_TAB, KC_PIPE, KC_CIRCUMFLEX, KC_GRAVE, KC_NO,			KC_EXLM, KC_QUES, KC_QUOT, KC_UNDS, KC_KP_PLUS,
	KC_NO, KC_NO, KC_NO, MO(4), KC_NO, 			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
[_DOUBLE_TROUBLE] = LAYOUT(
	GLOBAL_COMMAND_1,	GLOBAL_COMMAND_2,	GLOBAL_COMMAND_3,	GLOBAL_COMMAND_4,	GLOBAL_COMMAND_5, GLOBAL_COMMAND_6,	GLOBAL_COMMAND_7,	GLOBAL_COMMAND_8, GLOBAL_COMMAND_9, KC_NO,
	KC_NO, KC_NO, KC_NO, KC_BACKSPACE, VSCODE_SEARCH_IN_FILES,				VSCODE_PHP_ARROW, VSCODE_MOVE_WORD_LEFT, GLOBAL_COMMAND_DOWN, GLOBAL_COMMAND_UP, VSCODE_MOVE_WORD_RIGHT,
	COMMAND_Z_INVERSE, KC_NO, KC_NO, KC_NO,	KC_NO, 			KC_NO, KC_NO, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE, KC_NO,
	KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO, KC_NO, KC_SPC,		KC_NO,	KC_NO,	KC_NO
),
[_OTRO] = LAYOUT(
	KC_EXCLAIM, KC_AT, KC_HASH, KC_DOLLAR, KC_PERCENT,			KC_CIRCUMFLEX, KC_AMPERSAND, KC_ASTERISK, KC_LEFT_PAREN,	KC_RIGHT_PAREN,
	KC_NO, KC_NO, KC_NO, KC_BACKSPACE, KC_NO, 			KC_NO, VSCODE_MOVE_WORD_LEFT, GLOBAL_COMMAND_DOWN, GLOBAL_COMMAND_UP, VSCODE_MOVE_WORD_RIGHT,
	TAB_INVERSE, KC_NO, GLOBAL_COMMAND_C, GLOBAL_COMMAND_V, KC_NO,			KC_NO, KC_NO, KC_NO, KC_NO,	KC_EQUAL,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 			KC_NO, MO(2), KC_NO, KC_NO, KC_NO
),
[_SPECIAL] = LAYOUT(
	SCREENSHOT_SELECTION, SCREENSHOT_SELECTION_LAYOUT, SCREENSHOT_FULL, KC_NO, VSCODE_SHIT_SHIT,			GIT_YES, GIT_STATUS, GIT_NO, KC_NO,	VSCODE_0,
	VSCODE_1, VSCODE_2, VSCODE_3, VSCODE_4, VSCODE_5, 			GIT_ADD_P, GIT_COMMIT, GIT_PUSH_FORCE, VM_URL, GIT_CHECKOUT_DOT,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,			KC_NO, KC_NO, KC_NO, KC_NO,	KC_NO,
	KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, 			KC_NO, KC_NO, KC_NO, KC_NO, KC_NO
),
};

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (state->pressed) {
        if (state->count == 1
#ifndef PERMISSIVE_HOLD
            && !state->interrupted
#endif
        ) {
            register_code16(tap_hold->hold);
            tap_hold->held = tap_hold->hold;
        } else {
            register_code16(tap_hold->tap);
            tap_hold->held = tap_hold->tap;
        }
    }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
    tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

    if (tap_hold->held) {
        unregister_code16(tap_hold->held);
        tap_hold->held = 0;
    }
}
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold) \
    { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }
tap_dance_action_t tap_dance_actions[] = {
    [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_CAPS_LOCK, KC_LEFT_SHIFT),
};


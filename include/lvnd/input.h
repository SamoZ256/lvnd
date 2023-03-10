#ifndef LVND_INPUT_H
#define LVND_INPUT_H

typedef struct LvndInput {
    long long beginTime;
} LvndInput;

//---------------- LvndKey ----------------
#define LVND_TOTAL_KEY_COUNT 121

typedef enum LvndKey {
    LVND_KEY_SPACE,
    LVND_KEY_APOSTROPHE,
    LVND_KEY_COMMA,
    LVND_KEY_MINUS,
    LVND_KEY_PERIOD,
    LVND_KEY_SLASH,
    LVND_KEY_0,
    LVND_KEY_1,
    LVND_KEY_2,
    LVND_KEY_3,
    LVND_KEY_4,
    LVND_KEY_5,
    LVND_KEY_6,
    LVND_KEY_7,
    LVND_KEY_8,
    LVND_KEY_9,
    LVND_KEY_SEMICOLON,
    LVND_KEY_EQUAL,
    LVND_KEY_A,
    LVND_KEY_B,
    LVND_KEY_C,
    LVND_KEY_D,
    LVND_KEY_E,
    LVND_KEY_F,
    LVND_KEY_G,
    LVND_KEY_H,
    LVND_KEY_I,
    LVND_KEY_J,
    LVND_KEY_K,
    LVND_KEY_L,
    LVND_KEY_M,
    LVND_KEY_N,
    LVND_KEY_O,
    LVND_KEY_P,
    LVND_KEY_Q,
    LVND_KEY_R,
    LVND_KEY_S,
    LVND_KEY_T,
    LVND_KEY_U,
    LVND_KEY_V,
    LVND_KEY_W,
    LVND_KEY_X,
    LVND_KEY_Y,
    LVND_KEY_Z,
    LVND_KEY_LEFT_BRACKET,
    LVND_KEY_BACKSLASH,
    LVND_KEY_RIGHT_BRACKET,
    LVND_KEY_GRAVE_ACCENT,
    LVND_KEY_WORLD_1,
    LVND_KEY_WORLD_2,

    LVND_KEY_ESCAPE,
    LVND_KEY_ENTER,
    LVND_KEY_TAB,
    LVND_KEY_BACKSPACE,
    LVND_KEY_INSERT,
    LVND_KEY_DELETE,
    LVND_KEY_RIGHT,
    LVND_KEY_LEFT,
    LVND_KEY_DOWN,
    LVND_KEY_UP,
    LVND_KEY_PAGE_UP,
    LVND_KEY_PAGE_DOWN,
    LVND_KEY_HOME,
    LVND_KEY_END,
    LVND_KEY_CAPS_LOCK,
    LVND_KEY_SCROLL_LOCK,
    LVND_KEY_NUM_LOCK,
    LVND_KEY_PRINT_SCREEN,
    LVND_KEY_PAUSE,
    LVND_KEY_F1,
    LVND_KEY_F2,
    LVND_KEY_F3,
    LVND_KEY_F4,
    LVND_KEY_F5,
    LVND_KEY_F6,
    LVND_KEY_F7,
    LVND_KEY_F8,
    LVND_KEY_F9,
    LVND_KEY_F10,
    LVND_KEY_F11,
    LVND_KEY_F12,
    LVND_KEY_F13,
    LVND_KEY_F14,
    LVND_KEY_F15,
    LVND_KEY_F16,
    LVND_KEY_F17,
    LVND_KEY_F18,
    LVND_KEY_F19,
    LVND_KEY_F20,
    LVND_KEY_F21,
    LVND_KEY_F22,
    LVND_KEY_F23,
    LVND_KEY_F24,
    LVND_KEY_F25,
    LVND_KEY_KP_0,
    LVND_KEY_KP_1,
    LVND_KEY_KP_2,
    LVND_KEY_KP_3,
    LVND_KEY_KP_4,
    LVND_KEY_KP_5,
    LVND_KEY_KP_6,
    LVND_KEY_KP_7,
    LVND_KEY_KP_8,
    LVND_KEY_KP_9,
    LVND_KEY_KP_DECIMAL,
    LVND_KEY_KP_DIVIDE,
    LVND_KEY_KP_MULTIPLY,
    LVND_KEY_KP_SUBTRACT,
    LVND_KEY_KP_ADD,
    LVND_KEY_KP_ENTER,
    LVND_KEY_KP_EQUAL,
    LVND_KEY_LEFT_SHIFT,
    LVND_KEY_LEFT_CONTROL,
    LVND_KEY_LEFT_ALT,
    LVND_KEY_LEFT_SUPER,
    LVND_KEY_RIGHT_SHIFT,
    LVND_KEY_RIGHT_CONTROL,
    LVND_KEY_RIGHT_ALT,
    LVND_KEY_RIGHT_SUPER,
    LVND_KEY_MENU,

    LVND_KEY_UNDEFINED
} LvndKey;

//---------------- LvndModifier ----------------
#define LVND_TOTAL_MODIFIER_COUNT 9

typedef enum LvndModifier {
    LVND_MODIFIER_SHIFT         = 0b1,
    LVND_MODIFIER_ALT           = 0b10,
    LVND_MODIFIER_SUPER         = 0b100,
    LVND_MODIFIER_CONTROL       = 0b1000,
    LVND_MODIFIER_CAPS_LOCK     = 0b10000
} LvndModifier;

//---------------- LvndMouseButton ----------------
#define LVND_TOTAL_MOUSE_BUTTON_COUNT 3

typedef enum LvndMouseButton {
    LVND_MOUSE_BUTTON_LEFT,
    LVND_MOUSE_BUTTON_RIGHT,
    LVND_MOUSE_BUTTON_MIDDLE
} LvndMouseButton;

//---------------- LvndState ----------------
typedef enum LvndState {
    LVND_STATE_PRESSED,
    LVND_STATE_RELEASED
} LvndState;

//---------------- LvndCursorState ----------------
typedef enum LvndCursorState {
    LVND_CURSOR_STATE_NORMAL,
    LVND_CURSOR_STATE_HIDDEN
} LvndCursorState;

double _lvndGetTime();

#endif

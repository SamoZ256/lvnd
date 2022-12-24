#ifndef LVND_CALLBACKS_H
#define LVND_CALLBACKS_H

#include "window.h"

//Callbacks
typedef void (*LvndWindowResizeCallbackFun)(LvndWindow* window, uint16_t width, uint16_t height);

typedef void (*LvndWindowFocusCallbackFun)(LvndWindow* window, bool focused);

typedef void (*LvndCursorEnteredCallbackFun)(LvndWindow* window, bool entered);

typedef void (*LvndCursorMovedCallbackFun)(LvndWindow* window, int32_t xpos, int32_t ypos);

typedef void (*LvndMouseButtonPressedCallbackFun)(LvndWindow* window, LvndMouseButton mouseButton, LvndState state);

typedef void (*LvndScrollCallbackFun)(LvndWindow* window, double xoffset, double yoffset);

typedef void (*LvndKeyPressedCallbackFun)(LvndWindow* window, LvndKey key, LvndState state);

//Callback interface
LvndWindowResizeCallbackFun _lvndSetWindowResizeCallback(LvndWindow* window, LvndWindowResizeCallbackFun callback);

LvndWindowFocusCallbackFun _lvndSetWindowFocusCallback(LvndWindow* window, LvndWindowFocusCallbackFun callback);

LvndCursorEnteredCallbackFun _lvndSetCursorEnteredCallback(LvndWindow* window, LvndCursorEnteredCallbackFun callback);

LvndCursorMovedCallbackFun _lvndSetCursorMovedCallback(LvndWindow* window, LvndCursorMovedCallbackFun callback);

LvndMouseButtonPressedCallbackFun _lvndSetMouseButtonPressedCallback(LvndWindow* window, LvndMouseButtonPressedCallbackFun callback);

LvndScrollCallbackFun _lvndSetScrollCallback(LvndWindow* window, LvndScrollCallbackFun callback);

LvndKeyPressedCallbackFun _lvndSetKeyPressedCallback(LvndWindow* window, LvndKeyPressedCallbackFun callback);

#endif

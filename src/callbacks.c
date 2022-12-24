#include "lvnd/callbacks.h"

//Callback interface
LvndWindowResizeCallbackFun _lvndSetWindowResizeCallback(LvndWindow* window, LvndWindowResizeCallbackFun callback) {
    LvndWindowResizeCallbackFun prevCallback = window->callbacks.windowResizeCallback;
    window->callbacks.windowResizeCallback = callback;

    return prevCallback;
}

LvndWindowFocusCallbackFun _lvndSetWindowFocusCallback(LvndWindow* window, LvndWindowFocusCallbackFun callback) {
    LvndWindowFocusCallbackFun prevCallback = window->callbacks.windowFocusCallback;
    window->callbacks.windowFocusCallback = callback;

    return prevCallback;
}

LvndCursorEnteredCallbackFun _lvndSetCursorEnteredCallback(LvndWindow* window, LvndCursorEnteredCallbackFun callback) {
    LvndCursorEnteredCallbackFun prevCallback = window->callbacks.cursorEnteredCallback;
    window->callbacks.cursorEnteredCallback = callback;

    return prevCallback;
}

LvndCursorMovedCallbackFun _lvndSetCursorMovedCallback(LvndWindow* window, LvndCursorMovedCallbackFun callback) {
    LvndCursorMovedCallbackFun prevCallback = window->callbacks.cursorMovedCallback;
    window->callbacks.cursorMovedCallback = callback;

    return prevCallback;
}

LvndMouseButtonPressedCallbackFun _lvndSetMouseButtonPressedCallback(LvndWindow* window, LvndMouseButtonPressedCallbackFun callback) {
    LvndMouseButtonPressedCallbackFun prevCallback = window->callbacks.mouseButtonPressedCallback;
    window->callbacks.mouseButtonPressedCallback = callback;

    return prevCallback;
}

LvndScrollCallbackFun _lvndSetScrollCallback(LvndWindow* window, LvndScrollCallbackFun callback) {
    LvndScrollCallbackFun prevCallback = window->callbacks.scrollCallback;
    window->callbacks.scrollCallback = callback;

    return prevCallback;
}

LvndKeyPressedCallbackFun _lvndSetKeyPressedCallback(LvndWindow* window, LvndKeyPressedCallbackFun callback) {
    LvndKeyPressedCallbackFun prevCallback = window->callbacks.keyPressedCallback;
    window->callbacks.keyPressedCallback = callback;

    return prevCallback;
}

#include "lvnd/window.h"

#include <stdlib.h>

#include "lvnd/context.h"

#ifdef LVND_PLATFORM_COCOA
#include "lvnd/cocoa/cocoa_window.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "lvnd/uikit/uikit_window.h"
#elif defined(LVND_PLATFORM_X11)
#include "lvnd/x11/x11_window.h"
#elif defined(LVND_PLATFORM_WAYLAND)
#include "lvnd/wayland/wayland_window.h"
#elif defined(LVND_PLATFORM_WIN32)
#include "lvnd/win32/win32_window.h"
#endif

LvndWindow* _lvndCreateWindow(uint16_t width, uint16_t height, const char* title) {
    LvndWindow* window = (LvndWindow*)malloc(sizeof(LvndWindow));
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndCreateWindow(window, width, height, title);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndCreateWindow(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndCreateWindow(window, width, height, title);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndCreateWindow(window, width, height, title);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndCreateWindow(window, width, height, title);
#endif
    window->contextInitialized = false;

    window->userPtr = NULL;
    window->width = width;
    window->height = height;
    window->isOpen = true;

    //Inputs
    for (uint16_t i = 0; i < LVND_TOTAL_KEY_COUNT; i++)
        window->keys[i] = LVND_STATE_RELEASED;
    for (uint16_t i = 0; i < LVND_TOTAL_MOUSE_BUTTON_COUNT; i++)
        window->mouseButtons[i] = LVND_STATE_RELEASED;
    window->modifiers = 0;
    
    window->mouseX = 0;
    window->mouseY = 0;

    window->cursorState = LVND_CURSOR_STATE_NORMAL;

    //Callbacks
    window->callbacks.windowResizeCallback = NULL;
    window->callbacks.windowFocusCallback = NULL;
    window->callbacks.cursorEnteredCallback = NULL;
    window->callbacks.cursorMovedCallback = NULL;
    window->callbacks.mouseButtonPressedCallback = NULL;
    window->callbacks.scrollCallback = NULL;
    window->callbacks.keyPressedCallback = NULL;

    //Setting as last bound
    g_lvndContext.lastBoundWindow = window;

    return window;
}

void _lvndDestroyWindow(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndDestroyWindow(window);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndDestroyWindow(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndDestroyWindow(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndDestroyWindow(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndDestroyWindow(window);
#endif
    free(window);
}

void _lvndPollEvents(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndPollEvents();
#elif defined(LVND_PLATFORM_X11)
    x11_lvndPollEvents(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndPollEvents(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndPollEvents(window);
#endif
}

bool _lvndWindowIsOpen(LvndWindow* window) {
    return window->isOpen;
}

void _lvndSetWindowTitle(LvndWindow* window, const char* title) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndSetWindowTitle(window, title);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndSetWindowTitle(window, title);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndSetWindowTitle(window, title);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndSetWindowTitle(window, title);
#endif
}

void _lvndGetWindowSize(LvndWindow* window, uint16_t* width, uint16_t* height) {
    *width = window->width;
    *height = window->height;
}

void _lvndWindowGetFramebufferSize(LvndWindow* window, uint16_t* width, uint16_t* height) {
    *width = window->framebufferWidth;
    *height = window->framebufferHeight;
}

void _lvndWindowGetFramebufferScale(LvndWindow* window, float* xscale, float* yscale) {
    *xscale = window->framebufferScaleX;
    *yscale = window->framebufferScaleY;
}

LvndState _lvndGetKeyState(LvndWindow* window, LvndKey key) {
    return window->keys[key];
}

LvndState _lvndGetMouseButtonState(LvndWindow* window, LvndMouseButton mouseButton) {
    return window->mouseButtons[mouseButton];
}

void _lvndGetCursorPosition(LvndWindow* window, int32_t* mouseX, int32_t* mouseY) {
    *mouseX = window->mouseX;
    *mouseY = window->mouseY;
}

void _lvndSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndSetCursorPosition(window, mouseX, mouseY);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndSetCursorPosition(window, mouseX, mouseY);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndSetCursorPosition(window, mouseX, mouseY);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndSetCursorPosition(window, mouseX, mouseY);
#endif
}

void _lvndSetCursorState(LvndWindow* window, LvndCursorState state) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndSetCursorState(window, state);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndSetCursorState(window, state);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndSetCursorState(window, state);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndSetCursorState(window, state);
#endif
}

void _lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndSetWindowFullscreenMode(window, fullscreen);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndSetWindowFullscreenMode(window, fullscreen);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndSetWindowFullscreenMode(window, fullscreen);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndSetWindowFullscreenMode(window, fullscreen);
#endif
}

bool _lvndGetModifier(LvndWindow* window, LvndModifier modifier) {
    return window->modifiers & modifier;
}

//Crosss-platform main loop
int _lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void)) {
#ifdef LVND_PLATFORM_COCOA
    return cocoa_lvndMainLoop(window, start, updateFrame);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndMainLoop(window, start, updateFrame);
#elif defined(LVND_PLATFORM_X11)
    return x11_lvndMainLoop(window, start, updateFrame);
#elif defined(LVND_PLATFORM_WAYLAND)
    return wayland_lvndMainLoop(window, start, updateFrame);
#elif defined(LVND_PLATFORM_WIN32)
    return win32_lvndMainLoop(window, start, updateFrame);
#endif
}

//User pointer
void _lvndSetWindowUserPointer(LvndWindow* window, void* userPtr) {
    window->userPtr = userPtr;
}

void* _lvndGetWindowUserPointer(LvndWindow* window) {
    return window->userPtr;
}

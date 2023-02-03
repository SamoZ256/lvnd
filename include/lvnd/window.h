#ifndef LVND_WINDOW_H
#define LVND_WINDOW_H

#include <stdint.h>
#include <stdbool.h>
#include <assert.h>

#include "common.h"

#ifdef LVND_PLATFORM_COCOA
#include "cocoa/cocoa_handle.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "uikit/uikit_handle.h"
#elif defined(LVND_PLATFORM_X11)
#include "x11/x11_handle.h"
#elif defined(LVND_PLATFORM_WAYLAND)
#include "wayland/wayland_handle.h"
#elif defined(LVND_PLATFORM_WIN32)
#include "win32/win32_handle.h"
#endif

#include "menu_bar.h"
#include "input.h"

//Window
typedef struct LvndWindow {
#ifdef LVND_PLATFORM_COCOA
    Cocoa_LvndWindowHandle* handle;
#elif defined(LVND_PLATFORM_UIKIT)
    UIKit_LvndWindowHandle* handle;
#elif defined(LVND_PLATFORM_X11)
    X11_LvndWindowHandle* handle;
#elif defined(LVND_PLATFORM_WAYLAND)
    Wayland_LvndWindowHandle* handle;
#elif defined(LVND_PLATFORM_WIN32)
    Win32_LvndWindowHandle* handle;
#endif
    bool contextInitialized;

    void* userPtr;

    struct LvndCallbacks {
        void (*windowResizeCallback)(struct LvndWindow*, uint16_t, uint16_t);
        void (*windowFocusCallback)(struct LvndWindow*, bool);
        void (*cursorEnteredCallback)(struct LvndWindow*, bool);
        void (*cursorMovedCallback)(struct LvndWindow*, int32_t, int32_t);
        void (*mouseButtonPressedCallback)(struct LvndWindow*, LvndMouseButton, LvndState);
        void (*scrollCallback)(struct LvndWindow*, double, double);
        void (*keyPressedCallback)(struct LvndWindow*, LvndKey, LvndState);
        void (*charCallback)(struct LvndWindow*, uint16_t);
    } callbacks;

    uint16_t width, height;
    uint16_t framebufferWidth, framebufferHeight;
    float framebufferScaleX, framebufferScaleY;

    bool isOpen;
    bool isMaximized;

    //Input states
    LvndState keys[LVND_TOTAL_KEY_COUNT];// = {LVND_STATE_RELEASED};
    LvndState mouseButtons[LVND_TOTAL_MOUSE_BUTTON_COUNT];// = {LVND_STATE_RELEASED};
    uint16_t modifiers;

    int32_t mouseX, mouseY;
    LvndCursorState cursorState;
} LvndWindow;

LvndWindow* _lvndCreateWindow(uint16_t width, uint16_t height, const char* title);

void _lvndDestroyWindow(LvndWindow* window);

void _lvndPollEvents(LvndWindow* window);

bool _lvndWindowIsOpen(LvndWindow* window);

void _lvndSetWindowTitle(LvndWindow* window, const char* title);

void _lvndGetWindowSize(LvndWindow* window, uint16_t* width, uint16_t* height);

void _lvndWindowGetFramebufferSize(LvndWindow* window, uint16_t* width, uint16_t* height);

void _lvndWindowGetFramebufferScale(LvndWindow* window, float* xscale, float* yscale);

LvndState _lvndGetKeyState(LvndWindow* window, LvndKey key);

LvndState _lvndGetMouseButtonState(LvndWindow* window, LvndMouseButton mouseButton);

void _lvndGetCursorPosition(LvndWindow* window, int32_t* mouseX, int32_t* mouseY);

void _lvndSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY);

void _lvndSetCursorState(LvndWindow* window, LvndCursorState state);

void _lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen);

bool _lvndGetModifier(LvndWindow* window, LvndModifier modifier);

//Crosss-platform main loop
int _lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void));

//User pointer
void _lvndSetWindowUserPointer(LvndWindow* window, void* userPtr);

void* _lvndGetWindowUserPointer(LvndWindow* window);

#endif

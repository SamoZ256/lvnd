#include "lvnd/opengl/opengl.h"

#ifdef __MACOS__
#include "lvnd/cocoa/opengl/cocoa_opengl.h"
#elif defined(__IOS__)
#include "lvnd/uikit/opengl/uikit_opengl.h"
#elif defined(__LINUX__)
#include "lvnd/x11/opengl/x11_opengl.h"
#endif

void _lvndOpenGLCreateContext(LvndWindow* window) {
#ifdef __MACOS__
    cocoa_lvndOpenGLCreateContext(window);
#elif defined(__IOS__)
    uikit_lvndOpenGLCreateContext(window);
#elif defined(__LINUX__)
    x11_lvndOpenGLCreateContext(window);
#endif
    window->contextInitialized = true;
}

void _lvndOpenGLDestroyContext(LvndWindow* window) {
#ifdef __MACOS__
    cocoa_lvndOpenGLDestroyContext(window);
#elif defined(__IOS__)
    uikit_lvndOpenGLDestroyContext(window);
#elif defined(__LINUX__)
    x11_lvndOpenGLDestroyContext(window);
#endif
}

void _lvndOpenGLResize(LvndWindow* window) {
#ifdef __MACOS__
    cocoa_lvndOpenGLResize(window);
#elif defined(__IOS__)
    uikit_lvndOpenGLResize(window);
#elif defined(__LINUX__)
    x11_lvndOpenGLResize(window);
#endif
}

void _lvndOpenGLSwapBuffers(LvndWindow* window) {
#ifdef __MACOS__
    cocoa_lvndOpenGLSwapBuffers(window);
#elif defined(__IOS__)
    uikit_lvndOpenGLSwapBuffers(window);
#elif defined(__LINUX__)
    x11_lvndOpenGLSwapBuffers(window);
#endif
}

void _lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
#ifdef __MACOS__
    cocoa_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(__IOS__)
    uikit_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(__LINUX__)
    x11_lvndOpenGLSetSwapInterval(window, interval);
#endif
}

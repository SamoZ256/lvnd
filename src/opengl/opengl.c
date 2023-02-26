#include "lvnd/opengl/opengl.h"

#ifdef LVND_PLATFORM_COCOA
#include "lvnd/cocoa/opengl/cocoa_opengl.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "lvnd/uikit/opengl/uikit_opengl.h"
#elif defined(LVND_PLATFORM_X11)
#include "lvnd/x11/opengl/x11_opengl.h"
#elif defined(LVND_PLATFORM_WAYLAND)
#include "lvnd/wayland/opengl/wayland_opengl.h"
#elif defined(LVND_PLATFORM_WIN32)
#include "lvnd/win32/opengl/win32_opengl.h"
#endif

void _lvndOpenGLCreateContext(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLCreateContext(window);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLCreateContext(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLCreateContext(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLCreateContext(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLCreateContext(window);
#endif
    window->contextInitialized = true;
}

void _lvndOpenGLDestroyContext(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLDestroyContext(window);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLDestroyContext(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLDestroyContext(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLDestroyContext(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLDestroyContext(window);
#endif
}

void _lvndOpenGLResize(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLResize(window);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLResize(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLResize(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLResize(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLResize(window);
#endif
}

void _lvndOpenGLSwapBuffers(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLSwapBuffers(window);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLSwapBuffers(window);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLSwapBuffers(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLSwapBuffers(window);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLSwapBuffers(window);
#endif
}

void _lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLSetSwapInterval(window, interval);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLSetSwapInterval(window, interval);
#endif
}

LvndOpenGLProc _lvndOpenGLGetLoadProc(const char* procname) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndOpenGLGetLoadProc(procname);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndOpenGLGetLoadProc(procname);
#elif defined(LVND_PLATFORM_X11)
    x11_lvndOpenGLGetLoadProc(procname);
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndOpenGLGetLoadProc(procname);
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndOpenGLGetLoadProc(procname);
#endif
}

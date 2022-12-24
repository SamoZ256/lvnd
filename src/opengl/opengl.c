#include "lvnd/opengl/opengl.h"

#include "lvnd/cocoa/opengl/cocoa_opengl.h"

void _lvndOpenGLCreateContext(LvndWindow* window) {
#ifdef __APPLE__
    cocoa_lvndOpenGLCreateContext(window);
#endif
}

void _lvndOpenGLDestroyContext(LvndWindow* window) {
#ifdef __APPLE__
    cocoa_lvndOpenGLDestroyContext(window);
#endif
}

void _lvndOpenGLResize(LvndWindow* window) {
#ifdef __APPLE__
    cocoa_lvndOpenGLResize(window);
#endif
}

void _lvndOpenGLSwapBuffers(LvndWindow* window) {
#ifdef __APPLE__
    cocoa_lvndOpenGLSwapBuffers(window);
#endif
}

void _lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
#ifdef __APPLE__
    cocoa_lvndOpenGLSetSwapInterval(window, interval);
#endif
}

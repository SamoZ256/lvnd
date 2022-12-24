#include "lvnd/x11/opengl/x11_opengl.h"

#include <GL/glx.h>

#include "lvnd/common.h"

void x11_lvndOpenGLCreateContext(LvndWindow* window) {
    //TODO: create the context

    if(!glXMakeCurrent(window->handle->display, window->handle->openglWindow, window->handle->openglContext)) {
        LVND_ERROR("Failed to make GLX context current");
    }
}

void x11_lvndOpenGLDestroyContext(LvndWindow* window) {

}

void x11_lvndOpenGLResize(LvndWindow* window) {
    //TODO: implement this
}

void x11_lvndOpenGLSwapBuffers(LvndWindow* window) {
    glXSwapBuffers(window->handle->display, window->handle->openglWindow);
}

void x11_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
    //TODO: implement this
}

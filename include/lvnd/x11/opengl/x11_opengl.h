#ifndef LVND_X11_OPENGL_H
#define LVND_X11_OPENGL_H

#include "lvnd/opengl/opengl.h"

void x11_lvndOpenGLCreateContext(LvndWindow* window);

void x11_lvndOpenGLDestroyContext(LvndWindow* window);

void x11_lvndOpenGLResize(LvndWindow* window);

void x11_lvndOpenGLSwapBuffers(LvndWindow* window);

void x11_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval);

#endif

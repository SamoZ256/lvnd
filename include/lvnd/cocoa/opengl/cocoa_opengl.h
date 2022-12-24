#ifndef LVND_COCOA_OPENGL_H
#define LVND_COCOA_OPENGL_H

#include "lvnd/opengl/opengl.h"

void cocoa_lvndOpenGLCreateContext(LvndWindow* window);

void cocoa_lvndOpenGLDestroyContext(LvndWindow* window);

void cocoa_lvndOpenGLResize(LvndWindow* window);

void cocoa_lvndOpenGLSwapBuffers(LvndWindow* window);

void cocoa_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval);

#endif

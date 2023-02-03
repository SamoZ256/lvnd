#ifndef LVND_WAYLAND_OPENGL_H
#define LVND_WAYLAND_OPENGL_H

#include "lvnd/opengl/opengl.h"

void wayland_lvndOpenGLCreateContext(LvndWindow* window);

void wayland_lvndOpenGLDestroyContext(LvndWindow* window);

void wayland_lvndOpenGLResize(LvndWindow* window);

void wayland_lvndOpenGLSwapBuffers(LvndWindow* window);

void wayland_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval);

#endif

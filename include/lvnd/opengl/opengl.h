#ifndef LVND_OPENGL_H
#define LVND_OPENGL_H

#include "../window.h"

typedef void (*LvndOpenGLProc)(void);

void _lvndOpenGLCreateContext(LvndWindow* window);

void _lvndOpenGLDestroyContext(LvndWindow* window);

void _lvndOpenGLResize(LvndWindow* window);

void _lvndOpenGLSwapBuffers(LvndWindow* window);

void _lvndOpenGLSetSwapInterval(LvndWindow* window, int interval);

LvndOpenGLProc _lvndOpenGLGetLoadProc(const char* procname);

#endif

#ifndef LVND_X11_WINDOW_H
#define LVND_X11_WINDOW_H

#include "../window.h"

void x11_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title);

void x11_lvndDestroyWindow(LvndWindow* window);

void x11_lvndPollEvents(LvndWindow* window);

void x11_lvndSetWindowTitle(LvndWindow* window, const char* title);

void x11_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY);

void x11_lvndSetCursorState(LvndWindow* window, LvndCursorState state);

void x11_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen);

#endif

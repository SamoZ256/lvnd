#ifndef LVND_WAYLAND_WINDOW_H
#define LVND_WAYLAND_WINDOW_H

#include "../window.h"

void wayland_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title);

void wayland_lvndDestroyWindow(LvndWindow* window);

void wayland_lvndPollEvents(LvndWindow* window);

void wayland_lvndSetWindowTitle(LvndWindow* window, const char* title);

void wayland_lvndSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY);

void wayland_lvndSetCursorState(LvndWindow* window, LvndCursorState state);

void wayland_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen);

//Cross-platform main loop
int wayland_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void));

#endif

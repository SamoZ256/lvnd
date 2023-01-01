#ifndef LVND_COCOA_WINDOW_H
#define LVND_COCOA_WINDOW_H

#include "../window.h"

void cocoa_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title);

void cocoa_lvndDestroyWindow(LvndWindow* window);

void cocoa_lvndPollEvents();

void cocoa_lvndSetWindowTitle(LvndWindow* window, const char* title);

void cocoa_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY);

void cocoa_lvndSetCursorState(LvndWindow* window, LvndCursorState state);

void cocoa_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen);

//Cross-platform main loop
int cocoa_lvndMainLoop(LvndWindow* window, void (*updateFrame)(void));

#endif

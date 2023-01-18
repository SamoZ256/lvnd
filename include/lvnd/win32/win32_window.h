#ifndef WIN32_WINDOW_H
#define WIN32_WINDOW_H

#include "../window.h"

void win32_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title);

void win32_lvndDestroyWindow(LvndWindow* window);

void win32_lvndPollEvents(LvndWindow* window);

void win32_lvndSetWindowTitle(LvndWindow* window, const char* title);

void win32_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY);

void win32_lvndSetCursorState(LvndWindow* window, LvndCursorState state);

void win32_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen);

//Cross-platform main loop
int win32_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void));

#endif

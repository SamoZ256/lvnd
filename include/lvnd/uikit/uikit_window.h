#ifndef LVND_UIKIT_WINDOW_H
#define LVND_UIKIT_WINDOW_H

#include "../window.h"

void uikit_lvndCreateWindow(LvndWindow* window);

void uikit_lvndDestroyWindow(LvndWindow* window);

//Cross-platform main loop
int uikit_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void));

#endif

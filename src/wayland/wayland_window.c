#include "lvnd/wayland/wayland_window.h"

#include <stdio.h>
#include <stdlib.h>

void wayland_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title) {
    //TODO: implement this
}

void wayland_lvndDestroyWindow(LvndWindow* window) {
    //TODO: implement this
}

void wayland_lvndPollEvents(LvndWindow* window) {
    //TODO: implement this
}

void wayland_lvndSetWindowTitle(LvndWindow* window, const char* title) {
    //TODO: implement this
}

void wayland_lvndSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {
    //TODO: implement this
}

void wayland_lvndSetCursorState(LvndWindow* window, LvndCursorState state) {
    //TODO: implement this
}

void wayland_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {
    //TODO: implement this
}

//Cross-platform main loop
int wayland_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void)) {
    if (start != NULL)
        start();

    while (window->isOpen) {
        wayland_lvndPollEvents(window);

        if (updateFrame != NULL)
            updateFrame();
    }

    return 0;
}

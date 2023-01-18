#include "lvnd/win32/win32_window.h"

#include <windows.h>

LRESULT CALLBACK wndProc(HWND hwnd, UINT msg,
    WPARAM wParam, LPARAM lParam) {

    switch(msg) {
      case WM_DESTROY:
          PostQuitMessage(0);
          break;
    }

    return DefWindowProcW(hwnd, msg, wParam, lParam);
}

void win32_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title) {
    window->handle = (Win32_LvndWindowHandle*)malloc(sizeof(Win32_LvndWindowHandle));

    WNDCLASSW wc;

    wc.style         = CS_HREDRAW | CS_VREDRAW;
    wc.cbClsExtra    = 0;
    wc.cbWndExtra    = 0;
    wc.lpszClassName = L"Window";
    wc.hInstance     = NULL;
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.lpszMenuName  = NULL;
    wc.lpfnWndProc   = wndProc;
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);

    RegisterClassW(&wc);
    //TODO: set the actual window title
    window->handle->window = CreateWindowW(wc.lpszClassName, L"Window Title",
                WS_OVERLAPPEDWINDOW | WS_VISIBLE,
                0, 0, width, height, NULL, NULL, NULL, NULL);
}

void win32_lvndDestroyWindow(LvndWindow* window) {
    DestroyWindow(window->handle->window);
}

void win32_lvndPollEvents(LvndWindow* window) {
    MSG msg;
    while (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE)) {
        if (msg.message == WM_QUIT) {
            window->isOpen = false;
        } else {
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }
}

void win32_lvndSetWindowTitle(LvndWindow* window, const char* title) {

}

void win32_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {

}

void win32_lvndSetCursorState(LvndWindow* window, LvndCursorState state) {

}

void win32_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {

}

//Cross-platform main loop
int win32_lvndMainLoop(LvndWindow* window, void (*start)(void), void (*updateFrame)(void)) {
    if (start != NULL)
        start();

    while (window->isOpen) {
        win32_lvndPollEvents(window);

        if (updateFrame != NULL)
            updateFrame();
    }

    return 0;
}

#include "lvnd/x11/x11_window.h"

#include <stdio.h>
#include <stdlib.h>

void x11_lvndCreateWindow(LvndWindow* window, uint16_t width, uint16_t height, const char* title) {
    window->handle = (X11_LvndWindowHandle*)malloc(sizeof(X11_LvndWindowHandle));

    window->handle->display = XOpenDisplay((char*)0);
    window->handle->screen = DefaultScreen(window->handle->display);
    window->handle->black = BlackPixel(window->handle->display, window->handle->screen);
    window->handle->white = WhitePixel(window->handle->display, window->handle->screen);

    window->handle->window = XCreateSimpleWindow(window->handle->display, DefaultRootWindow(window->handle->display), 0, 0, width, height, 5, window->handle->white, window->handle->black);

    XSetStandardProperties(window->handle->display, window->handle->window, title, "Hello", None, NULL, 0, NULL);

    XSelectInput(window->handle->display, window->handle->window, ExposureMask | ButtonPressMask | KeyPressMask);

    window->handle->gc = XCreateGC(window->handle->display, window->handle->window, 0, 0);

    XSetBackground(window->handle->display, window->handle->gc, window->handle->white);
	XSetForeground(window->handle->display, window->handle->gc, window->handle->black);

	XClearWindow(window->handle->display, window->handle->window);
	XMapRaised(window->handle->display, window->handle->window);

    //Delete message
    window->handle->deleteMessage = XInternAtom(window->handle->display, "WM_DELETE_WINDOW", False);
    XSetWMProtocols(window->handle->display, window->handle->window, &window->handle->deleteMessage, 1);
}

void x11_lvndDestroyWindow(LvndWindow* window) {
    XFreeGC(window->handle->display, window->handle->gc);
	XDestroyWindow(window->handle->display, window->handle->window);
	XCloseDisplay(window->handle->display);
}

void x11_lvndPollEvents(LvndWindow* window) {
    XPending(window->handle->display);

    while (QLength(window->handle->display)) {
        XNextEvent(window->handle->display, &window->handle->event);
        
        switch (window->handle->event.type) {
            case ClientMessage:
                if (window->handle->event.xclient.data.l[0] == window->handle->deleteMessage) {
                    window->isOpen = false;
                }
            case Expose:
                if (window->handle->event.xexpose.count == 0) {
                    //printf("Window is exposed\n");
                }
                break;
            case KeyPress:
                if (XLookupString(&window->handle->event.xkey, window->handle->text, 255, &window->handle->key, 0) == 1) {
                    printf("You pressed the %c key!\n", window->handle->text[0]);
                }
                break;
            case ButtonPress:
                printf("You pressed a button at (%i,%i)\n", window->handle->event.xbutton.x, window->handle->event.xbutton.y);
                break;
            default:
                break;
        }
    }
}

void x11_lvndSetWindowTitle(LvndWindow* window, const char* title) {
    XStoreName(window->handle->display, window->handle->window, title);
}

void x11_lvndWindowSetCursorPosition(LvndWindow* window, int32_t mouseX, int32_t mouseY) {

}

void x11_lvndSetCursorState(LvndWindow* window, LvndCursorState state) {

}

void x11_lvndSetWindowFullscreenMode(LvndWindow* window, bool fullscreen) {
    
}

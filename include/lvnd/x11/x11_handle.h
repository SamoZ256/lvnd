#ifndef LVND_X11_HANDLE_H
#define LVND_X11_HANDLE_H

#include <stdbool.h>

#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <X11/Xos.h>

typedef struct __GLXcontextRec* GLXContext;
typedef XID GLXWindow;

typedef struct X11_LvndWindowHandle {
    Display* display;
    int screen;
    Window window;
    GC gc;

    GLXContext openglContext; //OpenGL optional
    GLXWindow openglWindow; //OpenGL optional

    unsigned long black, white;

    XEvent event;
	KeySym key;
	char text[255];
    Atom deleteMessage;
} X11_LvndWindowHandle;

#endif

#ifndef LVND_COCOA_HANDLE_H
#define LVND_COCOA_HANDLE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct Cocoa_LvndWindowHandle {
    void* appDelegate;
    void* window;
    void* windowDelegate;
    void* view;
    void* layer;

    void* openglContext; //OpenGL optional
    void* openglFramework; //OpenGL optional
    void* openglPixelFormat; //OpenGL optional

    bool isRetina;
    bool occluded;
    uint64_t frequency;
} Cocoa_LvndWindowHandle;

#endif

#include "lvnd/cocoa/opengl/cocoa_opengl.h"

#include <mach/mach_time.h>

#import <Cocoa/Cocoa.h>
#import <OpenGL/OpenGL.h>
#import <OpenGL/gl3.h>

#include "lvnd/common.h"
#include "lvnd/context.h"

void cocoa_lvndOpenGLCreateContext(LvndWindow* window) {
    //TODO: create a string version
    //const char* strOpenGLVersion = "";

    window->handle->openglFramework = CFBundleGetBundleWithIdentifier(CFSTR("com.apple.opengl"));
    if (window->handle->openglFramework == NULL) {
        LVND_ERROR("Failed to create NS OpenGL framework");
    }

    NSOpenGLPixelFormatAttribute attributes[32];
    uint16_t attribIndex = 0;

#define ADD_ATTRIBUTE(attrib) attributes[attribIndex++] = attrib;
#define SET_ATTRIBUTE(attrib1, attrib2) ADD_ATTRIBUTE(attrib1); ADD_ATTRIBUTE(attrib2);

    ADD_ATTRIBUTE(NSOpenGLPFAAccelerated);
    ADD_ATTRIBUTE(NSOpenGLPFAClosestPolicy);

    if (g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR] >= 4) {
        SET_ATTRIBUTE(NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion4_1Core);
    } else if (g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR] >= 3) {
        SET_ATTRIBUTE(NSOpenGLPFAOpenGLProfile, NSOpenGLProfileVersion3_2Core);
    }

    //TODO: calculate bit sizes at runtime
    SET_ATTRIBUTE(NSOpenGLPFAColorSize, 24);
    SET_ATTRIBUTE(NSOpenGLPFAAlphaSize, 16);
    SET_ATTRIBUTE(NSOpenGLPFADepthSize, 32);
    SET_ATTRIBUTE(NSOpenGLPFAStencilSize, 8);

    //TODO: make this an option
    ADD_ATTRIBUTE(NSOpenGLPFADoubleBuffer);
    SET_ATTRIBUTE(NSOpenGLPFASampleBuffers, 0);

    //TODO: find out why should I do this
    ADD_ATTRIBUTE(0);

    window->handle->openglPixelFormat = [[NSOpenGLPixelFormat alloc] initWithAttributes:attributes];
    if (window->handle->openglPixelFormat == NULL) {
        LVND_ERROR("Failed to create NS OpenGL pixel format");
    }

    window->handle->openglContext = [[NSOpenGLContext alloc] initWithFormat:window->handle->openglPixelFormat shareContext: nil];

    if (window->handle->openglContext == NULL) {
        LVND_ERROR("Failed to create NS OpenGL context");
    }

    //TODO: detect if screen is retina on application startup
    [(id)window->handle->view setWantsBestResolutionOpenGLSurface:window->handle->isRetina];
    [(id)window->handle->openglContext setView:window->handle->view];

    [(id)window->handle->openglContext makeCurrentContext];
}

void cocoa_lvndOpenGLDestroyContext(LvndWindow* window) {
    [(id)window->handle->openglFramework release];
    [(id)window->handle->openglPixelFormat release];
    [(id)window->handle->openglContext release];
}

void cocoa_lvndOpenGLResize(LvndWindow* window) {
    [(id)window->handle->openglContext update];
}

void cocoa_lvndOpenGLSwapBuffers(LvndWindow* window) {
    //TODO: do something with the blinking, it's terrible
    if (window->handle->occluded) {
        int interval = 0;
        [(id)window->handle->openglContext getValues:&interval
                                  forParameter:NSOpenGLContextParameterSwapInterval];

        if (interval > 0) {
            const double framerate = 60.0;
            const uint64_t frequency = window->handle->frequency;
            const uint64_t value = mach_absolute_time();

            const double elapsed = value / (double) frequency;
            const double period = 1.0 / framerate;
            const double delay = period - fmod(elapsed, period);

            usleep(floorl(delay * 1e6));
        }
    }

    [(id)window->handle->openglContext flushBuffer];
}

void cocoa_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
    [(id)window->handle->openglContext setValues:&interval
                                   forParameter:NSOpenGLContextParameterSwapInterval];
}

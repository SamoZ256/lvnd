#include "lvnd/x11/opengl/x11_opengl.h"

#include <GL/glx.h>

#include "lvnd/common.h"
#include "lvnd/context.h"

void x11_lvndOpenGLCreateContext(LvndWindow* window) {
    int attributes[32];
    GLXFBConfig fbconfig = NULL;

    GLXFBConfig* fbconfigs;
    int fbconfigCount;

    fbconfigs = glXGetFBConfigs(window->handle->display, window->handle->screen, &fbconfigCount);
    if (!fbconfigs || !fbconfigCount) {
        LVND_ERROR("Failed to get GLX framebuffer configs");
    }
    
#define ADD_ATTRIBUTE(attrib) attributes[attribIndex++] = attrib;
#define SET_ATTRIBUTE(attrib1, attrib2) ADD_ATTRIBUTE(attrib1); ADD_ATTRIBUTE(attrib2);

    int attribIndex = 0;
    int mask = GLX_CONTEXT_CORE_PROFILE_BIT_ARB;
    int flags = 0;

    SET_ATTRIBUTE(GLX_CONTEXT_MAJOR_VERSION_ARB, g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR]);
    SET_ATTRIBUTE(GLX_CONTEXT_MINOR_VERSION_ARB, g_lvndContext.windowParamValues[LVND_WINDOW_PARAM_OPENGL_VERSION_MINOR]);

    if (mask)
        SET_ATTRIBUTE(GLX_CONTEXT_PROFILE_MASK_ARB, mask);

    if (flags)
        SET_ATTRIBUTE(GLX_CONTEXT_FLAGS_ARB, flags);

    SET_ATTRIBUTE(None, None);

    window->handle->openglContext = glXCreateNewContext(window->handle->display, fbconfig, GLX_RGBA_TYPE, 0, True);
    if (!window->handle->openglContext) {
        LVND_ERROR("Failed to create GLX context");
    }

    window->handle->openglWindow = glXCreateWindow(window->handle->display, fbconfig, window->handle->window, NULL);
    if (!window->handle->openglWindow) {
        LVND_ERROR("Failed to create GLX window");
    }

    if(!glXMakeCurrent(window->handle->display, window->handle->openglWindow, window->handle->openglContext)) {
        LVND_ERROR("Failed to make GLX context current");
    }
}

void x11_lvndOpenGLDestroyContext(LvndWindow* window) {
    glXDestroyWindow(window->handle->display, window->handle->openglWindow);
    glXDestroyContext(window->handle->display, window->handle->openglContext);
}

void x11_lvndOpenGLResize(LvndWindow* window) {
    //TODO: implement this
}

void x11_lvndOpenGLSwapBuffers(LvndWindow* window) {
    glXSwapBuffers(window->handle->display, window->handle->openglWindow);
}

void x11_lvndOpenGLSetSwapInterval(LvndWindow* window, int interval) {
    //TODO: implement this
}

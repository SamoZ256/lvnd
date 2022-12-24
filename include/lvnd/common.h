#ifndef LVND_COMMON_H
#define LVND_COMMON_H

#define LVND_VERSION_MAJOR 1
#define LVND_VERSION_MINOR 0
#define LVND_VERSION_REVISION 0

#define LVND_ERROR(msg) \
printf("[lvnd ERROR]::" "%s" ": " msg "\n", __FUNCTION__);

/*************************************************************************
 * Validation (optional)
*************************************************************************/
#define LVND_VALIDATE_INIT \
if (!g_lvndContext.initialized) { \
    LVND_ERROR("Context must be initialized before a call to this function"); \
}

#define LVND_VALIDATE_WINDOW(window) \
if (window == NULL) { \
    LVND_ERROR("Window must be a valid window handle"); \
}

#define LVND_VALIDATE_POINTER(ptr) \
if (ptr == NULL) { \
    LVND_ERROR("'" #ptr "' must be a valid pointer"); \
}

#ifdef __APPLE__

#define LVND_VALIDATE_OPENGL_CONTEXT(window) \
if (window->handle->openglContext == NULL) { \
    LVND_ERROR("OpenGL context must be initialized before a call to this function"); \
}

#elif defined linux

#define LVND_VALIDATE_OPENGL_CONTEXT(window) \
if (window->handle->openglDrawable == 0) { \
    LVND_ERROR("OpenGL context must be initialized before a call to this function"); \
}

#elif defined _WIN32

//TODO: implement OpenGL error on windows

#endif

#endif

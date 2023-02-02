#include <stdio.h>

#include <glad/glad.h>

#define LVND_DEBUG
#define LVND_BACKEND_OPENGL
#include "lvnd/lvnd.h"

int main() {
    lvndInit();

    lvndSetWindowParamValue(LVND_WINDOW_PARAM_OPENGL_VERSION_MAJOR, 4);
    lvndSetWindowParamValue(LVND_WINDOW_PARAM_OPENGL_VERSION_MINOR, 6);

    LvndWindow* window = lvndCreateWindow(400, 300, "My Super Window");
    lvndOpenGLCreateContext(window);

    gladLoadGL();

    glViewport(0, 0, 400, 300);
    
    while (lvndWindowIsOpen(window)) {
        lvndPollEvents(window);

        glClearColor(0.3f, 0.2f, 0.8f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        lvndOpenGLSwapBuffers(window);
    }

    lvndOpenGLCreateContext(window);
    lvndDestroyWindow(window);

    return 0;
}

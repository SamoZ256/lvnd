#ifndef LVND_UIKIT_HANDLE_H
#define LVND_UIKIT_HANDLE_H

#include <stdbool.h>
#include <stdint.h>

typedef struct UIKit_LvndWindowHandle {
    void* viewController;
    void* layer;

    void (*start)(void);
    void (*updateFrame)(void);
} UIKit_LvndWindowHandle;

#endif

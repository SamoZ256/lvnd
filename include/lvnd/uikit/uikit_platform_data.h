#ifndef UIKIT_PLATFORM_DATA_H
#define UIKIT_PLATFORM_DATA_H

#include "../window.h"

typedef struct UIKit_LvndPlatformData {
    bool initialized;
    
    LvndWindow* window;
    void* device;
    
    void (*initCalls[1])(void);
    uint16_t initCallCount;
} UIKit_LvndPlatformData;

#endif

#include "lvnd/init.h"

#include <stddef.h>
#include <sys/time.h>

#include "lvnd/common.h"

#include "lvnd/context.h"

#ifdef __MACOS__
#include "lvnd/cocoa/cocoa_init.h"
#elif defined(__IOS__)
#include "lvnd/uikit/uikit_init.h"
#elif defined(__LINUX__)
#include "lvnd/x11/x11_init.h"
#elif defined(__WIN32__)
#include "lvnd/win32/win32_init.h"
#endif

void _lvndInit() {
#ifdef __MACOS__
    cocoa_lvndInit();
#elif defined(__IOS__)
    uikit_lvndInit();
#elif defined(__LINUX__)
    x11_lvndInit();
#elif defined(__WIN32__)
    win32_lvndInit();
#endif

    struct timeval tv;
    gettimeofday(&tv, NULL);
    g_lvndContext.input.beginTime = tv.tv_sec;

    //Set the initialized variable to true
    g_lvndContext.initialized = true;
}

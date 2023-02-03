#include "lvnd/init.h"

#include <stddef.h>
#include <sys/time.h>

#include "lvnd/common.h"

#include "lvnd/context.h"

#ifdef LVND_PLATFORM_COCOA
#include "lvnd/cocoa/cocoa_init.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "lvnd/uikit/uikit_init.h"
#elif defined(LVND_PLATFORM_WAYLAND)
#include "lvnd/wayland/wayland_init.h"
#elif defined(LVND_PLATFORM_X11)
#include "lvnd/x11/x11_init.h"
#elif defined(LVND_PLATFORM_WIN32)
#include "lvnd/win32/win32_init.h"
#endif

void _lvndInit() {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndInit();
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndInit();
#elif defined(LVND_PLATFORM_X11)
    x11_lvndInit();
#elif defined(LVND_PLATFORM_WAYLAND)
    wayland_lvndInit();
#elif defined(LVND_PLATFORM_WIN32)
    win32_lvndInit();
#endif

    struct timeval tv;
    gettimeofday(&tv, NULL);
    g_lvndContext.input.beginTime = tv.tv_sec;

    //Set the initialized variable to true
    g_lvndContext.initialized = true;
}

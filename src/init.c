#include "lvnd/init.h"

#include <stddef.h>
#include <sys/time.h>

#include "lvnd/context.h"

#ifdef __APPLE__
#include "lvnd/cocoa/cocoa_init.h"
#elif defined linux
#include "lvnd/x11/x11_init.h"
#elif defined _WIN32
#include "lvnd/win32/win32_init.h"
#endif

void _lvndInit() {
#ifdef __APPLE__
    cocoa_lvndInit();
#elif defined linux
    x11_lvndInit();
#elif defined _WIN32
    win32_lvndInit();
#endif

    struct timeval tv;
    gettimeofday(&tv, NULL);
    g_lvndContext.input.beginTime = tv.tv_sec;

    //Set the initialized variable to true
    g_lvndContext.initialized = true;
}

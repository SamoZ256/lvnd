#include "lvnd/metal/metal.h"

#ifdef LVND_PLATFORM_COCOA
#include "lvnd/cocoa/metal/cocoa_metal.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "lvnd/uikit/metal/uikit_metal.h"
#endif

void _lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {
#ifdef LVND_PLATFORM_COCOA
    cocoa_lvndMetalCreateLayer(window, width, height, device);
#elif defined(LVND_PLATFORM_UIKIT)
    uikit_lvndMetalCreateLayer(window, width, height, device);
#endif
}

void _lvndMetalDestroyLayer(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    return cocoa_lvndMetalDestroyLayer(window);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndMetalDestroyLayer(window);
#endif
}

void* _lvndMetalNextDrawable(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    return cocoa_lvndMetalNextDrawable(window);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndMetalNextDrawable(window);
#endif
}

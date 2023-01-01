#include "lvnd/metal/metal.h"

#ifdef __MACOS__
#include "lvnd/cocoa/metal/cocoa_metal.h"
#elif defined(__IOS__)
#include "lvnd/uikit/metal/uikit_metal.h"
#endif

void _lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {
#ifdef __MACOS__
    cocoa_lvndMetalCreateLayer(window, width, height, device);
#elif defined(__IOS__)
    uikit_lvndMetalCreateLayer(window, width, height, device);
#endif
}

void _lvndMetalDestroyLayer(LvndWindow* window) {
#ifdef __MACOS__
    return cocoa_lvndMetalDestroyLayer(window);
#elif defined(__IOS__)
    return uikit_lvndMetalDestroyLayer(window);
#endif
}

void* _lvndMetalNextDrawable(LvndWindow* window) {
#ifdef __MACOS__
    return cocoa_lvndMetalNextDrawable(window);
#elif defined(__IOS__)
    return uikit_lvndMetalNextDrawable(window);
#endif
}

#include "lvnd/metal/metal.h"

#ifdef __APPLE__
#include "lvnd/cocoa/metal/cocoa_metal.h"
#endif

void _lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {
#ifdef __APPLE__
    cocoa_lvndMetalCreateLayer(window, width, height, device);
#endif
}

void _lvndMetalDestroyLayer(LvndWindow* window) {
#ifdef __APPLE__
    return cocoa_lvndMetalDestroyLayer(window);
#endif
}

void* _lvndMetalNextDrawable(LvndWindow* window) {
#ifdef __APPLE__
    return cocoa_lvndMetalNextDrawable(window);
#endif
}

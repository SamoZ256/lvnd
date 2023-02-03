#include "lvnd/vulkan/vulkan.h"

#ifdef LVND_PLATFORM_COCOA
#include "lvnd/cocoa/vulkan/cocoa_vulkan.h"
#elif defined(LVND_PLATFORM_UIKIT)
#include "lvnd/uikit/vulkan/uikit_vulkan.h"
#elif defined(LVND_PLATFORM_X11)
#include "lvnd/x11/vulkan/x11_vulkan.h"
#elif defined(LVND_PLATFORM_WAYLAND)
#include "lvnd/wayland/vulkan/wayland_vulkan.h"
#elif defined(LVND_PLATFORM_WIN32)
#include "lvnd/win32/vulkan/win32_vulkan.h"
#endif

VkResult _lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
#ifdef LVND_PLATFORM_COCOA
    return cocoa_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(LVND_PLATFORM_X11)
    return x11_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(LVND_PLATFORM_WAYLAND)
    return wayland_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(LVND_PLATFORM_WIN32)
    return win32_lvndVulkanCreateWindowSurface(window, instance, surface);
#endif
}

void _lvndVulkanDestroyLayer(LvndWindow* window) {
#ifdef LVND_PLATFORM_COCOA
    return cocoa_lvndVulkanDestroyLayer(window);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndVulkanDestroyLayer(window);
#elif defined(LVND_PLATFORM_X11)
    return x11_lvndVulkanDestroyLayer(window);
#elif defined(LVND_PLATFORM_WAYLAND)
    return wayland_lvndVulkanDestroyLayer(window);
#elif defined(LVND_PLATFORM_WIN32)
    return win32_lvndVulkanDestroyLayer(window);
#endif
}

const char** _lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
#ifdef __APPLE__
    return cocoa_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(LVND_PLATFORM_UIKIT)
    return uikit_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(LVND_PLATFORM_X11)
    return x11_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(LVND_PLATFORM_WAYLAND)
    return wayland_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(LVND_PLATFORM_WIN32)
    return win32_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#endif
}

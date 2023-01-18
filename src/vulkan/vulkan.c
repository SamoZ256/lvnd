#include "lvnd/vulkan/vulkan.h"

#ifdef __MACOS__
#include "lvnd/cocoa/vulkan/cocoa_vulkan.h"
#elif defined(__IOS__)
#include "lvnd/uikit/vulkan/uikit_vulkan.h"
#elif defined(__LINUX__)
#include "lvnd/x11/vulkan/x11_vulkan.h"
#elif defined(__WIN32__)
#include "lvnd/win32/vulkan/win32_vulkan.h"
#endif

VkResult _lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
#ifdef __MACOS__
    return cocoa_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(__IOS__)
    return uikit_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(__LINUX__)
    return x11_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined(__WIN32__)
    return win32_lvndVulkanCreateWindowSurface(window, instance, surface);
#endif
}

void _lvndVulkanDestroyLayer(LvndWindow* window) {
#ifdef __MACOS__
    return cocoa_lvndVulkanDestroyLayer(window);
#elif defined(__IOS__)
    return uikit_lvndVulkanDestroyLayer(window);
#elif defined(__LINUX__)
    return x11_lvndVulkanDestroyLayer(window);
#elif defined(__WIN32__)
    return win32_lvndVulkanDestroyLayer(window);
#endif
}

const char** _lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
#ifdef __APPLE__
    return cocoa_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(__IOS__)
    return uikit_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(__LINUX__)
    return x11_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined(__WIN32__)
    return win32_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#endif
}

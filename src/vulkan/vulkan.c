#include "lvnd/vulkan/vulkan.h"

#ifdef __APPLE__
#include "lvnd/cocoa/vulkan/cocoa_vulkan.h"
#elif defined linux
#include "lvnd/x11/vulkan/x11_vulkan.h"
#elif defined _WIN32
#include "lvnd/win32/vulkan/win32_vulkan.h"
#endif

VkResult _lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
#ifdef __APPLE__
    return cocoa_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined linux
    return x11_lvndVulkanCreateWindowSurface(window, instance, surface);
#elif defined _WIN32
    return win32_lvndVulkanCreateWindowSurface(window, instance, surface);
#endif
}

void _lvndVulkanDestroyLayer(LvndWindow* window) {
#ifdef __APPLE__
    return cocoa_lvndVulkanDestroyLayer(window);
#elif defined linux
    return x11_lvndVulkanDestroyLayer(window);
#elif defined _WIN32
    return win32_lvndVulkanDestroyLayer(window);
#endif
}

const char** _lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
#ifdef __APPLE__
    return cocoa_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined linux
    return x11_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#elif defined _WIN32
    return win32_lvndVulkanGetRequiredInstanceExtensions(extensionCount);
#endif
}

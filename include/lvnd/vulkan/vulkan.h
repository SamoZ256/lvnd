#ifndef LVND_VULKAN_H
#define LVND_VULKAN_H

#include <stdlib.h>

#include "../common.h"

#ifdef __MACOS__
#define VK_USE_PLATFORM_MACOS_MVK
#elif defined(__LINUX__)
#define VK_USE_PLATFORM_XLIB_KHR
#endif
#include <vulkan/vulkan.h>

#include "../window.h"

VkResult _lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface);

void _lvndVulkanDestroyLayer(LvndWindow* window);

const char** _lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount);

#endif

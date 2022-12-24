#ifndef LVND_COCOA_VULKAN_H
#define LVND_COCOA_VULKAN_H

#include "../../vulkan/vulkan.h"

VkResult cocoa_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface);

void cocoa_lvndVulkanDestroyLayer(LvndWindow* window);

const char** cocoa_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount);

#endif

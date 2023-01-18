#ifndef LVND_X11_VULKAN_H
#define LVND_X11_VULKAN_H

#include "../../vulkan/vulkan.h"

VkResult x11_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface);

void x11_lvndVulkanDestroyLayer(LvndWindow* window);

const char** x11_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount);

#endif

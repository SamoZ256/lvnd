#ifndef LVND_WAYLAND_VULKAN_H
#define LVND_WAYLAND_VULKAN_H

#include "../../vulkan/vulkan.h"

VkResult wayland_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface);

void wayland_lvndVulkanDestroyLayer(LvndWindow* window);

const char** wayland_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount);

#endif

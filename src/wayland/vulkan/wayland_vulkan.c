#include "lvnd/wayland/vulkan/wayland_vulkan.h"

#include <vulkan/vulkan_wayland.h>

VkResult wayland_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
    VkWaylandSurfaceCreateInfoKHR surfaceCreateInfo;
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_WAYLAND_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.pNext = NULL;
    //surfaceCreateInfo.display = window->handle->display; //TODO: add this
    //surfaceCreateInfo.surface = window->handle->surface; //TODO: add this
    surfaceCreateInfo.flags = 0;
    
    return vkCreateWaylandSurfaceKHR(instance, &surfaceCreateInfo, NULL, surface);
}

void wayland_lvndVulkanDestroyLayer(LvndWindow* window) {

}

const char** wayland_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
    const char** extensions = (const char**)malloc(sizeof(const char*) * 2);
    extensions[0] = VK_KHR_SURFACE_EXTENSION_NAME;
	extensions[1] = "VK_KHR_wayland_surface";

    *extensionCount = 2;

    return extensions;
}


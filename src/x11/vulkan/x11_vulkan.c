#include "lvnd/x11/vulkan/x11_vulkan.h"

VkResult x11_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
    VkXlibSurfaceCreateInfoKHR surfaceCreateInfo;
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_XLIB_SURFACE_CREATE_INFO_KHR;
    surfaceCreateInfo.pNext = NULL;
    surfaceCreateInfo.dpy = window->handle->display;
    surfaceCreateInfo.window = window->handle->window;
    surfaceCreateInfo.flags = 0;
    
    return vkCreateXlibSurfaceKHR(instance, &surfaceCreateInfo, NULL, surface);
}

void x11_lvndVulkanDestroyLayer(LvndWindow* window) {

}

const char** x11_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
    const char** extensions = (const char**)malloc(sizeof(const char*) * 2);
    extensions[0] = VK_KHR_SURFACE_EXTENSION_NAME;
	extensions[1] = "VK_KHR_xlib_surface";

    *extensionCount = 2;

    return extensions;
}

#include "lvnd/cocoa/vulkan/cocoa_vulkan.h"

#import <QuartzCore/QuartzCore.h>
#import <Cocoa/Cocoa.h>

VkResult cocoa_lvndVulkanCreateWindowSurface(LvndWindow* window, VkInstance instance, VkSurfaceKHR* surface) {
    CAMetalLayer* layer = [CAMetalLayer layer];
    [layer setContentsScale:window->framebufferScaleX];
    window->handle->layer = layer;

    NSWindow* nswindow = window->handle->window;
    nswindow.contentView.layer = layer;
    nswindow.contentView.wantsLayer = YES;

    VkMacOSSurfaceCreateInfoMVK surfaceCreateInfo;
    surfaceCreateInfo.sType = VK_STRUCTURE_TYPE_MACOS_SURFACE_CREATE_INFO_MVK;
    surfaceCreateInfo.pNext = NULL;
    surfaceCreateInfo.pView = window->handle->view;
    surfaceCreateInfo.flags = 0;
    
    return vkCreateMacOSSurfaceMVK(instance, &surfaceCreateInfo, NULL, surface);
}

void cocoa_lvndVulkanDestroyLayer(LvndWindow* window) {
    [(id)window->handle->layer release];
}

const char** cocoa_lvndVulkanGetRequiredInstanceExtensions(uint16_t* extensionCount) {
    const char** extensions = (const char**)malloc(sizeof(const char*) * 3);
    extensions[0] = VK_KHR_SURFACE_EXTENSION_NAME;
	extensions[1] = "VK_EXT_metal_surface";
	extensions[2] = "VK_MVK_macos_surface";

    *extensionCount = 3;

    return extensions;
}

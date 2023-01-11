#include "lvnd/uikit/metal/uikit_metal.h"

#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <UIKit/UIKit.h>

#include "lvnd/context.h"
#include "lvnd/uikit/uikit_platform_data.h"

#import "lvnd/uikit/uikit_view_controller.h"

void _uikit_lvndMetalCreateLayer() {
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    LvndWindow* window = (LvndWindow*)platformData->window;
    
    /*
    CGSize size = {};
    size.width = window->width;
    size.height = window->height;
    */
    
    UIKit_LvndViewController* uiViewController = CFBridgingRelease(platformData->window->handle->viewController);
    //uiWiew.view.wantsLayer = YES;
    
    uiViewController->metalLayer = [CAMetalLayer layer];
    uiViewController->metalLayer.device = (__bridge id<MTLDevice>)platformData->device;
    uiViewController->metalLayer.pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
    //uiViewController->metalLayer.drawableSize = size;
    uiViewController->metalLayer.framebufferOnly = NO;
    uiViewController->metalLayer.frame = uiViewController.view.layer.frame;
    uiViewController.view.layer.sublayers = nil;
    [uiViewController.view.layer addSublayer:uiViewController->metalLayer];
    platformData->window->handle->layer = (void*)CFBridgingRetain(uiViewController->metalLayer);
    //uiWiew.view.layer = layer;
}

void uikit_lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {
    UIKit_LvndPlatformData* platformData = (UIKit_LvndPlatformData*)(g_lvndContext.platformData);
    platformData->device = device;
    
    //We cannot call @ref _uikit_lvndMetalCreateLayer before calling @ref lvndMainLoop, because all the uikit classes get initialized by that call
    if (platformData->initialized)
        _uikit_lvndMetalCreateLayer();
    else
        platformData->initCalls[platformData->initCallCount++] = _uikit_lvndMetalCreateLayer;
}

void uikit_lvndMetalDestroyLayer(LvndWindow* window) {
    //TODO: release the layer
    //[(CAMetalLayer*)CFBridgingRelease(window->handle->layer) release];
}

void* uikit_lvndMetalNextDrawable(LvndWindow* window) {
    CAMetalLayer* metalLayer = (__bridge CAMetalLayer*)window->handle->layer;

    return (void*)CFBridgingRetain([metalLayer nextDrawable]);
}

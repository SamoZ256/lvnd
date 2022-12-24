#include "lvnd/cocoa/metal/cocoa_metal.h"

#import <Metal/Metal.h>
#import <QuartzCore/QuartzCore.h>
#import <Cocoa/Cocoa.h>

void cocoa_lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device) {    
    CGSize size = {};
    size.height = height;
    size.width = width;
    
    CAMetalLayer* layer = [CAMetalLayer layer];
    layer.device = (__bridge id<MTLDevice>) device;
    layer.pixelFormat = MTLPixelFormatBGRA8Unorm_sRGB;
    layer.drawableSize = size;
    window->handle->layer = layer;

    NSWindow* nswindow = window->handle->window;
    nswindow.contentView.layer = layer;
    nswindow.contentView.wantsLayer = YES;
}

void cocoa_lvndMetalDestroyLayer(LvndWindow* window) {
    [(id)window->handle->layer release];
}

void* cocoa_lvndMetalNextDrawable(LvndWindow* window) {
    CAMetalLayer* metalLayer = (__bridge CAMetalLayer*) window->handle->layer;

    return [metalLayer nextDrawable];
}

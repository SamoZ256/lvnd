#ifndef LVND_COCOA_METAL_H
#define LVND_COCOA_METAL_H

#include "../../window.h"

void cocoa_lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device);

void cocoa_lvndMetalDestroyLayer(LvndWindow* window);

void* cocoa_lvndMetalNextDrawable(LvndWindow* window);

#endif

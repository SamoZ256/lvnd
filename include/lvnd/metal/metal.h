#ifndef LVND_METAL_H
#define LVND_METAL_H

#include "../window.h"

void _lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device);

void _lvndMetalDestroyLayer(LvndWindow* window);

void* _lvndMetalNextDrawable(LvndWindow* window);

#endif

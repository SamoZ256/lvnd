#ifndef LVND_UIKIT_METAL_H
#define LVND_UIKIT_METAL_H

#include "../../window.h"

void uikit_lvndMetalCreateLayer(LvndWindow* window, uint16_t width, uint16_t height, void* device);

void uikit_lvndMetalDestroyLayer(LvndWindow* window);

void* uikit_lvndMetalNextDrawable(LvndWindow* window);

#endif

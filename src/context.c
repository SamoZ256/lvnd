#include "lvnd/context.h"

#include <stdlib.h>

LvndContext g_lvndContext = {
    .initialized = false,
    .hasMenuBar = false,
    .globalMenuBar = NULL,
    .windowParamValues = {
        0,
        0
    }
};

void _lvndSetWindowParamValue(LvndWindowParam param, unsigned int value) {
    g_lvndContext.windowParamValues[param] = value;
}

#ifndef LVND_CONTEXT_H
#define LVND_CONTEXT_H

#include <stdbool.h>

#include "input.h"
#include "menu_bar.h"
#include "window_params.h"

typedef struct LvndContext {
    void* platformData;

    bool initialized;
    bool hasMenuBar;
    LvndMenuBar* globalMenuBar;

    unsigned int windowParamValues[LVND_TOTAL_WINDOW_PARAM_COUNT];

    LvndInput input;
} LvndContext;

extern LvndContext g_lvndContext;

void _lvndSetWindowParamValue(LvndWindowParam param, unsigned int value);

#endif

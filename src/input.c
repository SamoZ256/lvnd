#include "lvnd/input.h"

#include <stddef.h>
#include <sys/time.h>

#include "lvnd/context.h"

double _lvndGetTime() {
    struct timeval tv;
    gettimeofday(&tv, NULL);

    return (tv.tv_sec - g_lvndContext.input.beginTime) + tv.tv_usec / 1000000.0;
}

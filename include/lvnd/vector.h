#ifndef LVND_VECTOR_H
#define LVND_VECTOR_H

#include <stdint.h>

#define LVND_DEFAULT_VECTOR_CAPACITY 4

typedef struct LvndVector {
    void** items;
    int size;
    int capacity;
} LvndVector;

LvndVector* lvndCreateVector(uint32_t capacity);

void lvndVectorResize(LvndVector* vector, int capacity);

void lvndVectorPushBack(LvndVector* vector, void* item);

void lvndVectorSet(LvndVector* vector, int index, void* item);

void* lvndVectorGet(LvndVector* vector, int index);

void lvndVectorDelete(LvndVector* vector, int index);

void lvndVectorFree(LvndVector* vector);

#endif

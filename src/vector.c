#include "lvnd/vector.h"

#include <stdlib.h>

LvndVector* lvndCreateVector(uint32_t capacity) {
    LvndVector* vector = (LvndVector*)malloc(sizeof(LvndVector));

    vector->capacity = capacity;
    vector->size = 0;
    vector->items = malloc(sizeof(void*) * capacity);

    return vector;
}

void lvndVectorResize(LvndVector* vector, int capacity) {
    void **items = realloc(vector->items, sizeof(void *) * capacity);
    if (items) {
        vector->items = items;
        vector->capacity = capacity;
    }
}

void lvndVectorPushBack(LvndVector* vector, void* item) {
    if (vector->capacity == vector->size) {
        lvndVectorResize(vector, vector->capacity * 2);
    }
    vector->items[vector->size++] = item;
}

void lvndVectorSet(LvndVector* vector, int index, void* item) {
    vector->items[index] = item;
}

void* lvndVectorGet(LvndVector* vector, int index) {
    return vector->items[index];
}

void lvndVectorDelete(LvndVector* vector, int index) {
    int i = 0;
    vector->items[index] = NULL;
    for (i = index; (i < vector->size - 1); ++i) {
        vector->items[i] = vector->items[i + 1];
        vector->items[i + 1] = NULL;
    }
    vector->size--;
    if ((vector->size > 0) && ((vector->size) == (vector->capacity / 4))) {
        lvndVectorResize(vector, vector->capacity / 2);
    }
}

void lvndVectorFree(LvndVector* vector) {
    free(vector->items);
    vector->items = NULL;
}

void lvndVectorEraseFirst(LvndVector* vector) {
    vector->size--;
    //vector->items = realloc(vector->items + sizeof(void*), sizeof(void*) * vector->capacity);
    for(uint32_t i = 0; i < vector->size; i++) {
        vector->items[i] = vector->items[i + 1];
    }
    vector->items = realloc(vector->items, vector->capacity * sizeof(void*));
}

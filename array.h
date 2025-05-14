#pragma once

#include <stdlib.h>

#define DEFAULT_ARRAY_SIZE 8;

typedef struct array {
    void** data;
    size_t size;
    size_t index;
} array;

array* new_array(size_t size);

void array_add(array* arr, void* data);
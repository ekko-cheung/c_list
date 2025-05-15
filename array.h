#pragma once

#include <stdlib.h>

#define DEFAULT_ARRAY_SIZE 8

typedef struct array array;

array* new_array(size_t size);

void array_add(array* arr, void* data);

void* array_get(array* arr, size_t index);

void* array_remove(array* arr, size_t index);

size_t array_count(array* arr);
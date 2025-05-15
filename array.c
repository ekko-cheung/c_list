#include <stdlib.h>
#include <string.h>

#include "array.h"

typedef struct array {
    void** data;
    size_t size;
    size_t index;
} array;

array* new_array(size_t size) {
    if (size <= 0) {
        size = DEFAULT_ARRAY_SIZE;
    }

    array* arr = (array*)malloc(sizeof(array*));
    arr->data = NULL;
    arr->size = size;

    return arr;
}

void grow(array* arr, size_t size) {
    size_t old_size = arr->size;
    size_t new_size = old_size >> 1 + old_size;
    if (new_size - size < 0) {
        new_size = size;
    }

    void** new_data = malloc(sizeof(void*) * new_size);
    if (arr->data != NULL) {
        memcpy(new_data, arr->data, old_size);
        free(arr->data);
    }
    arr->data = new_data;
    arr->size = new_size;
}

void ensure_capaticy(array* arr) {
    if (arr->data == NULL) {
        arr->data = malloc(sizeof(void*) * arr->size);
        return;
    }

    if (arr->index == arr->size) {
        grow(arr, arr->size);
    }
}

void array_add(array* arr, void* data) {
    ensure_capaticy(arr);

    arr->data[arr->index] = data;
    arr->index++;
}

void* array_get(array* arr, size_t index) {
    if (index >= arr->index) {
        return NULL;
    }

    return arr->data[index];
}

void* array_remove(array* arr, size_t index) {
    if (index >= arr->index) {
        return NULL;
    }

    void* data = arr->data[index];
    size_t new_index = arr->index-1;
    if (new_index > index) {
        for (int i = index; i < new_index; i++) {
            arr->data[i] = arr->data[i+1];
        }
    }
    arr->data[new_index] = NULL;
    arr->index = new_index;

    return data;
}

size_t array_count(array* arr) {
    return arr->index;
}
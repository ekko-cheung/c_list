#include <stdlib.h>
#include <string.h>

#include "array.h";

array* new_array(size_t size) {
    if (size <= 0) {
        size = DEFAULT_ARRAY_SIZE;
    }

    array* arr = (array*)malloc(sizeof(array*));
    arr->data = NULL;
    arr->size = DEFAULT_ARRAY_SIZE;

    return arr;
}

void ensure_capaticy(array* arr, size_t new_size) {
    if (arr->data == NULL) {
        new_size = new_size > arr->size ? new_size : arr->size;
    }

    if (new_size - arr->size > 0) {
        grow(arr, new_size);
    }
}

void grow(array* arr, size_t size) {
    size_t old_size = arr->size;
    size_t new_size = old_size >> 1 + old_size;
    if (new_size - size < 0) {
        new_size = size;
    }

    void** new_data = malloc(sizeof(void*) * new_size);
    memcpy(new_data, arr->data, old_size);
    free(arr->data);
    arr->data = new_data;
    arr->size = new_size;
}

void array_add(array* arr, void* data) {
    ensure_capaticy(arr, arr->index+1);

    arr->data[arr->index] = data;
    arr->index++;
}
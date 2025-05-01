#pragma once

#include <stdlib.h>

#define FREE_VALUES 1
#define NO_FREE_VALUES 0

typedef struct node node;

typedef struct node {
    void* value;
    node* prev;
    node* next;
} node;

typedef struct linked_list {
    node* head;
    node* tail;
    size_t size;
} linked_list;

linked_list* new_linked_list();

void linked_list_add(linked_list* list, void* value);

void* linked_list_rm_idx(linked_list* list, int i);

void* linked_list_get_idx(linked_list* list, int index);

void linked_list_set_idx(linked_list* list, int index, void* value);

void free_linked_list(linked_list* list, int free_values);
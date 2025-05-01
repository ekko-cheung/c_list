#include <stdlib.h>

#include "list.h"

static node* new_node(void* value, node* prev, node* next) {
    node* n = (node*)malloc(sizeof(node));
    n->prev = prev;
    n->next = next;
    n->value = value;

    return n;
}

linked_list* new_linked_list() {
    linked_list* l = (linked_list*)malloc(sizeof(linked_list));
    l->head = NULL;
    l->tail = NULL;

    return l;
}

static void last_add(linked_list* list, void* value) {
    node* last = list->tail;
    node* n = new_node(value, last, NULL);
    list->tail = n;
    if (last == NULL) {
        list->head = n;
    } else {
        last->next = n;
    }
    list->size++;
}

static void head_add(linked_list* list, void* value) {
    node* first = list->head;
    node* n = new_node(value, NULL, first);
    list->head = n;
    if (first == NULL) {
        list->tail = n;
    } else {
        first->prev = n;
    }
    list->size++;
}

static node* node_get_index(linked_list* list, int index) {
    int half = list->size >> 1;
    if (index <= half) {
        node* head = list->head;
        for (int i = 0; i < index; i++) {
            head = head->next;
        }
        return head;
    }

    if (index > half) {
        node* tail = list->tail;
        for (int i = list->size - 1; i > index; i--) {
            tail = tail->prev;
        }
        return tail;
    }

    return NULL;
}

void linked_list_add(linked_list *list, void *value) {
    if (list == NULL) return;
    last_add(list, value);
}

void linked_list_add_head(linked_list* list, void* value) {
    if (list == NULL) return;
    head_add(list, value);
}

void linked_list_add_idx(linked_list* list, void* value, int index) {
    if (list == NULL || (index < 0 || index > list->size)) return;

    if (index == list->size) {
        last_add(list, value);
        return;
    }

    node* n = node_get_index(list, index);
    node* prev = n->prev;
    node* new_n = new_node(value, prev, n);
    n->prev = new_n;

    if (prev == NULL) {
        list->head = new_n;
    } else {
        prev->next = new_n;
    }

    list->size++;
}

void* linked_list_get_idx(linked_list* list, int index) {
    if (list == NULL || (index < 0 || index >= list->size)) return NULL;

    return node_get_index(list, index)->value;
}

void* linked_list_rm_idx(linked_list* list, int i) {
    if (list == NULL || (i < 0 || i >= list->size)) return NULL;

    node* n = node_get_index(list, i);
    node* prev = n->prev;
    node* next = n->next;

    if (prev == NULL) {
        list->head = next;
    } else {
        prev->next = next;
        n->prev = NULL;
    }

    if (next == NULL) {
        list->tail = prev;
    } else {
        next->prev = prev;
        n->next = NULL;
    }

    void* value = n->value;
    n->value = NULL;
    list->size--;
    free(n);

    return value;
}

void linked_list_set_idx(linked_list *list, int index, void *value) {
    if (list == NULL || (index < 0 || index >= list->size)) return;
    node_get_index(list, index)->value = value;
}

void free_linked_list(linked_list* list, int free_values) {
    if (list == NULL) return;

    node* n = list->head;
    while (n != NULL) {
        node* next = n->next;
        if (free_values) {
            free(n->value);
        }
        n->prev = NULL;
        n->next = NULL;
        n->value = NULL;
        free(n);
        n = next;
    }

    free(list);
}

void* linked_list_peek(linked_list* list) {
    if (list == NULL || list->head == NULL) return NULL;

    return list->head->value;
}
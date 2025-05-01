#include <stdio.h>
#include "list.h"

int main() {
    linked_list* l = new_linked_list();
    linked_list_add(l, "Hello");
    linked_list_add(l, "World");

    printf("%s\n", (char*)linked_list_get_idx(l, 0));
    printf("%s\n", (char*)linked_list_get_idx(l, 1));
}
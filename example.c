#include <stdio.h>
#include "list.h"
#include "array.h"

int main() {
    linked_list* l = new_linked_list();
    linked_list_add(l, "Hello");
    linked_list_add(l, "World");

    printf("%s\n", (char*)linked_list_get_idx(l, 0));
    printf("%s\n", (char*)linked_list_get_idx(l, 1));

    int num1 = 0;
    int num2 = 1;
    int num3 = 2;
    array* arr = new_array(3);
    array_add(arr, &num1);
    array_add(arr, &num2);
    array_add(arr, &num3);

    array_remove(arr, 1);
    printf("count: %ld,[%d, %d]\n", array_count(arr),  *(int*)array_get(arr, 0), *(int*)array_get(arr,1));
}
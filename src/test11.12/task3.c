#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    struct LinkedList* list = newLinkedList();
    char inp[64] = "";
    char* endptr;
    printf("Введите число (q для выхода): ");
    scanf(" %s", inp);
    while (strcmp(inp, "q") != 0) {
        int value = strtol(inp, &endptr, 10);
        pushBack(list, value);
        printf("Введите число (q для выхода): ");
        scanf(" %s", inp);
    }
    printf("Исходный список\n");
    printList(list);

    struct LinkedList* reversed = reverse(list); // возвращаем указатель на новый перевернутый список
    printf("\nПеревернутый \n");
    printList(reversed);

    clearList(list);

    return 0;
}

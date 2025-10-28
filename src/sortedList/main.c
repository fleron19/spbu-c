#include "sortedList.h"
#include <stdio.h>

void listOperations(SortedList* list, int inp)
{
    switch (inp) {
    case 1:
        int toAdd = 0;
        printf("Введите значение, которое нужно добавить в список: ");
        scanf("%d", &toAdd);
        pushElement(list, toAdd);
        break;
    case 2:
        int toRem = 0;
        printf("Введите значение, которое нужно удалить из списка: ");
        scanf("%d", &toRem);
        deleteElement(list, toRem);
        break;
    case 3:
        printf("Список:\n");
        printSortedList(list);
        break;
    default:
        printf("Неверный номер операции!\n");
    }
}
int main()
{
    SortedList* list = newSortedList();
    int inp = 0;
    printf("Введите номер операции: ");
    scanf("%d", &inp);
    while (inp) {
        listOperations(list, inp);
        printf("Введите номер операции: ");
        scanf("%d", &inp);
    }
    return 0;
}

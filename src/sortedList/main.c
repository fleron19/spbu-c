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
    printf("Это программа для оперирования сортированным списком\n");
    printf("Список операций:\n");
    printf("0 - выйти\n");
    printf("1 - добавить значение в сортированный список\n");
    printf("2 - удалить значение из списка\n");
    printf("3 - распечатать список\n");
    printf("Введите номер операции:\n");
    scanf("%d", &inp);
    while (inp) {
        listOperations(list, inp);
        printf("Введите номер операции: ");
        scanf("%d", &inp);
    }
    deleteSortedList(list);
    return 0;
}

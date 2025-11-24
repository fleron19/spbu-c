#include "sortedList.h"
#include <stdio.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

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

bool testIsEmpty()
{
    SortedList* list = newSortedList();
    return isEmpty(list);
    deleteSortedList(list);
}

bool testOneElement()
{
    SortedList* list = newSortedList();
    pushElement(list, 1);
    return !isEmpty(list);
    deleteSortedList(list);
}

bool testDeletion()
{
    SortedList* list = newSortedList();
    pushElement(list, 1);
    deleteElement(list, 1);
    return isEmpty(list);
    deleteSortedList(list);
}

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }

    if (testMode) {
        bool (*tests[3])() = { &testIsEmpty, &testOneElement, &testDeletion };
        for (int testNum = 0; testNum < 3; ++testNum) {
            if (tests[testNum]()) {
                printf(GREEN("Test %d passed!\n"), testNum + 1);
            } else {
                printf(RED("Test %d failed!\n"), testNum + 1);
                return 1;
            }
        }
        return 0;
    }
    SortedList* list = newSortedList();
    int inp = 0;
    printf("Введите номер операции: ");
    scanf("%d", &inp);
    while (inp) {
        listOperations(list, inp);
        printf("Введите номер операции: ");
        scanf("%d", &inp);
    }
    deleteSortedList(list);
    return 0;
}

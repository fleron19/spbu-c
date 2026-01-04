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
    bool res = isEmpty(list);
    deleteSortedList(list);
    return res;
}

bool testOneElement()
{
    SortedList* list = newSortedList();
    pushElement(list, 1);
    bool res = !isEmpty(list);
    deleteSortedList(list);
    return res;
}

bool testDeletion()
{
    SortedList* list = newSortedList();
    pushElement(list, 1);
    deleteElement(list, 1);
    bool res = isEmpty(list);
    deleteSortedList(list);
    return res;
}

bool testDeletionNot()
{
    SortedList* list = newSortedList();
    pushElement(list, 1);
    bool res = deleteElement(list, 2);
    return !res;
}

bool testInvariant()
{
    SortedList* list = newSortedList();
    pushElement(list, 3);
    pushElement(list, 2);
    pushElement(list, 1);
    int expected[3] = { 1, 2, 3 };
    bool res = compareSortedListAndArray(list, expected, 3);
    deleteSortedList(list);
    return res;
}

bool testSame()
{
    SortedList* list = newSortedList();
    pushElement(list, 2);
    pushElement(list, 3);
    pushElement(list, 2);
    int expected[3] = { 2, 2, 3 };
    bool res = compareSortedListAndArray(list, expected, 3);
    deleteSortedList(list);
    return res;
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
        bool (*tests[6])() = { &testIsEmpty, &testOneElement, &testDeletion,
            &testInvariant, &testSame, &testDeletionNot };
        for (int testNum = 0; testNum < 6; ++testNum) {
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

#pragma once
#include <stdbool.h>
#include <stddef.h>

typedef struct SortedList SortedList;

// creates new dynamically allocated SortedList
SortedList* newSortedList(void);
// pushes value into list
void pushElement(SortedList* list, int value);
// deletes value from list
bool deleteElement(SortedList* list, int value);
// checks that list is not empty (true = empty, false = not empty)
bool isEmpty(SortedList* list);
// deletes dynamically allocated SortedList
void deleteSortedList(SortedList* list);
// prints values of SortedList
void printSortedList(SortedList* list);
// compares values of a sorted list and an array (true = equals, false = differs)
int compareSortedListAndArray(SortedList* list, int* arr, size_t arrSize);

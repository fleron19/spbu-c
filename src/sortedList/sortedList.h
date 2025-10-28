#pragma once
#include <stdbool.h>

typedef struct SortedList SortedList;

SortedList* newSortedList(void);
void pushElement(SortedList* list, int value);
int deleteElement(SortedList* list, int value);
bool isEmpty(SortedList* list);
void deleteSortedList(SortedList* list);
void printSortedList(SortedList* list);

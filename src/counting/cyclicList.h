#pragma once
#include <stdbool.h>

typedef struct CyclicList CyclicList;

CyclicList* newCyclicList(void);
void pushElement(CyclicList* list, int value);
int deleteIndex(CyclicList* list, unsigned value);
int getElement(CyclicList* list, unsigned value);
bool isEmpty(CyclicList* list);
void deleteCyclicList(CyclicList* list);
struct CyclicListNode* lastCyclicListNode(CyclicList* list);
int lengthCyclicList(CyclicList* list);

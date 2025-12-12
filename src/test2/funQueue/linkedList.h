#pragma once
#include <stdbool.h>

typedef struct LinkedList LinkedList;

LinkedList* newLinkedList(void);
void pushElementBack(LinkedList* list, int value);
void pushElementHead(LinkedList* list, int value);
int popElementBack(LinkedList* list);
int popElementHead(LinkedList* list);
void reverse(LinkedList* list);
bool isEmpty(LinkedList* list);
void deleteLinkedList(LinkedList* list);

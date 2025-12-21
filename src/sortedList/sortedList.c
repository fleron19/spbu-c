#include "sortedList.h"
#include <stdio.h>
#include <stdlib.h>

struct SortedListNode {
    int value;
    struct SortedListNode* next;
};
struct SortedList {
    struct SortedListNode* head;
};

SortedList* newSortedList(void)
{
    SortedList* list = calloc(1, sizeof(*list));
    list->head = NULL;
    return list;
}

void pushElement(SortedList* list, int value)
{
    struct SortedListNode* node = (struct SortedListNode*)malloc(sizeof(struct SortedListNode));
    node->value = value;
    node->next = list->head;
    list->head = node;
    struct SortedListNode* prevNode = NULL;
    struct SortedListNode* currNode = node->next;
    while (currNode != NULL) {
        if (value > currNode->value) {
            node->next = currNode->next;
            currNode->next = node;
            if (prevNode) {
                prevNode->next = currNode;
            } else {
                list->head = currNode;
            }
            prevNode = currNode;
            currNode = node->next;
        } else {
            break;
        }
    }
}

bool isEmpty(SortedList* list)
{
    return list->head == NULL;
}

void deleteSortedList(SortedList* list)
{
    while (!isEmpty(list)) {
        struct SortedListNode* oldNode = list->head;
        list->head = oldNode->next;
        free(oldNode);
    }
    free(list);
}
void printSortedList(SortedList* list)
{
    if (!isEmpty(list)) {
        struct SortedListNode* currNode = list->head;
        while (currNode) {
            printf("%d ", currNode->value);
            currNode = currNode->next;
        }
        printf("\n");
    } else {
        printf("Список пуст\n");
    }
}

// Using bool so we return true or false depending on was the value in the list
bool deleteElement(SortedList* list, int value) 
{
    if (isEmpty(list)) {
        return false;
    }
    struct SortedListNode* prevNode = NULL;
    struct SortedListNode* currNode = list->head;
    while (currNode) {
        if (value == currNode->value) {
            if (prevNode) {
                prevNode->next = currNode->next;
            } else {
                list->head = currNode->next;
            }
            free(currNode);
            return true;
        }
        prevNode = currNode;
        currNode = currNode->next;
    }
    return false; // value was not presented
}

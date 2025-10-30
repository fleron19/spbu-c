#include "cyclicList.h"
#include <stdio.h>
#include <stdlib.h>

struct CyclicListNode {
    int value;
    struct CyclicListNode* next;
};

struct CyclicList {
    struct CyclicListNode* head;
};

CyclicList* newCyclicList(void)
{
    CyclicList* list = calloc(1, sizeof(*list));
    list->head = NULL;
    return list;
}

void pushElement(CyclicList* list, int value)
{
    struct CyclicListNode* node = malloc(sizeof(struct CyclicListNode));
    node->value = value;

    if (isEmpty(list)) {
        node->next = node;
        list->head = node;
    } else {
        node->next = list->head->next;
        list->head->next = node;
        list->head = node;
    }
}
bool isEmpty(CyclicList* list)
{
    return list->head == NULL;
}

int lengthCyclicList(CyclicList* list)
{
    if (isEmpty(list)) {
        return 0;
    } else {
        struct CyclicListNode* first = list->head;
        struct CyclicListNode* nextNode = first->next;
        int count = 1;
        while (nextNode != first) {
            count += 1;
            nextNode = nextNode->next;
        }
        return count;
    }
}
void deleteCyclicList(CyclicList* list)
{
    if (isEmpty(list)) {
        free(list);
        return;
    }

    struct CyclicListNode* current = list->head->next;
    struct CyclicListNode* nextNode = NULL;

    while (current != list->head) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
    free(list->head);
    list->head = NULL;
    free(list);
}

int deleteIndex(CyclicList* list, unsigned index) // deletenig by index instead of value, 1 - correct delition, 0 - incorrect
{
    if (isEmpty(list)) {
        return 0;
    }

    struct CyclicListNode* firstNode = list->head->next;

    if (index == 0) {
        if (firstNode->next == firstNode) {
            list->head = NULL;
        } else {
            list->head->next = firstNode->next;
        }
        free(firstNode);
        return 1;
    }

    struct CyclicListNode* currNode = firstNode;
    for (unsigned i = 0; i < index - 1; ++i) {
        currNode = currNode->next;
    }

    struct CyclicListNode* toDelete = currNode->next;
    currNode->next = toDelete->next;

    if (toDelete == list->head) {
        list->head = currNode;
    }

    free(toDelete);
    return 1;
}
int getElement(CyclicList* list, unsigned index)
{
    if (!isEmpty(list)) {
        struct CyclicListNode* prevNode = NULL;
        struct CyclicListNode* currNode = list->head;
        for (unsigned i = 0; i <= index; ++i) {
            if (currNode) {
                prevNode = currNode;
                currNode = currNode->next;
            } else {
                return -1;
            }
        }
        return currNode->value;
    } else {
        return -1;
    }
}
struct CyclicListNode* lastCyclicListNode(CyclicList* list)
{
    if (isEmpty(list)) {
        return NULL;
    }

    struct CyclicListNode* currNode = list->head;
    while (currNode->next != list->head) {
        currNode = currNode->next;
    }
    return currNode;
}

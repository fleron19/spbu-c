#include "linkedList.h"
#include <stdio.h>
#include <stdlib.h>

struct LinkedListNode {
    int value;
    struct LinkedListNode* next;
};
struct LinkedList {
    struct LinkedListNode* head;
};

LinkedList* newLinkedList(void)
{
    LinkedList* list = calloc(1, sizeof(*list));
    list->head = NULL;
    return list;
}

bool isEmpty(LinkedList* list)
{
    return list->head == NULL;
}

void deleteLinkedList(LinkedList* list)
{
    while (!isEmpty(list)) {
        struct LinkedListNode* oldNode = list->head;
        list->head = oldNode->next;
        free(oldNode);
    }
    free(list);
}

int popElementHead(LinkedList* list)
{
    if (!isEmpty(list)) {
        struct LinkedListNode* currNode = list->head;
        int val = currNode->value;
        struct LinkedListNode* nextNode = currNode->next;
        list->head = nextNode;
        free(currNode);
        return val;

    } else {
        return -1;
    }
}

int popElementBack(LinkedList* list)
{
    if (!isEmpty(list)) {
        struct LinkedListNode* prevNode = list->head;
        struct LinkedListNode* currNode = prevNode->next;
        struct LinkedListNode* nextNode;
        if (currNode) {
            struct LinkedListNode* nextNode = prevNode->next;
        } else {
            return popElementHead(list);
        }
        while (nextNode) {
            prevNode = currNode;
            currNode = prevNode->next;
            nextNode = currNode->next;
        }
        int val = currNode->value;
        free(currNode);
        prevNode->next = NULL;
        return val;
    } else {
        return -1;
    }
}

void pushElementHead(LinkedList* list, int value)
{
    struct LinkedListNode* node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
    node->value = value;
    node->next = list->head;
    list->head = node;
}

void pushElementBack(LinkedList* list, int value)
{
    if (!isEmpty(list)) {
        struct LinkedListNode* prevNode = list->head;
        struct LinkedListNode* currNode = prevNode->next;
        while (currNode) {
            prevNode = currNode;
            currNode = prevNode->next;
        }
        struct LinkedListNode* node = (struct LinkedListNode*)malloc(sizeof(struct LinkedListNode));
        node->value = value;
        prevNode->next = node;
    } else {
        pushElementHead(list, value);
    }
}

void reverse(LinkedList* list)
{
    if (!isEmpty(list)) {
        struct LinkedListNode* prevNode = NULL;
        struct LinkedListNode* currNode = list->head;
        if (!currNode) {
            return;
        }
        while (currNode) {
            struct LinkedListNode* next = currNode->next;

            currNode->next = prevNode;

            prevNode = currNode;
            currNode = next;
        }
    }
}

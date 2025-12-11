#include <stdlib.h>
#include <stdio.h>

struct Node {
    int data;
    struct Node* next;
};

struct LinkedList {
    struct Node* head;
};

struct LinkedList* newLinkedList()
{
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    return newList;
}
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void pushBack(struct LinkedList* list, int data)
{
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    struct Node* temp = list->head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

struct LinkedList* reverse(struct LinkedList* listin)
{
    struct LinkedList* copy = malloc(sizeof *copy);
    copy->head = NULL;
    struct Node* tail = NULL;
    for (struct Node* p = listin->head; p; p = p->next) {
        struct Node* n = malloc(sizeof *n);
        n->data = p->data;
        n->next = NULL;
        if (!copy->head)
            copy->head = tail = n;
        else {
            tail->next = n;
            tail = n;
        }
    }
    if (copy == NULL || copy->head == NULL)
        return copy;

    struct Node* prev = NULL;
    struct Node* current = copy->head;
    struct Node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    copy->head = prev;
    return copy;
}

void clearList(struct LinkedList* list)
{
    if (list == NULL)
        return;
    struct Node* curr = list->head;
    while (curr != NULL) {
        struct Node* tmp = curr->next;
        free(curr);
        curr = tmp;
    }
    list->head = NULL;
    free(list);
}

void printList(struct LinkedList* list)
{
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("END\n");
}


#pragma once

struct Node;
struct LinkedList;
struct LinkedList* newLinkedList();
struct Node* createNode(int data);
void pushBack(struct LinkedList* list, int data);
struct LinkedList* reverse(struct LinkedList* listin);
void clearList(struct LinkedList* list);
void printList(struct LinkedList* list);

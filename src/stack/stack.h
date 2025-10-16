#pragma once


typedef struct {
    char value;
    struct StackNode* next;
} StackNode;

typedef struct {
    struct StackNode* head;
} Stack;

Stack newStack(void);
void push(Stack* stack, char value);
char pop(Stack* stack);

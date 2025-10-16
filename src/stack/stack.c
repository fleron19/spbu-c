#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

  
struct StackNode {
    char value;
    struct StackNode* next;
};
struct Stack{
    struct StackNode* head;
};

Stack newStack(void)
{
    Stack stack = { .head = NULL };
    return stack;
}

void push(Stack* stack, char value)
{
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode));

    node->value = value;
    node->next = stack->head;
    stack->head = node;
}
char pop(Stack* stack)
{
      if (stack->head == NULL) {
        return '\0';
    }
    struct StackNode* oldNode = stack->head;
    char res = oldNode->value;
    stack->head = oldNode->next;

    free(oldNode);
    return res;
}


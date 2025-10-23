#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

struct StackNode {
    char value;
    struct StackNode* next;
};
struct Stack {
    struct StackNode* head;
};

Stack* newStack(void)
{
    Stack* stack = calloc(1, sizeof(*stack));
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

bool isEmpty(Stack* stack)
{
    return stack->head == NULL;
}

void deleteStack(Stack* stack)
{
    while (!isEmpty(stack)) {
        pop(stack);
    }
    free(stack);
}

char top(Stack* stack)
{
    if (!isEmpty(stack)){
        return stack->head->value;
    }
    return '\0';
}

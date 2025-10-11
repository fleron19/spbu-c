#include <stdio.h>
#include <stdlib.h>

typedef struct StackNode StackNode;

struct StackNode {
    int value;
    StackNode* next;
};
typedef struct {
    StackNode* head;
} Stack;

Stack new(void)
{
    Stack stack = { .head = NULL };
    return stack;
}

void push(Stack* stack, int value)
{
    StackNode* node = (StackNode*)malloc(sizeof(StackNode*));

    node->value = value;
    node->next = stack->head;
    stack->head = node;
}
int pop(Stack* stack)
{
    StackNode* oldNode = stack->head;
    int res = oldNode->value;
    stack->head = oldNode->next;

    free(oldNode);
    return res;
}
int main(void)
{
    Stack stack = new ();

    push(&stack, 1);
    push(&stack, 2);

    int a = pop(&stack);

    printf("%d\n", a);

    return 0;
}

#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* newStack(void);
void push(Stack* stack, char value);
// can pop only from non-empty stack, checking it with isEmpty before opping is necessary
char pop(Stack* stack);
bool isEmpty(Stack* stack);
// every created stack should be eventually deleted using this function to prevent memory leakage
void deleteStack(Stack* stack);
// can see top element non-empty stack, checking it with isEmpty before opping is necessary
char top(Stack* stack);

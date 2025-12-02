#pragma once
#include <stdbool.h>

typedef struct Stack Stack;

Stack* newStack(void);
void push(Stack* stack, char value);
char pop(Stack* stack);
bool isEmpty(Stack* stack);
void deleteStack(Stack* stack);

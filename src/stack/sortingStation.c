#include "stack.h"
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int operatorPriority(char op1, char op2) // 0 - одинаковый приоритет, 1 - op1 приоритетнее, 2 - op2 приоритетнее
{
    if ((op1 == '+') || (op1 == '-') && (op2 == '*') || (op2 == '/')) {
        return 2;
    } else if ((op1 == '*') || (op1 == '/') && (op2 == '-') || (op2 == '+')) {
        return 1;
    }
    return 0;
}

bool isOperator(char sym)
{
    return (sym == '/' || sym == '+' || sym == '-' || sym == '*');
}

char* sortingStation(char* str)
{
    char space = ' ';
    Stack* stack = newStack();
    char* ret = (char*)calloc(2 * strlen(str), sizeof(char)); // already fills with \0 => res is C-string
    for (int i = 0; i < strlen(str); i++) {
        char sym = str[i];
        if (isdigit(sym)) {
            strncat(ret, &sym, 1);
            strncat(ret, &space, 1);
        } else if (isOperator(sym)) {
            if (!isEmpty(stack)) {
                while (isOperator(top(stack))) {
                    if (operatorPriority(top(stack), sym) <= 1) {
                        char token = pop(stack);
                        strncat(ret, &token, 1);
                        strncat(ret, &space, 1);
                    } else {
                        break;
                    }
                    if (isEmpty(stack)) {
                        break;
                    }
                }
            }
            push(stack, sym);
        } else if (sym == '(') {
            push(stack, sym);
        } else if (sym == ')') {
            if (isEmpty(stack)) {
                deleteStack(stack);
                return "Error! Missing bracket!";
            }
            while (top(stack) != '(') {
                char token = pop(stack);
                strncat(ret, &token, 1);
                strncat(ret, &space, 1);
                if (isEmpty(stack)) {
                    deleteStack(stack);
                    return "Error! Missing bracket!";
                }
            }
            pop(stack);
        }
    }
    while (!isEmpty(stack)) {
        char op = pop(stack);
        if (op == '(') {
            deleteStack(stack);
            return "Error! Missing bracket!";
        } else if (isOperator(op)) {
            strncat(ret, &op, 1);
            strncat(ret, &space, 1);
        }
    }
    deleteStack(stack);
    return ret;
}
int main(void)
{
    char input[200];
    scanf("%[^\n]", input);
    char* res = sortingStation(input);
    printf("%s\n", res);
    free(res);
    return 0;
}

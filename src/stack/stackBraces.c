#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool isValid(char* str)
{
    Stack* stack = newStack();
    for (int i = 0; i < (int)strlen(str); i++) {
        char curr = str[i];
        if ((curr == '(') || (curr == '[') || (curr == '{')) {
            push(stack, curr);
        } else if ((curr == ')') || (curr == ']') || (curr == '}')) {
            if (!isEmpty(stack)) {
                char last = pop(stack);
                if ((curr == ')') && (last != '(')) {
                    deleteStack(stack);
                    return false;
                }
                if ((curr == '}') && (last != '{')) {
                    deleteStack(stack);
                    return false;
                }
                if ((curr == ']') && (last != '[')) {
                    deleteStack(stack);
                    return false;
                }
            } else {
                deleteStack(stack);
                return false;
            }
        }
    }
    bool res = isEmpty(stack);
    deleteStack(stack);
    return res;
}
int main(void)
{
    const int BUFF = 100;
    char input[BUFF];
    scanf("%[^\n]", input);
    bool res = isValid(input);
    if (res) {
        printf("%s", "Valid!");
    } else {
        printf("%s", "Not valid!");
    }

    printf("\n");

    return 0;
}

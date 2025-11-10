#include "stack.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool isValid(char* str)
{
    Stack* stack = newStack();
    for (int i = 0; i < strlen(str); i++) {
        if ((str[i] == '(') || (str[i] == '[') || (str[i] == '{')) {
            push(stack, str[i]);
        } else if ((str[i] == ')') || (str[i] == ']') || (str[i] == '}')) {
            if (!isEmpty(stack)) {
                char last = pop(stack);
                if (((str[i] == ')') && (last != '(')) || ((str[i] == '}') && (last != '{')) || ((str[i] == ']') && (last != '['))) {
                    return false;
                }
            } else {
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
    char input[100];
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

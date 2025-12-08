#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

bool isValid(char* str)
{
    Stack* stack = newStack();
    for (int i = 0; i < (int)strlen(str); i++) {
        char ch = str[i];
        if ((ch == '(') || (ch == '[') || (ch == '{')) {
            push(stack, ch);
        } else if ((ch == ')') || (ch == ']') || (ch == '}')) {
            if (!isEmpty(stack)) {
                char last = pop(stack);
                if ((ch == ')') && (last != '(')) {
                    deleteStack(stack);
                    return false;
                }
                if ((ch == '}') && (last != '{')) {
                    deleteStack(stack);
                    return false;
                }
                if ((ch == ']') && (last != '[')) {
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

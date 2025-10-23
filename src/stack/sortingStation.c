#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "stack.h"
int operatorPriority(char op1, char op2) // 0 - одинаковый приоритет, 1 - op1 приоритетнее, 2 - op2 приоритетнее
{
    if (op1 == '+' || op1 == '-' && op2 == '*' || op2 == '/'){
        return 2;
    }
    else if (op1 == '*' || op1 == '/' && op2 == '-' || op2 == '+'){
        return 1;
    }
    return 0;
}

bool isOperator(char sym)
{
    return (sym == '/' || sym == '+' || sym == '-' || sym == '*');
}

char* sortingStation(char* str){
    char space = ' ';
    Stack* stack = newStack();
    char* ret = (char*)malloc(sizeof (char) * 200);
    for (int i = 0; i < strlen(str); i++){
        char sym = str[i] ;
        if (isdigit(sym)){
            strncat(ret, &sym, 1);
            strncat(ret, &space, 1);   
        }
        else if (isOperator(sym)){
            while (isOperator(top(stack))){
                if (operatorPriority(top(stack), sym) <= 1){
                    char token = pop(stack);
                    strncat(ret, &token, 1);
                    strncat(ret, &space, 1);   
                }
                else{
                    break;
                }
            }
            push(stack, sym);
        }
        else if (sym == '('){
            push(stack, sym);
        }
        else if (str[i] == ')'){
            while (top(stack) != '('){
                if (isEmpty(stack)){
                    return "Error! Missing bracket!";
                }
                char token = pop(stack);
                strncat(ret, &token, 1);
                strncat(ret, &space, 1);
            }
            pop(stack);
        }
    }
    while (!isEmpty(stack)){
        char op = pop(stack);
        if (op == '('){
            return "Error! Missing bracket!";    
        }
        else if (isOperator(op)){
            strncat(ret, &op, 1);
            strncat(ret, &space, 1);   
        }
       
    }
    deleteStack(stack);
    ret[strlen(ret) - 1] = '\0';
    return ret;    
}
int main(void)
{
    char input[200];
    scanf("%[^\n]", input);
    char* res = sortingStation(input);
    printf("%s\n", res);
    return 0;
}


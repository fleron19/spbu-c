#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "stack.h"

char sortingStation(char* str){
    char ret[200];
    for (int i = 0; i < strlen(str); i++){
        if (isdigit(str[i]) || str[i] == ' '){
            strcat(ret, str[i]);
        }
    }    
}
int main(void)
{
    char input[200];
    scanf("%[^\n]", input);
    char res = sortingStation(&input);
    printf("%s\n", res);

    return 0;
}


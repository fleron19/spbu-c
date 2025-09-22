#include <stdio.h>
#include <stdbool.h>
bool bracketsBalanced(char *toTest) 
{
    int i = 0;
    int counter = 0;
    while (toTest[i] != '\0'){
        if (toTest[i] == '('){
            counter++;
        }
        else {
            if (toTest[i] == ')') {
                counter--;
            } 
        }
        if (counter < 0) {
            return false;
        }
        i++;
    }
    if (counter == 0) {
        return true;
    }
    else {
        return false;
    }
}

int main(void)
{
    char test1[] = "()(test1((asd))qwe)*()((123))"; // Balanced
    char test2[] = "((()()))"; // Balanced
    char test3[] = "())()"; // Unbalanced
    printf("Test 1: %s\n", bracketsBalanced(test1) ? "Balanced" : "Unbalanced");
    printf("Test 2: %s\n", bracketsBalanced(test2) ? "Balanced" : "Unbalanced");
    printf("Test 3: %s\n", bracketsBalanced(test3) ? "Balanced" : "Unbalanced");
    return 0;
}
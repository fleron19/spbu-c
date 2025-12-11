#include "merge_sort.h"
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

char* toArray(int number)
{
    int n = 1;
    if (number != 0) {
        n = log10(number) + 1;
    }
    int i;
    char* numberArray = calloc(n, sizeof(char));
    for (i = n - 1; i >= 0; --i, number /= 10) {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

char* make_smallest(int num)
{
    char* chnum = toArray(num);
    mergeSort(chnum, 0, log10(num));
    return chnum;
}
int tests()
{
    int test1num = 321;
    int test2num = 0;
    int test3num = 55555;
    int test4num = 1234;
    char* res1 = make_smallest(test1num);
    char* res2 = make_smallest(test2num);
    char* res3 = make_smallest(test3num);
    char* res4 = make_smallest(test4num);
    if (!strcmp(res1, "123")) {
        printf(GREEN("Test 1 passed!\n"));
    } else {
        printf(RED("Test 1 failed!\n"));
        return 1;
    }
    if (!strcmp(res2, "0")) {
        printf(GREEN("Test 2 passed!\n"));
    } else {
        printf(RED("Test 2 failed!\n"));
        return 1;
    }
    if (!strcmp(res3, "55555")) {
        printf(GREEN("Test 3 passed!\n"));
    } else {
        printf(RED("Test 3 failed!\n"));
        return 1;
    }
    if (!strcmp(res4, "1234")) {
        printf(GREEN("Test 4 passed!\n"));
    } else {
        printf(RED("Test 4 failed!\n"));
        return 1;
    }
    return 0;
}

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }

    if (testMode) {
        int res = tests();
        return res;
    }
    int num = 0;
    printf("Enter a number: ");
    scanf("%d", &num);
    char* chnum = make_smallest(num);
    for (int i = 0; i < sizeof(chnum); i++) {
        printf("%c", chnum[i]);
    }
    printf("\n");
}

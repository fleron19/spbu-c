#include "merge_sort.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


char* toArray(int number)
{
    int n = log10(number) + 1;
    int i;
    char* numberArray = calloc(n, sizeof(char));
    for (i = n - 1; i >= 0; --i, number /= 10) {
        numberArray[i] = (number % 10) + '0';
    }
    return numberArray;
}

char* make_smallest(int num)
{
    char *chnum = toArray(num);
    mergeSort(chnum, 0, log10(num));
    return chnum;
}

int main()
{
    int num = 352;
    char* chnum = make_smallest(num);
    for (int i = 0; i < sizeof(chnum); i++) {
        printf("%c", chnum[i]);
    }
}

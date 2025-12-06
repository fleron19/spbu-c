#include "sorting.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    const int SIZE = 100;
    int count = 0;
    int arr[SIZE];
    int buff[SIZE];
    int original[SIZE];
    char input[2048];

    memcpy(original, arr, sizeof(arr));
    memset(arr, 0, sizeof(arr));
    memset(buff, 0, sizeof(buff));

    printf("Enter numbers (quantity <= 100): ");
    scanf("%[^\n]", input);
    getchar();

    char* token = strtok(input, " ");
    while (token != NULL) {
        arr[count] = atoi(token);
        count++;
        if (count > 100) {
            printf("Error! Only 100 numbers or less is allowed!\n");
            return -1;
        }
        token = strtok(NULL, " ");
    }
    if (count == 0) {
        printf("Error! Empty input!\n");
        return -1;
    } else {
        int* sorted = mergeSort(arr, buff, 0, count - 1);

        printf("Sorted array (%d elements): ", count);
        for (int i = 0; i < count; i++) {
            printf("%d ", sorted[i]);
        }
        printf("\n");

        int changed = 0;
        for (int i = 0; i < count; i++) {
            if (sorted[i] != original[i]) {
                changed++;
            }
        }
        return changed;
    }
}

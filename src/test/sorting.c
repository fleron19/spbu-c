#include <stdio.h>

void swap(int* a, int* b)
{ // swap elements
    int temp = *a;
    *a = *b;
    *b = temp;
}

void gnomeSort(int arr[], int n)
{
    int index = 0;
    while (index < n) {
        if (index == 0) {
            index++; // if at the beginning, move forward
        } else if (arr[index] >= arr[index - 1]) {
            index++; // if elements are in order, move forward
        } else {
            swap(&arr[index], &arr[index - 1]); // swap if out of order
            index--; // move backward to check the swapped element
        }
    }
}

int main(void)
{
    int arr[] = { 1, 7, 8, 2, 5, 4 };
    int arr2[] = { 1 };
    gnomeSort(arr2, 1);
    gnomeSort(arr, 6);
    for (int i = 0; i < 6; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

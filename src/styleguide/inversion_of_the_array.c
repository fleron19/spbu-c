#include <stdio.h>


void reverse(int arr[], int start, int end)
{
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void swapSegments(int arr[], int m, int n)
{
    reverse(arr, 0, m + n - 1);
    reverse(arr, 0, n - 1);
    reverse(arr, n, m + n - 1);
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int m = 2, n = 6; 
    int total = m + n;
    
    printf("Исходный массив: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    swapSegments(arr, m, n);
    
    printf("После перестановки: ");
    for (int i = 0; i < total; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}

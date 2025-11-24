#include <stdio.h>

int countNulls(int arr[], int size)
{
    int counter = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            counter++;
        }
    }
    return counter;
}

int main()
{
    const int SIZE = 5;
    int myArr[5] = { 1, 0, 4, 0, 0 };
    printf("%d", countNulls(myArr, SIZE));
    return 0;
}

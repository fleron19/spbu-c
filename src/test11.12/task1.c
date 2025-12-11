#include "merge_sort_int.h"
#include <stdio.h>

int main()
{
    int n = 0;
    int vals[1000] = { 0 };
    int count = 0;
    printf("Enter integers (enter 0 to stop):\n");
    int curr = 0;
    while (scanf("%d", &n) == 1 && n != 0) {
        if (count < 1000)
            vals[count++] = n;
    }
    if (count == 0)
        return 0;
    mergeSort(vals, 0, count - 1);

    int i = 0;
    while (i < count) {
        int value = vals[i];
        int cnt = 0;
        while (i < count && vals[i] == value) {
            cnt++;
            i++;
        }
        printf("%d = %d\n", value, cnt);
    }
    return 0;
}

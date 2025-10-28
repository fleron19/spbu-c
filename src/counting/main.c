#include "cyclicList.h"
#include <stdio.h>

int main()
{
    CyclicList* list = newCyclicList();
    int n, m = 0;
    printf("Введите n: ");
    scanf("%d", &n);
    printf("Введите m: ");
    scanf("%d", &m);

    for (int i = 1; i <= n; i++) {
        pushElement(list, i);
    }

    int current = 0;
    while (lengthCyclicList(list) > 1) {
        current = (current + m - 1);
        deleteIndex(list, current);
    }

    int lastAlive = getElement(list, 0);
    printf("Последний выживший - воин номер %d\n", lastAlive);

    deleteCyclicList(list);
    return 0;
}

#include "sorting.h"

int* mergeSort(int* up, int* down, unsigned left, unsigned right)
{
    if (left == right) {
        down[left] = up[left];
        return down;
    }

    unsigned int middle = left + (right - left) / 2;

    int* lBuff = mergeSort(up, down, left, middle);
    int* rBuff = mergeSort(up, down, middle + 1, right);

    int* target = lBuff == up ? down : up;

    unsigned int lCur = left, rCurr = middle + 1;
    for (unsigned int i = left; i <= right; i++) {
        if (lCur <= middle && rCurr <= right) {
            if (lBuff[lCur] < rBuff[rCurr]) {
                target[i] = lBuff[lCur];
                lCur++;
            } else {
                target[i] = rBuff[rCurr];
                rCurr++;
            }
        } else if (lCur <= middle) {
            target[i] = lBuff[lCur];
            lCur++;
        } else {
            target[i] = rBuff[rCurr];
            rCurr++;
        }
    }
    return target;
}

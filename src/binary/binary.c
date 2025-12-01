#include "binary.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

char* intToBin(int num)
{
    char* bits = calloc(32, sizeof(char));
    for (int i = 0; i < 32; i++) {
        bits[31 - i] = (num >> i) & 1;
    }
    return bits;
}

int binToInt(char* num)
{
    int res = 0;
    // if num - positive
    if (num[0] == 0) {
        for (int i = 31; i >= 0; i--) {
            if (num[i]) {
                res += 1 << 31 - i;
            }
        }
        return res;
    // if num - negative
    } else {
        for (int i = 31; i >= 0; i--) {
            if (!num[i]) {
                res += 1 << 31 - i;
            }
        }
        res += 1;
        return -res;
    }
}
void printBin(char* num, bool full)
{
    bool leading = full;
    for (int i = 0; i < 32; i++) {
        if (!leading) {
            leading = (num[i] == 1);
        }
        if (leading) {
            printf("%d", num[i]);
        }
    }
    if (!leading) {
        printf("0");
    }
    printf("\n");
}

char* binSum(char* f, char* s)
{
    char* res = calloc(32, sizeof(char));
    char d = 0;
    char curr = 0;
    for (int i = 31; i >= 0; i--) {
        curr = 0;
        curr += s[i];
        curr += f[i];
        curr += d;
        if (curr == 1){
            res[i] = 1;
            d = 0;
        }
        else if (curr == 2){
            d = 1;
        }
        else if (curr == 3){
            d = 1;
            res[i] = 1;
        }

    }
    return res;
}

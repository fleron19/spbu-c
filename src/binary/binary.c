#include "binary.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

struct BinaryNum {
    bool bits[32];
};

struct BinaryNum* intToBin(int32_t number)
{
    struct BinaryNum* binNum = { calloc(32, sizeof(bool)) };
    for (int i = 0; i < 32; i++) {
        binNum->bits[31 - i] = (number >> i) & 1;
    }
    return binNum;
}

int binToInt(struct BinaryNum* num)
{
    int res = 0;
    int s = 0;
    for (int i = 31; i > 0; i--) {
        s += num->bits[i] * (1 << (31 - i));
    }
    res = -(num->bits[0] * (1 << 31)) + s;
}
void printBin(struct BinaryNum* num, bool full)
{
    // if we want to print binary without leading zeros, simply skip all the bits before we reach first 1
    // then print all bits except last
    // and always print last bit
    bool leading = full;
    for (int i = 0; i < 31; i++) {
        if (!leading) {
            leading = num->bits[i];
        }
        if (leading) {
            printf("%d", num->bits[i]);
        }
    }
    printf("%d", num->bits[31]);
    printf("\n");
}

struct BinaryNum* binSum(struct BinaryNum* f, struct BinaryNum* s)
{
    struct BinaryNum* res = { calloc(32, sizeof(char)) };
    bool carry = 0;
    for (int i = 31; i >= 0; i--) {
        bool a = s->bits[i];
        bool b = f->bits[i];
        res->bits[i] = a ^ b ^ carry;
        carry = (a * b) + (carry * (a ^ b));
    }
    return res;
}

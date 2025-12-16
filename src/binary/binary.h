#pragma once
#include <stdbool.h>

struct binaryNum* intToBin(int num);
int binToInt(struct binaryNum* num);
struct binaryNum* binSum(struct binaryNum* f, struct binaryNum* s);
// use full to see all bits, including leading zeros
void printBin(struct binaryNum* num, bool full);

#pragma once
#include <stdbool.h>

struct BinaryNum;
struct BinaryNum* intToBin(int num);
int binToInt(struct BinaryNum* num);
struct BinaryNum* binSum(struct BinaryNum* f, struct BinaryNum* s);
// use full to see all bits, including leading zeros
void printBin(struct BinaryNum* num, bool full);

#pragma once
#include <stdbool.h>

char* intToBin(int num);
int binToInt(char* num);
char* binSum(char* f, char* s);
//use full to see all bits, including leading zeros
void printBin(char* num, bool full);

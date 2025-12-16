#include "binary.h"
#include <stdio.h>
#include <string.h>

#define GREEN(string) "\x1b[32m" string "\x1b[0m"
#define RED(string) "\x1b[31m" string "\x1b[0m"

int main(int argc, char** argv)
{
    bool testMode = false;
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "--test") == 0) {
            testMode = true;
            break;
        }
    }

    if (testMode) {
        const int TEST_NUM = 10;
        int tests[10][3] = {
            { 111, 65, 176 },
            { 654, 78, 732 },
            { 0, 0, 0 },
            { -30, -170, -200 },
            { 5, -93, -88 },
            { -51, 208, 157 },
            { 12, 0, 12 },
            { -123, 0, -123 },
            { 1, -109, -108 },
            { 10, 20, 30 }
        };
        for (int test = 0; test < TEST_NUM; ++test) {
            struct binaryNum* bnum1 = intToBin(tests[test][0]);
            struct binaryNum* bnum2 = intToBin(tests[test][1]);
            struct binaryNum* resb = binSum(bnum1, bnum2);
            int res = binToInt(resb);
            if (tests[test][2] == res) {
                printf(GREEN("Test %d passed!\n"), test + 1);
            } else {
                printf(RED("Test %d failed!\n"), test + 1);
                return 1;
            }
        }
        return 0;
    }
    int num1 = 0;
    int num2 = 0;
    printf("n1 = ");
    scanf("%d", &num1);
    printf("n2 = ");
    scanf("%d", &num2);
    struct binaryNum* bnum1 = intToBin(num1);
    struct binaryNum* bnum2 = intToBin(num2);
    printBin(bnum1, true);
    printf("+\n");
    printBin(bnum2, true);
    printf("--------------------------------\n");
    struct binaryNum* res = binSum(bnum1, bnum2);
    printBin(res, true);
    int n = binToInt(res);
    printf("%d\n", n);
}

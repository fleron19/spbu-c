#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef union {
    double d;
    uint64_t u;
    unsigned char bytes[8];
} double_bits;

void prinSm2p(double x)
{
    double_bits db;
    memcpy(db.bytes, &x, sizeof db.bytes);
    uint64_t u = db.u;

    int sign = (u >> 63) & 1;
    uint64_t exp_bits = (u >> 52) & 0x7FFULL;
    uint64_t frac = u & ((1ULL << 52) - 1);
    const int bias = 1023;

    if (exp_bits == 0) {
        printf("Result: %c0.0*2^0\n", sign ? '-' : '+');
        return;
    }

    int exp_unbiased = (int)exp_bits - bias;
    double mantissa = 1.0 + (double)frac / (double)(1ULL << 52);
    printf("Result: %c%.20g*2^%d\n", sign ? '-' : '+', mantissa, exp_unbiased);
}

int main(void)
{
    double x;
    if (printf("Enter a number: "), fflush(stdout), scanf("%lf", &x) == 1) {
        prinSm2p(x);
    } else {
        printf("Error!\n");
    }
    return 0;
}

#include <stdint.h>
#include <stdio.h>

typedef union {
    double d;
    uint64_t u;
    struct {
#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
        uint64_t frac : 52;
        uint64_t exp  : 11;
        uint64_t sign : 1;
#else
        uint64_t sign : 1;
        uint64_t exp  : 11;
        uint64_t frac : 52;
#endif
    } parts;
} doubleBits;

void printSm2p(double x)
{
    doubleBits db;
    db.d = x;
    int sign = db.parts.sign;
    uint64_t exp_bits = db.parts.exp;
    uint64_t frac = db.parts.frac;
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
    printf("Enter a number: ");
    scanf("%lf", &x);
    printSm2p(x);
    return 0;
}

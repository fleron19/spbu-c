#include <stdint.h>
#include <stdio.h>

typedef union {
    double d;
    uint64_t u;
<<<<<<< HEAD
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
} double_bits;
=======
    unsigned char bytes[8];
} DoubleBits;
>>>>>>> 5ce1d6be535301bc8623446422389c1cd507b769

void printSm2p(double x)
{
    double_bits db;
<<<<<<< HEAD
    db.d = x;
    int sign = db.parts.sign;
    uint64_t exp_bits = db.parts.exp;
    uint64_t frac = db.parts.frac;
=======
    memcpy(db.bytes, &x, sizeof db.bytes);
    uint64_t u = db.u;

    int sign = (u >> 63) & 1;
    uint64_t expBits = (u >> 52) & 0x7FFULL;
    uint64_t frac = u & ((1ULL << 52) - 1);
>>>>>>> 5ce1d6be535301bc8623446422389c1cd507b769
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
    if (scanf("%lf", &x) == 1) prinSm2p(x);
    return 0;
}

#include <stdio.h>
void unsignedDivision(int dividend, int divisor, int *quotient, int *remainder)
{
    *quotient = 0;
    *remainder = dividend;
    while (*remainder >= divisor) {
        (*quotient)++;
        *remainder -= divisor;
    }
}

void divisionWithRemainder(int dividend, int divisor, int *quotient, int *remainder)
{
    if (divisor != 0) {
        if (divisor < 0) {
            divisionWithRemainder(dividend, -divisor, quotient, remainder);
            *quotient = -*quotient;
        }
        if (dividend < 0 && divisor > 0) {
            divisionWithRemainder(-dividend, divisor, quotient, remainder);
            *quotient = -*quotient;
            if (*remainder != 0){
                (*quotient) --;
                *remainder = divisor - *remainder;
            }
        }
        if (divisor >  0 && dividend > 0) {
            unsignedDivision(dividend, divisor, quotient, remainder);   
        } 
    }
    else {
        printf("Zero division error!\n");
    }
}

int main(void)
{  
    int n = 15;
    int d = -4;
    int q = 0;
    int r = 0;
    divisionWithRemainder(n, d, &q, &r);
    printf("%d : %d = %d + %d\n", n, d, q, r);
    return 0;
}

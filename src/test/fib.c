#include <stdlib.h>
#include <stdio.h>

int fibSum(int notBigger){
    int sum = 0;
    int num1 = 0;
    int num2 = 1;
    int buff = 0;
    while (num2 <= notBigger) {
        if (num2 % 2 == 0) {
            sum += num2;
        }
        buff = num2;
        num2 = num1 + num2;
        num1 = buff;
    }
    return sum;
}

int main(void)
{
    printf("%d", fibSum(1000000));
}

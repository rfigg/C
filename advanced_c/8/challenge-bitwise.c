/*
Do some bitwise operations and display results in binary
*/

#include <stdio.h>

long long decimalToBinary(int dec);

int main()
{
    int a = 0, b = 0;

    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);

    //printf("%d, %d\n", decimalToBinary(a), decimalToBinary(b));

    printf("Result of ~ on %d(%lld) is: %lld\n", a, decimalToBinary(a), decimalToBinary(~a));
    printf("Result of ~ on %d(%lld) is: %lld\n", b, decimalToBinary(b), decimalToBinary(~b));

    printf("%lld & %lld: %lld\n", decimalToBinary(a), decimalToBinary(b), decimalToBinary(a & b));
    printf("|: %lld\n", decimalToBinary(a | b));
    printf("^: %lld\n", decimalToBinary(a ^ b));

    printf("%lld >> 2: %lld\n", decimalToBinary(a), decimalToBinary(a >> 2));
    printf("%lld << 2: %lld\n", decimalToBinary(b), decimalToBinary(b << 2));

    return 0;
}

long long decimalToBinary(int dec)
{
    long long bin = 0;
    int place = 1;

    while (dec != 0)
    {
        bin += (dec % 2) * place;
        dec /= 2;
        place *= 10;
    }

    return bin;
}

/* Results:
Forgot about returning long longs to accomodate long binary numbers
He used lots of local vars where I called function in printf
Same otherwise
*/


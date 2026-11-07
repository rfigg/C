/*
Do some bitwise operations and display results in binary
*/

#include <stdio.h>

int decimalToBinary(int dec);

int main()
{
    int a = 0, b = 0;

    printf("Enter a number: ");
    scanf("%d", &a);
    printf("Enter another number: ");
    scanf("%d", &b);

    //printf("%d, %d\n", decimalToBinary(a), decimalToBinary(b));

    printf("Result of ~ on %d(%d) is: %d\n", a, decimalToBinary(a), decimalToBinary(~a));
    printf("Result of ~ on %d(%d) is: %d\n", b, decimalToBinary(b), decimalToBinary(~b));

    printf("%d & %d: %d\n", decimalToBinary(a), decimalToBinary(b), decimalToBinary(a & b));
    printf("|: %d\n", decimalToBinary(a | b));
    printf("^: %d\n", decimalToBinary(a ^ b));

    printf("%d >> 2: %d\n", decimalToBinary(a), decimalToBinary(a >> 2));
    printf("%d << 2: %d\n", decimalToBinary(b), decimalToBinary(b << 2));

    return 0;
}

int decimalToBinary(int dec)
{
    int bin = 0;
    int place = 1;

    while (dec != 0)
    {
        bin += (dec % 2) * place;
        dec /= 2;
        place *= 10;
    }

    return bin;
}


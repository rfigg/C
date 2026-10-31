// Second binary / bit challenge
// Convert decimal int to long long binary representation

#include <stdio.h>
#include <limits.h>

long long dtob(int d) {
    long long b = 0;
    unsigned long long place = 1;

    while (d != 0) {
        b += (d % 2) * place;
        d /= 2;
        place *= 10;
//        printf(" %llu", place);
    }

    return b;
}

int main(void) {
    int d;

    printf("Long long max: %lld\n", LLONG_MAX);

    while (1) {
        printf("Decimal to convert to binary? ");
        scanf("%d", &d);

        printf("Binary representation: %lld\n", dtob(d));
    }

    return 1;
}

/*
Seems to work but above 1023 (giving 10 1s) goes weird.
Results:
Again changing from unsigned to signed long long.
Still goes weird at 1024.
Maybe it's the place variable overflowing?
It is!
Fixed to convert higher numbers by using huge type for place var.
*/

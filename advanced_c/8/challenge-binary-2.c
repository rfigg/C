// Second binary / bit challenge
// Convert decimal int to long long binary representation

#include <stdio.h>
#include <limits.h>

unsigned long long dtob(int d) {
    unsigned long long b = 0;
    int place = 1;

    while (d > 0) {
        b += (d % 2) * place;
        d /= 2;
        place *= 10;
    }

    return b;
}

int main(void) {
    int d;

    printf("Unsigned long long max: %llu\n", ULLONG_MAX);

    while (1) {
        printf("Decimal to convert to binary? ");
        scanf("%d", &d);

        printf("Binary representation: %llu\n", dtob(d));
    }

    return 1;
}

/*
Seems to work but above 1023 (giving 10 1s) goes weird.
Results:
*/

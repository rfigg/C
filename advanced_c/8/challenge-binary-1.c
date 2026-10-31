// function that converts long long representation of binary
// and returns int decimal value.
// Assuming unsigned/positive only, not specified but fits examples

#include <stdio.h>

int btod(unsigned long long b) {
    int t = 0;
    int place = 1;

    while (b > 0) {
        t += (b % 2) * place;
        b /= 10;
        place *= 2;
    }

    return t;
}

int main(void) {
    unsigned long long b;

    while (1) {
        printf("Number to convert? \n");
        scanf("%llu", &b);
        
        printf("Converting %llu to decimal...\n", b);

        printf("Converted to: %d\n", btod(b));
    }

    return 1;
}

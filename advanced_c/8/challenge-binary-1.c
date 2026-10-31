// function that converts long long representation of binary
// and returns int decimal value.
// Assuming unsigned/positive only, not specified but fits examples

#include <stdio.h>
#include <math.h>

int btod(long long b) {
    int t = 0;
    int i = 0;
    int remainder = 0;

    while (b != 0) {
        t += (b % 10) * pow(2, i);
        b /= 10;
        i += 1;
    }

    return t;
}

int main(void) {
    long long b;

    while (1) {
        printf("Number to convert? \n");
        scanf("%lld", &b);
        
        printf("Converting %lld to decimal...\n", b);

        printf("Converted to: %d\n", btod(b));
    }

    return 1;
}

/*
Results:
He used regular long long, why did I use unsigned?
He prototypes function at top and implements below main, maybe this is
a c convention.
Algorithm almost the same, keeps track of an incrementing decimal and uses
pow(2, i) instead of keeping that result in a var. Also mods by 10 instead of 2
and keeps remiander in var. More readable.
*/


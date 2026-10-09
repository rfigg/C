#include <stdio.h>
#include <string.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

/* Why does their function fail on largest negative 2's complement number?
n = -n would overflow?
How to print correctly? Use an unsigned for absolute value?
*/

void reverse(char s[]);

void itoa(int n, char s[]) {
    int i, sign;

    sign = n;
    i = 0;
    do {
        s[i++] = abs(n % 10) + '0'; // abs on each digit avoids n = -n problem
    } while ((n /= 10) != 0); // test changed, neg numbers don't work with abs (worked with mine) 
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/*
Mine works. Theirs avoids the unsigned casting and uses a cool #define absolute function thing.
Similar steps otherwise, changes test after /= to != instead of > to avoid infinite loop with negative.
*/

int main() {
    int n = -53848;
    char s[1000];

    itoa(n, s);
    printf("%d becomes %s\n", n, s);
    return 0;
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


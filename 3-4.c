#include <string.h>

/* Why does their function fail on largest negative 2's complement number?
n = -n would overflow?
How to print correctly? Use an unsigned for absolute value?
*/

void reverse(char s[]);

void itoa(int n, char s[]) {
    int i, sign;
    unsigned u;

    if ((sign = n) < 0)
        u = (unsigned)-n;
    else
        u = (unsigned)n;
    i = 0;
    do {
        s[i++] = u % 10 + '0';
    } while ((u /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

void reverse(char s[]) {
    int c, i, j;

    for (i = 0, j = strlen(s)-1; i < j; i++, j--) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}


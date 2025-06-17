#include <stdio.h>
#include <string.h>

/* Write itoa(n,s,m) where number n is converted to alpha and put into string s, and
is padded with spaces if not min width m.
*/

void reverse(char s[]);

void itoa(int n, char s[], int minwidth) {
    int i, sign;

    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    while (i < minwidth)            // add spaces to reach minimum field width
        s[i++] = ' ';
    s[i] = '\0';
    reverse(s);
}

int main() {
    int n = 12345;
    char s[1000];

    itoa(n, s, 10);
    printf("%d becomes ****%s****\n", n, s);
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


#include <string.h>
#include <stdio.h>
#define abs(x) ((x) < 0 ? -(x) : (x))

/* Write itob(n,s,b) that converts integer n into base b character
representation in string s. e.g. itob(n,s,16) converts to hex.
Max base allowed? Start with it open.
Algo like itoa:
get sign
make n positive
do while through writing digits in reverse
write sign
terminate
reverse
*/

void itob(int n, char s[], int b) {
    int i, sign;
    void reverse(char s[]);

    sign = n;
    i = 0;
    do {
        if (abs(n % b) >= 0 && abs(n % b) <= 9)
            s[i++] = abs(n % b) + '0';
        else
            s[i++] = abs(n % b) - 10 + 'a';  // hail mary on good input.
    } while ((n /= b) != 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse(s);
}

/* Mine apparently works.
Theirs ignores the 2s complement bug from last question, goes back to n = -n.
Also they simplify if else into a conditional (ternary) operator. Leaving it.
*/

int main() {
    char s[1000];

    itob(17,s,16);
    printf("Number %d in base %d comes out: %s\n", 17, 16, s);
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

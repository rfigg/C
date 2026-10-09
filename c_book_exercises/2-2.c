#include <stdio.h>
#define MAX 1000

/* Write a loop equivalent to theirs without using && or ||
*/

int main() {
    int i, c, lim;
    char s[MAX];

    lim = MAX-1;
    for (i=0; i<lim-1; ++i) {
        if ((c=getchar()) == EOF)
            break;
        else if (c == '\n')
            break;
        else
            s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    ++i;
    s[i] = '\0';
    printf("%s", s);
    return 0;
}

/* Theirs uses while loop conditional on enum acting as boolean,
set to false using same tests I use to break.
Maybe breaks are bad form.
*/

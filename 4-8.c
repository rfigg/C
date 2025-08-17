/* Modify getch and ungetch to only handle 1 char of pushback */
#include <stdio.h>

char buf = 0;   /* 0 if no char to push back, char value if there is one */

int getch(void)
{
//    return (buf) ? buf : getchar();
    if (buf) {
        int t = buf;    // this ok?
        buf = 0;
        return t;
    } else
        return getchar();
}

void ungetch(int c)
{
    buf = c;
}

/* Not handling more than one char, assuminng good input.
Got rid of ternary to handle zeroing buf then returning value that was in it.
*/

int main()
{
    int c;

    ungetch('z');   /* Shouldn't see this */
    ungetch('x');   /* Test should print an x then echo input */
    while ((c = getch()) != EOF)
        printf("%c", c);
    return 0;
}


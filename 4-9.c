/* Modify getch and ungetch to handle EOF correctly. What should they do?
How to handle pushed back EOF?

Had to check answer. Since chars are a byte and ints are 2 or more, and since
EOF is -1, converting chars to ints could add 1s or 0s depending on machine,
converting to negative or positive ints unpredictably. FF -> 00FF or FFFF (255
or -1).
Use int instead of char if EOF is to be treated like other chars, no conversion
occurs.
Write from memory for practice.
*/

#include <stdio.h>

#define BUFSIZE 100

int buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
        printf("No room!\n.");
    else
        buf[bufp++] = c;
}


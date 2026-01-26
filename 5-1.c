/* Their getint treats a + or - not followed by a digit as zero.
 * Fix it so that this character is pushed back on to input.
 *
 * Plan: When matching c to + or - and calling getchar(), check if that char
 * is a digit, call ungetch and return 0 */

#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
int getint(int *);

int main ()
{
	int x, t;

	while ((t = getint(&x)) != EOF)
		if (t)	// valid value
			printf("Int: %d\n", x);	
		else
			printf("NAN.\n");
	return 0;
}

int getint(int *pn)
{
	int c, sign, d;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-') {
        d = c;  // save sign char
		if (!isdigit(c = getch())) {	// not a digit after + or -
            if (c != EOF)
                ungetch(c);     // push back non-digit
			ungetch(c);         // push back sign char
			return d;           // return sign char as signal to caller
		}
    }
	for (*pn = 0; isdigit(c); c = getch())
		*pn = *pn * 10 + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp =0; /* next free position in buf */
int getch(void) /* get a (possibly pushed back) character */
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */ 
{
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}
/* Seems to infinite loop on any non number besides + or -.
 * Used getchar instead of getch in my addition, no change */
/* Changed to be like theirs, pushing back sign char. Infinite loop
still happening, guessing it's in my main or copy of getch/ungetch */


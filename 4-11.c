/* Modify getop to not use ungetch. Hint: internal static variable.*/
# include <stdio.h>
# include <ctype.h>
# define NUMBER '0'

int getch(void);

int main()
{
    return 0;
}

int getop(char s[])
{
    int i, c;
    static int lastchar = 0;   // one char buffer, 0 if no last char stored
    // change to int, convention to handle EOF values, etc

    if (lastchar == 0)          // get first char from buffer or getch()
        c = getch();
    else {
        c = lastchar;
        lastchar = 0;
    }

    while ((s[0] = c) == ' ' || c == '\t')
        c = getch();
    
    s[1] = '\0';

    if (!isdigit(c) && c != '.')
        return c;
    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        lastchar = c;
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; /* buffer for ungetch */
int bufp =0; /* next free position in buf */
int getch(void) /* get a (possibly pushed back) character */
{
return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c) /* push character back on input */ {
if (bufp >= BUFSIZE)
printf("ungetch: too many characters\n");
else
buf[bufp++] = c;
}

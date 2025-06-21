/* Modify calculator to handle modulus % and negative numbers */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);
int getch(void);
void ungetch(int);

int main()
{
    /*

    ...

    */
    case '%':
        op2 = pop();
        if (op2 != 0)
            push(pop() % op2);
        else
            printf("error: divide by zero modulus!\n");
        break;
    /*

    ...

    */
}

int getop(char s[])
{
    int i, c, sign;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (c == '-') {       // set sign variable, consume - char
        sign = -1;
        c = getch();
    } else {              // any char other than -
        sign = 1;
    }
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
        ungetch(c);
    return NUMBER;
}
    

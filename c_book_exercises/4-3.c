/* Modify calculator to handle modulus % and negative numbers */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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
        if (op2 != 0.0) // need to specify float
            push(fmod(pop(), op2));  // can't just use % on floats. math.h has float remainder function fmod
        else
            printf("error: divide by zero modulus!\n");
        break;
    /*

    ...

    */
}

int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    i = 0;
    if (!isdigit(c) && c != '.' && c != '-')
        return c;
    if (c == '-')
        if (isdigit(c = getch()) || c == '.')
            s[++i] = c;
        else {
            if (c != EOF)
                ungetch(c);
            return '-';
        }
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
/* Theirs doesn't need sign variable. They set i to zero before checking not a number,
extend that check to include -. They check past - to see if it's a number, preserve - if not
by ungetting that next char. Important distinction I missed - minus op vs neg number.
*/


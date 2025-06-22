/* Add access to library functions like sin, exp, pow. See math.h */

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'  // code for number found
#define NAME 'n'    // code for name found

int getop(char []);
void push(double);
double pop(void);
void mathfnc(char []);  // handle functions
int getch(void);
void ungetch(int);

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
        case NUMBER:
            push(atof(s));
            break;
        case NAME:
            mathfnc(s);
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("Divide by zero.\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("Error, unknown command.\n");
            break;
        }
    }
    return 0;
}

void mathfnc(char s[]) {
    double op2;

    if (strcmp(s, "sin") == 0)
        push(sin(pop()));
    else if (strcmp(s, "cos") == 0)
        push(cos(pop()));
    else if (strcmp(s, "exp") == 0)
        push(exp(pop()));
    else if (strcmp(s, "pow") == 0) {
        op2 = pop();
        push(pow(pop(), op2));
    } else
        printf("Error, %s is not supported.\n", s);
}

int getop(char s[]) {
    int c, i;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';    // at least have complete string with first nonblank
    i = 0;
    if (islower(c)) {       // new function to me, lower case char either command or name
        while (islower(s[++i] = c = getch()))
            ;       // advance i past last lower case char
        s[i] = '\0';// cap off string
        if (c != EOF)
            ungetch(c); // if not end of file, put char after last lower case char back
        if (strlen(s) > 1) // not a command
            return NAME;
        else
            return c;
    }
    if (!isdigit(c) && c != '.')
        return c;   // not a digit
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

#define MAXVAL 1000

int sp = 0;
double val[MAXVAL];

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Stack is full up, no room for %g.\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("Nothing on the stack to pop.\n");
        return 0.0;
    }
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;   // buffer pointer

int getch(void) {
    if (bufp > 0)
        return buf[--bufp];
    else
        return getchar();
    /* they do return (bufp > 0) ? buf[--bufp] : getchar(); Nice */
}

void ungetch(int c) {
    if (bufp < BUFSIZE)
        buf[bufp++] = c;
    else
        printf("Buffer bursting at the seams, no dice.\n");
}

/* Combo of copying and coding from memory for practice
Seems to work in a command line interactive way from shell. Cool! */

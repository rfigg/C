#include <stdio.h>

/* Program to check a c program to check for basic syntax errors
like matching parens, brackets, braces. Also quotes, escape sequences, comments

Pseudo:
for each of 3, count up on opening, down on closing, non zero is an error.
Ignore chars in quotes, comments, or escaped.
*/

int parens, brackets, braces;

void check_syntax(int c);   // read each char and count opening and closing chars
void in_comment(void);
void echo_quote(int c);
void count_char(int c);     // couting logic for parens, etc, used like putchar

int main() {
    int c;

    parens = brackets = braces = 0;
    while ((c = getchar()) != EOF)
        check_syntax(c);
    printf("Parentheses %d, brackets %d, braces %d\n", parens, brackets,  braces);
    return 0;
}

void check_syntax(int c) {
    int d;
    
    if (c == '/')       // dont count in comment
        if ((d = getchar()) == '*')
            in_comment();
        else if (d == '/')
            check_syntax(d);    // same recursion from last one, attempted
        else
            count_char(d);      // count char after slash
    else if (c == '\'' || c == '"')
        echo_quote(c);          // dont count in quotes
    else
        count_char(c);          // count all other chars
}

void in_comment(void) {
    int c, d;

    c = getchar();
    d = getchar();
    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
}

void echo_quote(int c) {
    int d;

    while ((d = getchar()) != c)
        if (d == '\\')
            getchar();
}

void count_char(int c) {
    /*putchar(c);*/
    if (c == '(') {
        /*printf("UP");*/
        ++parens;
    }
    else if (c == ')') {
        /*printf("DOWN");*/
        --parens;
    }
    else if (c == '[') {
        /*printf("UP");*/
        ++brackets;
    }
    else if (c == ']') {
        /*printf("DOWN");*/
        --brackets;
    }
    else if (c == '{') {
        /*printf("UP");*/
        ++braces;
    }
    else if (c == '}') {
        /*printf("DOWN");*/
        --braces;
    }
}

/*
First attempt
Mostly worked, caught another single quote in double slash comments.
Fixed and seems to work now.
Checking book answer: Avoids unnecessary recursion like I started with.
Some details identical.
Main thing I missed, they check for negative count in main loop and print error and reset count
to avoid passing test with )))(((. At end error is reported for positive count mismatch.
Also, example does not initialize external variables. Turns out these are defaulted to zero here.
*/


#include <stdio.h>

/* Remove all comments from a c program.
Don't forget quoted strings and character constants.
*/

void rcomment(int c);
void in_comment(void);
void echo_quote(int c);

int main() {
    int c, d; // d seems to not be used?

    while ((c=getchar()) != EOF)
        rcomment(c);
    return 0;
}

void rcomment(int c) {
    int d;

    if (c == '/')
        if ((d = getchar()) == '*')
            in_comment();
        else if (d == '/') {
            putchar(c);
            rcomment(d);    // recursive already?
        } else {
            putchar(c);
            putchar(d);     // no comment
        }
    else if ( c == '\'' || c == '"')
        echo_quote(c);      // quote, no comment
    else
        putchar(c);         // no comment
}

void in_comment(void) {
    int c, d;

    printf("(IN COMMENT)");
    c = getchar();
    d = getchar();

    while (c != '*' || d != '/') {
        c = d;
        d = getchar();
    }
    printf("(OUT COMMENT)");
}

void echo_quote(int c) {
    int d;

    printf("(IN QUOTE)");
    putchar(c);     // write opening quote char
    while ((d = getchar()) != c) {
        putchar(d);
        if (d == '\\')
            putchar(getchar()); // escape sequence, write next char to skip test
    }
    putchar(d);     // write closing quote char
    printf("(OUT QUOTE)");
}

/*
First attempt. Removes block comment mostly and some line comments. mostly.
Implement book answer for practice.
Book doesn't use double slash line comments? Hadn't noticed. Looked up: added in C99. Add for fun later?
Works for most input files, but 1-13.c prints second comment block ends in a infinite char printing loop
Answer: a single quote in a double slash comment, flipped the in/out of quote status
Next problem, star not followed by slash seems to end comment.
Answer: I reversed my (!= || !=) into (!= && !=) again.
*/

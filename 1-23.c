#include <stdio.h>
#define IN 1
#define OUT 0

/* Remove all comments from a c program.
Don't forget quoted strings and character constants.

Pseudo:
Read in a char at a time.
If //, ignore rest of chars until next line.
If slash star, ignore chars until star slash.
Try with tracking 2 chars, putting last after checking current char.
*/

int main() {
    int c, lastc;   // char and last char
    int comstatus, stringstatus;    // in or out of a comment, string

    comstatus = stringstatus = OUT;  // start out of comment and string
    lastc = '\0';    // set last char to no-match null char
    while ( (c=getchar()) != EOF ) {
        if (c == '/' && lastc == '/' && stringstatus == OUT && comstatus == OUT) {  // one line comment
            while ( (c=getchar() != '\n') && c != EOF );    // won't work, will consume EOF char before while test.
            if (c == '\n')
                putchar(c);
            lastc = '\0';
        } else if (c == '*' && lastc == '/' && stringstatus == OUT && comstatus == OUT) { // block comment
            comstatus = IN;
            while ( (c=getchar()) != EOF && comstatus == IN ) {
                if (c=='/' && lastc == '*')
                    comstatus = OUT;
                lastc = c;
            }
        } else if (c == '"' && comstatus == OUT ) { // if we get a quote out of a comment...
            if (stringstatus == OUT)    // ... and out of a string
                stringstatus = IN;      // go into string
            else                        // ... and in a string
                if (lastc != '\\')    // not escape character
                    stringstatus = OUT; // exit string status
        }
        if (comstatus == OUT)
            putchar(lastc);
        lastc = c;
        if (c == EOF)
            break;
        }
}
/*
First attempt. Removes block comment mostly and some line comments. mostly.
*/

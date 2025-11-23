/* Use mygetline to read an entire input line, making getch and ungetch
unnecessary. Revise calculator to use this approach.

Copying for this one, been a while.
*/

#include <stdio.h>
#include <ctype.h>

#define MAXLINE 100     // maximum length of input line
#define NUMBER '0'      // 0 char is code for number found

int mygetline(char line[], int limit);    // ahead definition of mygetline function

int li = 0;     // line index
char line[MAXLINE]; // char array to hold the input line

int main()
{
    return 0;
}

int getop(char s[]) // get next operator or operand
{
    int c, i;

    if (line[li] == '\0')   // if char is terminating null char (end of line or no line yet)
        if (mygetline(line, MAXLINE) == 0)
            return EOF;     // nothing after null char, end of file
        else
            li = 0;         // else reset line index
    while ((s[0] = c = line[li++]) == ' ' || c == '\t') // advance line index and assign to c and s[0], as long as it's a space or tab
        ;
    s[1] = '\0';            // put terminating char after whatever first usable char we just found
    if (!isdigit(c) && c != '.')
        return c;           // not a digit or a dot, not a number
    i = 0;                  // set to iterate through s
    if (isdigit(c))         // there's a digit before any decimal
        while (isdigit(s[++i] = c = line[li++]))
            ;               // iterate through line as long as it's digits, storing in c and next s
    if (c == '.')           // fraction
        while (isdigit(s[++i] = c = line[li++]))
            ;
    s[i] = '\0';
    li--;                   // back up one character in global input line, read one too many
    return NUMBER;
}

int mygetline(char line[], int limit)
{
    int c, i;

    i = 0;
    while (--limit > 0 && (c = getchar()) != EOF && c != '\n')
        line[i++] = c;
    if (c == '\n')
        line[i++] = c;
    line[i] = '\0';
    return i;
}



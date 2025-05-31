#include <stdio.h>

#define COLS 10
#define TABS 4

/*
Fold long input lines into 2 or more lines after the last non-blank character
that occurs before the n-th column of input.
*/

char line[COLS];

int expandtab(int pos);
int findblank(int pos);
int newpos(int pos);
void printl(int pos);

int main() {
    int c, pos; //  char variable, current position in line (0 index)

    pos = 0;
    while ((c=getchar()) != EOF) { // get chars
        line[pos] = c;
        if (c == '\t')
            pos = expandtab(pos);
        else if (c == '\n') {
            printl(pos);
            pos = 0;
        } else if (++pos >= COLS) {
            pos = findblank(pos);
            printl(pos);
            pos = newpos(pos);
        }
    }
}

void printl(int pos) {  // print line up to pos column, not including
    int i;

    for (i = 0; i < pos; i++)
        putchar(line[i]);
    if (pos > 0)    // if anything printed
        putchar('\n');
}

int expandtab(int pos) {
    line[pos] = ' ';   // tab at least 1 blank
    for (++pos; pos < COLS && pos % TABS != 0; ++pos)
        line[pos] = ' ';    // add spaces until at col limit or tab stop
    if (pos < COLS) // still room in line
        return pos;
    else {      // line is full
        printl(pos);
        return 0;
    }
}

int findblank(int pos) {    // return position of last blank + 1 or COLS if no spaces
    while (pos > 0 && line[pos] != ' ')
        --pos;
    if (pos == 0)   // no spaces
        return COLS;
    else
        return pos + 1 ;    // position after last space
}

int newpos(int pos) {   // rearrange line with new position
    int i, j;

    if (pos <= 0 || pos >= COLS )
        return 0;
    else {
        i = 0;
        for (j = pos; j < COLS; ++j) {
            line[i] = line[j];
            ++i;
        }
        return i;
    }
}
/* book solutions
Flipping last time, now they're using external variables and functions in a cool way where
I tried a simple char stream. Rewriting along theirs for practice.
Line at a time.
*/

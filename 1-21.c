#include <stdio.h>
#define MAXLINE 1000
#define TAB 4
//#define INSPACE 1
//#define OUTSPACE 0
/*
Replace strings of blanks with minimum number of tabs and blanks for same spacing.
*/

void entab(char s[], int t);    // replaces consecutive spaces with tabs where possible
int mygetline(char line[], int max);    // get a line with max length 

int main()
{
    char line[MAXLINE];

    while ( (mygetline(line, MAXLINE)) > 0 ) {
        entab(line, TAB);
        printf("%s", line);
    }
    return 0;
}

void entab(char line[], int tab)  // try modulo math method for practice
{
    int i, j;    //source position, dest position (same string)
    int nspaces;
    int nexttab;

    nexttab = tab;
    i = j = 0;
    nspaces = 0;
    while ( line[i] != '\0') {  // while not at end of string
        if ( line[i] == ' ') {  // if a space, count a space and move source pointer forward
            ++nspaces;
            ++i;
        } else if ( nspaces == 0 ) {    //if a char, and no spaces yet, add char at j, incr i and j
            line[j] = line[i];
            ++i;
            ++j;
        } else if ( nspaces > 0 ) {  //if a char and nspaces > 0 (start of a word), loop adding tabs and spaces at j
            while ( (nspaces / tab) > 0 ) { //  nspaces / tab = # of tabs
                line[j] = '\t';
                nspaces -= tab;
                ++j;
            }
            while ( (nspaces % tab) > 0) {  //  npsaces % tab = spaces at end
                line[j] = ' ';
                --nspaces;
                ++j;
            }
        } else {
            //you shouldn't be here
        }
    }
    while ( nspaces / tab > 0 ) {   // handle trailing spaces
        line[j] = '\t';
        nspaces -= tab;
        ++j;
    }
    while ( nspaces % tab > 0 ) {
        line[j] = ' ';
        --nspaces;
        ++j;
    }
    line[j] = '\0';
    
    return; // void? new length?
}

int mygetline(char line[], int max)
{
    int c, i;

    for (i=0; i<max-1 && (c=getchar())!=EOF && c!='\n'; ++i)
        line[i] = c;
    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}

/*

*/

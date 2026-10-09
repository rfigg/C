#include <stdio.h>
#define TAB 5
/*
Replace strings of blanks with minimum number of tabs and blanks for same spacing.
*/

int main()
{
    int c, nblanks, ntabs, pos;

    nblanks = ntabs = 0;
    for (pos = 1; (c = getchar()) != EOF; ++pos)
        if (c == ' ') {
            if (pos % TAB != 0)
                ++nblanks;
            else {
                nblanks = 0;
                ++ntabs;
            }
        } else {
            while (ntabs > 0) {  // write out tabs. book used concise for loop without 1st clause
                putchar('\t');
                --ntabs;
            }
            if (c == '\t')  // if last char was a tab, ignore spaces and add tab later
                nblanks = 0;
            while (nblanks > 0) {  // write remaining spaces. book uses else and another concise for loop
                putchar(' ');
                --nblanks;
            }
            putchar(c);
            if (c == '\n')
                pos = 0;  // confused me why zero based? loop with add 1
            if (c == '\t')  // book has this after else, saves one comparison i guess
                pos += (TAB - (pos-1) % TAB) - 1;  // did same to me here. t-(p-1)%t is the correct number of spaces, then subtract one more anticipating loop increment
        }
}

/*
Book answer much simpler, not sure why I overcomplicated this after last one.
No need for string variables or functions, just get and put chars.
Seems to fail on input of all spaces, no newline. main else never reached, no output.
*/

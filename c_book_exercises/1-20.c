#include <stdio.h>
#define TAB 9

/* Write a program "detab" to replace tabs with proper number of spaces
to reach next tab stop. Fixed set of stops every n columns.
Should n be a variable or symbolic parameter?

Pseudo:
read each char, count up columns, count down to next stop. reset count on newline.
on tab, loop adding spaces until you reach next stop.
*/

int main()
{
  int c, col, nexttab;

  col=0;
  nexttab = TAB;
  while ((c = getchar()) != EOF) {
    // if \n, put char, reset col and nexttab
    // if \t, loop adding spaces
    // else put char, count up and down
    if (c == '\t') {
      // loop adding spaces
      while (nexttab > 0) {
        putchar(' ');
        ++col;
        --nexttab;
      }
      nexttab = TAB;
    } else {
      // put char
      // if \n, reset col and nexttab
      // else count up and down, reset nexttab
      putchar(c);
      if (c == '\n') {
        col = 0;
        nexttab = TAB;
      } else {
        ++col;
        --nexttab;
        if (nexttab == 0)  // at tab stop, reset tab
          nexttab = TAB;
      }
    }
  }
}

/* my version pre answer checking. Thought I would need to count columns
for modulo type math but didn't seem to need to.*/

/*
Book answer uses a pos variable to track column like I thought I would,
1 based instead of 0. Uses modulo math to get number of blanks.
Mine seems to get same answer? Not rigorously tested.
*/

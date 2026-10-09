#include <stdio.h>

int main()
{
    int c, lastBlank;

    lastBlank = 0;

    while ((c = getchar()) != EOF) {
      if (c != ' ') {
        putchar(c);
        lastBlank = 0;
      }
      else if (!lastBlank) {
        putchar(' ');
        lastBlank = 1;
      }
    }

    /* Book solution used simpler char and lastchar variables,
    no need for extra fake boolean thing I did */
}

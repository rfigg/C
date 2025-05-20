#include <stdio.h>
#define IN 1
#define OUT 0

/* print input formatted one word per line */
int main() {
  int c, state;

  state = OUT;
  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        putchar('\n');
        state = OUT;
      }
    }
    else {
      if (state == OUT) {
        state = IN;
        putchar(c);
      } else
        putchar(c);
    }
  }
  // putchar('\n');
}

/*
Book answer: mostly the same, slightly different logic.
Under first if, checks for state = in to put newline at finish of word and change state to out (instead of setting to out regardless)
I print newline then first char at start or word, requiring extra \n at the end.
Actually, realized mine adds extra line before first word as well. Bug!
*/

/* fixing logic for 2nd commit */

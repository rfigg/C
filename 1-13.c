#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXSIZE 20  // # of word sizes to track. over this goes in 'more' bucket

/* draw histogram of the lengths of words of input
pseudo:
use same in/out of word logic
count length of each word
at end of word, add 1 to corresponding array element
for each element, loop and output character to make bar
*/

int main() {
  int x, c, nc, state, totals[MAXSIZE], more;

  state = OUT;
  nc = more = 0;
  for (x = 0; x < MAXSIZE; ++x)
    totals[x] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {
        if (nc <= MAXSIZE)   // could also check for >=0 for safety)
          ++totals[nc-1];
        else
          ++more;
        state = OUT;
        // printf("%d ", nc);
        nc = 0;
      }
    } else {
      if (state == OUT)
        state = IN;
      ++nc;
    }
  }

  // for (x = 0; x < MAXSIZE; ++x) {
  //   printf("%d: %d\n", x+1, totals[x]);
  // }
  // printf("over: %d\n", more);

  for (x = 0; x < MAXSIZE; ++x) {
    printf("%2d | ", x+1);
    for (c = 0; c < totals[x]; ++c)
      putchar('#');
    putchar('\n');
  }
  printf(" + | ");
  for (c = 0; c < more; ++c)
    putchar('#');
  putchar('\n');
}

/*
Book example adds limit to word size and tracks maximum value to get a good ratio for histogram instead of 1 char per count.
Better use of nc, 0 out of word, 1 with first letter, no -1.
But is first array slot used? A: seems to start with i=1 after, ignoring [0] slot.
Scales with length = array value * max bar length / largest value in array. Has logic to print 1 char for value greater than 0,
but sign seems backwards in answer.

Vertical works same until output. Sign seems correct in this example. Steps downward from max histogram bar length.
*/

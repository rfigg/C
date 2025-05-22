#include <stdio.h>

#define IN 1
#define OUT 0
#define MAXSIZE 20  // # of word sizes to track. over this goes in 'more' bucket
#define MAXHIST 30 // max length of histogram bar

/* draw histogram of the lengths of words of input */

int main() {
  int x, c, nc, state, totals[MAXSIZE], more, len, maxvalue;

  state = OUT;
  nc = more = 0;
  for (x = 0; x < MAXSIZE; ++x)
    totals[x] = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ' || c == '\t' || c == '\n') {
      if (state == IN) {  // book answer uses if (nc > 0). different? seems maybe IN state corresponds to nc > 0, and OUT nc == 0.
        if (nc < MAXSIZE)
          ++totals[nc];
        else
          ++more;
        state = OUT;
        nc = 0;
      }
    } else {
      if (state == OUT)
        state = IN;
      ++nc;
    }
  }

  //maxvalue from answer book
  maxvalue = 0; 
  for (x = 1; x < MAXSIZE; ++x)
    if (totals[x] > maxvalue)
      maxvalue = totals[x];
    
  for (x = 1; x < MAXSIZE; ++x) {
    printf("%5d - %5d : ", x, totals[x]);
    if (totals[x] > 0) {
      if ((len = totals[x] * MAXHIST / maxvalue) <= 0) // is this sign backwards? no, I don't understand this ratio
        len = 1;
    } else
      len = 0;
    while (len > 0) {
      putchar('*');
      --len;
    }
    putchar('\n');
  }
  if (more > 0)
    printf("There are %d words with %d characters or more.\n", more, MAXSIZE);
}

/*
Book example adds limit to word size and tracks maximum value to get a good ratio for histogram instead of 1 char per count.
Better use of nc, 0 out of word, 1 with first letter, no -1.
But is first array slot used? A: seems to start with i=1 after, ignoring [0] slot.
Scales with length = array value * max bar length / largest value in array. Has logic to print 1 char for value greater than 0,
but sign seems backwards in answer.

Vertical works same until output. Sign seems correct in this example. Steps downward from max histogram bar length.
*/

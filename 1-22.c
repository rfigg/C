#include <stdio.h>

#define COLS 10

/*
Fold long input lines into 2 or more lines after the last non-blank character
that occurs before the n-th column of input.

Pseudo:
Seem to need string to store word until end of word is reached. Can't back up
putchars.
Read a char. if non-blank, add to word, advance poisition.
If non-blank and word longer than limit, some indicator and next line, reset position.
If blank and below limit,
    if word: add word and add blank. reset word
    no word: add blank
Else blank and above limit,
    if there's a word: new line, reset position, add word, add blank
    no word: already added spaces, add newline, reset position
*/

int main() {
    int c, i, pos, wordsize; // pos is where we are in output against column limit. wordsize is chars in current word
    int word[COLS+1]; // record word until output, not sure about +1

    wordsize = 0;
    pos = 1;
    while ((c=getchar()) != EOF) { // get chars and advance position. may neeed while.
        if (c != ' ') { // 
            word[wordsize] = c;
            ++wordsize;
            if (wordsize >= COLS) {  // check for word as long as column limit. check for off by 1.
               for (i = 0; i < wordsize; i++) // write word
                   putchar(word[i]);
               putchar('\n');   // next line
               pos = 0;
               wordsize = 0;
            }
        } else if (pos <= (COLS-wordsize)) {   // if blank char and word fits. check for off by 1.
            if (wordsize > 0) {     // if there's a word, add it and reset word.
                for (i = 0; i < wordsize; i++) {
                    putchar(word[i]);
                    ++pos;
                }
                wordsize = 0;
            }
            putchar(' ');       // add blank
            ++pos;
        } else {        // blank and word won't fit
            if (wordsize > 0) {     // new line, reset pos, add word, add blank
                putchar('\n');
                pos = 0;
                for (i = 0; i < wordsize; ++i) {
                    putchar(word[i]);
                    ++pos;
                }
                wordsize = 0;
                putchar(' ');
                ++pos;
            } else {    // otherwise all spaces, next line, reset
                putchar(' ');
                putchar('\n');
                pos = 0;
            }
        }
    }
}

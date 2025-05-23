#include <stdio.h>

#define IN 1
#define OUT 0
#define START 32   // start array with char value 32
#define END 127   // end array with char value 127

/* Print a histogram of frequencies of different characters in input */
int main() {
    int c, i;
    int nc[END - START + 1];   // number of characters for each value in range
//    printf("nc sized at %d\n", END - START +1 );
    for (i = 0; i <= (END - START); ++i) {
        nc[i] = 0;
//        printf("%d 0'd, ", i);
    }
    while ((c = getchar()) != EOF) {
        if ((c >= START) && (c <= END))
            ++nc[c - START];
    }

    // test output
    for (i = 0; i <= (END - START); ++i)
        printf("%d: %d\n", i + START, nc[i]);
}

/* Leaving test output for now, can histogram later if I want */

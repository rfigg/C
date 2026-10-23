// This just displays the global var from the other file
#include <stdio.h>

extern int lp_counter;

void display() {
    printf("%d... ", lp_counter);
    if (lp_counter == 5)
        printf("\n");
}

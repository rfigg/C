#include <stdio.h>

/* pipe small text file to this, see all ones until a final zero. */

int main() {
    int c;

    while (c = getchar() != EOF ) {
        printf("%d",c);
    }

    printf("\nLast character not equaled with EOF gave: %d\n", c );
}

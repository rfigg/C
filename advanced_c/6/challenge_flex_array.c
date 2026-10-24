// Flexible array members
// Read in array size. Allocate memory for struct, fill with data, print

#include <stdio.h>
#include <stdlib.h>

struct myflex {
    int size;
    int data[];
};

int main () {
    struct myflex *x;
    int s;

    printf("Enter size of array: ");
    scanf("%d", &s);

    printf("%d\n", s);

    x = malloc( sizeof(struct myflex) + s*sizeof(int) );
    
    for (int i = 0; i < s; i++) {
        //x->data[i] = 42;
        x->data[i] = 101+i;
    }

    for (int i = 0; i < s; i++) {
        printf("%d\n", x->data[i]);
    }

    free(x);
    return 0;
}


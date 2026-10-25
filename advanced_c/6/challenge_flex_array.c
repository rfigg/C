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

    x = malloc( sizeof(struct myflex) + s*sizeof(int) );
    
    x->size = s;
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

/*
Results:
He starts by setting struct pointer to NULL and initializing s to 0
He uses malloc.h instead of stlib.h, which this clang didn't like
He malloc'd in 2 steps with an extra size_t var
I didn't set the size field of the struct
My population of the array with numbers is more fun.
*/

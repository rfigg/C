#include <stdio.h>

//extern int i;     Can do here or in function since it's not used elsewhere
//extern char text[]; // Don't need size (probably CAN'T), defined in other file.
extern char text[][50];     // Apparently you have to define second size of 2d arrays? Why a different size of 2nd dimension in example?

extern int count;

void write_extern(void) {
    printf("The count is %d\n", count);
}

void foo(void)
{
    extern int i;

    i = 100;
}


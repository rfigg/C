#include <stdio.h>

int i = 5;

//char text[255];
char text[255][25];

void foo(void);

int count = 12;

extern void write_extern(void);

int fun() {
    static int count = 0;

    count++;
    return count;
}


int main (void)
{
    printf ("%i ", i);
    foo ();
    printf ("%i\n", i);

    write_extern();

    printf("%d ", fun());
    printf("%d\n", fun());

    return 0;
}


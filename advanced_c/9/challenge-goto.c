/*
Output a triangle of asterisks, 9 wide at the bottom
Simulate nested looping structure
Don't use any looping, only goto
At the end, see why goto is bad :)
*/

#include <stdio.h>

#define WIDTH 9

int main()
{
    int star1, star2;
    int i;

    // outer loop for each line, inner loop for each char
    // index of which chars are stars in 2 vars, increment and decrement each line
    // last line all stars
    star1 = star2 = WIDTH / 2 + 1;      // middle spot

    outer_loop:
    if (star1 == 1)     // last line
        goto last;
    
    i = 1;
    inner_loop:
    if (i == star1 || i == star2)
        printf("*");
    else
        printf(" ");
    
    i++;
    if (i <= WIDTH)
        goto inner_loop;

    printf("\n");
    star1--;
    star2++;

    goto outer_loop;

    last:
    i = 1;
    last_loop:
    printf("*");
    i++;

    if (i <= WIDTH)
        goto last_loop;
    printf("\n");

    return 0;
}


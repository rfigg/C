/* Use their printd idea to write a recursive version of itoa,
integer to alpha, convert integer to a string.

Plan:
Take a string and an integer.
Use static index to walk through result string.
If > 10, call self with i/10.
Write integer mod 10.
If it's the last digit, add null terminator.
*/

#include <stdio.h>
#include <stdlib.h>

void myitoa(char s[], int i)
{
    printf("Entering function with i = %d\n", i);
    
    static int x;

    if (i / 10)
        myitoa(s,(i / 10));
    else
    {
        x = 0;
        if (i < 0)
            s[x++] = '-';
    }

    s[x++] = (abs(i % 10) + '0');

    //if (!(i / 10))  // Guess it's evaluating false for negatives
    s[x] = '\0';

    return;
}

int main()
{
    char result[50];
    myitoa(result, 12345);
    printf("Result: %s\n", result);
    
    myitoa(result, -10);
    printf("Result: %s\n", result);

    myitoa(result, -1);
    printf("Result: %s\n", result);
    
    myitoa(result, -531);
    printf("Result: %s\n", result);

    myitoa(result, 1);
    printf("Result: %s\n", result);
    
    myitoa(result, 143256);
    printf("Result: %s\n", result);
    return 0;
}

/* -1 is printing as -10. Confirmed for other single digits. One change now it's not writing null char on multi digit negatives.
It was bad logic of "if (!(i/10))"
Ended up almost the same as theirs, no need to change. They use abs(x) mod 10 rather than mod then absolute. Should be the same?
*/

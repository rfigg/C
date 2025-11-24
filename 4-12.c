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

    if (i / 10)
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

    return 0;
}

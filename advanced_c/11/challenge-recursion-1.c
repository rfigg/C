/* Challenge - section 11 - Recursion 1
Recursively sum numbers 1 to n.
*/

#include <stdio.h>

int sum(int n)
{
    if (n == 1)
        return 1;

    return n + sum(n - 1);
}

int main()
{
    printf("%d\n", sum(6));
    printf("%d\n", sum(3));
    printf("%d\n", sum(11));

    return 0;
}


/* Challenge - Section 11 - Variadic functions
Create function that sums any amount of integers
First argument is # of ints, all others are ints to sum
*/

#include <stdio.h>
#include <stdarg.h>

int varSum(int count, ...);

int main()
{
    int sum = 0;

    sum = varSum(5, 2, 3, 4, 5, 6);
    printf("Sum: %d\n", sum);
    sum = varSum(2, 10, 20);
    printf("Sum: %d\n", sum);
    sum = varSum(3, 10, 20, 30);
    printf("Sum: %d\n", sum);
    sum = varSum(4, 10, 20, 30, 40);
    printf("Sum: %d\n", sum);

    return 0;
}

int varSum(int count, ...)
{
    int s = 0;
    va_list args;

    va_start(args, count);

    for (int i = 0; i < count; i++)
        s += va_arg(args, int);

    va_end(args);

    return s;
}

/* Results:
Basically identical besides names and output formatting.
*/

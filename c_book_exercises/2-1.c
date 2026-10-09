#include <stdio.h>
#include <limits.h>
#include <float.h>

/*
Determine ranges of char, short, int, and long, both signed and unsigned,
by printing values from headers and by computation. Bonus: compute ranges
of various floating point types.
Hint: limits.h and float.h
*/

int main() {
    printf("Signed char min, max: %5d,%5d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Unsigned char min, max: %5u,%5u\n", 0, UCHAR_MAX);
    printf("Signed short min, max: %5d,%5d\n", SHRT_MIN, SHRT_MAX);
    printf("Unsigned short min, max: %5u,%5u\n", 0, USHRT_MAX);
    printf("Signed int min, max: %5d,%5d\n", INT_MIN, INT_MAX);
    printf("Unsigned int min, max: %5u,%5u\n", 0, UINT_MAX);
    printf("Signed long min, max: %5ld, %5ld\n", LONG_MIN, LONG_MAX);
    printf("Unsigned long min, max: %5lu, %5lu\n", 0, ULONG_MAX);
    
    /* a few examples of finding limits with bit shifts */
    printf("No cheating signed char min: %d\n", ~(char)((unsigned char) ~0 >> 1));
    printf("No cheating signed int max: %d\n", (int)((unsigned int) ~0 >> 1));
    printf("No cheating signed long int min: %ld\n", ~(long int)((unsigned long int) ~0 >> 1));
    printf("No cheating unsigned short max: %u\n", (unsigned short) ~0);
    printf("No cheating unsigned long max: %lu\n", (unsigned long) ~0);
    
    return 0;
}

/*
First attempt had overflows, trying to put in bigger vars seems wrong.
Just use correct printf format specifiers.
Bit shifts don't seem to work.
Answer book pdf looked like negative signs. Learned about bitwise NOT operator.
To get max or min: ~0 gets all 1s. Cast to unsigned type (max unsigned).
Shift right 1 to clear the sign bit. Cast that to signed type for max.
(bitwise negate that for min) (unsigned maxs can skip all the extra)
*/

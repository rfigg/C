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
    long int li;

    printf("Signed char min, max: %5d,%5d\n", SCHAR_MIN, SCHAR_MAX);
    printf("Range: %d\n", SCHAR_MAX - SCHAR_MIN);
    printf("Unsigned char min, max: %5d,%5d\n", 0, UCHAR_MAX);
    printf("Range: %d\n", UCHAR_MAX - 0);
    printf("Signed short min, max: %5d,%5d\n", SHRT_MIN, SHRT_MAX);
    printf("Range: %d\n", SHRT_MAX - SHRT_MIN);
    printf("Unsigned short min, max: %5d,%5d\n", 0, USHRT_MAX);
    printf("Range: %d\n", USHRT_MAX - 0);
    printf("Signed int min, max: %5d,%5d\n", INT_MIN, INT_MAX);
    li = INT_MAX - INT_MIN;
    printf("Range: %ld\n", li);
    printf("Unsigned int min, max: %5d,%5d\n", 0, UINT_MAX);
    printf("Range: %d\n", UINT_MAX - 0);
    
    return 0;
}

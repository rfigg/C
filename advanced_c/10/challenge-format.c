/* Challenge - Section 10 - formatting functions
Read from file a set of numbers
Write even, odd, or prime numbers to stdout
Use fscanf or fgets+sscanf
Make helper functions iseven and isprime (check for positive, etc)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#include <stdlib.h>

bool iseven(const int);
bool isprime(const int);

int main() {
    FILE *fp = NULL;
    int num = 0;

    // open file, hardcode for this challenge for ease of use
    if ((fp = fopen("numbers.txt", "r")) == NULL) {
        puts("Couldn't open file");
        exit(1);
    }

    // read each number, check for even, then prime, else odd
    while (fscanf(fp, "%d", &num) != EOF) {
        if (iseven(num))
            printf("Even number: %d\n", num);
        else if (isprime(num))
            printf("Prime number: %d\n", num);
        else
            printf("Odd number: %d\n", num);
    }

    fclose(fp);
    return 0;
}

bool iseven(const int n) {
    if (n % 2 == 0)
        return true;
    else
        return false;
}

bool isprime(const int n) {
    int y = (int)sqrt(n); // largest factor to check

    if (n < 0) return false; // if negative, not prime
    
    // check if divisible by all x up to square root of n
    for (int x = 2; x <= y; x++)
        if (n % x == 0)
            return false;

    // if it passed all the above, it's prime
    return true;
}

/* Results:
Functions use const ints as parameters, good to practice this
Adding stdlib for exit, good to practice this as well, I think
Also fixed return code 0 on failure, should be 1
He stores result in var, checks for -1 instead of EOF, uses do/while
In this case mine works, might have gotten lucky.
- checked fscanf reference, actually mine is better: error returns EOF
His iseven uses cool bitwise one-liner: return !(num & 1);
He checks prime factors up to n/2 instead of sqrt(n) for some reason
Also I corrected my weird thought that 2 wasn't prime cuz it's even :/
*/

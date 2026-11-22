/* Challenge - Section 10 - formatting functions
Read from file a set of numbers
Write even, odd, or prime numbers to stdout
Use fscanf or fgets+sscanf
Make helper functions iseven and isprime (check for positive, etc)
*/

#include <stdio.h>
#include <stdbool.h>
#include <math.h>

bool iseven(int n);
bool isprime(int n);

int main() {
    FILE *fp = NULL;
    int num = 0;

    // open file, hardcode for this challenge for ease of use
    if ((fp = fopen("numbers.txt", "r")) == NULL) {
        puts("Couldn't open file");
        return 0;
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

bool iseven(int n) {
    if (n % 2 == 0)
        return true;
    else
        return false;
}

bool isprime(int n) {
    int y = (int)sqrt(n); // largest factor to check

    if (n <= 2) return false; // if 2 or less, not prime
    
    // check if divisible by all x up to square root of n
    for (int x = 3; x <= y; x++)
        if (n % x == 0)
            return false;

    // if it passed all the above, it's prime
    return true;
}


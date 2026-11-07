/*
Bitmasks - setting and reading bits
Take in a number, and a bit to check and set (0-31)
Display number before and after setting bit
*/

#include <stdio.h>

int main()
{
    int num = 0, bit = -1;

    printf("Enter a number: ");
    scanf("%d", &num);

    while ( (bit < 0) || (bit > 31) ) {
        printf("Bit to set and check (0-31): ");
        scanf("%d", &bit);
    }

   // check and print bit
   printf("The %d bit is set to %d\n", bit, (num >> bit) & 1);

   // set bit
   int newNum = (1 << bit) | num;
   printf("Bit set, supposedly.\n");

   // print old and new num
   printf("Number before setting the %d bit: %d\n", bit, num);
   printf("Number after setting the %d bit: %d\n", bit, newNum);
        
    return 0;
}


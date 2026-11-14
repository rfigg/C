/* Challenge: using setjmp and longjmp
TBH, can't tell what the instructions want here
*/

#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

void error_recovery();

int main()
{
    int i = setjmp(j);
        
    if (i == 0)
        error_recovery();

    return 0;
}

void error_recovery()
{
    printf("Error!\n");
    longjmp(j, 1);
}

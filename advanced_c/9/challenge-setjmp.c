/* Challenge: using setjmp and longjmp
TBH, can't tell what the instructions want here
*/

#include <stdio.h>
#include <setjmp.h>

jmp_buf j;

void error_recovery();

int main()
{
    while(1) {
        if (setjmp(j)) {
            printf("I'm in main!\n");
            break;
        } else {
            error_recovery();
        }
    }

    return 0;
}

void error_recovery()
{
    printf("Error!\n");
    longjmp(j, 1);
}

/* Result:
Ok, pretty much does the same as mine but from within a forever loop.
*/

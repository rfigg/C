/* Write recursive version of reverse(s), reversing string s in place.

Plan:
Find length of string, swap 1st and last
Call self on next and next to last etc until center
How to initialize and count if it's called recursively with just s?
After spinning wheels, they use this function to call another recursive function.
*/

#include <string.h>
#include <stdio.h>

void reverse(char s[])
{
   void reallyreverse(char s[], int start, int length);

   reallyreverse(s, 0, strlen(s));
}

void reallyreverse(char s[], int start, int length)
{
    int c, i;

    i = length - (start + 1);   // as start moves up, length moves back

    if (start < i) {
        c = s[start];
        s[start] = s[i];
        s[i] = c;
        reallyreverse(s, start+1, length);
    }
}

int main()
{
    char s[] = "Hello.";
    reverse(s);
    printf("%s\n", s);

    char what[] = ".taht ekil em ta kool t'noD";
    reverse(what);
    printf("%s\n", what);

    
    return 0;
}

#include <stdio.h>
#define YES 1
#define NO 0

/* Write a version of squeeze that deletes any character
from s1 that matches any char in s2 */

void squeeze(char s1[], char s2[]) {
    int i, j, k, contains;

    for (i = j = 0; s1[i] != '\0'; i++) {
        contains = NO;
        for (k = 0; s2[k] != '\0'; k++)
            if (s1[i] == s2[k])
                contains = YES;
        if (!contains)
            s1[j++] = s1[i];
        s1[j] = '\0';
    }
}

int main() {
    char s1[] = "abcdefghijklmnop"; 
    char s2[] = "aeio";
    squeeze(s1, s2);
    printf("%s\n", s1);
    return 0;
}

/* Mine works.*/

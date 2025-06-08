/* any(s1,s2) returns first location in s1 where any char
from string s2 occurs, or -1 if none do. */

int any(char s1[], char s2[]) {
    int i, k;

    for (i = 0; s1[i] != '\0'; i++) {
        for (k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ;
        if (s2[k] == s1[i])
            return i;
    }
    return -1;
}
/* My version */


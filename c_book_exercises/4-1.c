/* Write  strrindex(s,t) returning position of rightmost occurance
of t in s, or -1 if not found.
*/

int strrindex(char s[], char t[])
{
    int i, j, k;
    int lastindex = -1;  // hold value of last match found to return.

    for (i = 0; s[i] != '\0'; i++) {
        for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; ++j, ++k)
            ;
        if (k > 0 && t[k] == '\0')
            lastindex = i;
    }
    return i;
}

/* My try is basically identical to their 1st solution.
They have an efficient 2nd solution, mostly the same but the loop
for (i = strlen(s) - strlen(t); i >= 0; i--)
starts at last possible position that could fit a match, and goes
backwards through characters until reaching start of string. It
returns immediately without extra variable, or returns -1 at end.
*/


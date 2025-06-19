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

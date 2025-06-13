/* Write escape(s,t) that converts chars like newline and tab into \n and \t
while copying string t to string s. Use switch. Then write other direction.*/


void escape(char s[], char t[]) {
    int i, j; // iterators for s and t

    i = j = 0;
    while (t[j] != '\0') { // Read to end of source string t
        switch (t[j]) {
            case '\n':
                s[i++] = '\\';
                s[i++] = 'n';
                j++;
                break;
            case '\t':
                s[i++] = '\\';
                s[i++] = 't';
                j++;
                break;
            default:
                s[i++] = t[j++];
                break;
        }
    }
    s[j] = '\0';
}

/* My attempt before answer check. */


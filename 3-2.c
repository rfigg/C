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
/* Though logically equivalent, theirs uses a nice for loop to initialize
i and j as well as to increment i. Will copy in my attempt at unescape.
Assuming you can next switches and break gets out of innermost */

void unescape(char s[], char t[]) {
    int i, j;

    for (i = j = 0; j != '\0'; j++) {
        switch (t[j]) {
            case '\\':
                switch (t[j+1]) {
                    case 't':
                        s[i++] = '\t';
                        ++j;
                        break;
                    case 'n':
                        s[i++] = '\n';
                        ++j;
                        break;
                    default:
                        s[i++] = t[j];
                        break;
                }
                break;
            default:
                s[i] = t[j];
                break;
        }
    }
    s[i] = '\0';
}


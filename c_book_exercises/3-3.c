/* Write expand(s1,s2) that expands a-z in s1 to include all chars in s2.

if not a '-', copy char
    else if both chars low case, replace dash
        if both chars upper case, replace dash
        if both chars digits, replace dash

*/

void expand(char s[], char t[]) {
    int i, j;
    char c;

    i = j = 0;
    while ((c = s[i++]) != '\0')    // put s[i] in c, advance i 
        if (s[i] == '-' && s[i+1] >= c) {   // check dash and next char. Will accept a-a?
            i++;
            while (c < s[i])
                t[j++] = c++;
        } else
            t[j++] = c;
    t[j] = '\0';
}
/* Mine works, theirs uses one less char, many less comparisons, some similar logic.
They don't check for chars on either side of dash being in same range, just less than.
Clever use of one char variable, i, and i+1 to check dash.
*/

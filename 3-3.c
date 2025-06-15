/* Write expand(s1,s2) that expands a-z in s1 to include all chars in s2.

if not a '-', copy char
    else if both chars low case, replace dash
        if both chars upper case, replace dash
        if both chars digits, replace dash

*/

void expand(char s[], char t[]) {
    int i, j;
    char p, n;

    for (i = j = 0; s[i] != '\0'; i++) {
        if (s[i] != '-')   // If not a dash, copy the char
            t[j++] = s[i];
        else if (i == 0)    // case of leading char is a dash
            t[j++] = '-';
        else {
            p = s[i-1]; // store char before and after dash for ease
            n = s[i+1];
            if (p < n)  // if correct order and at least sequential
                if ((p >= 'a' && p <= 'z' && n >= 'a' && n <= 'z') || // both chars low case
                    (p >= 'A' && p <= 'Z' && n >= 'A' && n <= 'Z') ||  // both upper case
                    (p >= '0' && p <= '9' && n >= '0' && n <= '9')) // both digits
                    while (++p < n)     // increment p and add until n
                        t[j++] = p;     // add char to t and icrement dest
                else
                    t[j++] = '-';       // p < n but not in same range 
            else       // if chars on either side not in same range or low-high
                t[j++] = '-';             // p > n
        }
    }
    t[j] = '\0';
}


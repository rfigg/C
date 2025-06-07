#include <stdio.h>

/* write htoi(s), converting string of hex digits (optional 0x or 0X),
to integer value. Accepts 0-9, a-f, A-F */

int htoi(char s[]);
int hexcharval(char c);

int main() {
    int i;
    char s[] = "0x1a8E24c";

    i = htoi(s);
    printf("String %s becomes int %d.\n", s, i);

    return 0;
}

int htoi(char s[]) {
    int i, result;

    result = 0;     // initialize return value
    // check for 0x or 0X and skip over
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;
    else
        i = 0;
    while (s[i] != '\0') {  // loop through digits and compute result
        result = result * 16 + (hexcharval(s[i]));
        ++i;
    }

    return result;
}

int hexcharval(char c) {
    int res;
    
    res = 0;
    if (c >= '0' && c <= '9')
        res = c - '0';
    else if (c >= 'a' && c <= 'f')
        res = 10 + (c - 'a');
    else if (c >= 'A' && c <= 'F')
        res = 10 + (c - 'A');

    return res;
}

/*
First try. Getting negative numbers. Fixed errors in hexcharval logic.

*/

/* Rewrite function lower to use conditional expression instead of if-else.
Original:
int lower(int c) {
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}
*/

int lower(int c) {
    return c >= 'A' && c <= 'Z' ? c + 'a' - 'A' : c;
}

/* Got it aside from unnecessary parentheses */


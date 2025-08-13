/* Write a routine, ungets(s) that will push back an entire string onto the input.
Should it know about buf and bufp, or just use ungetch?
Try both ways?
*/

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    if (bufp > 0) {
        return (buf[--bufp]);
    } else {
        return getchar();
    }
    // K&R do nice oneline: return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE) {
        printf("Can't ungetch, buffer is full at %d characters.\n", BUFSIZE);
    } else {
        buf[bufp++] = c;
    }
}

/*
Will string fit in buffer?
If using ungetch, need to unget in reverse?
What does pushing back an entire string mean?
Add chars of string to stack so they will be pulled next in correct order.
1st char should be top of stack. Add backwards.
*/
/* My version using ungetch and rejecting s larger than buffer size */
void ungets(char s[]) {
    int i;

    /*for (i = 0; s[i] != '\0'; i++) {
        ungetch(s[i]);
    }
    vibing, added string backwards*/

    for (i = 0; s[i] != '\0'; i++)
        ;
    if (i > (BUFSIZE - bufp)) { // if s won't fit in buffer. BUFSIZE - bufp should be available number of chars
       printf("Can't fit string in buffer.\n");
       return;
    }
    while (i > 0) {
        ungetch(s[i--]);
    }
    return;
}


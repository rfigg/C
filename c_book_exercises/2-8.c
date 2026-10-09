/* rightrot(x,n) returns value of integer x rotated to the right
by n bit positions */

unsigned rightrot(unsigned x, int n) {
    int bit;  // save bit from end
    int wordlength(void);

    while (n-- > 0) {
        bit = (x & 1) << (wordlength() - 1);    // zero all but bit 0, move that bit to the end
        x = x >> 1;                             // rotate bits right, leaving top pos open
        x = x | bit;                            // set top bit
    }
    return x;
}

int wordlength(void) {
    int i;
    unsigned v = (unsigned) ~0;

    for (i = 1; (v = v >> 1) > 0; i++)
        ;
    return i;
}

unsigned rightrot2(unsigned x, int n) {
    // no-loop second version for practice
    unsigned bits;

    if ((n = n % wordlength()) > 0) {
        bits = ~(~0 << n) & x;  // all 1s left shifted leaves n 0s. flip, mask x for right n bits.
        bits = bits << (wordlength() - n);  // shift n right bits to leftmost bits
        x = x >> n;
        x = x | bits;
    }
    return x;
}
/*
Guess: Save leftmost bit. Shift left, add bit to right. Repeat times n.
Can assume signed or unsigned?
Next guess: Shift x right, and with 011111... to clear top bit if signed
Or that with all zeros (even x) or 100000.... (odd x)
Probably there's a way to shift right n, or that with left shifted size - n, no loop

Their answer, 2 versions:
1) Unsigned only. Doesn't use i, can decrement n without consequence (call by value).
Uses a function to count word length.
Get rightmost bit anding x with 0001, shifting left length - 1, get 1 in left spot.
And that with x.
2) no loop, like predicted. isolate bits, shifting, masking, setting.
*/


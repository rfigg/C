/* rightrot(x,n) returns value of integer x rotated to the right
by n bit positions */

int rightrot(int x, int n) {
    short bit;  // save bit from end
    int i;

    for (int i=0; i<n; i++) {
        bit = x % 2; // bit should match pos 0 of x
        x = ((x >> 1) & (~0 >> 1)) |  // shift x right, and with 0 followed by 1s
            (bit ? ~(~0 >> 1) : 0);     // or that with 1 followed by 0s or 0, depending on bit
    }
    return 0;
}

/*
Guess: Save leftmost bit. Shift left, add bit to right. Repeat times n.
Can assume signed or unsigned?
Next guess: Shift x right, and with 011111... to clear top bit if signed
Or that with all zeros (even x) or 100000.... (odd x)
Probably there's a way to shift right n, or that with left shifted size - n, no loop
*/


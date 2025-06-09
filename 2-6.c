/* setbits(x,p,n,y) returns x with the n bits that begin at position p
set to the rightmost n bits of y, leaving other bits unchanged.
*/

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    return;
}

/* Best guess: mask off y so it's zeros until last n bits,
shift y left p+1-n. for x, mask off n bits at p to zero them,
or with shifted y. */


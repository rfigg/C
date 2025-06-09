/* invert(x,p,n) return x with n bits at postion p inverted */

unsigned invert(unsigned x, int p, int n) {
    return x & ~(~(~0 << n) << (p+1-n)) |       // zero out x at p and or with...
        (~x & (~(~0 << n) << (p+1-n)));         // inverse x anded with 1s at p, 0s elsewhere
}     

/*
My attempt, first at bitwise anything.
*/

/* invert(x,p,n) return x with n bits at postion p inverted */

unsigned invert(unsigned x, int p, int n) {
    return x ^ (~(~0 << n) << (p+1-n));
}     

/*
My attempt, first at bitwise anything.
I think mine works, but theirs is cooler.
Uses xor like I wanted to, but xor with 1 inverts, not xor with self.
xor with 0 leaves the same.
*/

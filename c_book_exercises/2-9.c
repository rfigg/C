/* Two's complement x &= (x-1) deletes rightmost 1-bit in x. Why?
Anding x with x - 1. */

int bitcount(unsigned x) {
    int count;

    for (count = 0; x != 0; x &= x-1)
        ++count;
    return count;
}

/* -1 takes from the rightmost 1. Try it, it just does!
Old bitcount has to shift once for every bit.
Here we skip zeroes. Worst case is all 1s, equal to shifts in old bitcount. */


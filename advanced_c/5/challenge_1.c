// Section 5 Challenge 1
// Decalre a bunch of variables

static double b;
float c;

int main(void) {
    auto int a;     // copied auto from their solution. mixed opinions on using it in modern c.
    static float d;
    register int e;

    return 0;
}

static void f(void){
    // printf("Can't call me from there!\n");
}

/* Results:
Almost the same as their solution.
They used auto for a, and they set all these to values for some reason
Also they return 1, again. Why signal failure return? More questionable c in c course.
*/


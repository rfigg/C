/* Rewrite binary search to use only one test inside loop, with more tests outside */

int binsearch(int x, int v[], int n) {
    int low, mid, high;

    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high && x != v[mid]) {    // change loop to exit on equals
        if (x < v[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
        mid = (low + high) / 2;
    }
    if (x == v[mid])
        return mid;
    else
        return -1;
}

/* My attempt. Logic doesn't quite work
Thier answer: uses 1 less test in loop but adds test in loop conditional.
Guessing that won't be much faster.*/

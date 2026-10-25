// Complex number challenge
// Unclear directions - create a complex number with the imaginary number squared?
// Just guessing on these.

#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
    double complex a = I * I;
    printf("%.2f%+.2fi\n", creal(a), cimag(a));

    double complex b = pow(I, 2);
    printf("%.2f%+.2fi\n", creal(b), cimag(b));

    const double PI = acos(-1);
    double complex c = exp(I * PI);
    printf("%.2f%+.2fi\n", creal(c), cimag(c));

    double complex d = 1 + 2*I;
    double complex e = 1 - 2*I;
    printf("%.2f%+.2fi\n", creal(d*e), cimag(d*e));

    return 0;
}

/*
Results:
My guess was more complicated than what he wanted.
Euler's needed the exp function, ok? Looking up, this raises e to the power
Last wanted to started with the 2 conjugates and multiply,
also not specified in directions.
*/


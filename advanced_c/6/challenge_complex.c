// Complex number challenge
// Unclear directions - create a complex number with the imaginary number squared?
// Just guessing on these.

#include <stdio.h>
#include <math.h>
#include <complex.h>

int main() {
    double complex a = 2.0 + 3.0 * I;
    //a *= cimag(a);
    //printf("%.2f%+.2fi\n", creal(a), cimag(a));
    printf("%.2f%+.2fi\n", creal(a), cimag(a) * cimag(a));

    double complex b = 2.0 + 3.0 * I;
    printf("%.2f%+.2fi\n", creal(b), pow(cimag(b), 2));

    const double PI = acos(-1);
    double complex c = I * PI;
    printf("%.2f%+.2fi\n", creal(c), cimag(c));

    double complex d = 1 + 2*I;
    double complex e = conj(d);
    printf("%.2f%+.2fi\n", creal(e), cimag(e));

    return 0;
}


#include <stdio.h>
#include <complex.h>

int main() {
#ifdef __STD_NO_COMPLEX__
    printf("No complex numbers\n");
#else
    printf("Complex numbers supported\n");
#endif

#ifdef _STD_NO_VLA__
    printf("No variable length arrays\n");
#else
    printf("Variable length arrays supported\n");
#endif

    printf("Eye: %f %f\n", cimag(_Complex_I), cimag(I));

    double complex cx = 1.0 + 3.0*I;
    double _Complex cy = 1.0 - 4.0*_Complex_I;

    //printf("Starting: cx = %.2f+%.2fi, cy = %.2f+%.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));
    // printf formatting thing: %+ apparently puts in + or - sign
    printf("Starting: cx = %.2f%+.2fi, cy = %.2f%+.2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));
    
    double complex sum = cx + cy;
    printf("Sum: %.2f%+.2fi\n",creal(sum),cimag(sum));

    double complex diff = cx - cy;
    printf("Difference: %.2f%+.2fi\n",creal(diff),cimag(diff));
    
    double complex product = cx * cy;
    printf("Product: %.2f%+.2fi\n",creal(product),cimag(product));

    double complex quot = cx / cy;
    printf("Quotient: %.2f%+.2fi\n",creal(quot),cimag(quot));

    double complex conjugate = conj(cx);
    printf("Conjugate: %.2f%+.2fi\n",creal(conjugate),cimag(conjugate));

    double complex power = cpow(cx, cy);
    printf("x ^ y: %.2f%+.2fi\n",creal(power),cimag(power));


}


# include <stdio.h>

/* Add a header to the floating point table */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Farenheit Celsius\n");
    printf("-----------------\n");

    fahr = lower;
    while (fahr <= upper) {
        celsius = (5.0/9.0) * (fahr - 32.0);
        printf("%9.0f  %6.1f\n", fahr, celsius);
        fahr += step;
    } 
}

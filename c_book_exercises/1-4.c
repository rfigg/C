# include <stdio.h>

/* Reverse to go from Celsius to Farenheit */

int main() {
    float fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    printf("Celsius Farenheit\n");
    printf("-----------------\n");

    celsius = lower;
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%6.0f  %9.1f\n", celsius, fahr);
        celsius += step;
    }
}

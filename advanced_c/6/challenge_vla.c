// Use variable length array to read in elements of that array then
// sum the elements

#include <stdio.h>

int main() {
    int in_size = 0;
    int total = 0;

    printf("How many numbers to sum?\n");
    scanf("%d", &in_size);
    int sum_array[in_size];    

    for (int i = 0; i < in_size; i++) {
       printf("Element %d: ", i+1);
       scanf("%d", &sum_array[i]);
       total += sum_array[i];
    }

    printf("The total was %d\n", total);
}


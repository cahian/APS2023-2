#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sorting/bubble.h"

void randinit() {
    srand(time(NULL));
}

int randgen(int limit) {
    return rand() % limit + 1;
}

void printarray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Initilize random system
    randinit();

    // Initilize array variables
    int size = 100000;
    int array[size];

    // Fill array with random numbers
    for (int i = 0; i < size; i++) {
        array[i] = randgen(size);
    }

    // Show the original array
    printf("Array original:\n");
    printarray(array, size);

    // Record the starting time
    clock_t start_time = clock();

    // Sort the original array
    bubblesort(array, size);

    // Record the ending time
    clock_t end_time = clock();

    // Calculate the elapsed time in seconds
    double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

    // Show the sorted array
    printf("Array ordenado:\n");
    printarray(array, size);

    // Show the elapsed time in seconds
    printf("Tempo gasto: %f segundos\n", elapsed_time);

    return 0;
}

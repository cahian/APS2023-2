#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ***********************************
// Algoritmos de ordenacao de array
// ***********************************

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void quick_sort(int array[], int size) {
    quick_sort2(array, 0, size - 1);
}

void quick_sort2(int array[], int low, int high) {
    if (low < high) {
        // Choose the rightmost element as pivot
        int pivot = array[high];

        // Pointer for greater element
        int i = low - 1;

        // Traverse through all elements, compare each element with pivot
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                // If element smaller than pivot is found, swap it with the greater element pointed by i
                i++;
                swap(&array[i], &array[j]);
            }
        }

        // Swap the pivot element with the greater element specified by i
        swap(&array[i + 1], &array[high]);

        // Recursively sort the sub-arrays
        quick_sort(array, low, i);
        quick_sort(array, i + 2, high);
    }
}


void merge_sort(int array[], int size) {
    merge_sort2(array, 0, size - 1);
}

void merge_sort2(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Sort first and second halves
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);

        // Merge the sorted halves
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];

        // Copy data to temporary arrayays L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = array[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = array[m + 1 + j];

        // Merge the temporary arrayays back into array[l..r]
        int i = 0, j = 0, k = l;
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                array[k] = L[i];
                i++;
            } else {
                array[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], if there are any
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if there are any
        while (j < n2) {
            array[k] = R[j];
            j++;
            k++;
        }
    }
}

void insertion_sort(int array[], int size) {
    int i, key, j;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Move elements of array[0..i-1] that are greater than key to one position ahead of their current position
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selection_sort(int array[], int size) {
    int i, j, min_index;

    // One by one move the boundary of the unsorted subarray
    for (i = 0; i < size - 1; i++) {
        // Find the minimum element in the unsorted array
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        // Swap the found minimum element with the first element
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Last i elements are already in place
        for (int j = 0; j < size - i - 1; j++) {
            // Traverse the array from 0 to size - i - 1
            // Swap if the element found is greater than the next element
            if (array[j] > array[j + 1]) {
                // Swap array[j] and array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

void (*sort[])(int[], int) = {
    quick_sort
    merge_sort,
    insertion_sort,
    selection_sort,
    bubble_sort,
};

// ***********************************
// Gerador de numeros aleatorios
// ***********************************

void random_init() {
    srand(time(NULL));
}

int random_generate(int limit) {
    return rand() % limit + 1;
}

// ***********************************
// Sistema de preenchimento de array 
// ***********************************

void fill_ordered(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
}

void fill_semiordered(int array[], int size) {
    for (int i = 0; i < n; i++) {
        if (random_generate(array, 2) == 1) {
            array[i] = random_generate(array, size);
        } else {
            array[i] = i + 1;
        }
    }
}

void fill_random(int array[], int size) {
    for (int i = 0; i < size; i++) {
        array[i] = random_generate(size);
    }

}

void (*fill[])(int[], int) = {
    fill_ordered,
    fill_semiordered,
    fill_random,
};

// ***********************************
// Funcao principal
// ***********************************

int main() {
    // Inicializar o gerador de numeros aleatorios
    random_init();

    // 
    for (int i = 0; i < sizeof(sort) / sizeof(sort[0]); i++) {
        // Testar o algoritmo de ordenacao com tamanhos diferentes de array
        for (int size = 10; size < 1000000; size *= 10) {
            //
            for (int j = 0; j < sizeof(fill) / sizeof(fill[0]); j++) {
                // 
                int array[size];

                // 
                fill[j](array, size);

                // Record the starting time
                clock_t start_time = clock();

                //
                sort[i](array, size);

                // Record the ending time
                clock_t end_time = clock();

                // Calculate the elapsed time in seconds
                double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

                // Show the elapsed time in seconds
                printf("Tempo gasto: %f segundos\n", elapsed_time);
            }
        }
    }

    return 0;
}


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// ***********************************
// Algoritmos de ordenacao de array
// ***********************************

struct array_function {
    void (*call)(int[], int);
    const char *name;
};

// ***********************************
// Algoritmos de ordenacao de array
// ***********************************

void quick_sort(int array[], int size) {
    quick_sort2(array, 0, size - 1);
}

void quick_sort2(int array[], int low, int high) {
    if (low < high) {
        // Escolhe o elemento mais à direita como pivô
        int pivot = array[high];

        // Ponteiro para o elemento maior
        int i = low - 1;

        // Percorre todos os elementos, compara cada elemento com o pivô
        for (int j = low; j < high; j++) {
            if (array[j] <= pivot) {
                // Se um elemento menor que o pivô for encontrado, troca com o
                // elemento maior apontado por i
                i++;
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Troca o elemento do pivô com o elemento maior especificado por i
        int temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        // Ordena recursivamente as submatrizes
        quick_sort2(array, low, i);
        quick_sort2(array, i + 2, high);
    }
}

void merge_sort(int array[], int size) {
    merge_sort2(array, 0, size - 1);
}

void merge_sort2(int array[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;

        // Ordena as primeiras e segundas metades
        merge_sort(array, l, m);
        merge_sort(array, m + 1, r);

        // Une as metades ordenadas
        int n1 = m - l + 1;
        int n2 = r - m;
        int L[n1], R[n2];

        // Copia os dados para os arrays temporários L[] e R[]
        for (int i = 0; i < n1; i++)
            L[i] = array[l + i];
        for (int j = 0; j < n2; j++)
            R[j] = array[m + 1 + j];

        // Une os arrays temporários de volta no array[l..r]
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

        // Copia os elementos restantes de L[], se houver algum
        while (i < n1) {
            array[k] = L[i];
            i++;
            k++;
        }

        // Copia os elementos restantes de R[], se houver algum
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

        // Move os elementos do array[0..i-1] que são maiores que a chave para
        // uma posição à frente de sua posição atual
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

void selection_sort(int array[], int size) {
    int i, j, min_index;

    // Move a fronteira do subarray não ordenado uma posição por vez
    for (i = 0; i < size - 1; i++) {
        // Encontra o elemento mínimo no array não ordenado
        min_index = i;
        for (j = i + 1; j < size; j++) {
            if (array[j] < array[min_index]) {
                min_index = j;
            }
        }

        // Troca o elemento mínimo encontrado com o primeiro elemento
        int temp = array[min_index];
        array[min_index] = array[i];
        array[i] = temp;
    }
}

void bubble_sort(int array[], int size) {
    for (int i = 0; i < size - 1; i++) {
        // Os últimos i elementos já estão no lugar
        for (int j = 0; j < size - i - 1; j++) {
            // Percorre o array de 0 a size - i - 1
            // Troca se o elemento encontrado for maior que o próximo elemento
            if (array[j] > array[j + 1]) {
                // Troca array[j] e array[j + 1]
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

struct array_function sort[] = {
    {quick_sort, "Quick Sort"},
    {merge_sort, "Merge Sort"},
    {insertion_sort, "Insertion Sort"},
    {selection_sort, "Selection Sort"},
    {bubble_sort, "Bubble Sort"},
};

// ***********************************
// Gerador de numeros aleatorios
// ***********************************

void random_init() {
    srand(time(NULL));
}

int random_generate(int max) {
    return rand() % max + 1;
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
    for (int i = 0; i < size; i++) {
        if (random_generate(2) == 1) {
            array[i] = random_generate(size);
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

struct array_function fill[] = {
    {fill_ordered, "Fill Ordered"},
    {fill_semiordered, "Fill Semiordered"},
    {fill_random, "Fill Random"},
};

// ***********************************
// Função principal
// ***********************************

int main() {
    // Inicializar o gerador de números aleatórios
    random_init();

    // Iterar sobre os algoritmos de ordenação
    for (int i = 0; i < sizeof(sort) / sizeof(sort[0]); i++) {
        // Testar o algoritmo de ordenação com tamanhos diferentes de array
        for (int size = 10; size < 1000000; size *= 10) {
            // Iterar sobre os métodos de preenchimento do array
            for (int j = 0; j < sizeof(fill) / sizeof(fill[0]); j++) {
                // Criar um array para armazenar os dados
                int array[size];

                // Preencher o array de acordo com o método selecionado
                fill[j].call(array, size);

                // Registrar o tempo inicial
                clock_t start_time = clock();

                // Chamar a função de ordenação selecionada
                sort[i].call(array, size);

                // Registrar o tempo final
                clock_t end_time = clock();

                // Calcular o tempo decorrido em segundos
                double elapsed_time = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

                // Exibir o tempo decorrido em segundos
                printf("Tempo gasto: %f segundos\n", elapsed_time);
            }
        }
    }

    return 0;
}

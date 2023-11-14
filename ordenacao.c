#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// TODO(cahian): Increase the size with pow(i, 2)
// TODO(cahian): Group by fill, sort instead of sort, fill

// ***********************************
// Estrutura para funções de array
// ***********************************

struct array_function {
    void (*call)(int[], int);
    const char *name;
};

// ***********************************
// Algoritmos de ordenação de array
// ***********************************

void quick_sort(int array[], int size) {
    // Alocar dinamicamente uma pilha para armazenar os índices de baixo e alto
    int *stack = (int *)malloc(size * sizeof(int) * 2);
    if (stack == NULL) {
        fprintf(stderr, "Falha na alocação de memória para a pilha\n");
        exit(EXIT_FAILURE);
    }

    int top = -1;
    int low = 0;
    int high = size - 1;
    int pivot, i, j, temp;

    // Inserir os índices inicial e final na pilha para iniciar o algoritmo
    stack[++top] = low;
    stack[++top] = high;

    // Loop principal do algoritmo quicksort usando a pilha
    while (top >= 0) {
        // Retirar os índices de baixo e alto da pilha
        high = stack[top--];
        low = stack[top--];

        // Escolher o pivô como o último elemento da parte a ser ordenada
        pivot = array[high];
        i = low - 1;

        // Particionar o arrayay ao redor do pivô
        for (j = low; j <= high - 1; j++) {
            if (array[j] <= pivot) {
                i++;
                // Trocar elementos menores que o pivô para a parte esquerda
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }

        // Colocar o pivô na posição correta no arrayay ordenado
        temp = array[i + 1];
        array[i + 1] = array[high];
        array[high] = temp;

        // Se houver elementos à esquerda do pivô, adicionar à pilha
        if (i - low > 0) {
            stack[++top] = low;
            stack[++top] = i;
        }

        // Se houver elementos à direita do pivô, adicionar à pilha
        if (high - i > 1) {
            stack[++top] = i + 2;
            stack[++top] = high;
        }
    }

    // Liberar a memória alocada para a pilha
    free(stack);
}

void merge_sort(int array[], int size) {
    // Alocar memória para um array temporário do mesmo tamanho
    // do array original
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) {
        fprintf(stderr, "Falha na alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    // Variáveis para controle de índices e tamanho das partes
    // a serem mescladas
    int i, j, k, l1, h1, l2, h2, part_size, flag = 0;

    // Loop externo para percorrer os diferentes tamanhos de partes
    // a serem mescladas
    for (part_size = 1; part_size < size; part_size *= 2) {
        l1 = 0;
        k = 0;

        // Loop interno para percorrer e mesclar as partes do array
        while (l1 + part_size < size) {
            h1 = l1 + part_size - 1;
            l2 = h1 + 1;
            h2 = l2 + part_size - 1;

            // Garantir que h2 não ultrapasse o limite do array
            if (h2 >= size) {
                h2 = size - 1;
            }

            i = l1;
            j = l2;

            // Loop para mesclar as partes ordenadamente
            while (i <= h1 && j <= h2) {
                if (array[i] <= array[j]) {
                    temp[k++] = array[i++];
                } else {
                    temp[k++] = array[j++];
                }
            }

            // Lidar com os elementos restantes de ambas as partes
            while (i <= h1) {
                temp[k++] = array[i++];
            }
            while (j <= h2) {
                temp[k++] = array[j++];
            }

            // Atualizar o índice para a próxima parte
            l1 = h2 + 1;
        }

        // Lidar com os elementos restantes no final do array original
        for (i = l1; k < size; i++) {
            temp[k++] = array[i];
        }

        // Atualizar o arrayay original com os elementos ordenados
        for (i = 0; i < size; i++) {
            array[i] = temp[i];
        }
    }

    // Liberar a memória alocada para o array temporário
    free(temp);
}

void insertion_sort(int array[], int size) {
    int i, key, j;

    for (i = 1; i < size; i++) {
        key = array[i];
        j = i - 1;

        // Move os elementos do array[0..i-1] que são maiores que a chave
        // para uma posição à frente de sua posição atual
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
// Gerador de números aleatorios
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
        printf("%s\n", sort[i].name);
        // Iterar sobre os métodos de preenchimento do array
        for (int j = 0; j < sizeof(fill) / sizeof(fill[0]); j++) {
            printf("\t%s\n", fill[j].name);
            // Testar o algoritmo de ordenação com tamanhos diferentes de array
            for (int size = 1000; size <= 100000; size *= 10) {
                // Criar um array dinâmico para armazenar os dados
                int *array = (int *)malloc(size * sizeof(int));
                if (array == NULL) {
                    fprintf(stderr, "Falha na alocação de memória\n");
                    exit(EXIT_FAILURE);
                }

                // Preencher o array de acordo com o método selecionado
                fill[j].call(array, size);

                // Registrar o tempo inicial
                clock_t start_time = clock();

                // Chamar a função de ordenação selecionada
                sort[i].call(array, size);

                // Registrar o tempo final
                clock_t end_time = clock();

                // Calcular o tempo decorrido em milissegundos
                double elapsed_time =
                    ((double)(end_time - start_time)) / CLOCKS_PER_SEC;

                // Exibir o tempo decorrido em milissegundos
                printf(
                    "\t\tTempo gasto para ordernar um array com %d elementos: "
                    "%.3f segundos\n",
                    size, elapsed_time);

                // Liberar a memória alocada para o array
                free(array);
            }
        }
    }

    return 0;
}

# APS2023-2

Comparação de algoritmos de ordenação

## Uso

Basta você compilar o programa usando o compilador de sua preferência, e
executa-lo para obter os resultados de tempo de execução em segundos, dos
algoritmos de ordenação em cada uma das situações que o array se apresenta:

```shell
$ gcc -o ordenacao.out -Wall -Wextra -O2 ordenacao.c
$ ./ordenacao
Fill Ordered
	Quick Sort
		Tempo gasto para ordernar um array com 1024 elementos: 0.002 segundos
		Tempo gasto para ordernar um array com 2048 elementos: 0.005 segundos
		Tempo gasto para ordernar um array com 4096 elementos: 0.012 segundos
		Tempo gasto para ordernar um array com 8192 elementos: 0.044 segundos
		Tempo gasto para ordernar um array com 16384 elementos: 0.175 segundos
		Tempo gasto para ordernar um array com 32768 elementos: 0.710 segundos
		Tempo gasto para ordernar um array com 65536 elementos: 2.824 segundos
		Tempo gasto para ordernar um array com 131072 elementos: 11.681 segundos
...
```

## Metodologia

A metodologia utilizada para permitir a análise da performance desses algoritmos
através desse programa não foi muito complexa. Esse programa apenas faz uma
comparação simples entre os algoritmos de ordenação, caso o array esteja ordenado,
semi-ordenado e aleatório. Em cada uma dessas situações, o algoritmo é testado
também com tamanhos diferentes de array.

Apenas parra fins de informação, os algoritmos de ordenação utilizados para
fazer a comparação até o momento estão abaixo:

- Quick Sort
- Merge Sort
- Insertion Sort
- Selection Sort
- Bubble Sort 

## Resultado

Os resultados da performance desses algoritmos na máquina abaixo, estão contidos
no arquivo [resultados.txt](https://github.com/cahian/APS2023-2/blob/main/resultado.txt)
presente neste repositório:

```
OS: Ubuntu 22.04.3 LTS x86_64 
Host: Inspiron 3583 
Kernel: 6.2.0-36-generic 
CPU: Intel i5-8265U (8) @ 3.900GHz 
GPU: Intel WhiskeyLake-U GT2 [UHD Graphics 620] 
Memory: 7794MiB 
```

## Licença

[MIT](https://choosealicense.com/licenses/mit/)


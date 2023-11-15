# APS2023-2

Comparação de algoritmos de ordenação

## Uso

Basta você compilar o programa usando o compilador de sua preferência, e
executar para obter os resultados (em segundos) dos algoritmos de ordenação
em cada uma

```shell
$ gcc -o ordenacao -Wall -Wextra -O2 ordenacao.c
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
```

## Licença

[MIT](https://choosealicense.com/licenses/mit/)


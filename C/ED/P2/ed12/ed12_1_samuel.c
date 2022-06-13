/*
1-Faça um programa que leia 5 numeros inserindo-os em uma lista de forma 
ordenada utilizando a ideia do algoritmo de insert sort. No final, o 
programa deve mostrar todos os nomes ordenados alfabeticamente.
*/

#include <stdio.h>
#include <conio.h>

void insertionSort(int *v, int tamanho)
{
	int i = 0;
	int j = 1;
	int aux = 0;
	while (j < tamanho)
	{
		aux = v[j];
		i = j - 1;
		while ((i >= 0) && (v[i] > aux))
		{
			v[i + 1] = v[i];
			i = i - 1;
		}
		v[i + 1] = aux;
		j = j + 1;
	}
}

int main(void)
{
	int t[] = {6, 12, 8, 4, 1};
	int tamanho = sizeof(t) / sizeof(int);
	insertionSort(&t, tamanho);
	int x = 0;
	for (x = 0; x < tamanho; x++)
	{
		printf("%i\n", t[x]);
	}
	getch();
}

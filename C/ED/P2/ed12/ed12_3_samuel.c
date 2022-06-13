/*
3- Faça um programa que leia 10 numeros e ordene-os pelo tamanho utilizando o algoritmo
da seleção. No final, o algoritmo deve mostrar todos os nomes ordenados.
*/

#include <stdio.h>
#include <conio.h>

void selection_sort(int *v, int tamanho)
{
	int i, j, min, aux;
	for (i = 0; i < (tamanho - 1); i++)
	{
		min = i;
		for (j = (i + 1); j < tamanho; j++)
		{
			if (v[j] < v[min])
				min = j;
		}
		if (v[i] != v[min])
		{
			aux = v[i];
			v[i] = v[min];
			v[min] = aux;
		}
	}
}

int main(void)
{
	int t[] = {8, 2, 1, 9, 23, 6, 12, 8, 4, 1};
	int tamanho = sizeof(t) / sizeof(int);
	selection_sort(&t, tamanho);
	int x = 0;
	for (x = 0; x < tamanho; x++)
	{
		printf("%i\n", t[x]);
	}
	getch();
}

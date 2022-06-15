/*
2. Crie um programa que dado uma string, coloque as letras dela em ordem crescente pelo
algoritmo de buble sort.
*/

#include <stdio.h>
#include <conio.h>

void bubbleSort(char *vetor, int tamanho)
{
	int i, j;
	char aux;

	printf("%c\n", tamanho);
	for (j = tamanho - 1; j >= 1; j--)
	{
		for (i = 0; i < j; i++)
		{
			if (vetor[i] > vetor[i + 1])
			{
				aux = vetor[i];
				vetor[i] = vetor[i + 1];
				vetor[i + 1] = aux;
			}
		}
	}
}

int main(void)
{
	char t[] = {'j', 'o', 'n', 'a', 't', 'h','a','n'};
	char tamanho = sizeof(t) / sizeof(char);
	bubbleSort(&t, tamanho);
	int x = 0;
	for (x = 0; x < tamanho; x++)
	{
		printf("%c", t[x]);
	}
	getch();
}

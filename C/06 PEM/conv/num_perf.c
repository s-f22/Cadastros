#include <stdio.h>

int main()
{
	int numero;
	int soma = 0;
	int i;
	
	printf("Insira um numero: \n");
	scanf("%i", &numero);
	
	for(i = 1; i < numero; i++)
	{
		if (numero % i == 0) soma += i;
	}
	
	printf("Soma correspondente do numero: %i", soma);
	if (numero == soma) printf("Soma correspondente do numero: %i", soma);
	
	return 0;
}

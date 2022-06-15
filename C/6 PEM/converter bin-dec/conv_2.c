#include <stdio.h>

int main()
{
	int num, resto, soma = 0;
	int peso = 1;
	
	printf("Insira um numero inteiro para converter: ");
	scanf("%i", &num);
	
	while ( num != 0 )
	{
		resto = num % 2;
		num = num / 2;
		
		soma += (resto * peso);
		peso = peso * 10;
	}
	
	printf("Conversao: %i", soma);
	
	return 0;
}

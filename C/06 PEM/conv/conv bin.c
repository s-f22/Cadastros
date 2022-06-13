#include <stdio.h>

int main()
{
	int num, resto, soma = 0;
	int peso = 1;
	
	printf("Insira um numero binario para converter: ");
	scanf("%i", &num);
	
	while ( num != 0 )
	{
		resto = num % 10;
		num = num / 10;
		
		soma += (resto * peso);
		peso = peso * 2;
	}
	
	printf("Conversao: %i", soma);
	
	return 0;
}

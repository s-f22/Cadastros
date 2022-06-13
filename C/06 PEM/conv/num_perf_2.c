#include <stdio.h>

int main()
{
	int numero;
	int soma = 0;
	int i;
	
	for (numero = 1; numero < 10000; numero++)
	{
		soma = 0;
		for (i = 1; i < numero; i++)
		{
			if (numero % i == 0)
			{
				soma += i;
			}
		}
		
		if (soma == numero)
		{
			printf("Numero perfeito: %i");
		}
	}
	
	return 0;
}

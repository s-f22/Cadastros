/*

6- Crie um laço e verifique qual a maior sequencia de números 
pares informados, o laço fara 10 iterações.

Exe:   1, 2,3,4,6,8,5,3,2,5,8,4,0   Sequencia :4,6,8   
O programa vai retornar: 3

*/

#include <stdio.h>

int main()
{
	int i, numero;
	int contador_A  = 0;
	int contador_B  = 0;
	
	for (i = 0; i < 10; i++)
	{
		printf("Insira um numero inteiro: ");
		scanf("%i", &numero);
		
		if ((numero % 2) == 0)
		{
			contador_A++;
		}
		else
		{
			if (contador_A > contador_B)
			{
				contador_B = contador_A;
				if (i == 9)
				{
					break;
				}
				contador_A = 0;
			}
			
		}
	}
	
	if (contador_A > contador_B)
	{
		printf("\nA maior sequencia de numeros pares digitada foi: %i.", contador_A);
	}
	else
	{
		printf("\nA maior sequencia de numeros pares digitada foi: %i.", contador_B);
	}
	
	return 0;
}

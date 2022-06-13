#include <stdio.h>

int main()
{
	float n1, n2, resultado;
	int op;
	
	printf("Insira dois numeros reais: \n");
	scanf("%f %f", &n1, &n2);
		
	printf("Insira o numero da operacao desejada: \n\n 1 - SOMA \n 2 - SUBTRACAO \n 3 - MULTIPICACAO \n 4 - DIVISAO \n\n");
	
	scanf("%i", &op);
		
	if (op == 1)
	{
		resultado = n1 + n2;
		printf("Resultado da SOMA: %.1f", resultado);
	} else {
		if (op == 2)
		{
			resultado = n1 - n2;
			printf("Resultado da SUBTRACAO: %.1f", resultado);
		} else {
			if (op == 3)
			{
				resultado = n1 * n2;
				printf("Resultado da MULTIPLICACAO: %.1f", resultado);
			} else {
				if (op == 4)
				{
					resultado = n1 / n2;
					printf("Resultado da DIVISAO: %.1f", resultado);
				} else {
					printf("Operacao INVALIDA.");
				}
			}
		}
	}
	
	return 0;
}

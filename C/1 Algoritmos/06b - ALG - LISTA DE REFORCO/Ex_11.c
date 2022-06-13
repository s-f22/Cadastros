/*

11-Faca um programa que receba dois numeros e mostre o maior. Se por acaso, os dois numeros forem iguais, imprima a mensagem Numeros iguais.

*/

#include <stdio.h>

int main()
{
	float n1, n2;
	
	printf("Insira dois numeros quaisquer: ");
	scanf("%f %f", &n1, &n2);
	
	if (n1 == n2)
	{
		printf("Os numeros digitados sao iguais. \n");
	}
	else
	{
		if (n1 > n2)
		{
			printf("O numero %.1f e maior que %.1f", n1, n2);
		}
		else
		{
			printf("O numero %.1f e maior que %.1f", n2, n1);
		}
	}
	
	return 0;
}

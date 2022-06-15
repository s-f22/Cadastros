/*

C- Faça um algoritmo que dado valor inteiro informado, calcule e exiba a tabuada do numero de 1 a 10

*/

#include <stdio.h>

int main ()
{
	int numero, i, resultado;
	
	printf("Insira um numero inteiro para calcular sua tabuada: ");
	scanf("%i", &numero);
	
	for ( i = 1; i <=10; i++ )
	{
		resultado = numero * i;
		printf("\n%2i x %2i = %2i\n", numero, i, resultado);
	}
	
	return 0;
}

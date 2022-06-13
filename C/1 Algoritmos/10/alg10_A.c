/*

Nome: Samuel Figueiredo Silveira
ADS Ipiranga Noturno 1º Semestre

a- Faça um algoritmo que armazene um vetor de inteiros de 20 posições, 
identifique  o percentual de números impares e de números pares informados.

*/

#include <stdio.h>

int main ()

{
	int numeros[20];
	int i;
	float pares, impares;
	float num_par = 0;
	
	for (i = 0; i < 20; i++)
	{
		printf("Digite um numero inteiro: ");
		scanf("%i", &numeros[i]);
		
		if ((numeros[i] % 2) == 0)
		{
			num_par++;
		}
	}
	
	pares = num_par / 20;
	impares = 1 - pares;
	
	printf("\nPercentual de numeros pares: %.2f%%; \nPercentual de numeros impares: %.2f%%;\n\n", pares, impares);
	
	return 0;	
}

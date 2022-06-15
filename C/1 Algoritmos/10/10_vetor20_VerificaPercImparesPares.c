/*



a- Fa�a um algoritmo que armazene um vetor de inteiros de 20 posi��es, 
identifique  o percentual de n�meros impares e de n�meros pares informados.

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

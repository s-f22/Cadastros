/*



b-Crie dois vetores do tipo inteiro com a capacidade de 10 posi��es, 
leia n�meros que ser�o armazenados sequencialmente no primeiro vetor, 
fa�a um novo la�o que armazene no segundo vetor o valor do primeiro 
multiplicado por 2 quando o �ndice for par, e multiplique por 3 quando 
o �ndice for impar.

*/

#include <stdio.h>

int main()
{
	int vetor_A[10];
	int vetor_B[10];
	int i, j, k;
	
	for(i = 0; i < 10; i++)
	{
		printf("Digite um numero inteiro: ");
		scanf("%i", &vetor_A[i]);
	}
	
	for(j = 0; j < 10; j++)
	{
		if((vetor_A[j] % 2) == 0)
		{
			vetor_B[j] = vetor_A[j] * 2;
		}
		else
		{
			vetor_B[j] = vetor_A[j] * 3;
		}
	}
	
	for(k = 0; k < 10; k++)
	{
		int ordem = k + 1;
		printf("\n%i numero no segundo vetor: %i", ordem, vetor_B[k]);
	}
	
	return 0;
}

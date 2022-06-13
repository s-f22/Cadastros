// Aluno: Samuel Figueiredo Silveira


#include <stdio.h>

/*
1- escreva uma função recursiva para calcular o valor de uma base x elevada a um expoente y.
2- escreva uma função recursiva que calcule o dobro de um numero N vezes
3- faça uma função recursiva que calcule o numero de fibonacci 1,2,3,5,7
*/



int funcao (int base, int expoente)
{
	if (expoente == 0)
		return 1;
	if (expoente == 1)
		return base;
		
	return base * funcao(base, expoente-1);
}


int main() 
{
	int base, expoente, resultado;
	
	printf("\nDigite um numero inteiro para a base: ");
	scanf("%d", &base);
	printf("\nDigite um numero inteiro para o expoente: ");
	scanf("%d", &expoente);
	
	if (expoente < 0) 
	{
		printf("O expoente deve ser maior ou igual a zero!");
	}
	else
	{
		resultado = funcao(base,expoente);
		printf("\nBase elevado a expoente: %d", resultado);
	}
}

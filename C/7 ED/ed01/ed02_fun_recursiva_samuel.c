// Aluno: Samuel Figueiredo Silveira


#include <stdio.h>

/*
1- escreva uma função recursiva para calcular o valor de uma base base elevada a um expoente y.
2- escreva uma função recursiva que calcule o dobro de um numero N vezes

teste: (para numero = 5, dobrado 4 vezes)
5 * 2 = 10		4	
10 * 2 = 20		3	
20 * 2 = 40		2	
40 * 2 = 80		1	

3- faça uma função recursiva que calcule o numero de fibonacci 1,2,3,5,7
*/



int funcao (int numero, int vezes)
{
	if (vezes == 1)
		return numero * 2;
		
	return funcao(numero * 2, vezes-1);
}


int main() 
{
	int numero, vezes, resultado;
	
	printf("\nDigite um numero inteiro: ");
	scanf("%d", &numero);
	printf("\nDigite quantas vezes deseja calcular seu dobro: ");
	scanf("%d", &vezes);
	
		resultado = funcao(numero,vezes);
		printf("\nO resultado calculado foi: %d", resultado);
}

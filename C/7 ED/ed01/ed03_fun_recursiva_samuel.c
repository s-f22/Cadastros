// Aluno: Samuel Figueiredo Silveira


#include <stdio.h>

/*
1- escreva uma função recursiva para calcular o valor de uma base base elevada a um expoente y.
2- escreva uma função recursiva que calcule o dobro de um numero N vezes
3- faça uma função recursiva que calcule o numero de fibonacci 1,2,3,5,7
*/



int fib(int N)
{   
	if(N<=2) return 1;
    else return fib(N-1) + fib(N-2);
}

int main()
{   
	int i, vezes;
	
	printf("Digite quantos numeros da sequencia de Fibonacci deseja exibir: ");
	scanf("%i", &vezes);
	
    for(i=1; i<=vezes; i++)
        printf("%d ", fib(i));
    
    return 0;
}

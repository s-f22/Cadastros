/*
ALUNO: SAMUEL FIGUEIREDO SILVEIRA
FATEC IPIRANGA - ADS - NOTURNO
P1 - PEM

2) Crie uma função RECURSIVA para calcular a soma dos quadrados dos números positivos até N. 
Para valores negativos de N, a função deve retornar o valor dela para o módulo do número, 
ou seja, o correspondente positivo. O protótipo da função é assim:  int  somaQuadrados (int  N)
       Exemplos:
    • se N  for 10, a função somaQuadrados deverá retornar o valor de  1² + 2² + 3² + …. + 8² + 9² + 10² = 385
    • se N  for 5, a função somaQuadrados deverá retornar o valor de  1² + 2² + 3² + 4² + 5² = 55
    • se N  for 0, a função somaQuadrados deverá retornar o valor 0
    • se N  for -5, a função somaQuadrados deverá retornar o mesmo que somaQuadrados(5) = 55

*/

#include<stdio.h>

int somaQuadrados(int base)
{
	if(base < 0)
		base = -base;
		if(base == 1) return 1;
		else
			return somaQuadrados(base - 1 ) + base * base;
}



int main()
{
	int numero;
	printf("Insira um numero inteiro N: ");
	scanf("%i", &numero);
	
	printf("Soma dos quadrados dos numeros positivos ate N = %d", somaQuadrados(numero));
	
	return 0;
}

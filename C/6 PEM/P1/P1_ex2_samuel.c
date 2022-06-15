/*


2) Crie uma fun��o RECURSIVA para calcular a soma dos quadrados dos n�meros positivos at� N. 
Para valores negativos de N, a fun��o deve retornar o valor dela para o m�dulo do n�mero, 
ou seja, o correspondente positivo. O prot�tipo da fun��o � assim:  int  somaQuadrados (int  N)
       Exemplos:
    � se N  for 10, a fun��o somaQuadrados dever� retornar o valor de  1� + 2� + 3� + �. + 8� + 9� + 10� = 385
    � se N  for 5, a fun��o somaQuadrados dever� retornar o valor de  1� + 2� + 3� + 4� + 5� = 55
    � se N  for 0, a fun��o somaQuadrados dever� retornar o valor 0
    � se N  for -5, a fun��o somaQuadrados dever� retornar o mesmo que somaQuadrados(5) = 55

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

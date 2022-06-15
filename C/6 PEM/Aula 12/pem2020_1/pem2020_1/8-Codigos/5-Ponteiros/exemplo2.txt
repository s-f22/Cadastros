#include <stdio.h>

//Isto ilustra a passagem de parâmetros POR VALOR,
//onde ocorre a cópia dos valores das variáveis.
//É sempre assim para tipos primitivos.

void troca(int x, int y) //isto não funciona!!!!
{	int aux;
	printf("troca: ANTES:  x = %d, y = %d\n", x, y);
	aux = x;
	x = y;
	y = aux;
	printf("troca: DEPOIS:  x = %d, y = %d\n", x, y);
}
int main()
{	int a=2, b=3;
	printf("main: ANTES: a = %d, b = %d\n", a, b);
	troca(a, b);
	printf("main: DEPOIS: a = %d, b = %d\n", a, b);
	return 0;
}
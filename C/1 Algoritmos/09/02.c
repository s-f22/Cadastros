/*

2- Dado o algoritmo abaixo escrito em C :

int x = 10; while(x>0) { prinf("%d",x); x--; }

*/

#include <stdio.h>

int main()
{
	//	a- reescreva com o laço faça até (for)
	
	int x;
	for (x = 10; x > 0; x--)
	{
		printf("%i\n", x);
	}
	
	//	b- reescreva com o laço faça enquanto (do while)
	
	x = 10;
	printf("\n");
	
	do
	{
		printf("%i\n", x);
		x--;
		
	} while (x > 0);
	
	
	return 0;
}




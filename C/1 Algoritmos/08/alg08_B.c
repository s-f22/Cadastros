/*

B � Elabore um algoritmo que gere e escreva os n�meros �mpares dos n�meros entre 100 e 200.

*/

#include <stdio.h>

int main ()
{
	int i;
	
	printf("Numeros inpares entre 100 e 200: \n\n");
	
	for (i = 100; i <= 200; i++)
	{
		if ((i % 2) != 0)
		{
			printf("%i ", i);
		}
	}
	
	return 0;
}

/*

8- Fa�a um algoritmo que conte de 1 a 100 e a cada m�ltiplo 
de 3 e 5 simultaneamente emita uma mensagem:  �M�ltiplo de 3 e 5�.

*/

#include <stdio.h>

int main()
{
	int i, multiplo_3, multiplo_5;
	
	for (i = 1; i <= 100; i++)
	{
		if((i % 3) == 0)
		{
			multiplo_3 = 1;
		}
		else
		{
			multiplo_3 = 0;
		}
		
		
		if((i % 5) == 0)
		{
			multiplo_5 = 1;
		}
		else
		{
			multiplo_5 = 0;
		}
		
		if (multiplo_3 == 1 && multiplo_5 == 1)
		{
			printf("O numero %i e multiplo de 3 e 5. \n", i);
		}
		
	}
	
	return 0;
}

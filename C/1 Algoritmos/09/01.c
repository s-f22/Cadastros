/*

1- Dado o algoritmo abaixo escrito em C :

int i, a, b; for(i=0; i<20; i++) { scanf("%d",&a); scanf("%d",&b); r = a + b; printf("%d\n", r); }

*/

//	a- reescreva com o laço enquanto faça (while)

#include <stdio.h>

int main()
{
	int i, a, b, r;
	
	while (i < 2)
	{
		//printf("Digite um numero inteiro para A: ");
		scanf("%i", &a);
		
		//printf("Digite um numero inteiro para B: ");
		scanf("%i", &b);
		
		r = a + b;
		
		printf("Soma entre os valores (R): %i\n\n", r);
		
		i++;
	}
	
	//	b- reescreva com o laço faça enquanto (do while)
	
	i = 0;
	
	do
	{
		//printf("Digite um numero inteiro para A: ");
		scanf("%i", &a);
		
		//printf("Digite um numero inteiro para B: ");
		scanf("%i", &b);
		
		r = a + b;
		
		printf("Soma entre os valores (R): %i\n\n", r);
		
		i++;
	} while (i < 2);
	
	return 0;
}



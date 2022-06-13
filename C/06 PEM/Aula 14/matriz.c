#include <stdio.h>

void preencher(int valor)
{
	int i;
	
	for(i = 0; i <= valor; i++)
	{
		printf(" =");
	}
}


int main()
{
	int tamanho;
	
	printf("Qtde: ");
	scanf("%i", &tamanho);
	
	preencher(tamanho);
	
	
	
	
	
	return 0;
}

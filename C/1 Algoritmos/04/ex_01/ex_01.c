#include <stdio.h>

int main()
{
	int n1;
	printf("Digite um numero inteiro: ");
	scanf("%i", &n1);
	
	if(n1%2 == 0)
	{
		printf("O numero %i e par.\n", n1);
	}else{
		printf("O numero %i e impar.\n", n1);
	}
	
	return 0;
}

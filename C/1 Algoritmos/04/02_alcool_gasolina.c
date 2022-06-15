#include <stdio.h>

int main()
{
	float alc, gas;
	printf("Insira o preco do alcool: ");
	scanf("%f", &alc);
	
	printf("Insira o preco da gasolina: ");
	scanf("%f", &gas);
	
	if (alc / gas <= 0.7)
	{
		printf("Abastecer com ALCOOL.");
	}else{
		printf("Abastecer com GASOLINA.");
	}
	
	return 0;
}

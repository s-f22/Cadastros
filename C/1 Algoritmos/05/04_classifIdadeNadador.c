#include <stdio.h>
int main()
{
	int idade;
	
	printf("Informe a idade do atleta: \n");
	scanf("%i", &idade);
	
	if (idade < 5)
	{
		printf("Idade nao permitida. \n");
	}
	
	if (idade >=5 && idade <=7)
	{
		printf("Categoria: INFANTIL A. \n");
	} else {
		if (idade >=8 && idade <=11)
		{
			printf("Categoria: INFANTIL B. \n");
		} else {
			if (idade >=12 && idade <=13)
			{
				printf("Categoria: JUVENIL A. \n");
			} else {
				if (idade >=14 && idade <=17)
				{
					printf("Categoria: JUVENIL B. \n");
				}  else {
					if (idade >=18)
					{
						printf("Categoria: ADULTOS. \n");
					}
				}
			}
		}
	}

	return 0;
}

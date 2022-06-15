/*



1 - Construa um programa em C que utiliza uma matriz 10x3 que 
armazene as  temperaturas maxima e minima do dia, assim como 
a media de temperatura na ultima coluna.  Crie um menu de escolha 
que ofereca as seguintes informacoes:

1.temperatura minima de todos os dias.
2.temperatura maxima de todos os dias.
3.maior variacao de temperatura de todos os dias.
4.Sair do programa.

*/

#include <stdio.h>

int main()
{
	float temp [10][3];
	int i;
	int opcao, posicao;
	float delta;
	float minima, maxima, amplitude;
	
	
	for(i = 0; i < 10; i++)
	{
		printf("\n%i Temperatura Minima: ", i + 1);
		scanf("%f", &temp[i][0]);
		
		printf("%i Temperatura Maxima: ", i + 1);
		scanf("%f", &temp[i][1]);
		
		temp[i][2] = (temp[i][0] + temp[i][1]) / 2;
	}
	
	do
	{
		printf("\n|------------MENU DE FUNCOES------------|");
		printf("\n|                                       |");
		printf("\n|     1 - Temperaturas Minimas          |");
		printf("\n|     2 - Temperaturas Maximas          |");
		printf("\n|     3 - Maior variacao registrada     |");
		printf("\n|     4 - Sair                          |");
		printf("\n|                                       |");
		printf("\n|---------------------------------------|\n");
		
		scanf("%i", &opcao);
		
		switch (opcao)
		{
			case 1:
				for(i = 0; i < 10; i++) printf("%i Temperatura Minima: %.1f\n", i + 1, temp[i][0]);
				break;
				
			case 2:
				for(i = 0; i < 10; i++) printf("%i Temperatura Maxima: %.1f\n", i + 1, temp[i][1]);
				break;
				
			case 3:
				for (i = 0; i < 10; i++)
				{
					if (i == 0)
					{
						delta = temp[i][2];
						maxima = temp[i][1];
						minima = temp[i][0];
					} 
					
					if (delta < temp[i][2])
					{
						delta = temp[i][2];
						posicao = i;
					}
					
					if (maxima < temp[i][1]) maxima = temp[i][1];
					
					if (minima > temp[i][0]) minima = temp[i][0];
				}
				
				amplitude = maxima - minima;

				printf("\nA menor temperatura registrada foi de %.1f\n", minima);
				printf("A maior temperatura registrada foi de %.1f\n", maxima);
				printf("A amplitude entre as minimas e maximas foi de %.1f\n", amplitude);
				printf("A maior media registrada foi a do %i dia, com media de %.1f\n\n", posicao + 1, temp[posicao][2]);
			
				break;
				
			case 4:
				printf("\nAte logo!\n\n");
				break;
			
			default:
			printf("Opcao Invalida");
			break;
		}
		
	} while (opcao != 4);
	
	return 0;
}

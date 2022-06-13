#include <stdio.h>
#include <string.h>

int main(){
	
	int tamanho;
	
	int linha;
	int coluna;
	int flag = 0;
	int contador;
	int i;
	int dir = 0;
	
	int A = 0, B = 0, C = 0, D = 0;
	
	
	printf("Insira o tamanho inicial da figura: ");
	scanf("%i", &tamanho);
	
	
	contador = tamanho;
	int T = tamanho;
	
	char teste[] = " = ";
	
	int matriz[tamanho][tamanho];
	
	
	for( contador; contador > 0; contador-- )
	{
		if( flag == 0 )
		{
			switch( dir )
			{
				case 0:
				for(i = 0; i < tamanho; i++)
				{
					matriz[0][ i ] = 1;
				}
				dir++;
				break;
				
				case 1:
				for(i = 0; i < tamanho; i++)
				{
					matriz[0][ i ] = 1;
				}
				dir++;
				break;	
			}
			
		}
	}
	
	
	

	
	
	for(linha = 0; linha < T; linha++)
	{
		for(coluna = 0; coluna < T; coluna++)
		{	
			if(matriz[linha][coluna] != 1)
			{
				printf("   ");
			}
			else
			{
				printf("%s", teste);
			}				
		}
		printf("\n");
	}
	
	
	
	
	
	
	
	

	
	return 0;
}

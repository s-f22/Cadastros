#include <stdio.h>
#include <string.h>

int main(){
	
	int tamanho;
	int contador = 1;
	int direcao = 0;
	int linha = 0;
	int coluna = 0;
	
	printf("Insira o tamanho inicial da figura: ");
	scanf("%i", &tamanho);
	
	tamanho = tamanho - 1;
	int T = tamanho;
	char teste[] = " = ";
	
	int matriz[tamanho][tamanho];
	
	
	
	for(linha = 0; linha <= T; linha++)
	{
		for(coluna = 0; coluna <= T; coluna++)
		{	
			matriz[linha][coluna] = 0;
			printf("%i", matriz[linha][coluna]);			
		}
		printf("\n");
	}
	
	linha = 0;
	coluna = 0;
	printf("L=%i; C=%i\n", linha, coluna);
	
	
	
	
	do
	{
		printf("Coluna %i, Linha %i, Contador %i, tamanho %i", coluna, linha, contador, tamanho);
		if(direcao == 0 && contador <= T)
		{
			for(coluna; coluna < tamanho; coluna++)
			{
				matriz[linha][coluna] = 1;
				
			}
			direcao++;
			contador++;
			tamanho--;
		}
		printf("Coluna %i, Linha %i, Contador %i, tamanho %i", coluna, linha, contador, tamanho);
		if(direcao == 1 && contador <= T)
		{
			for(linha; linha < tamanho; linha++)
			{
				matriz[linha][coluna] = 1;
				
			}
			direcao++;
			contador++;
			tamanho--;
		}
		printf("Coluna %i, Linha %i, Contador %i, tamanho %i", coluna, linha, contador, tamanho);
		if(direcao == 2 && contador <= T)
		{
			for(coluna; coluna > contador; coluna--)
			{
				matriz[linha][coluna] = 1;
				
			}
			direcao++;
			contador++;
			tamanho--;
		}
		printf("Coluna %i, Linha %i, Contador %i, tamanho %i", coluna, linha, contador, tamanho);
		if(direcao == 3 && contador <= T)
		{
			for(linha; linha > contador; linha--)
			{
				matriz[linha][coluna] = 1;
				
			}
			direcao = 0;
			contador++;
			tamanho--;
		}

	}while( tamanho > 0);
	
	
	printf("\n\n\n");
	for(linha = 0; linha < T; linha++)
	{
		for(coluna = 0; coluna < T; coluna++)
		{	
			if(matriz[linha][coluna] == 1)
			{
				printf("%s", teste);
				
			}
			else
			{
				printf("   ");
			}				
		}
		printf("\n");
	}
	
	return 0;
}

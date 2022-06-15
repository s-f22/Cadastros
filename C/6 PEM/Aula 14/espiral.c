/*
ALUNO: SAMUEL FIGUEIREDO SILVEIRA
FATEC IPIRANGA - ADS - NOTURNO
P1 - PEM

4) Crie uma função em C para calcular e retornar a soma dos elementos da borda de uma matriz.
O protótipo da função é:  int  somaBorda ( int L, int C, int  mat [ L ] [ C ] )
Use repetição para criar seu código. Lembre-se que a função deverá funcionar para matrizes de quaisquer tamanhos.
DICA: Quais elementos estão na borda? Aqueles que têm índice de linha 0 ou o valor máximo, e adicionalmente têm índice de coluna 0 ou o valor máximo!!

*/

#include<stdio.h>

int L, C, l, c;
int somaL, somaC = 0;

int somaBorda( int L, int C, int mat[L][C] )
{
	for(l = 0; l < L; l++)
	{
		for(c = 0; c < C; c++)
		{	
			if(l == 0)
			{
				somaL += (l + 1);
				somaC += (c + 1);
			}
			else if(l == L - 1)
			{
				somaL += (l + 1);
				somaC += (c + 1);
			}
			else if((l > 0 && l < (L-1)) && c == 0 || c == (C-1))
			{
				somaL += (l + 1);
				somaC += (c + 1);
			}			
		}
	}
	
	printf("\nSoma das bordas da matriz informada: soma[%i][%i]", somaL, somaC);
	return somaL + somaC;
}


int main()
{
	
	int matriz[L][C];
	int resultado[1][1];
		
	printf("Insira a quantidade de linhas da matriz: ");
	scanf("%i", &L);
	
	printf("Insira a quantidade de colunas da matriz: ");
	scanf("%i", &C);
	
	for(l = 0; l < L; l++)
	{
		for(c = 0; c < C; c++)
				
			printf("(%2i,%2i) ", l+1, c+1);		
		
		printf("\n");
	}
	
	printf("\nValor somado, final : %i", somaBorda(L, C, matriz));
		
	
	return 0;
}




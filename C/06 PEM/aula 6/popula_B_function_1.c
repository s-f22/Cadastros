#include <stdio.h>

int i, j;
	int linha, coluna, contador;
	int B[28][12] = {
						{4,0,0,3,5,1,3,6,2,4,0,2}						
					};




void soma_4()
{
	if (B[linha - 1][coluna] < 6 && contador < 4)
		B[linha][coluna] = B[linha - 1][coluna] + 1;
						
	else if (B[linha - 1][coluna] < 5 && contador == 4)
	{
		B[linha][coluna] = B[linha - 1][coluna] + 2;
		contador = 0;
	}
		
	else if (B[linha - 1][coluna] == 5 && contador == 4)
	{
		B[linha][coluna] = 0;
		contador = 0;
	}
		
	else if (B[linha - 1][coluna] == 6 && contador == 4)
	{
		B[linha][coluna] = 1;
		contador = 0;
	}
			
	else if (B[linha - 1][coluna] == 6 && contador < 4)
		B[linha][coluna] = 0;
}



void soma_3()
{
	if (B[linha - 1][coluna] < 6 && contador < 3)
		B[linha][coluna] = B[linha - 1][coluna] + 1;
	
	else if (B[linha - 1][coluna] < 5 && contador == 3)
	{
		B[linha][coluna] = B[linha - 1][coluna] + 2;
		contador = 0;
	}
							
	else if (B[linha - 1][coluna] == 5 && contador == 3)
	{
		B[linha][coluna] = 0;
		contador = 0;
	}
		
	else if (B[linha - 1][coluna] == 6 && contador == 3)
	{
		B[linha][coluna] = 1;
		contador = 0;
	}
			
	else if (B[linha - 1][coluna] == 6 && contador < 3)
		B[linha][coluna] = 0;
}




int main()
{
	
	for(coluna = 0; coluna < 12; coluna++)
	{
		if(coluna <= 1)
			{
				for(linha = 1, contador = 1; linha < 28; linha++, contador++)
					soma_4();				
			}
		else
			
				for(linha = 1, contador = 1; linha < 28; linha++, contador++)
				{
					if(linha <= 3)	// volta a somar 4, depois de somar o primeiro e unico 3
						soma_3();
					else
						soma_4();		
				}
			
	}
	
	for(i = 0; i < 28; i++)
	{
		printf("\n");
		for(j = 0; j < 12; j++)
		{
			printf("%i ", B[i][j]);
		}
	}
	
	
	return 0;
}

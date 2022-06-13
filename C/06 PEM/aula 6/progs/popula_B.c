#include <stdio.h>

int main()
{
	int i, j;
	int lin, col, cont;
	int B[28][12] = {
						{4,0,0,3,5,1,3,6,2,4,0,2}						
					};
	for(col = 0; col < 12; col++)
	{
		if(col <= 1)
			{
				for(lin = 1, cont = 1; lin < 28; lin++, cont++)
				{
					if (B[lin - 1][col] < 6 && cont < 4)
						B[lin][col] = B[lin - 1][col] + 1;
						
					else if (B[lin - 1][col] < 5 && cont == 4)
					{
						B[lin][col] = B[lin - 1][col] + 2;
						cont = 0;
					}
						
					else if (B[lin - 1][col] == 5 && cont == 4)
					{
						B[lin][col] = 0;
						cont = 0;
					}
						
					else if (B[lin - 1][col] == 6 && cont == 4)
					{
						B[lin][col] = 1;
						cont = 0;
					}
							
					else if (B[lin - 1][col] == 6 && cont < 4)
						B[lin][col] = 0;			
				}
			}
		else
			
				for(lin = 1, cont = 1; lin < 28; lin++, cont++)
				{
					if(lin <= 3)	// volta a somar 4, depois de somar o primeiro e unico 3
					{
						if (B[lin - 1][col] < 6 && cont < 3)
						B[lin][col] = B[lin - 1][col] + 1;
						
						else if (B[lin - 1][col] < 5 && cont == 3)
						{
							B[lin][col] = B[lin - 1][col] + 2;
							cont = 0;
						}
												
						else if (B[lin - 1][col] == 5 && cont == 3)
						{
							B[lin][col] = 0;
							cont = 0;
						}
							
						else if (B[lin - 1][col] == 6 && cont == 3)
						{
							B[lin][col] = 1;
							cont = 0;
						}
								
						else if (B[lin - 1][col] == 6 && cont < 3)
							B[lin][col] = 0;
					}
					else
					{
						if (B[lin - 1][col] < 6 && cont < 4)
						B[lin][col] = B[lin - 1][col] + 1;
						
						else if (B[lin - 1][col] < 5 && cont == 4)
						{
							B[lin][col] = B[lin - 1][col] + 2;
							cont = 0;
						}
							
						else if (B[lin - 1][col] == 5 && cont == 4)
						{
							B[lin][col] = 0;
							cont = 0;
						}
							
						else if (B[lin - 1][col] == 6 && cont == 4)
						{
							B[lin][col] = 1;
							cont = 0;
						}
								
						else if (B[lin - 1][col] == 6 && cont < 4)
							B[lin][col] = 0;
					}		
				}
			
	}
	
	for(i = 0; i < 28; i++)
	{
		printf("\n");
		for(j = 0; j < 12; j++)
		{
			printf("  %i  ", B[i][j]);
		}
	}
	
	
	return 0;
}

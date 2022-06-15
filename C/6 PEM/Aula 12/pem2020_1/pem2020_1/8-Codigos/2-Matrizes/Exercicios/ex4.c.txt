#include<stdio.h>
#include<stdbool.h>
void busca(int L, int C, int mat[L][C], int procurado)
{	int x, y;
	bool achei = false;
	for(x=0; x<L; x++)
	{	for(y=0; y<C; y++)
		{	if( mat[x][y] == procurado)
			{	printf("O valor %d existe na linha %d e coluna %d\n", procurado, x, y);
				achei = true;
			}
		}
	}
	if(!achei) printf("O valor %d não existe na matriz\n", procurado);
}

int main()
{	int A[4][4] = 	{{3, 6, 4, 2},
				 {1, 2, 3, 4},
				 {0, 6, 9, 5},
				 {2, 4, 5, 8}};
	
	busca(4, 4, A, 5);
	return 0;
}

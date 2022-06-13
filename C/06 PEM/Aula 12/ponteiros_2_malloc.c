#include<stdio.h>
#include<stdlib.h>

int main()
{	int  *p;
	p = (int *) malloc(10 * sizeof(int));
	//o acima é mais ou menos equivalente a   int p[10];
	//só que é uma alocação dinâmica através de uma
	//chamada do sistema operacional (malloc)
	int i; 
	for(i=0; i<10;i++)
	{	p[i] = 2*i;
		printf("%d - ", p[i]);
	}
	return 0;
}



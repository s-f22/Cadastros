#include<stdio.h>
#include<stdlib.h>

int main()
{	int  *p;
	p = (int *) malloc(10 * sizeof(int));
	//o acima � mais ou menos equivalente a   int p[10];
	//s� que � uma aloca��o din�mica atrav�s de uma
	//chamada do sistema operacional (malloc)
	int i; 
	for(i=0; i<10;i++)
	{	p[i] = 2*i;
		printf("%d - ", p[i]);
	}
	return 0;
}



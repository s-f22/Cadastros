//Exemplo que N�O funciona como gostar�amos

#include<stdio.h>
int * funcao()
{	int vet[]={1,2,3,4,5};
	return vet;
}

int main()
{	int *p;
	p = funcao();
	//N�o funciona como imaginar�amos....
	printf("%d - %d - %d - %d - %d\n", p[0], p[1], p[2], p[3], p[4]);
	return 0;
}


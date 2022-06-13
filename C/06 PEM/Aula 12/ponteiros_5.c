#include<stdio.h>
#include<stdlib.h>
int main()
{	int * p, * q;
	p = (int *) malloc(10 * sizeof(int));
	q = (int *) malloc(10 * sizeof(int));

	int i;
	for(i=0; i<10;i++)
	{	p[i] = 2*i;
		printf("%u - ", p[i]);
	}
	printf("\nO vetor acima (p) esta no endereco %u\n\n", p);
	printf("\nO outro vetor (q) esta no endereco %u\n\n", q);
	//agora vamos aumentar o vetor p com realloc
	p = (int *) realloc(p, 100 * sizeof(int));
	for(i=10; i<100;i++)
	{	p[i] = 2*i;
	}
	printf("\nAumentando o vetor para 100 elementos:\n");
	for(i=0; i<100;i++)
	{	printf("%d - ", p[i]);
	}
	printf("\nO novo vetor esta no endereco %u\n\n", p);
	return 0;
}


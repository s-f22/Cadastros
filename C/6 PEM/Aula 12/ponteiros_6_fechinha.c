#include<stdio.h>
#include<stdlib.h>

struct amigo
{	int idade;
	char nome[50];
};

typedef struct amigo AMIGO;

int main()
{	AMIGO * p;
	p = (AMIGO *) malloc(5 * sizeof(AMIGO));
	//Isso é similar a: AMIGO p[5];


	char aux[50];
	int i;
	for(i=0; i<5;i++)
	{	printf("\nEntre com a idade:");
		fgets(aux, 50, stdin);
		p[i].idade = atoi(aux);
		printf("\nEntre com o nome:");
		fgets(p[i].nome, 50, stdin);
	}

	//ilustrando o uso do operador ->
	AMIGO * a;
	a = p;
	for(i=0; i<5;i++)
	{	printf("\nIdade: %d", a->idade);   //equivalente a:  printf("\nIdade: %d", p[i].idade);
		printf("\nNome: %s", a->nome);  //equivalente a:  printf("\nNome: %s", p[i].nome);
		//reparem no uso do operador ->
		a++;
	}
	return 0;
}


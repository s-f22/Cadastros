/*****************************************************************
C�digo Base para o Mini-Projeto Agenda de Amigos
----------------------------------------------------
Todos estes exerc�cios a seguir t�m por base o c�digo-base, que � um 
mini CRUD (Create-Read-Update-Delete, ou Criar-Ler-Atualizar-Remover).

1) Inclua novos campos, como endere�o, e-mail, data de nascimento, etc.

2) Crie uma fun��o procurar, com a assinatura abaixo, de modo que ela 
possa ser aproveitada tanto na funcionalidade procurar, quanto na excluir:

int procurar(char procurado[], struct ficha vetor[], int num_fichas)

 O retorno dessa fun��o ser� o �ndice do elemento encontrado, ou -1, 
 caso o mesmo n�o tenha sido localizado.

3) Reimplemente a fun��o procurar de modo recursivo (particularmente 
n�o h� nenhuma vantagem nesta altera��o, � s� para treinarmos recursividade).

DICA: Estou colando aqui o exerc�cio 10 da lista de recursividade:

	10) Crie uma fun��o recursiva que procure um n�mero dentro de um
		vetor, a partir de um dado �ndice. Se achar o mesmo, o m�todo
		retorna o �ndice onde ele se encontra, sen�o, retorna -1.

	-> S� para entendermos melhor o problema, a vers�o interativa
		(n�o-recursiva) seria assim:

		int busca(int vet[ ], int N, int indiceInicio, int procurado)
		{	int i;
			for(i=indiceInicio; i < N; i++)
			{	if(procurado == vet[i])  return i;
			}
			return -1;
		}

	Agora vamos pensar na vers�o recursiva.... 

	int buscaRecursiva(int vet[ ], int N, int indiceInicio, int procurado)
	{	if(indiceInicio >= N) return -1; //j� olhei em todo o vetor e n�o achei
		else if(vet[indiceInicio] == procurado) return indiceInicio;
		else return buscaRecursiva(vet, N, indiceInicio + 1, procurado);
	}


4) Refa�a a funcionalidade de exclus�o de modo a n�o ter que copiar todos 
os elementos abaixo do exclu�do.

	C�digo a ser substitu�do:
	int j;
    for(j=i+1; j<fichas_existentes; j++)
    {
    	agenda[j-1] = agenda[j];
    }
    fichas_existentes--;
    proxima--;


5) Refa�a o procurar de modo a trabalhar mesmo com peda�os de nomes 
(dica: pesquise uma fun��o chamada "strstr").

DICA: exemplo de uso da fun��o strstr()
--------

#include <stdio.h>
#include <string.h>
int main () {
	char texto[20] = "Joao da Silva";
	char pedaco1[10] = "Silva";
	char pedaco2[10] = "Santos";
	
	if(strstr(texto, pedaco1) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
		pedaco1, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco1, texto);
		
	if(strstr(texto, pedaco2) != NULL)
		printf("O pedaco %s existe dentro de %s\n",
		pedaco2, texto);
	else printf("O pedaco %s NAO existe dentro de %s\n",
		pedaco2, texto);
	return 0;
}


6) Crie uma funcionalidade de alterar (Update do crUd).


******************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
};

int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
        setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '5')
	{

		printf("\nEntre com a op��o desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Sair\n\n");
		gets(opcao);

		if(opcao[0] == '1') //inserir
		{
			printf("\nEntre com um nome:");
			gets(agenda[proxima].nome);
			printf("\nEntre com um telefone:");
			gets(agenda[proxima].telefone);
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //procurar
		{
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);

			bool achei = false; //nao achei
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, agenda[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s � %s\n",
			      agenda[i].nome, agenda[i].telefone);
			    //depois de achar nao preciso procurar mais
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome n�o encontrado\n");
			}
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    printf("O telefone de %s � %s\n",
			      agenda[i].nome, agenda[i].telefone);
			}
			if(fichas_existentes == 0)
				printf("A base de dados est� vazia!\n");
		}
		if(opcao[0] == '4') //excluir
		{
			char procurado[40];
			printf("\nEntre com o nome que sera exclu�do:");
			gets(procurado);

			bool achei = false; //nao achei
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			  //Ignorando Maiusculas/Minusculas:
			  //if(strcasecmp(procurado, agenda[i].nome) == 0)
			  if(strcmp(procurado, agenda[i].nome) == 0)
			  {
			    achei = true; //achei!!
			    printf("\n\nO telefone de %s, que � %s, ser� removido\n", agenda[i].nome, agenda[i].telefone);
			    int j;
			    for(j=i+1; j<fichas_existentes; j++)
			    {
					agenda[j-1] = agenda[j];
			    }
			    fichas_existentes--;
			    proxima--;
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome n�o encontrado\n");
			}
		}
	}
	return 0;
}
 


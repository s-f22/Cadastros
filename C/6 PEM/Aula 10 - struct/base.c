/*****************************************************************
Código Base para o Mini-Projeto Agenda de Amigos
----------------------------------------------------
Todos estes exercícios a seguir têm por base o código-base, que é um 
mini CRUD (Create-Read-Update-Delete, ou Criar-Ler-Atualizar-Remover).

1) Inclua novos campos, como endereço, e-mail, data de nascimento, etc.

2) Crie uma função procurar, com a assinatura abaixo, de modo que ela 
possa ser aproveitada tanto na funcionalidade procurar, quanto na excluir:

int procurar(char procurado[], struct ficha vetor[], int num_fichas)

 O retorno dessa função será o índice do elemento encontrado, ou -1, 
 caso o mesmo não tenha sido localizado.

3) Reimplemente a função procurar de modo recursivo (particularmente 
não há nenhuma vantagem nesta alteração, é só para treinarmos recursividade).

DICA: Estou colando aqui o exercício 10 da lista de recursividade:

	10) Crie uma função recursiva que procure um número dentro de um
		vetor, a partir de um dado índice. Se achar o mesmo, o método
		retorna o índice onde ele se encontra, senão, retorna -1.

	-> Só para entendermos melhor o problema, a versão interativa
		(não-recursiva) seria assim:

		int busca(int vet[ ], int N, int indiceInicio, int procurado)
		{	int i;
			for(i=indiceInicio; i < N; i++)
			{	if(procurado == vet[i])  return i;
			}
			return -1;
		}

	Agora vamos pensar na versão recursiva.... 

	int buscaRecursiva(int vet[ ], int N, int indiceInicio, int procurado)
	{	if(indiceInicio >= N) return -1; //já olhei em todo o vetor e não achei
		else if(vet[indiceInicio] == procurado) return indiceInicio;
		else return buscaRecursiva(vet, N, indiceInicio + 1, procurado);
	}


4) Refaça a funcionalidade de exclusão de modo a não ter que copiar todos 
os elementos abaixo do excluído.

	Código a ser substituído:
	int j;
    for(j=i+1; j<fichas_existentes; j++)
    {
    	agenda[j-1] = agenda[j];
    }
    fichas_existentes--;
    proxima--;


5) Refaça o procurar de modo a trabalhar mesmo com pedaços de nomes 
(dica: pesquise uma função chamada "strstr").

DICA: exemplo de uso da função strstr()
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

		printf("\nEntre com a opção desejada:\n");
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
			    printf("\n\nO telefone de %s é %s\n",
			      agenda[i].nome, agenda[i].telefone);
			    //depois de achar nao preciso procurar mais
			    break;
			  }
			}
			if(achei == false)
			{
			  printf("\n\nNome não encontrado\n");
			}
		}
		if(opcao[0] == '3') //listar tudo
		{
			printf("\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
			    printf("O telefone de %s é %s\n",
			      agenda[i].nome, agenda[i].telefone);
			}
			if(fichas_existentes == 0)
				printf("A base de dados está vazia!\n");
		}
		if(opcao[0] == '4') //excluir
		{
			char procurado[40];
			printf("\nEntre com o nome que sera excluído:");
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
			    printf("\n\nO telefone de %s, que é %s, será removido\n", agenda[i].nome, agenda[i].telefone);
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
			  printf("\n\nNome não encontrado\n");
			}
		}
	}
	return 0;
}
 


//Código Base para o Mini-Projeto Agenda de Amigos

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include <ctype.h>

struct ficha{
	char nome[40];
	char telefone[20];
	bool ativo;
};


//Variáveis Globais
struct ficha agenda[100];
int fichas_existentes = 0, proxima = 0;


//Protótipos
void meu_gets(char [], int);
char * strcasestr(char [], char []);
int procurar(char [], struct ficha [], int , int );
char menu();
void inserir();
void consultar();
void listar_tudo();
void excluir();
void alterar();


//Funções e Procedimentos
void meu_gets(char entrada[], int tamanho)
{   fgets(entrada, tamanho, stdin);
    entrada[strlen(entrada)-1] = '\0';
}

char * strcasestr(char string[], char substring[])
{   int i;
    char string_copia[100];
    strcpy(string_copia, string);
    for(i=0; i<strlen(string_copia); i++)
        string_copia[i] = tolower(string_copia[i]);
        
    char substring_copia[100];
    strcpy(substring_copia, substring);
    for(i=0; i<strlen(substring_copia); i++)
        substring_copia[i] = tolower(substring_copia[i]);
    
    return strstr(string_copia, substring_copia);
}

int procurar(char procurado[], struct ficha vetor[], int indInicio, int num_fichas)
{	int i;
	for(i=indInicio; i<num_fichas; i++)
	{
	  if(vetor[i].ativo && strcasestr(vetor[i].nome, procurado) != NULL)
	  {
	    return i;
	  }
	}
	return -1;
}

char menu()
{   char opcao[10]="0";
    printf("\nEntre com a opção desejada:\n");
	printf("\n1) Inserir ficha");
	printf("\n2) Procurar por nome");
	printf("\n3) Listar toda a base");
	printf("\n4) Excluir por nome");
	printf("\n5) Alterar");
	printf("\n6) Sair\n\n");
	meu_gets(opcao, 10);
    return opcao[0];
}

void inserir()
{   printf("\nEntre com um nome:");
	meu_gets(agenda[proxima].nome, 40);
	printf("\nEntre com um telefone:");
	meu_gets(agenda[proxima].telefone, 20);
	agenda[proxima].ativo = true;
	fichas_existentes++;
	proxima++;
}

void consultar()
{   char procurado[40];
	printf("\nEntre com o nome procurado:");
	meu_gets(procurado, 40);
    int inicio = 0;
    char resp[10];
    do{
		int i = procurar(procurado, agenda, inicio, fichas_existentes);
		if(i >= 0) printf("\n\nO telefone de %s é %s\n", 
		                agenda[i].nome, agenda[i].telefone);
		else printf("\n\nNome não encontrado\n");
		
		printf("Deseja continuar a busca? (S/N) -> ");
		meu_gets(resp, 10);
		if(resp[0] == 's' || resp[0] == 'S')
		    inicio = i+1;
    } while(resp[0] == 's' || resp[0] == 'S');
}

void listar_tudo()
{   printf("\n\n");
	int i;
	for(i=0; i<fichas_existentes; i++)
	{   if(agenda[i].ativo) printf("O telefone de %s é %s\n",
	      agenda[i].nome, agenda[i].telefone);
	}
	if(fichas_existentes == 0)
		printf("A base de dados está vazia!\n");
}

void excluir()
{   char procurado[40];
	printf("\nEntre com o nome que sera excluído:");
	meu_gets(procurado, 40);
    int inicio = 0;
    char resp[10];
    do{
		int i = procurar(procurado, agenda, inicio, fichas_existentes);
		if(i >= 0)
		{   printf("\n\nA ficha de %s deve ser removida? (S/N)\n",
		        agenda[i].nome);
		    meu_gets(resp, 10);
		    if(resp[0] == 's' || resp[0] == 'S')
		        agenda[i].ativo = false;    
		}
		else printf("\n\nNome não encontrado\n");
		
		printf("Deseja continuar a busca? (S/N) -> ");
		meu_gets(resp, 10);
		if(resp[0] == 's' || resp[0] == 'S')
		    inicio = i+1;
    } while(resp[0] == 's' || resp[0] == 'S');
}

void alterar()
{   char procurado[40], aux[40];
	printf("\nEntre com o nome da ficha a alterar:");
	meu_gets(procurado, 40);
    int inicio = 0;
    char resp[10];
    do{
		int i = procurar(procurado, agenda, inicio, fichas_existentes);
		if(i >= 0)
		{   printf("\nNome: %s\n", agenda[i].nome);
		    printf("--> tecle ENTER para manter ou um novo nome para modificar: ");
			meu_gets(aux, 40);
			if(strcmp(aux, "") != 0) // nome alterado
			    strcpy(agenda[i].nome, aux);
			printf("\nTelefone: %s\n", agenda[i].telefone);
			printf("--> tecle ENTER para manter ou um novo telefone para modificar: ");
			meu_gets(aux, 20);
			if(strcmp(aux, "") != 0) // telefone alterado
			    strcpy(agenda[i].telefone, aux);
		}
		else printf("\n\nNome não encontrado\n");
		
		printf("Deseja continuar a busca? (S/N) -> ");
		meu_gets(resp, 10);
		if(resp[0] == 's' || resp[0] == 'S')
		    inicio = i+1;
    } while(resp[0] == 's' || resp[0] == 'S');
}

int main()
{   char opcao = '0'; 
    setlocale(LC_ALL, "Portuguese");
	while(opcao != '6')
	{   opcao = menu();
		if(opcao == '1') inserir();
		if(opcao == '2') consultar();
		if(opcao == '3') listar_tudo();
		if(opcao == '4') excluir();
		if(opcao == '5') alterar();
	}
	return 0;
}






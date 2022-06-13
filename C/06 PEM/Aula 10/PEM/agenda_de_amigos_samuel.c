/*
*******************************************************************************
C�digo Base para o Mini-Projeto Agenda de Amigos

Todos estes exerc�cios a seguir t�m por base o c�digo-base ao lado, que � um
mini CRUD (Create-Read-Update-Delete, ou Criar-Ler-Atualizar-Remover).

1) Inclua novos campos, como endere�o, e-mail, data de nascimento, etc.

2) Crie uma fun��o procurar, com a assinatura abaixo, de modo que ela possa ser
aproveitada tanto na funcionalidade procurar, quanto na excluir:

*Resposta:
*******************************************************************************
int procurar(char procurado[], struct ficha vetor[], int num_fichas)
	{   int i=0;
    if(num_fichas<= 0) return -1; //n�o existe
    else if(strcmp(procurado, vetor[i].nome) == 0) return i;//achei
    else return i++ && procurar(procurado, vetor, num_fichas);
	}
*******************************************************************************

 	O retorno dessa fun��o ser� o �ndice do elemento encontrado, ou -1, caso o
 	mesmo n�o tenta sido localizado.

3) Reimplemente a fun��o procurar de modo recursivo (particularmente n�o h�
nenhuma vantagem nesta altera��o, � s� para treinarmos recursividade).

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
**********************************************************************************	
***Forma recursiva:

	int procurarRec(char procurado[], struct ficha vetor[], int num_fichas)
	{	
	 if(strcmp(procurado, vetor[num_fichas-1].nome) == 0) return num_fichas-1;
	 else if(strcmp(procurado, vetor[num_fichas-1].nome) > 0) 
	 return procurarRec(procurado, vetor, num_fichas-1); 
	 else return -1; 	
		
	}
***********************************************************************************

4) Refa�a a funcionalidade de exclus�o de modo a n�o ter que copiar todos os
elementos abaixo do exclu�do.

	C�digo a ser substitu�do:
				int j;
			        for(j=i+1; j<fichas_existentes; j++)
			        {
				    	agenda[j-1] = agenda[j];
			        }
			        fichas_existentes--;
			        proxima--;


5) Refa�a o procurar de modo a trabalhar mesmo com peda�os de nomes (dica:
pesquise uma fun��o chamada "strstr").

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
*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>

struct ficha{
	char nome[40];
	char telefone[20];
	char email[40];
	char naturalidade[40];
	char UF_Nasc[30];
	char dataNasc[20];
	char rua[40];
	char numero[10];
	char bairro[40];
	char municipio[40];
	bool ativo;
};

int procurarRec(char procurado[], struct ficha vetor[], int num_fichas)
	{	
	 if(strcmp(procurado, vetor[num_fichas-1].nome) == 0) return num_fichas-1;
	 else if(strcmp(procurado, vetor[num_fichas-1].nome) > 0) 
	 return procurarRec(procurado, vetor, num_fichas-1); 
	 else return -1; 	
		
	}

/*
int procurar(char procurado[], struct ficha vetor[], int num_fichas)
{ 
	int i;
	for(i=0; i<num_fichas; i++)
	{
		// strcmp() =  fun��o que retorna o numero de caracteres diferentes na compara��o
	    if(strcmp(procurado, vetor[i].nome) == 0)
		{
		 return i;
		}
	}
	return -1;					
}
*/



// --------------------------------------- RESPOSTA 5 ---------------------------------------------------


int procurar(char procurado[], struct ficha vetor[], int num_fichas)
{ 
	int i;
	for(i=0; i<num_fichas; i++)
	{
		
		// OBS: a ordem das variaveis de procura � invertida entre as fun��es strstr() e strcmp()
	    if(strstr(vetor[i].nome, procurado) != NULL)
		{
		 	return i;
		}
	}
	return -1;					
}





int main()
{
	struct ficha agenda[100];
	int fichas_existentes = 0, proxima = 0;
	char opcao[10]="0";
    setlocale(LC_ALL, "Portuguese");

	while(opcao[0] != '6')
	{
		printf("\nEntre com a op��o desejada:\n");
		printf("\n1) Inserir ficha:");
		printf("\n2) Procurar por nome:");
		printf("\n3) Listar toda a base:");
		printf("\n4) Excluir por nome:");
		printf("\n5) Update:");
		printf("\n6) Sair\n\n");
		
		gets(opcao);

		if(opcao[0] == '1') //**************Inserir**************************
		{
			printf("\nEntre com um nome:");
			gets(agenda[proxima].nome);
			agenda[proxima].ativo = true;
			printf("\nEntre com um telefone:");
			gets(agenda[proxima].telefone);
			agenda[proxima].ativo = true;
			/*
			printf("\nEntre com um email:");
			gets(agenda[proxima].email);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o local de nascimento:");
			gets(agenda[proxima].naturalidade);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o UF de nascimento:");
			gets(agenda[proxima].UF_Nasc);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com a data de nascimento:");
			gets(agenda[proxima].dataNasc);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o nome da rua:");
			gets(agenda[proxima].rua);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o numero da rua:");
			gets(agenda[proxima].numero);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o bairro:");
			gets(agenda[proxima].bairro);
		  	agenda[proxima].ativo = true;
			printf("\nEntre com o municipio:");
			gets(agenda[proxima].municipio);
			*/
		  	agenda[proxima].ativo = true;
			fichas_existentes++;
			proxima++;
		}
		if(opcao[0] == '2') //******************procurar************************
		{
			char procurado[40];
			printf("\nEntre com o nome procurado:");
			gets(procurado);

			int i = procurar(procurado, agenda, fichas_existentes);
			if(i>=0) 
			{
				printf("\n\nOs dados de %s s�o:\n", agenda[i].nome);
				printf("\n\nTelefone: %s\n", agenda[i].telefone);
				/*
				printf("\n\nEmail: %s\n", agenda[i].email);
				printf("\n\nTelefone: %s\n", agenda[i].telefone);
				printf("\n\nNaturalidade: %s\n", agenda[i].naturalidade);
				printf("\n\nEstado de nascimento: %s\n", agenda[i].UF_Nasc);
				printf("\n\nData de nascimento: %s\n", agenda[i].dataNasc);
				printf("\n\nNome da rua: %s\n", agenda[i].rua);
				printf("\n\nNumero: %s\n", agenda[i].numero);
				printf("\n\nBairro: %s\n", agenda[i].bairro);
				printf("\n\nMunicipio: %s\n", agenda[i].municipio);
				*/			
			}
			else printf("\n\nNome n�o encontrado\n");	
		}
		
		if(opcao[0] == '3') //*****************Listar tudo********************
		{
			//printf("\n\n");
			printf("==== Dados existentes ====\n\n");
			int i;
			for(i=0; i<fichas_existentes; i++)
			{
		     	if(agenda[i].ativo == true)
		     	{
					printf("\n\nOs dados de %s s�o:\n", agenda[i].nome);
					printf("\n\nTelefone: %s\n", agenda[i].telefone);
					/*
					printf("\n\nEmail: %s\n", agenda[i].email);
					printf("\n\nTelefone: %s\n", agenda[i].telefone);
					printf("\n\nNaturalidade: %s\n", agenda[i].naturalidade);
					printf("\n\nEstado de nascimento: %s\n", agenda[i].UF_Nasc);
					printf("\n\nData de nascimento: %s\n", agenda[i].dataNasc);
					printf("\n\nNome da rua: %s\n", agenda[i].rua);
					printf("\n\nNumero: %s\n", agenda[i].numero);
					printf("\n\nBairro: %s\n", agenda[i].bairro);
					printf("\n\nMunicipio: %s\n", agenda[i].municipio);
					*/	
				}
			}
				if(fichas_existentes == 0)
			  	printf("A base de dados est� vazia!\n");
			
		}
		if(opcao[0] == '4') //****************Excluir****************
		{
			char procurado[40];
			printf("\nEntre com o nome que sera exclu�do:");
			gets(procurado);
			
			int i = procurar(procurado, agenda, fichas_existentes);
			
			if(i>=0)
			{ 
				printf("\n\nO numero %s de %s ser� excluido!\n", agenda[i].telefone, agenda[i].nome);
				agenda[i].ativo = false;
			}
			
			else printf("\n\nNome n�o encontrado\n");	
		}
		
		if(opcao[0] == '5') //*****************Update********************
		{
			bool opInvalida = false;
			char procurado[40];
			printf("\nEntre com o nome que sera atualizado:");
			gets(procurado);
			
			int i = procurar(procurado, agenda, fichas_existentes);
			
			if(i>=0)
			{ 
				int opcao;
				
				printf("Qual informa��o deseja alterar? 1- nome; 2- telefone");
				scanf("%i", &opcao);
				
				switch (opcao)
				{
				case 1:
				    printf("\nEntre com um novo nome: ");
					gets(agenda[proxima].nome);
					
				    break;
				    
				case 2:
				    printf("\nEntre com um novo telefone: ");
					gets(agenda[proxima].telefone);
					
				    break;
				
				default:
					printf("\nValor inv�lido");
					opInvalida = true;
				    break;
				    
				}
				
				if(opInvalida == false)
				agenda[proxima].ativo = true;
			}
			
			opInvalida = false;
		}
		
	}
	
	return 0;
}
 


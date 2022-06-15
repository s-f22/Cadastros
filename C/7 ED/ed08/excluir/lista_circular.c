/******************************************************************************
Instruções
1-Implemente uma lista circular que represente o gerenciamento de processamento de um sistema operacional,
além das funções para adicionar, remover e listar, implemente uma função chamada de processar, que fara um
laço enquanto tiver elementos na lista e deduzira -1 do atributo carga do TAD processo, quando carga for
igual a 0 chame o metodo para remover o item da lista. Removendo todos os processos da lista encerre o laço

typedef struct processo {
  int pid;
  int carga;
  struct processo *prox;
} Processo;

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>


struct processo
{
	int valor;
	struct processo *proximo;
};
typedef struct processo tipoListaProcesso;



tipoListaProcesso *criaLista()
{
	tipoListaProcesso *lista = (tipoListaProcesso *)malloc(sizeof(tipoListaProcesso));
	lista->proximo = NULL;
	return lista;
}

int verificarListaVazia(tipoListaProcesso *lista)
{
	if (lista->proximo == NULL)
		return 1;
	else
		return 0;
}

void colocaNaLista(tipoListaProcesso *lista)
{
	tipoListaProcesso *novo = (tipoListaProcesso *)malloc(sizeof(tipoListaProcesso));

	printf("Informe um numero:");
	scanf("%i", &novo->valor);

	novo->proximo = lista->proximo; // pega o endereco do primeiro item e associa no ultimo

	if (verificarListaVazia(lista) == 1)
	{
		lista->proximo = novo;
	}
	else
	{
		tipoListaProcesso *temp = lista->proximo;
		while (temp->proximo != novo->proximo && temp->proximo != NULL)
		{
			temp = temp->proximo;
		}

		temp->proximo = novo;
	}
}

void colocaInicioLista(tipoListaProcesso *lista)
{
	tipoListaProcesso *novo = (tipoListaProcesso *)malloc(sizeof(tipoListaProcesso));
	printf("Informe um numero:");
	scanf("%i", &novo->valor);
	novo->proximo = NULL;

	if (verificarListaVazia(lista) == 1)
	{
		lista->proximo = novo;
	}
	else
	{
		novo->proximo = lista->proximo;
		lista->proximo = novo;
	}
}

void removerLista(tipoListaProcesso *lista, int valor)
{
	if (verificarListaVazia(lista) == 0)
	{
		tipoListaProcesso *temp = lista->proximo; // end do primeiro item associado
		tipoListaProcesso *anterior = lista;		 // end da cabe?da lista
		tipoListaProcesso *primeiro = lista->proximo;
		while (temp->proximo != primeiro && temp->proximo != NULL)
		{
			if (temp->valor == valor)
			{
				anterior->proximo = temp->proximo;
				printf("Item Removido %x %i \n", temp, temp->valor);
				free(temp);
				break;
			}
			else
			{
				anterior = temp;
				temp = temp->proximo;
			}
		}
	}
}

void exibe(tipoListaProcesso *lista)
{
	tipoListaProcesso *primeiro = lista->proximo;
	tipoListaProcesso *temp = lista->proximo;
	do
	{
		printf("Item %x %i \n", temp, temp->valor);
		temp = temp->proximo;
	} while (temp != primeiro);
}

void total(tipoListaProcesso *lista)
{
	int comprimento = 0;
	tipoListaProcesso *primeiro = lista->proximo;
	tipoListaProcesso *temp = lista->proximo;
	do
	{
		comprimento++;
		temp = temp->proximo;
	} while (temp != primeiro);

	printf("Total de itens : %i \n", comprimento);
}

int main(int argc, char *argv[])
{
	// vai cria end. inicial da final cabe?da fila
	tipoListaProcesso *lista = criaLista();
	colocaNaLista(lista);
	colocaNaLista(lista);
	colocaNaLista(lista);
	//	colocaInicioLista(lista);
	exibe(lista);
	total(lista);
	removerLista(lista, 5);
	exibe(lista);
	removerLista(lista, 7);
	total(lista);

	return 0;
}

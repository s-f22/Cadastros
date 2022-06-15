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

struct item
{
    int codigo;
    struct item *refProxItem;
} typedef tipoItem;

struct
{
    tipoItem *itemInicial;
} typedef tipoLista;



void adicionar(tipoLista *lista)
{
    tipoItem *novoItem = (tipoItem *)malloc(sizeof(tipoItem));
    printf("\nInforme um codigo:");
    scanf("%i", &novoItem->codigo);
    novoItem->refProxItem = lista->itemInicial;
    if (lista->itemInicial == NULL)
    {
        lista->itemInicial = novoItem;
        lista->itemInicial->refProxItem = lista->itemInicial;
    }
    else
    {
        tipoItem *auxiliar = lista->itemInicial;
        while (auxiliar->refProxItem != novoItem->refProxItem && auxiliar->refProxItem != NULL)
        {
            auxiliar = auxiliar->refProxItem;
        }
        auxiliar->refProxItem = novoItem;
    }
}

void listar(tipoLista *lista)
{
    if (lista->itemInicial == NULL)
    {
        printf("\nLista Vazia !!!");
    }
    else
    {
        tipoItem *auxiliar = lista->itemInicial;
        do
        {
            printf("\ncodigo=%i proximo=%i", auxiliar->codigo, auxiliar->refProxItem->codigo);
            auxiliar = auxiliar->refProxItem;
        } while (auxiliar != lista->itemInicial);
    }
}

void remover(tipoLista *lista, int codigo)
{
    if (lista->itemInicial == NULL)
    {
        printf("\nLista Vazia !!!");
    }
    else
    {
        tipoItem *auxiliar = lista->itemInicial;
        tipoItem *penultimoItem;
        do
        {
            if (auxiliar->codigo == codigo)
            {
                if (auxiliar == lista->itemInicial)
                { // quando for o primeiro item
                    lista->itemInicial = auxiliar->refProxItem;
                }
                else
                { // quando for qualquer item
                    penultimoItem->refProxItem = auxiliar->refProxItem;
                }
                free(auxiliar);
                printf("\ncodigo removido %i", codigo);
                break;
                // APAGAR
            }
            penultimoItem = auxiliar;
            auxiliar = auxiliar->refProxItem;
        } while (auxiliar != lista->itemInicial);
    }
}

int main()
{
    tipoLista l1 = {NULL};

    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);

    listar(&l1);

    remover(&l1, 2);
    listar(&l1);
    remover(&l1, 3);
    listar(&l1);
    adicionar(&l1);
    remover(&l1, 1);
    listar(&l1);

    return 0;
}

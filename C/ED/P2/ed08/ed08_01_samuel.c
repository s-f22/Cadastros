/*
ALUNO: Samuel Figueiredo

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
*/

#include <stdio.h>

struct processo
{
    int pid;
    int carga;
    struct processo *refProxItem;
} typedef tipoProcesso;

struct
{
    tipoProcesso *itemInicial;
} typedef tipoLista;

void adicionar(tipoLista *lista)
{
    tipoProcesso *novoItem = (tipoProcesso *)malloc(sizeof(tipoProcesso));

    printf("\nInforme um pid:");
    scanf("%i", &novoItem->pid);

    printf("\nInforme um valor de carga:");
    scanf("%i", &novoItem->carga);

    novoItem->refProxItem = lista->itemInicial;

    if (lista->itemInicial == NULL)
    {
        lista->itemInicial = novoItem;
        lista->itemInicial->refProxItem = lista->itemInicial;
    }
    else
    {
        tipoProcesso *auxiliar = lista->itemInicial;

        while (auxiliar->refProxItem != novoItem->refProxItem && auxiliar->refProxItem != NULL)
        {
            auxiliar = auxiliar->refProxItem;
        }
        auxiliar->refProxItem = novoItem;
    }
}

void listar(tipoLista *lista)
{
    if (lista->itemInicial->pid == NULL)
    {
        printf("\nLista Vazia !!!");
    }
    else
    {
        tipoProcesso *auxiliar = lista->itemInicial;
        do
        {
            printf("\npid=%i carga=%i proximo=%i", auxiliar->pid, auxiliar->carga, auxiliar->refProxItem->pid);
            auxiliar = auxiliar->refProxItem;
        } while (auxiliar != lista->itemInicial);
    }
}

void remover(tipoLista *lista, int pid)
{
    if (lista->itemInicial == NULL)
    {
        printf("\nLista Vazia !!!");
    }
    else
    {
        tipoProcesso *auxiliar = lista->itemInicial;
        tipoProcesso *penultimoProcesso;
        do
        {
            if (auxiliar->pid == pid)
            {
                if (auxiliar == lista->itemInicial)
                { // quando for o primeiro processo
                    lista->itemInicial = auxiliar->refProxItem;
                }
                else
                { // quando for qualquer processo
                    penultimoProcesso->refProxItem = auxiliar->refProxItem;
                }
                free(auxiliar);
                auxiliar->pid = NULL;
                printf("\ncodigo removido %i", pid);
                break;
                // APAGAR
            }
            penultimoProcesso = auxiliar;
            auxiliar = auxiliar->refProxItem;
        } while (auxiliar != lista->itemInicial);
    }
}

void processar(tipoLista *lista)
{
    if (lista->itemInicial == NULL)
    {
        printf("\nLista Vazia !!!");
    }
    else
    {
        tipoProcesso *auxiliar = lista->itemInicial;
        tipoProcesso *atual = lista->itemInicial;
        do
        {
            if (atual->carga > 0)
            {
                while (atual->carga > 0)
                {
                    atual->carga--;
                    printf("\nCarga finalizada. Restam %i cargas para processar.", atual->carga);
                }
                printf("\nProcesso encerrado.");
                remover(lista, atual);
                auxiliar = auxiliar->refProxItem;
                atual = auxiliar;
            }
            else
                return;

        } while (atual != NULL);
    }
}

int main()
{
    tipoLista l1 = {NULL};

    adicionar(&l1);
    adicionar(&l1);
    adicionar(&l1);

    processar(&l1);
    listar(&l1);


    return 0;
}
